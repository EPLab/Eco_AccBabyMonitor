# Description: Multiceiver for LU1
# Celine Liu <tzuchung1030@gmail.com>
# Date:    2011/02/22
# version: dynamic payload length
# Note: 1. Data Pipe 0 has a unique 5 byte address.
#          Data Pipes 1-5 share the 4 most significant address bytes. The LSByte must be unique for all 6 pipes.
#          If you want to use Data Pipes 2-5, you have to open Pipe 1 and set the most significant same bytes.
#       2. Static or Dynamic payload length could be set by dynpd, and PTX and PRX must be set consistently.
import EPL_Transceiver
import epl_usb_lib
import sys
from EPL_Transceiver_Param import *

addr_width = 5

connection = epl_usb_lib.EPL_USB()
transceiver = EPL_Transceiver.EPL_Transceiver(connection)

def string2int(indata):
	indata = "0x" + indata
	return int(indata, 16)

class usr_set_config:

	def __init__(self):
		#print "Enter _init_"
		self.config = {"output_power":"03", "channel":"76", "datarate":"00", "addr_width":"05",
					"pipe":[ON,OFF,OFF,OFF,OFF,OFF], "dest_addr":[["65","65","65","65","65"],["01","01","01","01","01"],["02","01","01","01","01"],["03","01","01","01","01"],["04","01","01","01","01"],["05","01","01","01","01"]],
					"autoack":[ON,ON,ON,ON,ON,ON], "dynpd":[OFF,OFF,OFF,OFF,OFF,OFF], "data_length": ["20","20","20","20","20","20"], "crc_mode":"03"}
		EPL_Transceiver.pload_length = 32
		EPL_Transceiver.usr_defined_pload = False
		EPL_Transceiver.usr_defined_ploads = ""
		EPL_Transceiver.usr_defined_ploads_len = 0
		EPL_Transceiver.data_length = [0x20,0x20,0x20,0x20,0x20,0x20]
		self.cpy_init()
		#self.set_init_config()

	def cpy_init(self):
		#print "Enter cpy_init"
		self.config = {"output_power":"03", "channel":"06", "datarate":"00", "addr_width":"03",
					"pipe":[ON,OFF,OFF,OFF,OFF,OFF], "dest_addr":[["01","01","0F","65","65"],["01","01","01","01","01"],["02","01","01","01","01"],["03","01","01","01","01"],["04","01","01","01","01"],["05","01","01","01","01"]],
					"autoack":[OFF,ON,ON,ON,ON,ON], "dynpd":[OFF,OFF,OFF,OFF,OFF,OFF], "data_length": ["06","20","20","20","20","20"], "crc_mode":"02"}
		EPL_Transceiver.pload_length = 32
		EPL_Transceiver.usr_defined_pload = False
		EPL_Transceiver.usr_defined_ploads = ""
		EPL_Transceiver.usr_defined_ploads_len = 0
		EPL_Transceiver.data_length = [0x20,0x20,0x20,0x20,0x20,0x20]
		self.set_init_config()

	def set_init_config(self):
		#print "Enter set_init_config"
		ret_val = transceiver.set_output_power(self.config["output_power"])
		if ret_val == 1:
			print "ERROR: set_init_output_power"

		ret_val = transceiver.set_channel(self.config["channel"])
		if ret_val == 1:
			print "ERROR: set_init_channel"

		ret_val = transceiver.set_datarate(self.config["datarate"])
		if ret_val == 1:
			print "ERROR: set_init_datarate"

		ret_val = transceiver.set_addr_width(self.config["addr_width"])
		if ret_val == 1:
			print "ERROR: set_init_addr_width"

		for i in range(6):
			ret_val = transceiver.set_autoack(i, self.config["autoack"][i])
			if ret_val == 1:
				print "ERROR: set_init_autoack"
			ret_val = transceiver.set_dest_addr(i, self.config["dest_addr"][i])
			if ret_val == 1:
				print "ERROR: set_init_dest_addr"
			ret_val = transceiver.set_data_length(i, self.config["data_length"][i])
			if ret_val == 1:
				print "ERROR: set_init_data_length"
			ret_val = transceiver.set_dynamic_payload(i, self.config["dynpd"][i])
			if ret_val == 1:
				print "ERROR: set_init_dynamic_payload"

		ret_val = transceiver.set_crc_mode(self.config["crc_mode"])
		if ret_val == 1:
			print "ERROR: set_init_crc_mode"


	def set_output_power(self):
		while True:
			try:
				if self.config["output_power"] == "03":
					config_output_power = 0
				elif self.config["output_power"] == "02":
					config_output_power = 6
				elif self.config["output_power"] == "01":
					config_output_power = 12
				elif self.config["output_power"] == "00":
					config_output_power = 18
				usr_input = raw_input("Output Power [0/6/12/18] (%d): "%(config_output_power))

				if len(usr_input) == 0:
					break
				if int(usr_input) == 0:
					self.config["output_power"] = "03"
					break
				elif int(usr_input) == 6:
					self.config["output_power"] = "02"
					break
				elif int(usr_input) == 12:
					self.config["output_power"] = "01"
					break
				elif int(usr_input) == 18:
					self.config["output_power"] = "00"
					break
			except:
				pass

		ret_val = transceiver.set_output_power(self.config["output_power"])
		if ret_val == 1:
			print "ERROR: SET OUTPUT POWER"


	def set_channel(self):
		while True:
			try:
				usr_input = raw_input("Channel [0~125] (%d): "%(string2int(self.config["channel"])))
				if len(usr_input) == 0:
					break

				if int(usr_input) >= 0 and int(usr_input) < 126:
					usr_input = hex(int(usr_input))
					self.config["channel"] = str(usr_input)[2:].zfill(2)
					break
			except:
				pass
		ret_val = transceiver.set_channel(self.config["channel"])
		if ret_val == 1:
			print "ERROR: SET CHANNEL"


	def set_datarate(self):
		while True:
			try:
				usr_input = raw_input("RF Datarate [1/2] (%d): "%(string2int(self.config["datarate"])+1))
				if len(usr_input) == 0:
					break

				if int(usr_input) == 1:
					self.config["datarate"] = "00"
					break
				elif int(usr_input) == 2:
					self.config["datarate"] = "01"
					break
			except:
				pass

		ret_val = transceiver.set_datarate(self.config["datarate"])
		if ret_val == 1:
			print "ERROR: SET DATARATE"


	def set_addr_width(self):
		global addr_width
		while True:
			try:
				usr_input = raw_input("Address Width [3/4/5] (%d): "%(string2int(self.config["addr_width"])))
				if len(usr_input) == 0:
					break

				if int(usr_input) == 3:
					addr_width = 3
					self.config["addr_width"] = "03"
					break
				elif int(usr_input) == 4:
					addr_width = 4
					self.config["addr_width"] = "04"
					break
				elif int(usr_input) == 5:
					addr_width = 5
					self.config["addr_width"] = "05"
					break
			except:
				pass

		ret_val = transceiver.set_addr_width(self.config["addr_width"])
		if ret_val == 1:
			print "ERROR: SET ADDRESS WIDTH"

## Celine -- 2010/11/10
	def set_autoack(self, pipe_num):
		while True:
			try:
				if self.config["autoack"][pipe_num] == ON:
					config_autoack = "on"
				elif self.config["autoack"][pipe_num] == OFF:
					config_autoack = "off"
				usr_input = raw_input("PIPE%d Autoack [on/off] (%s): "%(pipe_num, config_autoack) )
				if len(usr_input) == 0:
					break
				if usr_input == "on" or usr_input == "ON":
					self.config["autoack"][pipe_num] = ON
					break
				elif usr_input == "off" or usr_input == "OFF":
					self.config["autoack"][pipe_num] = OFF
					break
			except:
				pass

		ret_val = transceiver.set_autoack(pipe_num, self.config["autoack"][pipe_num])
		if ret_val == 1:
			print "ERROR: SET AUTOACK"

	def set_data_length(self, pipe_num):
		while True:
			try:
				usr_input = raw_input("PIPE%d Data Length [1~32] (%d): "%(pipe_num, string2int(self.config["data_length"][pipe_num])))
				if len(usr_input) == 0:
					break

				if int(usr_input) >= 0 and int(usr_input) <= 32:
					usr_input = hex(int(usr_input))
					self.config["data_length"][pipe_num] = str(usr_input)[2:].zfill(2)
					break

			except:
				pass

		ret_val = transceiver.set_data_length(pipe_num, self.config["data_length"][pipe_num])
		if ret_val == 1:
			print "ERROR: SET DATA LENGTH"

	# 20110221 celine dynamic payload #
	def set_dynamic_payload(self, pipe_num):
		while True:
			try:
				if self.config["dynpd"][pipe_num] == ON:
					config_dynpd = "on"
				elif self.config["dynpd"][pipe_num] == OFF:
					config_dynpd = "off"
				usr_input = raw_input("PIPE%d Dynamic Payload Length [on/off] (%s): "%(pipe_num, config_dynpd) )
				if len(usr_input) == 0:
					break
				if usr_input == "on" or usr_input == "ON":
					self.config["dynpd"][pipe_num] = ON
					break
				elif usr_input == "off" or usr_input == "OFF":
					self.config["dynpd"][pipe_num] = OFF
					break
			except:
				pass

		ret_val = transceiver.set_dynamic_payload(pipe_num, self.config["dynpd"][pipe_num])
		if ret_val == 1:
			print "ERROR: SET DYNAMIC PAYLOAD"


	def set_crc_mode(self):
		while True:
			try:
				if self.config["crc_mode"] == "00":
					config_crc_mode = "off"
				elif self.config["crc_mode"] == "02":
					config_crc_mode = "8"
				elif self.config["crc_mode"] == "03":
					config_crc_mode = "16"

				usr_input = raw_input("CRC Mode [8/16/off] (%s): "%config_crc_mode)
				if len(usr_input) == 0:
					break

				if usr_input == "off":
					self.config["crc_mode"] = "00"
					break
				elif int(usr_input) == 8:
					self.config["crc_mode"] = "02"
					break
				elif int(usr_input) == 16:
					self.config["crc_mode"] = "03"
					break
			except:
				pass

		ret_val = transceiver.set_crc_mode(self.config["crc_mode"])
		if ret_val == 1:
			print "ERROR: SET CRC MODE"

##	-- Celine 2011/01/20	--
## 	function to set destination address of multiceiver ##
	def set_dest_addr(self, pipe_num):
		global addr_width

		print "PIPE%d Destination Address [1~255] " %(pipe_num)
		if pipe_num < 2:
			SET_BYTE = addr_width - 1
		else:
		#pipe_num >= 2: The LSB 4 bytes are setting parallel to PIPE1 AND only need to set byte 0 #
			SET_BYTE = 0
			self.config["dest_addr"][pipe_num][1:] = self.config["dest_addr"][1][1:]
		current_byte = 0
		while current_byte <= SET_BYTE:
			try:
				usr_input = raw_input("		Byte %d (%3d): "%(current_byte, string2int(self.config["dest_addr"][pipe_num][current_byte])))				if len(usr_input) == 0:
					pass
				elif int(usr_input) >= 0 and int(usr_input) <= 255:
					usr_input = hex(int(usr_input))
					self.config["dest_addr"][pipe_num][current_byte] = str(usr_input)[2:].zfill(2)
				else:
					continue
				## check whether the LSByte of PIPEs are duplicate. If yes, reset the address (byte0).
				if current_byte == 0:
					check_pipe = 0
					while check_pipe <= 5:
						if self.config["pipe"][check_pipe] == ON and pipe_num != check_pipe:
							# the same Byte0
							if self.config["dest_addr"][check_pipe][current_byte] == self.config["dest_addr"][pipe_num][current_byte]:
								print "Byte %d of PIPE%d and PIPE%d are duplicate.Please change PIPE%d's setting." %(current_byte, check_pipe, pipe_num, pipe_num)
								break
							else:
								check_pipe = check_pipe + 1
						else:
							check_pipe = check_pipe + 1
					if check_pipe == 6:
						current_byte = current_byte + 1
				else:
					current_byte = current_byte + 1
			except:
				pass

		ret_val = transceiver.set_dest_addr(pipe_num, self.config["dest_addr"][pipe_num])
		if ret_val == 1:
			print "ERROR: SET DESTINATION ADDRESS"


	def set_usr_pload(self):
		while True:
			try:
				usr_input = raw_input("Customized Pload[y/n] (n): ")
				if len(usr_input) == 0:
					EPL_Transceiver.usr_defined_pload = False
					break

				if usr_input == "n" or usr_input == "N":
					EPL_Transceiver.usr_defined_pload = False
					break
				elif usr_input == "y" or usr_input == "Y":
					EPL_Transceiver.usr_defined_pload = True
					break
			except:
				pass

		if EPL_Transceiver.usr_defined_pload == True:	#Customized
			customized_pload = ""
			while True:
				try:
					usr_input = int(raw_input("Customized Pload Length: "))
					if usr_input > 0 and usr_input < 33:
						EPL_Transceiver.usr_defined_ploads_len = usr_input
						customized_pload = hex(usr_input)[2:].zfill(2)

						c = 0
						while c < usr_input:
							try:
								temp = raw_input("Tx Pload Byte %d [0~255]: " % c)
								if len(temp) == 0:
									customized_pload += "FF"
									c = c + 1
								else:
									if int(temp) >= 0 and int(temp) < 16:
										customized_pload = customized_pload + "0" + (hex(int(temp))[2:])
										c = c + 1
									elif int(temp) >= 16 and int(temp) < 256:
										customized_pload += (hex(int(temp))[2:])
										c = c + 1
							except:
								pass
						break
				except:
					pass
			# Customized
			ret_val = transceiver.set_usr_pload(True, customized_pload)
			if ret_val == 1:
				print "ERROR: SET USER PLOAD"
		else:
			EPL_Transceiver.usr_defined_ploads_len = 0
			ret_val = transceiver.set_usr_pload(False, "")
			if ret_val == 1:
				print "ERROR: SET AUTO PLOAD"

usr_config = usr_set_config()

while True:
	for i in range (22):
		print ""
	print "Welcome to EPL Transceiver !!"

	while True:
		try:
			print "1 sender, 2 dumper, 3 quit."
			usr_input = int(raw_input("EPL Transceiver> "))
			if usr_input == 1:
				usr_config.cpy_init()
				transceiver.enter_sender_mode()
				print "Enter Sender Mode!\r\n"
				break
			elif usr_input == 2:
				usr_config.cpy_init()
				transceiver.enter_dumper_mode()
				print "Enter Dumper Mode!\r\n"
				break
			elif usr_input == 3:
				break

		except:
			pass

	if usr_input == 3:
		sys.exit()


	while True:
		#try:
		if EPL_Transceiver.Tx_Rx == 0:
			usr_input = raw_input("Sender> ")
		elif EPL_Transceiver.Tx_Rx == 1:
			usr_input = raw_input("Dumper> ")
		else:
			print "ERROR: TRANSCEIVER SETTING"

		if usr_input == "q" or usr_input == "quit":
			break

		elif usr_input == "setup":
			print "=============== Setup ==============="
			# user input config
			if EPL_Transceiver.Tx_Rx == 0:	#0: Send mode
				usr_config.set_usr_pload()
			usr_config.set_output_power()
			usr_config.set_channel()
			usr_config.set_datarate()
			usr_config.set_addr_width()
			pipe_num = 0

			if EPL_Transceiver.Tx_Rx == 0:	#0: Send mode
				usr_config.set_autoack(0)
				usr_config.set_dest_addr(0)
				if EPL_Transceiver.usr_defined_pload == False:
					usr_config.set_data_length(0)
				# 20110221 celine #
				usr_config.set_dynamic_payload(0)
			else:
				print "======================================================================="
				print " PIPE0 ~ PIPE5 can receive six different addresses simultaneously."
				print " The LSByte(byte 0) of PIPE0 ~ PIPE5 cannot be duplicate."
				print " And PIPE1 ~ PIPE5 would share the 4 most significant address bytes."
				print " It means if using PIPE1 ~PIPE5, you have to open PIPE1 and set the 4 MSB same address."
				print "======================================================================="
				while pipe_num < 6:
					while True:
						try:
							if usr_config.config["pipe"][pipe_num] == ON:
								pipe_status = "on"
							elif usr_config.config["pipe"][pipe_num] == OFF:
								pipe_status = "off"
							usr_input = raw_input("PIPE%d [on/off] (%s): " %(pipe_num, pipe_status))
							if len(usr_input) == 0:
								break
							elif usr_input == "on" or usr_input == "ON":
								usr_config.config["pipe"][pipe_num] = ON
								break
							elif usr_input == "off" or usr_input == "OFF":
								usr_config.config["pipe"][pipe_num] = OFF
								break
						except:
							pass
					if usr_config.config["pipe"][pipe_num] == ON:
						# Data length should be set behind autoack and destination address.
						# The configuration of autoack and destination address will be set
						# when LU1 receives the config of data length.
						usr_config.set_autoack(pipe_num)
						usr_config.set_dest_addr(pipe_num)
						usr_config.set_data_length(pipe_num)
						usr_config.set_dynamic_payload(pipe_num)
					elif usr_config.config["pipe"][1] == OFF:
						#Will not send config to LU1
						break
					pipe_num = pipe_num + 1
			usr_config.set_crc_mode()

		elif usr_input == "h" or usr_input == "help":
			print "============ Command List ============="
			print "help(h):  Show help descriptions."
			print "show:     Show RF Configurations."
			print "setup:    Setup RF Configurations."
			if EPL_Transceiver.Tx_Rx == 0:
				print "run(r):   Start to Transmit RF packets."
			else:
				print "run(r):   Start to Receive RF Packets."
			print "cls:      Clear Screen."
			print "quit(q):  Back to EPL Transceiver. "
			print "=======================================\r\n"

		elif usr_input == "r" or usr_input == "run":
			#transceiver.set_pipe_status(usr_config.config["pipe"])
			if EPL_Transceiver.Tx_Rx == 0:
				transceiver.run_sender()
			elif EPL_Transceiver.Tx_Rx == 1:
				transceiver.run_dumper()

		elif usr_input == "show":
			transceiver.show_config()
			print "========= RF Configuration ========="

			print "Output Power:      ",
			if usr_config.config["output_power"] == "00":
				print "-18 dbm"
			elif usr_config.config["output_power"] == "01":
				print "-12 dbm"
			elif usr_config.config["output_power"] == "02":
				print "-6 dbm"
			else:
				print "0 dbm"

			print "RF Channel:        ",
			print "0x%s" % usr_config.config["channel"]	,
			print "(%d)" % string2int(usr_config.config["channel"])

			print "RF Datarate:       ",
			print "%d Mbps" % (string2int(usr_config.config["datarate"])+1)

			print "Address Width:     ",
			print "%d Bytes" % string2int(usr_config.config["addr_width"])


			if EPL_Transceiver.Tx_Rx == 0:	#send
				print "PIPE 0 Address:    ",
				if usr_config.config["addr_width"] == "05":
					print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][0][0:5])),
					print "(%3d, %3d, %3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][0][0]),string2int(usr_config.config["dest_addr"][0][1]), string2int(usr_config.config["dest_addr"][0][2]), string2int(usr_config.config["dest_addr"][0][3]),string2int(usr_config.config["dest_addr"][0][4]))
				elif usr_config.config["addr_width"] == "04":
					print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][0][0:4])),
					print "(%3d, %3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][0][0]),string2int(usr_config.config["dest_addr"][0][1]), string2int(usr_config.config["dest_addr"][0][2]), string2int(usr_config.config["dest_addr"][0][3]))
				elif usr_config.config["addr_width"] == "03":
					print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][0][0:3])),
					print "(%3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][0][0]),string2int(usr_config.config["dest_addr"][0][1]), string2int(usr_config.config["dest_addr"][0][2]))
				if EPL_Transceiver.usr_defined_pload == True:
					print "       Data Length:",
					print "%d Bytes [Customized]" % EPL_Transceiver.usr_defined_ploads_len
				else:
					print "       Data Length:",
					print "%d Bytes" % string2int(usr_config.config["data_length"][0])
				print "       Autoack:    ",
				if usr_config.config["autoack"][0] == ON:
					print "ON"
				else:
					print "OFF"
				print "       Dyn Payload:",
				if usr_config.config["dynpd"][0] == ON:
					print "ON"
				else:
					print "OFF"

			else: #EPL_Transceiver.Tx_Rx == 1
				pipe_num = 0
				while pipe_num < 6:
					if	usr_config.config["pipe"][pipe_num] == ON:
						print "PIPE %d Address:    "%pipe_num,
						if usr_config.config["addr_width"] == "05":
							print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][pipe_num][0:5])),
							print "(%3d, %3d, %3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][pipe_num][0]),string2int(usr_config.config["dest_addr"][pipe_num][1]), string2int(usr_config.config["dest_addr"][pipe_num][2]), string2int(usr_config.config["dest_addr"][pipe_num][3]),string2int(usr_config.config["dest_addr"][pipe_num][4]))
						elif usr_config.config["addr_width"] == "04":
							print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][pipe_num][0:4])),
							print "(%3d, %3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][pipe_num][0]),string2int(usr_config.config["dest_addr"][pipe_num][1]), string2int(usr_config.config["dest_addr"][pipe_num][2]), string2int(usr_config.config["dest_addr"][pipe_num][3]))
						elif usr_config.config["addr_width"] == "03":
							print "0x%s" % (', 0x'.join(usr_config.config["dest_addr"][pipe_num][0:3])),
							print "(%3d, %3d, %3d)" %( string2int(usr_config.config["dest_addr"][pipe_num][0]),string2int(usr_config.config["dest_addr"][pipe_num][1]), string2int(usr_config.config["dest_addr"][pipe_num][2]))
						print "       Data Length:",
						print "%d Bytes" % string2int(usr_config.config["data_length"][pipe_num])
						print "       Autoack:    ",
						if usr_config.config["autoack"][pipe_num] == ON:
							print "ON"
						else:
							print "OFF"
						print "       Dyn Payload:",
						if usr_config.config["dynpd"][pipe_num] == ON:
							print "ON"
						else:
							print "OFF"

						print ""
					pipe_num = pipe_num +1

			print "CRC Mode:          ",
			if usr_config.config["crc_mode"] == "02":
				print "8 Bits Mode"
			elif usr_config.config["crc_mode"] == "03":
				print "16 Bits Mode"
			elif usr_config.config["crc_mode"] == "00":
				print "OFF"

			print ""

		elif usr_input == "cls":
			for i in range (20):
				print ""

	#except:
	#	pass
