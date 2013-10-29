#!/usr/bin/env python

import transceiver.EPL_Transceiver as EPL_Transceiver
import transceiver.epl_usb_lib as epl_usb_lib
from transceiver.EPL_Transceiver_Param import *
import time
import struct
import signal

recv_addr = ["01", "01", "0F", "65", "65"]
send_addr = ["E6", "E6", "E6", "65", "65"]

prog_stop = False

def sigint_handler(signal, frame):
    global prog_stop
    prog_stop = True

signal.signal(signal.SIGINT, sigint_handler)

connection = epl_usb_lib.EPL_USB()
transceiver = EPL_Transceiver.EPL_Transceiver(connection)

transceiver.set_output_power("03") # 00: -18dB, 01: -12dB, 02: -6dB, 03: 0dB
transceiver.set_channel("0A") # Channel 10
transceiver.set_datarate("00")  # 00: 1Mbps, 01: 2Mbps
transceiver.set_addr_width("03")
# PIPE 0 setup
transceiver.set_autoack(0, OFF)
transceiver.set_dest_addr(0, send_addr)
transceiver.set_data_length(0, "0A")
transceiver.set_dynamic_payload(0, OFF)
# PIPE setup
#for i in range(1, 6):
#    transceiver.set_autoack(i, ON)
#    addr = "%02X" % i
#    transceiver.set_dest_addr(i, [addr, "01", "01", "01", "01"])
#    transceiver.set_data_length(i, "20")
#    transceiver.set_dynamic_payload(i, OFF)

transceiver.set_crc_mode("02") # 0: off, 02: 8-bit, 03: 16-bit
#transceiver.enter_sender_mode()

# pause before setting is ready
#time.sleep(0.01)


pkt_count = 1
fs = 2
while True:
    if prog_stop:
        break

    transceiver.set_dest_addr(0, send_addr)
    transceiver.enter_sender_mode()
    time.sleep(0.01)

    # setup packet
    cmd = OP_transceiver + EPL_USER_PLOAD + USRS_PLOAD
    eco_gid = 10
    pkt_len = 2
    cmd += "%02X%02X%02X" % (pkt_len, eco_gid, fs)
    print cmd
    try:
        connection.sendCmd(cmd)
        ret_val = connection.recvCmd(4)
        print ret_val
    except Exception as e:
        print e

    # reset LU1 counter
#    cmd = OP_transceiver + EPL_NEW_COUNTER
#    try:
#        connection.sendCmd(cmd)
#        ret_val = connection.recvCmd(3)
#        print ret_val
#    except Exception as e:
#        print e

    # send packet
    cmd = OP_transceiver + EPL_RUN_SENDER + USRS_PLOAD
    try:
        connection.sendCmd(cmd)
        ret_val = connection.recvCmd(4)
 #       print ret_val
    except Exception as e:
        print e

    # switch to receive mode
    transceiver.set_dest_addr(0, recv_addr)
    transceiver.enter_dumper_mode()

    # pause before setting is ready
#    time.sleep(0.01)
    cmd = OP_transceiver + EPL_RUN_DUMPER + "00"
    try:
        connection.sendCmd(cmd)
    except Exception as e:
        print e
    while True:
        if prog_stop:
            break

        try:
            ret_val = connection.recvCmd(34)

            pipe_num = ord(ret_val[32])
            data_length = ord(ret_val[33])
            payload = ret_val[0:32]
            print "PKT %03d" % pkt_count,

            stop = False
            for line in range(2):
                if stop:
                    break
                print "0x%04X: " % line,
                for i in range(16):
                    idx = line * 16 + i
                    if idx < data_length:
                        print "%02X" % ord(payload[idx]),
                    else:
                        stop = True
                        break
                print ""
        except Exception as e:
            print e
    cmd = OP_transceiver + EPL_EXIT_DUMPER
    connection.sendCmd(cmd)


    pkt_count += 1
    time.sleep(1)
