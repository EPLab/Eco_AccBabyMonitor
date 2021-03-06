import sys
sys.dont_write_bytecode = True

import matplotlib
matplotlib.use('TkAgg')

# load packages
#from numpy import arange, sin, pi
import numpy
from numpy import arange
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
import os.path

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
        self.debug = True
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
            self.lim[axis] = 500
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
            self.ax[axis].set_ylim(self.lim[axis] * -1, self.lim[axis])
            yticks = range(self.lim[axis] * -1, self.lim[axis], self.lim[axis] / 2)
            yticks.append(self.lim[axis])
            self.ax[axis].yaxis.set_ticks(yticks)
        self.lines['x'], = self.ax['x'].plot(t, s, SensorView.XCOLOR)
        self.lines['y'], = self.ax['y'].plot(t, s, SensorView.YCOLOR)
        self.lines['z'], = self.ax['z'].plot(t, s, SensorView.ZCOLOR)

        self.default_setup()

        # draw default graph
        self.f.tight_layout()

    def set_sample_fs(self, fs):
        # clear the old graph
        for axis in SensorView.AXISES:
            self.ax[axis].clear()

        # setup new graph according to new sampling freq.
        self.display_data_length    = int(self.display_time_duration / self.display_tick)
        self.display_tick_window    = int(self.display_tick * 1000) / (1000 / self.fs)
        t = arange(0.0, self.display_time_duration, self.display_tick)
        s = 0 * t
        for axis in SensorView.AXISES:
            self.data[axis] = [0.0] * self.display_data_length
            self.ax[axis].set_ylim(self.lim[axis] * -1, self.lim[axis])
            yticks = range(self.lim[axis] * -1, self.lim[axis], self.lim[axis] / 2)
            yticks.append(self.lim[axis])
            self.ax[axis].yaxis.set_ticks(yticks)
        self.lines['x'], = self.ax['x'].plot(t, s, SensorView.XCOLOR)
        self.lines['y'], = self.ax['y'].plot(t, s, SensorView.YCOLOR)
        self.lines['z'], = self.ax['z'].plot(t, s, SensorView.ZCOLOR)


        self.default_setup()

        # draw default graph
        self.f.tight_layout()

        # update canvas
        self.canvas.show()



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
                if not self.inq.empty():
                    self.inq.get()
                    self.inq.task_done()
                    continue
                else:
                    break
            if self._stop.isSet():
                if not self.inq.empty():
                    self.inq.get()
                    self.inq.task_done()
                    continue
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
            except Exception:
                continue

            # update graph
            if needUpdate and (datetime.now() - update_time > self.update_interval):
                self.task()
                update_time = datetime.now()
                needUpdate = False

        if self.debug:
            print self.name, " thread end"


    def task(self):  # update graph task takes 0.04 sec
        try:
            for axis in SensorView.AXISES:
                tmp = self.data[axis][:]
                tmp.reverse()
                self.lines[axis].set_ydata(numpy.array(tmp))
                self.ax[axis].set_ylim(self.lim[axis] * -1, self.lim[axis])
                yticks = range(self.lim[axis] * -1, self.lim[axis], self.lim[axis] / 2)
                yticks.append(self.lim[axis])
                self.ax[axis].yaxis.set_ticks(yticks)
#            self.ax[axis].relim()
#            self.ax[axis].autoscale_view()
        except Exception as e:
            if self.debug:
                print self.name, " graph setup error", e
            return

        try:
            self.canvas.show()
        except Exception as e:
            if self.debug:
                print e
            self.stop()

    def stop(self):
        while not self._quit.isSet():
            self._quit.set()
        self.off()

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

    TIMESTAMP_FORMAT = "%H:%M:%S"

    def __init__(self, sensor_count, qlist=None, sampling_fs=10):
        threading.Thread.__init__(self)
        self.debug = True
        self.name = "USB Transceiver"
        self.eco_gid = 10
        self.sensor_count = sensor_count
        self.qlist = qlist
        self.sampling_fs = sampling_fs

        self._stop = threading.Event()
        self._stop.clear()
        self._ctrl_lock = threading.Lock()
        self._pause = threading.Event()
        self.pause()
        self.send_q = Queue()

        # queu for datalogger
        self.log_q_list = None
        self.dataloggers = None

#        self.datalog_q = None
#        self.datalogger = None

        # USB connection
        self.dumper_mode = False
        self.isConnected = False
        self.setup_tranceiver()

    def set_sample_fs(self, fs):
        self.sampling_fs = fs

    def logger_start(self, fs):
        if self.debug:
            print self.name, " start data loggers"
#        self.datalog_q = Queue()
#        self.datalogger = DataLogger(self.datalog_q, "test.txt", fs)
#        self.datalogger.start()
        # clean up old Queues
        self.log_q_list = list()
        self.dataloggers = list()
        for i in range(self.sensor_count):
            self.log_q_list.append(Queue())
            self.dataloggers.append(DataLogger(self.log_q_list[i], "Sensor%d" % (i+1),  fs))
            self.dataloggers[i].start()

    def logger_stop(self):
        if self.dataloggers:
            if self.debug:
                print self.name, " stop data loggers"
#            self.datalogger.stop()
        for i in range(self.sensor_count):
            self.dataloggers[i].stop()

    def getTimeStamp(self, dt):
        stamp = dt.strftime(USBTransceiver.TIMESTAMP_FORMAT)
        stamp += ".%03d" % (dt.microsecond / 1000)
        return stamp

    def setup_tranceiver(self):
        if not self.isConnected:
            if self.debug:
                print self.name, " init"
            self.connection = epl_usb_lib.EPL_USB()
            self.isConnected = self.connection.isConnected
            if not self.isConnected:
                if self.debug:
                    print self.name + " is not connected"
                return
            self.transceiver = EPL_Transceiver.EPL_Transceiver(self.connection)
            self.setup_default()

    def setup_default(self):
        if self.debug:
            print self.name, " setup default settings"
        self.setup_tranceiver()
        if not self.isConnected:
            return
        self.transceiver.set_output_power(USBTransceiver.RF_POWER)
        self.transceiver.set_channel(USBTransceiver.RF_CHANNEL)
        self.transceiver.set_datarate(USBTransceiver.RF_DATARATE)
        self.transceiver.set_addr_width(USBTransceiver.RF_ADDR_WIDTH)
        self.transceiver.set_crc_mode(USBTransceiver.RF_CRC_MODE)
        # setup PIP 0, skip other PIPEs
        self.transceiver.set_autoack(0, OFF)
        self.transceiver.set_dynamic_payload(0, OFF)

    def setup_sender(self):
        if self.debug:
            print self.name, " prepare to send"
        self.setup_tranceiver()
        if not self.isConnected:
            return

        self.transceiver.set_dest_addr(0, USBTransceiver.SEND_ADDR)
        self.transceiver.set_data_length(0, USBTransceiver.RECV_WIDTH)
        self.transceiver.enter_sender_mode()
        # pause before setting is ready
        time.sleep(0.1)

    def setup_dumper(self):
        if self.debug:
            print self.name, " prepare to receive"
        self.setup_tranceiver()
        if not self.isConnected:
            return

        self.transceiver.set_dest_addr(0, USBTransceiver.RECV_ADDR)
        self.transceiver.set_data_length(0, USBTransceiver.RECV_WIDTH)
        self.transceiver.enter_dumper_mode()
        # pause before setting is ready
        time.sleep(0.1)
        # start listening
        cmd = OP_transceiver + EPL_RUN_DUMPER + "00"
        try:
            self.connection.sendCmd(cmd)
        except Exception as e:
            print "setup dumper exception"
            print e

    def exit_dumper(self):
        if self.debug:
            print self.name, " exit dumper mode"
        self.setup_tranceiver()
        if not self.isConnected:
            return

        cmd = OP_transceiver + EPL_EXIT_DUMPER
        try:
            self.connection.sendCmd(cmd)
        except Exception as e:
            print "exit dumper exception"
            print e
        # pause before transceiver is ready
        time.sleep(0.1)

    def send_start_packet(self, fs):
        if self.debug:
            print "Enqueue START pkt"
        self.sampling_fs = fs
        self.send_q.put(("SEND", fs))

    def _send_start_packet(self, fs):
        self.setup_tranceiver()
        if not self.isConnected:
            return

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
                print "Setup packet ", ret_val, fs, cmd
        except Exception as e:
            print e

        # send packet
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
        if self.debug:
            print "Enqueue STOP pkt"
        self.send_q.put(("SEND", 0))

    def recv_packet(self):
        self.setup_tranceiver()
        if not self.isConnected:
            return

        try:
            ret_val = self.connection.recvCmd(34)
            if not ret_val:
                return
            if len(ret_val) != 34:
                return

            # get timestamp
            timestamp = datetime.now()
            # receive 2 readings in 1 packet
            payload = ret_val[0:32]
            pipe_num = ord(ret_val[32])
            data_length = ord(ret_val[33])

            tmp = ord(ret_val[0])
            gid = (tmp & 0xF0) >> 4
            sid = (tmp & 0x0F)
            seq = ord(ret_val[1])
            timestamp -= timedelta(milliseconds=(sid))
            (x, y, z, v) = struct.unpack(">hhhh", "".join(payload[2:10]))
            gx, gy, gz = self.raw2g(x, y, z, v)
            log = [timestamp, gid, sid, seq, (x, y, z, v), (gx, gy, gz)]
            if self.qlist:
                self.qlist[sid - 1].put((gx, gy, gz))
#            if self.datalog_q:
#                self.datalog_q.put(log)
            if self.log_q_list[sid-1]:
                self.log_q_list[sid-1].put(log)

            timestamp += timedelta(milliseconds=(1000/self.sampling_fs))
            seq = ord(payload[11])
            (x, y, z, v) = struct.unpack(">hhhh", "".join(payload[12:20]))
            gx, gy, gz = self.raw2g(x, y, z, v)
            log = [timestamp, gid, sid, seq, (x, y, z, v), (gx, gy, gz)]
            if self.qlist:
                self.qlist[sid - 1].put((gx, gy, gz))
#            if self.datalog_q:
#                self.datalog_q.put(log)
            if self.log_q_list[sid-1]:
                self.log_q_list[sid-1].put(log)

            return
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
        except Exception as e:
            if self.debug:
                print "Recv pkt exception: ", e

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
                    msg = self.send_q.get()
                    if msg[0] == "SEND":
                        print "send pkt"
                        self._send_start_packet(msg[1])
                        print "send done"
                    self.send_q.task_done()
                    continue
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
                    print "send pkt"
                    self._send_start_packet(msg[1])
                    self.send_q.task_done()
                    print "send done"
            except Exception:
                pass

        if self.debug:
            print self.name, "thread end"
        # exit dumper
        self.exit_dumper()
        # Terminate USB Connection
        self.connection.close()

        if self.dataloggers:
            if self.debug:
                print self.name, "Terminate datalogger thread"
            for datalogger in self.dataloggers:
                datalogger.stop()


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
    FILENAME_DATE_FORMAT  = "%Y%m%d_%H%M%S"
    TIMESTAMP_FORMAT = "%H:%M:%S"

    def __init__(self, inq, prefix, sample_fs):
        threading.Thread.__init__(self)
        self.debug = True
        self.prefix = prefix
        self.name = self.prefix + " DataLogger"
        # genrate log title format and fields
        # one sensor log format
        self.sensor_title_raw_format = "%14s\t%6s\t%6s\t%6s\t%6s"
        self.sensor_title_raw_fields = ["TimeStamp", "X", "Y", "Z", "Vref"]
        self.sensor_title_fields = ["TimeStamp", "X(mg)", "Y(mg)", "Z(mg)"]
        self.sensor_title_format = "%14s\t%6s\t%6s\t%6s"
        self.sensor_raw_format = "%14s\t%6d\t%6d\t%6d\t%6d"
        self.sensor_format = "%14s\t%6d\t%6d\t%6d"
        # raw data log
        self.log_title_raw_fields = ["TimeStamp"]
        self.log_title_raw_format = "%14s"
        self.log_raw_format = "%14s"
        # converted data log
        self.log_title_fields = ["TimeStamp"]
        self.log_title_format = "%14s"
        self.log_format = "%14s"

        for i in range(5):
            idx = i + 1
            # raw
            self.log_title_raw_format += "%6s%6s%6s%6s"
            self.log_raw_format += "%6d%6d%6d%6d"
            self.log_title_raw_fields.append("%4d:X" % idx)
            self.log_title_raw_fields.append("%4d:Y" % idx)
            self.log_title_raw_fields.append("%4d:Z" % idx)
            self.log_title_raw_fields.append("%4d:V" % idx)
            # converted
            self.log_title_format += "%8s%8s%8s"
            self.log_format += "%8d%8d%8d"
            self.log_title_fields.append("%-4d:X(mg)" % idx)
            self.log_title_fields.append("%-4d:Y(mg)" % idx)
            self.log_title_fields.append("%-4d:Z(mg)" % idx)

        self.log_raw_title = self.log_title_raw_format % tuple(self.log_title_raw_fields)
        self.log_title = self.log_title_format % tuple(self.log_title_fields)

        self.sensor_raw_title = self.sensor_title_raw_format % tuple(self.sensor_title_raw_fields)
        self.sensor_title = self.sensor_title_format % tuple(self.sensor_title_fields)

        self.inq = inq
        self.sample_fs = sample_fs
        self._stop = threading.Event()
        self._stop.clear()

        self.rfd = None
        self.cfd = None

        # data map init.
        self.reading_map = {}
        for seq in range(1, sample_fs+1):
            self.reading_map[seq] = {}
            for sid in range(5):
                self.reading_map[seq][sid] = {}
                self.reading_map[seq][sid]["timestamp"] = datetime.now()
                self.reading_map[seq][sid]["raw"] = [0] * 4
                self.reading_map[seq][sid]["conv"] = [0] * 3

    def show_reading_map(self, no_conv=False):
        # print header
        if no_conv:
            print "%3s %12s %23s %23s %23s %23s %23s " % ("SEQ", "TIMESTAMP", "1:RAW", "2:RAW", "3:RAW", "4:RAW", "5:RAW")
        else:
            print "SEQ    TIMESTAMP   1:raw  1:conv  2:raw  2:conv  3:raw  3:conv  4:raw  4:conv  5:raw  5:conv"
        # print content
        for seq in range(1, self.sample_fs+1):
            print "%3d" % seq, self.getTimeStamp(self.reading_map[seq][0]['timestamp']),
            for sid in range(5):
                print "[",
                for idx in range(4):
                    print "%4d" % self.reading_map[seq][sid]['raw'][idx],
                print "]",
                if not no_conv:
                    print "[",
                    for idx in range(3):
                        print "%-4d" % self.reading_map[seq][sid]['conv'][idx],
                    print "]",
            print ""

    def getTimeStamp(self, dt):
        stamp = dt.strftime(USBTransceiver.TIMESTAMP_FORMAT)
        stamp += ".%03d" % (dt.microsecond / 1000)
        return stamp

    def task(self, msg):
        timestamp = msg[0]
        sensor_group = msg[1]
        sid = msg[2] - 1
        seq = msg[3]
        raw_reading = list(msg[4])
        conv_reading = list(msg[5])

#        self.reading_map[seq][0]['timestamp'] = timestamp
#        self.reading_map[seq][sid]['raw'] = raw_reading
#        self.reading_map[seq][sid]['conv'] = conv_reading
#
#        if self.debug and seq == 1:
##            self.show_reading_map(no_conv=True)
#            print self.log_raw_format % self.make_raw_log(1)
#            print self.log_format % self.make_log(1)

        log = [self.getTimeStamp(timestamp)]
        raw_log = [self.getTimeStamp(timestamp)]
        for idx in range(4):
            raw_log.append(raw_reading[idx])
        for idx in range(3):
            log.append(conv_reading[idx])
#        print raw_log
        if self.cfd:
            self.cfd.write(self.sensor_format % tuple(log))
            self.cfd.write('\n')
        if self.rfd:
            self.rfd.write(self.sensor_raw_format % tuple(log))
            self.rfd.write('\n')
#        print self.sensor_raw_format % tuple(raw_log)
#        print self.sensor_format % tuple(log)


    def make_raw_log(self, seq):
        timestamp = self.reading_map[seq][0]['timestamp']
        ret = [self.getTimeStamp(timestamp)]
        for sid in range(5):
            for idx in range(4):
                ret.append(self.reading_map[seq][sid]['raw'][idx])
        return tuple(ret)
        

    def make_log(self, seq):
        timestamp = self.reading_map[seq][0]['timestamp']
        ret = [self.getTimeStamp(timestamp)]
        for sid in range(5):
            for idx in range(3):
                ret.append(self.reading_map[seq][sid]['conv'][idx])
        return tuple(ret)

    def run(self):
        tmp = datetime.now().strftime(DataLogger.FILENAME_DATE_FORMAT)
        datapath = "data/" + tmp
        raw_filename  = "%s/%s_raw.txt" % (datapath, self.prefix)
        conv_filename = "%s/%s.txt" % (datapath, self.prefix)
        if self.debug:
            print self.name, " creat log file: %s" % (conv_filename)

        if not os.path.exists(datapath):
            os.makedirs(datapath)
#        self.rfd = open(raw_filename, 'w')
        self.cfd = open(conv_filename, 'w')
#        self.rfd.write(self.log_raw_title + '\n')
#        self.cfd.write(self.log_title + '\n')
        self.cfd.write(self.sensor_title + '\n')
        if self.debug:
            print self.name + " Thread start"
        while True:
            if self._stop.isSet():
                # kepp logging till no more data
                if self.inq.empty():
                    break                   
            try:
                msg = self.inq.get(timeout=1)
                self.task(msg)
                self.inq.task_done()
            except Exception:
                pass

        if self.debug:
            print self.name + " Thread stop"
        if self.debug:
            print self.name, " close log file"
#        self.rfd.flush()
        self.cfd.flush()
#        self.rfd.close()
        self.cfd.close()

    def stop(self):
        self._stop.set()

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
