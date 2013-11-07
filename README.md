install all x86 version instead of amd64
7-zip x64 needs to be installed
1. python27
    (add C:\Python27;C:\Python27\Scripts;C:\Python27\DLLs into Path)
2. setuptools
3. pip
4. scipy
5. numpy
6. matplotlib
7. install following packages using pip
    libusb1
    pyparsing
    python-dateutil
8 install manually
    pygubu  https://github.com/alejandroautalan/pygubu/archive/v0.9.1.zip
    python setup.py install
10. usb driver
       libusbK  http://sourceforge.net/projects/libusbk/
       download libusbK-RELEASE-setup.exe
       install, in C:\libusbK-dev-kit, run inf-wizard to generate usb driver
       (select WinUSB for libusb1 support)
       this will generate a USB driver installer, install the USB driver to be recognized by windows 7
11. since there's no libusb-1.0.dll installed for libusb1 to be loaded by types
      download https://github.com/libusbx/libusbx/archive/v1.0.17.zip
      copy MS32/dll/libusb-1.0.dll into C:\Python27\DLLs

