                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Fri Nov 19 17:26:13 2010
                              5 ;--------------------------------------------------------
                              6 	.module usb_api
                              7 	.optsdcc -mmcs51 --model-large
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _DECR
                             13 	.globl _GO
                             14 	.globl _BD
                             15 	.globl _RFCKEN
                             16 	.globl _RFCSN
                             17 	.globl _RFCE
                             18 	.globl _P05
                             19 	.globl _P04
                             20 	.globl _SCSN
                             21 	.globl _MCSN
                             22 	.globl _P03
                             23 	.globl _P02
                             24 	.globl _P01
                             25 	.globl _P00
                             26 	.globl _IV0
                             27 	.globl _IV1
                             28 	.globl _IV2
                             29 	.globl _IV3
                             30 	.globl _IV4
                             31 	.globl _SUSPEND
                             32 	.globl _WU
                             33 	.globl _SWRST
                             34 	.globl _RFSPIF
                             35 	.globl _RFF
                             36 	.globl _SPIF
                             37 	.globl _USBWUF
                             38 	.globl _USBF
                             39 	.globl _WUF
                             40 	.globl _TF2
                             41 	.globl _EXF2
                             42 	.globl _RFSPI
                             43 	.globl _RF
                             44 	.globl _SPI
                             45 	.globl _USBWU
                             46 	.globl _USB
                             47 	.globl _WUIRQ
                             48 	.globl _EXEN2
                             49 	.globl _EX0
                             50 	.globl _ET0
                             51 	.globl _EX1
                             52 	.globl _ET1
                             53 	.globl _ES0
                             54 	.globl _ET2
                             55 	.globl _EA
                             56 	.globl _T2I0
                             57 	.globl _T2I1
                             58 	.globl _T2CM
                             59 	.globl _T2R0
                             60 	.globl _T2R1
                             61 	.globl _I2FR
                             62 	.globl _I3FR
                             63 	.globl _T2PS
                             64 	.globl _RI0
                             65 	.globl _TI0
                             66 	.globl _RB80
                             67 	.globl _TB80
                             68 	.globl _REN0
                             69 	.globl _SM20
                             70 	.globl _SM1
                             71 	.globl _SM0
                             72 	.globl _IT0
                             73 	.globl _IE0
                             74 	.globl _IT1
                             75 	.globl _IE1
                             76 	.globl _TR0
                             77 	.globl _TF0
                             78 	.globl _TR1
                             79 	.globl _TF1
                             80 	.globl _P
                             81 	.globl _F1
                             82 	.globl _OV
                             83 	.globl _RS0
                             84 	.globl _RS1
                             85 	.globl _F0
                             86 	.globl _AC
                             87 	.globl _CY
                             88 	.globl _WPEN
                             89 	.globl _RDEND
                             90 	.globl _RDIS
                             91 	.globl _INFEN
                             92 	.globl _RDYN
                             93 	.globl _WEN
                             94 	.globl _STP
                             95 	.globl _MCDIS
                             96 	.globl _T2
                             97 	.globl _CRC
                             98 	.globl _CC3
                             99 	.globl _CC2
                            100 	.globl _CC1
                            101 	.globl _FCR
                            102 	.globl _FPCR
                            103 	.globl _FSR
                            104 	.globl _AESIA2
                            105 	.globl _AESIA1
                            106 	.globl _AESD
                            107 	.globl _AESIV
                            108 	.globl _AESKIN
                            109 	.globl _B
                            110 	.globl _ARCON
                            111 	.globl _MD5
                            112 	.globl _MD4
                            113 	.globl _MD3
                            114 	.globl _MD2
                            115 	.globl _MD1
                            116 	.globl _MD0
                            117 	.globl _AESCS
                            118 	.globl _RFCTL
                            119 	.globl _RFDAT
                            120 	.globl _ACC
                            121 	.globl _USBSLP
                            122 	.globl _WDCON
                            123 	.globl _PSW
                            124 	.globl _TH2
                            125 	.globl _TL2
                            126 	.globl _CRCH
                            127 	.globl _CRCL
                            128 	.globl _P0EXP
                            129 	.globl _T2CON
                            130 	.globl _CCH3
                            131 	.globl _CCL3
                            132 	.globl _CCH2
                            133 	.globl _CCL2
                            134 	.globl _CCH1
                            135 	.globl _CCL1
                            136 	.globl _CCEN
                            137 	.globl _IRCON
                            138 	.globl _SSSTAT
                            139 	.globl _SSDATA
                            140 	.globl _SSCONF
                            141 	.globl _S0RELH
                            142 	.globl _IP1
                            143 	.globl _IEN1
                            144 	.globl _TICKDV
                            145 	.globl _SMCTL
                            146 	.globl _SMDAT
                            147 	.globl _RSTRES
                            148 	.globl _REGXC
                            149 	.globl _REGXL
                            150 	.globl _REGXH
                            151 	.globl _S0RELL
                            152 	.globl _IP0
                            153 	.globl _IEN0
                            154 	.globl _INTEXP
                            155 	.globl _WUCONF
                            156 	.globl _PWRDWN
                            157 	.globl _CLKCTL
                            158 	.globl _USBCON
                            159 	.globl _IEN2
                            160 	.globl _S0BUF
                            161 	.globl _S0CON
                            162 	.globl _P0ALT
                            163 	.globl _P0DIR
                            164 	.globl _DPS
                            165 	.globl _RFCON
                            166 	.globl _CKCON
                            167 	.globl _TH1
                            168 	.globl _TH0
                            169 	.globl _TL1
                            170 	.globl _TL0
                            171 	.globl _TMOD
                            172 	.globl _TCON
                            173 	.globl _PCON
                            174 	.globl _DPH1
                            175 	.globl _DPL1
                            176 	.globl _DPH
                            177 	.globl _DPL
                            178 	.globl _SP
                            179 	.globl _P0
                            180 	.globl _usb_send_packet_PARM_2
                            181 	.globl _usb_state
                            182 	.globl _ep1_receive
                            183 	.globl _ep1_sent
                            184 	.globl _usb_init
                            185 	.globl _usb_wakeup
                            186 	.globl _usb_get_state
                            187 	.globl _usb_wait_for_configuration
                            188 	.globl _usb_send_packet
                            189 	.globl _usb_recv_packet
                            190 ;--------------------------------------------------------
                            191 ; special function registers
                            192 ;--------------------------------------------------------
                            193 	.area RSEG    (DATA)
                    0080    194 _P0	=	0x0080
                    0081    195 _SP	=	0x0081
                    0082    196 _DPL	=	0x0082
                    0083    197 _DPH	=	0x0083
                    0084    198 _DPL1	=	0x0084
                    0085    199 _DPH1	=	0x0085
                    0087    200 _PCON	=	0x0087
                    0088    201 _TCON	=	0x0088
                    0089    202 _TMOD	=	0x0089
                    008A    203 _TL0	=	0x008a
                    008B    204 _TL1	=	0x008b
                    008C    205 _TH0	=	0x008c
                    008D    206 _TH1	=	0x008d
                    008E    207 _CKCON	=	0x008e
                    0090    208 _RFCON	=	0x0090
                    0092    209 _DPS	=	0x0092
                    0094    210 _P0DIR	=	0x0094
                    0095    211 _P0ALT	=	0x0095
                    0098    212 _S0CON	=	0x0098
                    0099    213 _S0BUF	=	0x0099
                    009A    214 _IEN2	=	0x009a
                    00A0    215 _USBCON	=	0x00a0
                    00A3    216 _CLKCTL	=	0x00a3
                    00A4    217 _PWRDWN	=	0x00a4
                    00A5    218 _WUCONF	=	0x00a5
                    00A6    219 _INTEXP	=	0x00a6
                    00A8    220 _IEN0	=	0x00a8
                    00A9    221 _IP0	=	0x00a9
                    00AA    222 _S0RELL	=	0x00aa
                    00AB    223 _REGXH	=	0x00ab
                    00AC    224 _REGXL	=	0x00ac
                    00AD    225 _REGXC	=	0x00ad
                    00B1    226 _RSTRES	=	0x00b1
                    00B2    227 _SMDAT	=	0x00b2
                    00B3    228 _SMCTL	=	0x00b3
                    00B5    229 _TICKDV	=	0x00b5
                    00B8    230 _IEN1	=	0x00b8
                    00B9    231 _IP1	=	0x00b9
                    00BA    232 _S0RELH	=	0x00ba
                    00BC    233 _SSCONF	=	0x00bc
                    00BD    234 _SSDATA	=	0x00bd
                    00BE    235 _SSSTAT	=	0x00be
                    00C0    236 _IRCON	=	0x00c0
                    00C1    237 _CCEN	=	0x00c1
                    00C2    238 _CCL1	=	0x00c2
                    00C3    239 _CCH1	=	0x00c3
                    00C4    240 _CCL2	=	0x00c4
                    00C5    241 _CCH2	=	0x00c5
                    00C6    242 _CCL3	=	0x00c6
                    00C7    243 _CCH3	=	0x00c7
                    00C8    244 _T2CON	=	0x00c8
                    00C9    245 _P0EXP	=	0x00c9
                    00CA    246 _CRCL	=	0x00ca
                    00CB    247 _CRCH	=	0x00cb
                    00CC    248 _TL2	=	0x00cc
                    00CD    249 _TH2	=	0x00cd
                    00D0    250 _PSW	=	0x00d0
                    00D8    251 _WDCON	=	0x00d8
                    00D9    252 _USBSLP	=	0x00d9
                    00E0    253 _ACC	=	0x00e0
                    00E5    254 _RFDAT	=	0x00e5
                    00E6    255 _RFCTL	=	0x00e6
                    00E8    256 _AESCS	=	0x00e8
                    00E9    257 _MD0	=	0x00e9
                    00EA    258 _MD1	=	0x00ea
                    00EB    259 _MD2	=	0x00eb
                    00EC    260 _MD3	=	0x00ec
                    00ED    261 _MD4	=	0x00ed
                    00EE    262 _MD5	=	0x00ee
                    00EF    263 _ARCON	=	0x00ef
                    00F0    264 _B	=	0x00f0
                    00F1    265 _AESKIN	=	0x00f1
                    00F2    266 _AESIV	=	0x00f2
                    00F3    267 _AESD	=	0x00f3
                    00F5    268 _AESIA1	=	0x00f5
                    00F6    269 _AESIA2	=	0x00f6
                    00F8    270 _FSR	=	0x00f8
                    00F9    271 _FPCR	=	0x00f9
                    00FA    272 _FCR	=	0x00fa
                    FFFFC3C2    273 _CC1	=	0xffffc3c2
                    FFFFC5C4    274 _CC2	=	0xffffc5c4
                    FFFFC7C6    275 _CC3	=	0xffffc7c6
                    FFFFCBCA    276 _CRC	=	0xffffcbca
                    FFFFCDCC    277 _T2	=	0xffffcdcc
                            278 ;--------------------------------------------------------
                            279 ; special function bits
                            280 ;--------------------------------------------------------
                            281 	.area RSEG    (DATA)
                    00FF    282 _MCDIS	=	0x00ff
                    00FE    283 _STP	=	0x00fe
                    00FD    284 _WEN	=	0x00fd
                    00FC    285 _RDYN	=	0x00fc
                    00FB    286 _INFEN	=	0x00fb
                    00FA    287 _RDIS	=	0x00fa
                    00F9    288 _RDEND	=	0x00f9
                    00F8    289 _WPEN	=	0x00f8
                    00D7    290 _CY	=	0x00d7
                    00D6    291 _AC	=	0x00d6
                    00D5    292 _F0	=	0x00d5
                    00D4    293 _RS1	=	0x00d4
                    00D3    294 _RS0	=	0x00d3
                    00D2    295 _OV	=	0x00d2
                    00D1    296 _F1	=	0x00d1
                    00D0    297 _P	=	0x00d0
                    008F    298 _TF1	=	0x008f
                    008E    299 _TR1	=	0x008e
                    008D    300 _TF0	=	0x008d
                    008C    301 _TR0	=	0x008c
                    008B    302 _IE1	=	0x008b
                    008A    303 _IT1	=	0x008a
                    0089    304 _IE0	=	0x0089
                    0088    305 _IT0	=	0x0088
                    009F    306 _SM0	=	0x009f
                    009E    307 _SM1	=	0x009e
                    009D    308 _SM20	=	0x009d
                    009C    309 _REN0	=	0x009c
                    009B    310 _TB80	=	0x009b
                    009A    311 _RB80	=	0x009a
                    0099    312 _TI0	=	0x0099
                    0098    313 _RI0	=	0x0098
                    00CF    314 _T2PS	=	0x00cf
                    00CE    315 _I3FR	=	0x00ce
                    00CD    316 _I2FR	=	0x00cd
                    00CC    317 _T2R1	=	0x00cc
                    00CB    318 _T2R0	=	0x00cb
                    00CA    319 _T2CM	=	0x00ca
                    00C9    320 _T2I1	=	0x00c9
                    00C8    321 _T2I0	=	0x00c8
                    00AF    322 _EA	=	0x00af
                    00AD    323 _ET2	=	0x00ad
                    00AC    324 _ES0	=	0x00ac
                    00AB    325 _ET1	=	0x00ab
                    00AA    326 _EX1	=	0x00aa
                    00A9    327 _ET0	=	0x00a9
                    00A8    328 _EX0	=	0x00a8
                    00BF    329 _EXEN2	=	0x00bf
                    00BD    330 _WUIRQ	=	0x00bd
                    00BC    331 _USB	=	0x00bc
                    00BB    332 _USBWU	=	0x00bb
                    00BA    333 _SPI	=	0x00ba
                    00B9    334 _RF	=	0x00b9
                    00B8    335 _RFSPI	=	0x00b8
                    00C7    336 _EXF2	=	0x00c7
                    00C6    337 _TF2	=	0x00c6
                    00C5    338 _WUF	=	0x00c5
                    00C4    339 _USBF	=	0x00c4
                    00C3    340 _USBWUF	=	0x00c3
                    00C2    341 _SPIF	=	0x00c2
                    00C1    342 _RFF	=	0x00c1
                    00C0    343 _RFSPIF	=	0x00c0
                    00A7    344 _SWRST	=	0x00a7
                    00A6    345 _WU	=	0x00a6
                    00A5    346 _SUSPEND	=	0x00a5
                    00A4    347 _IV4	=	0x00a4
                    00A3    348 _IV3	=	0x00a3
                    00A2    349 _IV2	=	0x00a2
                    00A1    350 _IV1	=	0x00a1
                    00A0    351 _IV0	=	0x00a0
                    0080    352 _P00	=	0x0080
                    0081    353 _P01	=	0x0081
                    0082    354 _P02	=	0x0082
                    0083    355 _P03	=	0x0083
                    0083    356 _MCSN	=	0x0083
                    0083    357 _SCSN	=	0x0083
                    0084    358 _P04	=	0x0084
                    0085    359 _P05	=	0x0085
                    0090    360 _RFCE	=	0x0090
                    0091    361 _RFCSN	=	0x0091
                    0092    362 _RFCKEN	=	0x0092
                    00DF    363 _BD	=	0x00df
                    00E8    364 _GO	=	0x00e8
                    00E9    365 _DECR	=	0x00e9
                            366 ;--------------------------------------------------------
                            367 ; overlayable register banks
                            368 ;--------------------------------------------------------
                            369 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     370 	.ds 8
                            371 ;--------------------------------------------------------
                            372 ; internal ram data
                            373 ;--------------------------------------------------------
                            374 	.area DSEG    (DATA)
                            375 ;--------------------------------------------------------
                            376 ; overlayable items in internal ram 
                            377 ;--------------------------------------------------------
                            378 	.area OSEG    (OVR,DATA)
                            379 ;--------------------------------------------------------
                            380 ; indirectly addressable internal ram data
                            381 ;--------------------------------------------------------
                            382 	.area ISEG    (DATA)
                            383 ;--------------------------------------------------------
                            384 ; absolute internal ram data
                            385 ;--------------------------------------------------------
                            386 	.area IABS    (ABS,DATA)
                            387 	.area IABS    (ABS,DATA)
                            388 ;--------------------------------------------------------
                            389 ; bit data
                            390 ;--------------------------------------------------------
                            391 	.area BSEG    (BIT)
                            392 ;--------------------------------------------------------
                            393 ; paged external ram data
                            394 ;--------------------------------------------------------
                            395 	.area PSEG    (PAG,XDATA)
                            396 ;--------------------------------------------------------
                            397 ; external ram data
                            398 ;--------------------------------------------------------
                            399 	.area XSEG    (XDATA)
   80DB                     400 _ep1_sent::
   80DB                     401 	.ds 1
   80DC                     402 _ep1_receive::
   80DC                     403 	.ds 1
   80DD                     404 _usb_state::
   80DD                     405 	.ds 1
   80DE                     406 _usb_wait_for_configuration_usb_hal_state_1_1:
   80DE                     407 	.ds 1
   80DF                     408 _usb_send_packet_PARM_2:
   80DF                     409 	.ds 1
   80E0                     410 _usb_send_packet_in_data_1_1:
   80E0                     411 	.ds 3
                            412 ;--------------------------------------------------------
                            413 ; absolute external ram data
                            414 ;--------------------------------------------------------
                            415 	.area XABS    (ABS,XDATA)
                            416 ;--------------------------------------------------------
                            417 ; external initialized ram data
                            418 ;--------------------------------------------------------
                            419 	.area XISEG   (XDATA)
                            420 	.area HOME    (CODE)
                            421 	.area GSINIT0 (CODE)
                            422 	.area GSINIT1 (CODE)
                            423 	.area GSINIT2 (CODE)
                            424 	.area GSINIT3 (CODE)
                            425 	.area GSINIT4 (CODE)
                            426 	.area GSINIT5 (CODE)
                            427 	.area GSINIT  (CODE)
                            428 	.area GSFINAL (CODE)
                            429 	.area CSEG    (CODE)
                            430 ;--------------------------------------------------------
                            431 ; global & static initialisations
                            432 ;--------------------------------------------------------
                            433 	.area HOME    (CODE)
                            434 	.area GSINIT  (CODE)
                            435 	.area GSFINAL (CODE)
                            436 	.area GSINIT  (CODE)
                            437 ;--------------------------------------------------------
                            438 ; Home
                            439 ;--------------------------------------------------------
                            440 	.area HOME    (CODE)
                            441 	.area HOME    (CODE)
                            442 ;--------------------------------------------------------
                            443 ; code
                            444 ;--------------------------------------------------------
                            445 	.area CSEG    (CODE)
                            446 ;------------------------------------------------------------
                            447 ;Allocation info for local variables in function 'usb_init'
                            448 ;------------------------------------------------------------
                            449 ;------------------------------------------------------------
                            450 ;	../usb_api.c:24: void usb_init(void)
                            451 ;	-----------------------------------------
                            452 ;	 function usb_init
                            453 ;	-----------------------------------------
   0BE0                     454 _usb_init:
                    0002    455 	ar2 = 0x02
                    0003    456 	ar3 = 0x03
                    0004    457 	ar4 = 0x04
                    0005    458 	ar5 = 0x05
                    0006    459 	ar6 = 0x06
                    0007    460 	ar7 = 0x07
                    0000    461 	ar0 = 0x00
                    0001    462 	ar1 = 0x01
                            463 ;	../usb_api.c:26: hal_usb_init(true, device_req_cb, reset_cb, resume_cb, suspend_cb);
   0BE0 90 81 73            464 	mov	dptr,#_hal_usb_init_PARM_2
   0BE3 74 E1               465 	mov	a,#_device_req_cb
   0BE5 F0                  466 	movx	@dptr,a
   0BE6 A3                  467 	inc	dptr
   0BE7 74 0C               468 	mov	a,#(_device_req_cb >> 8)
   0BE9 F0                  469 	movx	@dptr,a
   0BEA 90 81 75            470 	mov	dptr,#_hal_usb_init_PARM_3
   0BED 74 18               471 	mov	a,#_reset_cb
   0BEF F0                  472 	movx	@dptr,a
   0BF0 A3                  473 	inc	dptr
   0BF1 74 0D               474 	mov	a,#(_reset_cb >> 8)
   0BF3 F0                  475 	movx	@dptr,a
   0BF4 90 81 77            476 	mov	dptr,#_hal_usb_init_PARM_4
   0BF7 74 08               477 	mov	a,#_resume_cb
   0BF9 F0                  478 	movx	@dptr,a
   0BFA A3                  479 	inc	dptr
   0BFB 74 0D               480 	mov	a,#(_resume_cb >> 8)
   0BFD F0                  481 	movx	@dptr,a
   0BFE 90 81 79            482 	mov	dptr,#_hal_usb_init_PARM_5
   0C01 74 EC               483 	mov	a,#_suspend_cb
   0C03 F0                  484 	movx	@dptr,a
   0C04 A3                  485 	inc	dptr
   0C05 74 0C               486 	mov	a,#(_suspend_cb >> 8)
   0C07 F0                  487 	movx	@dptr,a
   0C08 75 82 01            488 	mov	dpl,#0x01
   0C0B 12 19 CF            489 	lcall	_hal_usb_init
                            490 ;	../usb_api.c:28: hal_usb_endpoint_config(0x81, 32, ep_1_in_cb);          //bulk EP IN  1
   0C0E 90 81 81            491 	mov	dptr,#_hal_usb_endpoint_config_PARM_2
   0C11 74 20               492 	mov	a,#0x20
   0C13 F0                  493 	movx	@dptr,a
   0C14 90 81 82            494 	mov	dptr,#_hal_usb_endpoint_config_PARM_3
   0C17 74 28               495 	mov	a,#_ep_1_in_cb
   0C19 F0                  496 	movx	@dptr,a
   0C1A A3                  497 	inc	dptr
   0C1B 74 0D               498 	mov	a,#(_ep_1_in_cb >> 8)
   0C1D F0                  499 	movx	@dptr,a
   0C1E 75 82 81            500 	mov	dpl,#0x81
   0C21 12 1C 83            501 	lcall	_hal_usb_endpoint_config
                            502 ;	../usb_api.c:29: hal_usb_endpoint_config(0x01, 32, ep_1_out_cb);         //bulk EP OUT 1
   0C24 90 81 81            503 	mov	dptr,#_hal_usb_endpoint_config_PARM_2
   0C27 74 20               504 	mov	a,#0x20
   0C29 F0                  505 	movx	@dptr,a
   0C2A 90 81 82            506 	mov	dptr,#_hal_usb_endpoint_config_PARM_3
   0C2D 74 39               507 	mov	a,#_ep_1_out_cb
   0C2F F0                  508 	movx	@dptr,a
   0C30 A3                  509 	inc	dptr
   0C31 74 0D               510 	mov	a,#(_ep_1_out_cb >> 8)
   0C33 F0                  511 	movx	@dptr,a
   0C34 75 82 01            512 	mov	dpl,#0x01
   0C37 12 1C 83            513 	lcall	_hal_usb_endpoint_config
                            514 ;	../usb_api.c:31: ep1_sent = true;
   0C3A 90 80 DB            515 	mov	dptr,#_ep1_sent
   0C3D 74 01               516 	mov	a,#0x01
   0C3F F0                  517 	movx	@dptr,a
                            518 ;	../usb_api.c:32: ep1_receive = false;
   0C40 90 80 DC            519 	mov	dptr,#_ep1_receive
                            520 ;	../usb_api.c:34: usb_state = USB_AWAKE;
   0C43 E4                  521 	clr	a
   0C44 F0                  522 	movx	@dptr,a
   0C45 90 80 DD            523 	mov	dptr,#_usb_state
   0C48 F0                  524 	movx	@dptr,a
   0C49 22                  525 	ret
                            526 ;------------------------------------------------------------
                            527 ;Allocation info for local variables in function 'usb_wakeup'
                            528 ;------------------------------------------------------------
                            529 ;------------------------------------------------------------
                            530 ;	../usb_api.c:37: void usb_wakeup(void)
                            531 ;	-----------------------------------------
                            532 ;	 function usb_wakeup
                            533 ;	-----------------------------------------
   0C4A                     534 _usb_wakeup:
                            535 ;	../usb_api.c:39: hal_usb_wakeup();
   0C4A 12 1E 29            536 	lcall	_hal_usb_wakeup
                            537 ;	../usb_api.c:40: usb_state = USB_AWAKE;
   0C4D 90 80 DD            538 	mov	dptr,#_usb_state
   0C50 E4                  539 	clr	a
   0C51 F0                  540 	movx	@dptr,a
   0C52 22                  541 	ret
                            542 ;------------------------------------------------------------
                            543 ;Allocation info for local variables in function 'usb_get_state'
                            544 ;------------------------------------------------------------
                            545 ;------------------------------------------------------------
                            546 ;	../usb_api.c:43: usb_state_t usb_get_state()
                            547 ;	-----------------------------------------
                            548 ;	 function usb_get_state
                            549 ;	-----------------------------------------
   0C53                     550 _usb_get_state:
                            551 ;	../usb_api.c:45: return usb_state;
   0C53 90 80 DD            552 	mov	dptr,#_usb_state
   0C56 E0                  553 	movx	a,@dptr
   0C57 F5 82               554 	mov	dpl,a
   0C59 22                  555 	ret
                            556 ;------------------------------------------------------------
                            557 ;Allocation info for local variables in function 'usb_wait_for_configuration'
                            558 ;------------------------------------------------------------
                            559 ;i                         Allocated with name '_usb_wait_for_configuration_i_1_1'
                            560 ;usb_hal_state             Allocated with name '_usb_wait_for_configuration_usb_hal_state_1_1'
                            561 ;------------------------------------------------------------
                            562 ;	../usb_api.c:48: void usb_wait_for_configuration(void)
                            563 ;	-----------------------------------------
                            564 ;	 function usb_wait_for_configuration
                            565 ;	-----------------------------------------
   0C5A                     566 _usb_wait_for_configuration:
                            567 ;	../usb_api.c:52: do
   0C5A 7A 00               568 	mov	r2,#0x00
   0C5C 7B 00               569 	mov	r3,#0x00
   0C5E                     570 00103$:
                            571 ;	../usb_api.c:54: usb_hal_state = hal_usb_get_state();
   0C5E C0 02               572 	push	ar2
   0C60 C0 03               573 	push	ar3
   0C62 12 1E 44            574 	lcall	_hal_usb_get_state
   0C65 E5 82               575 	mov	a,dpl
   0C67 D0 03               576 	pop	ar3
   0C69 D0 02               577 	pop	ar2
   0C6B 90 80 DE            578 	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
   0C6E F0                  579 	movx	@dptr,a
                            580 ;	../usb_api.c:55: if(i>10)
   0C6F C3                  581 	clr	c
   0C70 74 0A               582 	mov	a,#0x0A
   0C72 9A                  583 	subb	a,r2
   0C73 74 80               584 	mov	a,#(0x00 ^ 0x80)
   0C75 8B F0               585 	mov	b,r3
   0C77 63 F0 80            586 	xrl	b,#0x80
   0C7A 95 F0               587 	subb	a,b
   0C7C 50 06               588 	jnc	00102$
                            589 ;	../usb_api.c:56: usb_hal_state=CONFIGURED;
   0C7E 90 80 DE            590 	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
   0C81 74 04               591 	mov	a,#0x04
   0C83 F0                  592 	movx	@dptr,a
   0C84                     593 00102$:
                            594 ;	../usb_api.c:57: i++;
   0C84 0A                  595 	inc	r2
   0C85 BA 00 01            596 	cjne	r2,#0x00,00112$
   0C88 0B                  597 	inc	r3
   0C89                     598 00112$:
                            599 ;	../usb_api.c:59: while(usb_hal_state != CONFIGURED);
   0C89 90 80 DE            600 	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
   0C8C E0                  601 	movx	a,@dptr
   0C8D FC                  602 	mov	r4,a
   0C8E BC 04 CD            603 	cjne	r4,#0x04,00103$
   0C91 22                  604 	ret
                            605 ;------------------------------------------------------------
                            606 ;Allocation info for local variables in function 'usb_send_packet'
                            607 ;------------------------------------------------------------
                            608 ;size                      Allocated with name '_usb_send_packet_PARM_2'
                            609 ;in_data                   Allocated with name '_usb_send_packet_in_data_1_1'
                            610 ;------------------------------------------------------------
                            611 ;	../usb_api.c:62: void usb_send_packet(uint8_t* in_data, uint8_t size)
                            612 ;	-----------------------------------------
                            613 ;	 function usb_send_packet
                            614 ;	-----------------------------------------
   0C92                     615 _usb_send_packet:
   0C92 AA F0               616 	mov	r2,b
   0C94 AB 83               617 	mov	r3,dph
   0C96 E5 82               618 	mov	a,dpl
   0C98 90 80 E0            619 	mov	dptr,#_usb_send_packet_in_data_1_1
   0C9B F0                  620 	movx	@dptr,a
   0C9C A3                  621 	inc	dptr
   0C9D EB                  622 	mov	a,r3
   0C9E F0                  623 	movx	@dptr,a
   0C9F A3                  624 	inc	dptr
   0CA0 EA                  625 	mov	a,r2
   0CA1 F0                  626 	movx	@dptr,a
                            627 ;	../usb_api.c:64: while(!ep1_sent)
   0CA2                     628 00101$:
   0CA2 90 80 DB            629 	mov	dptr,#_ep1_sent
   0CA5 E0                  630 	movx	a,@dptr
   0CA6 FA                  631 	mov	r2,a
   0CA7 60 F9               632 	jz	00101$
                            633 ;	../usb_api.c:66: ep1_sent = false;
   0CA9 90 80 DB            634 	mov	dptr,#_ep1_sent
   0CAC E4                  635 	clr	a
   0CAD F0                  636 	movx	@dptr,a
                            637 ;	../usb_api.c:67: hal_usb_send_data(0x81, in_data, size);
   0CAE 90 80 E0            638 	mov	dptr,#_usb_send_packet_in_data_1_1
   0CB1 E0                  639 	movx	a,@dptr
   0CB2 FA                  640 	mov	r2,a
   0CB3 A3                  641 	inc	dptr
   0CB4 E0                  642 	movx	a,@dptr
   0CB5 FB                  643 	mov	r3,a
   0CB6 A3                  644 	inc	dptr
   0CB7 E0                  645 	movx	a,@dptr
   0CB8 FC                  646 	mov	r4,a
   0CB9 90 80 DF            647 	mov	dptr,#_usb_send_packet_PARM_2
   0CBC E0                  648 	movx	a,@dptr
   0CBD FD                  649 	mov	r5,a
   0CBE 90 81 85            650 	mov	dptr,#_hal_usb_send_data_PARM_2
   0CC1 EA                  651 	mov	a,r2
   0CC2 F0                  652 	movx	@dptr,a
   0CC3 A3                  653 	inc	dptr
   0CC4 EB                  654 	mov	a,r3
   0CC5 F0                  655 	movx	@dptr,a
   0CC6 A3                  656 	inc	dptr
   0CC7 EC                  657 	mov	a,r4
   0CC8 F0                  658 	movx	@dptr,a
   0CC9 90 81 88            659 	mov	dptr,#_hal_usb_send_data_PARM_3
   0CCC ED                  660 	mov	a,r5
   0CCD F0                  661 	movx	@dptr,a
   0CCE 75 82 81            662 	mov	dpl,#0x81
   0CD1 02 1E 4B            663 	ljmp	_hal_usb_send_data
                            664 ;------------------------------------------------------------
                            665 ;Allocation info for local variables in function 'usb_recv_packet'
                            666 ;------------------------------------------------------------
                            667 ;------------------------------------------------------------
                            668 ;	../usb_api.c:70: void usb_recv_packet(){ 
                            669 ;	-----------------------------------------
                            670 ;	 function usb_recv_packet
                            671 ;	-----------------------------------------
   0CD4                     672 _usb_recv_packet:
                            673 ;	../usb_api.c:71: while(!ep1_receive)
   0CD4                     674 00101$:
   0CD4 90 80 DC            675 	mov	dptr,#_ep1_receive
   0CD7 E0                  676 	movx	a,@dptr
   0CD8 FA                  677 	mov	r2,a
   0CD9 60 F9               678 	jz	00101$
                            679 ;	../usb_api.c:74: ep1_receive = false;
   0CDB 90 80 DC            680 	mov	dptr,#_ep1_receive
   0CDE E4                  681 	clr	a
   0CDF F0                  682 	movx	@dptr,a
   0CE0 22                  683 	ret
                            684 ;------------------------------------------------------------
                            685 ;Allocation info for local variables in function 'device_req_cb'
                            686 ;------------------------------------------------------------
                            687 ;data_ptr                  Allocated to stack - offset -5
                            688 ;size                      Allocated to stack - offset -8
                            689 ;req                       Allocated to registers 
                            690 ;------------------------------------------------------------
                            691 ;	../usb_api.c:77: static hal_usb_dev_req_resp_t device_req_cb(hal_usb_device_req* req, uint8_t** data_ptr, uint16_t* size) reentrant
                            692 ;	-----------------------------------------
                            693 ;	 function device_req_cb
                            694 ;	-----------------------------------------
   0CE1                     695 _device_req_cb:
   0CE1 C0 11               696 	push	_bp
   0CE3 85 81 11            697 	mov	_bp,sp
                            698 ;	../usb_api.c:80: return NAK;
   0CE6 75 82 01            699 	mov	dpl,#0x01
   0CE9 D0 11               700 	pop	_bp
   0CEB 22                  701 	ret
                            702 ;------------------------------------------------------------
                            703 ;Allocation info for local variables in function 'suspend_cb'
                            704 ;------------------------------------------------------------
                            705 ;allow_remote_wu           Allocated to registers r2 
                            706 ;------------------------------------------------------------
                            707 ;	../usb_api.c:84: static void suspend_cb(uint8_t allow_remote_wu) reentrant
                            708 ;	-----------------------------------------
                            709 ;	 function suspend_cb
                            710 ;	-----------------------------------------
   0CEC                     711 _suspend_cb:
   0CEC AA 82               712 	mov	r2,dpl
                            713 ;	../usb_api.c:87: USBSLP = 1; // Disable USB clock (auto clear)
   0CEE 75 D9 01            714 	mov	_USBSLP,#0x01
                            715 ;	../usb_api.c:89: if (allow_remote_wu == 1)
   0CF1 BA 01 0A            716 	cjne	r2,#0x01,00102$
                            717 ;	../usb_api.c:93: WUCONF = (BIT_5 | BIT_3 | BIT_1);
   0CF4 75 A5 2A            718 	mov	_WUCONF,#0x2A
                            719 ;	../usb_api.c:94: usb_state = USB_REM_WU_ENABLE;
   0CF7 90 80 DD            720 	mov	dptr,#_usb_state
   0CFA 74 01               721 	mov	a,#0x01
   0CFC F0                  722 	movx	@dptr,a
   0CFD 22                  723 	ret
   0CFE                     724 00102$:
                            725 ;	../usb_api.c:99: WUCONF = (BIT_3 | BIT_1);
   0CFE 75 A5 0A            726 	mov	_WUCONF,#0x0A
                            727 ;	../usb_api.c:100: usb_state = USB_REM_WU_DISABLE;
   0D01 90 80 DD            728 	mov	dptr,#_usb_state
   0D04 74 02               729 	mov	a,#0x02
   0D06 F0                  730 	movx	@dptr,a
   0D07 22                  731 	ret
                            732 ;------------------------------------------------------------
                            733 ;Allocation info for local variables in function 'resume_cb'
                            734 ;------------------------------------------------------------
                            735 ;------------------------------------------------------------
                            736 ;	../usb_api.c:104: static void resume_cb() reentrant
                            737 ;	-----------------------------------------
                            738 ;	 function resume_cb
                            739 ;	-----------------------------------------
   0D08                     740 _resume_cb:
                            741 ;	../usb_api.c:107: ep1_sent = true;
   0D08 90 80 DB            742 	mov	dptr,#_ep1_sent
   0D0B 74 01               743 	mov	a,#0x01
   0D0D F0                  744 	movx	@dptr,a
                            745 ;	../usb_api.c:108: ep1_receive = false;
   0D0E 90 80 DC            746 	mov	dptr,#_ep1_receive
                            747 ;	../usb_api.c:109: usb_state = USB_AWAKE;
   0D11 E4                  748 	clr	a
   0D12 F0                  749 	movx	@dptr,a
   0D13 90 80 DD            750 	mov	dptr,#_usb_state
   0D16 F0                  751 	movx	@dptr,a
   0D17 22                  752 	ret
                            753 ;------------------------------------------------------------
                            754 ;Allocation info for local variables in function 'reset_cb'
                            755 ;------------------------------------------------------------
                            756 ;------------------------------------------------------------
                            757 ;	../usb_api.c:112: static void reset_cb() reentrant
                            758 ;	-----------------------------------------
                            759 ;	 function reset_cb
                            760 ;	-----------------------------------------
   0D18                     761 _reset_cb:
                            762 ;	../usb_api.c:115: ep1_sent = true;
   0D18 90 80 DB            763 	mov	dptr,#_ep1_sent
   0D1B 74 01               764 	mov	a,#0x01
   0D1D F0                  765 	movx	@dptr,a
                            766 ;	../usb_api.c:116: ep1_receive = false;
   0D1E 90 80 DC            767 	mov	dptr,#_ep1_receive
                            768 ;	../usb_api.c:117: usb_state = USB_AWAKE;
   0D21 E4                  769 	clr	a
   0D22 F0                  770 	movx	@dptr,a
   0D23 90 80 DD            771 	mov	dptr,#_usb_state
   0D26 F0                  772 	movx	@dptr,a
   0D27 22                  773 	ret
                            774 ;------------------------------------------------------------
                            775 ;Allocation info for local variables in function 'ep_1_in_cb'
                            776 ;------------------------------------------------------------
                            777 ;size                      Allocated to stack - offset -5
                            778 ;adr_ptr                   Allocated to registers 
                            779 ;------------------------------------------------------------
                            780 ;	../usb_api.c:121: static uint8_t ep_1_in_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
                            781 ;	-----------------------------------------
                            782 ;	 function ep_1_in_cb
                            783 ;	-----------------------------------------
   0D28                     784 _ep_1_in_cb:
   0D28 C0 11               785 	push	_bp
   0D2A 85 81 11            786 	mov	_bp,sp
                            787 ;	../usb_api.c:124: ep1_sent = true;
   0D2D 90 80 DB            788 	mov	dptr,#_ep1_sent
   0D30 74 01               789 	mov	a,#0x01
   0D32 F0                  790 	movx	@dptr,a
                            791 ;	../usb_api.c:125: return 0x60;
   0D33 75 82 60            792 	mov	dpl,#0x60
   0D36 D0 11               793 	pop	_bp
   0D38 22                  794 	ret
                            795 ;------------------------------------------------------------
                            796 ;Allocation info for local variables in function 'ep_1_out_cb'
                            797 ;------------------------------------------------------------
                            798 ;size                      Allocated to stack - offset -5
                            799 ;adr_ptr                   Allocated to stack - offset 1
                            800 ;i                         Allocated to registers r6 
                            801 ;------------------------------------------------------------
                            802 ;	../usb_api.c:128: static uint8_t ep_1_out_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
                            803 ;	-----------------------------------------
                            804 ;	 function ep_1_out_cb
                            805 ;	-----------------------------------------
   0D39                     806 _ep_1_out_cb:
   0D39 C0 11               807 	push	_bp
   0D3B 85 81 11            808 	mov	_bp,sp
   0D3E C0 82               809 	push	dpl
   0D40 C0 83               810 	push	dph
   0D42 C0 F0               811 	push	b
                            812 ;	../usb_api.c:134: usize = *size;
   0D44 E5 11               813 	mov	a,_bp
   0D46 24 FB               814 	add	a,#0xfb
   0D48 F8                  815 	mov	r0,a
   0D49 86 05               816 	mov	ar5,@r0
   0D4B 08                  817 	inc	r0
   0D4C 86 06               818 	mov	ar6,@r0
   0D4E 08                  819 	inc	r0
   0D4F 86 07               820 	mov	ar7,@r0
   0D51 8D 82               821 	mov	dpl,r5
   0D53 8E 83               822 	mov	dph,r6
   0D55 8F F0               823 	mov	b,r7
   0D57 12 33 F7            824 	lcall	__gptrget
   0D5A FD                  825 	mov	r5,a
   0D5B 90 80 79            826 	mov	dptr,#_usize
   0D5E F0                  827 	movx	@dptr,a
                            828 ;	../usb_api.c:136: for(i = 0;i < usize;i++)
   0D5F 7E 00               829 	mov	r6,#0x00
   0D61                     830 00101$:
   0D61 C3                  831 	clr	c
   0D62 EE                  832 	mov	a,r6
   0D63 9D                  833 	subb	a,r5
   0D64 50 2B               834 	jnc	00104$
                            835 ;	../usb_api.c:137: ubuf[i] = adr_ptr[i];
   0D66 C0 05               836 	push	ar5
   0D68 EE                  837 	mov	a,r6
   0D69 24 38               838 	add	a,#_ubuf
   0D6B FF                  839 	mov	r7,a
   0D6C E4                  840 	clr	a
   0D6D 34 80               841 	addc	a,#(_ubuf >> 8)
   0D6F FD                  842 	mov	r5,a
   0D70 A8 11               843 	mov	r0,_bp
   0D72 08                  844 	inc	r0
   0D73 EE                  845 	mov	a,r6
   0D74 26                  846 	add	a,@r0
   0D75 FA                  847 	mov	r2,a
   0D76 E4                  848 	clr	a
   0D77 08                  849 	inc	r0
   0D78 36                  850 	addc	a,@r0
   0D79 FB                  851 	mov	r3,a
   0D7A 08                  852 	inc	r0
   0D7B 86 04               853 	mov	ar4,@r0
   0D7D 8A 82               854 	mov	dpl,r2
   0D7F 8B 83               855 	mov	dph,r3
   0D81 8C F0               856 	mov	b,r4
   0D83 12 33 F7            857 	lcall	__gptrget
   0D86 FA                  858 	mov	r2,a
   0D87 8F 82               859 	mov	dpl,r7
   0D89 8D 83               860 	mov	dph,r5
   0D8B F0                  861 	movx	@dptr,a
                            862 ;	../usb_api.c:136: for(i = 0;i < usize;i++)
   0D8C 0E                  863 	inc	r6
   0D8D D0 05               864 	pop	ar5
   0D8F 80 D0               865 	sjmp	00101$
   0D91                     866 00104$:
                            867 ;	../usb_api.c:146: ep1_receive = true;
   0D91 90 80 DC            868 	mov	dptr,#_ep1_receive
   0D94 74 01               869 	mov	a,#0x01
   0D96 F0                  870 	movx	@dptr,a
                            871 ;	../usb_api.c:147: return 0xFF;
   0D97 75 82 FF            872 	mov	dpl,#0xFF
   0D9A 85 11 81            873 	mov	sp,_bp
   0D9D D0 11               874 	pop	_bp
   0D9F 22                  875 	ret
                            876 	.area CSEG    (CODE)
                            877 	.area CONST   (CODE)
                            878 	.area XINIT   (CODE)
                            879 	.area CABS    (ABS,CODE)
