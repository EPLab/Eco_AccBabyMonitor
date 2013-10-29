                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Fri Nov 19 19:41:12 2010
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mmcs51 --model-large
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _DECR
                             14 	.globl _GO
                             15 	.globl _BD
                             16 	.globl _RFCKEN
                             17 	.globl _RFCSN
                             18 	.globl _RFCE
                             19 	.globl _P05
                             20 	.globl _P04
                             21 	.globl _SCSN
                             22 	.globl _MCSN
                             23 	.globl _P03
                             24 	.globl _P02
                             25 	.globl _P01
                             26 	.globl _P00
                             27 	.globl _IV0
                             28 	.globl _IV1
                             29 	.globl _IV2
                             30 	.globl _IV3
                             31 	.globl _IV4
                             32 	.globl _SUSPEND
                             33 	.globl _WU
                             34 	.globl _SWRST
                             35 	.globl _RFSPIF
                             36 	.globl _RFF
                             37 	.globl _SPIF
                             38 	.globl _USBWUF
                             39 	.globl _USBF
                             40 	.globl _WUF
                             41 	.globl _TF2
                             42 	.globl _EXF2
                             43 	.globl _RFSPI
                             44 	.globl _RF
                             45 	.globl _SPI
                             46 	.globl _USBWU
                             47 	.globl _USB
                             48 	.globl _WUIRQ
                             49 	.globl _EXEN2
                             50 	.globl _EX0
                             51 	.globl _ET0
                             52 	.globl _EX1
                             53 	.globl _ET1
                             54 	.globl _ES0
                             55 	.globl _ET2
                             56 	.globl _EA
                             57 	.globl _T2I0
                             58 	.globl _T2I1
                             59 	.globl _T2CM
                             60 	.globl _T2R0
                             61 	.globl _T2R1
                             62 	.globl _I2FR
                             63 	.globl _I3FR
                             64 	.globl _T2PS
                             65 	.globl _RI0
                             66 	.globl _TI0
                             67 	.globl _RB80
                             68 	.globl _TB80
                             69 	.globl _REN0
                             70 	.globl _SM20
                             71 	.globl _SM1
                             72 	.globl _SM0
                             73 	.globl _IT0
                             74 	.globl _IE0
                             75 	.globl _IT1
                             76 	.globl _IE1
                             77 	.globl _TR0
                             78 	.globl _TF0
                             79 	.globl _TR1
                             80 	.globl _TF1
                             81 	.globl _P
                             82 	.globl _F1
                             83 	.globl _OV
                             84 	.globl _RS0
                             85 	.globl _RS1
                             86 	.globl _F0
                             87 	.globl _AC
                             88 	.globl _CY
                             89 	.globl _WPEN
                             90 	.globl _RDEND
                             91 	.globl _RDIS
                             92 	.globl _INFEN
                             93 	.globl _RDYN
                             94 	.globl _WEN
                             95 	.globl _STP
                             96 	.globl _MCDIS
                             97 	.globl _T2
                             98 	.globl _CRC
                             99 	.globl _CC3
                            100 	.globl _CC2
                            101 	.globl _CC1
                            102 	.globl _FCR
                            103 	.globl _FPCR
                            104 	.globl _FSR
                            105 	.globl _AESIA2
                            106 	.globl _AESIA1
                            107 	.globl _AESD
                            108 	.globl _AESIV
                            109 	.globl _AESKIN
                            110 	.globl _B
                            111 	.globl _ARCON
                            112 	.globl _MD5
                            113 	.globl _MD4
                            114 	.globl _MD3
                            115 	.globl _MD2
                            116 	.globl _MD1
                            117 	.globl _MD0
                            118 	.globl _AESCS
                            119 	.globl _RFCTL
                            120 	.globl _RFDAT
                            121 	.globl _ACC
                            122 	.globl _USBSLP
                            123 	.globl _WDCON
                            124 	.globl _PSW
                            125 	.globl _TH2
                            126 	.globl _TL2
                            127 	.globl _CRCH
                            128 	.globl _CRCL
                            129 	.globl _P0EXP
                            130 	.globl _T2CON
                            131 	.globl _CCH3
                            132 	.globl _CCL3
                            133 	.globl _CCH2
                            134 	.globl _CCL2
                            135 	.globl _CCH1
                            136 	.globl _CCL1
                            137 	.globl _CCEN
                            138 	.globl _IRCON
                            139 	.globl _SSSTAT
                            140 	.globl _SSDATA
                            141 	.globl _SSCONF
                            142 	.globl _S0RELH
                            143 	.globl _IP1
                            144 	.globl _IEN1
                            145 	.globl _TICKDV
                            146 	.globl _SMCTL
                            147 	.globl _SMDAT
                            148 	.globl _RSTRES
                            149 	.globl _REGXC
                            150 	.globl _REGXL
                            151 	.globl _REGXH
                            152 	.globl _S0RELL
                            153 	.globl _IP0
                            154 	.globl _IEN0
                            155 	.globl _INTEXP
                            156 	.globl _WUCONF
                            157 	.globl _PWRDWN
                            158 	.globl _CLKCTL
                            159 	.globl _USBCON
                            160 	.globl _IEN2
                            161 	.globl _S0BUF
                            162 	.globl _S0CON
                            163 	.globl _P0ALT
                            164 	.globl _P0DIR
                            165 	.globl _DPS
                            166 	.globl _RFCON
                            167 	.globl _CKCON
                            168 	.globl _TH1
                            169 	.globl _TH0
                            170 	.globl _TL1
                            171 	.globl _TL0
                            172 	.globl _TMOD
                            173 	.globl _TCON
                            174 	.globl _PCON
                            175 	.globl _DPH1
                            176 	.globl _DPL1
                            177 	.globl _DPH
                            178 	.globl _DPL
                            179 	.globl _SP
                            180 	.globl _P0
                            181 	.globl _array_cp_PARM_3
                            182 	.globl _array_cp_PARM_2
                            183 	.globl _packet
                            184 	.globl _usize
                            185 	.globl _ubuf
                            186 	.globl _cfg
                            187 	.globl _rf_cfg_data
                            188 	.globl _array_cp
                            189 ;--------------------------------------------------------
                            190 ; special function registers
                            191 ;--------------------------------------------------------
                            192 	.area RSEG    (DATA)
                    0080    193 _P0	=	0x0080
                    0081    194 _SP	=	0x0081
                    0082    195 _DPL	=	0x0082
                    0083    196 _DPH	=	0x0083
                    0084    197 _DPL1	=	0x0084
                    0085    198 _DPH1	=	0x0085
                    0087    199 _PCON	=	0x0087
                    0088    200 _TCON	=	0x0088
                    0089    201 _TMOD	=	0x0089
                    008A    202 _TL0	=	0x008a
                    008B    203 _TL1	=	0x008b
                    008C    204 _TH0	=	0x008c
                    008D    205 _TH1	=	0x008d
                    008E    206 _CKCON	=	0x008e
                    0090    207 _RFCON	=	0x0090
                    0092    208 _DPS	=	0x0092
                    0094    209 _P0DIR	=	0x0094
                    0095    210 _P0ALT	=	0x0095
                    0098    211 _S0CON	=	0x0098
                    0099    212 _S0BUF	=	0x0099
                    009A    213 _IEN2	=	0x009a
                    00A0    214 _USBCON	=	0x00a0
                    00A3    215 _CLKCTL	=	0x00a3
                    00A4    216 _PWRDWN	=	0x00a4
                    00A5    217 _WUCONF	=	0x00a5
                    00A6    218 _INTEXP	=	0x00a6
                    00A8    219 _IEN0	=	0x00a8
                    00A9    220 _IP0	=	0x00a9
                    00AA    221 _S0RELL	=	0x00aa
                    00AB    222 _REGXH	=	0x00ab
                    00AC    223 _REGXL	=	0x00ac
                    00AD    224 _REGXC	=	0x00ad
                    00B1    225 _RSTRES	=	0x00b1
                    00B2    226 _SMDAT	=	0x00b2
                    00B3    227 _SMCTL	=	0x00b3
                    00B5    228 _TICKDV	=	0x00b5
                    00B8    229 _IEN1	=	0x00b8
                    00B9    230 _IP1	=	0x00b9
                    00BA    231 _S0RELH	=	0x00ba
                    00BC    232 _SSCONF	=	0x00bc
                    00BD    233 _SSDATA	=	0x00bd
                    00BE    234 _SSSTAT	=	0x00be
                    00C0    235 _IRCON	=	0x00c0
                    00C1    236 _CCEN	=	0x00c1
                    00C2    237 _CCL1	=	0x00c2
                    00C3    238 _CCH1	=	0x00c3
                    00C4    239 _CCL2	=	0x00c4
                    00C5    240 _CCH2	=	0x00c5
                    00C6    241 _CCL3	=	0x00c6
                    00C7    242 _CCH3	=	0x00c7
                    00C8    243 _T2CON	=	0x00c8
                    00C9    244 _P0EXP	=	0x00c9
                    00CA    245 _CRCL	=	0x00ca
                    00CB    246 _CRCH	=	0x00cb
                    00CC    247 _TL2	=	0x00cc
                    00CD    248 _TH2	=	0x00cd
                    00D0    249 _PSW	=	0x00d0
                    00D8    250 _WDCON	=	0x00d8
                    00D9    251 _USBSLP	=	0x00d9
                    00E0    252 _ACC	=	0x00e0
                    00E5    253 _RFDAT	=	0x00e5
                    00E6    254 _RFCTL	=	0x00e6
                    00E8    255 _AESCS	=	0x00e8
                    00E9    256 _MD0	=	0x00e9
                    00EA    257 _MD1	=	0x00ea
                    00EB    258 _MD2	=	0x00eb
                    00EC    259 _MD3	=	0x00ec
                    00ED    260 _MD4	=	0x00ed
                    00EE    261 _MD5	=	0x00ee
                    00EF    262 _ARCON	=	0x00ef
                    00F0    263 _B	=	0x00f0
                    00F1    264 _AESKIN	=	0x00f1
                    00F2    265 _AESIV	=	0x00f2
                    00F3    266 _AESD	=	0x00f3
                    00F5    267 _AESIA1	=	0x00f5
                    00F6    268 _AESIA2	=	0x00f6
                    00F8    269 _FSR	=	0x00f8
                    00F9    270 _FPCR	=	0x00f9
                    00FA    271 _FCR	=	0x00fa
                    FFFFC3C2    272 _CC1	=	0xffffc3c2
                    FFFFC5C4    273 _CC2	=	0xffffc5c4
                    FFFFC7C6    274 _CC3	=	0xffffc7c6
                    FFFFCBCA    275 _CRC	=	0xffffcbca
                    FFFFCDCC    276 _T2	=	0xffffcdcc
                            277 ;--------------------------------------------------------
                            278 ; special function bits
                            279 ;--------------------------------------------------------
                            280 	.area RSEG    (DATA)
                    00FF    281 _MCDIS	=	0x00ff
                    00FE    282 _STP	=	0x00fe
                    00FD    283 _WEN	=	0x00fd
                    00FC    284 _RDYN	=	0x00fc
                    00FB    285 _INFEN	=	0x00fb
                    00FA    286 _RDIS	=	0x00fa
                    00F9    287 _RDEND	=	0x00f9
                    00F8    288 _WPEN	=	0x00f8
                    00D7    289 _CY	=	0x00d7
                    00D6    290 _AC	=	0x00d6
                    00D5    291 _F0	=	0x00d5
                    00D4    292 _RS1	=	0x00d4
                    00D3    293 _RS0	=	0x00d3
                    00D2    294 _OV	=	0x00d2
                    00D1    295 _F1	=	0x00d1
                    00D0    296 _P	=	0x00d0
                    008F    297 _TF1	=	0x008f
                    008E    298 _TR1	=	0x008e
                    008D    299 _TF0	=	0x008d
                    008C    300 _TR0	=	0x008c
                    008B    301 _IE1	=	0x008b
                    008A    302 _IT1	=	0x008a
                    0089    303 _IE0	=	0x0089
                    0088    304 _IT0	=	0x0088
                    009F    305 _SM0	=	0x009f
                    009E    306 _SM1	=	0x009e
                    009D    307 _SM20	=	0x009d
                    009C    308 _REN0	=	0x009c
                    009B    309 _TB80	=	0x009b
                    009A    310 _RB80	=	0x009a
                    0099    311 _TI0	=	0x0099
                    0098    312 _RI0	=	0x0098
                    00CF    313 _T2PS	=	0x00cf
                    00CE    314 _I3FR	=	0x00ce
                    00CD    315 _I2FR	=	0x00cd
                    00CC    316 _T2R1	=	0x00cc
                    00CB    317 _T2R0	=	0x00cb
                    00CA    318 _T2CM	=	0x00ca
                    00C9    319 _T2I1	=	0x00c9
                    00C8    320 _T2I0	=	0x00c8
                    00AF    321 _EA	=	0x00af
                    00AD    322 _ET2	=	0x00ad
                    00AC    323 _ES0	=	0x00ac
                    00AB    324 _ET1	=	0x00ab
                    00AA    325 _EX1	=	0x00aa
                    00A9    326 _ET0	=	0x00a9
                    00A8    327 _EX0	=	0x00a8
                    00BF    328 _EXEN2	=	0x00bf
                    00BD    329 _WUIRQ	=	0x00bd
                    00BC    330 _USB	=	0x00bc
                    00BB    331 _USBWU	=	0x00bb
                    00BA    332 _SPI	=	0x00ba
                    00B9    333 _RF	=	0x00b9
                    00B8    334 _RFSPI	=	0x00b8
                    00C7    335 _EXF2	=	0x00c7
                    00C6    336 _TF2	=	0x00c6
                    00C5    337 _WUF	=	0x00c5
                    00C4    338 _USBF	=	0x00c4
                    00C3    339 _USBWUF	=	0x00c3
                    00C2    340 _SPIF	=	0x00c2
                    00C1    341 _RFF	=	0x00c1
                    00C0    342 _RFSPIF	=	0x00c0
                    00A7    343 _SWRST	=	0x00a7
                    00A6    344 _WU	=	0x00a6
                    00A5    345 _SUSPEND	=	0x00a5
                    00A4    346 _IV4	=	0x00a4
                    00A3    347 _IV3	=	0x00a3
                    00A2    348 _IV2	=	0x00a2
                    00A1    349 _IV1	=	0x00a1
                    00A0    350 _IV0	=	0x00a0
                    0080    351 _P00	=	0x0080
                    0081    352 _P01	=	0x0081
                    0082    353 _P02	=	0x0082
                    0083    354 _P03	=	0x0083
                    0083    355 _MCSN	=	0x0083
                    0083    356 _SCSN	=	0x0083
                    0084    357 _P04	=	0x0084
                    0085    358 _P05	=	0x0085
                    0090    359 _RFCE	=	0x0090
                    0091    360 _RFCSN	=	0x0091
                    0092    361 _RFCKEN	=	0x0092
                    00DF    362 _BD	=	0x00df
                    00E8    363 _GO	=	0x00e8
                    00E9    364 _DECR	=	0x00e9
                            365 ;--------------------------------------------------------
                            366 ; overlayable register banks
                            367 ;--------------------------------------------------------
                            368 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     369 	.ds 8
                            370 ;--------------------------------------------------------
                            371 ; internal ram data
                            372 ;--------------------------------------------------------
                            373 	.area DSEG    (DATA)
   000F                     374 _main_sloc0_1_0:
   000F                     375 	.ds 2
                            376 ;--------------------------------------------------------
                            377 ; overlayable items in internal ram 
                            378 ;--------------------------------------------------------
                            379 	.area	OSEG    (OVR,DATA)
   0012                     380 _array_cp_sloc0_1_0::
   0012                     381 	.ds 2
   0014                     382 _array_cp_sloc1_1_0::
   0014                     383 	.ds 3
   0017                     384 _array_cp_sloc2_1_0::
   0017                     385 	.ds 3
                            386 ;--------------------------------------------------------
                            387 ; Stack segment in internal ram 
                            388 ;--------------------------------------------------------
                            389 	.area	SSEG	(DATA)
   004B                     390 __start__stack:
   004B                     391 	.ds	1
                            392 
                            393 ;--------------------------------------------------------
                            394 ; indirectly addressable internal ram data
                            395 ;--------------------------------------------------------
                            396 	.area ISEG    (DATA)
   0037                     397 _rf_cfg_data::
   0037                     398 	.ds 19
   004A                     399 _cfg::
   004A                     400 	.ds 1
                            401 ;--------------------------------------------------------
                            402 ; absolute internal ram data
                            403 ;--------------------------------------------------------
                            404 	.area IABS    (ABS,DATA)
                            405 	.area IABS    (ABS,DATA)
                            406 ;--------------------------------------------------------
                            407 ; bit data
                            408 ;--------------------------------------------------------
                            409 	.area BSEG    (BIT)
                            410 ;--------------------------------------------------------
                            411 ; paged external ram data
                            412 ;--------------------------------------------------------
                            413 	.area PSEG    (PAG,XDATA)
                            414 ;--------------------------------------------------------
                            415 ; external ram data
                            416 ;--------------------------------------------------------
                            417 	.area XSEG    (XDATA)
   8038                     418 _ubuf::
   8038                     419 	.ds 65
   8079                     420 _usize::
   8079                     421 	.ds 1
   807A                     422 _packet::
   807A                     423 	.ds 32
   809A                     424 _main_total_pkt_count_1_1:
   809A                     425 	.ds 2
   809C                     426 _main_addr_width_1_1:
   809C                     427 	.ds 2
   809E                     428 _main_data_length_1_1:
   809E                     429 	.ds 2
   80A0                     430 _main_customized_plen_1_1:
   80A0                     431 	.ds 2
   80A2                     432 _main_pipe_source_1_1:
   80A2                     433 	.ds 6
   80A8                     434 _main_ACKbuf_1_1:
   80A8                     435 	.ds 4
   80AC                     436 _main_temp_buf_1_1:
   80AC                     437 	.ds 34
   80CE                     438 _main_temp_addr_1_1:
   80CE                     439 	.ds 5
   80D3                     440 _array_cp_PARM_2:
   80D3                     441 	.ds 3
   80D6                     442 _array_cp_PARM_3:
   80D6                     443 	.ds 2
   80D8                     444 _array_cp_dst_array_1_1:
   80D8                     445 	.ds 3
                            446 ;--------------------------------------------------------
                            447 ; absolute external ram data
                            448 ;--------------------------------------------------------
                            449 	.area XABS    (ABS,XDATA)
                            450 ;--------------------------------------------------------
                            451 ; external initialized ram data
                            452 ;--------------------------------------------------------
                            453 	.area XISEG   (XDATA)
                            454 	.area HOME    (CODE)
                            455 	.area GSINIT0 (CODE)
                            456 	.area GSINIT1 (CODE)
                            457 	.area GSINIT2 (CODE)
                            458 	.area GSINIT3 (CODE)
                            459 	.area GSINIT4 (CODE)
                            460 	.area GSINIT5 (CODE)
                            461 	.area GSINIT  (CODE)
                            462 	.area GSFINAL (CODE)
                            463 	.area CSEG    (CODE)
                            464 ;--------------------------------------------------------
                            465 ; interrupt vector 
                            466 ;--------------------------------------------------------
                            467 	.area HOME    (CODE)
   0000                     468 __interrupt_vect:
   0000 02 00 6D            469 	ljmp	__sdcc_gsinit_startup
   0003 32                  470 	reti
   0004                     471 	.ds	7
   000B 32                  472 	reti
   000C                     473 	.ds	7
   0013 32                  474 	reti
   0014                     475 	.ds	7
   001B 32                  476 	reti
   001C                     477 	.ds	7
   0023 32                  478 	reti
   0024                     479 	.ds	7
   002B 32                  480 	reti
   002C                     481 	.ds	7
   0033 32                  482 	reti
   0034                     483 	.ds	7
   003B 32                  484 	reti
   003C                     485 	.ds	7
   0043 32                  486 	reti
   0044                     487 	.ds	7
   004B 32                  488 	reti
   004C                     489 	.ds	7
   0053 32                  490 	reti
   0054                     491 	.ds	7
   005B 02 2D 57            492 	ljmp	_usb_wu
   005E                     493 	.ds	5
   0063 02 2E D3            494 	ljmp	_usb_irq
                            495 ;--------------------------------------------------------
                            496 ; global & static initialisations
                            497 ;--------------------------------------------------------
                            498 	.area HOME    (CODE)
                            499 	.area GSINIT  (CODE)
                            500 	.area GSFINAL (CODE)
                            501 	.area GSINIT  (CODE)
                            502 	.globl __sdcc_gsinit_startup
                            503 	.globl __sdcc_program_startup
                            504 	.globl __start__stack
                            505 	.globl __mcs51_genXINIT
                            506 	.globl __mcs51_genXRAMCLEAR
                            507 	.globl __mcs51_genRAMCLEAR
                            508 ;	../main.c:40: idata struct epl_lu1_rf_en_config rf_cfg_data =
   00C6 78 37               509 	mov	r0,#_rf_cfg_data
   00C8 76 76               510 	mov	@r0,#0x76
   00CA 78 38               511 	mov	r0,#(_rf_cfg_data + 0x0001)
   00CC 76 05               512 	mov	@r0,#0x05
   00CE 78 39               513 	mov	r0,#(_rf_cfg_data + 0x0002)
   00D0 76 65               514 	mov	@r0,#0x65
   00D2 78 3A               515 	mov	r0,#(_rf_cfg_data + 0x0003)
   00D4 76 65               516 	mov	@r0,#0x65
   00D6 78 3B               517 	mov	r0,#(_rf_cfg_data + 0x0004)
   00D8 76 65               518 	mov	@r0,#0x65
   00DA 78 3C               519 	mov	r0,#(_rf_cfg_data + 0x0005)
   00DC 76 65               520 	mov	@r0,#0x65
   00DE 78 3D               521 	mov	r0,#(_rf_cfg_data + 0x0006)
   00E0 76 65               522 	mov	@r0,#0x65
   00E2 78 3E               523 	mov	r0,#(_rf_cfg_data + 0x0007)
   00E4 76 65               524 	mov	@r0,#0x65
   00E6 78 3F               525 	mov	r0,#(_rf_cfg_data + 0x0008)
   00E8 76 65               526 	mov	@r0,#0x65
   00EA 78 40               527 	mov	r0,#(_rf_cfg_data + 0x0009)
   00EC 76 65               528 	mov	@r0,#0x65
   00EE 78 41               529 	mov	r0,#(_rf_cfg_data + 0x000a)
   00F0 76 65               530 	mov	@r0,#0x65
   00F2 78 42               531 	mov	r0,#(_rf_cfg_data + 0x000b)
   00F4 76 65               532 	mov	@r0,#0x65
   00F6 78 43               533 	mov	r0,#(_rf_cfg_data + 0x000c)
   00F8 76 20               534 	mov	@r0,#0x20
   00FA 78 44               535 	mov	r0,#(_rf_cfg_data + 0x000d)
   00FC 76 00               536 	mov	@r0,#0x00
   00FE 78 45               537 	mov	r0,#(_rf_cfg_data + 0x000e)
   0100 76 03               538 	mov	@r0,#0x03
   0102 78 46               539 	mov	r0,#(_rf_cfg_data + 0x000f)
   0104 76 01               540 	mov	@r0,#0x01
   0106 78 47               541 	mov	r0,#(_rf_cfg_data + 0x0010)
   0108 76 0F               542 	mov	@r0,#0x0F
   010A 78 48               543 	mov	r0,#(_rf_cfg_data + 0x0011)
   010C 76 FA               544 	mov	@r0,#0xFA
   010E 08                  545 	inc	r0
   010F 76 00               546 	mov	@r0,#0x00
                            547 ;	../main.c:54: idata struct epl_lu1_rf_en_config * idata cfg = &rf_cfg_data;
   0111 78 4A               548 	mov	r0,#_cfg
   0113 76 37               549 	mov	@r0,#_rf_cfg_data
                            550 	.area GSFINAL (CODE)
   0119 02 00 66            551 	ljmp	__sdcc_program_startup
                            552 ;--------------------------------------------------------
                            553 ; Home
                            554 ;--------------------------------------------------------
                            555 	.area HOME    (CODE)
                            556 	.area HOME    (CODE)
   0066                     557 __sdcc_program_startup:
   0066 12 05 6A            558 	lcall	_main
                            559 ;	return from main will lock up
   0069 80 FE               560 	sjmp .
                            561 ;--------------------------------------------------------
                            562 ; code
                            563 ;--------------------------------------------------------
                            564 	.area CSEG    (CODE)
                            565 ;------------------------------------------------------------
                            566 ;Allocation info for local variables in function 'main'
                            567 ;------------------------------------------------------------
                            568 ;sloc0                     Allocated with name '_main_sloc0_1_0'
                            569 ;i                         Allocated with name '_main_i_1_1'
                            570 ;total_pkt_count           Allocated with name '_main_total_pkt_count_1_1'
                            571 ;addr_width                Allocated with name '_main_addr_width_1_1'
                            572 ;data_length               Allocated with name '_main_data_length_1_1'
                            573 ;customized_plen           Allocated with name '_main_customized_plen_1_1'
                            574 ;pipe_source               Allocated with name '_main_pipe_source_1_1'
                            575 ;ACKbuf                    Allocated with name '_main_ACKbuf_1_1'
                            576 ;temp_buf                  Allocated with name '_main_temp_buf_1_1'
                            577 ;temp_addr                 Allocated with name '_main_temp_addr_1_1'
                            578 ;------------------------------------------------------------
                            579 ;	../main.c:60: void main(void) {
                            580 ;	-----------------------------------------
                            581 ;	 function main
                            582 ;	-----------------------------------------
   056A                     583 _main:
                    0002    584 	ar2 = 0x02
                    0003    585 	ar3 = 0x03
                    0004    586 	ar4 = 0x04
                    0005    587 	ar5 = 0x05
                    0006    588 	ar6 = 0x06
                    0007    589 	ar7 = 0x07
                    0000    590 	ar0 = 0x00
                    0001    591 	ar1 = 0x01
                            592 ;	../main.c:62: int total_pkt_count = 1;
   056A 90 80 9A            593 	mov	dptr,#_main_total_pkt_count_1_1
   056D 74 01               594 	mov	a,#0x01
   056F F0                  595 	movx	@dptr,a
   0570 E4                  596 	clr	a
   0571 A3                  597 	inc	dptr
   0572 F0                  598 	movx	@dptr,a
                            599 ;	../main.c:64: int	addr_width = 5, data_length = 32;
   0573 90 80 9C            600 	mov	dptr,#_main_addr_width_1_1
   0576 74 05               601 	mov	a,#0x05
   0578 F0                  602 	movx	@dptr,a
   0579 E4                  603 	clr	a
   057A A3                  604 	inc	dptr
   057B F0                  605 	movx	@dptr,a
   057C 90 80 9E            606 	mov	dptr,#_main_data_length_1_1
   057F 74 20               607 	mov	a,#0x20
   0581 F0                  608 	movx	@dptr,a
   0582 E4                  609 	clr	a
   0583 A3                  610 	inc	dptr
   0584 F0                  611 	movx	@dptr,a
                            612 ;	../main.c:66: int customized_plen = 0;
   0585 90 80 A0            613 	mov	dptr,#_main_customized_plen_1_1
   0588 E4                  614 	clr	a
   0589 F0                  615 	movx	@dptr,a
   058A A3                  616 	inc	dptr
   058B F0                  617 	movx	@dptr,a
                            618 ;	../main.c:71: unsigned char ACKbuf[] = "ACK";
   058C 90 80 A8            619 	mov	dptr,#_main_ACKbuf_1_1
   058F 74 41               620 	mov	a,#0x41
   0591 F0                  621 	movx	@dptr,a
   0592 90 80 A9            622 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0001)
   0595 74 43               623 	mov	a,#0x43
   0597 F0                  624 	movx	@dptr,a
   0598 90 80 AA            625 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0002)
   059B 74 4B               626 	mov	a,#0x4B
   059D F0                  627 	movx	@dptr,a
   059E 90 80 AB            628 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0003)
   05A1 E4                  629 	clr	a
   05A2 F0                  630 	movx	@dptr,a
                            631 ;	../main.c:77: P0EXP = 0x00;
   05A3 75 C9 00            632 	mov	_P0EXP,#0x00
                            633 ;	../main.c:78: P0ALT = 0x00;
   05A6 75 95 00            634 	mov	_P0ALT,#0x00
                            635 ;	../main.c:79: P0DIR = 0x00;
   05A9 75 94 00            636 	mov	_P0DIR,#0x00
                            637 ;	../main.c:82: epl_uart_init(UART_BAUD_57K6);
   05AC 75 82 03            638 	mov	dpl,#0x03
   05AF 12 18 1A            639 	lcall	_epl_uart_init
                            640 ;	../main.c:84: usb_init(); // Initialize USB
   05B2 12 0B E0            641 	lcall	_usb_init
                            642 ;	../main.c:85: EA=1; // Enable global IRQ
   05B5 D2 AF               643 	setb	_EA
                            644 ;	../main.c:88: P04 = 0;
   05B7 C2 84               645 	clr	_P04
                            646 ;	../main.c:89: P05 = 0;
   05B9 C2 85               647 	clr	_P05
                            648 ;	../main.c:91: for(i=0;i<3;i++)
   05BB 7A 00               649 	mov	r2,#0x00
   05BD 7B 00               650 	mov	r3,#0x00
   05BF                     651 00150$:
   05BF C3                  652 	clr	c
   05C0 EA                  653 	mov	a,r2
   05C1 94 03               654 	subb	a,#0x03
   05C3 EB                  655 	mov	a,r3
   05C4 64 80               656 	xrl	a,#0x80
   05C6 94 80               657 	subb	a,#0x80
   05C8 50 21               658 	jnc	00153$
                            659 ;	../main.c:92: LED_Blink(200);
   05CA 63 80 30            660 	xrl	_P0,#0x30
   05CD 90 00 C8            661 	mov	dptr,#0x00C8
   05D0 C0 02               662 	push	ar2
   05D2 C0 03               663 	push	ar3
   05D4 12 32 91            664 	lcall	_mdelay
   05D7 63 80 30            665 	xrl	_P0,#0x30
   05DA 90 00 C8            666 	mov	dptr,#0x00C8
   05DD 12 32 91            667 	lcall	_mdelay
   05E0 D0 03               668 	pop	ar3
   05E2 D0 02               669 	pop	ar2
                            670 ;	../main.c:91: for(i=0;i<3;i++)
   05E4 0A                  671 	inc	r2
   05E5 BA 00 D7            672 	cjne	r2,#0x00,00150$
   05E8 0B                  673 	inc	r3
   05E9 80 D4               674 	sjmp	00150$
   05EB                     675 00153$:
                            676 ;	../main.c:94: P04 = 0;
   05EB C2 84               677 	clr	_P04
                            678 ;	../main.c:95: P05 = 1;
   05ED D2 85               679 	setb	_P05
                            680 ;	../main.c:99: epl_rf_en_quick_init(cfg);
   05EF 78 4A               681 	mov	r0,#_cfg
   05F1 86 02               682 	mov	ar2,@r0
   05F3 7B 00               683 	mov	r3,#0x00
   05F5 7C 40               684 	mov	r4,#0x40
   05F7 8A 82               685 	mov	dpl,r2
   05F9 8B 83               686 	mov	dph,r3
   05FB 8C F0               687 	mov	b,r4
   05FD 12 02 FE            688 	lcall	_epl_rf_en_quick_init
                            689 ;	../main.c:102: hal_nrf_write_reg(FLUSH_TX, 0);
   0600 90 81 10            690 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   0603 E4                  691 	clr	a
   0604 F0                  692 	movx	@dptr,a
   0605 75 82 E1            693 	mov	dpl,#0xE1
   0608 12 15 B3            694 	lcall	_hal_nrf_write_reg
                            695 ;	../main.c:103: hal_nrf_write_reg(FLUSH_RX, 0);
   060B 90 81 10            696 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   060E E4                  697 	clr	a
   060F F0                  698 	movx	@dptr,a
   0610 75 82 E2            699 	mov	dpl,#0xE2
   0613 12 15 B3            700 	lcall	_hal_nrf_write_reg
                            701 ;	../main.c:106: while (1) {
   0616                     702 00148$:
                            703 ;	../main.c:108: usb_recv_packet();
   0616 12 0C D4            704 	lcall	_usb_recv_packet
                            705 ;	../main.c:110: packet[0] = 0x00;
   0619 90 80 7A            706 	mov	dptr,#_packet
   061C E4                  707 	clr	a
   061D F0                  708 	movx	@dptr,a
                            709 ;	../main.c:111: packet[1] = ubuf[1];
   061E 90 80 39            710 	mov	dptr,#(_ubuf + 0x0001)
   0621 E0                  711 	movx	a,@dptr
   0622 90 80 7B            712 	mov	dptr,#(_packet + 0x0001)
   0625 F0                  713 	movx	@dptr,a
                            714 ;	../main.c:112: packet[2] = ubuf[2];
   0626 90 80 3A            715 	mov	dptr,#(_ubuf + 0x0002)
   0629 E0                  716 	movx	a,@dptr
   062A 90 80 7C            717 	mov	dptr,#(_packet + 0x0002)
   062D F0                  718 	movx	@dptr,a
                            719 ;	../main.c:113: packet[3] = ubuf[3];
   062E 90 80 3B            720 	mov	dptr,#(_ubuf + 0x0003)
   0631 E0                  721 	movx	a,@dptr
   0632 90 80 7D            722 	mov	dptr,#(_packet + 0x0003)
   0635 F0                  723 	movx	@dptr,a
                            724 ;	../main.c:115: epl_rf_en_send(packet, data_length);
   0636 90 80 9E            725 	mov	dptr,#_main_data_length_1_1
   0639 E0                  726 	movx	a,@dptr
   063A FA                  727 	mov	r2,a
   063B A3                  728 	inc	dptr
   063C E0                  729 	movx	a,@dptr
   063D FB                  730 	mov	r3,a
   063E 8A 04               731 	mov	ar4,r2
   0640 90 80 2E            732 	mov	dptr,#_epl_rf_en_send_PARM_2
   0643 EC                  733 	mov	a,r4
   0644 F0                  734 	movx	@dptr,a
   0645 90 80 7A            735 	mov	dptr,#_packet
   0648 75 F0 00            736 	mov	b,#0x00
   064B C0 02               737 	push	ar2
   064D C0 03               738 	push	ar3
   064F C0 04               739 	push	ar4
   0651 12 04 CC            740 	lcall	_epl_rf_en_send
   0654 D0 04               741 	pop	ar4
   0656 D0 03               742 	pop	ar3
   0658 D0 02               743 	pop	ar2
                            744 ;	../main.c:118: switch(ubuf[1])
   065A 90 80 39            745 	mov	dptr,#(_ubuf + 0x0001)
   065D E0                  746 	movx	a,@dptr
   065E FD                  747 	mov	r5,a
   065F BD 01 03            748 	cjne	r5,#0x01,00211$
   0662 02 06 F5            749 	ljmp	00105$
   0665                     750 00211$:
   0665 BD 02 03            751 	cjne	r5,#0x02,00212$
   0668 02 07 10            752 	ljmp	00106$
   066B                     753 00212$:
   066B BD 03 03            754 	cjne	r5,#0x03,00213$
   066E 02 07 2B            755 	ljmp	00107$
   0671                     756 00213$:
   0671 BD 04 03            757 	cjne	r5,#0x04,00214$
   0674 02 07 46            758 	ljmp	00108$
   0677                     759 00214$:
   0677 BD 05 03            760 	cjne	r5,#0x05,00215$
   067A 02 07 B2            761 	ljmp	00111$
   067D                     762 00215$:
   067D BD 10 03            763 	cjne	r5,#0x10,00216$
   0680 02 07 E6            764 	ljmp	00195$
   0683                     765 00216$:
   0683 BD 30 03            766 	cjne	r5,#0x30,00217$
   0686 02 07 69            767 	ljmp	00109$
   0689                     768 00217$:
   0689 BD 40 03            769 	cjne	r5,#0x40,00218$
   068C 02 07 89            770 	ljmp	00110$
   068F                     771 00218$:
   068F BD F2 03            772 	cjne	r5,#0xF2,00219$
   0692 02 0A 6F            773 	ljmp	00144$
   0695                     774 00219$:
   0695 BD F3 02            775 	cjne	r5,#0xF3,00220$
   0698 80 1B               776 	sjmp	00104$
   069A                     777 00220$:
   069A BD F6 03            778 	cjne	r5,#0xF6,00221$
   069D 02 09 24            779 	ljmp	00126$
   06A0                     780 00221$:
   06A0 BD F7 03            781 	cjne	r5,#0xF7,00222$
   06A3 02 0A 22            782 	ljmp	00133$
   06A6                     783 00222$:
   06A6 BD F8 03            784 	cjne	r5,#0xF8,00223$
   06A9 02 09 09            785 	ljmp	00125$
   06AC                     786 00223$:
   06AC BD F9 03            787 	cjne	r5,#0xF9,00224$
   06AF 02 08 6D            788 	ljmp	00121$
   06B2                     789 00224$:
   06B2 02 06 16            790 	ljmp	00148$
                            791 ;	../main.c:120: case EPL_SENDER_MODE:
   06B5                     792 00104$:
                            793 ;	../main.c:121: customized_plen = 0;
   06B5 90 80 A0            794 	mov	dptr,#_main_customized_plen_1_1
   06B8 E4                  795 	clr	a
   06B9 F0                  796 	movx	@dptr,a
   06BA A3                  797 	inc	dptr
   06BB F0                  798 	movx	@dptr,a
                            799 ;	../main.c:122: for(i=0;i<PLOAD_LEN;i++)
   06BC 7D 00               800 	mov	r5,#0x00
   06BE 7E 00               801 	mov	r6,#0x00
   06C0                     802 00154$:
   06C0 C3                  803 	clr	c
   06C1 ED                  804 	mov	a,r5
   06C2 94 20               805 	subb	a,#0x20
   06C4 EE                  806 	mov	a,r6
   06C5 64 80               807 	xrl	a,#0x80
   06C7 94 80               808 	subb	a,#0x80
   06C9 50 18               809 	jnc	00157$
                            810 ;	../main.c:123: packet[i]=i+9;
   06CB ED                  811 	mov	a,r5
   06CC 24 7A               812 	add	a,#_packet
   06CE F5 82               813 	mov	dpl,a
   06D0 EE                  814 	mov	a,r6
   06D1 34 80               815 	addc	a,#(_packet >> 8)
   06D3 F5 83               816 	mov	dph,a
   06D5 8D 07               817 	mov	ar7,r5
   06D7 74 09               818 	mov	a,#0x09
   06D9 2F                  819 	add	a,r7
   06DA FF                  820 	mov	r7,a
   06DB F0                  821 	movx	@dptr,a
                            822 ;	../main.c:122: for(i=0;i<PLOAD_LEN;i++)
   06DC 0D                  823 	inc	r5
   06DD BD 00 E0            824 	cjne	r5,#0x00,00154$
   06E0 0E                  825 	inc	r6
   06E1 80 DD               826 	sjmp	00154$
   06E3                     827 00157$:
                            828 ;	../main.c:125: usb_send_packet(ACKbuf, 3);
   06E3 90 80 DF            829 	mov	dptr,#_usb_send_packet_PARM_2
   06E6 74 03               830 	mov	a,#0x03
   06E8 F0                  831 	movx	@dptr,a
   06E9 90 80 A8            832 	mov	dptr,#_main_ACKbuf_1_1
   06EC 75 F0 00            833 	mov	b,#0x00
   06EF 12 0C 92            834 	lcall	_usb_send_packet
                            835 ;	../main.c:126: break;
   06F2 02 06 16            836 	ljmp	00148$
                            837 ;	../main.c:129: case EPL_OUTPUT_POWER:
   06F5                     838 00105$:
                            839 ;	../main.c:130: hal_nrf_set_output_power(ubuf[2]);
   06F5 90 80 3A            840 	mov	dptr,#(_ubuf + 0x0002)
   06F8 E0                  841 	movx	a,@dptr
   06F9 F5 82               842 	mov	dpl,a
   06FB 12 12 30            843 	lcall	_hal_nrf_set_output_power
                            844 ;	../main.c:133: usb_send_packet(ACKbuf, 3);
   06FE 90 80 DF            845 	mov	dptr,#_usb_send_packet_PARM_2
   0701 74 03               846 	mov	a,#0x03
   0703 F0                  847 	movx	@dptr,a
   0704 90 80 A8            848 	mov	dptr,#_main_ACKbuf_1_1
   0707 75 F0 00            849 	mov	b,#0x00
   070A 12 0C 92            850 	lcall	_usb_send_packet
                            851 ;	../main.c:135: break;
   070D 02 06 16            852 	ljmp	00148$
                            853 ;	../main.c:137: case EPL_CHANNEL:
   0710                     854 00106$:
                            855 ;	../main.c:138: hal_nrf_set_rf_channel(ubuf[2]);
   0710 90 80 3A            856 	mov	dptr,#(_ubuf + 0x0002)
   0713 E0                  857 	movx	a,@dptr
   0714 F5 82               858 	mov	dpl,a
   0716 12 12 1C            859 	lcall	_hal_nrf_set_rf_channel
                            860 ;	../main.c:141: usb_send_packet(ACKbuf, 3);
   0719 90 80 DF            861 	mov	dptr,#_usb_send_packet_PARM_2
   071C 74 03               862 	mov	a,#0x03
   071E F0                  863 	movx	@dptr,a
   071F 90 80 A8            864 	mov	dptr,#_main_ACKbuf_1_1
   0722 75 F0 00            865 	mov	b,#0x00
   0725 12 0C 92            866 	lcall	_usb_send_packet
                            867 ;	../main.c:143: break;
   0728 02 06 16            868 	ljmp	00148$
                            869 ;	../main.c:145: case EPL_DATARATE:
   072B                     870 00107$:
                            871 ;	../main.c:146: hal_nrf_set_datarate(ubuf[2]);
   072B 90 80 3A            872 	mov	dptr,#(_ubuf + 0x0002)
   072E E0                  873 	movx	a,@dptr
   072F F5 82               874 	mov	dpl,a
   0731 12 12 52            875 	lcall	_hal_nrf_set_datarate
                            876 ;	../main.c:148: usb_send_packet(ACKbuf, 3);
   0734 90 80 DF            877 	mov	dptr,#_usb_send_packet_PARM_2
   0737 74 03               878 	mov	a,#0x03
   0739 F0                  879 	movx	@dptr,a
   073A 90 80 A8            880 	mov	dptr,#_main_ACKbuf_1_1
   073D 75 F0 00            881 	mov	b,#0x00
   0740 12 0C 92            882 	lcall	_usb_send_packet
                            883 ;	../main.c:149: break;
   0743 02 06 16            884 	ljmp	00148$
                            885 ;	../main.c:151: case EPL_ADDR_WIDTH:
   0746                     886 00108$:
                            887 ;	../main.c:152: addr_width = (int)ubuf[2];
   0746 90 80 3A            888 	mov	dptr,#(_ubuf + 0x0002)
   0749 E0                  889 	movx	a,@dptr
   074A FD                  890 	mov	r5,a
   074B 90 80 9C            891 	mov	dptr,#_main_addr_width_1_1
   074E F0                  892 	movx	@dptr,a
   074F A3                  893 	inc	dptr
   0750 E4                  894 	clr	a
   0751 F0                  895 	movx	@dptr,a
                            896 ;	../main.c:153: hal_nrf_set_address_width(ubuf[2]);
   0752 8D 82               897 	mov	dpl,r5
   0754 12 10 70            898 	lcall	_hal_nrf_set_address_width
                            899 ;	../main.c:155: usb_send_packet(ACKbuf, 3);
   0757 90 80 DF            900 	mov	dptr,#_usb_send_packet_PARM_2
   075A 74 03               901 	mov	a,#0x03
   075C F0                  902 	movx	@dptr,a
   075D 90 80 A8            903 	mov	dptr,#_main_ACKbuf_1_1
   0760 75 F0 00            904 	mov	b,#0x00
   0763 12 0C 92            905 	lcall	_usb_send_packet
                            906 ;	../main.c:156: break;
   0766 02 06 16            907 	ljmp	00148$
                            908 ;	../main.c:158: case EPL_AUTOACK_P0:
   0769                     909 00109$:
                            910 ;	../main.c:159: hal_nrf_open_pipe(HAL_NRF_PIPE0, ubuf[2]);
   0769 90 80 3A            911 	mov	dptr,#(_ubuf + 0x0002)
   076C E0                  912 	movx	a,@dptr
   076D 90 80 E8            913 	mov	dptr,#_hal_nrf_open_pipe_PARM_2
   0770 F0                  914 	movx	@dptr,a
   0771 75 82 00            915 	mov	dpl,#0x00
   0774 12 0E 90            916 	lcall	_hal_nrf_open_pipe
                            917 ;	../main.c:161: usb_send_packet(ACKbuf, 3);
   0777 90 80 DF            918 	mov	dptr,#_usb_send_packet_PARM_2
   077A 74 03               919 	mov	a,#0x03
   077C F0                  920 	movx	@dptr,a
   077D 90 80 A8            921 	mov	dptr,#_main_ACKbuf_1_1
   0780 75 F0 00            922 	mov	b,#0x00
   0783 12 0C 92            923 	lcall	_usb_send_packet
                            924 ;	../main.c:162: break;
   0786 02 06 16            925 	ljmp	00148$
                            926 ;	../main.c:164: case EPL_DATA_LENGTH_P0:
   0789                     927 00110$:
                            928 ;	../main.c:165: data_length = (int)ubuf[2];
   0789 90 80 3A            929 	mov	dptr,#(_ubuf + 0x0002)
   078C E0                  930 	movx	a,@dptr
   078D FD                  931 	mov	r5,a
   078E 90 80 9E            932 	mov	dptr,#_main_data_length_1_1
   0791 F0                  933 	movx	@dptr,a
   0792 A3                  934 	inc	dptr
   0793 E4                  935 	clr	a
   0794 F0                  936 	movx	@dptr,a
                            937 ;	../main.c:166: hal_nrf_set_rx_pload_width(HAL_NRF_PIPE0, ubuf[2]);
   0795 90 80 F3            938 	mov	dptr,#_hal_nrf_set_rx_pload_width_PARM_2
   0798 ED                  939 	mov	a,r5
   0799 F0                  940 	movx	@dptr,a
   079A 75 82 00            941 	mov	dpl,#0x00
   079D 12 10 88            942 	lcall	_hal_nrf_set_rx_pload_width
                            943 ;	../main.c:168: usb_send_packet(ACKbuf, 3);
   07A0 90 80 DF            944 	mov	dptr,#_usb_send_packet_PARM_2
   07A3 74 03               945 	mov	a,#0x03
   07A5 F0                  946 	movx	@dptr,a
   07A6 90 80 A8            947 	mov	dptr,#_main_ACKbuf_1_1
   07A9 75 F0 00            948 	mov	b,#0x00
   07AC 12 0C 92            949 	lcall	_usb_send_packet
                            950 ;	../main.c:169: break;
   07AF 02 06 16            951 	ljmp	00148$
                            952 ;	../main.c:171: case EPL_CRC_MODE:
   07B2                     953 00111$:
                            954 ;	../main.c:172: if(ubuf[2] == 0)
   07B2 90 80 3A            955 	mov	dptr,#(_ubuf + 0x0002)
   07B5 E0                  956 	movx	a,@dptr
   07B6 FD                  957 	mov	r5,a
                            958 ;	../main.c:173: hal_nrf_set_crc_mode(HAL_NRF_CRC_OFF);
   07B7 70 07               959 	jnz	00118$
   07B9 F5 82               960 	mov	dpl,a
   07BB 12 0E 6C            961 	lcall	_hal_nrf_set_crc_mode
   07BE 80 14               962 	sjmp	00119$
   07C0                     963 00118$:
                            964 ;	../main.c:174: else if(ubuf[2] == 2)
   07C0 BD 02 08            965 	cjne	r5,#0x02,00115$
                            966 ;	../main.c:175: hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT);
   07C3 75 82 02            967 	mov	dpl,#0x02
   07C6 12 0E 6C            968 	lcall	_hal_nrf_set_crc_mode
   07C9 80 09               969 	sjmp	00119$
   07CB                     970 00115$:
                            971 ;	../main.c:176: else if(ubuf[2] == 3)
   07CB BD 03 06            972 	cjne	r5,#0x03,00119$
                            973 ;	../main.c:177: hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);
   07CE 75 82 03            974 	mov	dpl,#0x03
   07D1 12 0E 6C            975 	lcall	_hal_nrf_set_crc_mode
   07D4                     976 00119$:
                            977 ;	../main.c:181: usb_send_packet(ACKbuf, 3);
   07D4 90 80 DF            978 	mov	dptr,#_usb_send_packet_PARM_2
   07D7 74 03               979 	mov	a,#0x03
   07D9 F0                  980 	movx	@dptr,a
   07DA 90 80 A8            981 	mov	dptr,#_main_ACKbuf_1_1
   07DD 75 F0 00            982 	mov	b,#0x00
   07E0 12 0C 92            983 	lcall	_usb_send_packet
                            984 ;	../main.c:182: break;
   07E3 02 06 16            985 	ljmp	00148$
                            986 ;	../main.c:185: for (i=0;i<addr_width;i++)
   07E6                     987 00195$:
   07E6 90 80 9C            988 	mov	dptr,#_main_addr_width_1_1
   07E9 E0                  989 	movx	a,@dptr
   07EA FD                  990 	mov	r5,a
   07EB A3                  991 	inc	dptr
   07EC E0                  992 	movx	a,@dptr
   07ED FE                  993 	mov	r6,a
   07EE E4                  994 	clr	a
   07EF F5 0F               995 	mov	_main_sloc0_1_0,a
   07F1 F5 10               996 	mov	(_main_sloc0_1_0 + 1),a
   07F3                     997 00158$:
   07F3 C3                  998 	clr	c
   07F4 E5 0F               999 	mov	a,_main_sloc0_1_0
   07F6 9D                 1000 	subb	a,r5
   07F7 E5 10              1001 	mov	a,(_main_sloc0_1_0 + 1)
   07F9 64 80              1002 	xrl	a,#0x80
   07FB 8E F0              1003 	mov	b,r6
   07FD 63 F0 80           1004 	xrl	b,#0x80
   0800 95 F0              1005 	subb	a,b
   0802 50 31              1006 	jnc	00161$
                           1007 ;	../main.c:187: temp_addr[i] = ubuf[i+2];
   0804 C0 05              1008 	push	ar5
   0806 C0 06              1009 	push	ar6
   0808 E5 0F              1010 	mov	a,_main_sloc0_1_0
   080A 24 CE              1011 	add	a,#_main_temp_addr_1_1
   080C FF                 1012 	mov	r7,a
   080D E5 10              1013 	mov	a,(_main_sloc0_1_0 + 1)
   080F 34 80              1014 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0811 FD                 1015 	mov	r5,a
   0812 AE 0F              1016 	mov	r6,_main_sloc0_1_0
   0814 74 02              1017 	mov	a,#0x02
   0816 2E                 1018 	add	a,r6
   0817 24 38              1019 	add	a,#_ubuf
   0819 F5 82              1020 	mov	dpl,a
   081B E4                 1021 	clr	a
   081C 34 80              1022 	addc	a,#(_ubuf >> 8)
   081E F5 83              1023 	mov	dph,a
   0820 E0                 1024 	movx	a,@dptr
   0821 FE                 1025 	mov	r6,a
   0822 8F 82              1026 	mov	dpl,r7
   0824 8D 83              1027 	mov	dph,r5
   0826 F0                 1028 	movx	@dptr,a
                           1029 ;	../main.c:185: for (i=0;i<addr_width;i++)
   0827 05 0F              1030 	inc	_main_sloc0_1_0
   0829 E4                 1031 	clr	a
   082A B5 0F 02           1032 	cjne	a,_main_sloc0_1_0,00232$
   082D 05 10              1033 	inc	(_main_sloc0_1_0 + 1)
   082F                    1034 00232$:
   082F D0 06              1035 	pop	ar6
   0831 D0 05              1036 	pop	ar5
   0833 80 BE              1037 	sjmp	00158$
   0835                    1038 00161$:
                           1039 ;	../main.c:190: hal_nrf_set_address(HAL_NRF_TX, temp_addr);
   0835 90 80 EB           1040 	mov	dptr,#_hal_nrf_set_address_PARM_2
   0838 74 CE              1041 	mov	a,#_main_temp_addr_1_1
   083A F0                 1042 	movx	@dptr,a
   083B A3                 1043 	inc	dptr
   083C 74 80              1044 	mov	a,#(_main_temp_addr_1_1 >> 8)
   083E F0                 1045 	movx	@dptr,a
   083F A3                 1046 	inc	dptr
   0840 E4                 1047 	clr	a
   0841 F0                 1048 	movx	@dptr,a
   0842 75 82 06           1049 	mov	dpl,#0x06
   0845 12 0F C7           1050 	lcall	_hal_nrf_set_address
                           1051 ;	../main.c:191: hal_nrf_set_address(HAL_NRF_PIPE0, temp_addr);
   0848 90 80 EB           1052 	mov	dptr,#_hal_nrf_set_address_PARM_2
   084B 74 CE              1053 	mov	a,#_main_temp_addr_1_1
   084D F0                 1054 	movx	@dptr,a
   084E A3                 1055 	inc	dptr
   084F 74 80              1056 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0851 F0                 1057 	movx	@dptr,a
   0852 A3                 1058 	inc	dptr
   0853 E4                 1059 	clr	a
   0854 F0                 1060 	movx	@dptr,a
   0855 75 82 00           1061 	mov	dpl,#0x00
   0858 12 0F C7           1062 	lcall	_hal_nrf_set_address
                           1063 ;	../main.c:193: usb_send_packet(ACKbuf, 3);
   085B 90 80 DF           1064 	mov	dptr,#_usb_send_packet_PARM_2
   085E 74 03              1065 	mov	a,#0x03
   0860 F0                 1066 	movx	@dptr,a
   0861 90 80 A8           1067 	mov	dptr,#_main_ACKbuf_1_1
   0864 75 F0 00           1068 	mov	b,#0x00
   0867 12 0C 92           1069 	lcall	_usb_send_packet
                           1070 ;	../main.c:194: break;
   086A 02 06 16           1071 	ljmp	00148$
                           1072 ;	../main.c:196: case EPL_USER_PLOAD:
   086D                    1073 00121$:
                           1074 ;	../main.c:197: if (ubuf[2] == USRS_PLOAD){
   086D 90 80 3A           1075 	mov	dptr,#(_ubuf + 0x0002)
   0870 E0                 1076 	movx	a,@dptr
   0871 70 56              1077 	jnz	00123$
                           1078 ;	../main.c:198: customized_plen = (int)ubuf[3];
   0873 90 80 3B           1079 	mov	dptr,#(_ubuf + 0x0003)
   0876 E0                 1080 	movx	a,@dptr
   0877 FD                 1081 	mov	r5,a
   0878 7E 00              1082 	mov	r6,#0x00
   087A 90 80 A0           1083 	mov	dptr,#_main_customized_plen_1_1
   087D ED                 1084 	mov	a,r5
   087E F0                 1085 	movx	@dptr,a
   087F A3                 1086 	inc	dptr
   0880 EE                 1087 	mov	a,r6
   0881 F0                 1088 	movx	@dptr,a
                           1089 ;	../main.c:200: for(i=0;i<customized_plen;i++)
   0882 E4                 1090 	clr	a
   0883 F5 0F              1091 	mov	_main_sloc0_1_0,a
   0885 F5 10              1092 	mov	(_main_sloc0_1_0 + 1),a
   0887                    1093 00162$:
   0887 C3                 1094 	clr	c
   0888 E5 0F              1095 	mov	a,_main_sloc0_1_0
   088A 9D                 1096 	subb	a,r5
   088B E5 10              1097 	mov	a,(_main_sloc0_1_0 + 1)
   088D 64 80              1098 	xrl	a,#0x80
   088F 8E F0              1099 	mov	b,r6
   0891 63 F0 80           1100 	xrl	b,#0x80
   0894 95 F0              1101 	subb	a,b
   0896 50 5F              1102 	jnc	00124$
                           1103 ;	../main.c:202: packet[i] = ubuf[i+4];
   0898 C0 05              1104 	push	ar5
   089A C0 06              1105 	push	ar6
   089C E5 0F              1106 	mov	a,_main_sloc0_1_0
   089E 24 7A              1107 	add	a,#_packet
   08A0 FF                 1108 	mov	r7,a
   08A1 E5 10              1109 	mov	a,(_main_sloc0_1_0 + 1)
   08A3 34 80              1110 	addc	a,#(_packet >> 8)
   08A5 FD                 1111 	mov	r5,a
   08A6 AE 0F              1112 	mov	r6,_main_sloc0_1_0
   08A8 74 04              1113 	mov	a,#0x04
   08AA 2E                 1114 	add	a,r6
   08AB 24 38              1115 	add	a,#_ubuf
   08AD F5 82              1116 	mov	dpl,a
   08AF E4                 1117 	clr	a
   08B0 34 80              1118 	addc	a,#(_ubuf >> 8)
   08B2 F5 83              1119 	mov	dph,a
   08B4 E0                 1120 	movx	a,@dptr
   08B5 FE                 1121 	mov	r6,a
   08B6 8F 82              1122 	mov	dpl,r7
   08B8 8D 83              1123 	mov	dph,r5
   08BA F0                 1124 	movx	@dptr,a
                           1125 ;	../main.c:200: for(i=0;i<customized_plen;i++)
   08BB 05 0F              1126 	inc	_main_sloc0_1_0
   08BD E4                 1127 	clr	a
   08BE B5 0F 02           1128 	cjne	a,_main_sloc0_1_0,00235$
   08C1 05 10              1129 	inc	(_main_sloc0_1_0 + 1)
   08C3                    1130 00235$:
   08C3 D0 06              1131 	pop	ar6
   08C5 D0 05              1132 	pop	ar5
   08C7 80 BE              1133 	sjmp	00162$
   08C9                    1134 00123$:
                           1135 ;	../main.c:206: customized_plen = 0;
   08C9 90 80 A0           1136 	mov	dptr,#_main_customized_plen_1_1
   08CC E4                 1137 	clr	a
   08CD F0                 1138 	movx	@dptr,a
   08CE A3                 1139 	inc	dptr
   08CF F0                 1140 	movx	@dptr,a
                           1141 ;	../main.c:208: for(i=0;i<PLOAD_LEN;i++)
   08D0 7D 00              1142 	mov	r5,#0x00
   08D2 7E 00              1143 	mov	r6,#0x00
   08D4                    1144 00166$:
   08D4 C3                 1145 	clr	c
   08D5 ED                 1146 	mov	a,r5
   08D6 94 20              1147 	subb	a,#0x20
   08D8 EE                 1148 	mov	a,r6
   08D9 64 80              1149 	xrl	a,#0x80
   08DB 94 80              1150 	subb	a,#0x80
   08DD 50 18              1151 	jnc	00124$
                           1152 ;	../main.c:210: packet[i]=i+9;
   08DF ED                 1153 	mov	a,r5
   08E0 24 7A              1154 	add	a,#_packet
   08E2 F5 82              1155 	mov	dpl,a
   08E4 EE                 1156 	mov	a,r6
   08E5 34 80              1157 	addc	a,#(_packet >> 8)
   08E7 F5 83              1158 	mov	dph,a
   08E9 8D 07              1159 	mov	ar7,r5
   08EB 74 09              1160 	mov	a,#0x09
   08ED 2F                 1161 	add	a,r7
   08EE FF                 1162 	mov	r7,a
   08EF F0                 1163 	movx	@dptr,a
                           1164 ;	../main.c:208: for(i=0;i<PLOAD_LEN;i++)
   08F0 0D                 1165 	inc	r5
   08F1 BD 00 E0           1166 	cjne	r5,#0x00,00166$
   08F4 0E                 1167 	inc	r6
   08F5 80 DD              1168 	sjmp	00166$
   08F7                    1169 00124$:
                           1170 ;	../main.c:214: usb_send_packet(ACKbuf, 3);
   08F7 90 80 DF           1171 	mov	dptr,#_usb_send_packet_PARM_2
   08FA 74 03              1172 	mov	a,#0x03
   08FC F0                 1173 	movx	@dptr,a
   08FD 90 80 A8           1174 	mov	dptr,#_main_ACKbuf_1_1
   0900 75 F0 00           1175 	mov	b,#0x00
   0903 12 0C 92           1176 	lcall	_usb_send_packet
                           1177 ;	../main.c:215: break;
   0906 02 06 16           1178 	ljmp	00148$
                           1179 ;	../main.c:218: case EPL_NEW_COUNTER:
   0909                    1180 00125$:
                           1181 ;	../main.c:219: total_pkt_count = 1;
   0909 90 80 9A           1182 	mov	dptr,#_main_total_pkt_count_1_1
   090C 74 01              1183 	mov	a,#0x01
   090E F0                 1184 	movx	@dptr,a
   090F E4                 1185 	clr	a
   0910 A3                 1186 	inc	dptr
   0911 F0                 1187 	movx	@dptr,a
                           1188 ;	../main.c:220: usb_send_packet(ACKbuf, 3);
   0912 90 80 DF           1189 	mov	dptr,#_usb_send_packet_PARM_2
   0915 74 03              1190 	mov	a,#0x03
   0917 F0                 1191 	movx	@dptr,a
   0918 90 80 A8           1192 	mov	dptr,#_main_ACKbuf_1_1
   091B 75 F0 00           1193 	mov	b,#0x00
   091E 12 0C 92           1194 	lcall	_usb_send_packet
                           1195 ;	../main.c:221: break;
   0921 02 06 16           1196 	ljmp	00148$
                           1197 ;	../main.c:223: case EPL_RUN_SENDER:
   0924                    1198 00126$:
                           1199 ;	../main.c:225: epl_rf_en_enter_tx_mode();
   0924 C0 02              1200 	push	ar2
   0926 C0 03              1201 	push	ar3
   0928 C0 04              1202 	push	ar4
   092A 12 04 38           1203 	lcall	_epl_rf_en_enter_tx_mode
                           1204 ;	../main.c:228: hal_nrf_clear_irq_flag(HAL_NRF_TX_DS);
   092D 75 82 05           1205 	mov	dpl,#0x05
   0930 12 0E 0B           1206 	lcall	_hal_nrf_clear_irq_flag
                           1207 ;	../main.c:229: hal_nrf_clear_irq_flag(HAL_NRF_MAX_RT);
   0933 75 82 04           1208 	mov	dpl,#0x04
   0936 12 0E 0B           1209 	lcall	_hal_nrf_clear_irq_flag
                           1210 ;	../main.c:231: epl_uart_putstr("cus plen =");
   0939 90 34 17           1211 	mov	dptr,#__str_1
   093C 75 F0 80           1212 	mov	b,#0x80
   093F 12 18 9D           1213 	lcall	_epl_uart_putstr
                           1214 ;	../main.c:232: epl_uart_putint(customized_plen);
   0942 90 80 A0           1215 	mov	dptr,#_main_customized_plen_1_1
   0945 E0                 1216 	movx	a,@dptr
   0946 FD                 1217 	mov	r5,a
   0947 A3                 1218 	inc	dptr
   0948 E0                 1219 	movx	a,@dptr
   0949 FE                 1220 	mov	r6,a
   094A 8D 82              1221 	mov	dpl,r5
   094C 8E 83              1222 	mov	dph,r6
   094E C0 05              1223 	push	ar5
   0950 C0 06              1224 	push	ar6
   0952 12 19 02           1225 	lcall	_epl_uart_putint
                           1226 ;	../main.c:233: epl_uart_putstr("data len =");
   0955 90 34 22           1227 	mov	dptr,#__str_2
   0958 75 F0 80           1228 	mov	b,#0x80
   095B 12 18 9D           1229 	lcall	_epl_uart_putstr
   095E D0 06              1230 	pop	ar6
   0960 D0 05              1231 	pop	ar5
   0962 D0 04              1232 	pop	ar4
   0964 D0 03              1233 	pop	ar3
   0966 D0 02              1234 	pop	ar2
                           1235 ;	../main.c:234: epl_uart_putint(data_length);
   0968 8A 82              1236 	mov	dpl,r2
   096A 8B 83              1237 	mov	dph,r3
   096C C0 04              1238 	push	ar4
   096E C0 05              1239 	push	ar5
   0970 C0 06              1240 	push	ar6
   0972 12 19 02           1241 	lcall	_epl_uart_putint
   0975 D0 06              1242 	pop	ar6
   0977 D0 05              1243 	pop	ar5
   0979 D0 04              1244 	pop	ar4
                           1245 ;	../main.c:236: if (ubuf[2] == AUTO_PLOAD){
   097B 90 80 3A           1246 	mov	dptr,#(_ubuf + 0x0002)
   097E E0                 1247 	movx	a,@dptr
   097F FA                 1248 	mov	r2,a
   0980 BA 01 35           1249 	cjne	r2,#0x01,00128$
                           1250 ;	../main.c:237: epl_uart_putstr("auto pload\r\n");
   0983 90 34 2D           1251 	mov	dptr,#__str_3
   0986 75 F0 80           1252 	mov	b,#0x80
   0989 C0 04              1253 	push	ar4
   098B 12 18 9D           1254 	lcall	_epl_uart_putstr
   098E D0 04              1255 	pop	ar4
                           1256 ;	../main.c:238: packet[0] = total_pkt_count++;
   0990 90 80 9A           1257 	mov	dptr,#_main_total_pkt_count_1_1
   0993 E0                 1258 	movx	a,@dptr
   0994 FA                 1259 	mov	r2,a
   0995 A3                 1260 	inc	dptr
   0996 E0                 1261 	movx	a,@dptr
   0997 FB                 1262 	mov	r3,a
   0998 90 80 9A           1263 	mov	dptr,#_main_total_pkt_count_1_1
   099B 74 01              1264 	mov	a,#0x01
   099D 2A                 1265 	add	a,r2
   099E F0                 1266 	movx	@dptr,a
   099F E4                 1267 	clr	a
   09A0 3B                 1268 	addc	a,r3
   09A1 A3                 1269 	inc	dptr
   09A2 F0                 1270 	movx	@dptr,a
   09A3 90 80 7A           1271 	mov	dptr,#_packet
   09A6 EA                 1272 	mov	a,r2
   09A7 F0                 1273 	movx	@dptr,a
                           1274 ;	../main.c:239: epl_rf_en_send(packet, data_length);
   09A8 90 80 2E           1275 	mov	dptr,#_epl_rf_en_send_PARM_2
   09AB EC                 1276 	mov	a,r4
   09AC F0                 1277 	movx	@dptr,a
   09AD 90 80 7A           1278 	mov	dptr,#_packet
   09B0 75 F0 00           1279 	mov	b,#0x00
   09B3 12 04 CC           1280 	lcall	_epl_rf_en_send
   09B6 80 1F              1281 	sjmp	00130$
   09B8                    1282 00128$:
                           1283 ;	../main.c:242: epl_uart_putstr("usrs pload\r\n");
   09B8 90 34 3A           1284 	mov	dptr,#__str_4
   09BB 75 F0 80           1285 	mov	b,#0x80
   09BE C0 05              1286 	push	ar5
   09C0 C0 06              1287 	push	ar6
   09C2 12 18 9D           1288 	lcall	_epl_uart_putstr
   09C5 D0 06              1289 	pop	ar6
   09C7 D0 05              1290 	pop	ar5
                           1291 ;	../main.c:243: epl_rf_en_send(packet, customized_plen);
   09C9 90 80 2E           1292 	mov	dptr,#_epl_rf_en_send_PARM_2
   09CC ED                 1293 	mov	a,r5
   09CD F0                 1294 	movx	@dptr,a
   09CE 90 80 7A           1295 	mov	dptr,#_packet
   09D1 75 F0 00           1296 	mov	b,#0x00
   09D4 12 04 CC           1297 	lcall	_epl_rf_en_send
                           1298 ;	../main.c:245: LED_Toggle();
   09D7                    1299 00130$:
   09D7 63 80 30           1300 	xrl	_P0,#0x30
                           1301 ;	../main.c:246: mdelay(20);
   09DA 90 00 14           1302 	mov	dptr,#0x0014
   09DD 12 32 91           1303 	lcall	_mdelay
                           1304 ;	../main.c:248: array_cp(temp_buf, ACKbuf, 3);
   09E0 90 80 D3           1305 	mov	dptr,#_array_cp_PARM_2
   09E3 74 A8              1306 	mov	a,#_main_ACKbuf_1_1
   09E5 F0                 1307 	movx	@dptr,a
   09E6 A3                 1308 	inc	dptr
   09E7 74 80              1309 	mov	a,#(_main_ACKbuf_1_1 >> 8)
   09E9 F0                 1310 	movx	@dptr,a
   09EA A3                 1311 	inc	dptr
   09EB E4                 1312 	clr	a
   09EC F0                 1313 	movx	@dptr,a
   09ED 90 80 D6           1314 	mov	dptr,#_array_cp_PARM_3
   09F0 74 03              1315 	mov	a,#0x03
   09F2 F0                 1316 	movx	@dptr,a
   09F3 E4                 1317 	clr	a
   09F4 A3                 1318 	inc	dptr
   09F5 F0                 1319 	movx	@dptr,a
   09F6 90 80 AC           1320 	mov	dptr,#_main_temp_buf_1_1
   09F9 75 F0 00           1321 	mov	b,#0x00
   09FC 12 0B 58           1322 	lcall	_array_cp
                           1323 ;	../main.c:249: temp_buf[3] = hal_nrf_read_reg(OBSERVE_TX) & 0x0F;
   09FF 75 82 08           1324 	mov	dpl,#0x08
   0A02 12 15 95           1325 	lcall	_hal_nrf_read_reg
   0A05 E5 82              1326 	mov	a,dpl
   0A07 54 0F              1327 	anl	a,#0x0F
   0A09 90 80 AF           1328 	mov	dptr,#(_main_temp_buf_1_1 + 0x0003)
   0A0C F0                 1329 	movx	@dptr,a
                           1330 ;	../main.c:250: usb_send_packet(temp_buf, 4);
   0A0D 90 80 DF           1331 	mov	dptr,#_usb_send_packet_PARM_2
   0A10 74 04              1332 	mov	a,#0x04
   0A12 F0                 1333 	movx	@dptr,a
   0A13 90 80 AC           1334 	mov	dptr,#_main_temp_buf_1_1
   0A16 75 F0 00           1335 	mov	b,#0x00
   0A19 12 0C 92           1336 	lcall	_usb_send_packet
                           1337 ;	../main.c:252: epl_rf_en_enter_rx_mode();
   0A1C 12 04 40           1338 	lcall	_epl_rf_en_enter_rx_mode
                           1339 ;	../main.c:254: break;
   0A1F 02 06 16           1340 	ljmp	00148$
                           1341 ;	../main.c:257: case EPL_RUN_DUMPER:
   0A22                    1342 00133$:
                           1343 ;	../main.c:259: hal_nrf_clear_irq_flag(HAL_NRF_RX_DR);
   0A22 75 82 06           1344 	mov	dpl,#0x06
   0A25 12 0E 0B           1345 	lcall	_hal_nrf_clear_irq_flag
                           1346 ;	../main.c:260: hal_nrf_flush_rx();
   0A28 12 14 E3           1347 	lcall	_hal_nrf_flush_rx
                           1348 ;	../main.c:261: epl_rf_en_enter_rx_mode();
   0A2B 12 04 40           1349 	lcall	_epl_rf_en_enter_rx_mode
                           1350 ;	../main.c:263: while (1)
   0A2E                    1351 00142$:
                           1352 ;	../main.c:274: if (ubuf[1] == 0xf5)
   0A2E 90 80 39           1353 	mov	dptr,#(_ubuf + 0x0001)
   0A31 E0                 1354 	movx	a,@dptr
   0A32 FA                 1355 	mov	r2,a
   0A33 BA F5 03           1356 	cjne	r2,#0xF5,00239$
   0A36 02 06 16           1357 	ljmp	00148$
   0A39                    1358 00239$:
                           1359 ;	../main.c:279: if (hal_nrf_rx_fifo_empty()==0)
   0A39 12 12 CD           1360 	lcall	_hal_nrf_rx_fifo_empty
   0A3C E5 82              1361 	mov	a,dpl
   0A3E 70 EE              1362 	jnz	00142$
                           1363 ;	../main.c:281: pipe_source[0] = hal_nrf_get_rx_data_source();
   0A40 12 14 92           1364 	lcall	_hal_nrf_get_rx_data_source
   0A43 AA 82              1365 	mov	r2,dpl
   0A45 90 80 A2           1366 	mov	dptr,#_main_pipe_source_1_1
   0A48 EA                 1367 	mov	a,r2
   0A49 F0                 1368 	movx	@dptr,a
                           1369 ;	../main.c:282: hal_nrf_read_rx_pload(temp_buf);
   0A4A 90 80 AC           1370 	mov	dptr,#_main_temp_buf_1_1
   0A4D 75 F0 00           1371 	mov	b,#0x00
   0A50 12 14 9E           1372 	lcall	_hal_nrf_read_rx_pload
                           1373 ;	../main.c:285: temp_buf[32] = pipe_source[0];
   0A53 90 80 A2           1374 	mov	dptr,#_main_pipe_source_1_1
   0A56 E0                 1375 	movx	a,@dptr
   0A57 90 80 CC           1376 	mov	dptr,#(_main_temp_buf_1_1 + 0x0020)
   0A5A F0                 1377 	movx	@dptr,a
                           1378 ;	../main.c:286: usb_send_packet(temp_buf, 33);
   0A5B 90 80 DF           1379 	mov	dptr,#_usb_send_packet_PARM_2
   0A5E 74 21              1380 	mov	a,#0x21
   0A60 F0                 1381 	movx	@dptr,a
   0A61 90 80 AC           1382 	mov	dptr,#_main_temp_buf_1_1
   0A64 75 F0 00           1383 	mov	b,#0x00
   0A67 12 0C 92           1384 	lcall	_usb_send_packet
                           1385 ;	../main.c:288: LED_Toggle();
   0A6A 63 80 30           1386 	xrl	_P0,#0x30
                           1387 ;	../main.c:293: case EPL_SHOW_CONFIG:
   0A6D 80 BF              1388 	sjmp	00142$
   0A6F                    1389 00144$:
                           1390 ;	../main.c:294: epl_uart_putstr("\r\n1. CONFIG = ");
   0A6F 90 34 47           1391 	mov	dptr,#__str_5
   0A72 75 F0 80           1392 	mov	b,#0x80
   0A75 12 18 9D           1393 	lcall	_epl_uart_putstr
                           1394 ;	../main.c:295: epl_uart_puthex(hal_nrf_read_reg(RF_CH));
   0A78 75 82 05           1395 	mov	dpl,#0x05
   0A7B 12 15 95           1396 	lcall	_hal_nrf_read_reg
   0A7E 7B 00              1397 	mov	r3,#0x00
   0A80 8B 83              1398 	mov	dph,r3
   0A82 12 19 68           1399 	lcall	_epl_uart_puthex
                           1400 ;	../main.c:296: epl_uart_putstr("\r\n2. EN_AA = ");
   0A85 90 34 56           1401 	mov	dptr,#__str_6
   0A88 75 F0 80           1402 	mov	b,#0x80
   0A8B 12 18 9D           1403 	lcall	_epl_uart_putstr
                           1404 ;	../main.c:297: epl_uart_puthex(hal_nrf_read_reg(EN_AA));
   0A8E 75 82 01           1405 	mov	dpl,#0x01
   0A91 12 15 95           1406 	lcall	_hal_nrf_read_reg
   0A94 7B 00              1407 	mov	r3,#0x00
   0A96 8B 83              1408 	mov	dph,r3
   0A98 12 19 68           1409 	lcall	_epl_uart_puthex
                           1410 ;	../main.c:298: epl_uart_putstr("\r\n3. EN_RXADDR = ");
   0A9B 90 34 64           1411 	mov	dptr,#__str_7
   0A9E 75 F0 80           1412 	mov	b,#0x80
   0AA1 12 18 9D           1413 	lcall	_epl_uart_putstr
                           1414 ;	../main.c:299: epl_uart_puthex(hal_nrf_read_reg(EN_RXADDR));
   0AA4 75 82 02           1415 	mov	dpl,#0x02
   0AA7 12 15 95           1416 	lcall	_hal_nrf_read_reg
   0AAA 7B 00              1417 	mov	r3,#0x00
   0AAC 8B 83              1418 	mov	dph,r3
   0AAE 12 19 68           1419 	lcall	_epl_uart_puthex
                           1420 ;	../main.c:300: epl_uart_putstr("\r\n4. RF_SETUP = ");
   0AB1 90 34 76           1421 	mov	dptr,#__str_8
   0AB4 75 F0 80           1422 	mov	b,#0x80
   0AB7 12 18 9D           1423 	lcall	_epl_uart_putstr
                           1424 ;	../main.c:301: epl_uart_puthex(hal_nrf_read_reg(RF_SETUP));
   0ABA 75 82 06           1425 	mov	dpl,#0x06
   0ABD 12 15 95           1426 	lcall	_hal_nrf_read_reg
   0AC0 7B 00              1427 	mov	r3,#0x00
   0AC2 8B 83              1428 	mov	dph,r3
   0AC4 12 19 68           1429 	lcall	_epl_uart_puthex
                           1430 ;	../main.c:302: epl_uart_putstr("\r\n5. STATUS = ");
   0AC7 90 34 87           1431 	mov	dptr,#__str_9
   0ACA 75 F0 80           1432 	mov	b,#0x80
   0ACD 12 18 9D           1433 	lcall	_epl_uart_putstr
                           1434 ;	../main.c:303: epl_uart_puthex(hal_nrf_read_reg(STATUS));
   0AD0 75 82 07           1435 	mov	dpl,#0x07
   0AD3 12 15 95           1436 	lcall	_hal_nrf_read_reg
   0AD6 7B 00              1437 	mov	r3,#0x00
   0AD8 8B 83              1438 	mov	dph,r3
   0ADA 12 19 68           1439 	lcall	_epl_uart_puthex
                           1440 ;	../main.c:304: epl_uart_putstr("\r\n6. RX_PW_P0 = ");
   0ADD 90 34 96           1441 	mov	dptr,#__str_10
   0AE0 75 F0 80           1442 	mov	b,#0x80
   0AE3 12 18 9D           1443 	lcall	_epl_uart_putstr
                           1444 ;	../main.c:305: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P0));
   0AE6 75 82 11           1445 	mov	dpl,#0x11
   0AE9 12 15 95           1446 	lcall	_hal_nrf_read_reg
   0AEC 7B 00              1447 	mov	r3,#0x00
   0AEE 8B 83              1448 	mov	dph,r3
   0AF0 12 19 68           1449 	lcall	_epl_uart_puthex
                           1450 ;	../main.c:306: epl_uart_putstr("\r\n7. RX_P0 = ");
   0AF3 90 34 A7           1451 	mov	dptr,#__str_11
   0AF6 75 F0 80           1452 	mov	b,#0x80
   0AF9 12 18 9D           1453 	lcall	_epl_uart_putstr
                           1454 ;	../main.c:307: hal_nrf_read_multibyte_reg(0x0A, temp_addr);
   0AFC 90 81 13           1455 	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
   0AFF 74 CE              1456 	mov	a,#_main_temp_addr_1_1
   0B01 F0                 1457 	movx	@dptr,a
   0B02 A3                 1458 	inc	dptr
   0B03 74 80              1459 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0B05 F0                 1460 	movx	@dptr,a
   0B06 A3                 1461 	inc	dptr
   0B07 E4                 1462 	clr	a
   0B08 F0                 1463 	movx	@dptr,a
   0B09 75 82 0A           1464 	mov	dpl,#0x0A
   0B0C 12 16 20           1465 	lcall	_hal_nrf_read_multibyte_reg
                           1466 ;	../main.c:308: epl_uart_puthex(temp_addr[0]);
   0B0F 90 80 CE           1467 	mov	dptr,#_main_temp_addr_1_1
   0B12 E0                 1468 	movx	a,@dptr
   0B13 FA                 1469 	mov	r2,a
   0B14 7B 00              1470 	mov	r3,#0x00
   0B16 8A 82              1471 	mov	dpl,r2
   0B18 8B 83              1472 	mov	dph,r3
   0B1A 12 19 68           1473 	lcall	_epl_uart_puthex
                           1474 ;	../main.c:309: epl_uart_puthex(temp_addr[1]);
   0B1D 90 80 CF           1475 	mov	dptr,#(_main_temp_addr_1_1 + 0x0001)
   0B20 E0                 1476 	movx	a,@dptr
   0B21 FA                 1477 	mov	r2,a
   0B22 7B 00              1478 	mov	r3,#0x00
   0B24 8A 82              1479 	mov	dpl,r2
   0B26 8B 83              1480 	mov	dph,r3
   0B28 12 19 68           1481 	lcall	_epl_uart_puthex
                           1482 ;	../main.c:310: epl_uart_puthex(temp_addr[2]);
   0B2B 90 80 D0           1483 	mov	dptr,#(_main_temp_addr_1_1 + 0x0002)
   0B2E E0                 1484 	movx	a,@dptr
   0B2F FA                 1485 	mov	r2,a
   0B30 7B 00              1486 	mov	r3,#0x00
   0B32 8A 82              1487 	mov	dpl,r2
   0B34 8B 83              1488 	mov	dph,r3
   0B36 12 19 68           1489 	lcall	_epl_uart_puthex
                           1490 ;	../main.c:311: epl_uart_puthex(temp_addr[3]);
   0B39 90 80 D1           1491 	mov	dptr,#(_main_temp_addr_1_1 + 0x0003)
   0B3C E0                 1492 	movx	a,@dptr
   0B3D FA                 1493 	mov	r2,a
   0B3E 7B 00              1494 	mov	r3,#0x00
   0B40 8A 82              1495 	mov	dpl,r2
   0B42 8B 83              1496 	mov	dph,r3
   0B44 12 19 68           1497 	lcall	_epl_uart_puthex
                           1498 ;	../main.c:312: epl_uart_puthex(temp_addr[4]);
   0B47 90 80 D2           1499 	mov	dptr,#(_main_temp_addr_1_1 + 0x0004)
   0B4A E0                 1500 	movx	a,@dptr
   0B4B FA                 1501 	mov	r2,a
   0B4C 7B 00              1502 	mov	r3,#0x00
   0B4E 8A 82              1503 	mov	dpl,r2
   0B50 8B 83              1504 	mov	dph,r3
   0B52 12 19 68           1505 	lcall	_epl_uart_puthex
                           1506 ;	../main.c:318: }// end switch case
   0B55 02 06 16           1507 	ljmp	00148$
                           1508 ;------------------------------------------------------------
                           1509 ;Allocation info for local variables in function 'array_cp'
                           1510 ;------------------------------------------------------------
                           1511 ;src_array                 Allocated with name '_array_cp_PARM_2'
                           1512 ;len                       Allocated with name '_array_cp_PARM_3'
                           1513 ;dst_array                 Allocated with name '_array_cp_dst_array_1_1'
                           1514 ;i                         Allocated with name '_array_cp_i_1_1'
                           1515 ;sloc0                     Allocated with name '_array_cp_sloc0_1_0'
                           1516 ;sloc1                     Allocated with name '_array_cp_sloc1_1_0'
                           1517 ;sloc2                     Allocated with name '_array_cp_sloc2_1_0'
                           1518 ;------------------------------------------------------------
                           1519 ;	../main.c:322: void array_cp(unsigned char *dst_array, unsigned char *src_array, int len)
                           1520 ;	-----------------------------------------
                           1521 ;	 function array_cp
                           1522 ;	-----------------------------------------
   0B58                    1523 _array_cp:
   0B58 AA F0              1524 	mov	r2,b
   0B5A AB 83              1525 	mov	r3,dph
   0B5C E5 82              1526 	mov	a,dpl
   0B5E 90 80 D8           1527 	mov	dptr,#_array_cp_dst_array_1_1
   0B61 F0                 1528 	movx	@dptr,a
   0B62 A3                 1529 	inc	dptr
   0B63 EB                 1530 	mov	a,r3
   0B64 F0                 1531 	movx	@dptr,a
   0B65 A3                 1532 	inc	dptr
   0B66 EA                 1533 	mov	a,r2
   0B67 F0                 1534 	movx	@dptr,a
                           1535 ;	../main.c:326: for(i=0;i<len;i++)
   0B68 90 80 D8           1536 	mov	dptr,#_array_cp_dst_array_1_1
   0B6B E0                 1537 	movx	a,@dptr
   0B6C FA                 1538 	mov	r2,a
   0B6D A3                 1539 	inc	dptr
   0B6E E0                 1540 	movx	a,@dptr
   0B6F FB                 1541 	mov	r3,a
   0B70 A3                 1542 	inc	dptr
   0B71 E0                 1543 	movx	a,@dptr
   0B72 FC                 1544 	mov	r4,a
   0B73 90 80 D3           1545 	mov	dptr,#_array_cp_PARM_2
   0B76 E0                 1546 	movx	a,@dptr
   0B77 F5 14              1547 	mov	_array_cp_sloc1_1_0,a
   0B79 A3                 1548 	inc	dptr
   0B7A E0                 1549 	movx	a,@dptr
   0B7B F5 15              1550 	mov	(_array_cp_sloc1_1_0 + 1),a
   0B7D A3                 1551 	inc	dptr
   0B7E E0                 1552 	movx	a,@dptr
   0B7F F5 16              1553 	mov	(_array_cp_sloc1_1_0 + 2),a
   0B81 90 80 D6           1554 	mov	dptr,#_array_cp_PARM_3
   0B84 E0                 1555 	movx	a,@dptr
   0B85 F8                 1556 	mov	r0,a
   0B86 A3                 1557 	inc	dptr
   0B87 E0                 1558 	movx	a,@dptr
   0B88 F9                 1559 	mov	r1,a
   0B89 E4                 1560 	clr	a
   0B8A F5 12              1561 	mov	_array_cp_sloc0_1_0,a
   0B8C F5 13              1562 	mov	(_array_cp_sloc0_1_0 + 1),a
   0B8E                    1563 00101$:
   0B8E C3                 1564 	clr	c
   0B8F E5 12              1565 	mov	a,_array_cp_sloc0_1_0
   0B91 98                 1566 	subb	a,r0
   0B92 E5 13              1567 	mov	a,(_array_cp_sloc0_1_0 + 1)
   0B94 64 80              1568 	xrl	a,#0x80
   0B96 89 F0              1569 	mov	b,r1
   0B98 63 F0 80           1570 	xrl	b,#0x80
   0B9B 95 F0              1571 	subb	a,b
   0B9D 50 40              1572 	jnc	00105$
                           1573 ;	../main.c:327: dst_array[i] = src_array[i];
   0B9F C0 00              1574 	push	ar0
   0BA1 C0 01              1575 	push	ar1
   0BA3 E5 12              1576 	mov	a,_array_cp_sloc0_1_0
   0BA5 2A                 1577 	add	a,r2
   0BA6 F5 17              1578 	mov	_array_cp_sloc2_1_0,a
   0BA8 E5 13              1579 	mov	a,(_array_cp_sloc0_1_0 + 1)
   0BAA 3B                 1580 	addc	a,r3
   0BAB F5 18              1581 	mov	(_array_cp_sloc2_1_0 + 1),a
   0BAD 8C 19              1582 	mov	(_array_cp_sloc2_1_0 + 2),r4
   0BAF E5 12              1583 	mov	a,_array_cp_sloc0_1_0
   0BB1 25 14              1584 	add	a,_array_cp_sloc1_1_0
   0BB3 FE                 1585 	mov	r6,a
   0BB4 E5 13              1586 	mov	a,(_array_cp_sloc0_1_0 + 1)
   0BB6 35 15              1587 	addc	a,(_array_cp_sloc1_1_0 + 1)
   0BB8 FF                 1588 	mov	r7,a
   0BB9 AD 16              1589 	mov	r5,(_array_cp_sloc1_1_0 + 2)
   0BBB 8E 82              1590 	mov	dpl,r6
   0BBD 8F 83              1591 	mov	dph,r7
   0BBF 8D F0              1592 	mov	b,r5
   0BC1 12 33 F7           1593 	lcall	__gptrget
   0BC4 FE                 1594 	mov	r6,a
   0BC5 85 17 82           1595 	mov	dpl,_array_cp_sloc2_1_0
   0BC8 85 18 83           1596 	mov	dph,(_array_cp_sloc2_1_0 + 1)
   0BCB 85 19 F0           1597 	mov	b,(_array_cp_sloc2_1_0 + 2)
   0BCE 12 32 78           1598 	lcall	__gptrput
                           1599 ;	../main.c:326: for(i=0;i<len;i++)
   0BD1 05 12              1600 	inc	_array_cp_sloc0_1_0
   0BD3 E4                 1601 	clr	a
   0BD4 B5 12 02           1602 	cjne	a,_array_cp_sloc0_1_0,00111$
   0BD7 05 13              1603 	inc	(_array_cp_sloc0_1_0 + 1)
   0BD9                    1604 00111$:
   0BD9 D0 01              1605 	pop	ar1
   0BDB D0 00              1606 	pop	ar0
   0BDD 80 AF              1607 	sjmp	00101$
   0BDF                    1608 00105$:
   0BDF 22                 1609 	ret
                           1610 	.area CSEG    (CODE)
                           1611 	.area CONST   (CODE)
   3417                    1612 __str_1:
   3417 63 75 73 20 70 6C  1613 	.ascii "cus plen ="
        65 6E 20 3D
   3421 00                 1614 	.db 0x00
   3422                    1615 __str_2:
   3422 64 61 74 61 20 6C  1616 	.ascii "data len ="
        65 6E 20 3D
   342C 00                 1617 	.db 0x00
   342D                    1618 __str_3:
   342D 61 75 74 6F 20 70  1619 	.ascii "auto pload"
        6C 6F 61 64
   3437 0D                 1620 	.db 0x0D
   3438 0A                 1621 	.db 0x0A
   3439 00                 1622 	.db 0x00
   343A                    1623 __str_4:
   343A 75 73 72 73 20 70  1624 	.ascii "usrs pload"
        6C 6F 61 64
   3444 0D                 1625 	.db 0x0D
   3445 0A                 1626 	.db 0x0A
   3446 00                 1627 	.db 0x00
   3447                    1628 __str_5:
   3447 0D                 1629 	.db 0x0D
   3448 0A                 1630 	.db 0x0A
   3449 31 2E 20 43 4F 4E  1631 	.ascii "1. CONFIG = "
        46 49 47 20 3D 20
   3455 00                 1632 	.db 0x00
   3456                    1633 __str_6:
   3456 0D                 1634 	.db 0x0D
   3457 0A                 1635 	.db 0x0A
   3458 32 2E 20 45 4E 5F  1636 	.ascii "2. EN_AA = "
        41 41 20 3D 20
   3463 00                 1637 	.db 0x00
   3464                    1638 __str_7:
   3464 0D                 1639 	.db 0x0D
   3465 0A                 1640 	.db 0x0A
   3466 33 2E 20 45 4E 5F  1641 	.ascii "3. EN_RXADDR = "
        52 58 41 44 44 52
        20 3D 20
   3475 00                 1642 	.db 0x00
   3476                    1643 __str_8:
   3476 0D                 1644 	.db 0x0D
   3477 0A                 1645 	.db 0x0A
   3478 34 2E 20 52 46 5F  1646 	.ascii "4. RF_SETUP = "
        53 45 54 55 50 20
        3D 20
   3486 00                 1647 	.db 0x00
   3487                    1648 __str_9:
   3487 0D                 1649 	.db 0x0D
   3488 0A                 1650 	.db 0x0A
   3489 35 2E 20 53 54 41  1651 	.ascii "5. STATUS = "
        54 55 53 20 3D 20
   3495 00                 1652 	.db 0x00
   3496                    1653 __str_10:
   3496 0D                 1654 	.db 0x0D
   3497 0A                 1655 	.db 0x0A
   3498 36 2E 20 52 58 5F  1656 	.ascii "6. RX_PW_P0 = "
        50 57 5F 50 30 20
        3D 20
   34A6 00                 1657 	.db 0x00
   34A7                    1658 __str_11:
   34A7 0D                 1659 	.db 0x0D
   34A8 0A                 1660 	.db 0x0A
   34A9 37 2E 20 52 58 5F  1661 	.ascii "7. RX_P0 = "
        50 30 20 3D 20
   34B4 00                 1662 	.db 0x00
                           1663 	.area XINIT   (CODE)
                           1664 	.area CABS    (ABS,CODE)
