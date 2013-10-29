;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Fri Nov 19 19:41:12 2010
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
_main_sloc0_1_0:
	.ds 2
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
_main_data_length_1_1:
	.ds 2
_main_customized_plen_1_1:
	.ds 2
_main_pipe_source_1_1:
	.ds 6
_main_ACKbuf_1_1:
	.ds 4
_main_temp_buf_1_1:
	.ds 34
_main_temp_addr_1_1:
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
;	../main.c:40: idata struct epl_lu1_rf_en_config rf_cfg_data =
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
;sloc0                     Allocated with name '_main_sloc0_1_0'
;i                         Allocated with name '_main_i_1_1'
;total_pkt_count           Allocated with name '_main_total_pkt_count_1_1'
;addr_width                Allocated with name '_main_addr_width_1_1'
;data_length               Allocated with name '_main_data_length_1_1'
;customized_plen           Allocated with name '_main_customized_plen_1_1'
;pipe_source               Allocated with name '_main_pipe_source_1_1'
;ACKbuf                    Allocated with name '_main_ACKbuf_1_1'
;temp_buf                  Allocated with name '_main_temp_buf_1_1'
;temp_addr                 Allocated with name '_main_temp_addr_1_1'
;------------------------------------------------------------
;	../main.c:60: void main(void) {
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
;	../main.c:62: int total_pkt_count = 1;
	mov	dptr,#_main_total_pkt_count_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:64: int	addr_width = 5, data_length = 32;
	mov	dptr,#_main_addr_width_1_1
	mov	a,#0x05
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_main_data_length_1_1
	mov	a,#0x20
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:66: int customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:71: unsigned char ACKbuf[] = "ACK";
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
	clr	a
	movx	@dptr,a
;	../main.c:77: P0EXP = 0x00;
	mov	_P0EXP,#0x00
;	../main.c:78: P0ALT = 0x00;
	mov	_P0ALT,#0x00
;	../main.c:79: P0DIR = 0x00;
	mov	_P0DIR,#0x00
;	../main.c:82: epl_uart_init(UART_BAUD_57K6);
	mov	dpl,#0x03
	lcall	_epl_uart_init
;	../main.c:84: usb_init(); // Initialize USB
	lcall	_usb_init
;	../main.c:85: EA=1; // Enable global IRQ
	setb	_EA
;	../main.c:88: P04 = 0;
	clr	_P04
;	../main.c:89: P05 = 0;
	clr	_P05
;	../main.c:91: for(i=0;i<3;i++)
	mov	r2,#0x00
	mov	r3,#0x00
00150$:
	clr	c
	mov	a,r2
	subb	a,#0x03
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00153$
;	../main.c:92: LED_Blink(200);
	xrl	_P0,#0x30
	mov	dptr,#0x00C8
	push	ar2
	push	ar3
	lcall	_mdelay
	xrl	_P0,#0x30
	mov	dptr,#0x00C8
	lcall	_mdelay
	pop	ar3
	pop	ar2
;	../main.c:91: for(i=0;i<3;i++)
	inc	r2
	cjne	r2,#0x00,00150$
	inc	r3
	sjmp	00150$
00153$:
;	../main.c:94: P04 = 0;
	clr	_P04
;	../main.c:95: P05 = 1;
	setb	_P05
;	../main.c:99: epl_rf_en_quick_init(cfg);
	mov	r0,#_cfg
	mov	ar2,@r0
	mov	r3,#0x00
	mov	r4,#0x40
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_epl_rf_en_quick_init
;	../main.c:102: hal_nrf_write_reg(FLUSH_TX, 0);
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	clr	a
	movx	@dptr,a
	mov	dpl,#0xE1
	lcall	_hal_nrf_write_reg
;	../main.c:103: hal_nrf_write_reg(FLUSH_RX, 0);
	mov	dptr,#_hal_nrf_write_reg_PARM_2
	clr	a
	movx	@dptr,a
	mov	dpl,#0xE2
	lcall	_hal_nrf_write_reg
;	../main.c:106: while (1) {
00148$:
;	../main.c:108: usb_recv_packet();
	lcall	_usb_recv_packet
;	../main.c:110: packet[0] = 0x00;
	mov	dptr,#_packet
	clr	a
	movx	@dptr,a
;	../main.c:111: packet[1] = ubuf[1];
	mov	dptr,#(_ubuf + 0x0001)
	movx	a,@dptr
	mov	dptr,#(_packet + 0x0001)
	movx	@dptr,a
;	../main.c:112: packet[2] = ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#(_packet + 0x0002)
	movx	@dptr,a
;	../main.c:113: packet[3] = ubuf[3];
	mov	dptr,#(_ubuf + 0x0003)
	movx	a,@dptr
	mov	dptr,#(_packet + 0x0003)
	movx	@dptr,a
;	../main.c:115: epl_rf_en_send(packet, data_length);
	mov	dptr,#_main_data_length_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	ar4,r2
	mov	dptr,#_epl_rf_en_send_PARM_2
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_packet
	mov	b,#0x00
	push	ar2
	push	ar3
	push	ar4
	lcall	_epl_rf_en_send
	pop	ar4
	pop	ar3
	pop	ar2
;	../main.c:118: switch(ubuf[1])
	mov	dptr,#(_ubuf + 0x0001)
	movx	a,@dptr
	mov	r5,a
	cjne	r5,#0x01,00211$
	ljmp	00105$
00211$:
	cjne	r5,#0x02,00212$
	ljmp	00106$
00212$:
	cjne	r5,#0x03,00213$
	ljmp	00107$
00213$:
	cjne	r5,#0x04,00214$
	ljmp	00108$
00214$:
	cjne	r5,#0x05,00215$
	ljmp	00111$
00215$:
	cjne	r5,#0x10,00216$
	ljmp	00195$
00216$:
	cjne	r5,#0x30,00217$
	ljmp	00109$
00217$:
	cjne	r5,#0x40,00218$
	ljmp	00110$
00218$:
	cjne	r5,#0xF2,00219$
	ljmp	00144$
00219$:
	cjne	r5,#0xF3,00220$
	sjmp	00104$
00220$:
	cjne	r5,#0xF6,00221$
	ljmp	00126$
00221$:
	cjne	r5,#0xF7,00222$
	ljmp	00133$
00222$:
	cjne	r5,#0xF8,00223$
	ljmp	00125$
00223$:
	cjne	r5,#0xF9,00224$
	ljmp	00121$
00224$:
	ljmp	00148$
;	../main.c:120: case EPL_SENDER_MODE:
00104$:
;	../main.c:121: customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:122: for(i=0;i<PLOAD_LEN;i++)
	mov	r5,#0x00
	mov	r6,#0x00
00154$:
	clr	c
	mov	a,r5
	subb	a,#0x20
	mov	a,r6
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00157$
;	../main.c:123: packet[i]=i+9;
	mov	a,r5
	add	a,#_packet
	mov	dpl,a
	mov	a,r6
	addc	a,#(_packet >> 8)
	mov	dph,a
	mov	ar7,r5
	mov	a,#0x09
	add	a,r7
	mov	r7,a
	movx	@dptr,a
;	../main.c:122: for(i=0;i<PLOAD_LEN;i++)
	inc	r5
	cjne	r5,#0x00,00154$
	inc	r6
	sjmp	00154$
00157$:
;	../main.c:125: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:126: break;
	ljmp	00148$
;	../main.c:129: case EPL_OUTPUT_POWER:
00105$:
;	../main.c:130: hal_nrf_set_output_power(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_output_power
;	../main.c:133: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:135: break;
	ljmp	00148$
;	../main.c:137: case EPL_CHANNEL:
00106$:
;	../main.c:138: hal_nrf_set_rf_channel(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_rf_channel
;	../main.c:141: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:143: break;
	ljmp	00148$
;	../main.c:145: case EPL_DATARATE:
00107$:
;	../main.c:146: hal_nrf_set_datarate(ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_datarate
;	../main.c:148: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:149: break;
	ljmp	00148$
;	../main.c:151: case EPL_ADDR_WIDTH:
00108$:
;	../main.c:152: addr_width = (int)ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_main_addr_width_1_1
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
;	../main.c:153: hal_nrf_set_address_width(ubuf[2]);
	mov	dpl,r5
	lcall	_hal_nrf_set_address_width
;	../main.c:155: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:156: break;
	ljmp	00148$
;	../main.c:158: case EPL_AUTOACK_P0:
00109$:
;	../main.c:159: hal_nrf_open_pipe(HAL_NRF_PIPE0, ubuf[2]);
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	dptr,#_hal_nrf_open_pipe_PARM_2
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_hal_nrf_open_pipe
;	../main.c:161: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:162: break;
	ljmp	00148$
;	../main.c:164: case EPL_DATA_LENGTH_P0:
00110$:
;	../main.c:165: data_length = (int)ubuf[2];
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_main_data_length_1_1
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
;	../main.c:166: hal_nrf_set_rx_pload_width(HAL_NRF_PIPE0, ubuf[2]);
	mov	dptr,#_hal_nrf_set_rx_pload_width_PARM_2
	mov	a,r5
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_hal_nrf_set_rx_pload_width
;	../main.c:168: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:169: break;
	ljmp	00148$
;	../main.c:171: case EPL_CRC_MODE:
00111$:
;	../main.c:172: if(ubuf[2] == 0)
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r5,a
;	../main.c:173: hal_nrf_set_crc_mode(HAL_NRF_CRC_OFF);
	jnz	00118$
	mov	dpl,a
	lcall	_hal_nrf_set_crc_mode
	sjmp	00119$
00118$:
;	../main.c:174: else if(ubuf[2] == 2)
	cjne	r5,#0x02,00115$
;	../main.c:175: hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT);
	mov	dpl,#0x02
	lcall	_hal_nrf_set_crc_mode
	sjmp	00119$
00115$:
;	../main.c:176: else if(ubuf[2] == 3)
	cjne	r5,#0x03,00119$
;	../main.c:177: hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);
	mov	dpl,#0x03
	lcall	_hal_nrf_set_crc_mode
00119$:
;	../main.c:181: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:182: break;
	ljmp	00148$
;	../main.c:185: for (i=0;i<addr_width;i++)
00195$:
	mov	dptr,#_main_addr_width_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	clr	a
	mov	_main_sloc0_1_0,a
	mov	(_main_sloc0_1_0 + 1),a
00158$:
	clr	c
	mov	a,_main_sloc0_1_0
	subb	a,r5
	mov	a,(_main_sloc0_1_0 + 1)
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	jnc	00161$
;	../main.c:187: temp_addr[i] = ubuf[i+2];
	push	ar5
	push	ar6
	mov	a,_main_sloc0_1_0
	add	a,#_main_temp_addr_1_1
	mov	r7,a
	mov	a,(_main_sloc0_1_0 + 1)
	addc	a,#(_main_temp_addr_1_1 >> 8)
	mov	r5,a
	mov	r6,_main_sloc0_1_0
	mov	a,#0x02
	add	a,r6
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r6,a
	mov	dpl,r7
	mov	dph,r5
	movx	@dptr,a
;	../main.c:185: for (i=0;i<addr_width;i++)
	inc	_main_sloc0_1_0
	clr	a
	cjne	a,_main_sloc0_1_0,00232$
	inc	(_main_sloc0_1_0 + 1)
00232$:
	pop	ar6
	pop	ar5
	sjmp	00158$
00161$:
;	../main.c:190: hal_nrf_set_address(HAL_NRF_TX, temp_addr);
	mov	dptr,#_hal_nrf_set_address_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x06
	lcall	_hal_nrf_set_address
;	../main.c:191: hal_nrf_set_address(HAL_NRF_PIPE0, temp_addr);
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
;	../main.c:193: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:194: break;
	ljmp	00148$
;	../main.c:196: case EPL_USER_PLOAD:
00121$:
;	../main.c:197: if (ubuf[2] == USRS_PLOAD){
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	jnz	00123$
;	../main.c:198: customized_plen = (int)ubuf[3];
	mov	dptr,#(_ubuf + 0x0003)
	movx	a,@dptr
	mov	r5,a
	mov	r6,#0x00
	mov	dptr,#_main_customized_plen_1_1
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	a,r6
	movx	@dptr,a
;	../main.c:200: for(i=0;i<customized_plen;i++)
	clr	a
	mov	_main_sloc0_1_0,a
	mov	(_main_sloc0_1_0 + 1),a
00162$:
	clr	c
	mov	a,_main_sloc0_1_0
	subb	a,r5
	mov	a,(_main_sloc0_1_0 + 1)
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	jnc	00124$
;	../main.c:202: packet[i] = ubuf[i+4];
	push	ar5
	push	ar6
	mov	a,_main_sloc0_1_0
	add	a,#_packet
	mov	r7,a
	mov	a,(_main_sloc0_1_0 + 1)
	addc	a,#(_packet >> 8)
	mov	r5,a
	mov	r6,_main_sloc0_1_0
	mov	a,#0x04
	add	a,r6
	add	a,#_ubuf
	mov	dpl,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r6,a
	mov	dpl,r7
	mov	dph,r5
	movx	@dptr,a
;	../main.c:200: for(i=0;i<customized_plen;i++)
	inc	_main_sloc0_1_0
	clr	a
	cjne	a,_main_sloc0_1_0,00235$
	inc	(_main_sloc0_1_0 + 1)
00235$:
	pop	ar6
	pop	ar5
	sjmp	00162$
00123$:
;	../main.c:206: customized_plen = 0;
	mov	dptr,#_main_customized_plen_1_1
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	../main.c:208: for(i=0;i<PLOAD_LEN;i++)
	mov	r5,#0x00
	mov	r6,#0x00
00166$:
	clr	c
	mov	a,r5
	subb	a,#0x20
	mov	a,r6
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00124$
;	../main.c:210: packet[i]=i+9;
	mov	a,r5
	add	a,#_packet
	mov	dpl,a
	mov	a,r6
	addc	a,#(_packet >> 8)
	mov	dph,a
	mov	ar7,r5
	mov	a,#0x09
	add	a,r7
	mov	r7,a
	movx	@dptr,a
;	../main.c:208: for(i=0;i<PLOAD_LEN;i++)
	inc	r5
	cjne	r5,#0x00,00166$
	inc	r6
	sjmp	00166$
00124$:
;	../main.c:214: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:215: break;
	ljmp	00148$
;	../main.c:218: case EPL_NEW_COUNTER:
00125$:
;	../main.c:219: total_pkt_count = 1;
	mov	dptr,#_main_total_pkt_count_1_1
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
;	../main.c:220: usb_send_packet(ACKbuf, 3);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_main_ACKbuf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:221: break;
	ljmp	00148$
;	../main.c:223: case EPL_RUN_SENDER:
00126$:
;	../main.c:225: epl_rf_en_enter_tx_mode();
	push	ar2
	push	ar3
	push	ar4
	lcall	_epl_rf_en_enter_tx_mode
;	../main.c:228: hal_nrf_clear_irq_flag(HAL_NRF_TX_DS);
	mov	dpl,#0x05
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:229: hal_nrf_clear_irq_flag(HAL_NRF_MAX_RT);
	mov	dpl,#0x04
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:231: epl_uart_putstr("cus plen =");
	mov	dptr,#__str_1
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:232: epl_uart_putint(customized_plen);
	mov	dptr,#_main_customized_plen_1_1
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	push	ar5
	push	ar6
	lcall	_epl_uart_putint
;	../main.c:233: epl_uart_putstr("data len =");
	mov	dptr,#__str_2
	mov	b,#0x80
	lcall	_epl_uart_putstr
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	../main.c:234: epl_uart_putint(data_length);
	mov	dpl,r2
	mov	dph,r3
	push	ar4
	push	ar5
	push	ar6
	lcall	_epl_uart_putint
	pop	ar6
	pop	ar5
	pop	ar4
;	../main.c:236: if (ubuf[2] == AUTO_PLOAD){
	mov	dptr,#(_ubuf + 0x0002)
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0x01,00128$
;	../main.c:237: epl_uart_putstr("auto pload\r\n");
	mov	dptr,#__str_3
	mov	b,#0x80
	push	ar4
	lcall	_epl_uart_putstr
	pop	ar4
;	../main.c:238: packet[0] = total_pkt_count++;
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
;	../main.c:239: epl_rf_en_send(packet, data_length);
	mov	dptr,#_epl_rf_en_send_PARM_2
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_packet
	mov	b,#0x00
	lcall	_epl_rf_en_send
	sjmp	00130$
00128$:
;	../main.c:242: epl_uart_putstr("usrs pload\r\n");
	mov	dptr,#__str_4
	mov	b,#0x80
	push	ar5
	push	ar6
	lcall	_epl_uart_putstr
	pop	ar6
	pop	ar5
;	../main.c:243: epl_rf_en_send(packet, customized_plen);
	mov	dptr,#_epl_rf_en_send_PARM_2
	mov	a,r5
	movx	@dptr,a
	mov	dptr,#_packet
	mov	b,#0x00
	lcall	_epl_rf_en_send
;	../main.c:245: LED_Toggle();
00130$:
	xrl	_P0,#0x30
;	../main.c:246: mdelay(20);
	mov	dptr,#0x0014
	lcall	_mdelay
;	../main.c:248: array_cp(temp_buf, ACKbuf, 3);
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
;	../main.c:249: temp_buf[3] = hal_nrf_read_reg(OBSERVE_TX) & 0x0F;
	mov	dpl,#0x08
	lcall	_hal_nrf_read_reg
	mov	a,dpl
	anl	a,#0x0F
	mov	dptr,#(_main_temp_buf_1_1 + 0x0003)
	movx	@dptr,a
;	../main.c:250: usb_send_packet(temp_buf, 4);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x04
	movx	@dptr,a
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:252: epl_rf_en_enter_rx_mode();
	lcall	_epl_rf_en_enter_rx_mode
;	../main.c:254: break;
	ljmp	00148$
;	../main.c:257: case EPL_RUN_DUMPER:
00133$:
;	../main.c:259: hal_nrf_clear_irq_flag(HAL_NRF_RX_DR);
	mov	dpl,#0x06
	lcall	_hal_nrf_clear_irq_flag
;	../main.c:260: hal_nrf_flush_rx();
	lcall	_hal_nrf_flush_rx
;	../main.c:261: epl_rf_en_enter_rx_mode();
	lcall	_epl_rf_en_enter_rx_mode
;	../main.c:263: while (1)
00142$:
;	../main.c:274: if (ubuf[1] == 0xf5)
	mov	dptr,#(_ubuf + 0x0001)
	movx	a,@dptr
	mov	r2,a
	cjne	r2,#0xF5,00239$
	ljmp	00148$
00239$:
;	../main.c:279: if (hal_nrf_rx_fifo_empty()==0)
	lcall	_hal_nrf_rx_fifo_empty
	mov	a,dpl
	jnz	00142$
;	../main.c:281: pipe_source[0] = hal_nrf_get_rx_data_source();
	lcall	_hal_nrf_get_rx_data_source
	mov	r2,dpl
	mov	dptr,#_main_pipe_source_1_1
	mov	a,r2
	movx	@dptr,a
;	../main.c:282: hal_nrf_read_rx_pload(temp_buf);
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_hal_nrf_read_rx_pload
;	../main.c:285: temp_buf[32] = pipe_source[0];
	mov	dptr,#_main_pipe_source_1_1
	movx	a,@dptr
	mov	dptr,#(_main_temp_buf_1_1 + 0x0020)
	movx	@dptr,a
;	../main.c:286: usb_send_packet(temp_buf, 33);
	mov	dptr,#_usb_send_packet_PARM_2
	mov	a,#0x21
	movx	@dptr,a
	mov	dptr,#_main_temp_buf_1_1
	mov	b,#0x00
	lcall	_usb_send_packet
;	../main.c:288: LED_Toggle();
	xrl	_P0,#0x30
;	../main.c:293: case EPL_SHOW_CONFIG:
	sjmp	00142$
00144$:
;	../main.c:294: epl_uart_putstr("\r\n1. CONFIG = ");
	mov	dptr,#__str_5
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:295: epl_uart_puthex(hal_nrf_read_reg(RF_CH));
	mov	dpl,#0x05
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:296: epl_uart_putstr("\r\n2. EN_AA = ");
	mov	dptr,#__str_6
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:297: epl_uart_puthex(hal_nrf_read_reg(EN_AA));
	mov	dpl,#0x01
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:298: epl_uart_putstr("\r\n3. EN_RXADDR = ");
	mov	dptr,#__str_7
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:299: epl_uart_puthex(hal_nrf_read_reg(EN_RXADDR));
	mov	dpl,#0x02
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:300: epl_uart_putstr("\r\n4. RF_SETUP = ");
	mov	dptr,#__str_8
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:301: epl_uart_puthex(hal_nrf_read_reg(RF_SETUP));
	mov	dpl,#0x06
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:302: epl_uart_putstr("\r\n5. STATUS = ");
	mov	dptr,#__str_9
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:303: epl_uart_puthex(hal_nrf_read_reg(STATUS));
	mov	dpl,#0x07
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:304: epl_uart_putstr("\r\n6. RX_PW_P0 = ");
	mov	dptr,#__str_10
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:305: epl_uart_puthex(hal_nrf_read_reg(RX_PW_P0));
	mov	dpl,#0x11
	lcall	_hal_nrf_read_reg
	mov	r3,#0x00
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:306: epl_uart_putstr("\r\n7. RX_P0 = ");
	mov	dptr,#__str_11
	mov	b,#0x80
	lcall	_epl_uart_putstr
;	../main.c:307: hal_nrf_read_multibyte_reg(0x0A, temp_addr);
	mov	dptr,#_hal_nrf_read_multibyte_reg_PARM_2
	mov	a,#_main_temp_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_main_temp_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
	mov	dpl,#0x0A
	lcall	_hal_nrf_read_multibyte_reg
;	../main.c:308: epl_uart_puthex(temp_addr[0]);
	mov	dptr,#_main_temp_addr_1_1
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:309: epl_uart_puthex(temp_addr[1]);
	mov	dptr,#(_main_temp_addr_1_1 + 0x0001)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:310: epl_uart_puthex(temp_addr[2]);
	mov	dptr,#(_main_temp_addr_1_1 + 0x0002)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:311: epl_uart_puthex(temp_addr[3]);
	mov	dptr,#(_main_temp_addr_1_1 + 0x0003)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:312: epl_uart_puthex(temp_addr[4]);
	mov	dptr,#(_main_temp_addr_1_1 + 0x0004)
	movx	a,@dptr
	mov	r2,a
	mov	r3,#0x00
	mov	dpl,r2
	mov	dph,r3
	lcall	_epl_uart_puthex
;	../main.c:318: }// end switch case
	ljmp	00148$
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
;	../main.c:322: void array_cp(unsigned char *dst_array, unsigned char *src_array, int len)
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
;	../main.c:326: for(i=0;i<len;i++)
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
;	../main.c:327: dst_array[i] = src_array[i];
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
;	../main.c:326: for(i=0;i<len;i++)
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
	.ascii "cus plen ="
	.db 0x00
__str_2:
	.ascii "data len ="
	.db 0x00
__str_3:
	.ascii "auto pload"
	.db 0x0D
	.db 0x0A
	.db 0x00
__str_4:
	.ascii "usrs pload"
	.db 0x0D
	.db 0x0A
	.db 0x00
__str_5:
	.db 0x0D
	.db 0x0A
	.ascii "1. CONFIG = "
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
	.ascii "4. RF_SETUP = "
	.db 0x00
__str_9:
	.db 0x0D
	.db 0x0A
	.ascii "5. STATUS = "
	.db 0x00
__str_10:
	.db 0x0D
	.db 0x0A
	.ascii "6. RX_PW_P0 = "
	.db 0x00
__str_11:
	.db 0x0D
	.db 0x0A
	.ascii "7. RX_P0 = "
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
