import sys
sys.dont_write_bytecode = True

import matplotlib
matplotlib.use('TkAgg')

# load packages
from numpy import arange, sin, pi
import numpy
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import mpl_toolkits.axisartist as AA
import threading
import time
from Queue import Queue
import struct
import transceiver.EPL_Transceiver as EPL_Transceiver
import transceiver.epl_usb_lib as epl_usb_lib
from transceiver.EPL_Transceiver_Param import *
from datetime import datetime, timedelta

# load GUI associated packages
try:
    import tkinter as tk
except:
    import Tkinter as tk

class SensorView(threading.Thread):
    # some class constants
    RED = "#FF0000"
    GREEN = "#00FF00"

    XCOLOR = 'red'
    YCOLOR = 'green'
    ZCOLOR = 'blue'

    BACKGROUND = 'black'
    AXISCOLOR = 'white'
    AXISES = ['x', 'y', 'z']

    def __init__(self, num, label, text, frame, inq, fs):
        self.debug = False
        threading.Thread.__init__(self)
        self.sensor_id = num
        self.name = "Sensor %d" % self.sensor_id
        self.label = label
        self.text = text
        self.frame = frame
        self.inq = inq
        self.fs = fs
        self.update_interval = timedelta(milliseconds=200)

        self.display_time_duration  = 5.0    #  display 5 sec. data
        self.display_tick           = 0.1
        self.display_data_length    = int(self.display_time_duration / self.display_tick)
        self.display_tick_window    = int(self.display_tick * 1000) / (1000 / self.fs)

        self._stop = threading.Event()
        self._stop.set()
        self._quit = threading.Event()
        self._quit.clear()
        self.connected = False
        self.data = {}
        self.lim = {}
        for axis in SensorView.AXISES:
            self.data[axis] = []
            self.lim[axis] = 1000
        self.data['t'] = []
        self.ax = {}
        self.lines = {}

        # init. label
        self.off()

        # init. figure
        self.f = Figure(figsize=(3, 5), facecolor=SensorView.BACKGROUND)
        self.ax['x'] = AA.Subplot(self.f, 3, 1, 1, axisbg=SensorView.BACKGROUND)
        self.ax['y'] = AA.Subplot(self.f, 3, 1, 2, axisbg=SensorView.BACKGROUND)
        self.ax['z'] = AA.Subplot(self.f, 3, 1, 3, axisbg=SensorView.BACKGROUND)
        self.canvas = canvas = FigureCanvasTkAgg(self.f, self.frame)
        canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)
        for axis in SensorView.AXISES:
            self.f.add_subplot(self.ax[axis])

        t = arange(0.0, self.display_time_duration, self.display_tick)
        s = 0 * t
        for axis in SensorView.AXISES:
            self.data[axis] = [0.0] * self.display_data_length
        self.lines['x'], = self.ax['x'].plot(t, s, SensorView.XCOLOR)
        self.lines['y'], = self.ax['y'].plot(t, s, SensorView.YCOLOR)
        self.lines['z'], = self.ax['z'].plot(t, s, SensorView.ZCOLOR)

        self.default_setup()

        # draw default graph
        self.f.tight_layout()


    def on(self):
        self.text.set(self.name + "(ON)")
        self.label.configure(background=SensorView.GREEN)

    def off(self):
        self.text.set(self.name + "(OFF)")
        self.label.configure(background=SensorView.RED)

    def default_setup(self):
        for key in self.ax.keys():
            self.ax[key].axis["bottom", "top", "right"].set_visible(False)
            self.ax[key].axis["y=0"] = self.ax[key].new_floating_axis(nth_coord=0, value=0)
            self.ax[key].axis["y=0"].toggle(all=True, ticklabels=False)
            self.ax[key].axis[:].major_ticklabels.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].minor_ticklabels.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].major_ticks.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].minor_ticks.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].line.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].label.set_color(SensorView.AXISCOLOR)
            self.ax[key].axis[:].major_ticklabels.set_fontsize(10)

    def run(self):
        self.canvas.show()
        update_time = datetime.now() - self.update_interval
        tmp = None
        count = 0
        needUpdate = False
        if self.debug:
            print self.name, " thread start"
        while True:
            if self._quit.isSet():
                break
            if self._stop.isSet():
                time.sleep(0.5)
                continue

            try:
                val = self.inq.get(timeout=5)
                if not tmp:
                    tmp = list(val)
                else:
                    for i in range(3):
                        tmp[i] = (tmp[i] + val[i]) / 2
                if count == 0:
                    for axis in SensorView.AXISES:
                        self.data[axis].pop(0)
                    for i in range(3):
                        tmp[i] = (tmp[i] / 10) * 10
                    self.data['x'].append(tmp[0])
                    self.data['y'].append(tmp[1])
                    self.data['z'].append(tmp[2])

                    # y axis limit
                    for axis in SensorView.AXISES:
                        lim = max([max(self.data[axis]), abs(min(self.data[axis]))])
                        self.lim[axis] = ((lim / 500) + 1) * 500
                        # sensor itself is +-3G
                        if self.lim[axis] > 3000:
                            self.lim[axis] = 3000
                    needUpdate = True

                count = (count + 1) % self.display_tick_window
            except Exception as e:
                pass

            # update graph
            if needUpdate and (datetime.now() - update_time > self.update_interval):
                self.task()
                update_time = datetime.now()
                needUpdate = False

        if self.debug:
            print self.name, " thread end"


    def task(self):  # update graph task takes 0.04 sec
        for axis in SensorView.AXISES:
            self.lines[axis].set_ydata(numpy.array(self.data[axis]))
            self.ax[axis].set_ylim(self.lim[axis] * -1, self.lim[axis])
            yticks = range(self.lim[axis] * -1, self.lim[axis], self.lim[axis] / 2)
            yticks.append(self.lim[axis])
            self.ax[axis].yaxis.set_ticks(yticks)
#            self.ax[axis].relim()
#            self.ax[axis].autoscale_view()
        try:
            self.canvas.show()
        except Exception as e:
            print e
            self.stop()

    def stop(self):
        while not self._quit.isSet():
            self._quit.set()

    def pause(self):
        while not self._stop.isSet():
            self._stop.set()
        self.off()

    def resume(self):
        while self._stop.isSet():
            self._stop.clear()
        self.on()

class USBTransceiver(threading.Thread):
    RECV_ADDR = ["01", "01", "0F", "65", "65"] # base station address, 3 bytes
    RECV_WIDTH = "14"
    SEND_ADDR = ["E6", "E6", "E6", "65", "65"] # broadcast address, 3 bytes
    PKT_LENGTH = 2

    RF_CHANNEL = "0A"  # 10
    RF_POWER = "03" # 00: -18dB, 01: -12dB, 02: -6dB, 03: 0dB
    RF_DATARATE = "00" # 00: 1Mbps, 01: 2Mbps
    RF_ADDR_WIDTH = "03"
    RF_CRC_MODE = "02" # 0: off, 02: 8-bit, 03: 16-bit

    def __init__(self, count, qlist=None):
        threading.Thread.__init__(self)
        self.debug = True
        self.name = "USB Transceiver"
        self.eco_gid = 10
        self.sensor_count = count
        self.qlist = qlist
        self.connection = epl_usb_lib.EPL_USB()
        self.transceiver = EPL_Transceiver.EPL_Transceiver(self.connection)
        self._stop = threading.Event()
        self._stop.clear()
        self._ctrl_lock = threading.Lock()
        self._pause = threading.Event()
        self.pause()
        self.send_q = Queue()
        self.dumper_mode = False

        self.setup_default()

    def setup_default(self):
        self.transceiver.set_output_power(USBTransceiver.RF_POWER)
        self.transceiver.set_channel(USBTransceiver.RF_CHANNEL)
        self.transceiver.set_datarate(USBTransceiver.RF_DATARATE)
        self.transceiver.set_addr_width(USBTransceiver.RF_ADDR_WIDTH)
        self.transceiver.set_crc_mode(USBTransceiver.RF_CRC_MODE)
        # setup PIP 0, skip other PIPEs
        self.transceiver.set_autoack(0, OFF)
        self.transceiver.set_dynamic_payload(0, OFF)

    def setup_sender(self):
        self.transceiver.set_dest_addr(0, USBTransceiver.SEND_ADDR)
        self.transceiver.set_data_length(0, USBTransceiver.RECV_WIDTH)
        self.transceiver.enter_sender_mode()
        # pause before setting is ready
        time.sleep(0.01)

    def setup_dumper(self):
        self.transceiver.set_dest_addr(0, USBTransceiver.RECV_ADDR)
        self.transceiver.set_data_length(0, USBTransceiver.RECV_WIDTH)
        self.transceiver.enter_dumper_mode()
        # pause before setting is ready
        time.sleep(0.01)
        # start listening
        cmd = OP_transceiver + EPL_RUN_DUMPER + "00"
        try:
            self.connection.sendCmd(cmd)
        except Exception as e:
            print e

    def exit_dumper(self):
        cmd = OP_transceiver + EPL_EXIT_DUMPER
        try:
            self.connection.sendCmd(cmd)
        except Exception as e:
            print e
        # pause before transceiver is ready
        time.sleep(0.01)

    def send_start_packet(self, fs):
        self.send_q.put(("SEND", fs))

    def _send_start_packet(self, fs):
        with self._ctrl_lock:
            if self.dumper_mode:
                self.exit_dumper()

            self.setup_sender()

            # setup packet
            cmd = OP_transceiver + EPL_USER_PLOAD + USRS_PLOAD
            cmd += "%02X%02X%02X" % (USBTransceiver.PKT_LENGTH, self.eco_gid, fs)
            try:
                self.connection.sendCmd(cmd)
                ret_val = self.connection.recvCmd(4)
                if self.debug:
                    print "Setup packet ", ret_val, fs
            except Exception as e:
                print e

            # setnd packet
            cmd = OP_transceiver + EPL_RUN_SENDER + USRS_PLOAD
            try:
                self.connection.sendCmd(cmd)
                ret_val = self.connection.recvCmd(4)
                if self.debug:
                    print "Send packet ", ret_val, fs
            except Exception as e:
                print e

            if self.dumper_mode:
                self.setup_dumper()

    def send_stop_packet(self):
        self.send_q.put(0)

    def recv_packet(self):
        try:
            ret_val = self.connection.recvCmd(34)
            payload = ret_val[0:32]
            pipe_num = ord(ret_val[32])
            data_length = ord(ret_val[33])

            tmp = ord(ret_val[0])
            gid = (tmp & 0xF0) >> 4
            sid = (tmp & 0x0F)
            seq = ord(ret_val[1])
            (x, y, z, v) = struct.unpack(">hhhh", "".join(payload[2:10]))
            x, y, z = self.raw2g(x, y, z, v)
            if self.qlist:
                self.qlist[sid - 1].put((x, y, z))
            seq = ord(payload[11])
            (x, y, z, v) = struct.unpack(">hhhh", "".join(payload[12:20]))
            x, y, z = self.raw2g(x, y, z, v)
            if self.qlist:
                self.qlist[sid - 1].put((x, y, z))
            if self.debug:
                print "RECV PKT FROM :\n",
                stop = False
                for line in range(2):
                    if stop:
                        break
                    print "\t0x%04X: " % line,
                    for i in range(16):
                        idx = line * 16 + i
                        if idx < data_length:
                            print "%02X" % ord(payload[idx]),
                        else:
                            stop = True
                            break
                    print ""
            dispatch = True
        except Exception as e:
            if self.debug:
                print "Recv pkt exception"
            print e

    def raw2g(self, x, y, z, v):
        gx = int((0.0 + x - v)/ (2 ** 12) * (3000/333) * 1000)
        gy = int((0.0 + y - v)/ (2 ** 12) * (3000/333) * 1000)
        gz = int((0.0 + z - v)/ (2 ** 12) * (3000/333) * 1000)
        return gx, gy, gz

    def run(self):
        if self.debug:
            print self.name, "thread start"
        while True:
            if self._stop.isSet():
                if not self.send_q.empty():
                    self.send_q.get()
                    self.send_q.task_done()
                    continue
                else:
                    break

            if self._pause.isSet():
                if not self.send_q.empty():
                    self.send_q.get()
                    self.send_q.task_done()
                time.sleep(0.5)
                continue

            if self.send_q.empty():
                self.send_q.put(("RECV", None))

            try:
                msg = self.send_q.get(timeout=1)
                if msg[0] == "RECV":
                    self.recv_packet()
                    self.send_q.task_done()
                if msg[0] == "SEND":
                    pass
            except Exception as e:
                pass

        if self.debug:
            print self.name, "thread end"


    def stop(self):
        while not self._stop.isSet():
            if self.debug:
                print self.name, " stop"
            self._stop.set()

    def pause(self):
        while not self._pause.isSet():
            if self.debug:
                print self.name, " pause"
            self._pause.set()

    def resume(self):
        while self._pause.isSet():
            if self.debug:
                print self.name, " resume"
            self._pause.clear()


class DataLogger(threading.Thread):
    def __init__(self, inq, fname):
        threading.Thread.__init__(self)
        self.inq = inq
        self.fname = fname
        self._stop = threading.Event()

        self.fd = None

    def start(self):
        while not self._stop.isSet():
            msg = self.inq.get()
            self.task(msg)
            self.inq.task_done()
        while not self.inq.empty():
            self.inq.task_done()
        self.inq.join()

    def stop(self):
        set._stop.set()

    def task(self, msg):
        pass


if __name__ == "__main__":
    dongle = USBTransceiver(5)
    dongle.exit_dumper()

    time.sleep(1)
    dongle.setup_dumper()
    dongle.dumper_mode = True
    dongle.start()
#    dongle.send_stop_packet()
#    dongle.send_stop_packet()
    time.sleep(2)
#    dongle.send_start_packet(10)
    dongle.resume()
    time.sleep(1)
#    dongle.send_start_packet(100)
    time.sleep(3)
#    dongle.pause()
#    dongle.send_stop_packet()
#    dongle.send_stop_packet()
#    dongle.send_stop_packet()
#    dongle.send_stop_packet()
#    dongle.send_stop_packet()
    time.sleep(3)
    dongle.stop()
    dongle.exit_dumper()
   # dongle.start()
