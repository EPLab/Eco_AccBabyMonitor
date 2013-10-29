;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Tue Oct 26 13:20:49 2010
;--------------------------------------------------------
	.module epl_rf_en
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
	.globl _epl_rf_en_send_PARM_2
	.globl _epl_rf_en_send_dst_PARM_3
	.globl _epl_rf_en_send_dst_PARM_2
	.globl _epl_rf_en_easy_start_rx_PARM_3
	.globl _epl_rf_en_easy_start_rx_PARM_2
	.globl _epl_rf_en_easy_start_tx_PARM_3
	.globl _epl_rf_en_easy_start_tx_PARM_2
	.globl _epl_rf_en_rcv_pipe_config_PARM_4
	.globl _epl_rf_en_rcv_pipe_config_PARM_3
	.globl _epl_rf_en_rcv_pipe_config_PARM_2
	.globl _epl_rf_en_init_PARM_9
	.globl _epl_rf_en_init_PARM_8
	.globl _epl_rf_en_init_PARM_7
	.globl _epl_rf_en_init_PARM_6
	.globl _epl_rf_en_init_PARM_5
	.globl _epl_rf_en_init_PARM_4
	.globl _epl_rf_en_init_PARM_3
	.globl _epl_rf_en_init_PARM_2
	.globl _epl_rf_en_init
	.globl _epl_rf_en_rcv_pipe_config
	.globl _epl_rf_en_easy_start_tx
	.globl _epl_rf_en_easy_start_rx
	.globl _epl_rf_en_quick_init
	.globl _epl_rf_en_enter_tx_mode
	.globl _epl_rf_en_enter_rx_mode
	.globl _epl_rf_en_set_dst_addr
	.globl _epl_rf_en_send_dst
	.globl _epl_rf_en_send
	.globl _epl_rf_en_rx_pload_is_empty
	.globl _epl_rf_en_read_rx_pload
	.globl _epl_rf_en_wait_rcv_msg
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
_epl_rf_en_quick_init_sloc0_1_0:
	.ds 1
_epl_rf_en_quick_init_sloc1_1_0:
	.ds 1
_epl_rf_en_quick_init_sloc2_1_0:
	.ds 1
_epl_rf_en_quick_init_sloc3_1_0:
	.ds 1
_epl_rf_en_quick_init_sloc4_1_0:
	.ds 3
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
_epl_rf_en_init_PARM_2:
	.ds 1
_epl_rf_en_init_PARM_3:
	.ds 1
_epl_rf_en_init_PARM_4:
	.ds 1
_epl_rf_en_init_PARM_5:
	.ds 2
_epl_rf_en_init_PARM_6:
	.ds 1
_epl_rf_en_init_PARM_7:
	.ds 1
_epl_rf_en_init_PARM_8:
	.ds 1
_epl_rf_en_init_PARM_9:
	.ds 1
_epl_rf_en_init_in_channel_1_1:
	.ds 1
_epl_rf_en_rcv_pipe_config_PARM_2:
	.ds 3
_epl_rf_en_rcv_pipe_config_PARM_3:
	.ds 1
_epl_rf_en_rcv_pipe_config_PARM_4:
	.ds 1
_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1:
	.ds 1
_epl_rf_en_easy_start_tx_PARM_2:
	.ds 1
_epl_rf_en_easy_start_tx_PARM_3:
	.ds 2
_epl_rf_en_easy_start_tx_channel_1_1:
	.ds 1
_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1:
	.ds 5
_epl_rf_en_easy_start_rx_PARM_2:
	.ds 1
_epl_rf_en_easy_start_rx_PARM_3:
	.ds 1
_epl_rf_en_easy_start_rx_channel_1_1:
	.ds 1
_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1:
	.ds 5
_epl_rf_en_quick_init_in_cfg_1_1:
	.ds 3
_epl_rf_en_set_dst_addr_in_dst_addr_1_1:
	.ds 3
_epl_rf_en_send_dst_PARM_2:
	.ds 3
_epl_rf_en_send_dst_PARM_3:
	.ds 1
_epl_rf_en_send_dst_in_dst_addr_1_1:
	.ds 3
_epl_rf_en_send_PARM_2:
	.ds 1
_epl_rf_en_send_in_tx_pload_1_1:
	.ds 3
_epl_rf_en_read_rx_pload_out_rx_pload_1_1:
	.ds 3
_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1:
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
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_init'
;------------------------------------------------------------
;in_datarate               Allocated with name '_epl_rf_en_init_PARM_2'
;in_output_power           Allocated with name '_epl_rf_en_init_PARM_3'
;in_auto_retr              Allocated with name '_epl_rf_en_init_PARM_4'
;in_auto_retr_delay        Allocated with name '_epl_rf_en_init_PARM_5'
;in_addr_width             Allocated with name '_epl_rf_en_init_PARM_6'
;in_crc_mode               Allocated with name '_epl_rf_en_init_PARM_7'
;in_spi_clk_rate           Allocated with name '_epl_rf_en_init_PARM_8'
;in_rf_int                 Allocated with name '_epl_rf_en_init_PARM_9'
;in_channel                Allocated with name '_epl_rf_en_init_in_channel_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:55: void epl_rf_en_init(unsigned char in_channel, 		// Freq = in_channel + 2400 MHz
;	-----------------------------------------
;	 function epl_rf_en_init
;	-----------------------------------------
_epl_rf_en_init:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	mov	a,dpl
	mov	dptr,#_epl_rf_en_init_in_channel_1_1
	movx	@dptr,a
;	../epl_rf_en.c:66: RFCTL = 0x010 + in_spi_clk_rate; // Enable RF SPI and set the clock rate of SPI.
	mov	dptr,#_epl_rf_en_init_PARM_8
	movx	a,@dptr
	mov	r2,a
	mov	a,#0x10
	add	a,r2
	mov	_RFCTL,a
;	../epl_rf_en.c:68: RFCKEN = 1;	// RF clock enable.
	setb	_RFCKEN
;	../epl_rf_en.c:71: hal_nrf_close_pipe(HAL_NRF_ALL); // Close all pipes first. By default, pipe0 and pipe1 are opened.
	mov	dpl,#0xFF
	lcall	_hal_nrf_close_pipe
;	../epl_rf_en.c:73: hal_nrf_set_datarate(in_datarate);
	mov	dptr,#_epl_rf_en_init_PARM_2
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_datarate
;	../epl_rf_en.c:74: hal_nrf_set_auto_retr(in_auto_retr, in_auto_retr_delay); // First parameter is set to zero indicating the auto retransmission is off.
	mov	dptr,#_epl_rf_en_init_PARM_4
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_epl_rf_en_init_PARM_5
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_hal_nrf_set_auto_retr_PARM_2
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dpl,r2
	lcall	_hal_nrf_set_auto_retr
;	../epl_rf_en.c:75: hal_nrf_set_output_power(in_output_power); // Maximum radio output power (0dbm).
	mov	dptr,#_epl_rf_en_init_PARM_3
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_output_power
;	../epl_rf_en.c:76: hal_nrf_set_crc_mode(in_crc_mode);
	mov	dptr,#_epl_rf_en_init_PARM_7
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_crc_mode
;	../epl_rf_en.c:78: hal_nrf_set_address_width(in_addr_width); // Both RX and TX's address width are Configured.
	mov	dptr,#_epl_rf_en_init_PARM_6
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_address_width
;	../epl_rf_en.c:80: hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode
	mov	dpl,#0x00
	lcall	_hal_nrf_set_operation_mode
;	../epl_rf_en.c:82: hal_nrf_set_rf_channel(in_channel);
	mov	dptr,#_epl_rf_en_init_in_channel_1_1
	movx	a,@dptr
	mov	dpl,a
	lcall	_hal_nrf_set_rf_channel
;	../epl_rf_en.c:83: hal_nrf_set_power_mode(HAL_NRF_PWR_UP); // Power up radio
	mov	dpl,#0x01
	lcall	_hal_nrf_set_power_mode
;	../epl_rf_en.c:84: hal_nrf_get_clear_irq_flags();
	lcall	_hal_nrf_get_clear_irq_flags
;	../epl_rf_en.c:86: RFCE = 0;
	clr	_RFCE
;	../epl_rf_en.c:89: RF = in_rf_int;
	mov	dptr,#_epl_rf_en_init_PARM_9
	movx	a,@dptr
	add	a,#0xff
	mov	_RF,c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_rcv_pipe_config'
;------------------------------------------------------------
;in_pipe_rcv_addr          Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_2'
;in_pipe_pload_length      Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_3'
;in_auto_ack               Allocated with name '_epl_rf_en_rcv_pipe_config_PARM_4'
;in_pipe_num               Allocated with name '_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:105: void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, 		// The pipe number
;	-----------------------------------------
;	 function epl_rf_en_rcv_pipe_config
;	-----------------------------------------
_epl_rf_en_rcv_pipe_config:
	mov	a,dpl
	mov	dptr,#_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1
	movx	@dptr,a
;	../epl_rf_en.c:110: hal_nrf_open_pipe(in_pipe_num, in_auto_ack); // Open pipe and configure the auto ack function.
	mov	dptr,#_epl_rf_en_rcv_pipe_config_in_pipe_num_1_1
	movx	a,@dptr
	mov	r2,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	movx	a,@dptr
	mov	dptr,#_hal_nrf_open_pipe_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	push	ar2
	lcall	_hal_nrf_open_pipe
	pop	ar2
;	../epl_rf_en.c:111: hal_nrf_set_address(in_pipe_num, in_pipe_rcv_addr); // Address for PRX pipe
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_hal_nrf_set_address_PARM_2
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	mov	dpl,r2
	push	ar2
	lcall	_hal_nrf_set_address
	pop	ar2
;	../epl_rf_en.c:112: hal_nrf_set_rx_pload_width(in_pipe_num, in_pipe_pload_length);
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	movx	a,@dptr
	mov	dptr,#_hal_nrf_set_rx_pload_width_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	ljmp	_hal_nrf_set_rx_pload_width
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_easy_start_tx'
;------------------------------------------------------------
;auto_retr                 Allocated with name '_epl_rf_en_easy_start_tx_PARM_2'
;delay                     Allocated with name '_epl_rf_en_easy_start_tx_PARM_3'
;channel                   Allocated with name '_epl_rf_en_easy_start_tx_channel_1_1'
;my_tx_dst_addr            Allocated with name '_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:123: void epl_rf_en_easy_start_tx(unsigned char channel, uint8_t auto_retr, uint16_t delay){
;	-----------------------------------------
;	 function epl_rf_en_easy_start_tx
;	-----------------------------------------
_epl_rf_en_easy_start_tx:
	mov	a,dpl
	mov	dptr,#_epl_rf_en_easy_start_tx_channel_1_1
	movx	@dptr,a
;	../epl_rf_en.c:125: char my_tx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
	mov	dptr,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0001)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0002)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0003)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 + 0x0004)
	mov	a,#0x65
	movx	@dptr,a
;	../epl_rf_en.c:128: epl_rf_en_init(channel,
	mov	dptr,#_epl_rf_en_easy_start_tx_channel_1_1
	movx	a,@dptr
	mov	r2,a
;	../epl_rf_en.c:131: auto_retr,
	mov	dptr,#_epl_rf_en_easy_start_tx_PARM_2
	movx	a,@dptr
	mov	r3,a
;	../epl_rf_en.c:132: delay,
	mov	dptr,#_epl_rf_en_easy_start_tx_PARM_3
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
;	../epl_rf_en.c:136: RF_EN_INT_DISABLE);
	mov	dptr,#_epl_rf_en_init_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_3
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_4
	mov	a,r3
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_5
	mov	a,r4
	movx	@dptr,a
	inc	dptr
	mov	a,r5
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_6
	mov	a,#0x05
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_7
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_8
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_9
	clr	a
	movx	@dptr,a
	mov	dpl,r2
	push	ar3
	lcall	_epl_rf_en_init
;	../epl_rf_en.c:138: epl_rf_en_set_dst_addr(my_tx_dst_addr);
	mov	dptr,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
	mov	b,#0x00
	lcall	_epl_rf_en_set_dst_addr
	pop	ar3
;	../epl_rf_en.c:140: if( auto_retr != 0){
	mov	a,r3
	jz	00102$
;	../epl_rf_en.c:144: my_tx_dst_addr,
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_epl_rf_en_easy_start_tx_my_tx_dst_addr_1_1 >> 8)
	movx	@dptr,a
	inc	dptr
	clr	a
	movx	@dptr,a
;	../epl_rf_en.c:146: RF_EN_AUTO_ACK_ON
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,#0x20
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,#0x01
	movx	@dptr,a
	mov	dpl,#0x00
	lcall	_epl_rf_en_rcv_pipe_config
00102$:
;	../epl_rf_en.c:150: epl_rf_en_enter_tx_mode();
	ljmp	_epl_rf_en_enter_tx_mode
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_easy_start_rx'
;------------------------------------------------------------
;pload_len                 Allocated with name '_epl_rf_en_easy_start_rx_PARM_2'
;auto_ack                  Allocated with name '_epl_rf_en_easy_start_rx_PARM_3'
;channel                   Allocated with name '_epl_rf_en_easy_start_rx_channel_1_1'
;my_rx_dst_addr            Allocated with name '_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:161: void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, bool auto_ack){
;	-----------------------------------------
;	 function epl_rf_en_easy_start_rx
;	-----------------------------------------
_epl_rf_en_easy_start_rx:
	mov	a,dpl
	mov	dptr,#_epl_rf_en_easy_start_rx_channel_1_1
	movx	@dptr,a
;	../epl_rf_en.c:163: char my_rx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
	mov	dptr,#_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0001)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0002)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0003)
	mov	a,#0x65
	movx	@dptr,a
	mov	dptr,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 + 0x0004)
	mov	a,#0x65
	movx	@dptr,a
;	../epl_rf_en.c:166: epl_rf_en_init(channel,
	mov	dptr,#_epl_rf_en_easy_start_rx_channel_1_1
	movx	a,@dptr
	mov	r2,a
;	../epl_rf_en.c:174: RF_EN_INT_DISABLE);
	mov	dptr,#_epl_rf_en_init_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_3
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_4
	clr	a
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_5
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_6
	mov	a,#0x05
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_7
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_8
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_9
	clr	a
	movx	@dptr,a
	mov	dpl,r2
	lcall	_epl_rf_en_init
;	../epl_rf_en.c:178: my_rx_dst_addr,
;	../epl_rf_en.c:179: pload_len,
	mov	dptr,#_epl_rf_en_easy_start_rx_PARM_2
	movx	a,@dptr
	mov	r2,a
;	../epl_rf_en.c:180: auto_ack
	mov	dptr,#_epl_rf_en_easy_start_rx_PARM_3
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,#_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,#(_epl_rf_en_easy_start_rx_my_rx_dst_addr_1_1 >> 8)
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
;	../epl_rf_en.c:183: epl_rf_en_enter_rx_mode();
	ljmp	_epl_rf_en_enter_rx_mode
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_quick_init'
;------------------------------------------------------------
;sloc0                     Allocated with name '_epl_rf_en_quick_init_sloc0_1_0'
;sloc1                     Allocated with name '_epl_rf_en_quick_init_sloc1_1_0'
;sloc2                     Allocated with name '_epl_rf_en_quick_init_sloc2_1_0'
;sloc3                     Allocated with name '_epl_rf_en_quick_init_sloc3_1_0'
;sloc4                     Allocated with name '_epl_rf_en_quick_init_sloc4_1_0'
;in_cfg                    Allocated with name '_epl_rf_en_quick_init_in_cfg_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:193: void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg)
;	-----------------------------------------
;	 function epl_rf_en_quick_init
;	-----------------------------------------
_epl_rf_en_quick_init:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_quick_init_in_cfg_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:197: epl_rf_en_init(in_cfg->channel,
	mov	dptr,#_epl_rf_en_quick_init_in_cfg_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	_epl_rf_en_quick_init_sloc2_1_0,a
;	../epl_rf_en.c:198: in_cfg->datarate,
	mov	a,#0x0D
	add	a,r2
	mov	r6,a
	clr	a
	addc	a,r3
	mov	r7,a
	mov	ar0,r4
	mov	dpl,r6
	mov	dph,r7
	mov	b,r0
	lcall	__gptrget
	mov	_epl_rf_en_quick_init_sloc1_1_0,a
;	../epl_rf_en.c:200: in_cfg->auto_retr,
	mov	a,#0x10
	add	a,r2
	mov	r7,a
	clr	a
	addc	a,r3
	mov	r0,a
	mov	ar1,r4
	mov	dpl,r7
	mov	dph,r0
	mov	b,r1
	lcall	__gptrget
	mov	_epl_rf_en_quick_init_sloc0_1_0,a
;	../epl_rf_en.c:201: in_cfg->auto_retr_delay,
	mov	a,#0x11
	add	a,r2
	mov	r0,a
	clr	a
	addc	a,r3
	mov	r1,a
	mov	ar7,r4
	mov	dpl,r0
	mov	dph,r1
	mov	b,r7
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
;	../epl_rf_en.c:202: in_cfg->addr_width,
	mov	a,#0x01
	add	a,r2
	mov	r7,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar5,r4
	mov	dpl,r7
	mov	dph,r6
	mov	b,r5
	lcall	__gptrget
	mov	_epl_rf_en_quick_init_sloc3_1_0,a
;	../epl_rf_en.c:203: in_cfg->crc_mode,
	mov	a,#0x0E
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
;	../epl_rf_en.c:205: RF_EN_INT_DISABLE);
	mov	dptr,#_epl_rf_en_init_PARM_2
	mov	a,_epl_rf_en_quick_init_sloc1_1_0
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_3
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_4
	mov	a,_epl_rf_en_quick_init_sloc0_1_0
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_5
	mov	a,r0
	movx	@dptr,a
	inc	dptr
	mov	a,r1
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_6
	mov	a,_epl_rf_en_quick_init_sloc3_1_0
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_7
	mov	a,r5
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_8
	mov	a,#0x03
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_init_PARM_9
	clr	a
	movx	@dptr,a
	mov	dpl,_epl_rf_en_quick_init_sloc2_1_0
	push	ar2
	push	ar3
	push	ar4
	lcall	_epl_rf_en_init
	pop	ar4
	pop	ar3
	pop	ar2
;	../epl_rf_en.c:207: epl_rf_en_set_dst_addr(in_cfg->my_tx_dst_addr);
	mov	a,#0x02
	add	a,r2
	mov	r5,a
	clr	a
	addc	a,r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar2
	push	ar3
	push	ar4
	lcall	_epl_rf_en_set_dst_addr
	pop	ar4
	pop	ar3
	pop	ar2
;	../epl_rf_en.c:212: in_cfg->my_prx_addr,
	mov	a,#0x07
	add	a,r2
	mov	_epl_rf_en_quick_init_sloc4_1_0,a
	clr	a
	addc	a,r3
	mov	(_epl_rf_en_quick_init_sloc4_1_0 + 1),a
	mov	(_epl_rf_en_quick_init_sloc4_1_0 + 2),r4
;	../epl_rf_en.c:213: in_cfg->data_length,
	mov	a,#0x0C
	add	a,r2
	mov	r0,a
	clr	a
	addc	a,r3
	mov	r1,a
	mov	ar5,r4
	mov	dpl,r0
	mov	dph,r1
	mov	b,r5
	lcall	__gptrget
	mov	r0,a
;	../epl_rf_en.c:214: in_cfg->auto_ack
	mov	a,#0x0F
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_2
	mov	a,_epl_rf_en_quick_init_sloc4_1_0
	movx	@dptr,a
	inc	dptr
	mov	a,(_epl_rf_en_quick_init_sloc4_1_0 + 1)
	movx	@dptr,a
	inc	dptr
	mov	a,(_epl_rf_en_quick_init_sloc4_1_0 + 2)
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_3
	mov	a,r0
	movx	@dptr,a
	mov	dptr,#_epl_rf_en_rcv_pipe_config_PARM_4
	mov	a,r2
	movx	@dptr,a
	mov	dpl,#0x00
	ljmp	_epl_rf_en_rcv_pipe_config
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_enter_tx_mode'
;------------------------------------------------------------
;------------------------------------------------------------
;	../epl_rf_en.c:221: void epl_rf_en_enter_tx_mode(void)
;	-----------------------------------------
;	 function epl_rf_en_enter_tx_mode
;	-----------------------------------------
_epl_rf_en_enter_tx_mode:
;	../epl_rf_en.c:223: RFCE = 0;
	clr	_RFCE
;	../epl_rf_en.c:224: hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode
	mov	dpl,#0x00
	ljmp	_hal_nrf_set_operation_mode
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_enter_rx_mode'
;------------------------------------------------------------
;------------------------------------------------------------
;	../epl_rf_en.c:230: void epl_rf_en_enter_rx_mode(void)
;	-----------------------------------------
;	 function epl_rf_en_enter_rx_mode
;	-----------------------------------------
_epl_rf_en_enter_rx_mode:
;	../epl_rf_en.c:232: RFCE = 1;
	setb	_RFCE
;	../epl_rf_en.c:233: hal_nrf_set_operation_mode(HAL_NRF_PRX); // Enter RF RX mode
	mov	dpl,#0x01
	ljmp	_hal_nrf_set_operation_mode
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_set_dst_addr'
;------------------------------------------------------------
;in_dst_addr               Allocated with name '_epl_rf_en_set_dst_addr_in_dst_addr_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:241: void epl_rf_en_set_dst_addr(uint8_t *in_dst_addr)
;	-----------------------------------------
;	 function epl_rf_en_set_dst_addr
;	-----------------------------------------
_epl_rf_en_set_dst_addr:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_set_dst_addr_in_dst_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:243: hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
	mov	dptr,#_epl_rf_en_set_dst_addr_in_dst_addr_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_hal_nrf_set_address_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dpl,#0x06
	ljmp	_hal_nrf_set_address
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_send_dst'
;------------------------------------------------------------
;in_tx_pload               Allocated with name '_epl_rf_en_send_dst_PARM_2'
;in_pload_length           Allocated with name '_epl_rf_en_send_dst_PARM_3'
;in_dst_addr               Allocated with name '_epl_rf_en_send_dst_in_dst_addr_1_1'
;count                     Allocated with name '_epl_rf_en_send_dst_count_2_2'
;------------------------------------------------------------
;	../epl_rf_en.c:253: void epl_rf_en_send_dst(uint8_t *in_dst_addr, uint8_t *in_tx_pload, uint8_t in_pload_length)
;	-----------------------------------------
;	 function epl_rf_en_send_dst
;	-----------------------------------------
_epl_rf_en_send_dst:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_send_dst_in_dst_addr_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:255: hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
	mov	dptr,#_epl_rf_en_send_dst_in_dst_addr_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_hal_nrf_set_address_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dpl,#0x06
	lcall	_hal_nrf_set_address
;	../epl_rf_en.c:256: epl_rf_en_enter_tx_mode();
	lcall	_epl_rf_en_enter_tx_mode
;	../epl_rf_en.c:257: hal_nrf_write_tx_pload(in_tx_pload, in_pload_length);
	mov	dptr,#_epl_rf_en_send_dst_PARM_2
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_epl_rf_en_send_dst_PARM_3
	movx	a,@dptr
	mov	dptr,#_hal_nrf_write_tx_pload_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_hal_nrf_write_tx_pload
;	../epl_rf_en.c:258: CE_PULSE();
	setb	_RFCE
	mov	r2,#0x14
00104$:
	mov	ar3,r2
	dec	r2
	mov	a,r3
	jnz	00104$
	clr	_RFCE
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_send'
;------------------------------------------------------------
;in_pload_length           Allocated with name '_epl_rf_en_send_PARM_2'
;in_tx_pload               Allocated with name '_epl_rf_en_send_in_tx_pload_1_1'
;count                     Allocated with name '_epl_rf_en_send_count_2_2'
;------------------------------------------------------------
;	../epl_rf_en.c:268: void epl_rf_en_send(uint8_t *in_tx_pload, uint8_t in_pload_length)
;	-----------------------------------------
;	 function epl_rf_en_send
;	-----------------------------------------
_epl_rf_en_send:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_send_in_tx_pload_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:270: epl_rf_en_enter_tx_mode();
	lcall	_epl_rf_en_enter_tx_mode
;	../epl_rf_en.c:271: hal_nrf_write_tx_pload(in_tx_pload, in_pload_length);
	mov	dptr,#_epl_rf_en_send_in_tx_pload_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_epl_rf_en_send_PARM_2
	movx	a,@dptr
	mov	dptr,#_hal_nrf_write_tx_pload_PARM_2
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_hal_nrf_write_tx_pload
;	../epl_rf_en.c:272: CE_PULSE();
	setb	_RFCE
	mov	r2,#0x14
00104$:
	mov	ar3,r2
	dec	r2
	mov	a,r3
	jnz	00104$
	clr	_RFCE
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_rx_pload_is_empty'
;------------------------------------------------------------
;rx_fifo_status            Allocated with name '_epl_rf_en_rx_pload_is_empty_rx_fifo_status_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:281: bool epl_rf_en_rx_pload_is_empty(void)
;	-----------------------------------------
;	 function epl_rf_en_rx_pload_is_empty
;	-----------------------------------------
_epl_rf_en_rx_pload_is_empty:
;	../epl_rf_en.c:284: rx_fifo_status = hal_nrf_get_rx_fifo_status();
	lcall	_hal_nrf_get_rx_fifo_status
	mov	r2,dpl
;	../epl_rf_en.c:285: if (rx_fifo_status == 0x01)
	cjne	r2,#0x01,00102$
;	../epl_rf_en.c:287: return 1;	// RX fifo is empty.
	mov	dpl,#0x01
;	../epl_rf_en.c:291: return 0;	// RX fifo is not empty or is full.
	ret
00102$:
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_read_rx_pload'
;------------------------------------------------------------
;out_rx_pload              Allocated with name '_epl_rf_en_read_rx_pload_out_rx_pload_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:300: void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload)
;	-----------------------------------------
;	 function epl_rf_en_read_rx_pload
;	-----------------------------------------
_epl_rf_en_read_rx_pload:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_read_rx_pload_out_rx_pload_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:302: hal_nrf_read_rx_pload(out_rx_pload);
	mov	dptr,#_epl_rf_en_read_rx_pload_out_rx_pload_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_hal_nrf_read_rx_pload
;------------------------------------------------------------
;Allocation info for local variables in function 'epl_rf_en_wait_rcv_msg'
;------------------------------------------------------------
;out_rx_pload              Allocated with name '_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1'
;------------------------------------------------------------
;	../epl_rf_en.c:312: void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload)
;	-----------------------------------------
;	 function epl_rf_en_wait_rcv_msg
;	-----------------------------------------
_epl_rf_en_wait_rcv_msg:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../epl_rf_en.c:314: epl_rf_en_enter_rx_mode();
	lcall	_epl_rf_en_enter_rx_mode
;	../epl_rf_en.c:315: while (epl_rf_en_rx_pload_is_empty());
00101$:
	lcall	_epl_rf_en_rx_pload_is_empty
	mov	a,dpl
	jnz	00101$
;	../epl_rf_en.c:316: hal_nrf_read_rx_pload(out_rx_pload);
	mov	dptr,#_epl_rf_en_wait_rcv_msg_out_rx_pload_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	ljmp	_hal_nrf_read_rx_pload
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
