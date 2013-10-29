;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Mon Oct 14 23:38:20 2013
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _DECR
	.globl _GO
	.globl _BD
	.globl _RFCKEN
	.globl _RFCSN
	.globl _RFCE
	.globl _P05
	.globl _P04
	.globl _SCSN
	.globl _MCSN
	.globl _P03
	.globl _P02
	.globl _P01
	.globl _P00
	.globl _IV0
	.globl _IV1
	.globl _IV2
	.globl _IV3
	.globl _IV4
	.globl _SUSPEND
	.globl _WU
	.globl _SWRST
	.globl _RFSPIF
	.globl _RFF
	.globl _SPIF
	.globl _USBWUF
	.globl _USBF
	.globl _WUF
	.globl _TF2
	.globl _EXF2
	.globl _RFSPI
	.globl _RF
	.globl _SPI
	.globl _USBWU
	.globl _USB
	.globl _WUIRQ
	.globl _EXEN2
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES0
	.globl _ET2
	.globl _EA
	.globl _T2I0
	.globl _T2I1
	.globl _T2CM
	.globl _T2R0
	.globl _T2R1
	.globl _I2FR
	.globl _I3FR
	.globl _T2PS
	.globl _RI0
	.globl _TI0
	.globl _RB80
	.globl _TB80
	.globl _REN0
	.globl _SM20
	.globl _SM1
	.globl _SM0
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _P
	.globl _F1
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _WPEN
	.globl _RDEND
	.globl _RDIS
	.globl _INFEN
	.globl _RDYN
	.globl _WEN
	.globl _STP
	.globl _MCDIS
	.globl _T2
	.globl _CRC
	.globl _CC3
	.globl _CC2
	.globl _CC1
	.globl _FCR
	.globl _FPCR
	.globl _FSR
	.globl _AESIA2
	.globl _AESIA1
	.globl _AESD
	.globl _AESIV
	.globl _AESKIN
	.globl _B
	.globl _ARCON
	.globl _MD5
	.globl _MD4
	.globl _MD3
	.globl _MD2
	.globl _MD1
	.globl _MD0
	.globl _AESCS
	.globl _RFCTL
	.globl _RFDAT
	.globl _ACC
	.globl _USBSLP
	.globl _WDCON
	.globl _PSW
	.globl _TH2
	.globl _TL2
	.globl _CRCH
	.globl _CRCL
	.globl _P0EXP
	.globl _T2CON
	.globl _CCH3
	.globl _CCL3
	.globl _CCH2
	.globl _CCL2
	.globl _CCH1
	.globl _CCL1
	.globl _CCEN
	.globl _IRCON
	.globl _SSSTAT
	.globl _SSDATA
	.globl _SSCONF
	.globl _S0RELH
	.globl _IP1
	.globl _IEN1
	.globl _TICKDV
	.globl _SMCTL
	.globl _SMDAT
	.globl _RSTRES
	.globl _REGXC
	.globl _REGXL
	.globl _REGXH
	.globl _S0RELL
	.globl _IP0
	.globl _IEN0
	.globl _INTEXP
	.globl _WUCONF
	.globl _PWRDWN
	.globl _CLKCTL
	.globl _USBCON
	.globl _IEN2
	.globl _S0BUF
	.globl _S0CON
	.globl _P0ALT
	.globl _P0DIR
	.globl _DPS
	.globl _RFCON
	.globl _CKCON
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH1
	.globl _DPL1
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _array_cp_PARM_3
	.globl _array_cp_PARM_2
	.globl _packet
	.globl _usize
	.globl _ubuf
	.globl _cfg
	.globl _rf_cfg_data
	.globl _array_cp
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (DATA)
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_DPL1	=	0x0084
_DPH1	=	0x0085
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_CKCON	=	0x008e
_RFCON	=	0x0090
_DPS	=	0x0092
_P0DIR	=	0x0094
_P0ALT	=	0x0095
_S0CON	=	0x0098
_S0BUF	=	0x0099
_IEN2	=	0x009a
_USBCON	=	0x00a0
_CLKCTL	=	0x00a3
_PWRDWN	=	0x00a4
_WUCONF	=	0x00a5
_INTEXP	=	0x00a6
_IEN0	=	0x00a8
_IP0	=	0x00a9
_S0RELL	=	0x00aa
_REGXH	=	0x00ab
_REGXL	=	0x00ac
_REGXC	=	0x00ad
_RSTRES	=	0x00b1
_SMDAT	=	0x00b2
_SMCTL	=	0x00b3
_TICKDV	=	0x00b5
_IEN1	=	0x00b8
_IP1	=	0x00b9
_S0RELH	=	0x00ba
_SSCONF	=	0x00bc
_SSDATA	=	0x00bd
_SSSTAT	=	0x00be
_IRCON	=	0x00c0
_CCEN	=	0x00c1
_CCL1	=	0x00c2
_CCH1	=	0x00c3
_CCL2	=	0x00c4
_CCH2	=	0x00c5
_CCL3	=	0x00c6
_CCH3	=	0x00c7
_T2CON	=	0x00c8
_P0EXP	=	0x00c9
_CRCL	=	0x00ca
_CRCH	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_PSW	=	0x00d0
_WDCON	=	0x00d8
_USBSLP	=	0x00d9
_ACC	=	0x00e0
_RFDAT	=	0x00e5
_RFCTL	=	0x00e6
_AESCS	=	0x00e8
_MD0	=	0x00e9
_MD1	=	0x00ea
_MD2	=	0x00eb
_MD3	=	0x00ec
_MD4	=	0x00ed
_MD5	=	0x00ee
_ARCON	=	0x00ef
_B	=	0x00f0
_AESKIN	=	0x00f1
_AESIV	=	0x00f2
_AESD	=	0x00f3
_AESIA1	=	0x00f5
_AESIA2	=	0x00f6
_FSR	=	0x00f8
_FPCR	=	0x00f9
_FCR	=	0x00fa
_CC1	=	0xffffc3c2
_CC2	=	0xffffc5c4
_CC3	=	0xffffc7c6
_CRC	=	0xffffcbca
_T2	=	0xffffcdcc
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (DATA)
_MCDIS	=	0x00ff
_STP	=	0x00fe
_WEN	=	0x00fd
_RDYN	=	0x00fc
_INFEN	=	0x00fb
_RDIS	=	0x00fa
_RDEND	=	0x00f9
_WPEN	=	0x00f8
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_F1	=	0x00d1
_P	=	0x00d0
_TF1	=	0x008f
_TR1	=	0x008e
_TF0	=	0x008d
_TR0	=	0x008c
_IE1	=	0x008b
_IT1	=	0x008a
_IE0	=	0x0089
_IT0	=	0x0088
_SM0	=	0x009f
_SM1	=	0x009e
_SM20	=	0x009d
_REN0	=	0x009c
_TB80	=	0x009b
_RB80	=	0x009a
_TI0	=	0x0099
_RI0	=	0x0098
_T2PS	=	0x00cf
_I3FR	=	0x00ce
_I2FR	=	0x00cd
_T2R1	=	0x00cc
_T2R0	=	0x00cb
_T2CM	=	0x00ca
_T2I1	=	0x00c9
_T2I0	=	0x00c8
_EA	=	0x00af
_ET2	=	0x00ad
_ES0	=	0x00ac
_ET1	=	0x00ab
_EX1	=	0x00aa
_ET0	=	0x00a9
_EX0	=	0x00a8
_EXEN2	=	0x00bf
_WUIRQ	=	0x00bd
_USB	=	0x00bc
_USBWU	=	0x00bb
_SPI	=	0x00ba
_RF	=	0x00b9
_RFSPI	=	0x00b8
_EXF2	=	0x00c7
_TF2	=	0x00c6
_WUF	=	0x00c5
_USBF	=	0x00c4
_USBWUF	=	0x00c3
_SPIF	=	0x00c2
_RFF	=	0x00c1
_RFSPIF	=	0x00c0
_SWRST	=	0x00a7
_WU	=	0x00a6
_SUSPEND	=	0x00a5
_IV4	=	0x00a4
_IV3	=	0x00a3
_IV2	=	0x00a2
_IV1	=	0x00a1
_IV0	=	0x00a0
_P00	=	0x0080
_P01	=	0x0081
_P02	=	0x0082
_P03	=	0x0083
_MCSN	=	0x0083
_SCSN	=	0x0083
_P04	=	0x0084
_P05	=	0x0085
_RFCE	=	0x0090
_RFCSN	=	0x0091
_RFCKEN	=	0x0092
_BD	=	0x00df
_GO	=	0x00e8
_DECR	=	0x00e9
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
	.area	OSEG    (OVR,DATA)
_array_cp_sloc0_1_0::
	.ds 2
_array_cp_sloc1_1_0::
	.ds 3
_array_cp_sloc2_1_0::
	.ds 3
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
_rf_cfg_data::
	.ds 19
_cfg::
	.ds 1
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
_ubuf::
	.ds 65
_usize::
	.ds 1
_packet::
	.ds 32
_main_total_pkt_count_1_1:
	.ds 2
_main_addr_width_1_1:
	.ds 2
_main_customized_plen_1_1:
	.ds 2
_main_auto_ack_1_1:
	.ds 1
_main_ACKbuf_1_1:
	.ds 4
_main_temp_buf_1_1:
	.ds 34
_main_temp_addr_1_1:
	.ds 5
_main_data_length_1_1:
	.ds 1
_main_addr_buf_1_1:
	.ds 5
_array_cp_PARM_2:
	.ds 3
_array_cp_PARM_3:
	.ds 2
_array_cp_dst_array_1_1:
	.ds 3
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
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_usb_wu
	.ds	5
	ljmp	_usb_irq
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	../main.c:42: idata struct epl_lu1_rf_en_config rf_cfg_data = { { 118 }, //-- RF channel --//
	mov	r0,#_rf_cfg_data
	mov	@r0,#0x76
	mov	r0,#(_rf_cfg_data + 0x0001)
	mov	@r0,#0x05
	mov	r0,#(_rf_cfg_data + 0x0002)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0003)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0004)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0005)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0006)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0007)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0008)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x0009)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x000a)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x000b)
	mov	@r0,#0x65
	mov	r0,#(_rf_cfg_data + 0x000c)
	mov	@r0,#0x20
	mov	r0,#(_rf_cfg_data + 0x000d)
	mov	@r0,#0x00
	mov	r0,#(_rf_cfg_data + 0x000e)
	mov	@r0,#0x03
	mov	r0,#(_rf_cfg_data + 0x000f)
	mov	@r0,#0x01
	mov	r0,#(_rf_cfg_data + 0x0010)
	mov	@r0,#0x0F
	mov	r0,#(_rf_cfg_data + 0x0011)
	mov	@r0,#0xFA
	inc	r0
	mov	@r0,#0x00
;	../main.c:54: idata struct epl_lu1_rf_en_config * idata cfg = &rf_cfg_data;
	mov	r0,#_cfg
	mov	@r0,#_rf_cfg_data
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;i                         Allocated with name '_main_i_1_1'
;total_pkt_count           Allocated with name '_main_total_pkt_count_1_1'
;addr_width                Allocated with name '_main_addr_width_1_1'
;customized_plen           Allocated with name '_main_customized_plen_1_1'
;pipe_num                  Allocated with name '_main_pipe_num_1_1'
;auto_ack                  Allocated with name '_main_auto_ack_1_1'
;pipe_source               Allocated with name '_main_pipe_source_1_1'
;ACKbuf                    Allocated with name '_main_ACKbuf_1_1'
;temp_buf                  Allocated with name '_main_temp_buf_1_1'
;temp_addr                 Allocated with name '_main_temp_addr_1_1'
;data_length               Allocated with name '_main_data_length_1_1'
;dynpd_pipe                Allocated with name '_main_dynpd_pipe_1_1'
;addr_buf                  Allocated with name '_main_addr_buf_1_1'
;------------------------------------------------------------
;	../main.c:58: void main(void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	../main.c:60: int total_pkt_count = 1;
	mov	dptr,#_main_total_pkt_count_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:61: int addr_width = 5;
	mov	dptr,#_main_addr_width_1_1
	mov	a,#0x05
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:62: int customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:64: epl_rf_en_auto_ack_t auto_ack = 0;
	mov	dptr,#_main_auto_ack_1_1
	clr	a
	movx	@dptr,a
;	../main.c:69: unsigned char ACKbuf[] = "ACK";
	mov	dptr,#_main_ACKbuf_1_1
	mov	a,#0x41
	movx	@dptr,a
	mov	dptr,#(_main_ACKbuf_1_1 + 0x0001)
	mov	a,#0x43
	movx	@dptr,a
	mov	dptr,#(_main_ACKbuf_1_1 + 0x0002)
	mov	a,#0x4B
	movx	@dptr,a
	mov	dptr,#(_main_ACKbuf_1_1 + 0x0003)
;	../main.c:72: unsigned char data_length = 0;
	clr	a
	movx	@dptr,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:76: P0EXP = 0x00;
	mov	_P0EXP,#0x00
;	../main.c:77: P0ALT = 0x00;
	mov	_P0ALT,#0x00
;	../main.c:78: P0DIR = 0x00;
	mov	_P0DIR,#0x00
;	../main.c:81: epl_uart_init(UART_BAUD_57K6);
	mov	dpl,#0x03
	lcall	_epl_uart_init
;	../main.c:83: usb_init(); // Initialize USB
	lcall	_usb_init
;	../main.c:84: EA = 1; // Enable global IRQ
	setb	_EA
;	../main.c:86: epl_rf_en_quick_init(cfg);
	mov	r0,#_cfg
	mov	ar2,@r0
	mov	r3,#0x00
	mov	r4,#0x40
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_epl_rf_en_quick_init
;	../main.c:89: hal_nrf_write_reg(FLUSH_TX, 0);
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	clr	a
	movx	@dptr,a
	mov	dpl,#0xE1
	lcall	_hal_nrf_write_reg
;	../main.c:90: hal_nrf_write_reg(FLUSH_RX, 0);
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	clr	a
	movx	@dptr,a
	mov	dpl,#0xE2
	lcall	_hal_nrf_write_reg
;	../main.c:92: hal_nrf_lock_unlock();
	lcall	_hal_nrf_lock_unlock
;	../main.c:93: hal_nrf_enable_dynamic_pl();
	lcall	_hal_nrf_enable_dynamic_pl
;	../main.c:95: LED_Blink(20);
	xrl	_P0,#0x30
	mov	dptr,#0x0014
	lcall	_mdelay
	xrl	_P0,#0x30
	mov	dptr,#0x0014
	lcall	_mdelay
;	../main.c:96: epl_uart_putstr("start!");
	mov	dptr,#__str_1
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:97: while (1) {
00192$:
;	../main.c:98: usb_recv_packet();
	lcall	_usb_recv_packet
;	../main.c:99: switch (ubuf[1]) {
	mov	dptr,#(_ubuf + 0x0001)
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,00302$
	ljmp	00112$
00302$:
	cjne	r2,#0x02,00303$
	ljmp	00113$
00303$:
	cjne	r2,#0x03,00304$
	ljmp	00114$
00304$:
	cjne	r2,#0x04,00305$
	ljmp	00115$
00305$:
	cjne	r2,#0x05,00306$
	ljmp	00128$
00306$:
	cjne	r2,#0x10,00307$
	ljmp	00269$
00307$:
	cjne	r2,#0x11,00308$
	ljmp	00271$
00308$:
	cjne	r2,#0x12,00309$
	ljmp	00273$
00309$:
	cjne	r2,#0x13,00310$
	ljmp	00275$
00310$:
	cjne	r2,#0x14,00311$
	ljmp	00277$
00311$:
	cjne	r2,#0x15,00312$
	ljmp	00279$
00312$:
	cjne	r2,#0x30,00313$
	ljmp	00116$
00313$:
	cjne	r2,#0x31,00314$
	ljmp	00117$
00314$:
	cjne	r2,#0x32,00315$
	ljmp	00118$
00315$:
	cjne	r2,#0x33,00316$
	ljmp	00119$
00316$:
	cjne	r2,#0x34,00317$
	ljmp	00120$
00317$:
	cjne	r2,#0x35,00318$
	ljmp	00121$
00318$:
	cjne	r2,#0x40,00319$
	ljmp	00122$
00319$:
	cjne	r2,#0x41,00320$
	ljmp	00123$
00320$:
	cjne	r2,#0x42,00321$
	ljmp	00124$
00321$:
	cjne	r2,#0x43,00322$
	ljmp	00125$
00322$:
	cjne	r2,#0x44,00323$
	ljmp	00126$
00323$:
	cjne	r2,#0x45,00324$
	ljmp	00127$
00324$:
	cjne	r2,#0xF2,00325$
	ljmp	00188$
00325$:
	cjne	r2,#0xF3,00326$
	sjmp	00105$
00326$:
	cjne	r2,#0xF4,00327$
	sjmp	00109$
00327$:
	cjne	r2,#0xF6,00328$
	ljmp	00153$
00328$:
	cjne	r2,#0xF7,00329$
	ljmp	00162$
00329$:
	cjne	r2,#0xF8,00330$
	ljmp	00147$
00330$:
	cjne	r2,#0xF9,00331$
	ljmp	00143$
00331$:
	cjne	r2,#0xFA,00332$
	ljmp	00148$
00332$:
	ljmp	00190$
;	../main.c:102: LED_Off();
00105$:
	orl	_P0,#0x30
;	../main.c:103: customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:104: for (i = 0; i < PLOAD_LEN; i++)
	mov	r2,#0x00
	mov	r3,#0x00
00194$:
	clr	c
	mov	a,r2
	subb	a,#0x20
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00197$
;	../main.c:105: packet[i] = i + 9;
	mov	a,r2
	add	a,#_packet
	mov	dpl,a
	mov	a,r3
	addc	a,#(_packet >> 8)
	mov	dph,a
	mov	ar4,r2
	mov	a,#0x09
	add	a,r4
	mov	r4,a
	movx	@dptr,a
;	../main.c:104: for (i = 0; i < PLOAD_LEN; i++)
	inc	r2
	cjne	r2,#0x00,00194$
	inc	r3
	sjmp	00194$
00197$:
;	../main.c:106: hal_nrf_close_pipe(HAL_NRF_PIPE1);
	mov	dpl,#0x01
	lcall	_hal_nrf_close_pipe
;	../main.c:107: hal_nrf_close_pipe(HAL_NRF_PIPE2);
	mov	dpl,#0x02
	lcall	_hal_nrf_close_pipe
;	../main.c:108: hal_nrf_close_pipe(HAL_NRF_PIPE3);
	mov	dpl,#0x03
	lcall	_hal_nrf_close_pipe
;	../main.c:109: hal_nrf_close_pipe(HAL_NRF_PIPE4);
	mov	dpl,#0x04
	lcall	_hal_nrf_close_pipe
;	../main.c:110: hal_nrf_close_pipe(HAL_NRF_PIPE5);
	mov	dpl,#0x05
	lcall	_hal_nrf_close_pipe
;	../main.c:111: break;
	ljmp	00190$
;	../main.c:114: LED_Off();
00109$:
	orl	_P0,#0x30
;	../main.c:115: hal_nrf_close_pipe(HAL_NRF_PIPE1);
	mov	dpl,#0x01
	lcall	_hal_nrf_close_pipe
;	../main.c:116: hal_nrf_close_pipe(HAL_NRF_PIPE2);
	mov	dpl,#0x02
	lcall	_hal_nrf_close_pipe
;	../main.c:117: hal_nrf_close_pipe(HAL_NRF_PIPE3);
	mov	dpl,#0x03
	lcall	_hal_nrf_close_pipe
;	../main.c:118: hal_nrf_close_pipe(HAL_NRF_PIPE4);
	mov	dpl,#0x04
	lcall	_hal_nrf_close_pipe
;	../main.c:119: hal_nrf_close_pipe(HAL_NRF_PIPE5);
	mov	dpl,#0x05
	lcall	_hal_nrf_close_pipe
;	../main.c:120: break;
	ljmp	00190$
;	../main.c:122: case EPL_OUTPUT_POWER: 			//Host:set_output_power
00112$:
;	../main.c:123: hal_nrf_set_output_power(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_output_power
;	../main.c:124: epl_uart_putstr("EPL_OUTPUT_POWER\n");
	mov	dptr,#__str_2
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:125: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:126: epl_uart_putstr("EPL_OUTPUT_POWER     END\n");
	mov	dptr,#__str_3
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:127: break;
	ljmp	00190$
;	../main.c:129: case EPL_CHANNEL:
00113$:
;	../main.c:130: hal_nrf_set_rf_channel(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_rf_channel
;	../main.c:131: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:132: break;
	ljmp	00190$
;	../main.c:134: case EPL_DATARATE:
00114$:
;	../main.c:135: hal_nrf_set_datarate(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_datarate
;	../main.c:136: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:137: break;
	ljmp	00190$
;	../main.c:139: case EPL_ADDR_WIDTH:
00115$:
;	../main.c:140: addr_width = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_addr_width_1_1
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
;	../main.c:141: hal_nrf_set_address_width(ubuf[2]);
	mov	dpl,r2
	lcall	_hal_nrf_set_address_width
;	../main.c:142: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:143: break;
	ljmp	00190$
;	../main.c:145: case EPL_AUTOACK_P0:
00116$:
;	../main.c:146: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:147: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:148: break;
	ljmp	00190$
;	../main.c:150: case EPL_AUTOACK_P1:
00117$:
;	../main.c:151: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:152: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:153: break;
	ljmp	00190$
;	../main.c:155: case EPL_AUTOACK_P2:
00118$:
;	../main.c:156: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:157: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:158: break;
	ljmp	00190$
;	../main.c:160: case EPL_AUTOACK_P3:
00119$:
;	../main.c:161: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:162: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:163: break;
	ljmp	00190$
;	../main.c:165: case EPL_AUTOACK_P4:
00120$:
;	../main.c:166: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:167: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:168: break;
	ljmp	00190$
;	../main.c:170: case EPL_AUTOACK_P5:
00121$:
;	../main.c:171: auto_ack = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_main_auto_ack_1_1
	movx	@dptr,a
;	../main.c:172: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:173: break;
	ljmp	00190$
;	../main.c:175: case EPL_DATA_LENGTH_P0:
00122$:
;	../main.c:176: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:177: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:178: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:179: break;
	ljmp	00190$
;	../main.c:181: case EPL_DATA_LENGTH_P1:
00123$:
;	../main.c:182: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:183: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE1, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x01
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:184: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:185: break;
	ljmp	00190$
;	../main.c:187: case EPL_DATA_LENGTH_P2:
00124$:
;	../main.c:188: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:189: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE2, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x02
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:190: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:191: break;
	ljmp	00190$
;	../main.c:193: case EPL_DATA_LENGTH_P3:
00125$:
;	../main.c:194: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:195: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE3, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x03
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:196: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:197: break;
	ljmp	00190$
;	../main.c:200: case EPL_DATA_LENGTH_P4:
00126$:
;	../main.c:201: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:202: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE4, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x04
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:203: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:204: break;
	ljmp	00190$
;	../main.c:206: case EPL_DATA_LENGTH_P5:
00127$:
;	../main.c:207: data_length = (int) ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
;	../main.c:208: epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE5, temp_addr, data_length, auto_ack);
	mov	dptr,#_main_auto_ack_1_1
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dpl,#0x05
	lcall	_epl_rf_en_rcv_pipe_config
;	../main.c:209: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:210: break;
	ljmp	00190$
;	../main.c:212: case EPL_CRC_MODE:
00128$:
;	../main.c:213: if (ubuf[2] == 0)
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
;	../main.c:214: hal_nrf_set_crc_mode(HAL_NRF_CRC_OFF);
	jnz	00135$
	mov	dpl,a
	lcall	_hal_nrf_set_crc_mode
	sjmp	00136$
00135$:
;	../main.c:215: else if (ubuf[2] == 2)
	cjne	r2,#0x02,00132$
;	../main.c:216: hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT);
	mov	dpl,#0x02
	lcall	_hal_nrf_set_crc_mode
	sjmp	00136$
00132$:
;	../main.c:217: else if (ubuf[2] == 3)
	cjne	r2,#0x03,00136$
;	../main.c:218: hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);
	mov	dpl,#0x03
	lcall	_hal_nrf_set_crc_mode
00136$:
;	../main.c:222: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:223: break;
	ljmp	00190$
;	../main.c:226: for (i = 0; i < addr_width; i++) {
00269$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00198$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00201$
;	../main.c:227: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:226: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00340$
	inc	r5
00340$:
	pop	ar3
	pop	ar2
	sjmp	00198$
00201$:
;	../main.c:229: hal_nrf_set_address(HAL_NRF_PIPE0, temp_addr);
	mov	dptr,#_hal_nrf_set_address_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_hal_nrf_set_address
;	../main.c:230: epl_rf_en_set_dst_addr(temp_addr);
	mov	dptr,#_main_temp_addr_1_1
	mov	b,#0x00
	lcall	_epl_rf_en_set_dst_addr
;	../main.c:232: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:233: break;
	ljmp	00190$
;	../main.c:236: for (i = 0; i < addr_width; i++) {
00271$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00202$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00205$
;	../main.c:237: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:236: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00342$
	inc	r5
00342$:
	pop	ar3
	pop	ar2
	sjmp	00202$
00205$:
;	../main.c:239: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:240: break;
	ljmp	00190$
;	../main.c:242: for (i = 0; i < addr_width; i++) {
00273$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00206$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00209$
;	../main.c:243: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:242: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00344$
	inc	r5
00344$:
	pop	ar3
	pop	ar2
	sjmp	00206$
00209$:
;	../main.c:245: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:246: break;
	ljmp	00190$
;	../main.c:248: for (i = 0; i < addr_width; i++) {
00275$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00210$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00213$
;	../main.c:249: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:248: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00346$
	inc	r5
00346$:
	pop	ar3
	pop	ar2
	sjmp	00210$
00213$:
;	../main.c:251: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:252: break;
	ljmp	00190$
;	../main.c:254: for (i = 0; i < addr_width; i++) {
00277$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00214$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00217$
;	../main.c:255: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:254: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00348$
	inc	r5
00348$:
	pop	ar3
	pop	ar2
	sjmp	00214$
00217$:
;	../main.c:257: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:258: break;
	ljmp	00190$
;	../main.c:260: for (i = 0; i < addr_width; i++) {
00279$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	mov	r5,#0x00
00218$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00221$
;	../main.c:261: temp_addr[i] = ubuf[i + 2];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_main_temp_addr_1_1
	mov	r6,a
	mov	a,r5
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x02
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:260: for (i = 0; i < addr_width; i++) {
	inc	r4
	cjne	r4,#0x00,00350$
	inc	r5
00350$:
	pop	ar3
	pop	ar2
	sjmp	00218$
00221$:
;	../main.c:263: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:264: break;
	ljmp	00190$
;	../main.c:266: case EPL_USER_PLOAD:
00143$:
;	../main.c:267: if (ubuf[2] == USRS_PLOAD) {
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	jnz	00145$
;	../main.c:268: customized_plen = (int) ubuf[3];
	mov	dptr,#(_ubuf + 0x0003)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dptr,#_main_customized_plen_1_1
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
;	../main.c:270: for (i = 0; i < customized_plen; i++) {
	mov	r4,#0x00
	mov	r5,#0x00
00222$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r5
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00146$
;	../main.c:271: packet[i] = ubuf[i + 4];
	push	ar2
	push	ar3
	mov	a,r4
	add	a,#_packet
	mov	r6,a
	mov	a,r5
	addc	a,#(_packet >> 8)
	mov	r7,a
	mov	ar2,r4
	mov	a,#0x04
	add	a,r2
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r6
	mov	dph,r7
	movx	@dptr,a
;	../main.c:270: for (i = 0; i < customized_plen; i++) {
	inc	r4
	cjne	r4,#0x00,00353$
	inc	r5
00353$:
	pop	ar3
	pop	ar2
	sjmp	00222$
00145$:
;	../main.c:274: customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:276: for (i = 0; i < PLOAD_LEN; i++) {
	mov	r2,#0x00
	mov	r3,#0x00
00226$:
	clr	c
	mov	a,r2
	subb	a,#0x20
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00146$
;	../main.c:277: packet[i] = i + 9;
	mov	a,r2
	add	a,#_packet
	mov	dpl,a
	mov	a,r3
	addc	a,#(_packet >> 8)
	mov	dph,a
	mov	ar4,r2
	mov	a,#0x09
	add	a,r4
	mov	r4,a
	movx	@dptr,a
;	../main.c:276: for (i = 0; i < PLOAD_LEN; i++) {
	inc	r2
	cjne	r2,#0x00,00226$
	inc	r3
	sjmp	00226$
00146$:
;	../main.c:281: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:282: break;
	ljmp	00190$
;	../main.c:284: case EPL_NEW_COUNTER:
00147$:
;	../main.c:285: total_pkt_count = 1;
	mov	dptr,#_main_total_pkt_count_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:286: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:287: break;
	ljmp	00190$
;	../main.c:290: case EPL_DYNAMIC_PD:
00148$:
;	../main.c:291: dynpd_pipe = (int)ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
;	../main.c:292: if ((int)ubuf[3] == 01){
	mov	dptr,#(_ubuf + 0x0003)
	movx	a,@dptr
	mov	r3,a
	mov	r4,#0x00
	cjne	r3,#0x01,00150$
	cjne	r4,#0x00,00150$
;	../main.c:294: hal_nrf_write_reg(DYNPD, (1<<dynpd_pipe) | hal_nrf_read_reg(DYNPD));
	mov	b,r2
	inc	b
	mov	a,#0x01
	sjmp	00359$
00357$:
	add	a,acc
00359$:
	djnz	b,00357$
	mov	r3,a
	mov	dpl,#0x1C
	push	ar3
	lcall	_hal_nrf_read_reg
	mov	r4,dpl
	pop	ar3
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	mov	a,r4
	orl	a,r3
	movx	@dptr,a
	mov	dpl,#0x1C
	lcall	_hal_nrf_write_reg
	sjmp	00151$
00150$:
;	../main.c:298: hal_nrf_write_reg(DYNPD, ~(1<<dynpd_pipe) & hal_nrf_read_reg(DYNPD));
	mov	b,r2
	inc	b
	mov	a,#0x01
	sjmp	00362$
00360$:
	add	a,acc
00362$:
	djnz	b,00360$
	cpl	a
	mov	r2,a
	mov	dpl,#0x1C
	push	ar2
	lcall	_hal_nrf_read_reg
	mov	r3,dpl
	pop	ar2
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	mov	a,r3
	anl	a,r2
	movx	@dptr,a
	mov	dpl,#0x1C
	lcall	_hal_nrf_write_reg
00151$:
;	../main.c:301: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:302: break;
	ljmp	00190$
;	../main.c:305: LED_Toggle();
00153$:
	xrl	_P0,#0x30
;	../main.c:306: epl_rf_en_enter_tx_mode();
	lcall	_epl_rf_en_enter_tx_mode
;	../main.c:308: hal_nrf_clear_irq_flag(HAL_NRF_TX_DS);
	mov	dpl,#0x05
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:309: hal_nrf_clear_irq_flag(HAL_NRF_MAX_RT);
	mov	dpl,#0x04
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:311: if (ubuf[2] == AUTO_PLOAD) {
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,00157$
;	../main.c:313: packet[0] = total_pkt_count++;
	mov	dptr,#_main_total_pkt_count_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_main_total_pkt_count_1_1
	mov	a,#0x01
	add	a,r2
	movx	@dptr,a
	clr	a
	addc	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_packet
	mov	a,r2
	movx	@dptr,a
;	../main.c:314: epl_rf_en_send(packet, data_length);
	mov	dptr,#_main_data_length_1_1
	movx	a,@dptr
	mov	dptr,#_epl_rf_en_send_PARM_2
	movx	@dptr,a
	mov	dptr,#_packet
	mov	b,#0x00
	lcall	_epl_rf_en_send
	sjmp	00158$
00157$:
;	../main.c:318: epl_rf_en_send(packet, customized_plen);
	mov	dptr,#_main_customized_plen_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	dptr,#_epl_rf_en_send_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#_packet
	mov	b,#0x00
	lcall	_epl_rf_en_send
00158$:
;	../main.c:322: array_cp(temp_buf, ACKbuf, 3);
	mov	dptr,#_array_cp_PARM_2
	mov	a,#_main_ACKbuf_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_ACKbuf_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dptr,#_array_cp_PARM_3
	mov	a,#0x03
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_array_cp
;	../main.c:323: temp_buf[3] = hal_nrf_read_reg(OBSERVE_TX) & 0x0F;
	mov	dpl,#0x08
	lcall	_hal_nrf_read_reg
	mov	a,dpl
	anl	a,#0x0F
	mov	dptr,#(_main_temp_buf_1_1 + 0x0003)
	movx	@dptr,a
;	../main.c:324: usb_send_packet(temp_buf, 4);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x04
	movx	@dptr,a
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:325: epl_rf_en_enter_rx_mode();
	lcall	_epl_rf_en_enter_rx_mode
;	../main.c:326: LED_Toggle();
	xrl	_P0,#0x30
;	../main.c:327: break;
	ljmp	00190$
;	../main.c:329: case EPL_RUN_DUMPER:
00162$:
;	../main.c:330: hal_nrf_clear_irq_flag(HAL_NRF_RX_DR);
	mov	dpl,#0x06
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:331: hal_nrf_flush_rx();
	lcall	_hal_nrf_flush_rx
;	../main.c:332: epl_rf_en_enter_rx_mode();
	lcall	_epl_rf_en_enter_rx_mode
;	../main.c:333: while (1) {
00186$:
;	../main.c:334: LED_Off();
	orl	_P0,#0x30
;	../main.c:335: if (ubuf[1] == 0xf5) { // Host wants to terminate
	mov	dptr,#(_ubuf + 0x0001)
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0xF5,00183$
;	../main.c:337: LED_Off();
	orl	_P0,#0x30
;	../main.c:338: break;
	ljmp	00190$
00183$:
;	../main.c:339: }else if (hal_nrf_rx_fifo_empty() == 0) { // Rx_fifo is not empty
	lcall	_hal_nrf_rx_fifo_empty
	mov	a,dpl
	jnz	00186$
;	../main.c:340: LED_Toggle();
	xrl	_P0,#0x30
;	../main.c:341: pipe_source = hal_nrf_get_rx_data_source();
	lcall	_hal_nrf_get_rx_data_source
	mov	r2,dpl
;	../main.c:342: hal_nrf_read_rx_pload(temp_buf);
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	push	ar2
	lcall	_hal_nrf_read_rx_pload
	pop	ar2
;	../main.c:345: temp_buf[32] = pipe_source;
	mov	dptr,#(_main_temp_buf_1_1 + 0x0020)
	mov	a,r2
	movx	@dptr,a
;	../main.c:346: if(hal_nrf_read_reg(DYNPD)>>(int)pipe_source)
	mov	dpl,#0x1C
	push	ar2
	lcall	_hal_nrf_read_reg
	mov	r3,dpl
	pop	ar2
	mov	ar4,r2
	mov	r5,#0x00
	mov	b,r4
	inc	b
	mov	a,r3
	sjmp	00369$
00368$:
	clr	c
	rrc	a
00369$:
	djnz	b,00368$
	jz	00173$
;	../main.c:347: temp_buf[33] = hal_nrf_read_reg(RD_RX_PLOAD_W);
	mov	dpl,#0x60
	lcall	_hal_nrf_read_reg
	mov	r3,dpl
	mov	dptr,#(_main_temp_buf_1_1 + 0x0021)
	mov	a,r3
	movx	@dptr,a
	sjmp	00174$
00173$:
;	../main.c:349: temp_buf[33] = hal_nrf_read_reg(RX_PW_P0+pipe_source);
	mov	a,#0x11
	add	a,r2
	mov	dpl,a
	lcall	_hal_nrf_read_reg
	mov	r2,dpl
	mov	dptr,#(_main_temp_buf_1_1 + 0x0021)
	mov	a,r2
	movx	@dptr,a
00174$:
;	../main.c:353: usb_send_packet(temp_buf, 34);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x22
	movx	@dptr,a
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:355: if((hal_nrf_read_reg(STATUS))&0x10){
	mov	dpl,#0x07
	lcall	_hal_nrf_read_reg
	mov	a,dpl
	jnb	acc.4,00177$
;	../main.c:356: hal_nrf_write_reg(FLUSH_TX, 0);
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	clr	a
	movx	@dptr,a
	mov	dpl,#0xE1
	lcall	_hal_nrf_write_reg
;	../main.c:358: LED_Toggle();
00177$:
	xrl	_P0,#0x30
	ljmp	00186$
;	../main.c:364: case EPL_SHOW_CONFIG:
00188$:
;	../main.c:365: epl_uart_putstr("\r\n0. CONFIG = ");
	mov	dptr,#__str_4
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:366: epl_uart_puthex(hal_nrf_read_reg(CONFIG));
	mov	dpl,#0x00
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:367: epl_uart_putstr("\r\n1. RF_CH = ");
	mov	dptr,#__str_5
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:368: epl_uart_puthex(hal_nrf_read_reg(RF_CH));
	mov	dpl,#0x05
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:369: epl_uart_putstr("\r\n2. EN_AA = ");
	mov	dptr,#__str_6
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:370: epl_uart_puthex(hal_nrf_read_reg(EN_AA));
	mov	dpl,#0x01
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:371: epl_uart_putstr("\r\n3. EN_RXADDR = ");
	mov	dptr,#__str_7
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:372: epl_uart_puthex(hal_nrf_read_reg(EN_RXADDR));
	mov	dpl,#0x02
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:373: epl_uart_putstr("\r\n4. TX_ADDR = ");
	mov	dptr,#__str_8
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:374: hal_nrf_read_multibyte_reg(HAL_NRF_TX, addr_buf);
	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
	mov	a,#_main_addr_buf_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_addr_buf_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x06
	lcall	_hal_nrf_read_multibyte_reg
;	../main.c:375: epl_uart_puthex(addr_buf[0]);
	mov	dptr,#_main_addr_buf_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:376: epl_uart_puthex(addr_buf[1]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:377: epl_uart_puthex(addr_buf[2]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:378: epl_uart_puthex(addr_buf[3]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:379: epl_uart_puthex(addr_buf[4]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:380: epl_uart_putstr("\r\n4. RX_ADDR_PO = ");
	mov	dptr,#__str_9
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:381: hal_nrf_read_multibyte_reg(HAL_NRF_PIPE0, addr_buf);
	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
	mov	a,#_main_addr_buf_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_addr_buf_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_hal_nrf_read_multibyte_reg
;	../main.c:382: epl_uart_puthex(addr_buf[0]);
	mov	dptr,#_main_addr_buf_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:383: epl_uart_puthex(addr_buf[1]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:384: epl_uart_puthex(addr_buf[2]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:385: epl_uart_puthex(addr_buf[3]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:386: epl_uart_puthex(addr_buf[4]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:387: epl_uart_putstr("\r\n   RX_ADDR_P1 = ");
	mov	dptr,#__str_10
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:388: hal_nrf_read_multibyte_reg(HAL_NRF_PIPE1, addr_buf);
	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
	mov	a,#_main_addr_buf_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_addr_buf_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x01
	lcall	_hal_nrf_read_multibyte_reg
;	../main.c:389: epl_uart_puthex(addr_buf[0]);
	mov	dptr,#_main_addr_buf_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:390: epl_uart_puthex(addr_buf[1]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0001)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:391: epl_uart_puthex(addr_buf[2]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:392: epl_uart_puthex(addr_buf[3]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0003)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:393: epl_uart_puthex(addr_buf[4]);
	mov	dptr,#(_main_addr_buf_1_1 + 0x0004)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:394: epl_uart_putstr("\r\n   RX_ADDR_P2 = ");
	mov	dptr,#__str_11
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:395: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P2));
	mov	dpl,#0x0C
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:396: epl_uart_putstr("\r\n   RX_ADDR_P3 = ");
	mov	dptr,#__str_12
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:397: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P3));
	mov	dpl,#0x0D
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:398: epl_uart_putstr("\r\n   RX_ADDR_P4 = ");
	mov	dptr,#__str_13
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:399: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P4));
	mov	dpl,#0x0E
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:400: epl_uart_putstr("\r\n   RX_ADDR_P5 = ");
	mov	dptr,#__str_14
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:401: epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P5));
	mov	dpl,#0x0F
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:402: epl_uart_putstr("\r\n5. RX_PW_P0 = ");
	mov	dptr,#__str_15
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:403: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P0));
	mov	dpl,#0x11
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:404: epl_uart_putstr("\r\n   RX_PW_P1 = ");
	mov	dptr,#__str_16
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:405: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P1));
	mov	dpl,#0x12
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:406: epl_uart_putstr("\r\n   RX_PW_P2 = ");
	mov	dptr,#__str_17
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:407: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P2));
	mov	dpl,#0x13
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:408: epl_uart_putstr("\r\n   RX_PW_P3 = ");
	mov	dptr,#__str_18
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:409: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P3));
	mov	dpl,#0x14
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:410: epl_uart_putstr("\r\n   RX_PW_P4 = ");
	mov	dptr,#__str_19
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:411: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P4));
	mov	dpl,#0x15
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:412: epl_uart_putstr("\r\n   RX_PW_P5 = ");
	mov	dptr,#__str_20
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:413: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P5));
	mov	dpl,#0x16
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:414: epl_uart_putstr("\r\n6. RF_SETUP = ");
	mov	dptr,#__str_21
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:415: epl_uart_puthex(hal_nrf_read_reg(RF_SETUP));
	mov	dpl,#0x06
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:416: epl_uart_putstr("\r\n7. STATUS = ");
	mov	dptr,#__str_22
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:417: epl_uart_puthex(hal_nrf_read_reg(STATUS));
	mov	dpl,#0x07
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:418: epl_uart_putstr("\r\n8 .DYNPD = ");
	mov	dptr,#__str_23
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:419: epl_uart_puthex(hal_nrf_read_reg(DYNPD));
	mov	dpl,#0x1C
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:420: epl_uart_putstr("\r\n9. FEATURE = ");
	mov	dptr,#__str_24
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:421: epl_uart_puthex(hal_nrf_read_reg(FEATURE));
	mov	dpl,#0x1D
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:424: }// end switch case
00190$:
;	../main.c:425: mdelay(1);
	mov	dptr,#0x0001
	lcall	_mdelay
	ljmp	00192$
;------------------------------------------------------------
;Allocation info for local variables in function 'array_cp'
;------------------------------------------------------------
;src_array                 Allocated with name '_array_cp_PARM_2'
;len                       Allocated with name '_array_cp_PARM_3'
;dst_array                 Allocated with name '_array_cp_dst_array_1_1'
;i                         Allocated with name '_array_cp_i_1_1'
;sloc0                     Allocated with name '_array_cp_sloc0_1_0'
;sloc1                     Allocated with name '_array_cp_sloc1_1_0'
;sloc2                     Allocated with name '_array_cp_sloc2_1_0'
;------------------------------------------------------------
;	../main.c:431: void array_cp(unsigned char *dst_array, unsigned char *src_array, int len) {
;	-----------------------------------------
;	 function array_cp
;	-----------------------------------------
_array_cp:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_array_cp_dst_array_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../main.c:434: for (i = 0; i < len; i++)
	mov	dptr,#_array_cp_dst_array_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_array_cp_PARM_2
	movx	a,@dptr
	mov	_array_cp_sloc1_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_array_cp_sloc1_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_array_cp_sloc1_1_0 + 2),a
	mov	dptr,#_array_cp_PARM_3
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	clr	a
	mov	_array_cp_sloc0_1_0,a
	mov	(_array_cp_sloc0_1_0 + 1),a
00101$:
	clr	c
	mov	a,_array_cp_sloc0_1_0
	subb	a,r0
	mov	a,(_array_cp_sloc0_1_0 + 1)
	xrl	a,#0x80
	mov	b,r1
	xrl	b,#0x80
	subb	a,b
	jnc	00105$
;	../main.c:435: dst_array[i] = src_array[i];
	push	ar0
	push	ar1
	mov	a,_array_cp_sloc0_1_0
	add	a,r2
	mov	_array_cp_sloc2_1_0,a
	mov	a,(_array_cp_sloc0_1_0 + 1)
	addc	a,r3
	mov	(_array_cp_sloc2_1_0 + 1),a
	mov	(_array_cp_sloc2_1_0 + 2),r4
	mov	a,_array_cp_sloc0_1_0
	add	a,_array_cp_sloc1_1_0
	mov	r6,a
	mov	a,(_array_cp_sloc0_1_0 + 1)
	addc	a,(_array_cp_sloc1_1_0 + 1)
	mov	r7,a
	mov	r5,(_array_cp_sloc1_1_0 + 2)
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	mov	dpl,_array_cp_sloc2_1_0
	mov	dph,(_array_cp_sloc2_1_0 + 1)
	mov	b,(_array_cp_sloc2_1_0 + 2)
	lcall	__gptrput
;	../main.c:434: for (i = 0; i < len; i++)
	inc	_array_cp_sloc0_1_0
	clr	a
	cjne	a,_array_cp_sloc0_1_0,00111$
	inc	(_array_cp_sloc0_1_0 + 1)
00111$:
	pop	ar1
	pop	ar0
	sjmp	00101$
00105$:
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
__str_1:
	.ascii "start!"
	.db 0x00
__str_2:
	.ascii "EPL_OUTPUT_POWER"
	.db 0x0A
	.db 0x00
__str_3:
	.ascii "EPL_OUTPUT_POWER     END"
	.db 0x0A
	.db 0x00
__str_4:
	.db 0x0D
	.db 0x0A
	.ascii "0. CONFIG = "
	.db 0x00
__str_5:
	.db 0x0D
	.db 0x0A
	.ascii "1. RF_CH = "
	.db 0x00
__str_6:
	.db 0x0D
	.db 0x0A
	.ascii "2. EN_AA = "
	.db 0x00
__str_7:
	.db 0x0D
	.db 0x0A
	.ascii "3. EN_RXADDR = "
	.db 0x00
__str_8:
	.db 0x0D
	.db 0x0A
	.ascii "4. TX_ADDR = "
	.db 0x00
__str_9:
	.db 0x0D
	.db 0x0A
	.ascii "4. RX_ADDR_PO = "
	.db 0x00
__str_10:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_ADDR_P1 = "
	.db 0x00
__str_11:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_ADDR_P2 = "
	.db 0x00
__str_12:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_ADDR_P3 = "
	.db 0x00
__str_13:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_ADDR_P4 = "
	.db 0x00
__str_14:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_ADDR_P5 = "
	.db 0x00
__str_15:
	.db 0x0D
	.db 0x0A
	.ascii "5. RX_PW_P0 = "
	.db 0x00
__str_16:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_PW_P1 = "
	.db 0x00
__str_17:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_PW_P2 = "
	.db 0x00
__str_18:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_PW_P3 = "
	.db 0x00
__str_19:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_PW_P4 = "
	.db 0x00
__str_20:
	.db 0x0D
	.db 0x0A
	.ascii "   RX_PW_P5 = "
	.db 0x00
__str_21:
	.db 0x0D
	.db 0x0A
	.ascii "6. RF_SETUP = "
	.db 0x00
__str_22:
	.db 0x0D
	.db 0x0A
	.ascii "7. STATUS = "
	.db 0x00
__str_23:
	.db 0x0D
	.db 0x0A
	.ascii "8 .DYNPD = "
	.db 0x00
__str_24:
	.db 0x0D
	.db 0x0A
	.ascii "9. FEATURE = "
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
