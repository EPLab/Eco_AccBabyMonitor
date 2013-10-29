# File:    EPL_Transceiver.py
# Celine Liu <tzuchung1030@gmail.com>
# Date:    2011/02/22
# version: dynamic payload length

import signal
import time

from threading import Thread
#from msvcrt import getch
from EPL_Transceiver_Param import *


Tx_Rx = 0
KeyEvent_Stop = False
data_length = [0x20, 0x20, 0x20, 0x20, 0x20, 0x20]
usr_defined_pload = False
usr_defined_ploads = ""
usr_defined_ploads_len = 0


def KeyEvent_Handler(signal, frame):
	global KeyEvent_Stop

	KeyEvent_Stop = True
	# print "Enter command line mode ... "

signal.signal(signal.SIGINT, KeyEvent_Handler)


class EPL_Transceiver:
    def __init__(self, conn):
        self.connection = conn
        self.debug = True

    def string2int(self, indata):
        indata = "0x" + indata
        return int(indata, 16)

    def get_ret_val(self):
        # chcek result
        ret_val = self.connection.recvCmd(3)
        if ret_val == "ACK":
            return 0
        elif ret_val == "NAK":
            return 1
        else:
            print "ERROR GET_RET_VAL!!"
            return -1

    def enter_sender_mode(self):
        global Tx_Rx
        Tx_Rx = 0

        cmd = OP_transceiver + EPL_SENDER_MODE
        if self.debug:
            print "Sender mode: " + cmd
        self.connection.sendCmd(cmd)

    def enter_dumper_mode(self):
        global Tx_Rx
        Tx_Rx = 1

        cmd = OP_transceiver + EPL_DUMPER_MODE
        if self.debug:
            print "Dumper mode: " + cmd
        self.connection.sendCmd(cmd)

    def show_config(self):
        cmd = OP_transceiver + EPL_SHOW_CONFIG
        self.connection.sendCmd(cmd)

    def set_output_power(self, indata):
        # send cmdrun
        cmd = OP_transceiver + EPL_OUTPUT_POWER + indata
        if self.debug:
            print "output power = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_channel(self, indata):
        cmd = OP_transceiver + EPL_CHANNEL	+ indata
        if self.debug:
            print "channel = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_datarate(self, indata):
        cmd = OP_transceiver + EPL_DATARATE	+ indata
        if self.debug:
            print "datarate = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_addr_width(self, indata):
        cmd = OP_transceiver + EPL_ADDR_WIDTH + indata
        if self.debug:
            print "address width = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_autoack(self, pipe_num, indata):
        OP_AUTOACK = {
            0: EPL_AUTOACK_P0,
            1: EPL_AUTOACK_P1,
            2: EPL_AUTOACK_P2,
            3: EPL_AUTOACK_P3,
            4: EPL_AUTOACK_P4,
            5: EPL_AUTOACK_P5
        }[pipe_num]

        cmd = OP_transceiver + OP_AUTOACK + indata
        if self.debug:
            print "Pipe %d auto ack = %s" % (pipe_num, cmd)
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_dynamic_payload(self, pipe_num, indata):
        cmd = OP_transceiver + EPL_DYNAMIC_PD + str(pipe_num).zfill(2) + indata
        if self.debug:
            print "Pipe %d dynamic payload = %s" % (pipe_num, cmd)
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_data_length(self, pipe_num, indata):
        OP_DATA_LENGTH = {
            0: EPL_DATA_LENGTH_P0,
            1: EPL_DATA_LENGTH_P1,
            2: EPL_DATA_LENGTH_P2,
            3: EPL_DATA_LENGTH_P3,
            4: EPL_DATA_LENGTH_P4,
            5: EPL_DATA_LENGTH_P5
        }[pipe_num]

        data_length[pipe_num] = int(("0x"+indata), 16)
        cmd = OP_transceiver + OP_DATA_LENGTH + indata
        if self.debug:
            print "Pipe %d data length = %s" % (pipe_num, cmd)
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_crc_mode(self, indata):
        cmd = OP_transceiver + EPL_CRC_MODE + indata
        if self.debug:
            print "CRC mode = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_dest_addr(self, pipe_num, indata):
        indata = ''.join(indata)
        OP_DEST_ADDR = {
            0: EPL_RX_ADDR_P0,
            1: EPL_RX_ADDR_P1,
            2: EPL_RX_ADDR_P2,
            3: EPL_RX_ADDR_P3,
            4: EPL_RX_ADDR_P4,
            5: EPL_RX_ADDR_P5
        }[pipe_num]
        cmd = OP_transceiver + OP_DEST_ADDR + str(indata).zfill(2)
        if self.debug:
		    print "Pipe %d addr = %s" % (pipe_num, cmd)
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def set_usr_pload(self, usr_definedp, indata):
        global usr_defined_ploads

        usr_defined_ploads = indata
        if usr_definedp == True:
            cmd = OP_transceiver + EPL_USER_PLOAD + USRS_PLOAD + indata
        else:
            cmd = OP_transceiver + EPL_USER_PLOAD + AUTO_PLOAD

        if self.debug:
            print "usr pload = " + cmd
        self.connection.sendCmd(cmd)
        return self.get_ret_val()

    def run_sender(self):
        global KeyEvent_Stop
        global data_length
        global usr_defined_pload
        global usr_defined_ploads
        global usr_defined_ploads_len

        pkt_count = 1
        KeyEvent_Stop = False

		# send Cmd to LU1
        cmd = OP_transceiver + EPL_NEW_COUNTER
        self.connection.sendCmd(cmd)
        ret_val = self.connection.recvCmd(3)

        print "\r\nRF sending procedure begin ..."
        print "Press Ctrl + c to Stop.\r\n"

        while KeyEvent_Stop == False:
			# send Cmd to LU1
            if usr_defined_pload == True:
                cmd = OP_transceiver + EPL_RUN_SENDER + USRS_PLOAD
            else:
                cmd = OP_transceiver + EPL_RUN_SENDER + AUTO_PLOAD
            self.connection.sendCmd(cmd)
            ret_val = self.connection.recvCmd(4)

            # print msg on console
            print "Transmit " + str(pkt_count) + "'s packet."
            print "Auto Retransmission Count: %d" % ord(ret_val[3])

            if usr_defined_pload == True:
                if usr_defined_ploads_len < 16:
                    print "0x0000: ",
                    for i in range (usr_defined_ploads_len):
                        print "%02X " % self.string2int(usr_defined_ploads[2*(i+1):2*(i+2)]),
                else:
                    print "0x0000: ",
                    for i in range (16):
                        print "%02X " % self.string2int(usr_defined_ploads[2*(i+1):2*(i+2)]),
                    print "\r\n0x0010: ",
                    for i in range (usr_defined_ploads_len-16):
                        print "%02X " % self.string2int(usr_defined_ploads[(2*(i+1)+32):(2*(i+2)+32)]),
                print "\r\nEnd Packet.\r\n"
            else:
                if data_length[0] < 16:
                    print "0x0000: ",
                    for i in range (data_length[0]):
                        if i == 0:
                            print "%02X " % (pkt_count%256),
                        else:
                            print "%02X " % (i+9),
                else:
                    print "0x0000: ",
                    for i in range (16):
                        if i == 0:
                            print "%02X " % (pkt_count%256),
                        else:
                            print "%02X " % (i+9),

                    print "\r\n0x0010: ",
                    for i in range (data_length[0]-16):
                        print "%02X " % (i+9+16),
                print "\r\nEnd Packet.\r\n"

                if ret_val[0:3] != "ACK":
                    print "ERROR: Connection Failed"
                    break

            pkt_count += 1

            try:
                time.sleep(0.5)
            except:
                pass

        print "Stop RF sending process . "
        print "Enter command line mode ... "
        KeyEvent_Stop = False

    def run_dumper(self):
        global KeyEvent_Stop
        # global data_length
        pkt_count = 1

        cmd = OP_transceiver + EPL_RUN_DUMPER + "00"
        if self.debug:
            print "RUN DUMPER: " + cmd
        self.connection.sendCmd(cmd)
        print "RF receving procedure begin ..."
        print "Press Ctrl + c to Stop.\r\n"

        while True:
            # Press Ctrl + C will set KeyEvent_Stop to be true in KeyEvent_Handler.
            if KeyEvent_Stop == True:
                cmd = OP_transceiver + EPL_EXIT_DUMPER
                self.connection.sendCmd(cmd)
                KeyEvent_Stop = False
                break

            try:
                ret_val = self.connection.recvCmd(34)

                pipe_num = ord(ret_val[32])
                data_length = ord(ret_val[33])

                print "The %d\'st Packet from PIPE %d:  (%d Bytes)" % (pkt_count, pipe_num, data_length)

                c = 0
                if data_length > 16:
                    print "0x0000: ",
                    while c < 16:
                        print "%02X " % ord(ret_val[c]),
                        c = c + 1
                    print ""

                    c = 0
                    print "0x0010: ",
                    while c < (data_length -16):
                        print "%02X " % ord(ret_val[c+16]),
                        c = c + 1
                    print ""
                else:
                    print "0x0000: ",
                    while c < data_length:
                        print "%02X " % ord(ret_val[c]),
                        c = c + 1
                    print ""

                print "End Packet!"
                print ""
                pkt_count += 1
            except:
                pass
        print "Stop RF receiving process . "
        print "Enter command line mode ... "
        KeyEvent_Stop = False

    def InitLU1RF(self):
        self.set_output_power("03")
        self.set_channel("64")
        self.set_datarate("01")
        self.set_addr_width("05")
        self.set_autoack(0,ON)
        self.set_dest_addr(0,["65","65","65","65","65"])
        self.set_data_length(0,"20")
        self.set_dynamic_payload(0,OFF)
        self.set_crc_mode("03")
        self.enter_dumper_mode()

    def sendData(self, data):
        self.data_flush(DATA_TX)
        self.enter_sender_mode()
        cmd = binascii.unhexlify(OP_transceiver + EPL_USER_PLOAD + USRS_PLOAD) + chr(32) + data
        self.connection.sendData(cmd)
        self.get_ret_val()
        cmd = binascii.unhexlify(OP_transceiver + EPL_RUN_SENDER + USRS_PLOAD)
        self.connection.sendData(cmd)
        ret_val = self.get_ret_val()

    def readData(self, Length):
        data = self.connection.recvCmd(Length+2)
        return data[:32]

