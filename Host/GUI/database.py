from Tkinter import *
import time
#import dbi, odbc
from socket import *

bits = 0   # 0 = 8 bits, 1 = 12 bits
# xxx [] = [ {8bits}, {12 bits}]
one_g = [40,624]
num_loop = 5000
max_value = one_g[bits]*2
min_value = one_g[bits]*2*(-1)
shift = [170,2800]




def show2(self):

	print "2"


def TestConn(self):
	
	#import msvcrt   #   (Windows/DOS only). This module gives you access to a number of functions in the Microsoft Visual C/C++ Runtime Library (MSVCRT).
	import struct, string

	
	running = 5
	connected = 0
	self.socket.settimeout(5)
	#self.socket.
	r = struct.pack('h', 100)
	#addr = ('192.168.0.3', 2001)
	addr = (self.IP_Basestation_1 , 2001)

 	cmd='ft'
        r = struct.pack('h', 100)
        #print r+':'+cmd
        buf = self.socket.sendto(r+':'+cmd, addr)
 
    	
    	try:
        	buf, addr = self.socket.recvfrom(1024)
        	print 'Connection between host and base station is ok. Testing connection throughput'
    		connected = 1
    	except:
        	pass
	
	id = 0
	self.file_loaded = 0
	self.x_curve[id] = []
	self.y_curve[id] = []
	self.z_curve[id] = []
	self.start[id]   = 0
	self.maxx[id]    = 0
	self.maxy[id]    = 0
	self.maxz[id]    = 0

	
	
	begin_time = float(time.clock())
	
	for i in range(1,num_loop,1):
		
		        	
		#self.socket.sendto("h", addr)
		buf = self.socket.sendto(r+':'+cmd, addr)
		buf, addr = self.socket.recvfrom(1024)
	        #buf, addr = self.socket.recvfrom(2048)
	
	receive_time = float(time.clock())
        r1 = int(struct.unpack('B', buf[0])[0])
	r2 = int(struct.unpack('B', buf[1])[0])
	r3 = int(struct.unpack('B', buf[2])[0])
	r4 = int(struct.unpack('B', buf[3])[0])
	r5 = int(struct.unpack('B', buf[4])[0])                  
	r6 = int(struct.unpack('B', buf[5])[0])
	r7 = int(struct.unpack('B', buf[6])[0])
	r8 = int(struct.unpack('B', buf[7])[0])
	r9 = int(struct.unpack('B', buf[8])[0])
	r10 = int(struct.unpack('B', buf[9])[0])
	r11 = int(struct.unpack('B', buf[10])[0])
	r12 = int(struct.unpack('B', buf[11])[0])
	r13 = int(struct.unpack('B', buf[12])[0])
	r14 = int(struct.unpack('B', buf[13])[0])
	r15 = int(struct.unpack('B', buf[14])[0])                  
	r16 = int(struct.unpack('B', buf[15])[0])
	r17 = int(struct.unpack('B', buf[16])[0])
	r18 = int(struct.unpack('B', buf[17])[0])
	r19 = int(struct.unpack('B', buf[18])[0])
	r20 = int(struct.unpack('B', buf[19])[0])                           
	r21 = int(struct.unpack('B', buf[20])[0])
	r22 = int(struct.unpack('B', buf[21])[0])
	r23 = int(struct.unpack('B', buf[22])[0])
	r24 = int(struct.unpack('B', buf[23])[0])
	r25 = int(struct.unpack('B', buf[24])[0])                  
	r26 = int(struct.unpack('B', buf[25])[0])
	r27 = int(struct.unpack('B', buf[26])[0])
	
	#print "receive", r1, "begin time", begin_time," receive time" , receive_time ,"spend", receive_time-begin_time, " second"
	print "receive:", r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,r21,r22,r23,r24,r25,r26,r27, "Time Spend:", receive_time-begin_time,"second, Max Sample Rate :", int(num_loop/(receive_time-begin_time)), "requests/second \n"
	#print "receive:", r1,r2,r3,r4,r5,r6,",Time Spend:", receive_time-begin_time,"second, \nMax Sample Rate :", (int(1/(receive_time-begin_time))*2), "samples/s \n"
	#print "receive:", r1,r2,r3,r4,r5,r6,r7,r8,r9,",Time Spend:", receive_time-begin_time,"second, \nMax Sample Rate :", int(1/(receive_time-begin_time))*3, "samples/s \n"
	
	
	#print " spend %s"%(receive_time-begin_time)
	
	#print 'id', self.serverlist[id], 'socket list', self.socketlist[id]
	#self.socketlist[id] = socket.socket(AF_INET, SOCK_DGRAM, 0)
	#self.socketlist[id].settimeout(5)
	#self.socketlist[id] = mysocket
	#soc = my_socket.openSocket(0, self.socketlist[id], self.serverlist[id], port)
	#print 'Established connection'
	#print 'socket list', self.socketlist[id]
	#self.socketlist[id].send("H")
	#try:
	#	buf = self.socketlist[id].recv(8)
	#	print 'Get Data' 
       	#except:
	#	print 'Cannot connect to node!' 
	#	self.socketlist[id].close()	
	#	return
	

def Firmwareveresion(self):

	
	#import msvcrt   #   (Windows/DOS only). This module gives you access to a number of functions in the Microsoft Visual C/C++ Runtime Library (MSVCRT).
	import struct, string

	
	running = 5
	connected = 0
	self.socket.settimeout(5)
	addr = (self.IP_Basestation_1 , 2001)
	
 	cmd='fl\x40\x20\x03\x33\x12\x01\x01\x01'
        r = struct.pack('h', 100)
        #print r+':'+cmd
        buf = self.socket.sendto(r+':'+cmd, addr)
 
    	
    	try:
        	buf, addr = self.socket.recvfrom(1024)
        	print 'Connection testing is successful. Get Firmware Version'
    		connected = 1
    	except:
        	pass
	
#	id = 0
#	self.file_loaded = 0
#	self.x_curve[id] = []
#	self.y_curve[id] = []
#	self.z_curve[id] = []
#	self.start[id]   = 0
#	self.maxx[id]    = 0
#	self.maxy[id]    = 0
#	self.maxz[id]    = 0

	
	buf = self.socket.sendto(r+':'+cmd, addr)
	buf, addr = self.socket.recvfrom(1024)
	r1 = int(struct.unpack('B', buf[0])[0])
	r2 = int(struct.unpack('B', buf[1])[0])
	r3 = int(struct.unpack('B', buf[2])[0])
	r4 = int(struct.unpack('B', buf[3])[0])
	r5 = int(struct.unpack('B', buf[4])[0])                  
	r6 = int(struct.unpack('B', buf[5])[0])
	r7 = int(struct.unpack('B', buf[6])[0])
	r8 = int(struct.unpack('B', buf[7])[0])
	r9 = int(struct.unpack('B', buf[8])[0])
	r10 = int(struct.unpack('B', buf[9])[0])
	r11 = int(struct.unpack('B', buf[10])[0])
	r12 = int(struct.unpack('B', buf[11])[0])
	r13 = int(struct.unpack('B', buf[12])[0])
	r14 = int(struct.unpack('B', buf[13])[0])
	r15 = int(struct.unpack('B', buf[14])[0])                  
	r16 = int(struct.unpack('B', buf[15])[0])
	r17 = int(struct.unpack('B', buf[16])[0])
	r18 = int(struct.unpack('B', buf[17])[0])
	r19 = int(struct.unpack('B', buf[18])[0])
	r20 = int(struct.unpack('B', buf[19])[0])                           
	r21 = int(struct.unpack('B', buf[20])[0])
	r22 = int(struct.unpack('B', buf[21])[0])
	r23 = int(struct.unpack('B', buf[22])[0])
	r24 = int(struct.unpack('B', buf[23])[0])
	r25 = int(struct.unpack('B', buf[24])[0])                  
	r26 = int(struct.unpack('B', buf[25])[0])
	r27 = int(struct.unpack('B', buf[26])[0])
	
	print "receive:", r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,r21,r22,r23,r24,r25,r26,r27, "\n"
	



def SetFrequency(self):

	#import msvcrt   #   (Windows/DOS only). This module gives you access to a number of functions in the Microsoft Visual C/C++ Runtime Library (MSVCRT).
	import struct, string



	
	running = 5
	connected = 0
	self.socket.settimeout(5)
	addr = (self.IP_Basestation_1 , 2001)
	
        #cmd='ff\xc0\x20\x04\x33\x42\x0E\x64\x64'	#Set Channel data
        cmd='ff\x00\x20\x05\x33\x42\x64\x01\x01'	#Query Channel data
        
        r = struct.pack('h', 100)
        #print r+':'+cmd
        buf = self.socket.sendto(r+':'+cmd, addr)
 
    	
    	try:
        	buf, addr = self.socket.recvfrom(1024)
        	self.CurrentFrequency = int(struct.unpack('B', buf[0])[0])
        	print 'Connection to BS is successful. Get RF channel information'
        	connected = 1
    	except:
        	pass
	
	
	print "Current RF Channel is %i"%(self.CurrentFrequency)
	self.CurrentFrequencystr.set(self.CurrentFrequency)
	

	def setval():
		
		
		id = int(self.nodestr.get())
		CurrentFrequency = int(self.CurrentFrequencystr.get())
		
		addr = (self.IP_Basestation_1 , 2001)
        	r = struct.pack('h', 100)
		
		cmd='ff\xc0\x20\x04\x33\x42\x0E' +chr(CurrentFrequency) +'\x64'	#Set Channel data
       		print cmd
       		
       		buf = self.socket.sendto(r+':'+cmd, addr)
	    	
	    	try:
	        	buf, addr = self.socket.recvfrom(1024)
	        	r1 = int(struct.unpack('B', buf[0])[0])
	        	print r1
	        	print 'The new frequency is %i'%(CurrentFrequency)
	    	except:
			print 'Changing the new frequency process is failed'
			
		nf.destroy()
	
	
	# open a popup window
	nf = Toplevel()
	t = "Set Frequency"
	nf.title(t)
	self.status.set(t)
	infoFrame = Frame(nf, width = self.nodewin_width,
	              height = self.nodewin_height,  bd = 1)
	infoFrame.pack(fill = BOTH, expand = 0)



	Label(infoFrame,  text = 'Current RF Frequency:').grid(row = 0, column = 1, sticky = W)
	Entry(infoFrame, textvariable = self.CurrentFrequencystr).grid(row = 0, column = 2)
	Button(infoFrame, text = 'OK', command = setval).grid(row = 2, column = 2)



#def ParserCommand(self, file = "D:/doc/Python/WirelessController/Command.txt"):
def ParserCommand(self, file = ""):
		
			
	#import msvcrt   #   (Windows/DOS only). This module gives you access to a number of functions in the Microsoft Visual C/C++ Runtime Library (MSVCRT).
	import struct, string
	from tkFileDialog import askopenfilename
	
	running = 5
	connected = 0
	self.socket.settimeout(5)
	addr = (self.IP_Basestation_1 , 2001)
	r = struct.pack('h', 100)
	
	
	hex_table = {
		"0":"0",
		"1":"1",
		"2":"2",
		"3":"3",
		"4":"4",
		"5":"5",
		"6":"6",
		"7":"7",
		"8":"8",
		"9":"9",
		"a":"10",
		"b":"11",
		"c":"12",
		"d":"13",
		"e":"14",
		"f":"15",			
		"A":"10",
		"B":"11",
		"C":"12",
		"D":"13",
		"E":"14",
		"F":"15"			
		
		}

#	def hta(s):
#		s = '\000' + s
#   		h = ""
#    		for c in s:
#        		h = h + '%2x' % ord(c)
#    		return h
	
	
        			
	if file =="":
		file = askopenfilename(title="Open Command File",
		                       filetypes = (("Plain Text", "*"), #".txt"),
                                       ("All File", "*"))
                                          )
                print file
		if file:
			import os
			profileName        = os.path.basename(file)
			profilePath        = os.path.dirname(file)
		
			try:
				os.chdir(profilePath)
			except:
				pass	
			
			import string	
			fin = open(profileName, 'r')
			line = fin.readline().split()
		        
		        while len(line):
				
				#a=line.pop(0)
				#print a[0],' and ', a[1]
				
				cmd='fl'
	        		while len(line):
#	        			#buf = self.socket.sendto(r+':'+cmd, addr)
#	 				#print line.pop(0)
					#cmd='fl'
					temp_string = line.pop(0)
					#print temp_string
					#temp_string = 
					#print hex_table[temp_string[0]]
					#print hex_table[temp_string[1]]
					
					
					a = int(hex_table[temp_string[0]])*16 + int(hex_table[temp_string[1]])
					cmd = cmd + chr(a)
#	 				#print len(line)
#	 				#cmd = cmd + chr(int(line.pop(0)))
#	 				#print len(line)
	 			print cmd
				
				try:
					buf = self.socket.sendto(r+':'+cmd, addr)
					buf, addr = self.socket.recvfrom(1024)
					r1 = int(struct.unpack('B', buf[0])[0])
					r2 = int(struct.unpack('B', buf[1])[0])
					r3 = int(struct.unpack('B', buf[2])[0])
					r4 = int(struct.unpack('B', buf[3])[0])
					r5 = int(struct.unpack('B', buf[4])[0])                  
					r6 = int(struct.unpack('B', buf[5])[0])
					r7 = int(struct.unpack('B', buf[6])[0])
					r8 = int(struct.unpack('B', buf[7])[0])
					r9 = int(struct.unpack('B', buf[8])[0])
					r10 = int(struct.unpack('B', buf[9])[0])
					r11 = int(struct.unpack('B', buf[10])[0])
					r12 = int(struct.unpack('B', buf[11])[0])
					r13 = int(struct.unpack('B', buf[12])[0])
					r14 = int(struct.unpack('B', buf[13])[0])
					r15 = int(struct.unpack('B', buf[14])[0])                  
					r16 = int(struct.unpack('B', buf[15])[0])
					r17 = int(struct.unpack('B', buf[16])[0])
					r18 = int(struct.unpack('B', buf[17])[0])
					r19 = int(struct.unpack('B', buf[18])[0])
					r20 = int(struct.unpack('B', buf[19])[0])                           
					r21 = int(struct.unpack('B', buf[20])[0])
					r22 = int(struct.unpack('B', buf[21])[0])
					r23 = int(struct.unpack('B', buf[22])[0])
					r24 = int(struct.unpack('B', buf[23])[0])
					r25 = int(struct.unpack('B', buf[24])[0])                  
					r26 = int(struct.unpack('B', buf[25])[0])
					r27 = int(struct.unpack('B', buf[26])[0])
					
					print "receive:", r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20,r21,r22,r23,r24,r25,r26,r27, "\n"
					
				except:
					print "UDP Error"
			
				line = fin.readline().split()	
			
			fin.close()
		

def runSimuDatabase(self):
	import struct, string
	
	if self.fft == 1:
		self.fft = 0
		self.fftbutton.config(text = "FFT")
	#t = time.time()
	t = time.clock()
	if self.simu == 0: 
		self.simu = 1
		self.pause = 0
	else: 
		self.simu = 0
		self.pause = 1
		self.file_loaded = 1
		
	if self.simu == 1:
		self.zoom = 0
		self.t0 = t
		#self.start_time = -40 
		self.simubuttondatabase.config(text = ' Stop ')
		import threading
		self.nodethread = []
		self.graphthread = []
		self.list_reset_thread = []
		print 'start reading data...'
		for i in range(0, (self.nodenum)):
			self.start_time[i] = 0 
			self.prev_time[i] = -1
			self.last_time[i] = 0
			self.last_update_time = self.t0
			
		self.nodethread.append( threading.Thread(target = self.readData1_database, args =[0])) 
		self.nodethread[0].start()
		
			
		if not self.nogui:
			#a = 1
			self.thread2 = threading.Thread(target = self.runUpdateGraph)
			self.thread2.start()
		else:
			self.status.set("GUI is running under non-displaying mode")
			self.thread6 = threading.Thread(target = self.show_status_in_nongui_mode)
			self.thread6.start()		
		
		if self.Show_Sample_Rate:
		#	#print "yes , create show sample rate thread"
			self.thread3 = threading.Thread(target = self.show_sample_rate_thread)
		#	#print "yes , create show sample rate thread 1"
			self.thread3.start()
			#print "yes , create show sample rate thread 2"
			
		if self.Auto_Scrolling:
			self.thread4 = threading.Thread(target = self.autoscrolling_thread)
			self.thread4.start()
		
		
		if self.Show_Error_Rate:
		#	#print "yes , create show sample rate thread"
			self.thread5 = threading.Thread(target = self.show_error_rate_thread)
		#	#print "yes , create show sample rate thread 1"
			self.thread5.start()
			#print "yes , create show sample rate thread 2"
			
	else:
		self.t1 = t
		self.timeRange = self.t1-self.t0
		self.simubuttondatabase.config(text = ' Start ')

		####################################		
		# stop RIPE-MAC        
	        r = struct.pack('h', 100)
	        addr = ('192.168.2.3', 2001)
		cmd='fe'
		self.socket.sendto(r+':'+cmd, addr)
		self.socket.settimeout(5)
		self.simu = 0
		self.pause = 1
		####################################		
			
		#for soc in self.socketlist:
		#	soc.close()
		
#def run_remote_service():

	
	
def stop_remote_service():
	
	import telnetlib

def inititalize():
	self.file_loaded = 0
	self.x_curve[id] = []
	self.y_curve[id] = []
	self.z_curve[id] = []
	self.start[id]   = 0
	self.maxx[id]    = 0
	self.maxy[id]    = 0
	self.maxz[id]    = 0
	self.lost        = 0
		
def readData1_database(self, id):
	
	self.inititalize
	#print 'id', self.serverlist[id]
	self.readData_database(id)	
	self.number_of_packet_loss = 0
	


def readData_database(self, id):
	import socket, struct, string, os, math
	#import telnetlib
	
	running = 5
	connected = 0
	counter = 0
	table = [0, 0.6,0,-0.6]
	last_sequence_number = 0
	current_sequence_number = 0
	self.number_of_packet_loss = 0
	#loss = 0
	
	self.socket.settimeout(15)
	cmd = ''
	addr = (self.IP_Basestation_1 , 2001)
				
	sys.stderr.write('Connection is successful \n')
    	connected = 1
    	first = 1


	#########################################
	# start RIPE-MAC        
        r = struct.pack('h', 100)
        addr = ('192.168.2.3', 2001)
	cmd='fb'
	self.socket.sendto(r+':'+cmd, addr)
	self.socket.settimeout(1000)
	#########################################


	
	self.start_time[id]  = 0
	#self.socketlist[id] = socket.socket(AF_INET, SOCK_DGRAM, 0)
	#self.socketlist[id].setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
	#self.socket.settimeout(1000)
	#self.socket.setsockopt(SOL_SOCKET, SO_BROADCAST, 1) 


	#self.Last_FFT_Recalculation_Time = time.time()

	packet =[]
	buf = []
	
	self.t0 = t1 = time.clock()
	
	print "readData_database id:",id
	
	Length = 12 #27 #23
	threshold = 0.3
	
	while (self.simu and id == 0):
		#t2  = time.clock()
			
		packet = []
		try:
	        	buf, addr = self.socket.recvfrom(1024)
	        	
	        	for j in range(0, Length):
	        		packet.append(int(struct.unpack('B', buf[j])[0]))
	        		#data_buf[k] = (data_buf[k]-171)/256*2200/333*9.8
			
			i = packet[2] #very important
			#if i >= self.nodenum:
			#	print i
			#	continue
				
			self.last_pulling_time[i] = time.clock()

			#adjust = self.offset[i] * 15
			
	        	for j in range(3, Length):
	        		#packet[j] = packet[j]-shift[bits]	# for 8 bits ADC format
	        		#packet[j] = int(float(packet[j]-171)/256*2200/333*9.81)

	        		packet[j] = int(float(packet[j]-171)*0.35225842)
	        		#packet[j] = int(float(packet[j]-170)*0.25316723)

	              		if packet[j] > 50.0:#29.43: # 3g
	              			packet[j]= 50.0#29.43
				
					if packet[j] < -50.0:#-29.43: # -3g
						packet[j]= -50.0#-29.43	

	              		#packet[j] = round(packet[j] / one_g[bits])
	              		packet[j] = packet[j] / 30.0#9.81

			#print packet			
			#print "last pull time:", self.last_pulling_time[i]
			#xdata = packet[3]
			
			#if abs(xdata) > self.maxx[id]: self.maxx[id] = abs(xdata)
			#if abs(xdata) > self.maxx[i]: self.maxx[i] = abs(xdata)

			#set_offset = 1
			#offset = packet[3]
			#for j in range (4, Length):
			#	if math.fabs(packet[j] - packet[j-1]) > threshold:
			#		set_offset = 0
			#		break
			#	offset += packet[j]

			#if(set_offset):
			#	self.offset[i] = offset / (Length - 3)

			for j in range (3, Length):
				self.x_curve[i].append(packet[j])
				self.y_curve[i].append(0)
				self.z_curve[i].append(0)				
				self.timelist[i].append(self.last_pulling_time[i]-self.t0)					


			#print "==============="
			#if len(self.x_curve[i]) > l:
			#	l += 650
			#	print self.x_curve[i]
			#print str(len(self.x_curve[i]))
	   	except NameError,c:
	   		print 'error ', c, 'undefined : error while receiving packet '
		except:
			pass

	#print self.x_curve[0]		
	#print "Running for ", t1-self.t0, " seconds. Total ", len(self.x_curve[0]), " samples"
	#print "Number of Loss Packet  :", int(self.number_of_packet_loss), "Packet Loss Rate: " ,float(self.number_of_packet_loss / float((len(self.x_curve[0])+self.number_of_packet_loss)))*100.0, " %"	
	#print self.raw[2]	        
	#tn.write("\x1C")
	#tn.write("exit\n")
	try:
		self.socketlist[id].close()        
	except:
		pass
	


def runUpdateGraph(self):				# the name was changed by SM. [8/18/05]
	#import time
	#t0 = time.time()
	if self.simu==1: 
		
		for i in range(0, self.nodenum):
			self.updateGraph1(i)
		
		self.master.after(self.Thread_Update_Time, self.runUpdateGraph)		
		

def reset_list(self):
	
	#if (( time.time()- self.last_reset_time ) > (self.List_Reset_Time+ 0.2 ) ): #and self.Auto_Scrolling == 1:
		
						
	print "yes!! reset the chain"
	#self.last_reset_time = time.time()
	#
	self.pause = 1	
	#time.sleep(0.1)
	#for i in range(0, 10000):
	#	j=i
	
	self._lock.acquire()
	
	#for i in self.nodethread:
	#	i.join()
	self.thread2.join()
	
	
	for i in range(0, (self.nodenum)):
#	
#		self.x_curve[i].pop(0)# = [0]
#		self.y_curve[i].pop(0)# = [0]
#		self.z_curve[i].pop(0)# = [0]
#		self.fft_x_curve[i].pop(0)# = [0]
#		self.fft_y_curve[i].pop(0)# = [0]
#		self.fft_z_curve[i].pop(0)# = [0]
#		self.timelist[i].pop(0) #= [0]
#
		self.x_curve[i] = [0]
		self.y_curve[i] = [0]
		self.z_curve[i] = [0]
		self.fft_x_curve[i] = [0]
		self.fft_y_curve[i] = [0]
		self.fft_z_curve[i] = [0]
		self.timelist[i] = [0]
		self.flush_time = self.flush_time + 1
	
	self._lock.release()
	self.pause= 0
	
	#for i in range(0, (self.nodenum)):
	#	self.nodethread[i].start()
	
	self.master.after(self.List_Reset_Time*1000, self.reset_list)	



# 11/19/2005 Show Sample Rate of Sensor node by ChongJing

def show_sample_rate_thread(self):
	
	while self.simu:
	
		#print "inside show_sample_rate"
		t1=time.time()
		
		#print "before if"
		if len(self.x_curve[0]) and ((t1-self.t0)% self.List_Reset_Time ) and (float(self.timelist[0][-1])-float(self.timelist[0][0])):
			print len(self.x_curve[0]),"th frame", ((t1-self.t0)% self.List_Reset_Time ), " Already up for ", int((t1-self.t0)+(self.flush_time/self.nodenum)*self.List_Reset_Time) , " second"
			#print "Sample rate : %i samples/s "%(int(len(self.timelist[0])/(float(self.timelist[0][-1])-float(self.timelist[0][0])))/10)
			
			#self.sample_rate = int(len(self.timelist[0])/(float(self.timelist[0][-1])-float(self.timelist[0][0])))
					
			#print "node 0 receive: %.5f %.5f %f", r1,r2,r3,"Request Rate :", int(len(self.x_curve[0])/(t1-self.t0)), "requests/second"
		
			#if use reset thread to calculate sample rate
	 		#print "node 0 sample rate : %i samples/s  receive: %4.1f %4.1f %4.1f"%(int(len(self.x_curve[0])/((t1-self.t0)% self.List_Reset_Time )) ,r1,r2,r3)
			
			
			
			#if use pop to calculate sample rate
			#print "node 0 sample rate : %i samples/s  receive: %4.1f %4.1f %4.1f"%(int(len(self.x_curve[0])/((t1-self.t0))) ,r1,r2,r3)
		
		
		time.sleep(0.5)	



def show_error_rate_thread(self):
	
	while self.simu:
	
		#print "inside show_sample_rate"
		#t1=time.time()
		
		#print "before if"
		if len(self.x_curve[0]) >200:
		#	print len(self.x_curve[0]),"th frame", ((t1-self.t0)% self.List_Reset_Time ), " Already up for ", int((t1-self.t0)+(self.flush_time/self.nodenum)*self.List_Reset_Time) , " second"			
			#print "Sample rate : %i samples/s "%(int(len(self.timelist[0])/(float(self.timelist[0][-1])-float(self.timelist[0][0])))/10)
			print "Number of packet loss is: ", self.number_of_packet_loss
			print "Packet Loss Rate right now is ", float(self.number_of_packet_loss / (len(self.x_curve[0])+self.number_of_packet_loss))*100, " %"	
			#self.sample_rate = int(len(self.timelist[0])/(float(self.timelist[0][-1])-float(self.timelist[0][0])))
					
			#print "node 0 receive: %.5f %.5f %f", r1,r2,r3,"Request Rate :", int(len(self.x_curve[0])/(t1-self.t0)), "requests/second"
		
			#if use reset thread to calculate sample rate
	 		#print "node 0 sample rate : %i samples/s  receive: %4.1f %4.1f %4.1f"%(int(len(self.x_curve[0])/((t1-self.t0)% self.List_Reset_Time )) ,r1,r2,r3)
			
			
			
			#if use pop to calculate sample rate
			#print "node 0 sample rate : %i samples/s  receive: %4.1f %4.1f %4.1f"%(int(len(self.x_curve[0])/((t1-self.t0))) ,r1,r2,r3)
		
		
		time.sleep(1)	


def show_status_in_nongui_mode(self):
	
	while self.simu:
		
		t1= time.clock()
		t = 'GUI is running under non-displaying: Started %i seconds \n'%(t1 - self.t0)
		self.status.set(t)
		
		time.sleep(1)


def autoscrolling_thread(self):
	
	
	while self.simu:
	
		if (( time.time()- self.last_update_time ) > self.Auto_Scrolling_Time ):
						
			self.last_update_time = time.time()
			self.cur_node = (self.cur_node + 1) % self.nodenum
			#self.updateGraph1(self.nodenum)
			self.status.set("Now showing Node %i details"%(self.cur_node))
		
		
		time.sleep(0.5)		
	
	
	
def append_raw_packet(self, buf):
	import struct, string 
	
	for i in range(0, self.Packet_Size): 
		self.raw[i].append(int(struct.unpack('B', buf[i])[0]))	
	
	
def preference(self):
	
	def setval():
		id = int(self.nodestr.get())
		self.low_resolution = int(self.low_resolutionstr.get())
		self.high_resolution = int(self.high_resolutionstr.get())
		
		self.sample_rate = float(self.SAMPLING_RATEstr.get())
		SAMPLING_RATE = float(self.SAMPLING_RATEstr.get())
		#print "Sample_rate, self.sample_rate", SAMPLING_RATE, self.sample_rate	
		
		
		self.Thread_Update_Time = int(self.Thread_Update_Timestr.get())
		thread_update_time = int(self.Thread_Update_Timestr.get())
		
		self.Request_Sleep_Time = float(self.Request_Sleep_Timestr.get())
		Request_Sleep_Time = float(self.Request_Sleep_Timestr.get())		

		self.Auto_Scrolling_Time = int(self.Auto_Scrolling_Timestr.get())
		Auto_Scrolling_Time = int(self.Auto_Scrolling_Timestr.get())	

		self.Auto_Scrolling = int(self.Auto_Scrollingstr.get())
		Auto_Scrolling = int(self.Auto_Scrollingstr.get())	

		self.Database_enable = int(self.Database_enablestr.get())
		Database_enable = int(self.Database_enablestr.get())

		self.List_Reset_Time = int(self.List_Reset_Timestr.get())
		List_Reset_Time = int(self.List_Reset_Timestr.get())	
		
		
		if (int(self.FFT_Recalculation_Timestr.get())) < 2:
			print "FFT Recalcuation Time should be bigger than 2. \nFFT Recalcuation Time will be set to 2 now"
			#print self.FFT_Recalculation_Timestr 
			self.FFT_Recalculation_Timestr.set('2')
			#print self.FFT_Recalculation_Timestr 
		
		self.FFT_Recalculation_Time = int(self.FFT_Recalculation_Timestr.get())
		FFT_Recalculation_Time = int(self.FFT_Recalculation_Timestr.get())
			
		
		self.nogui = int(self.noguistr.get())
		NoGUI = int(self.noguistr.get())
		
		
		self.Show_Error_Rate = int(self.Show_Error_Ratestr.get())
		Show_Error_Rate = int(self.Show_Error_Ratestr.get())
		
		
		#self.IP_Basestation_1 = self.IP_Basestation_1str.get())
		#IP_Basestation_1 = int(self.IP_Basestation_1str.get())			
		#print thread_update_time, Sample_rate
		nf.destroy()
		# end of setcali

	# open a popup window
	nf = Toplevel()
	t = "Preference"
	nf.title(t)
	self.status.set(t)
	infoFrame = Frame(nf, width = self.nodewin_width,
	              height = self.nodewin_height,  bd = 1)
	infoFrame.pack(fill = BOTH, expand = 0)



	

	Label(infoFrame,  text = 'Resolution Stepping for each node:(Default:30)').grid(row = 0, column = 1, sticky = W)
	Label(infoFrame,  text = 'Resolution Steping for node detail:(Default:15)').grid(row = 1, column = 1, sticky = W)
	if not self.simu:
		Label(infoFrame,  text = 'Sample Rate:(Default:0.005)').grid(row = 2, column = 1, sticky = W)
	#Label(infoFrame,  text = 'Graph Thread Update Period:(Default:1)').grid(row = 3, column = 1, sticky = W)
	Label(infoFrame,  text = 'Thread Sleep').grid(row = 4, column = 1, sticky = W)
	Label(infoFrame,  text = 'Request Thread Sleep Time:(Default:0.01)').grid(row = 5, column = 1, sticky = W)
	Label(infoFrame,  text = 'Auto Scrolling').grid(row = 6, column = 1, sticky = W)
	Label(infoFrame,  text = 'Auto Scrolling Period(Second)').grid(row = 7, column = 1, sticky = W)
	Label(infoFrame,  text = 'Database Logging Enable').grid(row = 8, column = 1, sticky = W)
	Label(infoFrame,  text = 'Graph List Rest Time').grid(row = 9, column = 1, sticky = W)
	Label(infoFrame,  text = 'Show Sample Rate').grid(row = 10, column = 1, sticky = W)
	Label(infoFrame,  text = 'Base Station IP Address').grid(row = 11, column = 1, sticky = W)
	Label(infoFrame,  text = 'FFT7 Recalcuation Time(in second and should be grater than 2)').grid(row = 12, column = 1, sticky = W)
	
	
	
	if not self.simu:
		Label(infoFrame,  text = 'Display Error Rate').grid(row = 13, column = 1, sticky = W)
		Label(infoFrame,  text = 'Drawing').grid(row = 14,column = 1, sticky = W)
	
	#Label(infoFrame,  text = 'Max').grid(row = 1, column = 2, sticky = W)
	#Label(infoFrame,  text = 'X').grid(row = 2, column = 0, sticky = W)
	#Label(infoFrame,  text = 'Y').grid(row = 3, column = 0, sticky = W)
	#Label(infoFrame,  text = 'Z').grid(row = 4, column = 0, sticky = W)
	Entry(infoFrame, textvariable = self.low_resolutionstr).grid(row = 0, column = 2)
	Entry(infoFrame, textvariable = self.high_resolutionstr).grid(row = 1, column = 2)
	if not self.simu:
		Entry(infoFrame, textvariable = self.SAMPLING_RATEstr).grid(row = 2, column = 2)
	#Entry(infoFrame, textvariable = self.Thread_Update_Timestr).grid(row = 3, column = 2)
	Entry(infoFrame, textvariable = self.Request_Sleep_Timestr).grid(row = 5, column = 2)
	#Entry(infoFrame, textvariable = self.Auto_Scrollingstr).grid(row = 6, column = 2)
	Entry(infoFrame, textvariable = self.Auto_Scrolling_Timestr).grid(row = 7, column = 2)
	Entry(infoFrame, textvariable = self.List_Reset_Timestr).grid(row = 9, column = 2)
	#Entry(infoFrame, textvariable = self.Show_Sample_Ratestr).grid(row = 10, column = 2)
	#Entry(infoFrame, textvariable = 'TEXT2').grid(row = 10, column = 2)
	Entry(infoFrame, textvariable = self.IP_Basestation_1str).grid(row = 11, column = 2)
	#Entry(infoFrame, text = 'TEXT').grid(row = 11, column = 2)
	Entry(infoFrame, textvariable = self.FFT_Recalculation_Timestr).grid(row = 12, column = 2)
	
	
	
	Checkbutton(infoFrame, text="",	variable= self.Request_Sleep, onvalue="1", offvalue="0").grid(row = 4, column = 0)
	Checkbutton(infoFrame, text="",	variable= self.Auto_Scrollingstr, onvalue="1", offvalue="0").grid(row = 6, column = 0)
	Checkbutton(infoFrame, text="",	variable= self.Database_enablestr, onvalue="1", offvalue="0").grid(row = 8, column = 0)
	Checkbutton(infoFrame, text="",	variable= self.Show_Sample_Ratestr, onvalue="1", offvalue="0").grid(row = 10, column = 0)
	
	
	
	if not self.simu:
		Checkbutton(infoFrame, text="",	variable= self.Show_Error_Ratestr, onvalue="1", offvalue="0").grid(row = 13, column = 0)
		Checkbutton(infoFrame, text="",	variable= self.noguistr, onvalue="0", offvalue="1").grid(row = 14, column = 0)
	
	#Entry(infoFrame, textvariable = self.xmaxOnY).grid(row = 2, column = 2)
	#Entry(infoFrame, textvariable = self.yminOnY).grid(row = 3, column = 1)
	#Entry(infoFrame, textvariable = self.ymaxOnY).grid(row = 3, column = 2)
	#Entry(infoFrame, textvariable = self.zminOnY).grid(row = 4, column = 1)
	#Entry(infoFrame, textvariable = self.zmaxOnY).grid(row = 4, column = 2)
	Button(infoFrame, text = 'OK', command = setval).grid(row = 15, column = 2)
	

	
def testing(self):
	
	#def setval():


	# open a popup window
	nf = Toplevel()
	t = "MSP Testing"
	nf.title(t)
	self.status.set(t)
	infoFrame = Frame(nf, width = self.nodewin_width,
	              height = self.nodewin_height,  bd = 1)
	infoFrame.pack(fill = BOTH, expand = 0)



	#self.TestConnbutton  = Button(infoFrame, text='Communication Testing',relief= RAISED, command=self.TestConn, fg=self.buttonfg , bg=self.buttonbg).grid(row=0, column =0)
	self.TestConnbutton  = Button(infoFrame, text='Communication Testing',relief= RAISED, command=self.TestConn, fg=self.buttonfg , bg=self.buttonbg)
	
	self.TestConnbutton.pack(side = LEFT, fill = X, expand = 1)


	self.Firmwarebutton  = Button(infoFrame, text='Firmware Version',relief= RAISED, command=self.Firmwareveresion, fg=self.buttonfg , bg=self.buttonbg)
	#self.Firmwarebutton  = Button(infoFrame, text='Firmware Version',relief= RAISED, command=self.Firmwareveresion, fg=self.buttonfg , bg=self.buttonbg).grid(row=1, column =0)
	self.Firmwarebutton.pack(side = LEFT, fill = X, expand = 1)

	self.Parsercommandbutton  = Button(infoFrame, text='Parser Command',relief= RAISED, command=self.ParserCommand, fg=self.buttonfg , bg=self.buttonbg)
	#self.Firmwarebutton  = Button(infoFrame, text='Firmware Version',relief= RAISED, command=self.Firmwareveresion, fg=self.buttonfg , bg=self.buttonbg).grid(row=1, column =0)
	self.Parsercommandbutton.pack(side = LEFT, fill = X, expand = 1)


	self.SetFrequencybutton  = Button(infoFrame, text='Set Frequency',relief= RAISED, command=self.SetFrequency, fg=self.buttonfg , bg=self.buttonbg)
	self.SetFrequencybutton.pack(side = LEFT, fill = X, expand = 1)

 