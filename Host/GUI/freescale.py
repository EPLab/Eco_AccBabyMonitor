import Tkinter
from Tkinter import *
import os, sys, time
from socket import *
from tkFileDialog import askopenfilename, asksaveasfilename
#import dbi, odbc
import threading

# senor network configuration
#nodes = ['n1', 'n2', 'n3', 'n4']
#nodes = ['n1', 'n2']
#import sys
if len(sys.argv) == 1: nodes = ['n0']
else:
	#if sys.argv[1] == '1': nodes = ['n1']
	#elif sys.argv[1]=='2': nodes = ['n1', 'n2']
	#elif sys.argv[1]=='3': nodes = ['n1', 'n2', 'n3']
	#elif sys.argv[1]=='4': nodes = ['n1', 'n2', 'n3', 'n4']
	nodes = []
	for i in range(0, int(sys.argv[1])):
		nodeid = 'n' + str(i)
		#print 'nodeid: ', nodeid
		nodes.append(str(nodeid))
	#print 'nodes = ', nodes
# if-else
basenode = 'chocolate1'
sleeping = 'cornflowerblue'
working     = 'aquamarine3'
x_color = 'green'
y_color = 'blue'
z_color = 'red'
CBGCOLOR = 'black'
CNCOLOR = 'black'
buttonfg = 'white'
buttonbg = 'black'
font_size = 8
MAX_TIME  = 10			#max time unit per frame
MIN_RANGE_ON_X = 1.0		# minimun data range on X-axis
buffersize = 50

refresh_rate = 5
Vmax = 4.096
Vscale = Vmax/1024
V0   = Vmax/2
GAL  = 0.312

# constants defined by SM

NoGUI = 0
SCROLL_UNIT = 20		# graph scroll unit
#SAMPLING_RATE = 0.025		# sampling rate: 1 ms : deafult: 0.015
SAMPLING_RATE = 0.02
Thread_Update_Time = 30		# Thread update data every # ms
Request_Sleep 	   = 0		# Thread sleeping or not	
Request_Sleep_Time = 0.015	# Request Sleep Time # ms default 0.01 can reach 30 request per second for 20 nodes with 5 sets return 
high_resolution = 1		# default 15	won't be used for hiperwall
low_resolution  = 2		# default 30    be used for hiperwall
col_per_row     = 7	        # how many col per row 
Auto_Scrolling_Time = 1      	# auto scrolling time , second
Auto_Scrolling = 0		# Auto Scrolling Functionality : 1: enable
No_Of_Freescale = 1 #2		# Number of Freescale 
Database_enable = 0		# Enable Database logging or not  
Normalization = 100  		# To normalize the number getting from freescale
List_Reset_Time = 6000		# Reset list chain to save memory , default = 300 seconds
show_sample_rate = 0
Measure_Sample_Rate = 200
IP_Basestation_1='192.168.2.3'
#IP_Basestation_2='192.168.2.4'
FFT_Recalculation_Time = 2

Low_Resolution_Frame_Ratio = 1	#Shift Parameters for GUI Drawing
High_Resolution_Frame_Ratio = 1
FFT_Shift_Ratio = 2.3
Time_Range_Shift = 2.0
Packet_Size = 27
Show_Error_Rate = 0
IP_PREFIX	= '192.168.2.'
serverstart = 2
Hoststart= 201
HostNumner = 1



user='chongji'
Password='chongji'




# Not used
#	caller:
#			drawData1
#
def getGrid(MAX_TIME, scale, points):
	if(scale >= 1.0):
		timescale = MAX_TIME/(points*scale)
	elif(scale>=0.25):
		timescale = MAX_TIME*0.5
	else:
		timescale = MAX_TIME
	grid = 0
	if (timescale >= 1):
		if timescale > 10: time = int((timescale/10+0.5)*10)
		else: time = int(timescale+0.5)
		step = 1
		while grid == 0:
			for i in range(2, 10):
				if time < i*step and grid == 0:
					grid = (i-1)*step
			step = step*10
	else:
		if (timescale > 0.5): grid = 0.5
		else: grid = 0.2
		#step = 10
		#while(int(timescale*step)<=0):  
		#	step = step*10	
		#grid = 2*int(timescale*step)/float(step)
        
	return grid
# end of getGrid

class MainWidget:

	from database import *
	
	def __init__(self, master, width, height):
			 	       	
		if os.name == 'nt':	 	       	
			self.host = ''
		else:
			self.host = gethostbyname(gethostname())
			
		self.port = 2001
		self.socket = socket(AF_INET, SOCK_DGRAM)
		addr = getaddrinfo(self.host, self.port , AF_INET, SOCK_DGRAM)    
		print addr
		self.socket.bind (addr[0][4])
		self.record	= 0
		self.recordstr  = StringVar()
		
		self.high_resolution    = high_resolution
		self.high_resolutionstr = StringVar()
		self.high_resolutionstr.set(self.high_resolution)
		
		self.low_resolution	= low_resolution
		self.low_resolutionstr  = StringVar()
		self.low_resolutionstr.set(self.low_resolution)
		
		self.SAMPLING_RATEstr = StringVar()
		self.SAMPLING_RATEstr.set(SAMPLING_RATE)
		self.sample_rate  = SAMPLING_RATE	# sampling rate
		

		self.Thread_Update_Time	= Thread_Update_Time
		self.Thread_Update_Timestr  = StringVar()
		self.Thread_Update_Timestr.set(self.Thread_Update_Time)		

		self.Request_Sleep	= Request_Sleep
		self.Request_Sleepstr  = StringVar()
		self.Request_Sleepstr.set(self.Request_Sleep)	
	
		self.Request_Sleep_Time	= Request_Sleep_Time
		self.Request_Sleep_Timestr  = StringVar()
		self.Request_Sleep_Timestr.set(self.Request_Sleep_Time)	

		self.Auto_Scrolling = Auto_Scrolling
		self.Auto_Scrollingstr  = StringVar()
		self.Auto_Scrollingstr.set(self.Auto_Scrolling)	
				
		self.Auto_Scrolling_Time = Auto_Scrolling_Time
		self.Auto_Scrolling_Timestr  = StringVar()
		self.Auto_Scrolling_Timestr.set(self.Auto_Scrolling_Time)	
		
		self.Database_enable = Database_enable
		self.Database_enablestr  = StringVar()
		self.Database_enablestr.set(self.Database_enable)	

		self.Normalization = Normalization
		self.Normalizationstr  = StringVar()
		self.Normalizationstr.set(self.Normalization)			

		self.List_Reset_Time = List_Reset_Time
		self.List_Reset_Timestr  = StringVar()
		self.List_Reset_Timestr.set(self.List_Reset_Time)
			
		self.Show_Sample_Rate = show_sample_rate
		self.Show_Sample_Ratestr  = StringVar()
		self.Show_Sample_Ratestr.set(self.Show_Sample_Rate)
			
		self.IP_Basestation_1 = IP_Basestation_1 
 		self.IP_Basestation_1str  = StringVar()
		self.IP_Basestation_1str.set(self.IP_Basestation_1)           	
            	
            	self.FFT_Recalculation_Time = FFT_Recalculation_Time
 		self.FFT_Recalculation_Timestr  = StringVar()
		self.FFT_Recalculation_Timestr.set(self.FFT_Recalculation_Time)           	
            	self.Last_FFT_Recalculation_Time = time.time()
            	#self.Last_FFT_Recalculation_Time = 0
            	
            	
            	self.Show_Error_Rate	= Show_Error_Rate
		self.Show_Error_Ratestr  = StringVar()
		self.Show_Error_Ratestr.set(self.Show_Error_Rate)	
		
		self.CurrentFrequency	= 0
		self.CurrentFrequencystr = StringVar()
		self.CurrentFrequencystr.set(self.CurrentFrequency)
		
	
            	self.nogui		= NoGUI	
            	self.noguistr  = StringVar()
            	self.noguistr.set(self.nogui)
            	self.Packet_Size = Packet_Size
            	self.buttonfg = buttonfg
            	self.buttonbg = buttonbg
                #self.TestConnbutton.pack(side = LEFT, fill = X, expand = 1)
            	
            	
            	#self.IP_Basestation_2 = IP_Basestation_2
		self.error = 0
		self._lock = threading.RLock()
		self._lock2 = threading.RLock()
		self.last_update_time 	= 0
		#self.last_reset_time = 0
		self.pause = 0				#Control Reading Data Thread Pause or not 
		self.graphpause = 0			#Control Drawing Data Thread Pause or not 
		self.flush_time= 0		# Times to flush list size
		self.font_size = font_size
		self.last_reset_time= []
		self.raw = []
		self.number_of_packet_loss = 0.00 
		self.IP_PREFIX = IP_PREFIX
		self.Hoststart = Hoststart
		self.user = user
		self.Password= Password
		self.HostNumner = HostNumner
			

		
			
		self.master	= master
		self.C = __import__("guicfg")
		self.height 	= root.winfo_screenheight()	# height of the gui window
		self.width 	= root.winfo_screenwidth()	# width of the gui window
		print root.winfo_screenheight(), root.winfo_screenwidth()
		self.radius 	= self.C.radius			# ??
		self.keybuf 	= []					# ??
		self.xmargin 	= self.C.xmargin		# ??
		self.ymargin 	= self.C.ymargin		# ??
		#self.cheight    = self.C.c_height		# ??
		self.theight	= self.C.c_height		# ??

		# flags
		self.simu		= 0						# if start button is pressed, it is set to 1
		self.fft		= 0						# if fft is enabled, it is set to 1
		self.zoom		= 0						# if the graph is zoomed in, it is set to 1
		self.log		= 0						# if log is on, it is set to 1
		self.file_loaded= 0						# if there is data on the graph, it is set to 1

		# constants (??)
		self.scale		= 1						# ??
		
		# ??
		# These are used by setEndpoint. They seem redundant.
		self.xrax       = []
		self.xray       = [] 
		self.xraz       = []
		# ??
		# These are used by setEndpoint. They seem redundant.
		self.xrafx      = []
		self.xrafy      = [] 
		self.xrafz      = []

        # objects which contain actual sensor values
        # the objects are used when graphs are plotted
		self.timelist   = []
		self.x_curve    = []
		self.y_curve    = []
		self.z_curve    = []
		self.timelist_temp = []
		self.x_curve_temp = []
		self.y_curve_temp = []
		self.z_curve_temp = []
		
		self.offset   = []
		
		
		self.fft_x_curve= []
		self.fft_y_curve= [] 
		self.fft_z_curve= []
		
		self.socketlist = []				# list of sockets bound with sensors
		self.serverlist = []				# list of the IP addresses of sensors
						# ??
		
		self.lost       = 0					# ?? this looks like a flag.
											# But it is also initialized to a list

		# ? 
		self.maxx       = []				# list of the max absolute value read in x_curve
		self.maxy       = []				# list of the max absolute value read in y_curve
		self.maxz       = []				# list of the max absolute value read in z_curve

		# ?
		self.maxxf      = []
		self.maxyf      = []
		self.maxzf      = []

		# the index of the self.st[id] in the graph showing on the screen
		self.start      = []
		self.startf     = []
		# the index of the self.st[id] on the X-axes showing on the screen
		self.startx     = []
		self.starty     = []
		self.startz     = []
		# ?
		self.startfx    = []
		self.startfy    = []
		self.startfz    = []

		# the largest value on the X-axes showing on the screen
		self.endx       = [] 
		self.endy       = [] 
		self.endz       = []
		# ?
		self.endfx      = [] 
		self.endfy      = [] 
		self.endfz      = []

		self.st         = []			# list of the smallest value of the node on the graph showing in second
		self.lost       = []			# ??

		self.start_time = []			# list of the smallest value of the node on the graph showing
		self.prev_time = []
		self.last_time = []
		self.last_pulling_time = []

		self.t0			= 0				# data acquisition start time
		self.t1			= 0				# data acquisition end time
		self.timeRange	= 0				# time duration of data acquisition
	
		self.ratelist 		= [0]         # ?
		self.sizelist 		= [0]         # ?
		self.tx_ratelist 	= [0]         # ?
		self.tx_powerlist 	= [0]         # ?
	
		self.nodenum	= len(nodes)     # number of sensor nodes

		self.filename		= []			# list of log file names
		
		self.maxtime		= MAX_TIME
		self.rangeOnX		= float(MAX_TIME)	# data range on X-axis
		#self.current		= 0			# 09/09/2005 Current node show on status frame


		server = IP_PREFIX                # prefix of the sensor node ip address
		#for i in range(0, (self.nodenum+1)):
		for i in range(0, (self.nodenum)):
			self.xrax.append(1)
			self.xray.append(1)
			self.xraz.append(1)
			self.xrafx.append(1)
			self.xrafy.append(1)
			self.xrafz.append(1)

			self.lost.append(0)
			self.start_time.append(0)
			self.last_time.append(0)
			self.prev_time.append(0)
			self.last_pulling_time.append(0) 
			self.offset.append(0) 

			self.x_curve.append([])
			self.y_curve.append([])
			self.z_curve.append([])
			self.timelist.append([])
			
			self.x_curve_temp.append([])
			self.y_curve_temp.append([])
			self.z_curve_temp.append([])
			self.timelist_temp.append([])
			
			self.fft_x_curve.append([])
			self.fft_y_curve.append([])
			self.fft_z_curve.append([])

			self.socketlist.append('')
			self.serverlist.append(server+str(i+serverstart))
			
			
			
			self.ratelist.insert(i, 1)
			self.sizelist.insert(i, 1)
			self.tx_ratelist.insert(i, 1)
			self.tx_powerlist.insert(i, 1)
	
			self.maxx.append(0)
			self.maxy.append(0)
			self.maxz.append(0)
			#self.minx.append(10)
			#self.miny.append(10)
			#self.minz.append(10)
			self.maxxf.append(0)
			self.maxyf.append(0)
			self.maxzf.append(0)

			self.endx.append(0)
			self.endy.append(0)
			self.endz.append(0)

			self.endfx.append(0)
			self.endfy.append(0)
			self.endfz.append(0)

			self.start.append(0)
			self.startf.append(0)

			self.startx.append(0)
			self.starty.append(0)
			self.startz.append(0)

			self.startfx.append(0)
			self.startfy.append(0)
			self.startfz.append(0)
			self.st.append(0)
			self.filename.append("")
			self.last_reset_time.append(time.time())
			
		
		for i in range(0, self.Packet_Size):
			self.raw.append([])
		
		
		print self.last_reset_time
		print self.last_reset_time[0]
		# end of for

        # flags for zoom-in (??)
		self.bxrel        = 1			# when graph X is zoomed in, it is set to 1
		self.byrel        = 1			# when graph Y is zoomed in, it is set to 1
		self.bzrel        = 1			# when graph Z is zoomed in, it is set to 1

		self.cur_node     = 0				# current node index
		#self.sample_rate  = 0.005		# sampling rate
		self.measured_sample_rate = Measure_Sample_Rate
		
		
		self.nf = ""						# ?
		self.nodewin_width = 280			# ?
		self.nodewin_height = 200			# ?
		self.size         = StringVar()		#buffer size
		self.rate         = StringVar()		#sampling rate
		self.tx_rate      = StringVar()		#trasmission rate
		self.tx_power     = StringVar()		#tranmission power

		self.nodestr	  = StringVar()		# ?
		self.xoffstr      = StringVar()		# predefined X y-axis offset
		self.yoffstr      = StringVar()		# predefined Y y-axis offset
		self.zoffstr      = StringVar()		# predefined Z y-axis offset
		self.maxgstr      = StringVar()
		self.xoffstr.set(self.C.xdefault)  	
		self.yoffstr.set(self.C.ydefault)
		self.zoffstr.set(self.C.zdefault)
		self.maxgstr.set(self.C.gdefault)
		self.nodestr.set(0)
		
		self.xminOnY	= StringVar()
		self.xmaxOnY	= StringVar()
		self.yminOnY	= StringVar()
		self.ymaxOnY	= StringVar()
		self.zminOnY	= StringVar()
		self.zmaxOnY	= StringVar()

		self.xminOnY.set(float(self.C.xdefault) - float(self.C.gdefault))
		self.xmaxOnY.set(float(self.C.xdefault) + float(self.C.gdefault))
		self.yminOnY.set(float(self.C.ydefault) - float(self.C.gdefault))
		self.ymaxOnY.set(float(self.C.ydefault) + float(self.C.gdefault))
		self.zminOnY.set(float(self.C.zdefault) - float(self.C.gdefault))
		self.zmaxOnY.set(float(self.C.zdefault) + float(self.C.gdefault))
		
		self.scrollunit = SCROLL_UNIT
		# end of the initialization of variables

		#self.zoffset = 1.0	
		self.master.config(height = height, width = width)

		# define global variables
		self.frame = Frame(master, bd=0, height = height+40, width = width)
		self.frame.pack(fill=BOTH, expand =0)
		
		self.b = Canvas(self.frame, width = self.width, height = self.height, bg = self.C.canvas_bg, relief = SUNKEN)

		#define control bar	
		self.ctrlbar = Frame(self.frame, bd = 1, relief = RAISED, width = self.width)
		self.ctrlbar.pack(fill = BOTH, expand = 0)
#		
#		self.simubutton  = Button(self.ctrlbar, text='Start', relief= RAISED, command=self.runSimu, fg=buttonfg , bg=buttonbg)
#		self.simubutton.pack(side = LEFT, fill = X)
#	
#		self.fftbutton  = Button(self.ctrlbar, text='FFT', relief= RAISED, command=self.runFFT, fg=buttonfg , bg=buttonbg)
#		self.fftbutton.pack(side = LEFT, fill = X)	
#	
		
#		self.logbutton  = Button(self.ctrlbar, text='StartLog', relief= RAISED, command=self.saveLog, fg=buttonfg , bg=buttonbg)
#		self.logbutton.pack(side = LEFT, fill = X)
#		
#		self.zinbutton  = Button(self.ctrlbar, text='ZoomIn', relief= RAISED, command=self.zoomIn, fg=buttonfg , bg=buttonbg)
#		self.zinbutton.pack(side = LEFT, fill = X)
#
#		self.zoutbutton  = Button(self.ctrlbar, text='ZoomOut', relief= RAISED, command=self.zoomOut, fg=buttonfg , bg=buttonbg)
#		self.zoutbutton.pack(side = LEFT, fill = X)
#
#		self.calibutton  = Button(self.ctrlbar, text='Calibration', relief= RAISED, command=self.calibration, fg=buttonfg , bg=buttonbg)
#		self.calibutton.pack(side = LEFT, fill = X)


		
		self.simubuttondatabase = Button(self.ctrlbar, text=' Start ',
                        relief= RAISED, command=self.runSimuDatabase, fg=buttonfg , bg=buttonbg)
                self.simubuttondatabase.pack(side = LEFT, fill = X, expand = 1)
 
		self.savebutton  = Button(self.ctrlbar, text=' Save ', relief= RAISED, command=self.saveData, fg=buttonfg , bg=buttonbg)
		self.savebutton.pack(side = LEFT, fill = X,expand = 1)
		
		self.loadbutton  = Button(self.ctrlbar, text=' Load ', relief= RAISED, command=self.loadData, fg=buttonfg , bg=buttonbg)
		self.loadbutton.pack(side = LEFT, fill = X ,expand = 1)
  
            
 
 		
		self.zinbutton  = Button(self.ctrlbar, text='ZoomIn', relief= RAISED, command=self.zoomIn, fg=buttonfg , bg=buttonbg)
		self.zinbutton.pack(side = LEFT, fill = X, expand = 1)

		self.zoutbutton  = Button(self.ctrlbar, text='ZoomOut', relief= RAISED, command=self.zoomOut, fg=buttonfg , bg=buttonbg)
		self.zoutbutton.pack(side = LEFT, fill = X, expand = 1)
               
                                
                self.preference  = Button(self.ctrlbar, text='Preference',
                        relief= RAISED, command=self.preference, fg=buttonfg , bg=buttonbg)
                self.preference.pack(side = LEFT, fill = X,expand = 1)
		
                      
                self.Testingbutton  = Button(self.ctrlbar, text='MSP Testing',
                        relief= RAISED, command=self.testing, fg=buttonfg , bg=buttonbg)
                self.Testingbutton.pack(side = LEFT, fill = X, expand = 1)
             
             
                #self.TestConnbutton  = Button(self.ctrlbar, text='MSP Testing',
                #        relief= RAISED, command=self.TestConn, fg=buttonfg , bg=buttonbg)
                #self.TestConnbutton.pack(side = LEFT, fill = X, expand = 1)
                
		quitbutton  = Button(self.ctrlbar, text='Quit', relief= RAISED, command=self.quit, fg=buttonfg , bg=buttonbg)
		quitbutton.pack(side = LEFT, fill = X, expand = 1)
		'''
		self.cmdstr = StringVar()
                self.command = Entry(self.ctrlbar, relief = SUNKEN, bd = 1, width = 50, bg = 'white', textvariable = self.cmdstr)
                self.command.pack(side = LEFT, padx = 1, pady = 1, expand = 0)
		self.command.bind("<Return>", self.execcmd)
		self.command.bind("<Up>", self.getbuf)
		'''
		                
		#self.statusframe = Frame(self.frame, bd=1, height = self.theight, width = width)
                #self.statusframe.pack(fill=BOTH, expand = 0)
                
		self.middleframe = Frame(self.frame, bd=1, height = self.theight, width = width)
                self.middleframe.pack(fill=BOTH, expand = 0)
	
	
		#define middleframe window
		self.play = PhotoImage(file='right.gif')	# scroll right button
		self.backplay = PhotoImage(file='left.gif')	# scroll left button
		self.xc = []          # space for graph X
		self.yc = []          # space for graph Y
		self.zc = []          # space for graph Z
		self.xoffset=[]       # X y-axis offset
		self.yoffset=[]       # Y y-axis offset
		self.zoffset=[]       # Z y-axis offset

		self.graphXMinOnY = []		# minimum value on Y-axis in graph X
		self.graphXMaxOnY = []		# maximum value on Y-axis in graph X
		self.graphYMinOnY = []		# minimum value on Y-axis in graph Y
		self.graphYMaxOnY = []		# maximum value on Y-axis in graph Y
		self.graphZMinOnY = []		# minimum value on Y-axis in graph Z
		self.graphZMaxOnY = []		# maximum value on Y-axis in graph Z

		# initialize graphs
		for i in range(0, self.nodenum):
			# initialize graph X
			xc = Canvas(self.middleframe, width = self.width/(col_per_row), height = self.theight,
			            bg = CNCOLOR, bd = 0, relief = SUNKEN)
			xc.grid(row = i/(col_per_row), column = i % (col_per_row), sticky = W)
			self.xc.append(xc)
			self.xc[i].bind("<Button-1>",      self.setXAnchor)		# mouse button pressed on graph X
			self.xc[i].bind("<B1-Motion>",      self.XflyMotion)	# mouse button moved on graph X
			self.xc[i].bind("<ButtonRelease-1>", self.setXEndpoint)	# mouse button released on graph X
			self.drawGrid(self.xc[i], self.width/(col_per_row), self.theight, 'CHANNEL %i'%(i), 0)
			self.xoffset.append(float(self.xoffstr.get()))
			self.graphXMinOnY.append(float(self.xoffstr.get()) - float(self.maxgstr.get()))
			self.graphXMaxOnY.append(float(self.xoffstr.get()) + float(self.maxgstr.get()))
	
			# initialize graph Y
			#yc = Canvas(self.middleframe, width = self.width/3,	height = self.theight,
	                #bg = CNCOLOR, bd = 0, relief = SUNKEN)
			yc = xc
	                
			yc.grid(row = i/(col_per_row), column = i % (col_per_row))
			self.yc.append(yc)
			#self.yc[i].bind("<Button-1>",      self.setYAnchor)		# mouse button pressed on graph Y
			#self.yc[i].bind("<B1-Motion>",      self.YflyMotion)	# mouse button moved on graph Y
			#self.yc[i].bind("<ButtonRelease-1>", self.setYEndpoint)	# mouse button released on graph Y
			#self.drawGrid(self.yc[i], self.width/3, self.theight, 'Y', 0)
	
			self.yoffset.append(float(self.yoffstr.get()))
			self.graphYMinOnY.append(float(self.yoffstr.get()) - float(self.maxgstr.get()))
			self.graphYMaxOnY.append(float(self.yoffstr.get()) + float(self.maxgstr.get()))
	
			# initialize graph Z
			#zc = Canvas(self.middleframe, width = self.width/3, height = self.theight,
			#	        bg = CNCOLOR, bd = 0, relief = SUNKEN)
			zc = xc
			zc.grid(row = i/(col_per_row), column = i % (col_per_row))
			self.zc.append(zc)
			#self.zc[i].bind("<Button-1>",      self.setZAnchor)		# mouse button pressed on graph Z
			#self.zc[i].bind("<B1-Motion>",      self.ZflyMotion)	# mouse button moved on graph Z
			#self.zc[i].bind("<ButtonRelease-1>", self.setZEndpoint)	# mouse button released on graph Z
			#self.drawGrid(self.zc[i], self.width/3, self.theight, 'Z', 0)
	
			self.zoffset.append(float(self.zoffstr.get()))
			self.graphZMinOnY.append(float(self.zoffstr.get()) - float(self.maxgstr.get()))
			self.graphZMaxOnY.append(float(self.zoffstr.get()) + float(self.maxgstr.get()))
		
		# for
		# 09/09/2005 by ChongJing : initial x , y ,z status frame
		# initialize graph X
#		xc = Canvas(self.statusframe, width = self.width/3, height = self.theight,
#		            bg = CNCOLOR, bd = 0, relief = SUNKEN)
#		xc.grid(row = 0, column = 0, sticky = W)
#		self.xc.append(xc)
#		self.xc[self.nodenum].bind("<Button-1>",      self.setXAnchor)		# mouse button pressed on graph X
#		self.xc[self.nodenum].bind("<B1-Motion>",      self.XflyMotion)	# mouse button moved on graph X
#		self.xc[self.nodenum].bind("<ButtonRelease-1>", self.setXEndpoint)	# mouse button released on graph X
#		self.drawGrid(self.xc[self.nodenum], self.width/3, self.theight, 'CHANNEL DATA', 0)
#
#		self.xoffset.append(float(self.xoffstr.get()))
#		self.graphXMinOnY.append(float(self.xoffstr.get()) - float(self.maxgstr.get()))
#		self.graphXMaxOnY.append(float(self.xoffstr.get()) + float(self.maxgstr.get()))
#
#		# initialize graph Y
#		yc = Canvas(self.statusframe, width = self.width/3,	height = self.theight,
#                bg = CNCOLOR, bd = 0, relief = SUNKEN)
#		yc.grid(row = 0, column = 1)
#		self.yc.append(yc)
#		self.yc[self.nodenum].bind("<Button-1>",      self.setYAnchor)		# mouse button pressed on graph Y
#		self.yc[self.nodenum].bind("<B1-Motion>",      self.YflyMotion)	# mouse button moved on graph Y
#		self.yc[self.nodenum].bind("<ButtonRelease-1>", self.setYEndpoint)	# mouse button released on graph Y
#		self.drawGrid(self.yc[self.nodenum], self.width/3, self.theight, 'FFT', 1)
#
#		self.yoffset.append(float(self.yoffstr.get()))
#		self.graphYMinOnY.append(float(self.yoffstr.get()) - float(self.maxgstr.get()))
#		self.graphYMaxOnY.append(float(self.yoffstr.get()) + float(self.maxgstr.get()))
#
#
#		# initialize graph Z
#		zc = Canvas(self.statusframe, width = self.width/3, height = self.theight,
#			        bg = CNCOLOR, bd = 0, relief = SUNKEN)
#		zc.grid(row = 0, column = 2)
#		self.zc.append(zc)
#		self.zc[self.nodenum].bind("<Button-1>",      self.setZAnchor)		# mouse button pressed on graph Z
#		self.zc[self.nodenum].bind("<B1-Motion>",      self.ZflyMotion)	# mouse button moved on graph Z
#		self.zc[self.nodenum].bind("<ButtonRelease-1>", self.setZEndpoint)	# mouse button released on graph Z
#		self.drawGrid(self.zc[self.nodenum], self.width/3, self.theight, 'RESERVED', 0)
#
#		self.zoffset.append(float(self.zoffstr.get()))
#		self.graphZMinOnY.append(float(self.zoffstr.get()) - float(self.maxgstr.get()))
#		self.graphZMaxOnY.append(float(self.zoffstr.get()) + float(self.maxgstr.get()))
#	
#		self.maxg = float(self.maxgstr.get())			# maximum g value on Y-axis
#		
#		
#		
		
		
		
		
        # end of initializing middleframe window
	
		#--------status window-----------------------------#
		self.status = StringVar()
		Label(self.frame, relief = SUNKEN, textvariable = self.status).pack(fill = BOTH)
		self.status.set("Hiperwall GUI")
	# end of def __init__

	#-------------------button functions on the control bar -----------#
	def runSimu(self):					# start button
		if self.fft == 1:
			self.fft = 0
			self.fftbutton.config(text = "FFT")
		#t = time.time()
		t = time.clock()
		
		# switch the status
		if self.simu == 0:
			self.simu = 1
		else: 
			self.simu = 0
			self.file_loaded = 1

		if self.simu == 1:
			# start data acquisition
			self.zoom = 0
			#self.start_time = -40 
			self.simubutton.config(text = 'Stop')
			import threading
			self.nodethread = []
			print 'start reading data...'
			for i in range(0, self.nodenum):
				self.start_time[i] = 0 
				self.prev_time[i] = -1
				self.last_time[i] = 0
				#self.nodethread.append( threading.Thread(target = self.readData1, args =[i])) 
				self.nodethread.append( threading.Thread(target = self.thread_readData, args =[i])) 
				self.nodethread[i].start()
				#self.t0 = t
			if not self.nogui:
				self.thread2 = threading.Thread(target = self.thread_runUpdateGraph)
				self.thread2.start()
		else:

			# end data acquisition
			self.t1 = t
			self.timeRange = self.t1 - self.t0
			for soc in self.socketlist:
				soc.close()
			self.simubutton.config(text = 'Start')
	# end of def runSimu(self)
	
	# Modify by ChongJing on 10/27/2005 to support new version of GUI over FFT functionality 
	def runFFT(self):						# FFT button
		# switch the status
		if self.fft == 0:
			self.fft = 1
		else:
			self.fft = 0

		if self.fft == 1:
			self.fftbutton.config(text = "iFFT")
			for i in range(0, (self.nodenum+1)):
				
				if i != self.nodenum:
					self.drawGrid(self.xc[i], self.width/3, self.theight, 'Node %i in FFT mode '%(i), 0)
				else:
					self.drawGrid(self.xc[i], self.width/3, self.theight, 'X', 0)
					self.drawGrid(self.yc[i], self.width/3, self.theight, 'Y', 0)
					self.drawGrid(self.zc[i], self.width/3, self.theight, 'Z', 0)
				self.runFFT1(i)	
				

		else:
			self.fftbutton.config(text = "FFT")
			for i in range(0, (self.nodenum+1)):
				
				if i != self.nodenum:
					self.drawGrid(self.xc[i], self.width/3, self.theight, 'Node %i'%(i), 0)
				else:
					#print "redraw details after iFFT"
					self.drawGrid(self.xc[i], self.width/3, self.theight, 'X', 0)
					self.drawGrid(self.yc[i], self.width/3, self.theight, 'Y', 0)
					self.drawGrid(self.zc[i], self.width/3, self.theight, 'Z', 0)
			self.lost = 0
			for i in range(0, (self.nodenum+1)):
				#if len(self.x_curve[i]) > 10 or len(self.y_curve[i]) > 10 or len(self.z_curve[i]) > 10:
				self.updateGraph(i)



        def saveData(self, file = ''):                  # save button
                
                if self.simu == 1:
                        return
                
                if not file:
                        file = asksaveasfilename(title= " Save Sensor Profile",
                                        defaultextension = "",
                                        filetypes = (("Plain Text", ".txt"),("All File", "*.*")))

                import os, string
                filePath = os.path.dirname(file)
                fileName = os.path.basename(file)
                try:
                        os.chdir(filePath)
                except:
                        pass
                
                #if len(self.z_curve[self.cur_node])>0:
		for i in range(0, (self.nodenum)): # for each channel 

                        temp_raw_fileName = fileName.split('.')
                        temp_raw_fileName.append('')
                        
                        raw_fileName = str(temp_raw_fileName[0] + '#' + str(i) + '.' + temp_raw_fileName[1])
                        fin = open(raw_fileName, 'w')
                        #fin.write(str(self.timeRange)+ ' '+str((1.00/ self.sample_rate))+'Hz '+tstring+'\n')

                        #print   self.Packet_Size

                        fin.write('Channel ' + str(i) + '\n');
                        #fin.write('Length: ' + str(len(self.x_curve[i])) + '\n')
			
			t = 0
                        #for j in range(1, len(self.x_curve[i]), 2):
                        for j in range(0, len(self.x_curve[i])):
                        	if t != self.timelist[i][j]:
                        		t = self.timelist[i][j]
	                        	fin.write('\n')
	                                fin.write('%9.3f' % self.timelist[i][j])
	                        	fin.write('\t')
	                        	
                               	fin.write('%9.3f' % (self.x_curve[i][j] * 1.5))
                        fin.close()
                        
        # end of saveData



	def loadData(self, file = ""):			# load button
		
		if self.simu == 1:
			return
		
		if file =="":
			file = askopenfilename(title="Open Sensor Data",
                                           #defaultextension="",
                                            filetypes = (("Plain Text", "*"), #".txt"),
                                                         ("All File", "*"))
                                           )
		if file:
			import os
			profileName        = os.path.basename(file)
			profilePath        = os.path.dirname(file)
		 	#print profileName
			try:
				os.chdir(profilePath)
			except:
				pass	
			
			if self.fft == 1:
				self.fft = 0
				self.fftbutton.config(text = "FFT")

			import string	
			fin = open(profileName, 'r')
			line = fin.readline().split()
			#id = line.pop(0))	
			self.timeRange = float(line.pop(0))
			#print id, self.timeRange
			
			self.sample_rate = 1.0/ float(line.pop(0).split('.').pop(0))
			#print line.pop(0).split('.').pop(0)
			startdate = ''
			for buf in line:
				startdate = startdate +' '+buf
			t = 'Sensor data loaded, start at %s'%(startdate)	
			self.status.set(t)
			self.t0 = time.mktime(time.strptime(startdate.strip()))
			self.master.update_idletasks()
			self.zoom = 0
			
			for id in range(0,self.nodenum):
				self.start_time[id]  = 0
				self.prev_time[id]   = -1
				self.timelist[id]=[]
				self.x_curve[id] = []
				self.y_curve[id] = []
				self.z_curve[id] = []
				self.start[id]   = 0
				self.startx[id]  = 0
				self.starty[id]  = 0
				self.startz[id]  = 0
				self.maxx[id]    = 0
				self.maxy[id]    = 0
				self.maxz[id]    = 0
				self.xrax[id]    = 1
				self.xray[id]    = 1
				self.xraz[id]    = 1
				self.st[id]      = 0							
				self.endx[id] = 0
				self.endy[id] = 0
				self.endz[id] = 0
				self.last_time[id] = 0
				
			self.scale   = 1
			self.fft     = 0
			#self.fftbutton.config(text = 'FFT')

			#self.rangeOnX	= float(MAX_TIME)
			#self.scrollunit = self.rangeOnX / 2
		
		
		        #line = fin.readline().split()
		  	#print 'line', line
		  	line = fin.readline().split()
		        #print 'line', line
			while len(line):
				
				for i in range(0,self.nodenum):
					self.timelist[i].append(float(line[0]))
				
				for i in range(0,self.nodenum):
					self.x_curve[i].append(float(line[(i+1)]))
					
					if abs(float(line[(i+1)]))>self.maxx[i]:
				    		self.maxx[i] = abs(float(line[(i+1)]))	
				#if float(line[1]) < self.minx[id]:
				#	self.minx[id] = float(line[1])
				#self.y_curve[id].append(float(line[2]))
				#if abs(float(line[2]))>self.maxy[id]:
				#                        self.maxy[id] = abs(float(line[2]))
				#if float(line[2])< self.miny[id]:
				#	self.miny[id] = float(line[2])
				#    
				#self.z_curve[id].append(float(line[1]))
				#if abs(float(line[1])) > self.maxz[id]:
				#    self.maxz[id] = abs(float(line[1]))
				
					self.y_curve[i].append(192)
					self.z_curve[i].append(192)
				
				#if float(line[3]) < self.minz[id]:
				#	self.minz[id] = float(line[3])
				line = fin.readline().split()	
			
			fin.close()

            		#print 'print self.x_curve[0]',self.x_curve[0]
            
			#for i in range(0, len(self.x_curve)):
			#	print self.x_curve[i], self.y_curve[i], self.z_curve[i]	
			
			#self.endx[id] = len(self.x_curve[id])
			#self.endy[id] = len(self.y_curve[id])
			#self.endz[id] = len(self.z_curve[id])	
			#self.sample_rate = self.timeRange / len(self.z_curve[id])

			print 'sampling rate: ',self.sample_rate
			self.file_loaded = 1
			#if self.fft == 0:
			for i in range(0,self.nodenum):
				self.updateGraph(i)
			
			self.yc[self.nodenum].delete('x')
		# if
	# end of loadData

	def saveLog(self):						# Log button
		logStatus = (self.log + 1) % 2		# switch status
		if logStatus == 1:					# start logging
			self.logbutton.config(text = "StopLog")

			localtime = time.localtime()
			filename_prefix = "log"
			for i in range(0, 6):		# year + mon + day + hour + min + sec
				filename_prefix = filename_prefix + str('%02d'%localtime[i])
			for i in range(0, len(nodes)):
				self.filename[i] = filename_prefix + 'N'+str(i) + '.txt'
				print 'filename', self.filename[i]
				fdlog = open(self.filename[i], 'w')
				fdlog.write(nodes[i]+','+str(self.sample_rate)+'\n')
				self.log = logStatus
		else:
			self.logbutton.config(text = "StartLog")
			self.log = logStatus
			#for j in range(0, len(nodes)):
			#	self.fdlog[j].close()			
		# if-else
	# end of saveLog

	def zoomIn(self):
		if self.rangeOnX > MIN_RANGE_ON_X:
			self.rangeOnX /= 2.0
		print 'zoomIn , rangeOnX in zoomIn: ', self.rangeOnX
		for i in range(0, len(nodes)):
			self.display(i, self.st[i], 'X')
			#self.display(i, self.st[i], 'Y')
			#self.display(i, self.st[i], 'Z')
	# end of zoomIn

	# Not used
	#	caller:
	#			none
	def zoomOut1(self, event):
		self.zoomOut()

	def zoomOut(self):						# ZoomOut button
		self.rangeOnX *= 2
		if self.rangeOnX > MAX_TIME:
			self.rangeOnX = float(MAX_TIME)
			self.zoom = 0
		event = Event()
		for i in range(0, len(nodes)):
			self.display(i, 0, 'X')
			#self.display(i, 0, 'Y')
			#self.display(i, 0, 'Z')
		#self.scrollunit = SCROLL_UNIT
		#self.scrollunit = self.rangeOnX / 2
		print 'zoomOut, rangeOnX in zoomIn: ', self.rangeOnX
		#self.runFFT1(self.cur_node)
			
	def calibration(self):						# calibration button
		def setcali():
			id = int(self.nodestr.get())
			#self.xoffset[id] = float(self.xoffstr.get())
			#self.yoffset[id] = float(self.yoffstr.get())
			#self.zoffset[id] = float(self.zoffstr.get())
 			self.maxg = float(self.maxgstr.get())
			self.graphXMinOnY[id] = float(self.xminOnY.get())
			self.graphXMaxOnY[id] = float(self.xmaxOnY.get())
			self.graphYMinOnY[id] = float(self.yminOnY.get())
			self.graphYMaxOnY[id] = float(self.ymaxOnY.get())
			self.graphZMinOnY[id] = float(self.zminOnY.get())
			self.graphZMaxOnY[id] = float(self.zmaxOnY.get())

			try:
				self.updateGraph(self.cur_node)
			except:
				pass
			nf.destroy()
		# end of setcali

		# open a popup window
		nf = Toplevel()
		t = "Calibration"
		nf.title(t)
		self.status.set(t)
		infoFrame = Frame(nf, width = self.nodewin_width,
		              height = self.nodewin_height,  bd = 1)
		infoFrame.pack(fill = BOTH, expand = 0)

		Label(infoFrame,  text = 'Node ID').grid(row = 0, column = 0, sticky = W)
		Label(infoFrame,  text = 'Min').grid(row = 1, column = 1, sticky = W)
		Label(infoFrame,  text = 'Max').grid(row = 1, column = 2, sticky = W)
		Label(infoFrame,  text = 'X').grid(row = 2, column = 0, sticky = W)
		Label(infoFrame,  text = 'Y').grid(row = 3, column = 0, sticky = W)
		Label(infoFrame,  text = 'Z').grid(row = 4, column = 0, sticky = W)
		Entry(infoFrame, textvariable = self.nodestr).grid(row = 0, column = 1)
		Entry(infoFrame, textvariable = self.xminOnY).grid(row = 2, column = 1)
		Entry(infoFrame, textvariable = self.xmaxOnY).grid(row = 2, column = 2)
		Entry(infoFrame, textvariable = self.yminOnY).grid(row = 3, column = 1)
		Entry(infoFrame, textvariable = self.ymaxOnY).grid(row = 3, column = 2)
		Entry(infoFrame, textvariable = self.zminOnY).grid(row = 4, column = 1)
		Entry(infoFrame, textvariable = self.zmaxOnY).grid(row = 4, column = 2)
		Button(infoFrame, text = 'OK', command = setcali).grid(row = 5, column = 1)
	# end of calibration

	def help(self):                                # help button
		pass	
	
	def quit(self):                                # quit button
		for soc in self.socketlist: 
			if soc: soc.close()
		root.destroy()
	
	#---------------- event binding -----------#
	def execcmd(self, event):
		exec(self.cmdstr.get())
                self.keybuf.append(self.cmdstr.get())
		self.cmdstr.set('')

	def getbuf(self, event):
		if len(self.keybuf)>0 :self.cmdstr.set(self.keybuf.pop(-1))
			
    # modifed by SM
    # 8/16/05
	def selectNode(self, event):
		cmptags = self.c.gettags(self.c.find_closest(event.x, event.y))
		#print 'cmptags == ', cmptags
		if len(cmptags) != 0 and cmptags[0] !='current':
			prev_item = self.nodelist[self.prevSelect]['node']
			prev_line = self.nodelist[self.prevSelect]['line']
			cur_item = self.nodelist[int(cmptags[0])]['node']
			cur_line = self.nodelist[int(cmptags[0])]['line']
			color = self.nodelist[self.prevSelect]['color']
			self.c.itemconfigure(prev_item, fill = color, outline = color)
			self.c.itemconfigure(prev_line, fill = self.C.canvas_bg)
			self.c.itemconfigure(cur_item,  fill = self.C.selected_color)
			self.c.itemconfigure(cur_line,  fill = self.C.selected_color)
			self.prevSelect = int(cmptags[0])
			self.status.set('Viewing node ' + self.nodelist[int(cmptags[0])]['tags'])
			self.cur_node = int(cmptags[0])		
			self.updateGraph(self.cur_node)
		# if
	# end of selectNode
	'''def selectNode(self, event):
		cmptags = self.c.gettags(self.c.find_closest(event.x, event.y))		
		if cmptags[0] !='current':
			if self.prevSelect != 0:
				self.c.itemconfigure(self.nodelist[self.prevSelect-1], outline = 'black')	
			self.c.itemconfigure(self.nodelist[int(cmptags[0])-1], outline = 'white')
			self.prevSelect = int(cmptags[0])
			self.status.set('Node ' + cmptags[0])
			
			self.cur_node = int(cmptags[0])-1
	'''
	def nodeInfo(self, event):
		def sendCommand():
			print 'size: ', self.size.get(), 'rate: ', self.rate.get()
			print 'tx_rate: ', self.tx_rate.get(), 'tx_power: ', self.tx_power.get()
	
		def closeWindow():
			nf.destroy()
		
		cmptags = self.c.gettags(self.c.find_closest(event.x, event.y))
		if cmptags[0] !='current' and int(cmptags[0])!=base:
			nf = Toplevel()
			t = "Node " + cmptags[0] + " Configuration"
			nf.title(t)
			self.status.set(t) 
			infoFrame = Frame(nf, width = self.nodewin_width, 
					 height = self.nodewin_height,  bd = 1)
			infoFrame.pack(fill = BOTH, expand = 0)
			Label(infoFrame,  text = 'Node').grid(row = 0, column = 0, sticky = W)
			Label(infoFrame, text = cmptags[0]).grid(row = 0, column = 1, sticky = W)
			Label(infoFrame, text = 'Battery').grid(row = 1, column = 0, sticky = W)
			Label(infoFrame, text ='100').grid(row = 1, column = 1, sticky = W)

			Label(infoFrame, text = 'Sampling Rate').grid(row = 2, column = 0, sticky = W)
			Label(infoFrame, text = 'Buffer Size').grid(row = 3, column = 0, sticky = W)
			Label(infoFrame, text = 'TX Rate').grid(row = 4, column = 0, sticky = W)
			Label(infoFrame, text = 'TX Power').grid(row = 5, column = 0, sticky = W)
			Entry(infoFrame, textvariable = self.size).grid(row = 2, column = 1)
			Entry(infoFrame, textvariable = self.rate).grid(row = 3, column = 1)
			Entry(infoFrame, textvariable = self.tx_rate).grid(row = 4, column = 1)
			Entry(infoFrame, textvariable = self.tx_power).grid(row = 5, column = 1)
			Label(infoFrame, text = '(1-10)').grid(row = 2, column = 2, sticky = W)
			Label(infoFrame, text = '(1-10)').grid(row = 3, column = 2, sticky = W)
			Label(infoFrame, text = '(1-10)').grid(row = 4, column = 2, sticky = W)
			Label(infoFrame, text = '(1-10)').grid(row = 5, column = 2, sticky = W)
			Button(infoFrame, text = 'Configure', command = sendCommand).grid(row = 6, column = 0)
			Button(infoFrame, text = 'Close', command = closeWindow).grid(row = 6, column = 2)

			self.rate.set(self.ratelist[int(cmptags[0])])
			self.size.set(self.ratelist[int(cmptags[0])])
			self.tx_rate.set(self.ratelist[int(cmptags[0])])
			self.tx_power.set(self.ratelist[int(cmptags[0])])
		# if
	# end of nodeInfo

	# this was made for debugging
	# by SM
	def hello(self, event):
		print 'hello'
	
	# 8/16/05 modified by SM 
	# 09/11/05 MODIFIED by ChongJing 
	
	def setXAnchor(self, event):
		#print 'setXAnchor: mouse clicked at (', event.x,',', event.y,')', 'current node is', self.cur_node
	
		if not self.nogui:
			if self.fft == 0:
			
				for i in range(0, self.nodenum):
					if event.widget == self.xc[i]:
						self.cur_node = i
						print "setXAnchor"
						self.updateGraph1(i)
						self.status.set("Now showing Node %i details"%(self.cur_node))
						break		
			
			else:
				print "fft click"
				for i in range(0, self.nodenum):
					print i
					if event.widget == self.xc[i]:
						print "after click , runFFT %i"%(i)
						self.cur_node = i
						self.runFFT1(self.nodenum)
						self.status.set("Now showing Node %i FFT details"%(self.cur_node))
						break	
			
			if self.simu or len(self.x_curve[0]) < 2:
				return
        # the below lines were changed by SM
        # 8/17/05
		#if event.widget == self.xc:
		#	x = self.xc.canvasx(event.x)
		#	self.startxy = self.xc.canvasy(event.y)
		#else:
		#	x = self.fxc.canvasx(event.x)
		#	self.startxy = self.fxc.canvasy(event.y)


		#print 'node id: ', self.cur_node
	
			x = event.widget.canvasx(event.x)
			self.startxy = event.widget.canvasy(event.y)
	
			if x > self.xmargin:
				#startx =int( (x-self.xmargin)/self.xrax)
				self.startxx = x
			else: 
				self.startxx = self.xmargin 
				#startx = 0
			#self.startx += startx
			self.bxrel = 0
		

	
	def setYAnchor(self, event):
		#print 'setYAnchor: mouse clicked at (', event.x,',', event.y,')'
		if self.simu or len(self.y_curve[0]) < 2:
			return
		# the below statements were changed by SM
		# 8/17/05
		#if event.widget == self.yc:
		#	x = self.yc.canvasx(event.x)
        #	self.startyy = self.yc.canvasy(event.y)
		#else:
		#	x = self.fyc.canvasx(event.x)
        #	self.startyy = self.fyc.canvasy(event.y)
		for i in range(0, self.nodenum):
			if event.widget == self.yc[i]:
				self.cur_node = i
				break
		#print 'node id: ', self.cur_node

		x = event.widget.canvasx(event.x)
		self.startyy = event.widget.canvasy(event.y)
		if x > self.xmargin:
			self.startyx = x
		else:
			self.startyx = self.xmargin
		self.byrel  = 0

	def setZAnchor(self, event):
		#print 'setYAnchor: mouse clicked at (', event.x,',', event.y,')'
		if self.simu or len(self.z_curve[0]) < 2:
			return
		#if event.widget == self.zc:
		#	x = self.zc.canvasx(event.x)
        #        	self.startzy = self.zc.canvasy(event.y)
		#else:
		#	x = self.zc.canvasx(event.x)
        #        	self.startzy = self.zc.canvasy(event.y)
		#x = self.zc.canvasx(event.x)
                #self.startzy = self.zc.canvasy(event.y)
		for i in range(0, self.nodenum):
			if event.widget == self.zc[i]:
				self.cur_node = i
				break
		#print 'node id: ', self.cur_node

		x = event.widget.canvasx(event.x)
		self.startzy = event.widget.canvasy(event.y)
		if x > self.xmargin:
			self.startzx = x
                else:
			self.startzx = self.xmargin
		self.bzrel  = 0 
	
	def setXEndpoint(self, event):
		#print 'setXEndpoint'
		if self.simu or self.file_loaded == 0: return
		#print 'event.widget', event.widget
		#print 'self.xc', self.xc
		id = self.cur_node
		c = event.widget
		if event.widget == self.xc[id]:						# ????
			#c = self.xc
			fft = 0
		else:
            # modified by SM
            # 8/16/05
			#c = self.fxc
			fft = 1
		cmptags = c.gettags(c.find_closest(event.x, event.y))
		#print 'cmptags in setXEndpoint', cmptags
		#if len(cmptags) == 0:
		#	print 'event is empty'
		#	return
		
		#print 'cmptags[0]', cmptags[0]
		#print 'cmptags[1][1]',cmptags[1][1]
		if len(cmptags) > 2:
			if cmptags[1][1] == '>': 
				#print '???'
				self.forward(cmptags[1][0])		# shift three graphs forward
				return
			elif cmptags[1][1] =='<': 
				#print '!!!!'
				self.backward(cmptags[1][0])		# shift three graphs backward
				return

		# Zoom-in
		c.delete('zm')				# delete the rectangle showing the selected area
		
		return						# for the time being, zoom-in is disabled
		
		self.bxrel   = 1
		x = c.canvasx(event.x)
		#self.startz[self.cur_node], self.xraz[self.cur_node] =
		if abs(x-self.startxx) < 4 or self.file_loaded == 0:	# if selected area is too small or there is no data 
			return
		if fft == 0:
			self.startx[id], self.xrax[id], self.endx[id] = self.setEndpoint(x, c,
                	self.x_curve[id], self.fft_x_curve[id],
                	self.startx[id], self.endx[id],
                	self.maxx[id],   self.maxxf[id],
                	self.startxx, self.xrax[id], 'x', fft)
		else:
			self.startfx[id], self.xrafx[id], self.endfx[id] = self.setEndpoint(x, c,
                	self.x_curve[id], self.fft_x_curve[id],
                	self.startfx[id], self.endfx[id],
                	self.maxx[id],   self.maxxf[id],
                	self.startxx, self.xrafx[id], 'x', fft)
		#print 'startx: ', self.startx[id], 'endx: ',self.endx[id]
		#self.scrollunit = int(((self.endx[id] - self.startx[id]) / 2) * self.sample_rate / 2) * 2	# even number
	# end of setXEndpoint
	
	def setYEndpoint(self, event):
		if self.simu or self.file_loaded == 0: return
	
		# the below lines were changed by SM
		# 8/17/05
		id = self.cur_node
		c = event.widget
		if event.widget == self.yc[id]:
		#	c = self.yc
			fft = 0
		else:
		#	c = self.yc
			fft = 1
		cmptags = c.gettags(c.find_closest(event.x, event.y))
		#print 'cmptags in setYEndpoint', cmptags 
		if cmptags[0] == 'Y>':
			self.forward('Y')
			return
		elif cmptags[0] =='Y<':
			self.backward('Y')
			return

		# Zoom-in
		c.delete('zm')				# delete the rectangle showing the selected area
		
		return						# for the time being, zoom-in is disabled
		
		self.byrel   = 1
		x = c.canvasx(event.x)
		#self.startz[self.cur_node], self.xraz[self.cur_node] =
		if abs(x-self.startyx) < 4: return
		if fft == 0:
			self.starty[id], self.xray[id], self.endy[id] = self.setEndpoint(x, c,
                	self.y_curve[id], self.fft_y_curve[id],
                	self.starty[id], self.endy[id],
                	self.maxy[id],   self.maxyf[id],
                	self.startyx, self.xray[id], 'y', fft)
		else:
			self.startfy[id], self.xrafy[id], self.endfy[id] = self.setEndpoint(x, c,
                	self.y_curve[id], self.fft_y_curve[id],
                	self.startfy[id], self.endfy[id],
                	self.maxy[id],   self.maxyf[id],
                	self.startyx, self.xrafy[id], 'y', fft)

	def setZEndpoint(self, event):
		if self.simu or self.file_loaded == 0: return
        # the below lines were changed by SM
        # 8/17/05
		id = self.cur_node
		c = event.widget
		if event.widget == self.zc[id]:
		#	c = self.zc
			fft = 0
		else:
		#	c = self.zc
			fft = 1
		cmptags = c.gettags(c.find_closest(event.x, event.y))
		#print 'cmptags in setZEndpoint', cmptags 
		if cmptags[0] == 'Z>':
			self.forward('Z')
			return
		elif cmptags[0] =='Z<': 
			self.backward('Z')
			return

		# Zoom-in
		c.delete('zm')				# delete the rectangle showing the selected area
		
		return						# for the time being, zoom-in is disabled
		
		self.bzrel   = 1
		x = c.canvasx(event.x)
		#self.startz[self.cur_node], self.xraz[self.cur_node] =
		if abs(x-self.startzx) < 4: return
		if fft == 0:
			self.startz[id], self.xraz[id], self.endz[id] = self.setEndpoint(x, c,
			self.z_curve[id], self.fft_z_curve[id], 
			self.startz[id], self.endz[id], 
			self.maxz[id],  self.maxzf[id], 
			self.startzx, self.xraz[id], 'z', fft)
		else:
			self.startfz[id], self.xrafz[id], self.endfz[id] = self.setEndpoint(x, c,
			self.z_curve[id], self.fft_z_curve[id], 
			self.startfz[id], self.endfz[id], 
			self.maxz[id],  self.maxzf[id], 
			self.startzx, self.xrafz[id], 'z', fft)
	# end of setZEndpoint

	# This is for zoom-in
	# return:
	#		start:	??
	#		xra:	??
	#		end:	??
	#
	def setEndpoint(self, x, c, curv, fft_curves, start, end, maxt, maxf, startx, xra, tags, fft):
		if fft == 0 and len(curv) < 3: return
		if fft == 1 and len(fft_curves) < 3: return
		if self.zoom == 0 and fft == 0:
			endx =int((x-self.xmargin)/xra/self.sample_rate)
		else:
			endx =int((x-self.xmargin)/xra)
		endx += start
		if endx > len(curv): endx = len(curv)
		if startx > self.xmargin:
			if self.zoom == 0 and fft == 0:
				start += int( (startx-self.xmargin)/xra/self.sample_rate)
			else:
				start += int( (startx-self.xmargin)/xra)
		self.zoom = 1
		if fft == 0: 
			max = maxt 
			curves = curv
			#if start <= endx: end = endx
			#else:
                        #        end = start
                        #        start = endx
		        #		endx = end
		else: 
			max = maxf
			curves = fft_curves	
		if start <= endx:
			end = endx
		else:
			# swap(start, endx)
			p = endx
			endx = start
			start = p	
		#xra = self.drawData(c, endx, max, curves, start, tags, fft)
		#*******************xra = self.drawData(c, endx, max, curves, start, tags, fft, self.cur_node)
		#if fft == 0:
			#xraf = self.drawData(c, endx, max, curves, start, tags, fft)
		#	self.runFFT1(self.cur_node)
		return start, xra, end	
	# end of setEndpoint

	# modified by SM
	# 8/18/05
	def XflyMotion(self, event):
		if self.simu or len(self.x_curve[self.cur_node]) < 2: return
		c = event.widget
		#if event.widget == self.xc:
		#	c = self.xc
		#else:
		#	c = self.fxc
		if self.bxrel == 0 and (self.startx[self.cur_node] >= 0 or seld.startfx[self.cur_node] >=0):
			x = c.canvasx(event.x)
			y = c.canvasy(event.y)
			c.delete('zm')
			c.create_rectangle(self.startxx, self.startxy, x, y,outline = 'green', stipple='gray25', tags = 'zm')
			return
		else:
			c.delete('zm')
    # end of XflyMotion

	def YflyMotion(self, event):
		if self.simu or len(self.y_curve[self.cur_node]) < 2: return
		c = event.widget
		#if event.widget == self.yc:
		#	c = self.yc
		#else:
		#	c = self.fyc
		if self.byrel == 0 and self.starty[self.cur_node] >= 0:
			x = c.canvasx(event.x)
			y = c.canvasx(event.y)
			c.delete('zm')
			c.create_rectangle(self.startyx, self.startyy, x, y,outline = 'green', stipple='gray25', tags = 'zm')
			return
		else:
			c.delete('zm')
    # end of YflyMotion
 
	def ZflyMotion(self, event):
		if self.simu or len(self.z_curve[self.cur_node]) < 2: return
		c = event.widget
		#if event.widget == self.zc:
		#	c = self.zc
		#else:
		#	c = self.fzc
		if self.bzrel == 0 and self.startz[self.cur_node] >= 0:
			x = c.canvasx(event.x)
			y = c.canvasx(event.y)
			c.delete('zm')
			c.create_rectangle(self.startzx, self.startzy, x, y, outline = 'green', stipple='gray25', tags = 'zm')
			return
		else:
			c.delete('zm')
    # end of ZflyMotion

	def xZoomOut(self, event):
		if self.simu: return
		self.startx[self.cur_node] = 0
                max = self.maxxf[self.cur_node]
                min = 0
		curves = self.fft_x_curve[self.cur_node]
		i = 0
		while i/(self.sample_rate*len(self.fft_x_curve[self.cur_node]))<=20:
			i+=1
		endx = i
		self.xrax[self.cur_node] = self.drawData(self.fxc, endx, max, curves, 0, 'x', 1)
		self.runFFT1(self.cur_node)

	def yZoomOut(self, event):
		if self.simu: return
		self.starty[self.cur_node] = 0 
		
                max = self.maxyf[self.cur_node]
		curves = self.fft_y_curve[self.cur_node]
		i = 0
		while i/(self.sample_rate*len(self.fft_y_curve[self.cur_node]))<=20:
               		i+=1
		endx = i
                self.xray[self.cur_node] = self.drawData(self.fyc, endx, max, curves, 0, 'y', 1)
		self.runFFT1(self.cur_node)

	def zZoomOut(self, event):
		if self.simu: return
		self.startz[self.cur_node] = 0 
				
                max = self.maxzf[self.cur_node]
                min = 0
		curves = self.fft_z_curve[self.cur_node]
		i = 0
		while i/(self.sample_rate*len(self.fft_z_curve[self.cur_node]))<=20:
               		i+=1
		endx = i
               	self.updateGraph(self.cur_node)
		#self.xraz[self.cur_node] = self.drawData(self.zc, endx, max, curves, 0, 'z', 0)
		#self.runFFT1(self.cur_node)

	# scroll forward
	def forward(self, place):
		#if self.zoom == 1:
		#	self.zoomOut()
		self.scrollunit = self.rangeOnX / 2
		#print 'scrollunit in forward: ', self.scrollunit
		self.st[self.cur_node] += self.scrollunit
		self.display(self.cur_node, self.st[self.cur_node], place)
	
	# scroll backward
	def backward(self, place):
		#if self.zoom == 1:
		#	self.zoomOut()
		self.scrollunit = self.rangeOnX / 2
		#print 'scrollunit in backward: ', self.scrollunit
		self.st[self.cur_node] -= self.scrollunit
		if self.st[self.cur_node] < 0:
			self.st[self.cur_node] = 0
		self.display(self.cur_node, self.st[self.cur_node], place)
	
    # ??
	def placeNodes(self):
		self.nodelist = {}
		centerx = self.C.c_width/2
		centery = self.C.c_height/2
		radius	= self.C.radius
		R 		= self.C.distance
		
		#self.ihost = self.c.create_image(
		#			centerx, centery,
        #           image=photo,
        #        	tags = 'Host')
		self.hnode = self.c.create_oval(
					centerx-radius*.6, centery-radius*.6,
                    centerx+radius*.6, centery+radius*.6,
                    fill = 'black')
		self.hnodet = self.c.create_text(
                        centerx, centery,
                        text = 'H', fill='white')
		import math
		length = len(nodes)
		for i in range(0,length):
			id = nodes[i]
			ras = math.radians(i*360.0/length)
			x = centerx - R*math.cos(ras)
			y = centery - R*math.sin(ras)
			node = self.c.create_rectangle(
						x -radius, 
						y -radius, 
						x +radius,
					    y +radius,
						tags = str(i),
                        fill = self.C.colorlib[i],
                        outline = self.C.colorlib[i])
			self.c.create_text(x, y, text = id, tags = str(i),
                               font = self.C.font4)
			line = self.c.create_line(centerx, centery, x, y, tags=str(i),
                                      fill=self.C.canvas_bg)
			self.c.lower(line)
			self.nodelist[i] = {}
			self.nodelist[i]['tags'] = id
			self.nodelist[i]['node'] = node
			self.nodelist[i]['line'] = line
			self.nodelist[i]['color'] = self.C.colorlib[i]
		self.cur_node = 0
	# end of placeNodes
	
	# this is called by forward, backward, and zoomOut
	# modified by SM
	# 8/18/05
	#	caller:
	#			zoomOut, forward, backward
	def display(self, id, start, axis):
		#print 'cur_node', self.cur_node	
		#id = self.cur_node
		self.sta = start
		self.start[id] = int(start/self.sample_rate)	
                #print  self.start[self.cur_node], self.z_curve[self.cur_node]
		if self.start[id] > len(self.x_curve[id]): 
			self.st[id] -= self.scrollunit
			return

		self.startx[id] = self.start[id]
		if self.zoom == 0:
			#self.endx[id] = int((start+MAX_TIME)/self.sample_rate)
			self.endx[id] = int((start+self.rangeOnX)/self.sample_rate)
		else:
			self.endx[id] = int(((start+2*self.scrollunit))/self.sample_rate)
		if self.endx[id] > len(self.x_curve[id]):
			self.endx[id] = len(self.x_curve[id])

		self.starty[id] = self.start[id]
		self.endy[id] = self.endx[id]

		self.startz[id] = self.start[id]
		self.endz[id] = self.endx[id]

		#*******************self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.maxx[id], self.x_curve[id], self.start[id], 'x', 0, id)
		#self.xray[id] = self.drawData(self.yc[id], self.endy[id], self.maxy[id], self.y_curve[id], self.start[id], 'y', 0, id)
		#self.xraz[id] = self.drawData(self.zc[id], self.endz[id], self.maxz[id], self.z_curve[id], self.start[id], 'z', 0, id)
	# end of display

	def saveBuffer(self, size):
		if len(self.z_curve[self.cur_node]) < 1:
			print "Error: no data to write!\n"
			return

		file = 'result.txt'
		import os
		fin = open(file, 'a')
		for i in range(0, size):
			fin.write(str(self.x_curve[self.cur_node].pop(0))+' '+\
                          str(self.y_curve[self.cur_node].pop(0))\
                          +' '+str(self.z_curve[self.cur_node].pop(0))+'\n')
		fin.close()
	# end of saveBuffer

	#	caller:
	#			runFFT, loadData, calibration, selectNode, zZoomOut
	def updateGraph(self, id):
		if self.simu == 1:
			t = time.time()	
			#self.sample_rate = SAMPLING_RATE
			#while t - self.start_time[id]-self.t0 > MAX_TIME:
			while t - self.start_time[id]-self.t0 > self.rangeOnX:
				self.start[id] = self.endz[id]
				#self.start_time[id] += MAX_TIME
				self.start_time[id] += self.rangeOnX
				for i in range(0, len(self.nodelist)-1):
					self.st[i] = self.start_time[id]
			self.endx[id] = len(self.x_curve[id])#*self.sample_rate
			#self.endy[id] = len(self.y_curve[id])#*self.sample_rate
			#self.endz[id] = len(self.z_curve[id])#*self.sample_rate
			#*******************self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.maxx[id],  self.x_curve[id], self.start[id], 'x',0, id)
			#self.xray[id] = self.drawData(self.yc[id], self.endy[id], self.maxy[id],  self.y_curve[id], self.start[id], 'y',0, id)
			#self.xraz[id] = self.drawData(self.zc[id], self.endz[id], self.maxz[id],  self.z_curve[id], self.start[id], 'z',0, id)
		else:		# when data are loaded, else part is executed
		
			if id == self.nodenum:
				id = self.cur_node 
				flag=1
				#*******************self.xrax[self.nodenum] = self.drawData(self.xc[self.nodenum], self.endx[self.cur_node], self.maxx[self.cur_node], self.x_curve[self.cur_node], self.startx[self.cur_node], 'x', 0, self.cur_node)
#				self.xray[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endy[self.cur_node], self.maxy[self.cur_node], self.y_curve[self.cur_node], self.starty[self.cur_node], 'y', 0, self.cur_node)
#				self.xraz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endz[self.cur_node], self.maxz[self.cur_node], self.z_curve[self.cur_node], self.startz[self.cur_node], 'z', 0, self.cur_node)
			
			
			if self.file_loaded == 0: return	# if there is no data
			self.start[id] = int(self.st[id]/self.sample_rate)	
			self.startx[id] = self.start[id]
#			self.starty[id] = self.start[id]
#			self.startz[id] = self.start[id]
			#print 'self.st[', id, ']', ': ', self.st[id]
			#print 'self.start[', id, ']', ': ', self.start[id]
			#self.endz[id] = int((self.st[id]+MAX_TIME)/self.sample_rate)	
			self.endz[id] = int((self.st[id]+self.rangeOnX)/self.sample_rate)	
			if self.endz[id] > len(self.z_curve[id]):
				self.endz[id] = len(self.z_curve[id])	
			self.endy[id] = self.endz[id]
			self.endx[id] = self.endz[id]
			# the below drawData calls were fixed by SM	
			#*******************self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.maxx[id],  self.x_curve[id], self.startx[id], 'x', 0, id)
#			self.xray[id] = self.drawData(self.yc[id], self.endy[id], self.maxy[id],  self.y_curve[id], self.starty[id], 'y', 0, id)
#			self.xraz[id] = self.drawData(self.zc[id], self.endz[id], self.maxz[id],  self.z_curve[id], self.startz[id], 'z', 0, id)
			if self.fft == 1:self.runFFT1(id)
		# if-else
	# end of updateGraph

	# this function is only called by runUpdateGraph (database.py) 
	def updateGraph1(self, id):
		flag=0
		#print id, self.simu
		
		if self.simu == 1 and self.fft == 0:
			t = time.time()
			t0 = self.sample_rate*len(self.z_curve[id])     # time generated by the number of data packets
				
			tp = t - self.t0                                # real time difference
			if t0 > tp:  tt = tp
			else: tt = t0
			
			while tt - self.start_time[id] > self.rangeOnX:
				#print "enter stepping loop", tt, self.start_time[id],self.rangeOnX
				self.start[id] = self.endx[id]
				self.startx[id] = self.endx[id]
#					self.starty[id] = self.endy[id]
#					self.startz[id] = self.endz[id]
				#self.start_time[id] += MAX_TIME
				self.start_time[id] += self.rangeOnX
				#for i in range(0, len(self.nodelist)-1):
				#for i in range(0, len(self.nodelist)):
				#	self.st[i] = self.start_time[id]
				self.st[id] = self.start_time[id]
				#print 'start_time: ', self.start_time
				#print 'st: ', self.st
			if (tt -self.last_time[id] > 0.5): #set by Vahid default: 0.5
				#time.sleep(0.1)
				self.last_time[id] += 0.5 #set by Vahid default: 0.5
				#print "lst time:", self.last_time[id]
			else: 
				return


			#print "t:", t
			#print "t0:", t0
			#print "tp:", tp
			#print "tt:", tt
			
			index = int(self.last_time[id]/self.sample_rate)
			#print 'index: ', index
			self.endx[id] = index #*self.sample_rate
#				self.endy[id] = index #*self.sample_rate
#				self.endz[id] = index #*self.sample_rate
			
			#print "the range is self.endx[",id,"]:", self.start[id], self.endx[id],self.last_time[id]

			#print 'inside ori drawdata', id
			#if flag == 0:
			
			#self._lock2.acquire()
			
			################################################
			
			#self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.maxx[id], self.x_curve[id], self.startx[id], 'x', 0, id)
			#drawData(self, canvas, maxx, maxY, curves, index_start, item, mode, id):
			

			#print 'id:', id
				#print 'xc: ', self.xc[id]
				#print 'end:' , self.endx[id]
				#print 'start:' , self.startx[id]
				#print 'maxx:' , self.maxx[id]
				#print 'length:' , len(self.x_curve[id])
			#print "xrax: ", self.xrax[id]
			#temp = []
			#for j in range(self.startx[id], self.endx[id], 2):
			#	temp.append(self.x_curve[id][j+1])
			#print temp
			#print self.x_curve[id]
			#print " "
			
			if self.startx[id] % 2 == 0 : #important bug fix by Vahid
				self.startx[id] += 1

			self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.x_curve[id], self.startx[id], 'x', 0, id)


			#self.xrax[id] = self.drawData(self.xc[id], self.endx[id] - self.startx[id] -1, temp, 0, 'x', 0, id)

			################################################
			
			#except:
				#print id
			#if len(self.x_curve[self.cur_node]) >10 :
			#if flag == 1 :
			#print 'len of xc', len(self.xc), self.nodenum, self.cur_node
			#self.xrax[self.nodenum] = self.drawData(self.xc[self.nodenum], self.endx[self.cur_node], self.maxx[self.cur_node], self.x_curve[self.cur_node], self.startx[self.cur_node], 'x', 0, self.cur_node)
			#self.xray[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endy[self.cur_node], self.maxy[self.cur_node], self.y_curve[self.cur_node], self.starty[self.cur_node], 'y', 0, self.cur_node)
			#self.xraz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endz[self.cur_node], self.maxz[self.cur_node], self.z_curve[self.cur_node], self.startz[self.cur_node], 'z', 0, self.cur_node)
			
		
			#print flag		
		elif self.simu == 0 and self.fft == 0 :
			
			if self.file_loaded == 0: return
			self.start[id] = int(self.st[id]/self.sample_rate)
			self.startx[id] = self.start[id]
#			self.starty[id] = self.start[id]
#			self.startz[id] = self.start[id]
			#self.endz[id] = int((self.st[id]+MAX_TIME)/self.sample_rate)
			self.endz[id] = int((self.st[id]+self.rangeOnX)/self.sample_rate)
			if self.endz[id] > len(self.z_curve[id]):
				self.endz[id] = len(self.z_curve[id])
			self.endy[id] = self.endz[id]
			self.endx[id] = self.endz[id]
			#*******************self.xrax[id] = self.drawData(self.xc[id], self.endx[id], self.maxx[id], self.x_curve[id], self.startx[id], 'x', 0, id)
#			self.xray[id] = self.drawData(self.yc[id], self.endy[id], self.maxy[id], self.y_curve[id], self.starty[id], 'y', 0, id)
#			self.xraz[id] = self.drawData(self.zc[id], self.endz[id], self.maxz[id], self.z_curve[id], self.startz[id], 'z', 0, id)
			
			#if len(self.x_curve[self.cur_node]) >10 :
	
			#print 'len of xc', len(self.xc), self.nodenum, self.cur_node
			#**************self.xrax[self.nodenum] = self.drawData(self.xc[self.nodenum], self.endx[self.cur_node], self.maxx[self.cur_node], self.x_curve[self.cur_node], self.startx[self.cur_node], 'x', 0, self.cur_node)
#			self.xray[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endy[self.cur_node], self.maxy[self.cur_node], self.y_curve[self.cur_node], self.starty[self.cur_node], 'y', 0, self.cur_node)
#			self.xraz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endz[self.cur_node], self.maxz[self.cur_node], self.z_curve[self.cur_node], self.startz[self.cur_node], 'z', 0, self.cur_node)
				
			
			
			#print flag
		elif self.simu == 0 and self.fft == 1 :		
#			
				print "inside update graph for FFT for node %i"%(id)
#				t = time.time()
#				self.sample_rate = SAMPLING_RATE		# this should be set when the data acquisition starts.
#				#print 'len',len(self.z_curve[id])
#				t0 = self.sample_rate*len(self.z_curve[id])     # time generated by the number of data packets
#				tp = t - self.t0                                # real time difference
#				if t0 > tp:  tt = tp
#				else: tt = t0
#				#print t0, tp, tt
#				#while tt - self.start_time[id] > MAX_TIME:
#				 
#				while tt - self.start_time[id] > self.rangeOnX:
#					self.start[id] = self.endz[id]
#					self.startx[id] = self.endx[id]
#					self.starty[id] = self.endy[id]
#					self.startz[id] = self.endz[id]
#					#self.start_time[id] += MAX_TIME
#					self.start_time[id] += self.rangeOnX
#					#for i in range(0, len(self.nodelist)-1):
#					#for i in range(0, len(self.nodelist)):
#					#	self.st[i] = self.start_time[id]
#					self.st[id] = self.start_time[id]
#					#print 'start_time: ', self.start_time
#					#print 'st: ', self.st
#				if (tt -self.last_time[id] > 0.5):
#					#time.sleep(0.1)
#					self.last_time[id]+=0.5
#				else: return
#				index = int(self.last_time[id]/self.sample_rate)
#				#print 'index: ', index
#				self.endx[id] = index#*self.sample_rate
#				self.endy[id] = index#*self.sample_rate
#				self.endz[id] = index#*self.sample_rate
#				
#						
				#self.runFFT1(id)
				print "update sub frame"
				#if id == self.nodenum:
				id = self.cur_node 
				#self.xrax[self.nodenum] = self.drawData(self.xc[self.nodenum], self.endx[self.cur_node], self.maxx[self.cur_node], self.x_curve[self.cur_node], self.startx[self.cur_node], 'x', 0, self.cur_node)
				#self.xray[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endy[self.cur_node], self.maxy[self.cur_node], self.y_curve[self.cur_node], self.starty[self.cur_node], 'y', 0, self.cur_node)
				#self.xraz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endz[self.cur_node], self.maxz[self.cur_node], self.z_curve[self.cur_node], self.startz[self.cur_node], 'z', 0, self.cur_node)
				#*******************self.xrafx[id] = self.drawData(self.xc[self.nodenum], self.endfx[id], maxx, self.fft_x_curve[id], self.startfy[id], 'x', 0, id)
#				self.xrafy[id] = self.drawData(self.yc[self.nodenum], self.endfy[id], maxy, self.fft_y_curve[id], self.startfy[id], 'y', 0, id)
#				self.xrafz[id] = self.drawData(self.zc[self.nodenum], self.endfz[id], maxz, self.fft_z_curve[id], self.startfz[id], 'z', 0 , id)

			


		# if-else
	# end of updateGraph1
	
	def runFFT1(self, id):
		
		import FFT
#		import FFT
#		if id == self.nodenum:
#			print "enter RunFFT1 inside id == self.nodenum"
#			id = self.cur_node 
#			#self.xrafx[self.nodenum] = self.drawData(self.xc[self.nodenum], self.endx[self.cur_node], self.maxx[self.cur_node], self.x_curve[self.cur_node], self.startx[self.cur_node], 'x', 0, self.cur_node)
#			#self.xrafy[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endy[self.cur_node], self.maxy[self.cur_node], self.y_curve[self.cur_node], self.starty[self.cur_node], 'y', 0, self.cur_node)
#			#self.xrafz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endz[self.cur_node], self.maxz[self.cur_node], self.z_curve[self.cur_node], self.startz[self.cur_node], 'z', 0, self.cur_node)
#			maxx = max(self.fft_x_curve[id])
##			maxy = max(self.fft_y_curve[id])
##			maxz = max(self.fft_z_curve[id])
##	
#			#print "max x %i, max y %i, max z %i"%(maxx,maxy,maxz)
#			#print maxx,maxy,maxz, self.endfx[id], self.endfy[id], self.endfz[id]
#
#			self.xrafx[self.cur_node] = self.drawData(self.yc[self.cur_node], self.endfx[id], maxx, self.fft_x_curve[id], self.startfy[id], 'x', 1, id)
##			self.xrafy[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endfy[id], maxy, self.fft_y_curve[id], self.startfy[id], 'y', 1, id)
##			self.xrafz[self.nodenum] = self.drawData(self.zc[self.nodenum], self.endfz[id], maxz, self.fft_z_curve[id], self.startfz[id], 'z', 1, id)
#	
#		#elif len(self.x_curve[id])> 500:
#		else:
	
		#print "run runFFT1 calculation"
		#print self.startx[id], self.endx[id] 
		
		if (len(self.x_curve[id]) < (1.0/self.sample_rate)+10): 
			self.yc[self.nodenum].delete('x')
			return
		
		self.startf[id] = 1
		def absArray(clist):
			i = 0
			max = 0
			slist = []
			for i in range(1, len(clist)):
				v = abs(clist[i])
				slist.append(v)	
				if v > max: max = v
			return slist, max
		# end of absArray
			
		endx = 	int(self.endx[id])
		startx = int(self.endx[id] - (1/self.sample_rate))-1
		
		#print startx, endx
		#fft_x_curve = FFT.fft(self.x_curve[id][self.startx[id]: self.endx[id]])
		fft_x_curve = FFT.fft(self.x_curve[id][startx: endx])
		
		
		
		self.fft_x_curve[id], self.maxxf[id] = absArray(fft_x_curve)		
		#print self.fft_x_curve[id]
		#print self.fft_x_curve[id], self.maxxf[id] #,absArray(fft_x_curve)
		#print "length of fft_x_curve[id] is " , len(self.fft_x_curve[id])
		#self.fft_x_curve[id], self.maxxf[id] = absArray(fft_x_curve)		
		
		i = 0
		while i/(self.sample_rate*len(self.fft_x_curve[id]))<=1:
			i+=1	
			
		self.startfx[id] = i
		self.startfx[id] = self.startf[id]
#		maxx = 0
#		while i/(self.sample_rate*len(self.fft_x_curve[id]))<=20:
#			if self.fft_x_curve[id][i] >maxx:
#				maxx = self.fft_x_curve[id][i]
#			i+=1
		maxx = max(self.fft_x_curve[id])*2	
		
		#print "print maxxx is ",maxx
		
		self.endfx[id] = i
			
#			fft_y_curve = FFT.fft(self.y_curve[id][self.starty[id]:self.endy[id]])
#			self.fft_y_curve[id], self.maxyf[id] = absArray(fft_y_curve)
#			i = 0
#			while i/(self.sample_rate*len(self.fft_y_curve[id]))<=1:
#				i+=1
#			self.startfy[id] = i
#			maxy = 0
#			while i/(self.sample_rate*len(self.fft_y_curve[id]))<=20:
#				if self.fft_y_curve[id][i] >maxy:
#					maxy = self.fft_y_curve[id][i]
#				i+=1
#			self.endfy[id] = i 
#				
#			fft_z_curve = FFT.fft(self.z_curve[id][self.startz[id]:self.endz[id]])
#			self.fft_z_curve[id], self.maxzf[id] = absArray(fft_z_curve)
#			i = 0
#			while i/(self.sample_rate*len(self.fft_z_curve[id]))<1:
#				i+=1
#			self.startfz[id] = i
#			maxz = 0
#			while i/(self.sample_rate*len(self.fft_z_curve[id]))<=20:
#				if self.fft_z_curve[id][i] >maxz:
#					maxz = self.fft_z_curve[id][i]
#				i+=1
#			self.endfz[id] = i 
		#self.startfz[id] = self.startf[id]
		#self.endz[id] = 1024
		#print 'len', len(fft_z_curve)
	
		#*******************self.xrafx[self.nodenum] = self.drawData(self.yc[self.nodenum], self.endfx[id], maxx, self.fft_x_curve[id], self.startfy[id], 'x', 1, id)
#			self.xrafy[id] = self.drawData(self.yc[id], self.endfy[id], maxy, self.fft_y_curve[id], self.startfy[id], 'y', 1, id)
#			self.xrafz[id] = self.drawData(self.zc[id], self.endfz[id], maxz, self.fft_z_curve[id], self.startfz[id], 'z', 1, id)
#		
		#print "Auto_Scrolling_Time", Auto_Scrolling_Time	
		#print "Sample_rate, self.sample_rate", SAMPLING_RATE, self.sample_rate
		#print "self.Thread_Update_Time", self.Thread_Update_Time 
			
# end of runFFT1

	# this draw three blank graphs (X, Y, Z)
	def drawGrid(self, c, width, height, s, fft):
		c.delete(ALL)
		xmargin = self.xmargin
		ymargin = self.ymargin
		self.cell_xwidth = (width-xmargin)/12
		self.cell_ywidth = height/14
		startx = xmargin
		starty = ymargin + self.cell_ywidth
                
		#if self.fft == 0:
		if fft == 0:
		
			#c.create_text(xmargin+35, self.ymargin - 5, text = "Acceleration (g)", tags = 'gd',fill='white')
			#c.create_text(xmargin+35, self.ymargin - 5, text = "EEG signal", tags = 'gd',fill='white')
			c.create_text(width - 20, height/2-15, text = "Time(s)", tags = 'gd',fill='white')
		else:
			#c.create_text(xmargin+35, self.ymargin - 5, text = "Acceleration (g x sec)", tags = 'gd',fill='white')
			#c.create_text(xmargin+35, self.ymargin - 5, text = "EEG signal", tags = 'gd',fill='white')
			c.create_text(width - 20, height/2-15, text = "Freq(Hz)", tags = 'gd',fill='white')

		# draw grid
		# vertical lines
		i = 0
		while starty <= height - ymargin - self.cell_ywidth:
			g1 = c.create_line(startx, starty, 11 * self.cell_xwidth, starty, fill = 'grey50', tags = 'gd')
			c.lower(g1)
			if i == 5 and self.fft == 0:
				self.center = starty
			starty += self.cell_ywidth
			i = i+1
		starty = starty - self.cell_ywidth 
		if self.fft == 1: self.center = starty
		# Y-axis
		c.create_line(xmargin, ymargin, xmargin, starty, fill = 'white', width = 1, tags = 'gd', arrow = 'first')
		
		# horizontal lines
		while startx < width - xmargin - self.cell_xwidth:
			g2 = c.create_line(startx, ymargin+self.cell_ywidth, startx, starty, fill = 'grey50', tags = 'gd')
			c.lower(g2)
			startx += self.cell_xwidth

		startx = width - xmargin
		# X-axis
		c.create_line(xmargin, self.center, width, self.center, fill = 'white', width = 1, tags = 'gd', arrow = 'last')
		#c.create_line(xmargin, starty, startx, starty, fill = 'black', width = 1, tags = 'gd', arrow = 'last')
 		c.create_text(width/2, height-5, text = s,fill='white')
 		#c.create_text(width/5, height-5, text = s,fill='white')
 
 
		self.ybasef = starty
		self.ybase = self.center

		# draw scroll buttons
		if fft == 0 and s != 'CHANNEL DATA' and s != 'RESERVED':
			forward = c.create_image(width-20, height-10, image = self.play, tags = s+'>')
 			backward = c.create_image(20, height-10, image = self.backplay, tags = s+'<')
		#c.lift(item)
	# end of drawGrid

	# Thread
	#
	# if start button is pressed, this thread is activated.
	# the thread reads data from sensors and plots the data
	#
	#def readData1(self, id):
	def thread_readData(self, id):			# the name was changed by SM. [8/18/05]
		self.file_loaded = 0
		self.x_curve[id] = []
		self.y_curve[id] = []
		self.z_curve[id] = []
		self.start[id]   = 0
		self.maxx[id]    = 0
		self.maxy[id]    = 0
		self.maxz[id]    = 0
		self.lost        = 0

		print 'node id: ', self.serverlist[id]
		self.readData(id)	
	
	def readData(self, id):
		import socket
		import os,struct, time
		#os.system('rm -rf result.txt')
		my_socket = __import__('my_socket')
		#server = '10.0.2.2'
		port   = 10001
		#maxv = 0
	
		self.socketlist[id] = socket.socket(AF_INET, SOCK_DGRAM, 0)
		self.socketlist[id].settimeout(10)
		#self.socketlist[id] = mysocket
		#self.serverlist[id]  = '128.195.174.122'
		#self.serverlist[id]  = '192.168.2.102'
		soc = my_socket.openSocket(0, self.socketlist[id], self.serverlist[id], port)
		print 'Established connection'
		self.socketlist[id].send('1')
		try:
			buf = self.socketlist[id].recv(8)
		except:
			print 'Cannot connect to node!' 
			self.socketlist[id].close()	
			self.readData(id)
			#return
		#t0         = time.time()
		#print buf
		print 'receiving data (id: ', id, ')'
		size = 8*buffersize
		j = 0
		while self.simu:
			if j%40: self.socketlist[id].settimeout(1)
			else: 
				self.socketlist[id].settimeout(10)
				j = 0
			j = j +1
			#self.mysocket.send('1')
                        #read data	
			#print 'start collect data'		
			#buf = self.socketlist[id].recv(size)
			try:
				buf = self.socketlist[id].recv(428)
                	except:
				print 'Cannot receive data from node %d'%id
				self.lost = 1
				self.socketlist[id].close()
				self.readData(id)
				break	
			
			#print len(buf)
			if len(buf)< size:
				print "Error: size mismatch"
				#print len(buf), size
				continue	
			t1  = time.time()
			i = 0
			#timestr = time.ctime(t1)
			#print buf, struct.unpack('B',buf[0])[0]*1
			#print len(buf)
			#print 'x', '%x'%struct.unpack('B', buf[0])[0], '%x'%struct.unpack('B', buf[1])[0]
			#print 'y', '%x'%struct.unpack('B', buf[2])[0], '%x'%struct.unpack('B', buf[3])[0]
			#print 'z', '%x'%struct.unpack('B', buf[4])[0], '%x'%struct.unpack('B', buf[5])[0]
			#print '3', '%x'%struct.unpack('B', buf[6])[0]
			#print '4', '%x'%struct.unpack('B', buf[7])[0]
			#print t1-t0
			#t0 = t1

			if self.log == 1:
				fdlog = open(self.filename[id], 'a')

			for i in range(0, buffersize):
				#print "i", i
				offset = i*8
				xdata = struct.unpack('B', buf[0+offset])[0]*256 + struct.unpack('B', buf[1+offset])[0]
				#ydata = struct.unpack('B', buf[2+offset])[0]*256 + struct.unpack('B', buf[3+offset])[0]
				#print '4', '%x'%struct.unpack('B', buf[4+offset])[0]
				#print '5', '%x'%struct.unpack('B', buf[5+offset])[0]
				z1 = struct.unpack('B', buf[4+offset])[0]*256 + struct.unpack('B', buf[5+offset])[0]
				#z2 = struct.unpack('B', buf[6+offset])[0]*256 + struct.unpack('B', buf[7+offset])[0]
				#print z1
				xdata = float(xdata)*Vscale
				ydata = float(ydata)*Vscale
				if xdata >4.0: xdata = 4.0
				if ydata >4.0: ydata = 4.0
				xdata = xdata-2.0
				#ydata = ydata-2.0	
				#z1 = float(z1)*Vscale
				#z2 = float(z2)*Vscale
				#print zn, zp	
		        	if z1 >4.0: z1 = 4.0
				zdata = (z1 - 2.0)
				
				# compare maximum value
			
				if abs(xdata) > self.maxx[id]: self.maxx[id] = abs(xdata)
				#if abs(ydata) > self.maxy[id]: self.maxy[id] = abs(ydata)
				#if abs(zdata) > self.maxz[id]: self.maxz[id] = abs(zdata)
		
		
				#print "ACK: "+ buf
        			#store data
				#if zdata <=2.0 and zdata >= 0:
				t_sampling = t1-self.t0
				self.timelist[id].append(t_sampling)
				#self.x_curve[id].append(xdata-self.xoffset)
				#self.y_curve[id].append(ydata-self.yoffset)
				#self.z_curve[id].append(zdata-self.zoffset)	
				self.x_curve[id].append(xdata)
				#self.y_curve[id].append(ydata)
				self.lost = 0
				#self.z_curve[id].append(zdata)
				
				if self.log == 1:
					#fdlog = open(self.filename[id], 'a')
					sampling_time = '%.3f'%t_sampling
					x = '%4.3f'%xdata
					y = '%4.3f'%ydata
					z = '%4.3f'%zdata

					fdlog.write(str(sampling_time) + ','+
                               str(x)+','+str(y)+','+str(z)+'\n')
				# if
			# for
			if self.log == 1:
				fdlog.close()			


			#print i, time.time()-t1
			i = i+1
			cur_item = self.nodelist[id]['node']
			self.c.itemconfigure(cur_item,  fill = self.C.read_color)
		# end of while
		self.socketlist[id].close()
	# end of readData

				
	#def drawData(self, canvas, maxx, maxY, curves, index_start, item, mode, id):
	def drawData(self, canvas, maxx, curves, index_start, item, mode, id):
		canvas.delete(item)
		if self.fft == 0:
			ybase = self.ybase
			ygrid = 5
		else:
			ybase = self.ybasef
			ygrid = 10
		xgrid = 10 
	
		if item == 'x': 
			color = x_color
			#dvi   = self.xoffset[id]
			maxy = self.graphXMaxOnY[id]
			miny = self.graphXMinOnY[id]
			center = (miny + maxy) / 2
		elif item == 'y': 
			color = y_color
			#dvi   = self.yoffset[id]
			maxy = self.graphYMaxOnY[id]
			miny = self.graphYMinOnY[id]
			center = (miny + maxy) / 2
		else:		# item == 'z'
			color = z_color
			#dvi   = self.zoffset[id]
			maxy = self.graphZMaxOnY[id]
			miny = self.graphZMinOnY[id]
			center = (miny + maxy) / 2
		xbase = self.xmargin
		
		if self.fft == 0:
			#print "vahid -1"
			timeRange = maxx - index_start		# X-axis
		else:
			#print "vahid 0"
			timeRange = int(1.0/(self.sample_rate)/Time_Range_Shift)
			#timeRange = int(1.0/(self.sample_rate))
				
		width = self.width - 2 * self.xmargin	# remove left and right margins ??

		if self.fft == 0 and self.zoom == 0:
			#print "vahid1"
			#sampleRange = MAX_TIME
			sampleRange = self.rangeOnX
			# this function doesn't draw all the points in curves[].
			# the following step is index distance between two points on the curve
			#step =int(0.5 + float(sampleRange)/width/self.sample_rate) # adding 0.5 means round
			step = int(round(float(sampleRange)/width/self.sample_rate))
			#print 'step in drawData: ', step
			if self.start_time[id]!= self.prev_time[id] or self.lost:
				#print "vahid 1.5"
				self.step = step				# self.step is only used in drawData
				#print 'self.step is used'
				self.prev_time[id] = self.start_time[id]
		else:
			#print "vahid2"
			#dvi = 0
			center = 0
			#sampleRange = int(timeRange * self.sample_rate / 2) * 2			# even number
			#print self.scrollunit,timeRange, self.sample_rate
			#self.scrollunit = float(timeRange * self.sample_rate / 2)
			
			sampleRange = 2 * self.scrollunit
			sample_rate = self.sample_rate
			step = 1+sampleRange/width
			#print 'step in drawData: ', step

		if self.fft == 1: 
			#print "vahid3"
			maxy = float(int(maxY/5)*5+5)
		#yratio = (ygrid*self.cell_ywidth)/(maxy)
		yratio = (ygrid*self.cell_ywidth)/((maxy - miny) / 2)

		# put numbers on X-axis
		if self.fft==0:
			#print "vahid4"
			#grid = int(sampleRange/xgrid)
			grid = float(sampleRange)/float(xgrid)
			#xra = xgrid * self.cell_xwidth / sampleRange
			xra = xgrid * self.cell_xwidth / sampleRange * self.sample_rate
			
		else:
			#print "vahid5"
			fstart = index_start/(self.sample_rate*len(curves))
			fRange = self.rangeOnX/xgrid
			grid   = float((maxx-index_start)/xgrid)
			#print "xgrid, self.cell_xwidth, sampleRange",xgrid, self.cell_xwidth, sampleRange
			#xra = xgrid * self.cell_xwidth / sampleRange /FFT_Shift_Ratio * ( self.sample_rate / 0.005)
			xra = xgrid * self.cell_xwidth /sampleRange / FFT_Shift_Ratio * ( self.sample_rate / 0.005)
			
			#print "( self.sample_rate / 0.005), xra",(self.sample_rate / 0.005),xra
		
			if grid ==0: 
				#print "vahid6"
				gird = int(maxx-index_start)
	
		#print "maxx %f, maxy %f" %(maxx, maxy)
		
		
		#----------draw scale unit -------------------#
		# modified by SM
		# 8/19/05
		# draw x axis
		#if self.fft == 1:
		#	print 'index_start and grid', index_start, grid
					
		
		
		for i in range(0, xgrid+1):
			x = xbase + i * self.cell_xwidth
			if self.fft == 0:
				if self.zoom == 1:
					#print "vahid7"
					#print index_start, grid
					#s = str(int((i*grid+index_start)*self.sample_rate))
					#s = '%4.1f'%(i*grid+index_start*self.sample_rate)
					
					#if self.maxtime < 10:
					if self.rangeOnX < 10:
					
						s = str(float(i*grid+index_start*self.sample_rate))
					else:
						s = str(int(i*grid+index_start*self.sample_rate))
					
					print i,s
				else:
					#print "vahid8"
					#s = str(int(i*grid) + self.start_time[id])
					#print 'self.st[id] == ',self.st[id]
					#print 'self.start_time[id] == ',self.start_time[id]
					self.start_time[id] = self.st[id]
					#s = str(int(i*grid) + self.start_time[id])
					#s = '%4.1f'%(i*grid + self.start_time[id])
					
					
					#if self.maxtime < 10:
					if self.rangeOnX < 10:
						#print "vahid8.1"
						#s = str(float(i*grid + self.start_time[id]+(self.flush_time/self.nodenum)*self.List_Reset_Time))
						s = str(float(i*grid + self.start_time[id]+self.flush_time*self.List_Reset_Time))
					
					else:	
						#s = str(int(i*grid + self.start_time[id]+(self.flush_time/self.nodenum)*self.List_Reset_Time))
						s = str(int(i*grid + self.start_time[id]+self.flush_time*self.List_Reset_Time))
				
			else:
				#print "vahid9"
				#print "draw scale unit for FFT"
				#print "length of curve is ", len(curves)
				#print fRange , fstart
				fRange = 10
				s = '%4.0f'%(i*fRange+fstart)
				s = str(s)
				#print s
				#x = arange(0,100,10)
				#s = str(x)
				#print s
			#canvas.create_text(x, self.ybasef+10, {"text": s}, tags = item, fill='RED')
			#print s
			
			#create text number on the screen
			#canvas.create_text(x, self.ybasef+10, {"text": s}, tags = item, fill='WHITE')   
			#######canvas.create_text(x, self.ybasef+10, {"text": s}, tags = item, fill='White',font = self.C.font4)
			
			#print 'string: ', s
		# put numbers on Y-axis
		#grid = getGrid(maxy, self.scale, ygrid)
		#grid = maxy/ygrid
		grid = ((maxy - miny) / 2) / ygrid
		#starti = 1
		if self.fft == 1:
			#print "vahid9.5"
			starti = 1
			steprange = ygrid -1
			#print "length of curve is ", len(curves)
		else:
			#print "vahid10"
			starti = -ygrid
			#steprange = -starti
			steprange = ygrid
			#print 'add curve point'
		#print steprange
		# modified by SM
		# 8/19/05
		#for i in range(starti, ygrid+1):
		#	y = ybase - i*self.cell_ywidth
		#	if self.fft == 0: 
		#		s = '%3.2f'%(i*grid+dvi)
		#	else:
		#		s = '%3.1f'%(i*grid+dvi)
		#	canvas.create_text(self.xmargin-13, y, {"text": str(s)}, tags = item,fill='white')
		#  draw y axis
		
		for i in range(starti, ygrid+1):
			y = ybase - i * self.cell_ywidth
			#print "starti %i, ygrid %i"%(starti, ygrid)
			if self.fft == 0: 
				#print "vahid10.1"
				#s = '%3.2f'%(center + i*grid)
				s = str(float(center + i*grid))
			else:
				#print "vahid10.2"
				#s = '%3.1f'%(i*grid+dvi)
				s = '%3.1f'%(center + i*grid)
			#######canvas.create_text(self.xmargin-13, y, {"text": str(s)}, tags = item,fill='white')

		# ??
		if timeRange <= xgrid:
			#print "vahid10.3"
			#print 'When is this condition true?'
			return

		#-------------draw curve----------------------#
		# 10/02/05 Modified by ChongJing to reduce CPU load 
		
		#print "print curvpoints"
		
		curvpoints = []
		i = 0
		#if ( canvas == self.xc[self.nodenum]) or ( canvas == self.yc[self.nodenum]) or ( canvas == self.zc[self.nodenum]):
		#	self.step = self.high_resolution
			
		#else:
		self.step = self.low_resolution
			
		#step = 6
		#self.step = 5
		#avg = (maxy+miny)/2.0
		
		#11/11/2005 Add by ChongJing to do list flush functionality 
		#xbase = xbase + self.flush_time * self.List_Reset_Time
		#print xbase
		
		#if self.fft == 1:
		#	print 'sampleRange', sampleRange
		#	print 'xra and xbase', xra, xbase
				
		#print "ybase: ", ybase   #35
		#print "yratio: ", yratio #21.5
		#print "center: ", center #0
		#print "index_start: ", index_start
		
		#print "timeRange: ", timeRange
		while i < timeRange:
			if self.fft == 1 or self.zoom == 1:
				#print 'i, xra and xbase', i, xra, xbase
				curvpoints.append(i*xra + xbase)
				#print "vahid10.4"
			else:
				#curvpoints.append(i*xra*self.sample_rate + xbase)
				#print "vahid10.5"
				curvpoints.append(i*xra + xbase)
			
			try:
				#curvpoints.append(ybase - int((curves[index_start+i]-dvi)*yratio))
				curvpoints.append(ybase - int((curves[index_start+i]-center)*yratio))
				#print "vahid10.6"
			except:
				#print "vahid10.7"
				pass

			if self.fft == 0:
				#print "vahid10.8"
				i = i + self.step
				#print self.step
			else:
				#print "vahid10.9"
				i = i + 1
				#print "stepping inside FFT"
				#print 'length of line is', len(curvpoints)
				#print step
#	 	
#	 	if self.fft == 1:
#			print "stepping inside FFT"
#			print 'length of curvpoints is, length of curves is ', len(curvpoints),len(curves)
#			print "time range is ", timeRange	 
#			#print curvpoints		
	 	
	 	#For multi-threading debugging issue
	 	#if id ==0: 
	 		#print curvpoints
	 		#print len(curvpoints), index_start
		
		
		if len(curvpoints) < 4: 
			#print "vahid11"
			return
		#print 'Curve length is ', len(curvpoints)
		try:
			#print curvpoints
			canvas.create_line(curvpoints, fill = color, tags = item)
			#print "vahid12"
			#self._lock2.release()
		except:
			#print "vahid13"
			pass
			
			
		#self._lock2.release()
		#print "release lock2"
		
		return xra
		

	# end of drawData



#---------------------------end of class MainWidget ---------------------------#
#
xoffset = 0
yoffset = 0
width = 750
height = 600
root = Tk()
root.option_add('*font', ('Helvetica', 12,'bold'))
all = MainWidget(root, width, height)
root.resizable('false', 'false')
root.title('Duranode Network')
root.mainloop()
i                                                                                       