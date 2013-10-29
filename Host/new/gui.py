import sys
sys.dont_write_bytecode = True

# load GUI associated packages
try:
    import tkinter as tk
except:
    import Tkinter as tk

import pygubu
from eco import SensorView, USBTransceiver
import time
from Queue import Queue

class MyApp:
    def __init__(self, master):
        # debug mode
        self.debug = True

        self.started = False

        self.master = master
        # create builder
        self.builder = builder = pygubu.Builder()
        # load ui
        builder.add_from_file("baby_monitor.ui")

        # create widget
        self.main_window = builder.get_object('main_window', master)

        # callback functions
        builder.connect_callbacks(self)

        # bind window close event
        master.protocol('WM_DELETE_WINDOW', self.on_button_quit_clicked)

        # construct SensorView
        self.sv_q = []
        self.sv = []
        for i in range(1, 6):
            frame_id = "Sensor_%d" % i
            frame = builder.get_object(frame_id)
            label_id = "Label_sensor_%d" % i
            label = builder.get_object(label_id)
            text_id = "label_sensor_%d_text" % i
            text = builder.get_variable(text_id)
            inq = Queue()
            self.sv.append(SensorView(i, label, text, frame, inq, 100))
            self.sv_q.append(inq)

        # spawn threads for updating graphs, start in pause mode
 #       for i in range(5):
 #           self.sv[i].start()

        self.dongle = USBTransceiver(5, self.sv_q)
        self.dongle.exit_dumper()
        self.dongle.start()

    def on_button_quit_clicked(self):
        if self.debug:
            print "button quit clicked"
        if self.started:
            self.on_button_start_clicked()

        for i in range(5):
            self.sv[i].stop()

        self.dongle.stop()
        time.sleep(1)
        for i in range(5):
            if self.sv[i].isAlive():
                print "wait sv ", i
                self.sv[i].join()
        if self.dongle.isAlive():
            print "wait dongle"
            self.dongle.join()
        print "ready to exit"
        self.master.destroy()

    def on_button_start_clicked(self):
        text = self.builder.get_variable("current_start_text")
        if self.debug:
            print "button start clicked"
        if not self.started:
            if self.debug:
                print "Resume"
            # dongle enter dumper mode
            print "enter dumper"
            self.dongle.dumper_mode = True
            self.dongle.setup_dumper()
            self.dongle.resume()
            print "send start"
            self.dongle.send_start_packet(10)
            time.sleep(1)
            if not self.dongle.isAlive():
                self.dongle.start()

            text.set("Stop")
            self.started = True
            for i in range(5):
                if not self.sv[i].isAlive():
                    self.sv[i].start()
                self.sv[i].resume()
        else:
            if self.debug:
                print "Pause"
            print "send stop"
            self.dongle.send_stop_packet()
            self.dongle.pause()
            print "exit dumper"
            self.dongle.exit_dumper()

            text.set("Start")
            self.started = False
            for i in range(5):
                self.sv[i].pause()

    def on_button_save_clicked(self):
        if self.debug:
            print "button save clicked"

    def on_10Hz_clicked(self):
        if self.debug:
            print "select 10Hz"
        text_var = self.builder.get_variable('current_freq_text')
        text_var.set("10Hz")

    def on_20Hz_clicked(self):
        if self.debug:
            print "select 20Hz"
        text_var = self.builder.get_variable('current_freq_text')
        text_var.set("20Hz")

    def on_50Hz_clicked(self):
        if self.debug:
            print "select 50Hz"
        text_var = self.builder.get_variable('current_freq_text')
        text_var.set("50Hz")

    def on_100Hz_clicked(self):
        if self.debug:
            print "select 100Hz"
        text_var = self.builder.get_variable('current_freq_text')
        text_var.set("100Hz")


if __name__ == "__main__":
    root = tk.Tk()
    root.wm_title("EPL Eco Baby Monitoring")
    app = MyApp(root)
    root.mainloop()
