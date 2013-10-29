;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Fri Nov 19 17:26:14 2010
;--------------------------------------------------------
	.module usb_standard_desc
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _g_usb_string_desc
	.globl _g_usb_string_desc_2
	.globl _g_usb_string_desc_1
	.globl _g_usb_conf_desc
	.globl _g_usb_dev_desc
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (DATA)
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (DATA)
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
	.area CSEG    (CODE)
	.area CONST   (CODE)
_g_usb_dev_desc:
	.db #0x12
	.db #0x01
	.byte #0x00,#0x02
	.db #0x00
	.db #0x00
	.db #0x00
	.db #0x20
	.byte #0x15,#0x19
	.byte #0x77,#0x56
	.byte #0x00,#0x01
	.db #0x01
	.db #0x02
	.db #0x00
	.db #0x01
_g_usb_conf_desc:
	.db #0x09
	.db #0x02
	.byte #0x20,#0x00
	.db #0x01
	.db #0x01
	.db #0x00
	.db #0xA0
	.db #0x32
	.db #0x09
	.db #0x04
	.db #0x00
	.db #0x00
	.db #0x02
	.db #0xFF
	.db #0x01
	.db #0x00
	.db #0x00
	.db #0x07
	.db #0x05
	.db #0x81
	.db #0x02
	.byte #0x40,#0x00
	.db #0x00
	.db #0x07
	.db #0x05
	.db #0x01
	.db #0x02
	.byte #0x40,#0x00
	.db #0x00
_g_usb_string_desc_1:
	.db #0x2A
	.db #0x03
	.db #0x4E
	.db #0x00
	.db #0x6F
	.db #0x00
	.db #0x72
	.db #0x00
	.db #0x64
	.db #0x00
	.db #0x69
	.db #0x00
	.db #0x63
	.db #0x00
	.db #0x20
	.db #0x00
	.db #0x53
	.db #0x00
	.db #0x65
	.db #0x00
	.db #0x6D
	.db #0x00
	.db #0x69
	.db #0x00
	.db #0x63
	.db #0x00
	.db #0x6F
	.db #0x00
	.db #0x6E
	.db #0x00
	.db #0x64
	.db #0x00
	.db #0x75
	.db #0x00
	.db #0x63
	.db #0x00
	.db #0x74
	.db #0x00
	.db #0x6F
	.db #0x00
	.db #0x72
	.db #0x00
_g_usb_string_desc_2:
	.db #0x1A
	.db #0x03
	.db #0x45
	.db #0x00
	.db #0x63
	.db #0x00
	.db #0x6F
	.db #0x00
	.db #0x20
	.db #0x00
	.db #0x55
	.db #0x00
	.db #0x70
	.db #0x00
	.db #0x6C
	.db #0x00
	.db #0x6F
	.db #0x00
	.db #0x61
	.db #0x00
	.db #0x64
	.db #0x00
	.db #0x65
	.db #0x00
	.db #0x72
	.db #0x00
_g_usb_string_desc:
	.byte _g_usb_string_desc_1,(_g_usb_string_desc_1 >> 8),#0x80
	.byte _g_usb_string_desc_2,(_g_usb_string_desc_2 >> 8),#0x80
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
