"""
2010.8.3 (onetail) : modify EPL_USB constructor and add variable self.isConnect
"""
import os
import usb1
import sys
import binascii

class DeviceDescriptor(object) :
    def __init__(self, vendor_id, product_id, interface_id) :
        self.vendor_id = vendor_id
        self.product_id = product_id
        self.interface_id = interface_id

    def getDevice(self) :
        """
        Return the device corresponding to the device descriptor if it is
        available on a USB bus.  Otherwise, return None.  Note that the
        returned device has yet to be claimed or opened.
        """
        buses = usb.busses()
        for bus in buses :
	    print "bus length = %d" % len(bus.devices)
	    print "Devices = ",
            print bus.devices
            for device in bus.devices :
                print "Device VID = %0X" % device.idVendor
                print "Device PID = %0X" % device.idProduct
                if device.idVendor == self.vendor_id :
                    if device.idProduct == self.product_id :
			return device
        return None

    def getDevices(self) :
        """
        Return the device corresponding to the device descriptor if it is
        available on a USB bus.  Otherwise, return None.  Note that the
        returned device has yet to be claimed or opened.
        """
        self.devices = []
        buses = usb.busses()
        for bus in buses :
	    #print "bus length = %d" % len(bus.devices)
	    #print "Devices = ",
            #print bus.devices
            for device in bus.devices :
                #print "Device VID = %0X" % device.idVendor
                #print "Device PID = %0X" % device.idProduct
                if device.idVendor == self.vendor_id and device.idProduct == self.product_id:
                    self.devices.append(device)

        return self.devices


class PlugUSBDevice_old(object) :

    PLUG_VENDOR_ID = 0x1915
    PLUG_PRODUCT_ID = 0x5677
    PLUG_INTERFACE_ID = 0
    PLUG_BULK_IN_EP = 0x81
    PLUG_BULK_OUT_EP = 0x01

    def __init__(self) :
		self.device_descriptor = DeviceDescriptor(PlugUSBDevice.PLUG_VENDOR_ID,
                                                  PlugUSBDevice.PLUG_PRODUCT_ID,
                                                  PlugUSBDevice.PLUG_INTERFACE_ID)

		self.devices = self.device_descriptor.getDevices()
		self.handle = None
		self.device = None

    def open(self) :
        #self.device = self.device_descriptor.getDevice()
	#print self.devices
	for self.device in self.devices:
	    self.handle = self.device.open()


	    if os.name != 'posix' :
		self.handle.setConfiguration(1)
			    #print "a"
	    else :
		self.handle.reset()
			    #print "b"

	    try:
		self.handle.claimInterface(self.device_descriptor.interface_id)
		return
	    except:
		pass

    def close(self) :
        #print "release usb interface"
        self.handle.releaseInterface()

    def getDataPacket(self, nbytesToGet):
        return self.handle.bulkRead(PlugUSBDevice.PLUG_BULK_IN_EP,nbytesToGet,2500)

    def putDataPacket(self, dataToPut):
        return self.handle.bulkWrite(PlugUSBDevice.PLUG_BULK_OUT_EP,dataToPut,-1)

class PlugUSBDevice(object):
    PLUG_VENDOR_ID = 0x1915
    PLUG_PRODUCT_ID = 0x5677

    PLUG_CONFIGURATION = 1
    PLUG_INTERFACE_ID = 0
    PLUG_BULK_IN_EP = 0x81
    PLUG_BULK_OUT_EP = 0x01

    def __init__(self):
        self.device = None
        self.handle = None
        try:
            self.context = usb1.USBContext()
        except:
            print "Could not create extra USB context"
            return None

        self.device = self.context.getByVendorIDAndProductID(PlugUSBDevice.PLUG_VENDOR_ID, PlugUSBDevice.PLUG_PRODUCT_ID, skip_on_error=True)

    def open(self):
        if not self.device:
            print "No USB device has been choosen"
            return

        try:
            self.handle = self.device.open()
        except:
            print "open USB device failed"
            return

        try:
            self.handle.resetDevice()

            # claim configuration and interface
            self.handle.setConfiguration(PlugUSBDevice.PLUG_CONFIGURATION)
            self.handle.claimInterface(PlugUSBDevice.PLUG_INTERFACE_ID)
        except Exception as e:
            print e

        return

    def close(self):
        try:
#            self.handle.releaseInterface(PlugUSBDevice.PLUG_INTERFACE_ID)
            self.handle.close()
            self.context.exit()
        except Exception as e:
            print e
            print "USB Device close error"

    def getDataPacket(self, nbytesToGet):
        return self.handle.bulkRead(PlugUSBDevice.PLUG_BULK_IN_EP, nbytesToGet, 2500)

    def putDataPacket(self, dataToPut):
        return self.handle.bulkWrite(PlugUSBDevice.PLUG_BULK_OUT_EP, dataToPut, timeout=-1)


class EPL_USB:
    def __init__ (self):
        self.usb = PlugUSBDevice()
        self.isConnected = False
        if self.usb.device == None:
            print "USB Device Not Found"
            return None
        else:
            self.isConnected = True
            self.usb.open()
            print "USB Device Connected"

    #close connection
    def close (self):
        if self.isConnected:
            print "USB closed"
            self.usb.close()
        self.isConnected = False

    #send cmd
    def sendCmd(self,cmd):
        if self.isConnected:
            bdata = binascii.unhexlify(cmd)
            self.usb.putDataPacket(bdata)

    #send cmd
    def sendData(self,data):
        if self.isConnected:
            self.usb.putDataPacket(data)

    #convert tuple to string
    def t2s(self,v):
        z = ""
        for item in v:
            z += chr(item)
        return z

    def recvCmd(self,nbytesToGet):
        if self.isConnected:
            return self.usb.getDataPacket(nbytesToGet)

if __name__ == "__main__":
    dongle = EPL_USB()
    if dongle:
        dongle.close()
