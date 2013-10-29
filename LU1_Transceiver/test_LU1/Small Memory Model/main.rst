                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Mon Oct 14 23:38:20 2013
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
                            374 ;--------------------------------------------------------
                            375 ; overlayable items in internal ram 
                            376 ;--------------------------------------------------------
                            377 	.area	OSEG    (OVR,DATA)
   0010                     378 _array_cp_sloc0_1_0::
   0010                     379 	.ds 2
   0012                     380 _array_cp_sloc1_1_0::
   0012                     381 	.ds 3
   0015                     382 _array_cp_sloc2_1_0::
   0015                     383 	.ds 3
                            384 ;--------------------------------------------------------
                            385 ; Stack segment in internal ram 
                            386 ;--------------------------------------------------------
                            387 	.area	SSEG	(DATA)
   004B                     388 __start__stack:
   004B                     389 	.ds	1
                            390 
                            391 ;--------------------------------------------------------
                            392 ; indirectly addressable internal ram data
                            393 ;--------------------------------------------------------
                            394 	.area ISEG    (DATA)
   0037                     395 _rf_cfg_data::
   0037                     396 	.ds 19
   004A                     397 _cfg::
   004A                     398 	.ds 1
                            399 ;--------------------------------------------------------
                            400 ; absolute internal ram data
                            401 ;--------------------------------------------------------
                            402 	.area IABS    (ABS,DATA)
                            403 	.area IABS    (ABS,DATA)
                            404 ;--------------------------------------------------------
                            405 ; bit data
                            406 ;--------------------------------------------------------
                            407 	.area BSEG    (BIT)
                            408 ;--------------------------------------------------------
                            409 ; paged external ram data
                            410 ;--------------------------------------------------------
                            411 	.area PSEG    (PAG,XDATA)
                            412 ;--------------------------------------------------------
                            413 ; external ram data
                            414 ;--------------------------------------------------------
                            415 	.area XSEG    (XDATA)
   8038                     416 _ubuf::
   8038                     417 	.ds 65
   8079                     418 _usize::
   8079                     419 	.ds 1
   807A                     420 _packet::
   807A                     421 	.ds 32
   809A                     422 _main_total_pkt_count_1_1:
   809A                     423 	.ds 2
   809C                     424 _main_addr_width_1_1:
   809C                     425 	.ds 2
   809E                     426 _main_customized_plen_1_1:
   809E                     427 	.ds 2
   80A0                     428 _main_auto_ack_1_1:
   80A0                     429 	.ds 1
   80A1                     430 _main_ACKbuf_1_1:
   80A1                     431 	.ds 4
   80A5                     432 _main_temp_buf_1_1:
   80A5                     433 	.ds 34
   80C7                     434 _main_temp_addr_1_1:
   80C7                     435 	.ds 5
   80CC                     436 _main_data_length_1_1:
   80CC                     437 	.ds 1
   80CD                     438 _main_addr_buf_1_1:
   80CD                     439 	.ds 5
   80D2                     440 _array_cp_PARM_2:
   80D2                     441 	.ds 3
   80D5                     442 _array_cp_PARM_3:
   80D5                     443 	.ds 2
   80D7                     444 _array_cp_dst_array_1_1:
   80D7                     445 	.ds 3
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
   005B 02 33 4E            492 	ljmp	_usb_wu
   005E                     493 	.ds	5
   0063 02 34 CA            494 	ljmp	_usb_irq
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
                            508 ;	../main.c:42: idata struct epl_lu1_rf_en_config rf_cfg_data = { { 118 }, //-- RF channel --//
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
                            568 ;i                         Allocated with name '_main_i_1_1'
                            569 ;total_pkt_count           Allocated with name '_main_total_pkt_count_1_1'
                            570 ;addr_width                Allocated with name '_main_addr_width_1_1'
                            571 ;customized_plen           Allocated with name '_main_customized_plen_1_1'
                            572 ;pipe_num                  Allocated with name '_main_pipe_num_1_1'
                            573 ;auto_ack                  Allocated with name '_main_auto_ack_1_1'
                            574 ;pipe_source               Allocated with name '_main_pipe_source_1_1'
                            575 ;ACKbuf                    Allocated with name '_main_ACKbuf_1_1'
                            576 ;temp_buf                  Allocated with name '_main_temp_buf_1_1'
                            577 ;temp_addr                 Allocated with name '_main_temp_addr_1_1'
                            578 ;data_length               Allocated with name '_main_data_length_1_1'
                            579 ;dynpd_pipe                Allocated with name '_main_dynpd_pipe_1_1'
                            580 ;addr_buf                  Allocated with name '_main_addr_buf_1_1'
                            581 ;------------------------------------------------------------
                            582 ;	../main.c:58: void main(void) {
                            583 ;	-----------------------------------------
                            584 ;	 function main
                            585 ;	-----------------------------------------
   056A                     586 _main:
                    0002    587 	ar2 = 0x02
                    0003    588 	ar3 = 0x03
                    0004    589 	ar4 = 0x04
                    0005    590 	ar5 = 0x05
                    0006    591 	ar6 = 0x06
                    0007    592 	ar7 = 0x07
                    0000    593 	ar0 = 0x00
                    0001    594 	ar1 = 0x01
                            595 ;	../main.c:60: int total_pkt_count = 1;
   056A 90 80 9A            596 	mov	dptr,#_main_total_pkt_count_1_1
   056D 74 01               597 	mov	a,#0x01
   056F F0                  598 	movx	@dptr,a
   0570 E4                  599 	clr	a
   0571 A3                  600 	inc	dptr
   0572 F0                  601 	movx	@dptr,a
                            602 ;	../main.c:61: int addr_width = 5;
   0573 90 80 9C            603 	mov	dptr,#_main_addr_width_1_1
   0576 74 05               604 	mov	a,#0x05
   0578 F0                  605 	movx	@dptr,a
   0579 E4                  606 	clr	a
   057A A3                  607 	inc	dptr
   057B F0                  608 	movx	@dptr,a
                            609 ;	../main.c:62: int customized_plen = 0;
   057C 90 80 9E            610 	mov	dptr,#_main_customized_plen_1_1
   057F E4                  611 	clr	a
   0580 F0                  612 	movx	@dptr,a
   0581 A3                  613 	inc	dptr
   0582 F0                  614 	movx	@dptr,a
                            615 ;	../main.c:64: epl_rf_en_auto_ack_t auto_ack = 0;
   0583 90 80 A0            616 	mov	dptr,#_main_auto_ack_1_1
   0586 E4                  617 	clr	a
   0587 F0                  618 	movx	@dptr,a
                            619 ;	../main.c:69: unsigned char ACKbuf[] = "ACK";
   0588 90 80 A1            620 	mov	dptr,#_main_ACKbuf_1_1
   058B 74 41               621 	mov	a,#0x41
   058D F0                  622 	movx	@dptr,a
   058E 90 80 A2            623 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0001)
   0591 74 43               624 	mov	a,#0x43
   0593 F0                  625 	movx	@dptr,a
   0594 90 80 A3            626 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0002)
   0597 74 4B               627 	mov	a,#0x4B
   0599 F0                  628 	movx	@dptr,a
   059A 90 80 A4            629 	mov	dptr,#(_main_ACKbuf_1_1 + 0x0003)
                            630 ;	../main.c:72: unsigned char data_length = 0;
   059D E4                  631 	clr	a
   059E F0                  632 	movx	@dptr,a
   059F 90 80 CC            633 	mov	dptr,#_main_data_length_1_1
   05A2 F0                  634 	movx	@dptr,a
                            635 ;	../main.c:76: P0EXP = 0x00;
   05A3 75 C9 00            636 	mov	_P0EXP,#0x00
                            637 ;	../main.c:77: P0ALT = 0x00;
   05A6 75 95 00            638 	mov	_P0ALT,#0x00
                            639 ;	../main.c:78: P0DIR = 0x00;
   05A9 75 94 00            640 	mov	_P0DIR,#0x00
                            641 ;	../main.c:81: epl_uart_init(UART_BAUD_57K6);
   05AC 75 82 03            642 	mov	dpl,#0x03
   05AF 12 1E 11            643 	lcall	_epl_uart_init
                            644 ;	../main.c:83: usb_init(); // Initialize USB
   05B2 12 11 D7            645 	lcall	_usb_init
                            646 ;	../main.c:84: EA = 1; // Enable global IRQ
   05B5 D2 AF               647 	setb	_EA
                            648 ;	../main.c:86: epl_rf_en_quick_init(cfg);
   05B7 78 4A               649 	mov	r0,#_cfg
   05B9 86 02               650 	mov	ar2,@r0
   05BB 7B 00               651 	mov	r3,#0x00
   05BD 7C 40               652 	mov	r4,#0x40
   05BF 8A 82               653 	mov	dpl,r2
   05C1 8B 83               654 	mov	dph,r3
   05C3 8C F0               655 	mov	b,r4
   05C5 12 02 FE            656 	lcall	_epl_rf_en_quick_init
                            657 ;	../main.c:89: hal_nrf_write_reg(FLUSH_TX, 0);
   05C8 90 81 0F            658 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   05CB E4                  659 	clr	a
   05CC F0                  660 	movx	@dptr,a
   05CD 75 82 E1            661 	mov	dpl,#0xE1
   05D0 12 1B AA            662 	lcall	_hal_nrf_write_reg
                            663 ;	../main.c:90: hal_nrf_write_reg(FLUSH_RX, 0);
   05D3 90 81 0F            664 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   05D6 E4                  665 	clr	a
   05D7 F0                  666 	movx	@dptr,a
   05D8 75 82 E2            667 	mov	dpl,#0xE2
   05DB 12 1B AA            668 	lcall	_hal_nrf_write_reg
                            669 ;	../main.c:92: hal_nrf_lock_unlock();
   05DE 12 1A 78            670 	lcall	_hal_nrf_lock_unlock
                            671 ;	../main.c:93: hal_nrf_enable_dynamic_pl();
   05E1 12 19 8B            672 	lcall	_hal_nrf_enable_dynamic_pl
                            673 ;	../main.c:95: LED_Blink(20);
   05E4 63 80 30            674 	xrl	_P0,#0x30
   05E7 90 00 14            675 	mov	dptr,#0x0014
   05EA 12 38 88            676 	lcall	_mdelay
   05ED 63 80 30            677 	xrl	_P0,#0x30
   05F0 90 00 14            678 	mov	dptr,#0x0014
   05F3 12 38 88            679 	lcall	_mdelay
                            680 ;	../main.c:96: epl_uart_putstr("start!");
   05F6 90 3A 0E            681 	mov	dptr,#__str_1
   05F9 75 F0 80            682 	mov	b,#0x80
   05FC 12 1E 94            683 	lcall	_epl_uart_putstr
                            684 ;	../main.c:97: while (1) {
   05FF                     685 00192$:
                            686 ;	../main.c:98: usb_recv_packet();
   05FF 12 12 CB            687 	lcall	_usb_recv_packet
                            688 ;	../main.c:99: switch (ubuf[1]) {
   0602 90 80 39            689 	mov	dptr,#(_ubuf + 0x0001)
   0605 E0                  690 	movx	a,@dptr
   0606 FA                  691 	mov	r2,a
   0607 BA 01 03            692 	cjne	r2,#0x01,00302$
   060A 02 07 38            693 	ljmp	00112$
   060D                     694 00302$:
   060D BA 02 03            695 	cjne	r2,#0x02,00303$
   0610 02 07 65            696 	ljmp	00113$
   0613                     697 00303$:
   0613 BA 03 03            698 	cjne	r2,#0x03,00304$
   0616 02 07 80            699 	ljmp	00114$
   0619                     700 00304$:
   0619 BA 04 03            701 	cjne	r2,#0x04,00305$
   061C 02 07 9B            702 	ljmp	00115$
   061F                     703 00305$:
   061F BA 05 03            704 	cjne	r2,#0x05,00306$
   0622 02 09 C8            705 	ljmp	00128$
   0625                     706 00306$:
   0625 BA 10 03            707 	cjne	r2,#0x10,00307$
   0628 02 09 FC            708 	ljmp	00269$
   062B                     709 00307$:
   062B BA 11 03            710 	cjne	r2,#0x11,00308$
   062E 02 0A 71            711 	ljmp	00271$
   0631                     712 00308$:
   0631 BA 12 03            713 	cjne	r2,#0x12,00309$
   0634 02 0A CA            714 	ljmp	00273$
   0637                     715 00309$:
   0637 BA 13 03            716 	cjne	r2,#0x13,00310$
   063A 02 0B 23            717 	ljmp	00275$
   063D                     718 00310$:
   063D BA 14 03            719 	cjne	r2,#0x14,00311$
   0640 02 0B 7C            720 	ljmp	00277$
   0643                     721 00311$:
   0643 BA 15 03            722 	cjne	r2,#0x15,00312$
   0646 02 0B D5            723 	ljmp	00279$
   0649                     724 00312$:
   0649 BA 30 03            725 	cjne	r2,#0x30,00313$
   064C 02 07 BE            726 	ljmp	00116$
   064F                     727 00313$:
   064F BA 31 03            728 	cjne	r2,#0x31,00314$
   0652 02 07 D8            729 	ljmp	00117$
   0655                     730 00314$:
   0655 BA 32 03            731 	cjne	r2,#0x32,00315$
   0658 02 07 F2            732 	ljmp	00118$
   065B                     733 00315$:
   065B BA 33 03            734 	cjne	r2,#0x33,00316$
   065E 02 08 0C            735 	ljmp	00119$
   0661                     736 00316$:
   0661 BA 34 03            737 	cjne	r2,#0x34,00317$
   0664 02 08 26            738 	ljmp	00120$
   0667                     739 00317$:
   0667 BA 35 03            740 	cjne	r2,#0x35,00318$
   066A 02 08 40            741 	ljmp	00121$
   066D                     742 00318$:
   066D BA 40 03            743 	cjne	r2,#0x40,00319$
   0670 02 08 5A            744 	ljmp	00122$
   0673                     745 00319$:
   0673 BA 41 03            746 	cjne	r2,#0x41,00320$
   0676 02 08 97            747 	ljmp	00123$
   0679                     748 00320$:
   0679 BA 42 03            749 	cjne	r2,#0x42,00321$
   067C 02 08 D4            750 	ljmp	00124$
   067F                     751 00321$:
   067F BA 43 03            752 	cjne	r2,#0x43,00322$
   0682 02 09 11            753 	ljmp	00125$
   0685                     754 00322$:
   0685 BA 44 03            755 	cjne	r2,#0x44,00323$
   0688 02 09 4E            756 	ljmp	00126$
   068B                     757 00323$:
   068B BA 45 03            758 	cjne	r2,#0x45,00324$
   068E 02 09 8B            759 	ljmp	00127$
   0691                     760 00324$:
   0691 BA F2 03            761 	cjne	r2,#0xF2,00325$
   0694 02 0E 94            762 	ljmp	00188$
   0697                     763 00325$:
   0697 BA F3 02            764 	cjne	r2,#0xF3,00326$
   069A 80 26               765 	sjmp	00105$
   069C                     766 00326$:
   069C BA F4 02            767 	cjne	r2,#0xF4,00327$
   069F 80 73               768 	sjmp	00109$
   06A1                     769 00327$:
   06A1 BA F6 03            770 	cjne	r2,#0xF6,00328$
   06A4 02 0D 50            771 	ljmp	00153$
   06A7                     772 00328$:
   06A7 BA F7 03            773 	cjne	r2,#0xF7,00329$
   06AA 02 0D EF            774 	ljmp	00162$
   06AD                     775 00329$:
   06AD BA F8 03            776 	cjne	r2,#0xF8,00330$
   06B0 02 0C C2            777 	ljmp	00147$
   06B3                     778 00330$:
   06B3 BA F9 03            779 	cjne	r2,#0xF9,00331$
   06B6 02 0C 2E            780 	ljmp	00143$
   06B9                     781 00331$:
   06B9 BA FA 03            782 	cjne	r2,#0xFA,00332$
   06BC 02 0C DD            783 	ljmp	00148$
   06BF                     784 00332$:
   06BF 02 11 46            785 	ljmp	00190$
                            786 ;	../main.c:102: LED_Off();
   06C2                     787 00105$:
   06C2 43 80 30            788 	orl	_P0,#0x30
                            789 ;	../main.c:103: customized_plen = 0;
   06C5 90 80 9E            790 	mov	dptr,#_main_customized_plen_1_1
   06C8 E4                  791 	clr	a
   06C9 F0                  792 	movx	@dptr,a
   06CA A3                  793 	inc	dptr
   06CB F0                  794 	movx	@dptr,a
                            795 ;	../main.c:104: for (i = 0; i < PLOAD_LEN; i++)
   06CC 7A 00               796 	mov	r2,#0x00
   06CE 7B 00               797 	mov	r3,#0x00
   06D0                     798 00194$:
   06D0 C3                  799 	clr	c
   06D1 EA                  800 	mov	a,r2
   06D2 94 20               801 	subb	a,#0x20
   06D4 EB                  802 	mov	a,r3
   06D5 64 80               803 	xrl	a,#0x80
   06D7 94 80               804 	subb	a,#0x80
   06D9 50 18               805 	jnc	00197$
                            806 ;	../main.c:105: packet[i] = i + 9;
   06DB EA                  807 	mov	a,r2
   06DC 24 7A               808 	add	a,#_packet
   06DE F5 82               809 	mov	dpl,a
   06E0 EB                  810 	mov	a,r3
   06E1 34 80               811 	addc	a,#(_packet >> 8)
   06E3 F5 83               812 	mov	dph,a
   06E5 8A 04               813 	mov	ar4,r2
   06E7 74 09               814 	mov	a,#0x09
   06E9 2C                  815 	add	a,r4
   06EA FC                  816 	mov	r4,a
   06EB F0                  817 	movx	@dptr,a
                            818 ;	../main.c:104: for (i = 0; i < PLOAD_LEN; i++)
   06EC 0A                  819 	inc	r2
   06ED BA 00 E0            820 	cjne	r2,#0x00,00194$
   06F0 0B                  821 	inc	r3
   06F1 80 DD               822 	sjmp	00194$
   06F3                     823 00197$:
                            824 ;	../main.c:106: hal_nrf_close_pipe(HAL_NRF_PIPE1);
   06F3 75 82 01            825 	mov	dpl,#0x01
   06F6 12 15 3E            826 	lcall	_hal_nrf_close_pipe
                            827 ;	../main.c:107: hal_nrf_close_pipe(HAL_NRF_PIPE2);
   06F9 75 82 02            828 	mov	dpl,#0x02
   06FC 12 15 3E            829 	lcall	_hal_nrf_close_pipe
                            830 ;	../main.c:108: hal_nrf_close_pipe(HAL_NRF_PIPE3);
   06FF 75 82 03            831 	mov	dpl,#0x03
   0702 12 15 3E            832 	lcall	_hal_nrf_close_pipe
                            833 ;	../main.c:109: hal_nrf_close_pipe(HAL_NRF_PIPE4);
   0705 75 82 04            834 	mov	dpl,#0x04
   0708 12 15 3E            835 	lcall	_hal_nrf_close_pipe
                            836 ;	../main.c:110: hal_nrf_close_pipe(HAL_NRF_PIPE5);
   070B 75 82 05            837 	mov	dpl,#0x05
   070E 12 15 3E            838 	lcall	_hal_nrf_close_pipe
                            839 ;	../main.c:111: break;
   0711 02 11 46            840 	ljmp	00190$
                            841 ;	../main.c:114: LED_Off();
   0714                     842 00109$:
   0714 43 80 30            843 	orl	_P0,#0x30
                            844 ;	../main.c:115: hal_nrf_close_pipe(HAL_NRF_PIPE1);
   0717 75 82 01            845 	mov	dpl,#0x01
   071A 12 15 3E            846 	lcall	_hal_nrf_close_pipe
                            847 ;	../main.c:116: hal_nrf_close_pipe(HAL_NRF_PIPE2);
   071D 75 82 02            848 	mov	dpl,#0x02
   0720 12 15 3E            849 	lcall	_hal_nrf_close_pipe
                            850 ;	../main.c:117: hal_nrf_close_pipe(HAL_NRF_PIPE3);
   0723 75 82 03            851 	mov	dpl,#0x03
   0726 12 15 3E            852 	lcall	_hal_nrf_close_pipe
                            853 ;	../main.c:118: hal_nrf_close_pipe(HAL_NRF_PIPE4);
   0729 75 82 04            854 	mov	dpl,#0x04
   072C 12 15 3E            855 	lcall	_hal_nrf_close_pipe
                            856 ;	../main.c:119: hal_nrf_close_pipe(HAL_NRF_PIPE5);
   072F 75 82 05            857 	mov	dpl,#0x05
   0732 12 15 3E            858 	lcall	_hal_nrf_close_pipe
                            859 ;	../main.c:120: break;
   0735 02 11 46            860 	ljmp	00190$
                            861 ;	../main.c:122: case EPL_OUTPUT_POWER: 			//Host:set_output_power
   0738                     862 00112$:
                            863 ;	../main.c:123: hal_nrf_set_output_power(ubuf[2]);
   0738 90 80 3A            864 	mov	dptr,#(_ubuf + 0x0002)
   073B E0                  865 	movx	a,@dptr
   073C F5 82               866 	mov	dpl,a
   073E 12 18 27            867 	lcall	_hal_nrf_set_output_power
                            868 ;	../main.c:124: epl_uart_putstr("EPL_OUTPUT_POWER\n");
   0741 90 3A 15            869 	mov	dptr,#__str_2
   0744 75 F0 80            870 	mov	b,#0x80
   0747 12 1E 94            871 	lcall	_epl_uart_putstr
                            872 ;	../main.c:125: usb_send_packet(ACKbuf, 3);
   074A 90 80 DE            873 	mov	dptr,#_usb_send_packet_PARM_2
   074D 74 03               874 	mov	a,#0x03
   074F F0                  875 	movx	@dptr,a
   0750 90 80 A1            876 	mov	dptr,#_main_ACKbuf_1_1
   0753 75 F0 00            877 	mov	b,#0x00
   0756 12 12 89            878 	lcall	_usb_send_packet
                            879 ;	../main.c:126: epl_uart_putstr("EPL_OUTPUT_POWER     END\n");
   0759 90 3A 27            880 	mov	dptr,#__str_3
   075C 75 F0 80            881 	mov	b,#0x80
   075F 12 1E 94            882 	lcall	_epl_uart_putstr
                            883 ;	../main.c:127: break;
   0762 02 11 46            884 	ljmp	00190$
                            885 ;	../main.c:129: case EPL_CHANNEL:
   0765                     886 00113$:
                            887 ;	../main.c:130: hal_nrf_set_rf_channel(ubuf[2]);
   0765 90 80 3A            888 	mov	dptr,#(_ubuf + 0x0002)
   0768 E0                  889 	movx	a,@dptr
   0769 F5 82               890 	mov	dpl,a
   076B 12 18 13            891 	lcall	_hal_nrf_set_rf_channel
                            892 ;	../main.c:131: usb_send_packet(ACKbuf, 3);
   076E 90 80 DE            893 	mov	dptr,#_usb_send_packet_PARM_2
   0771 74 03               894 	mov	a,#0x03
   0773 F0                  895 	movx	@dptr,a
   0774 90 80 A1            896 	mov	dptr,#_main_ACKbuf_1_1
   0777 75 F0 00            897 	mov	b,#0x00
   077A 12 12 89            898 	lcall	_usb_send_packet
                            899 ;	../main.c:132: break;
   077D 02 11 46            900 	ljmp	00190$
                            901 ;	../main.c:134: case EPL_DATARATE:
   0780                     902 00114$:
                            903 ;	../main.c:135: hal_nrf_set_datarate(ubuf[2]);
   0780 90 80 3A            904 	mov	dptr,#(_ubuf + 0x0002)
   0783 E0                  905 	movx	a,@dptr
   0784 F5 82               906 	mov	dpl,a
   0786 12 18 49            907 	lcall	_hal_nrf_set_datarate
                            908 ;	../main.c:136: usb_send_packet(ACKbuf, 3);
   0789 90 80 DE            909 	mov	dptr,#_usb_send_packet_PARM_2
   078C 74 03               910 	mov	a,#0x03
   078E F0                  911 	movx	@dptr,a
   078F 90 80 A1            912 	mov	dptr,#_main_ACKbuf_1_1
   0792 75 F0 00            913 	mov	b,#0x00
   0795 12 12 89            914 	lcall	_usb_send_packet
                            915 ;	../main.c:137: break;
   0798 02 11 46            916 	ljmp	00190$
                            917 ;	../main.c:139: case EPL_ADDR_WIDTH:
   079B                     918 00115$:
                            919 ;	../main.c:140: addr_width = (int) ubuf[2];
   079B 90 80 3A            920 	mov	dptr,#(_ubuf + 0x0002)
   079E E0                  921 	movx	a,@dptr
   079F FA                  922 	mov	r2,a
   07A0 90 80 9C            923 	mov	dptr,#_main_addr_width_1_1
   07A3 F0                  924 	movx	@dptr,a
   07A4 A3                  925 	inc	dptr
   07A5 E4                  926 	clr	a
   07A6 F0                  927 	movx	@dptr,a
                            928 ;	../main.c:141: hal_nrf_set_address_width(ubuf[2]);
   07A7 8A 82               929 	mov	dpl,r2
   07A9 12 16 67            930 	lcall	_hal_nrf_set_address_width
                            931 ;	../main.c:142: usb_send_packet(ACKbuf, 3);
   07AC 90 80 DE            932 	mov	dptr,#_usb_send_packet_PARM_2
   07AF 74 03               933 	mov	a,#0x03
   07B1 F0                  934 	movx	@dptr,a
   07B2 90 80 A1            935 	mov	dptr,#_main_ACKbuf_1_1
   07B5 75 F0 00            936 	mov	b,#0x00
   07B8 12 12 89            937 	lcall	_usb_send_packet
                            938 ;	../main.c:143: break;
   07BB 02 11 46            939 	ljmp	00190$
                            940 ;	../main.c:145: case EPL_AUTOACK_P0:
   07BE                     941 00116$:
                            942 ;	../main.c:146: auto_ack = ubuf[2];
   07BE 90 80 3A            943 	mov	dptr,#(_ubuf + 0x0002)
   07C1 E0                  944 	movx	a,@dptr
   07C2 90 80 A0            945 	mov	dptr,#_main_auto_ack_1_1
   07C5 F0                  946 	movx	@dptr,a
                            947 ;	../main.c:147: usb_send_packet(ACKbuf, 3);
   07C6 90 80 DE            948 	mov	dptr,#_usb_send_packet_PARM_2
   07C9 74 03               949 	mov	a,#0x03
   07CB F0                  950 	movx	@dptr,a
   07CC 90 80 A1            951 	mov	dptr,#_main_ACKbuf_1_1
   07CF 75 F0 00            952 	mov	b,#0x00
   07D2 12 12 89            953 	lcall	_usb_send_packet
                            954 ;	../main.c:148: break;
   07D5 02 11 46            955 	ljmp	00190$
                            956 ;	../main.c:150: case EPL_AUTOACK_P1:
   07D8                     957 00117$:
                            958 ;	../main.c:151: auto_ack = ubuf[2];
   07D8 90 80 3A            959 	mov	dptr,#(_ubuf + 0x0002)
   07DB E0                  960 	movx	a,@dptr
   07DC 90 80 A0            961 	mov	dptr,#_main_auto_ack_1_1
   07DF F0                  962 	movx	@dptr,a
                            963 ;	../main.c:152: usb_send_packet(ACKbuf, 3);
   07E0 90 80 DE            964 	mov	dptr,#_usb_send_packet_PARM_2
   07E3 74 03               965 	mov	a,#0x03
   07E5 F0                  966 	movx	@dptr,a
   07E6 90 80 A1            967 	mov	dptr,#_main_ACKbuf_1_1
   07E9 75 F0 00            968 	mov	b,#0x00
   07EC 12 12 89            969 	lcall	_usb_send_packet
                            970 ;	../main.c:153: break;
   07EF 02 11 46            971 	ljmp	00190$
                            972 ;	../main.c:155: case EPL_AUTOACK_P2:
   07F2                     973 00118$:
                            974 ;	../main.c:156: auto_ack = ubuf[2];
   07F2 90 80 3A            975 	mov	dptr,#(_ubuf + 0x0002)
   07F5 E0                  976 	movx	a,@dptr
   07F6 90 80 A0            977 	mov	dptr,#_main_auto_ack_1_1
   07F9 F0                  978 	movx	@dptr,a
                            979 ;	../main.c:157: usb_send_packet(ACKbuf, 3);
   07FA 90 80 DE            980 	mov	dptr,#_usb_send_packet_PARM_2
   07FD 74 03               981 	mov	a,#0x03
   07FF F0                  982 	movx	@dptr,a
   0800 90 80 A1            983 	mov	dptr,#_main_ACKbuf_1_1
   0803 75 F0 00            984 	mov	b,#0x00
   0806 12 12 89            985 	lcall	_usb_send_packet
                            986 ;	../main.c:158: break;
   0809 02 11 46            987 	ljmp	00190$
                            988 ;	../main.c:160: case EPL_AUTOACK_P3:
   080C                     989 00119$:
                            990 ;	../main.c:161: auto_ack = ubuf[2];
   080C 90 80 3A            991 	mov	dptr,#(_ubuf + 0x0002)
   080F E0                  992 	movx	a,@dptr
   0810 90 80 A0            993 	mov	dptr,#_main_auto_ack_1_1
   0813 F0                  994 	movx	@dptr,a
                            995 ;	../main.c:162: usb_send_packet(ACKbuf, 3);
   0814 90 80 DE            996 	mov	dptr,#_usb_send_packet_PARM_2
   0817 74 03               997 	mov	a,#0x03
   0819 F0                  998 	movx	@dptr,a
   081A 90 80 A1            999 	mov	dptr,#_main_ACKbuf_1_1
   081D 75 F0 00           1000 	mov	b,#0x00
   0820 12 12 89           1001 	lcall	_usb_send_packet
                           1002 ;	../main.c:163: break;
   0823 02 11 46           1003 	ljmp	00190$
                           1004 ;	../main.c:165: case EPL_AUTOACK_P4:
   0826                    1005 00120$:
                           1006 ;	../main.c:166: auto_ack = ubuf[2];
   0826 90 80 3A           1007 	mov	dptr,#(_ubuf + 0x0002)
   0829 E0                 1008 	movx	a,@dptr
   082A 90 80 A0           1009 	mov	dptr,#_main_auto_ack_1_1
   082D F0                 1010 	movx	@dptr,a
                           1011 ;	../main.c:167: usb_send_packet(ACKbuf, 3);
   082E 90 80 DE           1012 	mov	dptr,#_usb_send_packet_PARM_2
   0831 74 03              1013 	mov	a,#0x03
   0833 F0                 1014 	movx	@dptr,a
   0834 90 80 A1           1015 	mov	dptr,#_main_ACKbuf_1_1
   0837 75 F0 00           1016 	mov	b,#0x00
   083A 12 12 89           1017 	lcall	_usb_send_packet
                           1018 ;	../main.c:168: break;
   083D 02 11 46           1019 	ljmp	00190$
                           1020 ;	../main.c:170: case EPL_AUTOACK_P5:
   0840                    1021 00121$:
                           1022 ;	../main.c:171: auto_ack = ubuf[2];
   0840 90 80 3A           1023 	mov	dptr,#(_ubuf + 0x0002)
   0843 E0                 1024 	movx	a,@dptr
   0844 90 80 A0           1025 	mov	dptr,#_main_auto_ack_1_1
   0847 F0                 1026 	movx	@dptr,a
                           1027 ;	../main.c:172: usb_send_packet(ACKbuf, 3);
   0848 90 80 DE           1028 	mov	dptr,#_usb_send_packet_PARM_2
   084B 74 03              1029 	mov	a,#0x03
   084D F0                 1030 	movx	@dptr,a
   084E 90 80 A1           1031 	mov	dptr,#_main_ACKbuf_1_1
   0851 75 F0 00           1032 	mov	b,#0x00
   0854 12 12 89           1033 	lcall	_usb_send_packet
                           1034 ;	../main.c:173: break;
   0857 02 11 46           1035 	ljmp	00190$
                           1036 ;	../main.c:175: case EPL_DATA_LENGTH_P0:
   085A                    1037 00122$:
                           1038 ;	../main.c:176: data_length = (int) ubuf[2];
   085A 90 80 3A           1039 	mov	dptr,#(_ubuf + 0x0002)
   085D E0                 1040 	movx	a,@dptr
   085E FA                 1041 	mov	r2,a
   085F 90 80 CC           1042 	mov	dptr,#_main_data_length_1_1
   0862 F0                 1043 	movx	@dptr,a
                           1044 ;	../main.c:177: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0, temp_addr, data_length, auto_ack);
   0863 90 80 A0           1045 	mov	dptr,#_main_auto_ack_1_1
   0866 E0                 1046 	movx	a,@dptr
   0867 FB                 1047 	mov	r3,a
   0868 90 80 0A           1048 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   086B 74 C7              1049 	mov	a,#_main_temp_addr_1_1
   086D F0                 1050 	movx	@dptr,a
   086E A3                 1051 	inc	dptr
   086F 74 80              1052 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0871 F0                 1053 	movx	@dptr,a
   0872 A3                 1054 	inc	dptr
   0873 E4                 1055 	clr	a
   0874 F0                 1056 	movx	@dptr,a
   0875 90 80 0D           1057 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   0878 EA                 1058 	mov	a,r2
   0879 F0                 1059 	movx	@dptr,a
   087A 90 80 0E           1060 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   087D EB                 1061 	mov	a,r3
   087E F0                 1062 	movx	@dptr,a
   087F 75 82 00           1063 	mov	dpl,#0x00
   0882 12 01 95           1064 	lcall	_epl_rf_en_rcv_pipe_config
                           1065 ;	../main.c:178: usb_send_packet(ACKbuf, 3);
   0885 90 80 DE           1066 	mov	dptr,#_usb_send_packet_PARM_2
   0888 74 03              1067 	mov	a,#0x03
   088A F0                 1068 	movx	@dptr,a
   088B 90 80 A1           1069 	mov	dptr,#_main_ACKbuf_1_1
   088E 75 F0 00           1070 	mov	b,#0x00
   0891 12 12 89           1071 	lcall	_usb_send_packet
                           1072 ;	../main.c:179: break;
   0894 02 11 46           1073 	ljmp	00190$
                           1074 ;	../main.c:181: case EPL_DATA_LENGTH_P1:
   0897                    1075 00123$:
                           1076 ;	../main.c:182: data_length = (int) ubuf[2];
   0897 90 80 3A           1077 	mov	dptr,#(_ubuf + 0x0002)
   089A E0                 1078 	movx	a,@dptr
   089B FA                 1079 	mov	r2,a
   089C 90 80 CC           1080 	mov	dptr,#_main_data_length_1_1
   089F F0                 1081 	movx	@dptr,a
                           1082 ;	../main.c:183: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE1, temp_addr, data_length, auto_ack);
   08A0 90 80 A0           1083 	mov	dptr,#_main_auto_ack_1_1
   08A3 E0                 1084 	movx	a,@dptr
   08A4 FB                 1085 	mov	r3,a
   08A5 90 80 0A           1086 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   08A8 74 C7              1087 	mov	a,#_main_temp_addr_1_1
   08AA F0                 1088 	movx	@dptr,a
   08AB A3                 1089 	inc	dptr
   08AC 74 80              1090 	mov	a,#(_main_temp_addr_1_1 >> 8)
   08AE F0                 1091 	movx	@dptr,a
   08AF A3                 1092 	inc	dptr
   08B0 E4                 1093 	clr	a
   08B1 F0                 1094 	movx	@dptr,a
   08B2 90 80 0D           1095 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   08B5 EA                 1096 	mov	a,r2
   08B6 F0                 1097 	movx	@dptr,a
   08B7 90 80 0E           1098 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   08BA EB                 1099 	mov	a,r3
   08BB F0                 1100 	movx	@dptr,a
   08BC 75 82 01           1101 	mov	dpl,#0x01
   08BF 12 01 95           1102 	lcall	_epl_rf_en_rcv_pipe_config
                           1103 ;	../main.c:184: usb_send_packet(ACKbuf, 3);
   08C2 90 80 DE           1104 	mov	dptr,#_usb_send_packet_PARM_2
   08C5 74 03              1105 	mov	a,#0x03
   08C7 F0                 1106 	movx	@dptr,a
   08C8 90 80 A1           1107 	mov	dptr,#_main_ACKbuf_1_1
   08CB 75 F0 00           1108 	mov	b,#0x00
   08CE 12 12 89           1109 	lcall	_usb_send_packet
                           1110 ;	../main.c:185: break;
   08D1 02 11 46           1111 	ljmp	00190$
                           1112 ;	../main.c:187: case EPL_DATA_LENGTH_P2:
   08D4                    1113 00124$:
                           1114 ;	../main.c:188: data_length = (int) ubuf[2];
   08D4 90 80 3A           1115 	mov	dptr,#(_ubuf + 0x0002)
   08D7 E0                 1116 	movx	a,@dptr
   08D8 FA                 1117 	mov	r2,a
   08D9 90 80 CC           1118 	mov	dptr,#_main_data_length_1_1
   08DC F0                 1119 	movx	@dptr,a
                           1120 ;	../main.c:189: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE2, temp_addr, data_length, auto_ack);
   08DD 90 80 A0           1121 	mov	dptr,#_main_auto_ack_1_1
   08E0 E0                 1122 	movx	a,@dptr
   08E1 FB                 1123 	mov	r3,a
   08E2 90 80 0A           1124 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   08E5 74 C7              1125 	mov	a,#_main_temp_addr_1_1
   08E7 F0                 1126 	movx	@dptr,a
   08E8 A3                 1127 	inc	dptr
   08E9 74 80              1128 	mov	a,#(_main_temp_addr_1_1 >> 8)
   08EB F0                 1129 	movx	@dptr,a
   08EC A3                 1130 	inc	dptr
   08ED E4                 1131 	clr	a
   08EE F0                 1132 	movx	@dptr,a
   08EF 90 80 0D           1133 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   08F2 EA                 1134 	mov	a,r2
   08F3 F0                 1135 	movx	@dptr,a
   08F4 90 80 0E           1136 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   08F7 EB                 1137 	mov	a,r3
   08F8 F0                 1138 	movx	@dptr,a
   08F9 75 82 02           1139 	mov	dpl,#0x02
   08FC 12 01 95           1140 	lcall	_epl_rf_en_rcv_pipe_config
                           1141 ;	../main.c:190: usb_send_packet(ACKbuf, 3);
   08FF 90 80 DE           1142 	mov	dptr,#_usb_send_packet_PARM_2
   0902 74 03              1143 	mov	a,#0x03
   0904 F0                 1144 	movx	@dptr,a
   0905 90 80 A1           1145 	mov	dptr,#_main_ACKbuf_1_1
   0908 75 F0 00           1146 	mov	b,#0x00
   090B 12 12 89           1147 	lcall	_usb_send_packet
                           1148 ;	../main.c:191: break;
   090E 02 11 46           1149 	ljmp	00190$
                           1150 ;	../main.c:193: case EPL_DATA_LENGTH_P3:
   0911                    1151 00125$:
                           1152 ;	../main.c:194: data_length = (int) ubuf[2];
   0911 90 80 3A           1153 	mov	dptr,#(_ubuf + 0x0002)
   0914 E0                 1154 	movx	a,@dptr
   0915 FA                 1155 	mov	r2,a
   0916 90 80 CC           1156 	mov	dptr,#_main_data_length_1_1
   0919 F0                 1157 	movx	@dptr,a
                           1158 ;	../main.c:195: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE3, temp_addr, data_length, auto_ack);
   091A 90 80 A0           1159 	mov	dptr,#_main_auto_ack_1_1
   091D E0                 1160 	movx	a,@dptr
   091E FB                 1161 	mov	r3,a
   091F 90 80 0A           1162 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   0922 74 C7              1163 	mov	a,#_main_temp_addr_1_1
   0924 F0                 1164 	movx	@dptr,a
   0925 A3                 1165 	inc	dptr
   0926 74 80              1166 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0928 F0                 1167 	movx	@dptr,a
   0929 A3                 1168 	inc	dptr
   092A E4                 1169 	clr	a
   092B F0                 1170 	movx	@dptr,a
   092C 90 80 0D           1171 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   092F EA                 1172 	mov	a,r2
   0930 F0                 1173 	movx	@dptr,a
   0931 90 80 0E           1174 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   0934 EB                 1175 	mov	a,r3
   0935 F0                 1176 	movx	@dptr,a
   0936 75 82 03           1177 	mov	dpl,#0x03
   0939 12 01 95           1178 	lcall	_epl_rf_en_rcv_pipe_config
                           1179 ;	../main.c:196: usb_send_packet(ACKbuf, 3);
   093C 90 80 DE           1180 	mov	dptr,#_usb_send_packet_PARM_2
   093F 74 03              1181 	mov	a,#0x03
   0941 F0                 1182 	movx	@dptr,a
   0942 90 80 A1           1183 	mov	dptr,#_main_ACKbuf_1_1
   0945 75 F0 00           1184 	mov	b,#0x00
   0948 12 12 89           1185 	lcall	_usb_send_packet
                           1186 ;	../main.c:197: break;
   094B 02 11 46           1187 	ljmp	00190$
                           1188 ;	../main.c:200: case EPL_DATA_LENGTH_P4:
   094E                    1189 00126$:
                           1190 ;	../main.c:201: data_length = (int) ubuf[2];
   094E 90 80 3A           1191 	mov	dptr,#(_ubuf + 0x0002)
   0951 E0                 1192 	movx	a,@dptr
   0952 FA                 1193 	mov	r2,a
   0953 90 80 CC           1194 	mov	dptr,#_main_data_length_1_1
   0956 F0                 1195 	movx	@dptr,a
                           1196 ;	../main.c:202: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE4, temp_addr, data_length, auto_ack);
   0957 90 80 A0           1197 	mov	dptr,#_main_auto_ack_1_1
   095A E0                 1198 	movx	a,@dptr
   095B FB                 1199 	mov	r3,a
   095C 90 80 0A           1200 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   095F 74 C7              1201 	mov	a,#_main_temp_addr_1_1
   0961 F0                 1202 	movx	@dptr,a
   0962 A3                 1203 	inc	dptr
   0963 74 80              1204 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0965 F0                 1205 	movx	@dptr,a
   0966 A3                 1206 	inc	dptr
   0967 E4                 1207 	clr	a
   0968 F0                 1208 	movx	@dptr,a
   0969 90 80 0D           1209 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   096C EA                 1210 	mov	a,r2
   096D F0                 1211 	movx	@dptr,a
   096E 90 80 0E           1212 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   0971 EB                 1213 	mov	a,r3
   0972 F0                 1214 	movx	@dptr,a
   0973 75 82 04           1215 	mov	dpl,#0x04
   0976 12 01 95           1216 	lcall	_epl_rf_en_rcv_pipe_config
                           1217 ;	../main.c:203: usb_send_packet(ACKbuf, 3);
   0979 90 80 DE           1218 	mov	dptr,#_usb_send_packet_PARM_2
   097C 74 03              1219 	mov	a,#0x03
   097E F0                 1220 	movx	@dptr,a
   097F 90 80 A1           1221 	mov	dptr,#_main_ACKbuf_1_1
   0982 75 F0 00           1222 	mov	b,#0x00
   0985 12 12 89           1223 	lcall	_usb_send_packet
                           1224 ;	../main.c:204: break;
   0988 02 11 46           1225 	ljmp	00190$
                           1226 ;	../main.c:206: case EPL_DATA_LENGTH_P5:
   098B                    1227 00127$:
                           1228 ;	../main.c:207: data_length = (int) ubuf[2];
   098B 90 80 3A           1229 	mov	dptr,#(_ubuf + 0x0002)
   098E E0                 1230 	movx	a,@dptr
   098F FA                 1231 	mov	r2,a
   0990 90 80 CC           1232 	mov	dptr,#_main_data_length_1_1
   0993 F0                 1233 	movx	@dptr,a
                           1234 ;	../main.c:208: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE5, temp_addr, data_length, auto_ack);
   0994 90 80 A0           1235 	mov	dptr,#_main_auto_ack_1_1
   0997 E0                 1236 	movx	a,@dptr
   0998 FB                 1237 	mov	r3,a
   0999 90 80 0A           1238 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
   099C 74 C7              1239 	mov	a,#_main_temp_addr_1_1
   099E F0                 1240 	movx	@dptr,a
   099F A3                 1241 	inc	dptr
   09A0 74 80              1242 	mov	a,#(_main_temp_addr_1_1 >> 8)
   09A2 F0                 1243 	movx	@dptr,a
   09A3 A3                 1244 	inc	dptr
   09A4 E4                 1245 	clr	a
   09A5 F0                 1246 	movx	@dptr,a
   09A6 90 80 0D           1247 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
   09A9 EA                 1248 	mov	a,r2
   09AA F0                 1249 	movx	@dptr,a
   09AB 90 80 0E           1250 	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
   09AE EB                 1251 	mov	a,r3
   09AF F0                 1252 	movx	@dptr,a
   09B0 75 82 05           1253 	mov	dpl,#0x05
   09B3 12 01 95           1254 	lcall	_epl_rf_en_rcv_pipe_config
                           1255 ;	../main.c:209: usb_send_packet(ACKbuf, 3);
   09B6 90 80 DE           1256 	mov	dptr,#_usb_send_packet_PARM_2
   09B9 74 03              1257 	mov	a,#0x03
   09BB F0                 1258 	movx	@dptr,a
   09BC 90 80 A1           1259 	mov	dptr,#_main_ACKbuf_1_1
   09BF 75 F0 00           1260 	mov	b,#0x00
   09C2 12 12 89           1261 	lcall	_usb_send_packet
                           1262 ;	../main.c:210: break;
   09C5 02 11 46           1263 	ljmp	00190$
                           1264 ;	../main.c:212: case EPL_CRC_MODE:
   09C8                    1265 00128$:
                           1266 ;	../main.c:213: if (ubuf[2] == 0)
   09C8 90 80 3A           1267 	mov	dptr,#(_ubuf + 0x0002)
   09CB E0                 1268 	movx	a,@dptr
   09CC FA                 1269 	mov	r2,a
                           1270 ;	../main.c:214: hal_nrf_set_crc_mode(HAL_NRF_CRC_OFF);
   09CD 70 07              1271 	jnz	00135$
   09CF F5 82              1272 	mov	dpl,a
   09D1 12 14 63           1273 	lcall	_hal_nrf_set_crc_mode
   09D4 80 14              1274 	sjmp	00136$
   09D6                    1275 00135$:
                           1276 ;	../main.c:215: else if (ubuf[2] == 2)
   09D6 BA 02 08           1277 	cjne	r2,#0x02,00132$
                           1278 ;	../main.c:216: hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT);
   09D9 75 82 02           1279 	mov	dpl,#0x02
   09DC 12 14 63           1280 	lcall	_hal_nrf_set_crc_mode
   09DF 80 09              1281 	sjmp	00136$
   09E1                    1282 00132$:
                           1283 ;	../main.c:217: else if (ubuf[2] == 3)
   09E1 BA 03 06           1284 	cjne	r2,#0x03,00136$
                           1285 ;	../main.c:218: hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);
   09E4 75 82 03           1286 	mov	dpl,#0x03
   09E7 12 14 63           1287 	lcall	_hal_nrf_set_crc_mode
   09EA                    1288 00136$:
                           1289 ;	../main.c:222: usb_send_packet(ACKbuf, 3);
   09EA 90 80 DE           1290 	mov	dptr,#_usb_send_packet_PARM_2
   09ED 74 03              1291 	mov	a,#0x03
   09EF F0                 1292 	movx	@dptr,a
   09F0 90 80 A1           1293 	mov	dptr,#_main_ACKbuf_1_1
   09F3 75 F0 00           1294 	mov	b,#0x00
   09F6 12 12 89           1295 	lcall	_usb_send_packet
                           1296 ;	../main.c:223: break;
   09F9 02 11 46           1297 	ljmp	00190$
                           1298 ;	../main.c:226: for (i = 0; i < addr_width; i++) {
   09FC                    1299 00269$:
   09FC 90 80 9C           1300 	mov	dptr,#_main_addr_width_1_1
   09FF E0                 1301 	movx	a,@dptr
   0A00 FA                 1302 	mov	r2,a
   0A01 A3                 1303 	inc	dptr
   0A02 E0                 1304 	movx	a,@dptr
   0A03 FB                 1305 	mov	r3,a
   0A04 7C 00              1306 	mov	r4,#0x00
   0A06 7D 00              1307 	mov	r5,#0x00
   0A08                    1308 00198$:
   0A08 C3                 1309 	clr	c
   0A09 EC                 1310 	mov	a,r4
   0A0A 9A                 1311 	subb	a,r2
   0A0B ED                 1312 	mov	a,r5
   0A0C 64 80              1313 	xrl	a,#0x80
   0A0E 8B F0              1314 	mov	b,r3
   0A10 63 F0 80           1315 	xrl	b,#0x80
   0A13 95 F0              1316 	subb	a,b
   0A15 50 2C              1317 	jnc	00201$
                           1318 ;	../main.c:227: temp_addr[i] = ubuf[i + 2];
   0A17 C0 02              1319 	push	ar2
   0A19 C0 03              1320 	push	ar3
   0A1B EC                 1321 	mov	a,r4
   0A1C 24 C7              1322 	add	a,#_main_temp_addr_1_1
   0A1E FE                 1323 	mov	r6,a
   0A1F ED                 1324 	mov	a,r5
   0A20 34 80              1325 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0A22 FF                 1326 	mov	r7,a
   0A23 8C 02              1327 	mov	ar2,r4
   0A25 74 02              1328 	mov	a,#0x02
   0A27 2A                 1329 	add	a,r2
   0A28 24 38              1330 	add	a,#_ubuf
   0A2A F5 82              1331 	mov	dpl,a
   0A2C E4                 1332 	clr	a
   0A2D 34 80              1333 	addc	a,#(_ubuf >> 8)
   0A2F F5 83              1334 	mov	dph,a
   0A31 E0                 1335 	movx	a,@dptr
   0A32 FA                 1336 	mov	r2,a
   0A33 8E 82              1337 	mov	dpl,r6
   0A35 8F 83              1338 	mov	dph,r7
   0A37 F0                 1339 	movx	@dptr,a
                           1340 ;	../main.c:226: for (i = 0; i < addr_width; i++) {
   0A38 0C                 1341 	inc	r4
   0A39 BC 00 01           1342 	cjne	r4,#0x00,00340$
   0A3C 0D                 1343 	inc	r5
   0A3D                    1344 00340$:
   0A3D D0 03              1345 	pop	ar3
   0A3F D0 02              1346 	pop	ar2
   0A41 80 C5              1347 	sjmp	00198$
   0A43                    1348 00201$:
                           1349 ;	../main.c:229: hal_nrf_set_address(HAL_NRF_PIPE0, temp_addr);
   0A43 90 80 EA           1350 	mov	dptr,#_hal_nrf_set_address_PARM_2
   0A46 74 C7              1351 	mov	a,#_main_temp_addr_1_1
   0A48 F0                 1352 	movx	@dptr,a
   0A49 A3                 1353 	inc	dptr
   0A4A 74 80              1354 	mov	a,#(_main_temp_addr_1_1 >> 8)
   0A4C F0                 1355 	movx	@dptr,a
   0A4D A3                 1356 	inc	dptr
   0A4E E4                 1357 	clr	a
   0A4F F0                 1358 	movx	@dptr,a
   0A50 75 82 00           1359 	mov	dpl,#0x00
   0A53 12 15 BE           1360 	lcall	_hal_nrf_set_address
                           1361 ;	../main.c:230: epl_rf_en_set_dst_addr(temp_addr);
   0A56 90 80 C7           1362 	mov	dptr,#_main_temp_addr_1_1
   0A59 75 F0 00           1363 	mov	b,#0x00
   0A5C 12 04 48           1364 	lcall	_epl_rf_en_set_dst_addr
                           1365 ;	../main.c:232: usb_send_packet(ACKbuf, 3);
   0A5F 90 80 DE           1366 	mov	dptr,#_usb_send_packet_PARM_2
   0A62 74 03              1367 	mov	a,#0x03
   0A64 F0                 1368 	movx	@dptr,a
   0A65 90 80 A1           1369 	mov	dptr,#_main_ACKbuf_1_1
   0A68 75 F0 00           1370 	mov	b,#0x00
   0A6B 12 12 89           1371 	lcall	_usb_send_packet
                           1372 ;	../main.c:233: break;
   0A6E 02 11 46           1373 	ljmp	00190$
                           1374 ;	../main.c:236: for (i = 0; i < addr_width; i++) {
   0A71                    1375 00271$:
   0A71 90 80 9C           1376 	mov	dptr,#_main_addr_width_1_1
   0A74 E0                 1377 	movx	a,@dptr
   0A75 FA                 1378 	mov	r2,a
   0A76 A3                 1379 	inc	dptr
   0A77 E0                 1380 	movx	a,@dptr
   0A78 FB                 1381 	mov	r3,a
   0A79 7C 00              1382 	mov	r4,#0x00
   0A7B 7D 00              1383 	mov	r5,#0x00
   0A7D                    1384 00202$:
   0A7D C3                 1385 	clr	c
   0A7E EC                 1386 	mov	a,r4
   0A7F 9A                 1387 	subb	a,r2
   0A80 ED                 1388 	mov	a,r5
   0A81 64 80              1389 	xrl	a,#0x80
   0A83 8B F0              1390 	mov	b,r3
   0A85 63 F0 80           1391 	xrl	b,#0x80
   0A88 95 F0              1392 	subb	a,b
   0A8A 50 2C              1393 	jnc	00205$
                           1394 ;	../main.c:237: temp_addr[i] = ubuf[i + 2];
   0A8C C0 02              1395 	push	ar2
   0A8E C0 03              1396 	push	ar3
   0A90 EC                 1397 	mov	a,r4
   0A91 24 C7              1398 	add	a,#_main_temp_addr_1_1
   0A93 FE                 1399 	mov	r6,a
   0A94 ED                 1400 	mov	a,r5
   0A95 34 80              1401 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0A97 FF                 1402 	mov	r7,a
   0A98 8C 02              1403 	mov	ar2,r4
   0A9A 74 02              1404 	mov	a,#0x02
   0A9C 2A                 1405 	add	a,r2
   0A9D 24 38              1406 	add	a,#_ubuf
   0A9F F5 82              1407 	mov	dpl,a
   0AA1 E4                 1408 	clr	a
   0AA2 34 80              1409 	addc	a,#(_ubuf >> 8)
   0AA4 F5 83              1410 	mov	dph,a
   0AA6 E0                 1411 	movx	a,@dptr
   0AA7 FA                 1412 	mov	r2,a
   0AA8 8E 82              1413 	mov	dpl,r6
   0AAA 8F 83              1414 	mov	dph,r7
   0AAC F0                 1415 	movx	@dptr,a
                           1416 ;	../main.c:236: for (i = 0; i < addr_width; i++) {
   0AAD 0C                 1417 	inc	r4
   0AAE BC 00 01           1418 	cjne	r4,#0x00,00342$
   0AB1 0D                 1419 	inc	r5
   0AB2                    1420 00342$:
   0AB2 D0 03              1421 	pop	ar3
   0AB4 D0 02              1422 	pop	ar2
   0AB6 80 C5              1423 	sjmp	00202$
   0AB8                    1424 00205$:
                           1425 ;	../main.c:239: usb_send_packet(ACKbuf, 3);
   0AB8 90 80 DE           1426 	mov	dptr,#_usb_send_packet_PARM_2
   0ABB 74 03              1427 	mov	a,#0x03
   0ABD F0                 1428 	movx	@dptr,a
   0ABE 90 80 A1           1429 	mov	dptr,#_main_ACKbuf_1_1
   0AC1 75 F0 00           1430 	mov	b,#0x00
   0AC4 12 12 89           1431 	lcall	_usb_send_packet
                           1432 ;	../main.c:240: break;
   0AC7 02 11 46           1433 	ljmp	00190$
                           1434 ;	../main.c:242: for (i = 0; i < addr_width; i++) {
   0ACA                    1435 00273$:
   0ACA 90 80 9C           1436 	mov	dptr,#_main_addr_width_1_1
   0ACD E0                 1437 	movx	a,@dptr
   0ACE FA                 1438 	mov	r2,a
   0ACF A3                 1439 	inc	dptr
   0AD0 E0                 1440 	movx	a,@dptr
   0AD1 FB                 1441 	mov	r3,a
   0AD2 7C 00              1442 	mov	r4,#0x00
   0AD4 7D 00              1443 	mov	r5,#0x00
   0AD6                    1444 00206$:
   0AD6 C3                 1445 	clr	c
   0AD7 EC                 1446 	mov	a,r4
   0AD8 9A                 1447 	subb	a,r2
   0AD9 ED                 1448 	mov	a,r5
   0ADA 64 80              1449 	xrl	a,#0x80
   0ADC 8B F0              1450 	mov	b,r3
   0ADE 63 F0 80           1451 	xrl	b,#0x80
   0AE1 95 F0              1452 	subb	a,b
   0AE3 50 2C              1453 	jnc	00209$
                           1454 ;	../main.c:243: temp_addr[i] = ubuf[i + 2];
   0AE5 C0 02              1455 	push	ar2
   0AE7 C0 03              1456 	push	ar3
   0AE9 EC                 1457 	mov	a,r4
   0AEA 24 C7              1458 	add	a,#_main_temp_addr_1_1
   0AEC FE                 1459 	mov	r6,a
   0AED ED                 1460 	mov	a,r5
   0AEE 34 80              1461 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0AF0 FF                 1462 	mov	r7,a
   0AF1 8C 02              1463 	mov	ar2,r4
   0AF3 74 02              1464 	mov	a,#0x02
   0AF5 2A                 1465 	add	a,r2
   0AF6 24 38              1466 	add	a,#_ubuf
   0AF8 F5 82              1467 	mov	dpl,a
   0AFA E4                 1468 	clr	a
   0AFB 34 80              1469 	addc	a,#(_ubuf >> 8)
   0AFD F5 83              1470 	mov	dph,a
   0AFF E0                 1471 	movx	a,@dptr
   0B00 FA                 1472 	mov	r2,a
   0B01 8E 82              1473 	mov	dpl,r6
   0B03 8F 83              1474 	mov	dph,r7
   0B05 F0                 1475 	movx	@dptr,a
                           1476 ;	../main.c:242: for (i = 0; i < addr_width; i++) {
   0B06 0C                 1477 	inc	r4
   0B07 BC 00 01           1478 	cjne	r4,#0x00,00344$
   0B0A 0D                 1479 	inc	r5
   0B0B                    1480 00344$:
   0B0B D0 03              1481 	pop	ar3
   0B0D D0 02              1482 	pop	ar2
   0B0F 80 C5              1483 	sjmp	00206$
   0B11                    1484 00209$:
                           1485 ;	../main.c:245: usb_send_packet(ACKbuf, 3);
   0B11 90 80 DE           1486 	mov	dptr,#_usb_send_packet_PARM_2
   0B14 74 03              1487 	mov	a,#0x03
   0B16 F0                 1488 	movx	@dptr,a
   0B17 90 80 A1           1489 	mov	dptr,#_main_ACKbuf_1_1
   0B1A 75 F0 00           1490 	mov	b,#0x00
   0B1D 12 12 89           1491 	lcall	_usb_send_packet
                           1492 ;	../main.c:246: break;
   0B20 02 11 46           1493 	ljmp	00190$
                           1494 ;	../main.c:248: for (i = 0; i < addr_width; i++) {
   0B23                    1495 00275$:
   0B23 90 80 9C           1496 	mov	dptr,#_main_addr_width_1_1
   0B26 E0                 1497 	movx	a,@dptr
   0B27 FA                 1498 	mov	r2,a
   0B28 A3                 1499 	inc	dptr
   0B29 E0                 1500 	movx	a,@dptr
   0B2A FB                 1501 	mov	r3,a
   0B2B 7C 00              1502 	mov	r4,#0x00
   0B2D 7D 00              1503 	mov	r5,#0x00
   0B2F                    1504 00210$:
   0B2F C3                 1505 	clr	c
   0B30 EC                 1506 	mov	a,r4
   0B31 9A                 1507 	subb	a,r2
   0B32 ED                 1508 	mov	a,r5
   0B33 64 80              1509 	xrl	a,#0x80
   0B35 8B F0              1510 	mov	b,r3
   0B37 63 F0 80           1511 	xrl	b,#0x80
   0B3A 95 F0              1512 	subb	a,b
   0B3C 50 2C              1513 	jnc	00213$
                           1514 ;	../main.c:249: temp_addr[i] = ubuf[i + 2];
   0B3E C0 02              1515 	push	ar2
   0B40 C0 03              1516 	push	ar3
   0B42 EC                 1517 	mov	a,r4
   0B43 24 C7              1518 	add	a,#_main_temp_addr_1_1
   0B45 FE                 1519 	mov	r6,a
   0B46 ED                 1520 	mov	a,r5
   0B47 34 80              1521 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0B49 FF                 1522 	mov	r7,a
   0B4A 8C 02              1523 	mov	ar2,r4
   0B4C 74 02              1524 	mov	a,#0x02
   0B4E 2A                 1525 	add	a,r2
   0B4F 24 38              1526 	add	a,#_ubuf
   0B51 F5 82              1527 	mov	dpl,a
   0B53 E4                 1528 	clr	a
   0B54 34 80              1529 	addc	a,#(_ubuf >> 8)
   0B56 F5 83              1530 	mov	dph,a
   0B58 E0                 1531 	movx	a,@dptr
   0B59 FA                 1532 	mov	r2,a
   0B5A 8E 82              1533 	mov	dpl,r6
   0B5C 8F 83              1534 	mov	dph,r7
   0B5E F0                 1535 	movx	@dptr,a
                           1536 ;	../main.c:248: for (i = 0; i < addr_width; i++) {
   0B5F 0C                 1537 	inc	r4
   0B60 BC 00 01           1538 	cjne	r4,#0x00,00346$
   0B63 0D                 1539 	inc	r5
   0B64                    1540 00346$:
   0B64 D0 03              1541 	pop	ar3
   0B66 D0 02              1542 	pop	ar2
   0B68 80 C5              1543 	sjmp	00210$
   0B6A                    1544 00213$:
                           1545 ;	../main.c:251: usb_send_packet(ACKbuf, 3);
   0B6A 90 80 DE           1546 	mov	dptr,#_usb_send_packet_PARM_2
   0B6D 74 03              1547 	mov	a,#0x03
   0B6F F0                 1548 	movx	@dptr,a
   0B70 90 80 A1           1549 	mov	dptr,#_main_ACKbuf_1_1
   0B73 75 F0 00           1550 	mov	b,#0x00
   0B76 12 12 89           1551 	lcall	_usb_send_packet
                           1552 ;	../main.c:252: break;
   0B79 02 11 46           1553 	ljmp	00190$
                           1554 ;	../main.c:254: for (i = 0; i < addr_width; i++) {
   0B7C                    1555 00277$:
   0B7C 90 80 9C           1556 	mov	dptr,#_main_addr_width_1_1
   0B7F E0                 1557 	movx	a,@dptr
   0B80 FA                 1558 	mov	r2,a
   0B81 A3                 1559 	inc	dptr
   0B82 E0                 1560 	movx	a,@dptr
   0B83 FB                 1561 	mov	r3,a
   0B84 7C 00              1562 	mov	r4,#0x00
   0B86 7D 00              1563 	mov	r5,#0x00
   0B88                    1564 00214$:
   0B88 C3                 1565 	clr	c
   0B89 EC                 1566 	mov	a,r4
   0B8A 9A                 1567 	subb	a,r2
   0B8B ED                 1568 	mov	a,r5
   0B8C 64 80              1569 	xrl	a,#0x80
   0B8E 8B F0              1570 	mov	b,r3
   0B90 63 F0 80           1571 	xrl	b,#0x80
   0B93 95 F0              1572 	subb	a,b
   0B95 50 2C              1573 	jnc	00217$
                           1574 ;	../main.c:255: temp_addr[i] = ubuf[i + 2];
   0B97 C0 02              1575 	push	ar2
   0B99 C0 03              1576 	push	ar3
   0B9B EC                 1577 	mov	a,r4
   0B9C 24 C7              1578 	add	a,#_main_temp_addr_1_1
   0B9E FE                 1579 	mov	r6,a
   0B9F ED                 1580 	mov	a,r5
   0BA0 34 80              1581 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0BA2 FF                 1582 	mov	r7,a
   0BA3 8C 02              1583 	mov	ar2,r4
   0BA5 74 02              1584 	mov	a,#0x02
   0BA7 2A                 1585 	add	a,r2
   0BA8 24 38              1586 	add	a,#_ubuf
   0BAA F5 82              1587 	mov	dpl,a
   0BAC E4                 1588 	clr	a
   0BAD 34 80              1589 	addc	a,#(_ubuf >> 8)
   0BAF F5 83              1590 	mov	dph,a
   0BB1 E0                 1591 	movx	a,@dptr
   0BB2 FA                 1592 	mov	r2,a
   0BB3 8E 82              1593 	mov	dpl,r6
   0BB5 8F 83              1594 	mov	dph,r7
   0BB7 F0                 1595 	movx	@dptr,a
                           1596 ;	../main.c:254: for (i = 0; i < addr_width; i++) {
   0BB8 0C                 1597 	inc	r4
   0BB9 BC 00 01           1598 	cjne	r4,#0x00,00348$
   0BBC 0D                 1599 	inc	r5
   0BBD                    1600 00348$:
   0BBD D0 03              1601 	pop	ar3
   0BBF D0 02              1602 	pop	ar2
   0BC1 80 C5              1603 	sjmp	00214$
   0BC3                    1604 00217$:
                           1605 ;	../main.c:257: usb_send_packet(ACKbuf, 3);
   0BC3 90 80 DE           1606 	mov	dptr,#_usb_send_packet_PARM_2
   0BC6 74 03              1607 	mov	a,#0x03
   0BC8 F0                 1608 	movx	@dptr,a
   0BC9 90 80 A1           1609 	mov	dptr,#_main_ACKbuf_1_1
   0BCC 75 F0 00           1610 	mov	b,#0x00
   0BCF 12 12 89           1611 	lcall	_usb_send_packet
                           1612 ;	../main.c:258: break;
   0BD2 02 11 46           1613 	ljmp	00190$
                           1614 ;	../main.c:260: for (i = 0; i < addr_width; i++) {
   0BD5                    1615 00279$:
   0BD5 90 80 9C           1616 	mov	dptr,#_main_addr_width_1_1
   0BD8 E0                 1617 	movx	a,@dptr
   0BD9 FA                 1618 	mov	r2,a
   0BDA A3                 1619 	inc	dptr
   0BDB E0                 1620 	movx	a,@dptr
   0BDC FB                 1621 	mov	r3,a
   0BDD 7C 00              1622 	mov	r4,#0x00
   0BDF 7D 00              1623 	mov	r5,#0x00
   0BE1                    1624 00218$:
   0BE1 C3                 1625 	clr	c
   0BE2 EC                 1626 	mov	a,r4
   0BE3 9A                 1627 	subb	a,r2
   0BE4 ED                 1628 	mov	a,r5
   0BE5 64 80              1629 	xrl	a,#0x80
   0BE7 8B F0              1630 	mov	b,r3
   0BE9 63 F0 80           1631 	xrl	b,#0x80
   0BEC 95 F0              1632 	subb	a,b
   0BEE 50 2C              1633 	jnc	00221$
                           1634 ;	../main.c:261: temp_addr[i] = ubuf[i + 2];
   0BF0 C0 02              1635 	push	ar2
   0BF2 C0 03              1636 	push	ar3
   0BF4 EC                 1637 	mov	a,r4
   0BF5 24 C7              1638 	add	a,#_main_temp_addr_1_1
   0BF7 FE                 1639 	mov	r6,a
   0BF8 ED                 1640 	mov	a,r5
   0BF9 34 80              1641 	addc	a,#(_main_temp_addr_1_1 >> 8)
   0BFB FF                 1642 	mov	r7,a
   0BFC 8C 02              1643 	mov	ar2,r4
   0BFE 74 02              1644 	mov	a,#0x02
   0C00 2A                 1645 	add	a,r2
   0C01 24 38              1646 	add	a,#_ubuf
   0C03 F5 82              1647 	mov	dpl,a
   0C05 E4                 1648 	clr	a
   0C06 34 80              1649 	addc	a,#(_ubuf >> 8)
   0C08 F5 83              1650 	mov	dph,a
   0C0A E0                 1651 	movx	a,@dptr
   0C0B FA                 1652 	mov	r2,a
   0C0C 8E 82              1653 	mov	dpl,r6
   0C0E 8F 83              1654 	mov	dph,r7
   0C10 F0                 1655 	movx	@dptr,a
                           1656 ;	../main.c:260: for (i = 0; i < addr_width; i++) {
   0C11 0C                 1657 	inc	r4
   0C12 BC 00 01           1658 	cjne	r4,#0x00,00350$
   0C15 0D                 1659 	inc	r5
   0C16                    1660 00350$:
   0C16 D0 03              1661 	pop	ar3
   0C18 D0 02              1662 	pop	ar2
   0C1A 80 C5              1663 	sjmp	00218$
   0C1C                    1664 00221$:
                           1665 ;	../main.c:263: usb_send_packet(ACKbuf, 3);
   0C1C 90 80 DE           1666 	mov	dptr,#_usb_send_packet_PARM_2
   0C1F 74 03              1667 	mov	a,#0x03
   0C21 F0                 1668 	movx	@dptr,a
   0C22 90 80 A1           1669 	mov	dptr,#_main_ACKbuf_1_1
   0C25 75 F0 00           1670 	mov	b,#0x00
   0C28 12 12 89           1671 	lcall	_usb_send_packet
                           1672 ;	../main.c:264: break;
   0C2B 02 11 46           1673 	ljmp	00190$
                           1674 ;	../main.c:266: case EPL_USER_PLOAD:
   0C2E                    1675 00143$:
                           1676 ;	../main.c:267: if (ubuf[2] == USRS_PLOAD) {
   0C2E 90 80 3A           1677 	mov	dptr,#(_ubuf + 0x0002)
   0C31 E0                 1678 	movx	a,@dptr
   0C32 70 4E              1679 	jnz	00145$
                           1680 ;	../main.c:268: customized_plen = (int) ubuf[3];
   0C34 90 80 3B           1681 	mov	dptr,#(_ubuf + 0x0003)
   0C37 E0                 1682 	movx	a,@dptr
   0C38 FA                 1683 	mov	r2,a
   0C39 7B 00              1684 	mov	r3,#0x00
   0C3B 90 80 9E           1685 	mov	dptr,#_main_customized_plen_1_1
   0C3E EA                 1686 	mov	a,r2
   0C3F F0                 1687 	movx	@dptr,a
   0C40 A3                 1688 	inc	dptr
   0C41 EB                 1689 	mov	a,r3
   0C42 F0                 1690 	movx	@dptr,a
                           1691 ;	../main.c:270: for (i = 0; i < customized_plen; i++) {
   0C43 7C 00              1692 	mov	r4,#0x00
   0C45 7D 00              1693 	mov	r5,#0x00
   0C47                    1694 00222$:
   0C47 C3                 1695 	clr	c
   0C48 EC                 1696 	mov	a,r4
   0C49 9A                 1697 	subb	a,r2
   0C4A ED                 1698 	mov	a,r5
   0C4B 64 80              1699 	xrl	a,#0x80
   0C4D 8B F0              1700 	mov	b,r3
   0C4F 63 F0 80           1701 	xrl	b,#0x80
   0C52 95 F0              1702 	subb	a,b
   0C54 50 5A              1703 	jnc	00146$
                           1704 ;	../main.c:271: packet[i] = ubuf[i + 4];
   0C56 C0 02              1705 	push	ar2
   0C58 C0 03              1706 	push	ar3
   0C5A EC                 1707 	mov	a,r4
   0C5B 24 7A              1708 	add	a,#_packet
   0C5D FE                 1709 	mov	r6,a
   0C5E ED                 1710 	mov	a,r5
   0C5F 34 80              1711 	addc	a,#(_packet >> 8)
   0C61 FF                 1712 	mov	r7,a
   0C62 8C 02              1713 	mov	ar2,r4
   0C64 74 04              1714 	mov	a,#0x04
   0C66 2A                 1715 	add	a,r2
   0C67 24 38              1716 	add	a,#_ubuf
   0C69 F5 82              1717 	mov	dpl,a
   0C6B E4                 1718 	clr	a
   0C6C 34 80              1719 	addc	a,#(_ubuf >> 8)
   0C6E F5 83              1720 	mov	dph,a
   0C70 E0                 1721 	movx	a,@dptr
   0C71 FA                 1722 	mov	r2,a
   0C72 8E 82              1723 	mov	dpl,r6
   0C74 8F 83              1724 	mov	dph,r7
   0C76 F0                 1725 	movx	@dptr,a
                           1726 ;	../main.c:270: for (i = 0; i < customized_plen; i++) {
   0C77 0C                 1727 	inc	r4
   0C78 BC 00 01           1728 	cjne	r4,#0x00,00353$
   0C7B 0D                 1729 	inc	r5
   0C7C                    1730 00353$:
   0C7C D0 03              1731 	pop	ar3
   0C7E D0 02              1732 	pop	ar2
   0C80 80 C5              1733 	sjmp	00222$
   0C82                    1734 00145$:
                           1735 ;	../main.c:274: customized_plen = 0;
   0C82 90 80 9E           1736 	mov	dptr,#_main_customized_plen_1_1
   0C85 E4                 1737 	clr	a
   0C86 F0                 1738 	movx	@dptr,a
   0C87 A3                 1739 	inc	dptr
   0C88 F0                 1740 	movx	@dptr,a
                           1741 ;	../main.c:276: for (i = 0; i < PLOAD_LEN; i++) {
   0C89 7A 00              1742 	mov	r2,#0x00
   0C8B 7B 00              1743 	mov	r3,#0x00
   0C8D                    1744 00226$:
   0C8D C3                 1745 	clr	c
   0C8E EA                 1746 	mov	a,r2
   0C8F 94 20              1747 	subb	a,#0x20
   0C91 EB                 1748 	mov	a,r3
   0C92 64 80              1749 	xrl	a,#0x80
   0C94 94 80              1750 	subb	a,#0x80
   0C96 50 18              1751 	jnc	00146$
                           1752 ;	../main.c:277: packet[i] = i + 9;
   0C98 EA                 1753 	mov	a,r2
   0C99 24 7A              1754 	add	a,#_packet
   0C9B F5 82              1755 	mov	dpl,a
   0C9D EB                 1756 	mov	a,r3
   0C9E 34 80              1757 	addc	a,#(_packet >> 8)
   0CA0 F5 83              1758 	mov	dph,a
   0CA2 8A 04              1759 	mov	ar4,r2
   0CA4 74 09              1760 	mov	a,#0x09
   0CA6 2C                 1761 	add	a,r4
   0CA7 FC                 1762 	mov	r4,a
   0CA8 F0                 1763 	movx	@dptr,a
                           1764 ;	../main.c:276: for (i = 0; i < PLOAD_LEN; i++) {
   0CA9 0A                 1765 	inc	r2
   0CAA BA 00 E0           1766 	cjne	r2,#0x00,00226$
   0CAD 0B                 1767 	inc	r3
   0CAE 80 DD              1768 	sjmp	00226$
   0CB0                    1769 00146$:
                           1770 ;	../main.c:281: usb_send_packet(ACKbuf, 3);
   0CB0 90 80 DE           1771 	mov	dptr,#_usb_send_packet_PARM_2
   0CB3 74 03              1772 	mov	a,#0x03
   0CB5 F0                 1773 	movx	@dptr,a
   0CB6 90 80 A1           1774 	mov	dptr,#_main_ACKbuf_1_1
   0CB9 75 F0 00           1775 	mov	b,#0x00
   0CBC 12 12 89           1776 	lcall	_usb_send_packet
                           1777 ;	../main.c:282: break;
   0CBF 02 11 46           1778 	ljmp	00190$
                           1779 ;	../main.c:284: case EPL_NEW_COUNTER:
   0CC2                    1780 00147$:
                           1781 ;	../main.c:285: total_pkt_count = 1;
   0CC2 90 80 9A           1782 	mov	dptr,#_main_total_pkt_count_1_1
   0CC5 74 01              1783 	mov	a,#0x01
   0CC7 F0                 1784 	movx	@dptr,a
   0CC8 E4                 1785 	clr	a
   0CC9 A3                 1786 	inc	dptr
   0CCA F0                 1787 	movx	@dptr,a
                           1788 ;	../main.c:286: usb_send_packet(ACKbuf, 3);
   0CCB 90 80 DE           1789 	mov	dptr,#_usb_send_packet_PARM_2
   0CCE 74 03              1790 	mov	a,#0x03
   0CD0 F0                 1791 	movx	@dptr,a
   0CD1 90 80 A1           1792 	mov	dptr,#_main_ACKbuf_1_1
   0CD4 75 F0 00           1793 	mov	b,#0x00
   0CD7 12 12 89           1794 	lcall	_usb_send_packet
                           1795 ;	../main.c:287: break;
   0CDA 02 11 46           1796 	ljmp	00190$
                           1797 ;	../main.c:290: case EPL_DYNAMIC_PD:
   0CDD                    1798 00148$:
                           1799 ;	../main.c:291: dynpd_pipe = (int)ubuf[2];
   0CDD 90 80 3A           1800 	mov	dptr,#(_ubuf + 0x0002)
   0CE0 E0                 1801 	movx	a,@dptr
   0CE1 FA                 1802 	mov	r2,a
                           1803 ;	../main.c:292: if ((int)ubuf[3] == 01){
   0CE2 90 80 3B           1804 	mov	dptr,#(_ubuf + 0x0003)
   0CE5 E0                 1805 	movx	a,@dptr
   0CE6 FB                 1806 	mov	r3,a
   0CE7 7C 00              1807 	mov	r4,#0x00
   0CE9 BB 01 2B           1808 	cjne	r3,#0x01,00150$
   0CEC BC 00 28           1809 	cjne	r4,#0x00,00150$
                           1810 ;	../main.c:294: hal_nrf_write_reg(DYNPD, (1<<dynpd_pipe) | hal_nrf_read_reg(DYNPD));
   0CEF 8A F0              1811 	mov	b,r2
   0CF1 05 F0              1812 	inc	b
   0CF3 74 01              1813 	mov	a,#0x01
   0CF5 80 02              1814 	sjmp	00359$
   0CF7                    1815 00357$:
   0CF7 25 E0              1816 	add	a,acc
   0CF9                    1817 00359$:
   0CF9 D5 F0 FB           1818 	djnz	b,00357$
   0CFC FB                 1819 	mov	r3,a
   0CFD 75 82 1C           1820 	mov	dpl,#0x1C
   0D00 C0 03              1821 	push	ar3
   0D02 12 1B 8C           1822 	lcall	_hal_nrf_read_reg
   0D05 AC 82              1823 	mov	r4,dpl
   0D07 D0 03              1824 	pop	ar3
   0D09 90 81 0F           1825 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   0D0C EC                 1826 	mov	a,r4
   0D0D 4B                 1827 	orl	a,r3
   0D0E F0                 1828 	movx	@dptr,a
   0D0F 75 82 1C           1829 	mov	dpl,#0x1C
   0D12 12 1B AA           1830 	lcall	_hal_nrf_write_reg
   0D15 80 27              1831 	sjmp	00151$
   0D17                    1832 00150$:
                           1833 ;	../main.c:298: hal_nrf_write_reg(DYNPD, ~(1<<dynpd_pipe) & hal_nrf_read_reg(DYNPD));
   0D17 8A F0              1834 	mov	b,r2
   0D19 05 F0              1835 	inc	b
   0D1B 74 01              1836 	mov	a,#0x01
   0D1D 80 02              1837 	sjmp	00362$
   0D1F                    1838 00360$:
   0D1F 25 E0              1839 	add	a,acc
   0D21                    1840 00362$:
   0D21 D5 F0 FB           1841 	djnz	b,00360$
   0D24 F4                 1842 	cpl	a
   0D25 FA                 1843 	mov	r2,a
   0D26 75 82 1C           1844 	mov	dpl,#0x1C
   0D29 C0 02              1845 	push	ar2
   0D2B 12 1B 8C           1846 	lcall	_hal_nrf_read_reg
   0D2E AB 82              1847 	mov	r3,dpl
   0D30 D0 02              1848 	pop	ar2
   0D32 90 81 0F           1849 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   0D35 EB                 1850 	mov	a,r3
   0D36 5A                 1851 	anl	a,r2
   0D37 F0                 1852 	movx	@dptr,a
   0D38 75 82 1C           1853 	mov	dpl,#0x1C
   0D3B 12 1B AA           1854 	lcall	_hal_nrf_write_reg
   0D3E                    1855 00151$:
                           1856 ;	../main.c:301: usb_send_packet(ACKbuf, 3);
   0D3E 90 80 DE           1857 	mov	dptr,#_usb_send_packet_PARM_2
   0D41 74 03              1858 	mov	a,#0x03
   0D43 F0                 1859 	movx	@dptr,a
   0D44 90 80 A1           1860 	mov	dptr,#_main_ACKbuf_1_1
   0D47 75 F0 00           1861 	mov	b,#0x00
   0D4A 12 12 89           1862 	lcall	_usb_send_packet
                           1863 ;	../main.c:302: break;
   0D4D 02 11 46           1864 	ljmp	00190$
                           1865 ;	../main.c:305: LED_Toggle();
   0D50                    1866 00153$:
   0D50 63 80 30           1867 	xrl	_P0,#0x30
                           1868 ;	../main.c:306: epl_rf_en_enter_tx_mode();
   0D53 12 04 38           1869 	lcall	_epl_rf_en_enter_tx_mode
                           1870 ;	../main.c:308: hal_nrf_clear_irq_flag(HAL_NRF_TX_DS);
   0D56 75 82 05           1871 	mov	dpl,#0x05
   0D59 12 14 02           1872 	lcall	_hal_nrf_clear_irq_flag
                           1873 ;	../main.c:309: hal_nrf_clear_irq_flag(HAL_NRF_MAX_RT);
   0D5C 75 82 04           1874 	mov	dpl,#0x04
   0D5F 12 14 02           1875 	lcall	_hal_nrf_clear_irq_flag
                           1876 ;	../main.c:311: if (ubuf[2] == AUTO_PLOAD) {
   0D62 90 80 3A           1877 	mov	dptr,#(_ubuf + 0x0002)
   0D65 E0                 1878 	movx	a,@dptr
   0D66 FA                 1879 	mov	r2,a
   0D67 BA 01 2B           1880 	cjne	r2,#0x01,00157$
                           1881 ;	../main.c:313: packet[0] = total_pkt_count++;
   0D6A 90 80 9A           1882 	mov	dptr,#_main_total_pkt_count_1_1
   0D6D E0                 1883 	movx	a,@dptr
   0D6E FA                 1884 	mov	r2,a
   0D6F A3                 1885 	inc	dptr
   0D70 E0                 1886 	movx	a,@dptr
   0D71 FB                 1887 	mov	r3,a
   0D72 90 80 9A           1888 	mov	dptr,#_main_total_pkt_count_1_1
   0D75 74 01              1889 	mov	a,#0x01
   0D77 2A                 1890 	add	a,r2
   0D78 F0                 1891 	movx	@dptr,a
   0D79 E4                 1892 	clr	a
   0D7A 3B                 1893 	addc	a,r3
   0D7B A3                 1894 	inc	dptr
   0D7C F0                 1895 	movx	@dptr,a
   0D7D 90 80 7A           1896 	mov	dptr,#_packet
   0D80 EA                 1897 	mov	a,r2
   0D81 F0                 1898 	movx	@dptr,a
                           1899 ;	../main.c:314: epl_rf_en_send(packet, data_length);
   0D82 90 80 CC           1900 	mov	dptr,#_main_data_length_1_1
   0D85 E0                 1901 	movx	a,@dptr
   0D86 90 80 2E           1902 	mov	dptr,#_epl_rf_en_send_PARM_2
   0D89 F0                 1903 	movx	@dptr,a
   0D8A 90 80 7A           1904 	mov	dptr,#_packet
   0D8D 75 F0 00           1905 	mov	b,#0x00
   0D90 12 04 CC           1906 	lcall	_epl_rf_en_send
   0D93 80 15              1907 	sjmp	00158$
   0D95                    1908 00157$:
                           1909 ;	../main.c:318: epl_rf_en_send(packet, customized_plen);
   0D95 90 80 9E           1910 	mov	dptr,#_main_customized_plen_1_1
   0D98 E0                 1911 	movx	a,@dptr
   0D99 FA                 1912 	mov	r2,a
   0D9A A3                 1913 	inc	dptr
   0D9B E0                 1914 	movx	a,@dptr
   0D9C 90 80 2E           1915 	mov	dptr,#_epl_rf_en_send_PARM_2
   0D9F EA                 1916 	mov	a,r2
   0DA0 F0                 1917 	movx	@dptr,a
   0DA1 90 80 7A           1918 	mov	dptr,#_packet
   0DA4 75 F0 00           1919 	mov	b,#0x00
   0DA7 12 04 CC           1920 	lcall	_epl_rf_en_send
   0DAA                    1921 00158$:
                           1922 ;	../main.c:322: array_cp(temp_buf, ACKbuf, 3);
   0DAA 90 80 D2           1923 	mov	dptr,#_array_cp_PARM_2
   0DAD 74 A1              1924 	mov	a,#_main_ACKbuf_1_1
   0DAF F0                 1925 	movx	@dptr,a
   0DB0 A3                 1926 	inc	dptr
   0DB1 74 80              1927 	mov	a,#(_main_ACKbuf_1_1 >> 8)
   0DB3 F0                 1928 	movx	@dptr,a
   0DB4 A3                 1929 	inc	dptr
   0DB5 E4                 1930 	clr	a
   0DB6 F0                 1931 	movx	@dptr,a
   0DB7 90 80 D5           1932 	mov	dptr,#_array_cp_PARM_3
   0DBA 74 03              1933 	mov	a,#0x03
   0DBC F0                 1934 	movx	@dptr,a
   0DBD E4                 1935 	clr	a
   0DBE A3                 1936 	inc	dptr
   0DBF F0                 1937 	movx	@dptr,a
   0DC0 90 80 A5           1938 	mov	dptr,#_main_temp_buf_1_1
   0DC3 75 F0 00           1939 	mov	b,#0x00
   0DC6 12 11 4F           1940 	lcall	_array_cp
                           1941 ;	../main.c:323: temp_buf[3] = hal_nrf_read_reg(OBSERVE_TX) & 0x0F;
   0DC9 75 82 08           1942 	mov	dpl,#0x08
   0DCC 12 1B 8C           1943 	lcall	_hal_nrf_read_reg
   0DCF E5 82              1944 	mov	a,dpl
   0DD1 54 0F              1945 	anl	a,#0x0F
   0DD3 90 80 A8           1946 	mov	dptr,#(_main_temp_buf_1_1 + 0x0003)
   0DD6 F0                 1947 	movx	@dptr,a
                           1948 ;	../main.c:324: usb_send_packet(temp_buf, 4);
   0DD7 90 80 DE           1949 	mov	dptr,#_usb_send_packet_PARM_2
   0DDA 74 04              1950 	mov	a,#0x04
   0DDC F0                 1951 	movx	@dptr,a
   0DDD 90 80 A5           1952 	mov	dptr,#_main_temp_buf_1_1
   0DE0 75 F0 00           1953 	mov	b,#0x00
   0DE3 12 12 89           1954 	lcall	_usb_send_packet
                           1955 ;	../main.c:325: epl_rf_en_enter_rx_mode();
   0DE6 12 04 40           1956 	lcall	_epl_rf_en_enter_rx_mode
                           1957 ;	../main.c:326: LED_Toggle();
   0DE9 63 80 30           1958 	xrl	_P0,#0x30
                           1959 ;	../main.c:327: break;
   0DEC 02 11 46           1960 	ljmp	00190$
                           1961 ;	../main.c:329: case EPL_RUN_DUMPER:
   0DEF                    1962 00162$:
                           1963 ;	../main.c:330: hal_nrf_clear_irq_flag(HAL_NRF_RX_DR);
   0DEF 75 82 06           1964 	mov	dpl,#0x06
   0DF2 12 14 02           1965 	lcall	_hal_nrf_clear_irq_flag
                           1966 ;	../main.c:331: hal_nrf_flush_rx();
   0DF5 12 1A DA           1967 	lcall	_hal_nrf_flush_rx
                           1968 ;	../main.c:332: epl_rf_en_enter_rx_mode();
   0DF8 12 04 40           1969 	lcall	_epl_rf_en_enter_rx_mode
                           1970 ;	../main.c:333: while (1) {
   0DFB                    1971 00186$:
                           1972 ;	../main.c:334: LED_Off();
   0DFB 43 80 30           1973 	orl	_P0,#0x30
                           1974 ;	../main.c:335: if (ubuf[1] == 0xf5) { // Host wants to terminate
   0DFE 90 80 39           1975 	mov	dptr,#(_ubuf + 0x0001)
   0E01 E0                 1976 	movx	a,@dptr
   0E02 FA                 1977 	mov	r2,a
   0E03 BA F5 06           1978 	cjne	r2,#0xF5,00183$
                           1979 ;	../main.c:337: LED_Off();
   0E06 43 80 30           1980 	orl	_P0,#0x30
                           1981 ;	../main.c:338: break;
   0E09 02 11 46           1982 	ljmp	00190$
   0E0C                    1983 00183$:
                           1984 ;	../main.c:339: }else if (hal_nrf_rx_fifo_empty() == 0) { // Rx_fifo is not empty
   0E0C 12 18 C4           1985 	lcall	_hal_nrf_rx_fifo_empty
   0E0F E5 82              1986 	mov	a,dpl
   0E11 70 E8              1987 	jnz	00186$
                           1988 ;	../main.c:340: LED_Toggle();
   0E13 63 80 30           1989 	xrl	_P0,#0x30
                           1990 ;	../main.c:341: pipe_source = hal_nrf_get_rx_data_source();
   0E16 12 1A 89           1991 	lcall	_hal_nrf_get_rx_data_source
   0E19 AA 82              1992 	mov	r2,dpl
                           1993 ;	../main.c:342: hal_nrf_read_rx_pload(temp_buf);
   0E1B 90 80 A5           1994 	mov	dptr,#_main_temp_buf_1_1
   0E1E 75 F0 00           1995 	mov	b,#0x00
   0E21 C0 02              1996 	push	ar2
   0E23 12 1A 95           1997 	lcall	_hal_nrf_read_rx_pload
   0E26 D0 02              1998 	pop	ar2
                           1999 ;	../main.c:345: temp_buf[32] = pipe_source;
   0E28 90 80 C5           2000 	mov	dptr,#(_main_temp_buf_1_1 + 0x0020)
   0E2B EA                 2001 	mov	a,r2
   0E2C F0                 2002 	movx	@dptr,a
                           2003 ;	../main.c:346: if(hal_nrf_read_reg(DYNPD)>>(int)pipe_source)
   0E2D 75 82 1C           2004 	mov	dpl,#0x1C
   0E30 C0 02              2005 	push	ar2
   0E32 12 1B 8C           2006 	lcall	_hal_nrf_read_reg
   0E35 AB 82              2007 	mov	r3,dpl
   0E37 D0 02              2008 	pop	ar2
   0E39 8A 04              2009 	mov	ar4,r2
   0E3B 7D 00              2010 	mov	r5,#0x00
   0E3D 8C F0              2011 	mov	b,r4
   0E3F 05 F0              2012 	inc	b
   0E41 EB                 2013 	mov	a,r3
   0E42 80 02              2014 	sjmp	00369$
   0E44                    2015 00368$:
   0E44 C3                 2016 	clr	c
   0E45 13                 2017 	rrc	a
   0E46                    2018 00369$:
   0E46 D5 F0 FB           2019 	djnz	b,00368$
   0E49 60 0F              2020 	jz	00173$
                           2021 ;	../main.c:347: temp_buf[33] = hal_nrf_read_reg(RD_RX_PLOAD_W);
   0E4B 75 82 60           2022 	mov	dpl,#0x60
   0E4E 12 1B 8C           2023 	lcall	_hal_nrf_read_reg
   0E51 AB 82              2024 	mov	r3,dpl
   0E53 90 80 C6           2025 	mov	dptr,#(_main_temp_buf_1_1 + 0x0021)
   0E56 EB                 2026 	mov	a,r3
   0E57 F0                 2027 	movx	@dptr,a
   0E58 80 0F              2028 	sjmp	00174$
   0E5A                    2029 00173$:
                           2030 ;	../main.c:349: temp_buf[33] = hal_nrf_read_reg(RX_PW_P0+pipe_source);
   0E5A 74 11              2031 	mov	a,#0x11
   0E5C 2A                 2032 	add	a,r2
   0E5D F5 82              2033 	mov	dpl,a
   0E5F 12 1B 8C           2034 	lcall	_hal_nrf_read_reg
   0E62 AA 82              2035 	mov	r2,dpl
   0E64 90 80 C6           2036 	mov	dptr,#(_main_temp_buf_1_1 + 0x0021)
   0E67 EA                 2037 	mov	a,r2
   0E68 F0                 2038 	movx	@dptr,a
   0E69                    2039 00174$:
                           2040 ;	../main.c:353: usb_send_packet(temp_buf, 34);
   0E69 90 80 DE           2041 	mov	dptr,#_usb_send_packet_PARM_2
   0E6C 74 22              2042 	mov	a,#0x22
   0E6E F0                 2043 	movx	@dptr,a
   0E6F 90 80 A5           2044 	mov	dptr,#_main_temp_buf_1_1
   0E72 75 F0 00           2045 	mov	b,#0x00
   0E75 12 12 89           2046 	lcall	_usb_send_packet
                           2047 ;	../main.c:355: if((hal_nrf_read_reg(STATUS))&0x10){
   0E78 75 82 07           2048 	mov	dpl,#0x07
   0E7B 12 1B 8C           2049 	lcall	_hal_nrf_read_reg
   0E7E E5 82              2050 	mov	a,dpl
   0E80 30 E4 0B           2051 	jnb	acc.4,00177$
                           2052 ;	../main.c:356: hal_nrf_write_reg(FLUSH_TX, 0);
   0E83 90 81 0F           2053 	mov	dptr,#_hal_nrf_write_reg_PARM_2
   0E86 E4                 2054 	clr	a
   0E87 F0                 2055 	movx	@dptr,a
   0E88 75 82 E1           2056 	mov	dpl,#0xE1
   0E8B 12 1B AA           2057 	lcall	_hal_nrf_write_reg
                           2058 ;	../main.c:358: LED_Toggle();
   0E8E                    2059 00177$:
   0E8E 63 80 30           2060 	xrl	_P0,#0x30
   0E91 02 0D FB           2061 	ljmp	00186$
                           2062 ;	../main.c:364: case EPL_SHOW_CONFIG:
   0E94                    2063 00188$:
                           2064 ;	../main.c:365: epl_uart_putstr("\r\n0. CONFIG = ");
   0E94 90 3A 41           2065 	mov	dptr,#__str_4
   0E97 75 F0 80           2066 	mov	b,#0x80
   0E9A 12 1E 94           2067 	lcall	_epl_uart_putstr
                           2068 ;	../main.c:366: epl_uart_puthex(hal_nrf_read_reg(CONFIG));
   0E9D 75 82 00           2069 	mov	dpl,#0x00
   0EA0 12 1B 8C           2070 	lcall	_hal_nrf_read_reg
   0EA3 7B 00              2071 	mov	r3,#0x00
   0EA5 8B 83              2072 	mov	dph,r3
   0EA7 12 1F 5F           2073 	lcall	_epl_uart_puthex
                           2074 ;	../main.c:367: epl_uart_putstr("\r\n1. RF_CH = ");
   0EAA 90 3A 50           2075 	mov	dptr,#__str_5
   0EAD 75 F0 80           2076 	mov	b,#0x80
   0EB0 12 1E 94           2077 	lcall	_epl_uart_putstr
                           2078 ;	../main.c:368: epl_uart_puthex(hal_nrf_read_reg(RF_CH));
   0EB3 75 82 05           2079 	mov	dpl,#0x05
   0EB6 12 1B 8C           2080 	lcall	_hal_nrf_read_reg
   0EB9 7B 00              2081 	mov	r3,#0x00
   0EBB 8B 83              2082 	mov	dph,r3
   0EBD 12 1F 5F           2083 	lcall	_epl_uart_puthex
                           2084 ;	../main.c:369: epl_uart_putstr("\r\n2. EN_AA = ");
   0EC0 90 3A 5E           2085 	mov	dptr,#__str_6
   0EC3 75 F0 80           2086 	mov	b,#0x80
   0EC6 12 1E 94           2087 	lcall	_epl_uart_putstr
                           2088 ;	../main.c:370: epl_uart_puthex(hal_nrf_read_reg(EN_AA));
   0EC9 75 82 01           2089 	mov	dpl,#0x01
   0ECC 12 1B 8C           2090 	lcall	_hal_nrf_read_reg
   0ECF 7B 00              2091 	mov	r3,#0x00
   0ED1 8B 83              2092 	mov	dph,r3
   0ED3 12 1F 5F           2093 	lcall	_epl_uart_puthex
                           2094 ;	../main.c:371: epl_uart_putstr("\r\n3. EN_RXADDR = ");
   0ED6 90 3A 6C           2095 	mov	dptr,#__str_7
   0ED9 75 F0 80           2096 	mov	b,#0x80
   0EDC 12 1E 94           2097 	lcall	_epl_uart_putstr
                           2098 ;	../main.c:372: epl_uart_puthex(hal_nrf_read_reg(EN_RXADDR));
   0EDF 75 82 02           2099 	mov	dpl,#0x02
   0EE2 12 1B 8C           2100 	lcall	_hal_nrf_read_reg
   0EE5 7B 00              2101 	mov	r3,#0x00
   0EE7 8B 83              2102 	mov	dph,r3
   0EE9 12 1F 5F           2103 	lcall	_epl_uart_puthex
                           2104 ;	../main.c:373: epl_uart_putstr("\r\n4. TX_ADDR = ");
   0EEC 90 3A 7E           2105 	mov	dptr,#__str_8
   0EEF 75 F0 80           2106 	mov	b,#0x80
   0EF2 12 1E 94           2107 	lcall	_epl_uart_putstr
                           2108 ;	../main.c:374: hal_nrf_read_multibyte_reg(HAL_NRF_TX, addr_buf);
   0EF5 90 81 12           2109 	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
   0EF8 74 CD              2110 	mov	a,#_main_addr_buf_1_1
   0EFA F0                 2111 	movx	@dptr,a
   0EFB A3                 2112 	inc	dptr
   0EFC 74 80              2113 	mov	a,#(_main_addr_buf_1_1 >> 8)
   0EFE F0                 2114 	movx	@dptr,a
   0EFF A3                 2115 	inc	dptr
   0F00 E4                 2116 	clr	a
   0F01 F0                 2117 	movx	@dptr,a
   0F02 75 82 06           2118 	mov	dpl,#0x06
   0F05 12 1C 17           2119 	lcall	_hal_nrf_read_multibyte_reg
                           2120 ;	../main.c:375: epl_uart_puthex(addr_buf[0]);
   0F08 90 80 CD           2121 	mov	dptr,#_main_addr_buf_1_1
   0F0B E0                 2122 	movx	a,@dptr
   0F0C FA                 2123 	mov	r2,a
   0F0D 7B 00              2124 	mov	r3,#0x00
   0F0F 8A 82              2125 	mov	dpl,r2
   0F11 8B 83              2126 	mov	dph,r3
   0F13 12 1F 5F           2127 	lcall	_epl_uart_puthex
                           2128 ;	../main.c:376: epl_uart_puthex(addr_buf[1]);
   0F16 90 80 CE           2129 	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
   0F19 E0                 2130 	movx	a,@dptr
   0F1A FA                 2131 	mov	r2,a
   0F1B 7B 00              2132 	mov	r3,#0x00
   0F1D 8A 82              2133 	mov	dpl,r2
   0F1F 8B 83              2134 	mov	dph,r3
   0F21 12 1F 5F           2135 	lcall	_epl_uart_puthex
                           2136 ;	../main.c:377: epl_uart_puthex(addr_buf[2]);
   0F24 90 80 CF           2137 	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
   0F27 E0                 2138 	movx	a,@dptr
   0F28 FA                 2139 	mov	r2,a
   0F29 7B 00              2140 	mov	r3,#0x00
   0F2B 8A 82              2141 	mov	dpl,r2
   0F2D 8B 83              2142 	mov	dph,r3
   0F2F 12 1F 5F           2143 	lcall	_epl_uart_puthex
                           2144 ;	../main.c:378: epl_uart_puthex(addr_buf[3]);
   0F32 90 80 D0           2145 	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
   0F35 E0                 2146 	movx	a,@dptr
   0F36 FA                 2147 	mov	r2,a
   0F37 7B 00              2148 	mov	r3,#0x00
   0F39 8A 82              2149 	mov	dpl,r2
   0F3B 8B 83              2150 	mov	dph,r3
   0F3D 12 1F 5F           2151 	lcall	_epl_uart_puthex
                           2152 ;	../main.c:379: epl_uart_puthex(addr_buf[4]);
   0F40 90 80 D1           2153 	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
   0F43 E0                 2154 	movx	a,@dptr
   0F44 FA                 2155 	mov	r2,a
   0F45 7B 00              2156 	mov	r3,#0x00
   0F47 8A 82              2157 	mov	dpl,r2
   0F49 8B 83              2158 	mov	dph,r3
   0F4B 12 1F 5F           2159 	lcall	_epl_uart_puthex
                           2160 ;	../main.c:380: epl_uart_putstr("\r\n4. RX_ADDR_PO = ");
   0F4E 90 3A 8E           2161 	mov	dptr,#__str_9
   0F51 75 F0 80           2162 	mov	b,#0x80
   0F54 12 1E 94           2163 	lcall	_epl_uart_putstr
                           2164 ;	../main.c:381: hal_nrf_read_multibyte_reg(HAL_NRF_PIPE0, addr_buf);
   0F57 90 81 12           2165 	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
   0F5A 74 CD              2166 	mov	a,#_main_addr_buf_1_1
   0F5C F0                 2167 	movx	@dptr,a
   0F5D A3                 2168 	inc	dptr
   0F5E 74 80              2169 	mov	a,#(_main_addr_buf_1_1 >> 8)
   0F60 F0                 2170 	movx	@dptr,a
   0F61 A3                 2171 	inc	dptr
   0F62 E4                 2172 	clr	a
   0F63 F0                 2173 	movx	@dptr,a
   0F64 75 82 00           2174 	mov	dpl,#0x00
   0F67 12 1C 17           2175 	lcall	_hal_nrf_read_multibyte_reg
                           2176 ;	../main.c:382: epl_uart_puthex(addr_buf[0]);
   0F6A 90 80 CD           2177 	mov	dptr,#_main_addr_buf_1_1
   0F6D E0                 2178 	movx	a,@dptr
   0F6E FA                 2179 	mov	r2,a
   0F6F 7B 00              2180 	mov	r3,#0x00
   0F71 8A 82              2181 	mov	dpl,r2
   0F73 8B 83              2182 	mov	dph,r3
   0F75 12 1F 5F           2183 	lcall	_epl_uart_puthex
                           2184 ;	../main.c:383: epl_uart_puthex(addr_buf[1]);
   0F78 90 80 CE           2185 	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
   0F7B E0                 2186 	movx	a,@dptr
   0F7C FA                 2187 	mov	r2,a
   0F7D 7B 00              2188 	mov	r3,#0x00
   0F7F 8A 82              2189 	mov	dpl,r2
   0F81 8B 83              2190 	mov	dph,r3
   0F83 12 1F 5F           2191 	lcall	_epl_uart_puthex
                           2192 ;	../main.c:384: epl_uart_puthex(addr_buf[2]);
   0F86 90 80 CF           2193 	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
   0F89 E0                 2194 	movx	a,@dptr
   0F8A FA                 2195 	mov	r2,a
   0F8B 7B 00              2196 	mov	r3,#0x00
   0F8D 8A 82              2197 	mov	dpl,r2
   0F8F 8B 83              2198 	mov	dph,r3
   0F91 12 1F 5F           2199 	lcall	_epl_uart_puthex
                           2200 ;	../main.c:385: epl_uart_puthex(addr_buf[3]);
   0F94 90 80 D0           2201 	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
   0F97 E0                 2202 	movx	a,@dptr
   0F98 FA                 2203 	mov	r2,a
   0F99 7B 00              2204 	mov	r3,#0x00
   0F9B 8A 82              2205 	mov	dpl,r2
   0F9D 8B 83              2206 	mov	dph,r3
   0F9F 12 1F 5F           2207 	lcall	_epl_uart_puthex
                           2208 ;	../main.c:386: epl_uart_puthex(addr_buf[4]);
   0FA2 90 80 D1           2209 	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
   0FA5 E0                 2210 	movx	a,@dptr
   0FA6 FA                 2211 	mov	r2,a
   0FA7 7B 00              2212 	mov	r3,#0x00
   0FA9 8A 82              2213 	mov	dpl,r2
   0FAB 8B 83              2214 	mov	dph,r3
   0FAD 12 1F 5F           2215 	lcall	_epl_uart_puthex
                           2216 ;	../main.c:387: epl_uart_putstr("\r\n   RX_ADDR_P1 = ");
   0FB0 90 3A A1           2217 	mov	dptr,#__str_10
   0FB3 75 F0 80           2218 	mov	b,#0x80
   0FB6 12 1E 94           2219 	lcall	_epl_uart_putstr
                           2220 ;	../main.c:388: hal_nrf_read_multibyte_reg(HAL_NRF_PIPE1, addr_buf);
   0FB9 90 81 12           2221 	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
   0FBC 74 CD              2222 	mov	a,#_main_addr_buf_1_1
   0FBE F0                 2223 	movx	@dptr,a
   0FBF A3                 2224 	inc	dptr
   0FC0 74 80              2225 	mov	a,#(_main_addr_buf_1_1 >> 8)
   0FC2 F0                 2226 	movx	@dptr,a
   0FC3 A3                 2227 	inc	dptr
   0FC4 E4                 2228 	clr	a
   0FC5 F0                 2229 	movx	@dptr,a
   0FC6 75 82 01           2230 	mov	dpl,#0x01
   0FC9 12 1C 17           2231 	lcall	_hal_nrf_read_multibyte_reg
                           2232 ;	../main.c:389: epl_uart_puthex(addr_buf[0]);
   0FCC 90 80 CD           2233 	mov	dptr,#_main_addr_buf_1_1
   0FCF E0                 2234 	movx	a,@dptr
   0FD0 FA                 2235 	mov	r2,a
   0FD1 7B 00              2236 	mov	r3,#0x00
   0FD3 8A 82              2237 	mov	dpl,r2
   0FD5 8B 83              2238 	mov	dph,r3
   0FD7 12 1F 5F           2239 	lcall	_epl_uart_puthex
                           2240 ;	../main.c:390: epl_uart_puthex(addr_buf[1]);
   0FDA 90 80 CE           2241 	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
   0FDD E0                 2242 	movx	a,@dptr
   0FDE FA                 2243 	mov	r2,a
   0FDF 7B 00              2244 	mov	r3,#0x00
   0FE1 8A 82              2245 	mov	dpl,r2
   0FE3 8B 83              2246 	mov	dph,r3
   0FE5 12 1F 5F           2247 	lcall	_epl_uart_puthex
                           2248 ;	../main.c:391: epl_uart_puthex(addr_buf[2]);
   0FE8 90 80 CF           2249 	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
   0FEB E0                 2250 	movx	a,@dptr
   0FEC FA                 2251 	mov	r2,a
   0FED 7B 00              2252 	mov	r3,#0x00
   0FEF 8A 82              2253 	mov	dpl,r2
   0FF1 8B 83              2254 	mov	dph,r3
   0FF3 12 1F 5F           2255 	lcall	_epl_uart_puthex
                           2256 ;	../main.c:392: epl_uart_puthex(addr_buf[3]);
   0FF6 90 80 D0           2257 	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
   0FF9 E0                 2258 	movx	a,@dptr
   0FFA FA                 2259 	mov	r2,a
   0FFB 7B 00              2260 	mov	r3,#0x00
   0FFD 8A 82              2261 	mov	dpl,r2
   0FFF 8B 83              2262 	mov	dph,r3
   1001 12 1F 5F           2263 	lcall	_epl_uart_puthex
                           2264 ;	../main.c:393: epl_uart_puthex(addr_buf[4]);
   1004 90 80 D1           2265 	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
   1007 E0                 2266 	movx	a,@dptr
   1008 FA                 2267 	mov	r2,a
   1009 7B 00              2268 	mov	r3,#0x00
   100B 8A 82              2269 	mov	dpl,r2
   100D 8B 83              2270 	mov	dph,r3
   100F 12 1F 5F           2271 	lcall	_epl_uart_puthex
                           2272 ;	../main.c:394: epl_uart_putstr("\r\n   RX_ADDR_P2 = ");
   1012 90 3A B4           2273 	mov	dptr,#__str_11
   1015 75 F0 80           2274 	mov	b,#0x80
   1018 12 1E 94           2275 	lcall	_epl_uart_putstr
                           2276 ;	../main.c:395: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P2));
   101B 75 82 0C           2277 	mov	dpl,#0x0C
   101E 12 1B 8C           2278 	lcall	_hal_nrf_read_reg
   1021 7B 00              2279 	mov	r3,#0x00
   1023 8B 83              2280 	mov	dph,r3
   1025 12 1F 5F           2281 	lcall	_epl_uart_puthex
                           2282 ;	../main.c:396: epl_uart_putstr("\r\n   RX_ADDR_P3 = ");
   1028 90 3A C7           2283 	mov	dptr,#__str_12
   102B 75 F0 80           2284 	mov	b,#0x80
   102E 12 1E 94           2285 	lcall	_epl_uart_putstr
                           2286 ;	../main.c:397: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P3));
   1031 75 82 0D           2287 	mov	dpl,#0x0D
   1034 12 1B 8C           2288 	lcall	_hal_nrf_read_reg
   1037 7B 00              2289 	mov	r3,#0x00
   1039 8B 83              2290 	mov	dph,r3
   103B 12 1F 5F           2291 	lcall	_epl_uart_puthex
                           2292 ;	../main.c:398: epl_uart_putstr("\r\n   RX_ADDR_P4 = ");
   103E 90 3A DA           2293 	mov	dptr,#__str_13
   1041 75 F0 80           2294 	mov	b,#0x80
   1044 12 1E 94           2295 	lcall	_epl_uart_putstr
                           2296 ;	../main.c:399: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P4));
   1047 75 82 0E           2297 	mov	dpl,#0x0E
   104A 12 1B 8C           2298 	lcall	_hal_nrf_read_reg
   104D 7B 00              2299 	mov	r3,#0x00
   104F 8B 83              2300 	mov	dph,r3
   1051 12 1F 5F           2301 	lcall	_epl_uart_puthex
                           2302 ;	../main.c:400: epl_uart_putstr("\r\n   RX_ADDR_P5 = ");
   1054 90 3A ED           2303 	mov	dptr,#__str_14
   1057 75 F0 80           2304 	mov	b,#0x80
   105A 12 1E 94           2305 	lcall	_epl_uart_putstr
                           2306 ;	../main.c:401: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P5));
   105D 75 82 0F           2307 	mov	dpl,#0x0F
   1060 12 1B 8C           2308 	lcall	_hal_nrf_read_reg
   1063 7B 00              2309 	mov	r3,#0x00
   1065 8B 83              2310 	mov	dph,r3
   1067 12 1F 5F           2311 	lcall	_epl_uart_puthex
                           2312 ;	../main.c:402: epl_uart_putstr("\r\n5. RX_PW_P0 = ");
   106A 90 3B 00           2313 	mov	dptr,#__str_15
   106D 75 F0 80           2314 	mov	b,#0x80
   1070 12 1E 94           2315 	lcall	_epl_uart_putstr
                           2316 ;	../main.c:403: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P0));
   1073 75 82 11           2317 	mov	dpl,#0x11
   1076 12 1B 8C           2318 	lcall	_hal_nrf_read_reg
   1079 7B 00              2319 	mov	r3,#0x00
   107B 8B 83              2320 	mov	dph,r3
   107D 12 1F 5F           2321 	lcall	_epl_uart_puthex
                           2322 ;	../main.c:404: epl_uart_putstr("\r\n   RX_PW_P1 = ");
   1080 90 3B 11           2323 	mov	dptr,#__str_16
   1083 75 F0 80           2324 	mov	b,#0x80
   1086 12 1E 94           2325 	lcall	_epl_uart_putstr
                           2326 ;	../main.c:405: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P1));
   1089 75 82 12           2327 	mov	dpl,#0x12
   108C 12 1B 8C           2328 	lcall	_hal_nrf_read_reg
   108F 7B 00              2329 	mov	r3,#0x00
   1091 8B 83              2330 	mov	dph,r3
   1093 12 1F 5F           2331 	lcall	_epl_uart_puthex
                           2332 ;	../main.c:406: epl_uart_putstr("\r\n   RX_PW_P2 = ");
   1096 90 3B 22           2333 	mov	dptr,#__str_17
   1099 75 F0 80           2334 	mov	b,#0x80
   109C 12 1E 94           2335 	lcall	_epl_uart_putstr
                           2336 ;	../main.c:407: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P2));
   109F 75 82 13           2337 	mov	dpl,#0x13
   10A2 12 1B 8C           2338 	lcall	_hal_nrf_read_reg
   10A5 7B 00              2339 	mov	r3,#0x00
   10A7 8B 83              2340 	mov	dph,r3
   10A9 12 1F 5F           2341 	lcall	_epl_uart_puthex
                           2342 ;	../main.c:408: epl_uart_putstr("\r\n   RX_PW_P3 = ");
   10AC 90 3B 33           2343 	mov	dptr,#__str_18
   10AF 75 F0 80           2344 	mov	b,#0x80
   10B2 12 1E 94           2345 	lcall	_epl_uart_putstr
                           2346 ;	../main.c:409: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P3));
   10B5 75 82 14           2347 	mov	dpl,#0x14
   10B8 12 1B 8C           2348 	lcall	_hal_nrf_read_reg
   10BB 7B 00              2349 	mov	r3,#0x00
   10BD 8B 83              2350 	mov	dph,r3
   10BF 12 1F 5F           2351 	lcall	_epl_uart_puthex
                           2352 ;	../main.c:410: epl_uart_putstr("\r\n   RX_PW_P4 = ");
   10C2 90 3B 44           2353 	mov	dptr,#__str_19
   10C5 75 F0 80           2354 	mov	b,#0x80
   10C8 12 1E 94           2355 	lcall	_epl_uart_putstr
                           2356 ;	../main.c:411: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P4));
   10CB 75 82 15           2357 	mov	dpl,#0x15
   10CE 12 1B 8C           2358 	lcall	_hal_nrf_read_reg
   10D1 7B 00              2359 	mov	r3,#0x00
   10D3 8B 83              2360 	mov	dph,r3
   10D5 12 1F 5F           2361 	lcall	_epl_uart_puthex
                           2362 ;	../main.c:412: epl_uart_putstr("\r\n   RX_PW_P5 = ");
   10D8 90 3B 55           2363 	mov	dptr,#__str_20
   10DB 75 F0 80           2364 	mov	b,#0x80
   10DE 12 1E 94           2365 	lcall	_epl_uart_putstr
                           2366 ;	../main.c:413: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P5));
   10E1 75 82 16           2367 	mov	dpl,#0x16
   10E4 12 1B 8C           2368 	lcall	_hal_nrf_read_reg
   10E7 7B 00              2369 	mov	r3,#0x00
   10E9 8B 83              2370 	mov	dph,r3
   10EB 12 1F 5F           2371 	lcall	_epl_uart_puthex
                           2372 ;	../main.c:414: epl_uart_putstr("\r\n6. RF_SETUP = ");
   10EE 90 3B 66           2373 	mov	dptr,#__str_21
   10F1 75 F0 80           2374 	mov	b,#0x80
   10F4 12 1E 94           2375 	lcall	_epl_uart_putstr
                           2376 ;	../main.c:415: epl_uart_puthex(hal_nrf_read_reg(RF_SETUP));
   10F7 75 82 06           2377 	mov	dpl,#0x06
   10FA 12 1B 8C           2378 	lcall	_hal_nrf_read_reg
   10FD 7B 00              2379 	mov	r3,#0x00
   10FF 8B 83              2380 	mov	dph,r3
   1101 12 1F 5F           2381 	lcall	_epl_uart_puthex
                           2382 ;	../main.c:416: epl_uart_putstr("\r\n7. STATUS = ");
   1104 90 3B 77           2383 	mov	dptr,#__str_22
   1107 75 F0 80           2384 	mov	b,#0x80
   110A 12 1E 94           2385 	lcall	_epl_uart_putstr
                           2386 ;	../main.c:417: epl_uart_puthex(hal_nrf_read_reg(STATUS));
   110D 75 82 07           2387 	mov	dpl,#0x07
   1110 12 1B 8C           2388 	lcall	_hal_nrf_read_reg
   1113 7B 00              2389 	mov	r3,#0x00
   1115 8B 83              2390 	mov	dph,r3
   1117 12 1F 5F           2391 	lcall	_epl_uart_puthex
                           2392 ;	../main.c:418: epl_uart_putstr("\r\n8 .DYNPD = ");
   111A 90 3B 86           2393 	mov	dptr,#__str_23
   111D 75 F0 80           2394 	mov	b,#0x80
   1120 12 1E 94           2395 	lcall	_epl_uart_putstr
                           2396 ;	../main.c:419: epl_uart_puthex(hal_nrf_read_reg(DYNPD));
   1123 75 82 1C           2397 	mov	dpl,#0x1C
   1126 12 1B 8C           2398 	lcall	_hal_nrf_read_reg
   1129 7B 00              2399 	mov	r3,#0x00
   112B 8B 83              2400 	mov	dph,r3
   112D 12 1F 5F           2401 	lcall	_epl_uart_puthex
                           2402 ;	../main.c:420: epl_uart_putstr("\r\n9. FEATURE = ");
   1130 90 3B 94           2403 	mov	dptr,#__str_24
   1133 75 F0 80           2404 	mov	b,#0x80
   1136 12 1E 94           2405 	lcall	_epl_uart_putstr
                           2406 ;	../main.c:421: epl_uart_puthex(hal_nrf_read_reg(FEATURE));
   1139 75 82 1D           2407 	mov	dpl,#0x1D
   113C 12 1B 8C           2408 	lcall	_hal_nrf_read_reg
   113F 7B 00              2409 	mov	r3,#0x00
   1141 8B 83              2410 	mov	dph,r3
   1143 12 1F 5F           2411 	lcall	_epl_uart_puthex
                           2412 ;	../main.c:424: }// end switch case
   1146                    2413 00190$:
                           2414 ;	../main.c:425: mdelay(1);
   1146 90 00 01           2415 	mov	dptr,#0x0001
   1149 12 38 88           2416 	lcall	_mdelay
   114C 02 05 FF           2417 	ljmp	00192$
                           2418 ;------------------------------------------------------------
                           2419 ;Allocation info for local variables in function 'array_cp'
                           2420 ;------------------------------------------------------------
                           2421 ;src_array                 Allocated with name '_array_cp_PARM_2'
                           2422 ;len                       Allocated with name '_array_cp_PARM_3'
                           2423 ;dst_array                 Allocated with name '_array_cp_dst_array_1_1'
                           2424 ;i                         Allocated with name '_array_cp_i_1_1'
                           2425 ;sloc0                     Allocated with name '_array_cp_sloc0_1_0'
                           2426 ;sloc1                     Allocated with name '_array_cp_sloc1_1_0'
                           2427 ;sloc2                     Allocated with name '_array_cp_sloc2_1_0'
                           2428 ;------------------------------------------------------------
                           2429 ;	../main.c:431: void array_cp(unsigned char *dst_array, unsigned char *src_array, int len) {
                           2430 ;	-----------------------------------------
                           2431 ;	 function array_cp
                           2432 ;	-----------------------------------------
   114F                    2433 _array_cp:
   114F AA F0              2434 	mov	r2,b
   1151 AB 83              2435 	mov	r3,dph
   1153 E5 82              2436 	mov	a,dpl
   1155 90 80 D7           2437 	mov	dptr,#_array_cp_dst_array_1_1
   1158 F0                 2438 	movx	@dptr,a
   1159 A3                 2439 	inc	dptr
   115A EB                 2440 	mov	a,r3
   115B F0                 2441 	movx	@dptr,a
   115C A3                 2442 	inc	dptr
   115D EA                 2443 	mov	a,r2
   115E F0                 2444 	movx	@dptr,a
                           2445 ;	../main.c:434: for (i = 0; i < len; i++)
   115F 90 80 D7           2446 	mov	dptr,#_array_cp_dst_array_1_1
   1162 E0                 2447 	movx	a,@dptr
   1163 FA                 2448 	mov	r2,a
   1164 A3                 2449 	inc	dptr
   1165 E0                 2450 	movx	a,@dptr
   1166 FB                 2451 	mov	r3,a
   1167 A3                 2452 	inc	dptr
   1168 E0                 2453 	movx	a,@dptr
   1169 FC                 2454 	mov	r4,a
   116A 90 80 D2           2455 	mov	dptr,#_array_cp_PARM_2
   116D E0                 2456 	movx	a,@dptr
   116E F5 12              2457 	mov	_array_cp_sloc1_1_0,a
   1170 A3                 2458 	inc	dptr
   1171 E0                 2459 	movx	a,@dptr
   1172 F5 13              2460 	mov	(_array_cp_sloc1_1_0 + 1),a
   1174 A3                 2461 	inc	dptr
   1175 E0                 2462 	movx	a,@dptr
   1176 F5 14              2463 	mov	(_array_cp_sloc1_1_0 + 2),a
   1178 90 80 D5           2464 	mov	dptr,#_array_cp_PARM_3
   117B E0                 2465 	movx	a,@dptr
   117C F8                 2466 	mov	r0,a
   117D A3                 2467 	inc	dptr
   117E E0                 2468 	movx	a,@dptr
   117F F9                 2469 	mov	r1,a
   1180 E4                 2470 	clr	a
   1181 F5 10              2471 	mov	_array_cp_sloc0_1_0,a
   1183 F5 11              2472 	mov	(_array_cp_sloc0_1_0 + 1),a
   1185                    2473 00101$:
   1185 C3                 2474 	clr	c
   1186 E5 10              2475 	mov	a,_array_cp_sloc0_1_0
   1188 98                 2476 	subb	a,r0
   1189 E5 11              2477 	mov	a,(_array_cp_sloc0_1_0 + 1)
   118B 64 80              2478 	xrl	a,#0x80
   118D 89 F0              2479 	mov	b,r1
   118F 63 F0 80           2480 	xrl	b,#0x80
   1192 95 F0              2481 	subb	a,b
   1194 50 40              2482 	jnc	00105$
                           2483 ;	../main.c:435: dst_array[i] = src_array[i];
   1196 C0 00              2484 	push	ar0
   1198 C0 01              2485 	push	ar1
   119A E5 10              2486 	mov	a,_array_cp_sloc0_1_0
   119C 2A                 2487 	add	a,r2
   119D F5 15              2488 	mov	_array_cp_sloc2_1_0,a
   119F E5 11              2489 	mov	a,(_array_cp_sloc0_1_0 + 1)
   11A1 3B                 2490 	addc	a,r3
   11A2 F5 16              2491 	mov	(_array_cp_sloc2_1_0 + 1),a
   11A4 8C 17              2492 	mov	(_array_cp_sloc2_1_0 + 2),r4
   11A6 E5 10              2493 	mov	a,_array_cp_sloc0_1_0
   11A8 25 12              2494 	add	a,_array_cp_sloc1_1_0
   11AA FE                 2495 	mov	r6,a
   11AB E5 11              2496 	mov	a,(_array_cp_sloc0_1_0 + 1)
   11AD 35 13              2497 	addc	a,(_array_cp_sloc1_1_0 + 1)
   11AF FF                 2498 	mov	r7,a
   11B0 AD 14              2499 	mov	r5,(_array_cp_sloc1_1_0 + 2)
   11B2 8E 82              2500 	mov	dpl,r6
   11B4 8F 83              2501 	mov	dph,r7
   11B6 8D F0              2502 	mov	b,r5
   11B8 12 39 EE           2503 	lcall	__gptrget
   11BB FE                 2504 	mov	r6,a
   11BC 85 15 82           2505 	mov	dpl,_array_cp_sloc2_1_0
   11BF 85 16 83           2506 	mov	dph,(_array_cp_sloc2_1_0 + 1)
   11C2 85 17 F0           2507 	mov	b,(_array_cp_sloc2_1_0 + 2)
   11C5 12 38 6F           2508 	lcall	__gptrput
                           2509 ;	../main.c:434: for (i = 0; i < len; i++)
   11C8 05 10              2510 	inc	_array_cp_sloc0_1_0
   11CA E4                 2511 	clr	a
   11CB B5 10 02           2512 	cjne	a,_array_cp_sloc0_1_0,00111$
   11CE 05 11              2513 	inc	(_array_cp_sloc0_1_0 + 1)
   11D0                    2514 00111$:
   11D0 D0 01              2515 	pop	ar1
   11D2 D0 00              2516 	pop	ar0
   11D4 80 AF              2517 	sjmp	00101$
   11D6                    2518 00105$:
   11D6 22                 2519 	ret
                           2520 	.area CSEG    (CODE)
                           2521 	.area CONST   (CODE)
   3A0E                    2522 __str_1:
   3A0E 73 74 61 72 74 21  2523 	.ascii "start!"
   3A14 00                 2524 	.db 0x00
   3A15                    2525 __str_2:
   3A15 45 50 4C 5F 4F 55  2526 	.ascii "EPL_OUTPUT_POWER"
        54 50 55 54 5F 50
        4F 57 45 52
   3A25 0A                 2527 	.db 0x0A
   3A26 00                 2528 	.db 0x00
   3A27                    2529 __str_3:
   3A27 45 50 4C 5F 4F 55  2530 	.ascii "EPL_OUTPUT_POWER     END"
        54 50 55 54 5F 50
        4F 57 45 52 20 20
        20 20 20 45 4E 44
   3A3F 0A                 2531 	.db 0x0A
   3A40 00                 2532 	.db 0x00
   3A41                    2533 __str_4:
   3A41 0D                 2534 	.db 0x0D
   3A42 0A                 2535 	.db 0x0A
   3A43 30 2E 20 43 4F 4E  2536 	.ascii "0. CONFIG = "
        46 49 47 20 3D 20
   3A4F 00                 2537 	.db 0x00
   3A50                    2538 __str_5:
   3A50 0D                 2539 	.db 0x0D
   3A51 0A                 2540 	.db 0x0A
   3A52 31 2E 20 52 46 5F  2541 	.ascii "1. RF_CH = "
        43 48 20 3D 20
   3A5D 00                 2542 	.db 0x00
   3A5E                    2543 __str_6:
   3A5E 0D                 2544 	.db 0x0D
   3A5F 0A                 2545 	.db 0x0A
   3A60 32 2E 20 45 4E 5F  2546 	.ascii "2. EN_AA = "
        41 41 20 3D 20
   3A6B 00                 2547 	.db 0x00
   3A6C                    2548 __str_7:
   3A6C 0D                 2549 	.db 0x0D
   3A6D 0A                 2550 	.db 0x0A
   3A6E 33 2E 20 45 4E 5F  2551 	.ascii "3. EN_RXADDR = "
        52 58 41 44 44 52
        20 3D 20
   3A7D 00                 2552 	.db 0x00
   3A7E                    2553 __str_8:
   3A7E 0D                 2554 	.db 0x0D
   3A7F 0A                 2555 	.db 0x0A
   3A80 34 2E 20 54 58 5F  2556 	.ascii "4. TX_ADDR = "
        41 44 44 52 20 3D
        20
   3A8D 00                 2557 	.db 0x00
   3A8E                    2558 __str_9:
   3A8E 0D                 2559 	.db 0x0D
   3A8F 0A                 2560 	.db 0x0A
   3A90 34 2E 20 52 58 5F  2561 	.ascii "4. RX_ADDR_PO = "
        41 44 44 52 5F 50
        4F 20 3D 20
   3AA0 00                 2562 	.db 0x00
   3AA1                    2563 __str_10:
   3AA1 0D                 2564 	.db 0x0D
   3AA2 0A                 2565 	.db 0x0A
   3AA3 20 20 20 52 58 5F  2566 	.ascii "   RX_ADDR_P1 = "
        41 44 44 52 5F 50
        31 20 3D 20
   3AB3 00                 2567 	.db 0x00
   3AB4                    2568 __str_11:
   3AB4 0D                 2569 	.db 0x0D
   3AB5 0A                 2570 	.db 0x0A
   3AB6 20 20 20 52 58 5F  2571 	.ascii "   RX_ADDR_P2 = "
        41 44 44 52 5F 50
        32 20 3D 20
   3AC6 00                 2572 	.db 0x00
   3AC7                    2573 __str_12:
   3AC7 0D                 2574 	.db 0x0D
   3AC8 0A                 2575 	.db 0x0A
   3AC9 20 20 20 52 58 5F  2576 	.ascii "   RX_ADDR_P3 = "
        41 44 44 52 5F 50
        33 20 3D 20
   3AD9 00                 2577 	.db 0x00
   3ADA                    2578 __str_13:
   3ADA 0D                 2579 	.db 0x0D
   3ADB 0A                 2580 	.db 0x0A
   3ADC 20 20 20 52 58 5F  2581 	.ascii "   RX_ADDR_P4 = "
        41 44 44 52 5F 50
        34 20 3D 20
   3AEC 00                 2582 	.db 0x00
   3AED                    2583 __str_14:
   3AED 0D                 2584 	.db 0x0D
   3AEE 0A                 2585 	.db 0x0A
   3AEF 20 20 20 52 58 5F  2586 	.ascii "   RX_ADDR_P5 = "
        41 44 44 52 5F 50
        35 20 3D 20
   3AFF 00                 2587 	.db 0x00
   3B00                    2588 __str_15:
   3B00 0D                 2589 	.db 0x0D
   3B01 0A                 2590 	.db 0x0A
   3B02 35 2E 20 52 58 5F  2591 	.ascii "5. RX_PW_P0 = "
        50 57 5F 50 30 20
        3D 20
   3B10 00                 2592 	.db 0x00
   3B11                    2593 __str_16:
   3B11 0D                 2594 	.db 0x0D
   3B12 0A                 2595 	.db 0x0A
   3B13 20 20 20 52 58 5F  2596 	.ascii "   RX_PW_P1 = "
        50 57 5F 50 31 20
        3D 20
   3B21 00                 2597 	.db 0x00
   3B22                    2598 __str_17:
   3B22 0D                 2599 	.db 0x0D
   3B23 0A                 2600 	.db 0x0A
   3B24 20 20 20 52 58 5F  2601 	.ascii "   RX_PW_P2 = "
        50 57 5F 50 32 20
        3D 20
   3B32 00                 2602 	.db 0x00
   3B33                    2603 __str_18:
   3B33 0D                 2604 	.db 0x0D
   3B34 0A                 2605 	.db 0x0A
   3B35 20 20 20 52 58 5F  2606 	.ascii "   RX_PW_P3 = "
        50 57 5F 50 33 20
        3D 20
   3B43 00                 2607 	.db 0x00
   3B44                    2608 __str_19:
   3B44 0D                 2609 	.db 0x0D
   3B45 0A                 2610 	.db 0x0A
   3B46 20 20 20 52 58 5F  2611 	.ascii "   RX_PW_P4 = "
        50 57 5F 50 34 20
        3D 20
   3B54 00                 2612 	.db 0x00
   3B55                    2613 __str_20:
   3B55 0D                 2614 	.db 0x0D
   3B56 0A                 2615 	.db 0x0A
   3B57 20 20 20 52 58 5F  2616 	.ascii "   RX_PW_P5 = "
        50 57 5F 50 35 20
        3D 20
   3B65 00                 2617 	.db 0x00
   3B66                    2618 __str_21:
   3B66 0D                 2619 	.db 0x0D
   3B67 0A                 2620 	.db 0x0A
   3B68 36 2E 20 52 46 5F  2621 	.ascii "6. RF_SETUP = "
        53 45 54 55 50 20
        3D 20
   3B76 00                 2622 	.db 0x00
   3B77                    2623 __str_22:
   3B77 0D                 2624 	.db 0x0D
   3B78 0A                 2625 	.db 0x0A
   3B79 37 2E 20 53 54 41  2626 	.ascii "7. STATUS = "
        54 55 53 20 3D 20
   3B85 00                 2627 	.db 0x00
   3B86                    2628 __str_23:
   3B86 0D                 2629 	.db 0x0D
   3B87 0A                 2630 	.db 0x0A
   3B88 38 20 2E 44 59 4E  2631 	.ascii "8 .DYNPD = "
        50 44 20 3D 20
   3B93 00                 2632 	.db 0x00
   3B94                    2633 __str_24:
   3B94 0D                 2634 	.db 0x0D
   3B95 0A                 2635 	.db 0x0A
   3B96 39 2E 20 46 45 41  2636 	.ascii "9. FEATURE = "
        54 55 52 45 20 3D
        20
   3BA3 00                 2637 	.db 0x00
                           2638 	.area XINIT   (CODE)
                           2639 	.area CABS    (ABS,CODE)
