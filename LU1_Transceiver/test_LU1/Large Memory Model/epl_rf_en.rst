                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Fri Nov 19 17:26:12 2010
                              5 ;--------------------------------------------------------
                              6 	.module epl_rf_en
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
                            180 	.globl _epl_rf_en_send_PARM_2
                            181 	.globl _epl_rf_en_send_dst_PARM_3
                            182 	.globl _epl_rf_en_send_dst_PARM_2
                            183 	.globl _epl_rf_en_easy_start_rx_PARM_3
                            184 	.globl _epl_rf_en_easy_start_rx_PARM_2
                            185 	.globl _epl_rf_en_easy_start_tx_PARM_3
                            186 	.globl _epl_rf_en_easy_start_tx_PARM_2
                            187 	.globl _epl_rf_en_rcv_pipe_config_PARM_4
                            188 	.globl _epl_rf_en_rcv_pipe_config_PARM_3
                            189 	.globl _epl_rf_en_rcv_pipe_config_PARM_2
                            190 	.globl _epl_rf_en_init_PARM_9
                            191 	.globl _epl_rf_en_init_PARM_8
                            192 	.globl _epl_rf_en_init_PARM_7
                            193 	.globl _epl_rf_en_init_PARM_6
                            194 	.globl _epl_rf_en_init_PARM_5
                            195 	.globl _epl_rf_en_init_PARM_4
                            196 	.globl _epl_rf_en_init_PARM_3
                            197 	.globl _epl_rf_en_init_PARM_2
                            198 	.globl _epl_rf_en_init
                            199 	.globl _epl_rf_en_rcv_pipe_config
                            200 	.globl _epl_rf_en_easy_start_tx
                            201 	.globl _epl_rf_en_easy_start_rx
                            202 	.globl _epl_rf_en_quick_init
                            203 	.globl _epl_rf_en_enter_tx_mode
                            204 	.globl _epl_rf_en_enter_rx_mode
                            205 	.globl _epl_rf_en_set_dst_addr
                            206 	.globl _epl_rf_en_send_dst
                            207 	.globl _epl_rf_en_send
                            208 	.globl _epl_rf_en_rx_pload_is_empty
                            209 	.globl _epl_rf_en_read_rx_pload
                            210 	.globl _epl_rf_en_wait_rcv_msg
                            211 ;--------------------------------------------------------
                            212 ; special function registers
                            213 ;--------------------------------------------------------
                            214 	.area RSEG    (DATA)
                    0080    215 _P0	=	0x0080
                    0081    216 _SP	=	0x0081
                    0082    217 _DPL	=	0x0082
                    0083    218 _DPH	=	0x0083
                    0084    219 _DPL1	=	0x0084
                    0085    220 _DPH1	=	0x0085
                    0087    221 _PCON	=	0x0087
                    0088    222 _TCON	=	0x0088
                    0089    223 _TMOD	=	0x0089
                    008A    224 _TL0	=	0x008a
                    008B    225 _TL1	=	0x008b
                    008C    226 _TH0	=	0x008c
                    008D    227 _TH1	=	0x008d
                    008E    228 _CKCON	=	0x008e
                    0090    229 _RFCON	=	0x0090
                    0092    230 _DPS	=	0x0092
                    0094    231 _P0DIR	=	0x0094
                    0095    232 _P0ALT	=	0x0095
                    0098    233 _S0CON	=	0x0098
                    0099    234 _S0BUF	=	0x0099
                    009A    235 _IEN2	=	0x009a
                    00A0    236 _USBCON	=	0x00a0
                    00A3    237 _CLKCTL	=	0x00a3
                    00A4    238 _PWRDWN	=	0x00a4
                    00A5    239 _WUCONF	=	0x00a5
                    00A6    240 _INTEXP	=	0x00a6
                    00A8    241 _IEN0	=	0x00a8
                    00A9    242 _IP0	=	0x00a9
                    00AA    243 _S0RELL	=	0x00aa
                    00AB    244 _REGXH	=	0x00ab
                    00AC    245 _REGXL	=	0x00ac
                    00AD    246 _REGXC	=	0x00ad
                    00B1    247 _RSTRES	=	0x00b1
                    00B2    248 _SMDAT	=	0x00b2
                    00B3    249 _SMCTL	=	0x00b3
                    00B5    250 _TICKDV	=	0x00b5
                    00B8    251 _IEN1	=	0x00b8
                    00B9    252 _IP1	=	0x00b9
                    00BA    253 _S0RELH	=	0x00ba
                    00BC    254 _SSCONF	=	0x00bc
                    00BD    255 _SSDATA	=	0x00bd
                    00BE    256 _SSSTAT	=	0x00be
                    00C0    257 _IRCON	=	0x00c0
                    00C1    258 _CCEN	=	0x00c1
                    00C2    259 _CCL1	=	0x00c2
                    00C3    260 _CCH1	=	0x00c3
                    00C4    261 _CCL2	=	0x00c4
                    00C5    262 _CCH2	=	0x00c5
                    00C6    263 _CCL3	=	0x00c6
                    00C7    264 _CCH3	=	0x00c7
                    00C8    265 _T2CON	=	0x00c8
                    00C9    266 _P0EXP	=	0x00c9
                    00CA    267 _CRCL	=	0x00ca
                    00CB    268 _CRCH	=	0x00cb
                    00CC    269 _TL2	=	0x00cc
                    00CD    270 _TH2	=	0x00cd
                    00D0    271 _PSW	=	0x00d0
                    00D8    272 _WDCON	=	0x00d8
                    00D9    273 _USBSLP	=	0x00d9
                    00E0    274 _ACC	=	0x00e0
                    00E5    275 _RFDAT	=	0x00e5
                    00E6    276 _RFCTL	=	0x00e6
                    00E8    277 _AESCS	=	0x00e8
                    00E9    278 _MD0	=	0x00e9
                    00EA    279 _MD1	=	0x00ea
                    00EB    280 _MD2	=	0x00eb
                    00EC    281 _MD3	=	0x00ec
                    00ED    282 _MD4	=	0x00ed
                    00EE    283 _MD5	=	0x00ee
                    00EF    284 _ARCON	=	0x00ef
                    00F0    285 _B	=	0x00f0
                    00F1    286 _AESKIN	=	0x00f1
                    00F2    287 _AESIV	=	0x00f2
                    00F3    288 _AESD	=	0x00f3
                    00F5    289 _AESIA1	=	0x00f5
                    00F6    290 _AESIA2	=	0x00f6
                    00F8    291 _FSR	=	0x00f8
                    00F9    292 _FPCR	=	0x00f9
                    00FA    293 _FCR	=	0x00fa
                    FFFFC3C2    294 _CC1	=	0xffffc3c2
                    FFFFC5C4    295 _CC2	=	0xffffc5c4
                    FFFFC7C6    296 _CC3	=	0xffffc7c6
                    FFFFCBCA    297 _CRC	=	0xffffcbca
                    FFFFCDCC    298 _T2	=	0xffffcdcc
                            299 ;--------------------------------------------------------
                            300 ; special function bits
                            301 ;--------------------------------------------------------
                            302 	.area RSEG    (DATA)
                    00FF    303 _MCDIS	=	0x00ff
                    00FE    304 _STP	=	0x00fe
                    00FD    305 _WEN	=	0x00fd
                    00FC    306 _RDYN	=	0x00fc
                    00FB    307 _INFEN	=	0x00fb
                    00FA    308 _RDIS	=	0x00fa
                    00F9    309 _RDEND	=	0x00f9
                    00F8    310 _WPEN	=	0x00f8
                    00D7    311 _CY	=	0x00d7
                    00D6    312 _AC	=	0x00d6
                    00D5    313 _F0	=	0x00d5
                    00D4    314 _RS1	=	0x00d4
                    00D3    315 _RS0	=	0x00d3
                    00D2    316 _OV	=	0x00d2
                    00D1    317 _F1	=	0x00d1
                    00D0    318 _P	=	0x00d0
                    008F    319 _TF1	=	0x008f
                    008E    320 _TR1	=	0x008e
                    008D    321 _TF0	=	0x008d
                    008C    322 _TR0	=	0x008c
                    008B    323 _IE1	=	0x008b
                    008A    324 _IT1	=	0x008a
                    0089    325 _IE0	=	0x0089
                    0088    326 _IT0	=	0x0088
                    009F    327 _SM0	=	0x009f
                    009E    328 _SM1	=	0x009e
                    009D    329 _SM20	=	0x009d
                    009C    330 _REN0	=	0x009c
                    009B    331 _TB80	=	0x009b
                    009A    332 _RB80	=	0x009a
                    0099    333 _TI0	=	0x0099
                    0098    334 _RI0	=	0x0098
                    00CF    335 _T2PS	=	0x00cf
                    00CE    336 _I3FR	=	0x00ce
                    00CD    337 _I2FR	=	0x00cd
                    00CC    338 _T2R1	=	0x00cc
                    00CB    339 _T2R0	=	0x00cb
                    00CA    340 _T2CM	=	0x00ca
                    00C9    341 _T2I1	=	0x00c9
                    00C8    342 _T2I0	=	0x00c8
                    00AF    343 _EA	=	0x00af
                    00AD    344 _ET2	=	0x00ad
                    00AC    345 _ES0	=	0x00ac
                    00AB    346 _ET1	=	0x00ab
                    00AA    347 _EX1	=	0x00aa
                    00A9    348 _ET0	=	0x00a9
                    00A8    349 _EX0	=	0x00a8
                    00BF    350 _EXEN2	=	0x00bf
                    00BD    351 _WUIRQ	=	0x00bd
                    00BC    352 _USB	=	0x00bc
                    00BB    353 _USBWU	=	0x00bb
                    00BA    354 _SPI	=	0x00ba
                    00B9    355 _RF	=	0x00b9
                    00B8    356 _RFSPI	=	0x00b8
                    00C7    357 _EXF2	=	0x00c7
                    00C6    358 _TF2	=	0x00c6
                    00C5    359 _WUF	=	0x00c5
                    00C4    360 _USBF	=	0x00c4
                    00C3    361 _USBWUF	=	0x00c3
                    00C2    362 _SPIF	=	0x00c2
                    00C1    363 _RFF	=	0x00c1
                    00C0    364 _RFSPIF	=	0x00c0
                    00A7    365 _SWRST	=	0x00a7
                    00A6    366 _WU	=	0x00a6
                    00A5    367 _SUSPEND	=	0x00a5
                    00A4    368 _IV4	=	0x00a4
                    00A3    369 _IV3	=	0x00a3
                    00A2    370 _IV2	=	0x00a2
                    00A1    371 _IV1	=	0x00a1
                    00A0    372 _IV0	=	0x00a0
                    0080    373 _P00	=	0x0080
                    0081    374 _P01	=	0x0081
                    0082    375 _P02	=	0x0082
                    0083    376 _P03	=	0x0083
                    0083    377 _MCSN	=	0x0083
                    0083    378 _SCSN	=	0x0083
                    0084    379 _P04	=	0x0084
                    0085    380 _P05	=	0x0085
                    0090    381 _RFCE	=	0x0090
                    0091    382 _RFCSN	=	0x0091
                    0092    383 _RFCKEN	=	0x0092
                    00DF    384 _BD	=	0x00df
                    00E8    385 _GO	=	0x00e8
                    00E9    386 _DECR	=	0x00e9
                            387 ;--------------------------------------------------------
                            388 ; overlayable register banks
                            389 ;--------------------------------------------------------
                            390 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     391 	.ds 8
                            392 ;--------------------------------------------------------
                            393 ; internal ram data
                            394 ;--------------------------------------------------------
                            395 	.area DSEG    (DATA)
   0008                     396 _epl_rf_en_quick_init_sloc0_1_0:
   0008                     397 	.ds 1
   0009                     398 _epl_rf_en_quick_init_sloc1_1_0:
   0009                     399 	.ds 1
   000A                     400 _epl_rf_en_quick_init_sloc2_1_0:
   000A                     401 	.ds 1
   000B                     402 _epl_rf_en_quick_init_sloc3_1_0:
   000B                     403 	.ds 1
   000C                     404 _epl_rf_en_quick_init_sloc4_1_0:
   000C                     405 	.ds 3
                            406 ;--------------------------------------------------------
                            407 ; overlayable items in internal ram 
                            408 ;--------------------------------------------------------
                            409 	.area OSEG    (OVR,DATA)
                            410 ;--------------------------------------------------------
                            411 ; indirectly addressable internal ram data
                            412 ;--------------------------------------------------------
                            413 	.area ISEG    (DATA)
                            414 ;--------------------------------------------------------
                            415 ; absolute internal ram data
                            416 ;--------------------------------------------------------
                            417 	.area IABS    (ABS,DATA)
                            418 	.area IABS    (ABS,DATA)
                            419 ;--------------------------------------------------------
                            420 ; bit data
                            421 ;--------------------------------------------------------
                            422 	.area BSEG    (BIT)
                            423 ;--------------------------------------------------------
                            424 ; paged external ram data
                            425 ;--------------------------------------------------------
                            426 	.area PSEG    (PAG,XDATA)
                            427 ;--------------------------------------------------------
                            428 ; external ram data
                            429 ;--------------------------------------------------------
                            430 	.area XSEG    (XDATA)
   8000                     431 _epl_rf_en_init_PARM_2:
   8000                     432 	.ds 1
   8001                     433 _epl_rf_en_init_PARM_3:
   8001                     434 	.ds 1
   8002                     435 _epl_rf_en_init_PARM_4:
   8002                     436 	.ds 1
   8003                     437 _epl_rf_en_init_PARM_5:
   8003                     438 	.ds 2
   8005                     439 _epl_rf_en_init_PARM_6:
   8005                     440 	.ds 1
   8006                     441 _epl_rf_en_init_PARM_7:
   8006                     442 	.ds 1
   8007                     443 _epl_rf_en_init_PARM_8:
   8007                     444 	.ds 1
   8008                     445 _epl_rf_en_init_PARM_9:
   8008                     446 	.ds 1
   8009                     447 _epl_rf_en_init_in_channel_1_1:
   8009                     448 	.ds 1
   800A                     449 _epl_rf_en_rcv_pipe_config_PARM_2:
   800A                     450 	.ds 3
   800D                     451 _epl_rf_en_rcv_pipe_config_PARM_3:
   800D                     452 	.ds 1
   800E                     453 _epl_rf_en_rcv_pipe_config_PARM_4:
   800E                     454 	.ds 1
   800F                     455 _epl_rf_en_rcv_pipe_config_in_pipe_num_1_1:
   800F                     456 	.ds 1
   8010                     457 _epl_rf_en_easy_start_tx_PARM_2:
   8010                     458 	.ds 1
   8011                     459 _epl_rf_en_easy_start_tx_PARM_3:
   8011                     460 	.ds 2
   8013                     461 _epl_rf_en_easy_start_tx_channel_1_1:
   8013                     462 	.ds 1
   8014                     463 _epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1:
   8014                     464 	.ds 5
   8019                     465 _epl_rf_en_easy_start_rx_PARM_2:
   8019                     466 	.ds 1
   801A                     467 _epl_rf_en_easy_start_rx_PARM_3:
   801A                     468 	.ds 1
   801B                     469 _epl_rf_en_easy_start_rx_channel_1_1:
   801B                     470 	.ds 1
   801C                     471 _epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1:
   801C                     472 	.ds 5
   8021                     473 _epl_rf_en_quick_init_in_cfg_1_1:
   8021                     474 	.ds 3
   8024                     475 _epl_rf_en_set_dst_addr_in_dst_addr_1_1:
   8024                     476 	.ds 3
   8027                     477 _epl_rf_en_send_dst_PARM_2:
   8027                     478 	.ds 3
   802A                     479 _epl_rf_en_send_dst_PARM_3:
   802A                     480 	.ds 1
   802B                     481 _epl_rf_en_send_dst_in_dst_addr_1_1:
   802B                     482 	.ds 3
   802E                     483 _epl_rf_en_send_PARM_2:
   802E                     484 	.ds 1
   802F                     485 _epl_rf_en_send_in_tx_pload_1_1:
   802F                     486 	.ds 3
   8032                     487 _epl_rf_en_read_rx_pload_out_rx_pload_1_1:
   8032                     488 	.ds 3
   8035                     489 _epl_rf_en_wait_rcv_msg_out_rx_pload_1_1:
   8035                     490 	.ds 3
                            491 ;--------------------------------------------------------
                            492 ; absolute external ram data
                            493 ;--------------------------------------------------------
                            494 	.area XABS    (ABS,XDATA)
                            495 ;--------------------------------------------------------
                            496 ; external initialized ram data
                            497 ;--------------------------------------------------------
                            498 	.area XISEG   (XDATA)
                            499 	.area HOME    (CODE)
                            500 	.area GSINIT0 (CODE)
                            501 	.area GSINIT1 (CODE)
                            502 	.area GSINIT2 (CODE)
                            503 	.area GSINIT3 (CODE)
                            504 	.area GSINIT4 (CODE)
                            505 	.area GSINIT5 (CODE)
                            506 	.area GSINIT  (CODE)
                            507 	.area GSFINAL (CODE)
                            508 	.area CSEG    (CODE)
                            509 ;--------------------------------------------------------
                            510 ; global & static initialisations
                            511 ;--------------------------------------------------------
                            512 	.area HOME    (CODE)
                            513 	.area GSINIT  (CODE)
                            514 	.area GSFINAL (CODE)
                            515 	.area GSINIT  (CODE)
                            516 ;--------------------------------------------------------
                            517 ; Home
                            518 ;--------------------------------------------------------
                            519 	.area HOME    (CODE)
                            520 	.area HOME    (CODE)
                            521 ;--------------------------------------------------------
                            522 ; code
                            523 ;--------------------------------------------------------
                            524 	.area CSEG    (CODE)
                            525 ;------------------------------------------------------------
                            526 ;Allocation info for local variables in function 'epl_rf_en_init'
                            527 ;------------------------------------------------------------
                            528 ;in_datarate               Allocated with name '_epl_rf_en_init_PARM_2'
                            529 ;in_output_power           Allocated with name '_epl_rf_en_init_PARM_3'
                            530 ;in_auto_retr              Allocated with name '_epl_rf_en_init_PARM_4'
                            531 ;in_auto_retr_delay        Allocated with name '_epl_rf_en_init_PARM_5'
                            532 ;in_addr_width             Allocated with name '_epl_rf_en_init_PARM_6'
                            533 ;in_crc_mode               Allocated with name '_epl_rf_en_init_PARM_7'
                            534 ;in_spi_clk_rate           Allocated with name '_epl_rf_en_init_PARM_8'
                            535 ;in_rf_int                 Allocated with name '_epl_rf_en_init_PARM_9'
                            536 ;in_channel                Allocated with name '_epl_rf_en_init_in_channel_1_1'
                            537 ;------------------------------------------------------------
                            538 ;	../epl_rf_en.c:55: void epl_rf_en_init(unsigned char in_channel, 		// Freq = in_channel + 2400 MHz
                            539 ;	-----------------------------------------
                            540 ;	 function epl_rf_en_init
                            541 ;	-----------------------------------------
   011C                     542 _epl_rf_en_init:
                    0002    543 	ar2 = 0x02
                    0003    544 	ar3 = 0x03
                    0004    545 	ar4 = 0x04
                    0005    546 	ar5 = 0x05
                    0006    547 	ar6 = 0x06
                    0007    548 	ar7 = 0x07
                    0000    549 	ar0 = 0x00
                    0001    550 	ar1 = 0x01
   011C E5 82               551 	mov	a,dpl
   011E 90 80 09            552 	mov	dptr,#_epl_rf_en_init_in_channel_1_1
   0121 F0                  553 	movx	@dptr,a
                            554 ;	../epl_rf_en.c:66: RFCTL = 0x010 + in_spi_clk_rate; // Enable RF SPI and set the clock rate of SPI.
   0122 90 80 07            555 	mov	dptr,#_epl_rf_en_init_PARM_8
   0125 E0                  556 	movx	a,@dptr
   0126 FA                  557 	mov	r2,a
   0127 74 10               558 	mov	a,#0x10
   0129 2A                  559 	add	a,r2
   012A F5 E6               560 	mov	_RFCTL,a
                            561 ;	../epl_rf_en.c:68: RFCKEN = 1;	// RF clock enable.
   012C D2 92               562 	setb	_RFCKEN
                            563 ;	../epl_rf_en.c:71: hal_nrf_close_pipe(HAL_NRF_ALL); // Close all pipes first. By default, pipe0 and pipe1 are opened.
   012E 75 82 FF            564 	mov	dpl,#0xFF
   0131 12 0F 47            565 	lcall	_hal_nrf_close_pipe
                            566 ;	../epl_rf_en.c:73: hal_nrf_set_datarate(in_datarate);
   0134 90 80 00            567 	mov	dptr,#_epl_rf_en_init_PARM_2
   0137 E0                  568 	movx	a,@dptr
   0138 F5 82               569 	mov	dpl,a
   013A 12 12 52            570 	lcall	_hal_nrf_set_datarate
                            571 ;	../epl_rf_en.c:74: hal_nrf_set_auto_retr(in_auto_retr, in_auto_retr_delay); // First parameter is set to zero indicating the auto retransmission is off.
   013D 90 80 02            572 	mov	dptr,#_epl_rf_en_init_PARM_4
   0140 E0                  573 	movx	a,@dptr
   0141 FA                  574 	mov	r2,a
   0142 90 80 03            575 	mov	dptr,#_epl_rf_en_init_PARM_5
   0145 E0                  576 	movx	a,@dptr
   0146 FB                  577 	mov	r3,a
   0147 A3                  578 	inc	dptr
   0148 E0                  579 	movx	a,@dptr
   0149 FC                  580 	mov	r4,a
   014A 90 80 EF            581 	mov	dptr,#_hal_nrf_set_auto_retr_PARM_2
   014D EB                  582 	mov	a,r3
   014E F0                  583 	movx	@dptr,a
   014F A3                  584 	inc	dptr
   0150 EC                  585 	mov	a,r4
   0151 F0                  586 	movx	@dptr,a
   0152 8A 82               587 	mov	dpl,r2
   0154 12 10 3B            588 	lcall	_hal_nrf_set_auto_retr
                            589 ;	../epl_rf_en.c:75: hal_nrf_set_output_power(in_output_power); // Maximum radio output power (0dbm).
   0157 90 80 01            590 	mov	dptr,#_epl_rf_en_init_PARM_3
   015A E0                  591 	movx	a,@dptr
   015B F5 82               592 	mov	dpl,a
   015D 12 12 30            593 	lcall	_hal_nrf_set_output_power
                            594 ;	../epl_rf_en.c:76: hal_nrf_set_crc_mode(in_crc_mode);
   0160 90 80 06            595 	mov	dptr,#_epl_rf_en_init_PARM_7
   0163 E0                  596 	movx	a,@dptr
   0164 F5 82               597 	mov	dpl,a
   0166 12 0E 6C            598 	lcall	_hal_nrf_set_crc_mode
                            599 ;	../epl_rf_en.c:78: hal_nrf_set_address_width(in_addr_width); // Both RX and TX's address width are Configured.
   0169 90 80 05            600 	mov	dptr,#_epl_rf_en_init_PARM_6
   016C E0                  601 	movx	a,@dptr
   016D F5 82               602 	mov	dpl,a
   016F 12 10 70            603 	lcall	_hal_nrf_set_address_width
                            604 ;	../epl_rf_en.c:80: hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode
   0172 75 82 00            605 	mov	dpl,#0x00
   0175 12 11 A8            606 	lcall	_hal_nrf_set_operation_mode
                            607 ;	../epl_rf_en.c:82: hal_nrf_set_rf_channel(in_channel);
   0178 90 80 09            608 	mov	dptr,#_epl_rf_en_init_in_channel_1_1
   017B E0                  609 	movx	a,@dptr
   017C F5 82               610 	mov	dpl,a
   017E 12 12 1C            611 	lcall	_hal_nrf_set_rf_channel
                            612 ;	../epl_rf_en.c:83: hal_nrf_set_power_mode(HAL_NRF_PWR_UP); // Power up radio
   0181 75 82 01            613 	mov	dpl,#0x01
   0184 12 11 E2            614 	lcall	_hal_nrf_set_power_mode
                            615 ;	../epl_rf_en.c:84: hal_nrf_get_clear_irq_flags();
   0187 12 0D F8            616 	lcall	_hal_nrf_get_clear_irq_flags
                            617 ;	../epl_rf_en.c:86: RFCE = 0;
   018A C2 90               618 	clr	_RFCE
                            619 ;	../epl_rf_en.c:89: RF = in_rf_int;
   018C 90 80 08            620 	mov	dptr,#_epl_rf_en_init_PARM_9
   018F E0                  621 	movx	a,@dptr
   0190 24 FF               622 	add	a,#0xff
   0192 92 B9               623 	mov	_RF,c
   0194 22                  624 	ret
                            625 ;------------------------------------------------------------
                            626 ;Allocation info for local variables in function 'epl_rf_en_rcv_pipe_config'
                            627 ;------------------------------------------------------------
                            628 ;in_pipe_rcv_addr          Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_2'
                            629 ;in_pipe_pload_length      Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_3'
                            630 ;in_auto_ack               Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_4'
                            631 ;in_pipe_num               Allocated with name '_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1'
                            632 ;------------------------------------------------------------
                            633 ;	../epl_rf_en.c:105: void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, 		// The pipe number
                            634 ;	-----------------------------------------
                            635 ;	 function epl_rf_en_rcv_pipe_config
                            636 ;	-----------------------------------------
   0195                     637 _epl_rf_en_rcv_pipe_config:
   0195 E5 82               638 	mov	a,dpl
   0197 90 80 0F            639 	mov	dptr,#_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1
   019A F0                  640 	movx	@dptr,a
                            641 ;	../epl_rf_en.c:110: hal_nrf_open_pipe(in_pipe_num, in_auto_ack); // Open pipe and configure the auto ack function.
   019B 90 80 0F            642 	mov	dptr,#_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1
   019E E0                  643 	movx	a,@dptr
   019F FA                  644 	mov	r2,a
   01A0 90 80 0E            645 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   01A3 E0                  646 	movx	a,@dptr
   01A4 90 80 E8            647 	mov	dptr,#_hal_nrf_open_pipe_PARM_2
   01A7 F0                  648 	movx	@dptr,a
   01A8 8A 82               649 	mov	dpl,r2
   01AA C0 02               650 	push	ar2
   01AC 12 0E 90            651 	lcall	_hal_nrf_open_pipe
   01AF D0 02               652 	pop	ar2
                            653 ;	../epl_rf_en.c:111: hal_nrf_set_address(in_pipe_num, in_pipe_rcv_addr); // Address for PRX pipe
   01B1 90 80 0A            654 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   01B4 E0                  655 	movx	a,@dptr
   01B5 FB                  656 	mov	r3,a
   01B6 A3                  657 	inc	dptr
   01B7 E0                  658 	movx	a,@dptr
   01B8 FC                  659 	mov	r4,a
   01B9 A3                  660 	inc	dptr
   01BA E0                  661 	movx	a,@dptr
   01BB FD                  662 	mov	r5,a
   01BC 90 80 EB            663 	mov	dptr,#_hal_nrf_set_address_PARM_2
   01BF EB                  664 	mov	a,r3
   01C0 F0                  665 	movx	@dptr,a
   01C1 A3                  666 	inc	dptr
   01C2 EC                  667 	mov	a,r4
   01C3 F0                  668 	movx	@dptr,a
   01C4 A3                  669 	inc	dptr
   01C5 ED                  670 	mov	a,r5
   01C6 F0                  671 	movx	@dptr,a
   01C7 8A 82               672 	mov	dpl,r2
   01C9 C0 02               673 	push	ar2
   01CB 12 0F C7            674 	lcall	_hal_nrf_set_address
   01CE D0 02               675 	pop	ar2
                            676 ;	../epl_rf_en.c:112: hal_nrf_set_rx_pload_width(in_pipe_num, in_pipe_pload_length);
   01D0 90 80 0D            677 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   01D3 E0                  678 	movx	a,@dptr
   01D4 90 80 F3            679 	mov	dptr,#_hal_nrf_set_rx_pload_width_PARM_2
   01D7 F0                  680 	movx	@dptr,a
   01D8 8A 82               681 	mov	dpl,r2
   01DA 02 10 88            682 	ljmp	_hal_nrf_set_rx_pload_width
                            683 ;------------------------------------------------------------
                            684 ;Allocation info for local variables in function 'epl_rf_en_easy_start_tx'
                            685 ;------------------------------------------------------------
                            686 ;auto_retr                 Allocated with name '_epl_rf_en_easy_start_tx_PARM_2'
                            687 ;delay                     Allocated with name '_epl_rf_en_easy_start_tx_PARM_3'
                            688 ;channel                   Allocated with name '_epl_rf_en_easy_start_tx_channel_1_1'
                            689 ;my_tx_dst_addr            Allocated with name '_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1'
                            690 ;------------------------------------------------------------
                            691 ;	../epl_rf_en.c:123: void epl_rf_en_easy_start_tx(unsigned char channel, uint8_t auto_retr, uint16_t delay){
                            692 ;	-----------------------------------------
                            693 ;	 function epl_rf_en_easy_start_tx
                            694 ;	-----------------------------------------
   01DD                     695 _epl_rf_en_easy_start_tx:
   01DD E5 82               696 	mov	a,dpl
   01DF 90 80 13            697 	mov	dptr,#_epl_rf_en_easy_start_tx_channel_1_1
   01E2 F0                  698 	movx	@dptr,a
                            699 ;	../epl_rf_en.c:125: char my_tx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
   01E3 90 80 14            700 	mov	dptr,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
   01E6 74 65               701 	mov	a,#0x65
   01E8 F0                  702 	movx	@dptr,a
   01E9 90 80 15            703 	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0001)
   01EC 74 65               704 	mov	a,#0x65
   01EE F0                  705 	movx	@dptr,a
   01EF 90 80 16            706 	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0002)
   01F2 74 65               707 	mov	a,#0x65
   01F4 F0                  708 	movx	@dptr,a
   01F5 90 80 17            709 	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0003)
   01F8 74 65               710 	mov	a,#0x65
   01FA F0                  711 	movx	@dptr,a
   01FB 90 80 18            712 	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0004)
   01FE 74 65               713 	mov	a,#0x65
   0200 F0                  714 	movx	@dptr,a
                            715 ;	../epl_rf_en.c:128: epl_rf_en_init(channel,
   0201 90 80 13            716 	mov	dptr,#_epl_rf_en_easy_start_tx_channel_1_1
   0204 E0                  717 	movx	a,@dptr
   0205 FA                  718 	mov	r2,a
                            719 ;	../epl_rf_en.c:131: auto_retr,
   0206 90 80 10            720 	mov	dptr,#_epl_rf_en_easy_start_tx_PARM_2
   0209 E0                  721 	movx	a,@dptr
   020A FB                  722 	mov	r3,a
                            723 ;	../epl_rf_en.c:132: delay,
   020B 90 80 11            724 	mov	dptr,#_epl_rf_en_easy_start_tx_PARM_3
   020E E0                  725 	movx	a,@dptr
   020F FC                  726 	mov	r4,a
   0210 A3                  727 	inc	dptr
   0211 E0                  728 	movx	a,@dptr
   0212 FD                  729 	mov	r5,a
                            730 ;	../epl_rf_en.c:136: RF_EN_INT_DISABLE);
   0213 90 80 00            731 	mov	dptr,#_epl_rf_en_init_PARM_2
   0216 E4                  732 	clr	a
   0217 F0                  733 	movx	@dptr,a
   0218 90 80 01            734 	mov	dptr,#_epl_rf_en_init_PARM_3
   021B 74 03               735 	mov	a,#0x03
   021D F0                  736 	movx	@dptr,a
   021E 90 80 02            737 	mov	dptr,#_epl_rf_en_init_PARM_4
   0221 EB                  738 	mov	a,r3
   0222 F0                  739 	movx	@dptr,a
   0223 90 80 03            740 	mov	dptr,#_epl_rf_en_init_PARM_5
   0226 EC                  741 	mov	a,r4
   0227 F0                  742 	movx	@dptr,a
   0228 A3                  743 	inc	dptr
   0229 ED                  744 	mov	a,r5
   022A F0                  745 	movx	@dptr,a
   022B 90 80 05            746 	mov	dptr,#_epl_rf_en_init_PARM_6
   022E 74 05               747 	mov	a,#0x05
   0230 F0                  748 	movx	@dptr,a
   0231 90 80 06            749 	mov	dptr,#_epl_rf_en_init_PARM_7
   0234 74 03               750 	mov	a,#0x03
   0236 F0                  751 	movx	@dptr,a
   0237 90 80 07            752 	mov	dptr,#_epl_rf_en_init_PARM_8
   023A 74 03               753 	mov	a,#0x03
   023C F0                  754 	movx	@dptr,a
   023D 90 80 08            755 	mov	dptr,#_epl_rf_en_init_PARM_9
   0240 E4                  756 	clr	a
   0241 F0                  757 	movx	@dptr,a
   0242 8A 82               758 	mov	dpl,r2
   0244 C0 03               759 	push	ar3
   0246 12 01 1C            760 	lcall	_epl_rf_en_init
                            761 ;	../epl_rf_en.c:138: epl_rf_en_set_dst_addr(my_tx_dst_addr);
   0249 90 80 14            762 	mov	dptr,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
   024C 75 F0 00            763 	mov	b,#0x00
   024F 12 04 48            764 	lcall	_epl_rf_en_set_dst_addr
   0252 D0 03               765 	pop	ar3
                            766 ;	../epl_rf_en.c:140: if( auto_retr != 0){
   0254 EB                  767 	mov	a,r3
   0255 60 1F               768 	jz	00102$
                            769 ;	../epl_rf_en.c:144: my_tx_dst_addr,
   0257 90 80 0A            770 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   025A 74 14               771 	mov	a,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
   025C F0                  772 	movx	@dptr,a
   025D A3                  773 	inc	dptr
   025E 74 80               774 	mov	a,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 >> 8)
   0260 F0                  775 	movx	@dptr,a
   0261 A3                  776 	inc	dptr
   0262 E4                  777 	clr	a
   0263 F0                  778 	movx	@dptr,a
                            779 ;	../epl_rf_en.c:146: RF_EN_AUTO_ACK_ON
   0264 90 80 0D            780 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   0267 74 20               781 	mov	a,#0x20
   0269 F0                  782 	movx	@dptr,a
   026A 90 80 0E            783 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   026D 74 01               784 	mov	a,#0x01
   026F F0                  785 	movx	@dptr,a
   0270 75 82 00            786 	mov	dpl,#0x00
   0273 12 01 95            787 	lcall	_epl_rf_en_rcv_pipe_config
   0276                     788 00102$:
                            789 ;	../epl_rf_en.c:150: epl_rf_en_enter_tx_mode();
   0276 02 04 38            790 	ljmp	_epl_rf_en_enter_tx_mode
                            791 ;------------------------------------------------------------
                            792 ;Allocation info for local variables in function 'epl_rf_en_easy_start_rx'
                            793 ;------------------------------------------------------------
                            794 ;pload_len                 Allocated with name '_epl_rf_en_easy_start_rx_PARM_2'
                            795 ;auto_ack                  Allocated with name '_epl_rf_en_easy_start_rx_PARM_3'
                            796 ;channel                   Allocated with name '_epl_rf_en_easy_start_rx_channel_1_1'
                            797 ;my_rx_dst_addr            Allocated with name '_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1'
                            798 ;------------------------------------------------------------
                            799 ;	../epl_rf_en.c:161: void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, bool auto_ack){
                            800 ;	-----------------------------------------
                            801 ;	 function epl_rf_en_easy_start_rx
                            802 ;	-----------------------------------------
   0279                     803 _epl_rf_en_easy_start_rx:
   0279 E5 82               804 	mov	a,dpl
   027B 90 80 1B            805 	mov	dptr,#_epl_rf_en_easy_start_rx_channel_1_1
   027E F0                  806 	movx	@dptr,a
                            807 ;	../epl_rf_en.c:163: char my_rx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
   027F 90 80 1C            808 	mov	dptr,#_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1
   0282 74 65               809 	mov	a,#0x65
   0284 F0                  810 	movx	@dptr,a
   0285 90 80 1D            811 	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0001)
   0288 74 65               812 	mov	a,#0x65
   028A F0                  813 	movx	@dptr,a
   028B 90 80 1E            814 	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0002)
   028E 74 65               815 	mov	a,#0x65
   0290 F0                  816 	movx	@dptr,a
   0291 90 80 1F            817 	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0003)
   0294 74 65               818 	mov	a,#0x65
   0296 F0                  819 	movx	@dptr,a
   0297 90 80 20            820 	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0004)
   029A 74 65               821 	mov	a,#0x65
   029C F0                  822 	movx	@dptr,a
                            823 ;	../epl_rf_en.c:166: epl_rf_en_init(channel,
   029D 90 80 1B            824 	mov	dptr,#_epl_rf_en_easy_start_rx_channel_1_1
   02A0 E0                  825 	movx	a,@dptr
   02A1 FA                  826 	mov	r2,a
                            827 ;	../epl_rf_en.c:174: RF_EN_INT_DISABLE);
   02A2 90 80 00            828 	mov	dptr,#_epl_rf_en_init_PARM_2
   02A5 E4                  829 	clr	a
   02A6 F0                  830 	movx	@dptr,a
   02A7 90 80 01            831 	mov	dptr,#_epl_rf_en_init_PARM_3
   02AA 74 03               832 	mov	a,#0x03
   02AC F0                  833 	movx	@dptr,a
   02AD 90 80 02            834 	mov	dptr,#_epl_rf_en_init_PARM_4
   02B0 E4                  835 	clr	a
   02B1 F0                  836 	movx	@dptr,a
   02B2 90 80 03            837 	mov	dptr,#_epl_rf_en_init_PARM_5
   02B5 F0                  838 	movx	@dptr,a
   02B6 A3                  839 	inc	dptr
   02B7 F0                  840 	movx	@dptr,a
   02B8 90 80 05            841 	mov	dptr,#_epl_rf_en_init_PARM_6
   02BB 74 05               842 	mov	a,#0x05
   02BD F0                  843 	movx	@dptr,a
   02BE 90 80 06            844 	mov	dptr,#_epl_rf_en_init_PARM_7
   02C1 74 03               845 	mov	a,#0x03
   02C3 F0                  846 	movx	@dptr,a
   02C4 90 80 07            847 	mov	dptr,#_epl_rf_en_init_PARM_8
   02C7 74 03               848 	mov	a,#0x03
   02C9 F0                  849 	movx	@dptr,a
   02CA 90 80 08            850 	mov	dptr,#_epl_rf_en_init_PARM_9
   02CD E4                  851 	clr	a
   02CE F0                  852 	movx	@dptr,a
   02CF 8A 82               853 	mov	dpl,r2
   02D1 12 01 1C            854 	lcall	_epl_rf_en_init
                            855 ;	../epl_rf_en.c:178: my_rx_dst_addr,
                            856 ;	../epl_rf_en.c:179: pload_len,
   02D4 90 80 19            857 	mov	dptr,#_epl_rf_en_easy_start_rx_PARM_2
   02D7 E0                  858 	movx	a,@dptr
   02D8 FA                  859 	mov	r2,a
                            860 ;	../epl_rf_en.c:180: auto_ack
   02D9 90 80 1A            861 	mov	dptr,#_epl_rf_en_easy_start_rx_PARM_3
   02DC E0                  862 	movx	a,@dptr
   02DD FB                  863 	mov	r3,a
   02DE 90 80 0A            864 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   02E1 74 1C               865 	mov	a,#_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1
   02E3 F0                  866 	movx	@dptr,a
   02E4 A3                  867 	inc	dptr
   02E5 74 80               868 	mov	a,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 >> 8)
   02E7 F0                  869 	movx	@dptr,a
   02E8 A3                  870 	inc	dptr
   02E9 E4                  871 	clr	a
   02EA F0                  872 	movx	@dptr,a
   02EB 90 80 0D            873 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   02EE EA                  874 	mov	a,r2
   02EF F0                  875 	movx	@dptr,a
   02F0 90 80 0E            876 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   02F3 EB                  877 	mov	a,r3
   02F4 F0                  878 	movx	@dptr,a
   02F5 75 82 00            879 	mov	dpl,#0x00
   02F8 12 01 95            880 	lcall	_epl_rf_en_rcv_pipe_config
                            881 ;	../epl_rf_en.c:183: epl_rf_en_enter_rx_mode();
   02FB 02 04 40            882 	ljmp	_epl_rf_en_enter_rx_mode
                            883 ;------------------------------------------------------------
                            884 ;Allocation info for local variables in function 'epl_rf_en_quick_init'
                            885 ;------------------------------------------------------------
                            886 ;sloc0                     Allocated with name '_epl_rf_en_quick_init_sloc0_1_0'
                            887 ;sloc1                     Allocated with name '_epl_rf_en_quick_init_sloc1_1_0'
                            888 ;sloc2                     Allocated with name '_epl_rf_en_quick_init_sloc2_1_0'
                            889 ;sloc3                     Allocated with name '_epl_rf_en_quick_init_sloc3_1_0'
                            890 ;sloc4                     Allocated with name '_epl_rf_en_quick_init_sloc4_1_0'
                            891 ;in_cfg                    Allocated with name '_epl_rf_en_quick_init_in_cfg_1_1'
                            892 ;------------------------------------------------------------
                            893 ;	../epl_rf_en.c:193: void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg)
                            894 ;	-----------------------------------------
                            895 ;	 function epl_rf_en_quick_init
                            896 ;	-----------------------------------------
   02FE                     897 _epl_rf_en_quick_init:
   02FE AA F0               898 	mov	r2,b
   0300 AB 83               899 	mov	r3,dph
   0302 E5 82               900 	mov	a,dpl
   0304 90 80 21            901 	mov	dptr,#_epl_rf_en_quick_init_in_cfg_1_1
   0307 F0                  902 	movx	@dptr,a
   0308 A3                  903 	inc	dptr
   0309 EB                  904 	mov	a,r3
   030A F0                  905 	movx	@dptr,a
   030B A3                  906 	inc	dptr
   030C EA                  907 	mov	a,r2
   030D F0                  908 	movx	@dptr,a
                            909 ;	../epl_rf_en.c:197: epl_rf_en_init(in_cfg->channel,
   030E 90 80 21            910 	mov	dptr,#_epl_rf_en_quick_init_in_cfg_1_1
   0311 E0                  911 	movx	a,@dptr
   0312 FA                  912 	mov	r2,a
   0313 A3                  913 	inc	dptr
   0314 E0                  914 	movx	a,@dptr
   0315 FB                  915 	mov	r3,a
   0316 A3                  916 	inc	dptr
   0317 E0                  917 	movx	a,@dptr
   0318 FC                  918 	mov	r4,a
   0319 8A 82               919 	mov	dpl,r2
   031B 8B 83               920 	mov	dph,r3
   031D 8C F0               921 	mov	b,r4
   031F 12 33 F7            922 	lcall	__gptrget
   0322 F5 0A               923 	mov	_epl_rf_en_quick_init_sloc2_1_0,a
                            924 ;	../epl_rf_en.c:198: in_cfg->datarate,
   0324 74 0D               925 	mov	a,#0x0D
   0326 2A                  926 	add	a,r2
   0327 FE                  927 	mov	r6,a
   0328 E4                  928 	clr	a
   0329 3B                  929 	addc	a,r3
   032A FF                  930 	mov	r7,a
   032B 8C 00               931 	mov	ar0,r4
   032D 8E 82               932 	mov	dpl,r6
   032F 8F 83               933 	mov	dph,r7
   0331 88 F0               934 	mov	b,r0
   0333 12 33 F7            935 	lcall	__gptrget
   0336 F5 09               936 	mov	_epl_rf_en_quick_init_sloc1_1_0,a
                            937 ;	../epl_rf_en.c:200: in_cfg->auto_retr,
   0338 74 10               938 	mov	a,#0x10
   033A 2A                  939 	add	a,r2
   033B FF                  940 	mov	r7,a
   033C E4                  941 	clr	a
   033D 3B                  942 	addc	a,r3
   033E F8                  943 	mov	r0,a
   033F 8C 01               944 	mov	ar1,r4
   0341 8F 82               945 	mov	dpl,r7
   0343 88 83               946 	mov	dph,r0
   0345 89 F0               947 	mov	b,r1
   0347 12 33 F7            948 	lcall	__gptrget
   034A F5 08               949 	mov	_epl_rf_en_quick_init_sloc0_1_0,a
                            950 ;	../epl_rf_en.c:201: in_cfg->auto_retr_delay,
   034C 74 11               951 	mov	a,#0x11
   034E 2A                  952 	add	a,r2
   034F F8                  953 	mov	r0,a
   0350 E4                  954 	clr	a
   0351 3B                  955 	addc	a,r3
   0352 F9                  956 	mov	r1,a
   0353 8C 07               957 	mov	ar7,r4
   0355 88 82               958 	mov	dpl,r0
   0357 89 83               959 	mov	dph,r1
   0359 8F F0               960 	mov	b,r7
   035B 12 33 F7            961 	lcall	__gptrget
   035E F8                  962 	mov	r0,a
   035F A3                  963 	inc	dptr
   0360 12 33 F7            964 	lcall	__gptrget
   0363 F9                  965 	mov	r1,a
                            966 ;	../epl_rf_en.c:202: in_cfg->addr_width,
   0364 74 01               967 	mov	a,#0x01
   0366 2A                  968 	add	a,r2
   0367 FF                  969 	mov	r7,a
   0368 E4                  970 	clr	a
   0369 3B                  971 	addc	a,r3
   036A FE                  972 	mov	r6,a
   036B 8C 05               973 	mov	ar5,r4
   036D 8F 82               974 	mov	dpl,r7
   036F 8E 83               975 	mov	dph,r6
   0371 8D F0               976 	mov	b,r5
   0373 12 33 F7            977 	lcall	__gptrget
   0376 F5 0B               978 	mov	_epl_rf_en_quick_init_sloc3_1_0,a
                            979 ;	../epl_rf_en.c:203: in_cfg->crc_mode,
   0378 74 0E               980 	mov	a,#0x0E
   037A 2A                  981 	add	a,r2
   037B FD                  982 	mov	r5,a
   037C E4                  983 	clr	a
   037D 3B                  984 	addc	a,r3
   037E FE                  985 	mov	r6,a
   037F 8C 07               986 	mov	ar7,r4
   0381 8D 82               987 	mov	dpl,r5
   0383 8E 83               988 	mov	dph,r6
   0385 8F F0               989 	mov	b,r7
   0387 12 33 F7            990 	lcall	__gptrget
   038A FD                  991 	mov	r5,a
                            992 ;	../epl_rf_en.c:205: RF_EN_INT_DISABLE);
   038B 90 80 00            993 	mov	dptr,#_epl_rf_en_init_PARM_2
   038E E5 09               994 	mov	a,_epl_rf_en_quick_init_sloc1_1_0
   0390 F0                  995 	movx	@dptr,a
   0391 90 80 01            996 	mov	dptr,#_epl_rf_en_init_PARM_3
   0394 74 03               997 	mov	a,#0x03
   0396 F0                  998 	movx	@dptr,a
   0397 90 80 02            999 	mov	dptr,#_epl_rf_en_init_PARM_4
   039A E5 08              1000 	mov	a,_epl_rf_en_quick_init_sloc0_1_0
   039C F0                 1001 	movx	@dptr,a
   039D 90 80 03           1002 	mov	dptr,#_epl_rf_en_init_PARM_5
   03A0 E8                 1003 	mov	a,r0
   03A1 F0                 1004 	movx	@dptr,a
   03A2 A3                 1005 	inc	dptr
   03A3 E9                 1006 	mov	a,r1
   03A4 F0                 1007 	movx	@dptr,a
   03A5 90 80 05           1008 	mov	dptr,#_epl_rf_en_init_PARM_6
   03A8 E5 0B              1009 	mov	a,_epl_rf_en_quick_init_sloc3_1_0
   03AA F0                 1010 	movx	@dptr,a
   03AB 90 80 06           1011 	mov	dptr,#_epl_rf_en_init_PARM_7
   03AE ED                 1012 	mov	a,r5
   03AF F0                 1013 	movx	@dptr,a
   03B0 90 80 07           1014 	mov	dptr,#_epl_rf_en_init_PARM_8
   03B3 74 03              1015 	mov	a,#0x03
   03B5 F0                 1016 	movx	@dptr,a
   03B6 90 80 08           1017 	mov	dptr,#_epl_rf_en_init_PARM_9
   03B9 E4                 1018 	clr	a
   03BA F0                 1019 	movx	@dptr,a
   03BB 85 0A 82           1020 	mov	dpl,_epl_rf_en_quick_init_sloc2_1_0
   03BE C0 02              1021 	push	ar2
   03C0 C0 03              1022 	push	ar3
   03C2 C0 04              1023 	push	ar4
   03C4 12 01 1C           1024 	lcall	_epl_rf_en_init
   03C7 D0 04              1025 	pop	ar4
   03C9 D0 03              1026 	pop	ar3
   03CB D0 02              1027 	pop	ar2
                           1028 ;	../epl_rf_en.c:207: epl_rf_en_set_dst_addr(in_cfg->my_tx_dst_addr);
   03CD 74 02              1029 	mov	a,#0x02
   03CF 2A                 1030 	add	a,r2
   03D0 FD                 1031 	mov	r5,a
   03D1 E4                 1032 	clr	a
   03D2 3B                 1033 	addc	a,r3
   03D3 FE                 1034 	mov	r6,a
   03D4 8C 07              1035 	mov	ar7,r4
   03D6 8D 82              1036 	mov	dpl,r5
   03D8 8E 83              1037 	mov	dph,r6
   03DA 8F F0              1038 	mov	b,r7
   03DC C0 02              1039 	push	ar2
   03DE C0 03              1040 	push	ar3
   03E0 C0 04              1041 	push	ar4
   03E2 12 04 48           1042 	lcall	_epl_rf_en_set_dst_addr
   03E5 D0 04              1043 	pop	ar4
   03E7 D0 03              1044 	pop	ar3
   03E9 D0 02              1045 	pop	ar2
                           1046 ;	../epl_rf_en.c:212: in_cfg->my_prx_addr,
   03EB 74 07              1047 	mov	a,#0x07
   03ED 2A                 1048 	add	a,r2
   03EE F5 0C              1049 	mov	_epl_rf_en_quick_init_sloc4_1_0,a
   03F0 E4                 1050 	clr	a
   03F1 3B                 1051 	addc	a,r3
   03F2 F5 0D              1052 	mov	(_epl_rf_en_quick_init_sloc4_1_0 + 1),a
   03F4 8C 0E              1053 	mov	(_epl_rf_en_quick_init_sloc4_1_0 + 2),r4
                           1054 ;	../epl_rf_en.c:213: in_cfg->data_length,
   03F6 74 0C              1055 	mov	a,#0x0C
   03F8 2A                 1056 	add	a,r2
   03F9 F8                 1057 	mov	r0,a
   03FA E4                 1058 	clr	a
   03FB 3B                 1059 	addc	a,r3
   03FC F9                 1060 	mov	r1,a
   03FD 8C 05              1061 	mov	ar5,r4
   03FF 88 82              1062 	mov	dpl,r0
   0401 89 83              1063 	mov	dph,r1
   0403 8D F0              1064 	mov	b,r5
   0405 12 33 F7           1065 	lcall	__gptrget
   0408 F8                 1066 	mov	r0,a
                           1067 ;	../epl_rf_en.c:214: in_cfg->auto_ack
   0409 74 0F              1068 	mov	a,#0x0F
   040B 2A                 1069 	add	a,r2
   040C FA                 1070 	mov	r2,a
   040D E4                 1071 	clr	a
   040E 3B                 1072 	addc	a,r3
   040F FB                 1073 	mov	r3,a
   0410 8A 82              1074 	mov	dpl,r2
   0412 8B 83              1075 	mov	dph,r3
   0414 8C F0              1076 	mov	b,r4
   0416 12 33 F7           1077 	lcall	__gptrget
   0419 FA                 1078 	mov	r2,a
   041A 90 80 0A           1079 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   041D E5 0C              1080 	mov	a,_epl_rf_en_quick_init_sloc4_1_0
   041F F0                 1081 	movx	@dptr,a
   0420 A3                 1082 	inc	dptr
   0421 E5 0D              1083 	mov	a,(_epl_rf_en_quick_init_sloc4_1_0 + 1)
   0423 F0                 1084 	movx	@dptr,a
   0424 A3                 1085 	inc	dptr
   0425 E5 0E              1086 	mov	a,(_epl_rf_en_quick_init_sloc4_1_0 + 2)
   0427 F0                 1087 	movx	@dptr,a
   0428 90 80 0D           1088 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   042B E8                 1089 	mov	a,r0
   042C F0                 1090 	movx	@dptr,a
   042D 90 80 0E           1091 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   0430 EA                 1092 	mov	a,r2
   0431 F0                 1093 	movx	@dptr,a
   0432 75 82 00           1094 	mov	dpl,#0x00
   0435 02 01 95           1095 	ljmp	_epl_rf_en_rcv_pipe_config
                           1096 ;------------------------------------------------------------
                           1097 ;Allocation info for local variables in function 'epl_rf_en_enter_tx_mode'
                           1098 ;------------------------------------------------------------
                           1099 ;------------------------------------------------------------
                           1100 ;	../epl_rf_en.c:221: void epl_rf_en_enter_tx_mode(void)
                           1101 ;	-----------------------------------------
                           1102 ;	 function epl_rf_en_enter_tx_mode
                           1103 ;	-----------------------------------------
   0438                    1104 _epl_rf_en_enter_tx_mode:
                           1105 ;	../epl_rf_en.c:223: RFCE = 0;
   0438 C2 90              1106 	clr	_RFCE
                           1107 ;	../epl_rf_en.c:224: hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode
   043A 75 82 00           1108 	mov	dpl,#0x00
   043D 02 11 A8           1109 	ljmp	_hal_nrf_set_operation_mode
                           1110 ;------------------------------------------------------------
                           1111 ;Allocation info for local variables in function 'epl_rf_en_enter_rx_mode'
                           1112 ;------------------------------------------------------------
                           1113 ;------------------------------------------------------------
                           1114 ;	../epl_rf_en.c:230: void epl_rf_en_enter_rx_mode(void)
                           1115 ;	-----------------------------------------
                           1116 ;	 function epl_rf_en_enter_rx_mode
                           1117 ;	-----------------------------------------
   0440                    1118 _epl_rf_en_enter_rx_mode:
                           1119 ;	../epl_rf_en.c:232: RFCE = 1;
   0440 D2 90              1120 	setb	_RFCE
                           1121 ;	../epl_rf_en.c:233: hal_nrf_set_operation_mode(HAL_NRF_PRX); // Enter RF RX mode
   0442 75 82 01           1122 	mov	dpl,#0x01
   0445 02 11 A8           1123 	ljmp	_hal_nrf_set_operation_mode
                           1124 ;------------------------------------------------------------
                           1125 ;Allocation info for local variables in function 'epl_rf_en_set_dst_addr'
                           1126 ;------------------------------------------------------------
                           1127 ;in_dst_addr               Allocated with name '_epl_rf_en_set_dst_addr_in_dst_addr_1_1'
                           1128 ;------------------------------------------------------------
                           1129 ;	../epl_rf_en.c:241: void epl_rf_en_set_dst_addr(uint8_t *in_dst_addr)
                           1130 ;	-----------------------------------------
                           1131 ;	 function epl_rf_en_set_dst_addr
                           1132 ;	-----------------------------------------
   0448                    1133 _epl_rf_en_set_dst_addr:
   0448 AA F0              1134 	mov	r2,b
   044A AB 83              1135 	mov	r3,dph
   044C E5 82              1136 	mov	a,dpl
   044E 90 80 24           1137 	mov	dptr,#_epl_rf_en_set_dst_addr_in_dst_addr_1_1
   0451 F0                 1138 	movx	@dptr,a
   0452 A3                 1139 	inc	dptr
   0453 EB                 1140 	mov	a,r3
   0454 F0                 1141 	movx	@dptr,a
   0455 A3                 1142 	inc	dptr
   0456 EA                 1143 	mov	a,r2
   0457 F0                 1144 	movx	@dptr,a
                           1145 ;	../epl_rf_en.c:243: hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
   0458 90 80 24           1146 	mov	dptr,#_epl_rf_en_set_dst_addr_in_dst_addr_1_1
   045B E0                 1147 	movx	a,@dptr
   045C FA                 1148 	mov	r2,a
   045D A3                 1149 	inc	dptr
   045E E0                 1150 	movx	a,@dptr
   045F FB                 1151 	mov	r3,a
   0460 A3                 1152 	inc	dptr
   0461 E0                 1153 	movx	a,@dptr
   0462 FC                 1154 	mov	r4,a
   0463 90 80 EB           1155 	mov	dptr,#_hal_nrf_set_address_PARM_2
   0466 EA                 1156 	mov	a,r2
   0467 F0                 1157 	movx	@dptr,a
   0468 A3                 1158 	inc	dptr
   0469 EB                 1159 	mov	a,r3
   046A F0                 1160 	movx	@dptr,a
   046B A3                 1161 	inc	dptr
   046C EC                 1162 	mov	a,r4
   046D F0                 1163 	movx	@dptr,a
   046E 75 82 06           1164 	mov	dpl,#0x06
   0471 02 0F C7           1165 	ljmp	_hal_nrf_set_address
                           1166 ;------------------------------------------------------------
                           1167 ;Allocation info for local variables in function 'epl_rf_en_send_dst'
                           1168 ;------------------------------------------------------------
                           1169 ;in_tx_pload               Allocated with name '_epl_rf_en_send_dst_PARM_2'
                           1170 ;in_pload_length           Allocated with name '_epl_rf_en_send_dst_PARM_3'
                           1171 ;in_dst_addr               Allocated with name '_epl_rf_en_send_dst_in_dst_addr_1_1'
                           1172 ;count                     Allocated with name '_epl_rf_en_send_dst_count_2_2'
                           1173 ;------------------------------------------------------------
                           1174 ;	../epl_rf_en.c:253: void epl_rf_en_send_dst(uint8_t *in_dst_addr, uint8_t *in_tx_pload, uint8_t in_pload_length)
                           1175 ;	-----------------------------------------
                           1176 ;	 function epl_rf_en_send_dst
                           1177 ;	-----------------------------------------
   0474                    1178 _epl_rf_en_send_dst:
   0474 AA F0              1179 	mov	r2,b
   0476 AB 83              1180 	mov	r3,dph
   0478 E5 82              1181 	mov	a,dpl
   047A 90 80 2B           1182 	mov	dptr,#_epl_rf_en_send_dst_in_dst_addr_1_1
   047D F0                 1183 	movx	@dptr,a
   047E A3                 1184 	inc	dptr
   047F EB                 1185 	mov	a,r3
   0480 F0                 1186 	movx	@dptr,a
   0481 A3                 1187 	inc	dptr
   0482 EA                 1188 	mov	a,r2
   0483 F0                 1189 	movx	@dptr,a
                           1190 ;	../epl_rf_en.c:255: hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
   0484 90 80 2B           1191 	mov	dptr,#_epl_rf_en_send_dst_in_dst_addr_1_1
   0487 E0                 1192 	movx	a,@dptr
   0488 FA                 1193 	mov	r2,a
   0489 A3                 1194 	inc	dptr
   048A E0                 1195 	movx	a,@dptr
   048B FB                 1196 	mov	r3,a
   048C A3                 1197 	inc	dptr
   048D E0                 1198 	movx	a,@dptr
   048E FC                 1199 	mov	r4,a
   048F 90 80 EB           1200 	mov	dptr,#_hal_nrf_set_address_PARM_2
   0492 EA                 1201 	mov	a,r2
   0493 F0                 1202 	movx	@dptr,a
   0494 A3                 1203 	inc	dptr
   0495 EB                 1204 	mov	a,r3
   0496 F0                 1205 	movx	@dptr,a
   0497 A3                 1206 	inc	dptr
   0498 EC                 1207 	mov	a,r4
   0499 F0                 1208 	movx	@dptr,a
   049A 75 82 06           1209 	mov	dpl,#0x06
   049D 12 0F C7           1210 	lcall	_hal_nrf_set_address
                           1211 ;	../epl_rf_en.c:256: epl_rf_en_enter_tx_mode();
   04A0 12 04 38           1212 	lcall	_epl_rf_en_enter_tx_mode
                           1213 ;	../epl_rf_en.c:257: hal_nrf_write_tx_pload(in_tx_pload, in_pload_length);
   04A3 90 80 27           1214 	mov	dptr,#_epl_rf_en_send_dst_PARM_2
   04A6 E0                 1215 	movx	a,@dptr
   04A7 FA                 1216 	mov	r2,a
   04A8 A3                 1217 	inc	dptr
   04A9 E0                 1218 	movx	a,@dptr
   04AA FB                 1219 	mov	r3,a
   04AB A3                 1220 	inc	dptr
   04AC E0                 1221 	movx	a,@dptr
   04AD FC                 1222 	mov	r4,a
   04AE 90 80 2A           1223 	mov	dptr,#_epl_rf_en_send_dst_PARM_3
   04B1 E0                 1224 	movx	a,@dptr
   04B2 90 81 00           1225 	mov	dptr,#_hal_nrf_write_tx_pload_PARM_2
   04B5 F0                 1226 	movx	@dptr,a
   04B6 8A 82              1227 	mov	dpl,r2
   04B8 8B 83              1228 	mov	dph,r3
   04BA 8C F0              1229 	mov	b,r4
   04BC 12 13 46           1230 	lcall	_hal_nrf_write_tx_pload
                           1231 ;	../epl_rf_en.c:258: CE_PULSE();
   04BF D2 90              1232 	setb	_RFCE
   04C1 7A 14              1233 	mov	r2,#0x14
   04C3                    1234 00104$:
   04C3 8A 03              1235 	mov	ar3,r2
   04C5 1A                 1236 	dec	r2
   04C6 EB                 1237 	mov	a,r3
   04C7 70 FA              1238 	jnz	00104$
   04C9 C2 90              1239 	clr	_RFCE
   04CB 22                 1240 	ret
                           1241 ;------------------------------------------------------------
                           1242 ;Allocation info for local variables in function 'epl_rf_en_send'
                           1243 ;------------------------------------------------------------
                           1244 ;in_pload_length           Allocated with name '_epl_rf_en_send_PARM_2'
                           1245 ;in_tx_pload               Allocated with name '_epl_rf_en_send_in_tx_pload_1_1'
                           1246 ;count                     Allocated with name '_epl_rf_en_send_count_2_2'
                           1247 ;------------------------------------------------------------
                           1248 ;	../epl_rf_en.c:268: void epl_rf_en_send(uint8_t *in_tx_pload, uint8_t in_pload_length)
                           1249 ;	-----------------------------------------
                           1250 ;	 function epl_rf_en_send
                           1251 ;	-----------------------------------------
   04CC                    1252 _epl_rf_en_send:
   04CC AA F0              1253 	mov	r2,b
   04CE AB 83              1254 	mov	r3,dph
   04D0 E5 82              1255 	mov	a,dpl
   04D2 90 80 2F           1256 	mov	dptr,#_epl_rf_en_send_in_tx_pload_1_1
   04D5 F0                 1257 	movx	@dptr,a
   04D6 A3                 1258 	inc	dptr
   04D7 EB                 1259 	mov	a,r3
   04D8 F0                 1260 	movx	@dptr,a
   04D9 A3                 1261 	inc	dptr
   04DA EA                 1262 	mov	a,r2
   04DB F0                 1263 	movx	@dptr,a
                           1264 ;	../epl_rf_en.c:270: epl_rf_en_enter_tx_mode();
   04DC 12 04 38           1265 	lcall	_epl_rf_en_enter_tx_mode
                           1266 ;	../epl_rf_en.c:271: hal_nrf_write_tx_pload(in_tx_pload, in_pload_length);
   04DF 90 80 2F           1267 	mov	dptr,#_epl_rf_en_send_in_tx_pload_1_1
   04E2 E0                 1268 	movx	a,@dptr
   04E3 FA                 1269 	mov	r2,a
   04E4 A3                 1270 	inc	dptr
   04E5 E0                 1271 	movx	a,@dptr
   04E6 FB                 1272 	mov	r3,a
   04E7 A3                 1273 	inc	dptr
   04E8 E0                 1274 	movx	a,@dptr
   04E9 FC                 1275 	mov	r4,a
   04EA 90 80 2E           1276 	mov	dptr,#_epl_rf_en_send_PARM_2
   04ED E0                 1277 	movx	a,@dptr
   04EE 90 81 00           1278 	mov	dptr,#_hal_nrf_write_tx_pload_PARM_2
   04F1 F0                 1279 	movx	@dptr,a
   04F2 8A 82              1280 	mov	dpl,r2
   04F4 8B 83              1281 	mov	dph,r3
   04F6 8C F0              1282 	mov	b,r4
   04F8 12 13 46           1283 	lcall	_hal_nrf_write_tx_pload
                           1284 ;	../epl_rf_en.c:272: CE_PULSE();
   04FB D2 90              1285 	setb	_RFCE
   04FD 7A 14              1286 	mov	r2,#0x14
   04FF                    1287 00104$:
   04FF 8A 03              1288 	mov	ar3,r2
   0501 1A                 1289 	dec	r2
   0502 EB                 1290 	mov	a,r3
   0503 70 FA              1291 	jnz	00104$
   0505 C2 90              1292 	clr	_RFCE
   0507 22                 1293 	ret
                           1294 ;------------------------------------------------------------
                           1295 ;Allocation info for local variables in function 'epl_rf_en_rx_pload_is_empty'
                           1296 ;------------------------------------------------------------
                           1297 ;rx_fifo_status            Allocated with name '_epl_rf_en_rx_pload_is_empty_rx_fifo_status_1_1'
                           1298 ;------------------------------------------------------------
                           1299 ;	../epl_rf_en.c:281: bool epl_rf_en_rx_pload_is_empty(void)
                           1300 ;	-----------------------------------------
                           1301 ;	 function epl_rf_en_rx_pload_is_empty
                           1302 ;	-----------------------------------------
   0508                    1303 _epl_rf_en_rx_pload_is_empty:
                           1304 ;	../epl_rf_en.c:284: rx_fifo_status = hal_nrf_get_rx_fifo_status();
   0508 12 13 19           1305 	lcall	_hal_nrf_get_rx_fifo_status
   050B AA 82              1306 	mov	r2,dpl
                           1307 ;	../epl_rf_en.c:285: if (rx_fifo_status == 0x01)
   050D BA 01 04           1308 	cjne	r2,#0x01,00102$
                           1309 ;	../epl_rf_en.c:287: return 1;	// RX fifo is empty.
   0510 75 82 01           1310 	mov	dpl,#0x01
                           1311 ;	../epl_rf_en.c:291: return 0;	// RX fifo is not empty or is full.
   0513 22                 1312 	ret
   0514                    1313 00102$:
   0514 75 82 00           1314 	mov	dpl,#0x00
   0517 22                 1315 	ret
                           1316 ;------------------------------------------------------------
                           1317 ;Allocation info for local variables in function 'epl_rf_en_read_rx_pload'
                           1318 ;------------------------------------------------------------
                           1319 ;out_rx_pload              Allocated with name '_epl_rf_en_read_rx_pload_out_rx_pload_1_1'
                           1320 ;------------------------------------------------------------
                           1321 ;	../epl_rf_en.c:300: void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload)
                           1322 ;	-----------------------------------------
                           1323 ;	 function epl_rf_en_read_rx_pload
                           1324 ;	-----------------------------------------
   0518                    1325 _epl_rf_en_read_rx_pload:
   0518 AA F0              1326 	mov	r2,b
   051A AB 83              1327 	mov	r3,dph
   051C E5 82              1328 	mov	a,dpl
   051E 90 80 32           1329 	mov	dptr,#_epl_rf_en_read_rx_pload_out_rx_pload_1_1
   0521 F0                 1330 	movx	@dptr,a
   0522 A3                 1331 	inc	dptr
   0523 EB                 1332 	mov	a,r3
   0524 F0                 1333 	movx	@dptr,a
   0525 A3                 1334 	inc	dptr
   0526 EA                 1335 	mov	a,r2
   0527 F0                 1336 	movx	@dptr,a
                           1337 ;	../epl_rf_en.c:302: hal_nrf_read_rx_pload(out_rx_pload);
   0528 90 80 32           1338 	mov	dptr,#_epl_rf_en_read_rx_pload_out_rx_pload_1_1
   052B E0                 1339 	movx	a,@dptr
   052C FA                 1340 	mov	r2,a
   052D A3                 1341 	inc	dptr
   052E E0                 1342 	movx	a,@dptr
   052F FB                 1343 	mov	r3,a
   0530 A3                 1344 	inc	dptr
   0531 E0                 1345 	movx	a,@dptr
   0532 FC                 1346 	mov	r4,a
   0533 8A 82              1347 	mov	dpl,r2
   0535 8B 83              1348 	mov	dph,r3
   0537 8C F0              1349 	mov	b,r4
   0539 02 14 9E           1350 	ljmp	_hal_nrf_read_rx_pload
                           1351 ;------------------------------------------------------------
                           1352 ;Allocation info for local variables in function 'epl_rf_en_wait_rcv_msg'
                           1353 ;------------------------------------------------------------
                           1354 ;out_rx_pload              Allocated with name '_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1'
                           1355 ;------------------------------------------------------------
                           1356 ;	../epl_rf_en.c:312: void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload)
                           1357 ;	-----------------------------------------
                           1358 ;	 function epl_rf_en_wait_rcv_msg
                           1359 ;	-----------------------------------------
   053C                    1360 _epl_rf_en_wait_rcv_msg:
   053C AA F0              1361 	mov	r2,b
   053E AB 83              1362 	mov	r3,dph
   0540 E5 82              1363 	mov	a,dpl
   0542 90 80 35           1364 	mov	dptr,#_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1
   0545 F0                 1365 	movx	@dptr,a
   0546 A3                 1366 	inc	dptr
   0547 EB                 1367 	mov	a,r3
   0548 F0                 1368 	movx	@dptr,a
   0549 A3                 1369 	inc	dptr
   054A EA                 1370 	mov	a,r2
   054B F0                 1371 	movx	@dptr,a
                           1372 ;	../epl_rf_en.c:314: epl_rf_en_enter_rx_mode();
   054C 12 04 40           1373 	lcall	_epl_rf_en_enter_rx_mode
                           1374 ;	../epl_rf_en.c:315: while (epl_rf_en_rx_pload_is_empty());
   054F                    1375 00101$:
   054F 12 05 08           1376 	lcall	_epl_rf_en_rx_pload_is_empty
   0552 E5 82              1377 	mov	a,dpl
   0554 70 F9              1378 	jnz	00101$
                           1379 ;	../epl_rf_en.c:316: hal_nrf_read_rx_pload(out_rx_pload);
   0556 90 80 35           1380 	mov	dptr,#_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1
   0559 E0                 1381 	movx	a,@dptr
   055A FA                 1382 	mov	r2,a
   055B A3                 1383 	inc	dptr
   055C E0                 1384 	movx	a,@dptr
   055D FB                 1385 	mov	r3,a
   055E A3                 1386 	inc	dptr
   055F E0                 1387 	movx	a,@dptr
   0560 FC                 1388 	mov	r4,a
   0561 8A 82              1389 	mov	dpl,r2
   0563 8B 83              1390 	mov	dph,r3
   0565 8C F0              1391 	mov	b,r4
   0567 02 14 9E           1392 	ljmp	_hal_nrf_read_rx_pload
                           1393 	.area CSEG    (CODE)
                           1394 	.area CONST   (CODE)
                           1395 	.area XINIT   (CODE)
                           1396 	.area CABS    (ABS,CODE)
