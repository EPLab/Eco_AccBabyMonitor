;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
; This file was generated Tue Oct 26 13:20:58 2010
;--------------------------------------------------------
	.module usb_api
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
	.globl _usb_send_packet_PARM_2
	.globl _usb_state
	.globl _ep1_receive
	.globl _ep1_sent
	.globl _usb_init
	.globl _usb_wakeup
	.globl _usb_get_state
	.globl _usb_wait_for_configuration
	.globl _usb_send_packet
	.globl _usb_recv_packet
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
_ep1_sent::
	.ds 1
_ep1_receive::
	.ds 1
_usb_state::
	.ds 1
_usb_wait_for_configuration_usb_hal_state_1_1:
	.ds 1
_usb_send_packet_PARM_2:
	.ds 1
_usb_send_packet_in_data_1_1:
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
;Allocation info for local variables in function 'usb_init'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:24: void usb_init(void)
;	-----------------------------------------
;	 function usb_init
;	-----------------------------------------
_usb_init:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
;	../usb_api.c:26: hal_usb_init(true, device_req_cb, reset_cb, resume_cb, suspend_cb);
	mov	dptr,#_hal_usb_init_PARM_2
	mov	a,#_device_req_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_device_req_cb >> 8)
	movx	@dptr,a
	mov	dptr,#_hal_usb_init_PARM_3
	mov	a,#_reset_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_reset_cb >> 8)
	movx	@dptr,a
	mov	dptr,#_hal_usb_init_PARM_4
	mov	a,#_resume_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_resume_cb >> 8)
	movx	@dptr,a
	mov	dptr,#_hal_usb_init_PARM_5
	mov	a,#_suspend_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_suspend_cb >> 8)
	movx	@dptr,a
	mov	dpl,#0x01
	lcall	_hal_usb_init
;	../usb_api.c:28: hal_usb_endpoint_config(0x81, 32, ep_1_in_cb);          //bulk EP IN  1
	mov	dptr,#_hal_usb_endpoint_config_PARM_2
	mov	a,#0x20
	movx	@dptr,a
	mov	dptr,#_hal_usb_endpoint_config_PARM_3
	mov	a,#_ep_1_in_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_ep_1_in_cb >> 8)
	movx	@dptr,a
	mov	dpl,#0x81
	lcall	_hal_usb_endpoint_config
;	../usb_api.c:29: hal_usb_endpoint_config(0x01, 32, ep_1_out_cb);         //bulk EP OUT 1
	mov	dptr,#_hal_usb_endpoint_config_PARM_2
	mov	a,#0x20
	movx	@dptr,a
	mov	dptr,#_hal_usb_endpoint_config_PARM_3
	mov	a,#_ep_1_out_cb
	movx	@dptr,a
	inc	dptr
	mov	a,#(_ep_1_out_cb >> 8)
	movx	@dptr,a
	mov	dpl,#0x01
	lcall	_hal_usb_endpoint_config
;	../usb_api.c:31: ep1_sent = true;
	mov	dptr,#_ep1_sent
	mov	a,#0x01
	movx	@dptr,a
;	../usb_api.c:32: ep1_receive = false;
	mov	dptr,#_ep1_receive
;	../usb_api.c:34: usb_state = USB_AWAKE;
	clr	a
	movx	@dptr,a
	mov	dptr,#_usb_state
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'usb_wakeup'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:37: void usb_wakeup(void)
;	-----------------------------------------
;	 function usb_wakeup
;	-----------------------------------------
_usb_wakeup:
;	../usb_api.c:39: hal_usb_wakeup();
	lcall	_hal_usb_wakeup
;	../usb_api.c:40: usb_state = USB_AWAKE;
	mov	dptr,#_usb_state
	clr	a
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'usb_get_state'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:43: usb_state_t usb_get_state()
;	-----------------------------------------
;	 function usb_get_state
;	-----------------------------------------
_usb_get_state:
;	../usb_api.c:45: return usb_state;
	mov	dptr,#_usb_state
	movx	a,@dptr
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'usb_wait_for_configuration'
;------------------------------------------------------------
;i                         Allocated with name '_usb_wait_for_configuration_i_1_1'
;usb_hal_state             Allocated with name '_usb_wait_for_configuration_usb_hal_state_1_1'
;------------------------------------------------------------
;	../usb_api.c:48: void usb_wait_for_configuration(void)
;	-----------------------------------------
;	 function usb_wait_for_configuration
;	-----------------------------------------
_usb_wait_for_configuration:
;	../usb_api.c:52: do
	mov	r2,#0x00
	mov	r3,#0x00
00103$:
;	../usb_api.c:54: usb_hal_state = hal_usb_get_state();
	push	ar2
	push	ar3
	lcall	_hal_usb_get_state
	mov	a,dpl
	pop	ar3
	pop	ar2
	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
	movx	@dptr,a
;	../usb_api.c:55: if(i>10)
	clr	c
	mov	a,#0x0A
	subb	a,r2
	mov	a,#(0x00 ^ 0x80)
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00102$
;	../usb_api.c:56: usb_hal_state=CONFIGURED;
	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
	mov	a,#0x04
	movx	@dptr,a
00102$:
;	../usb_api.c:57: i++;
	inc	r2
	cjne	r2,#0x00,00112$
	inc	r3
00112$:
;	../usb_api.c:59: while(usb_hal_state != CONFIGURED);
	mov	dptr,#_usb_wait_for_configuration_usb_hal_state_1_1
	movx	a,@dptr
	mov	r4,a
	cjne	r4,#0x04,00103$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'usb_send_packet'
;------------------------------------------------------------
;size                      Allocated with name '_usb_send_packet_PARM_2'
;in_data                   Allocated with name '_usb_send_packet_in_data_1_1'
;------------------------------------------------------------
;	../usb_api.c:62: void usb_send_packet(uint8_t* in_data, uint8_t size)
;	-----------------------------------------
;	 function usb_send_packet
;	-----------------------------------------
_usb_send_packet:
	mov	r2,b
	mov	r3,dph
	mov	a,dpl
	mov	dptr,#_usb_send_packet_in_data_1_1
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r2
	movx	@dptr,a
;	../usb_api.c:64: while(!ep1_sent)
00101$:
	mov	dptr,#_ep1_sent
	movx	a,@dptr
	mov	r2,a
	jz	00101$
;	../usb_api.c:66: ep1_sent = false;
	mov	dptr,#_ep1_sent
	clr	a
	movx	@dptr,a
;	../usb_api.c:67: hal_usb_send_data(0x81, in_data, size);
	mov	dptr,#_usb_send_packet_in_data_1_1
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_usb_send_packet_PARM_2
	movx	a,@dptr
	mov	r5,a
	mov	dptr,#_hal_usb_send_data_PARM_2
	mov	a,r2
	movx	@dptr,a
	inc	dptr
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	a,r4
	movx	@dptr,a
	mov	dptr,#_hal_usb_send_data_PARM_3
	mov	a,r5
	movx	@dptr,a
	mov	dpl,#0x81
	ljmp	_hal_usb_send_data
;------------------------------------------------------------
;Allocation info for local variables in function 'usb_recv_packet'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:70: void usb_recv_packet(){ 
;	-----------------------------------------
;	 function usb_recv_packet
;	-----------------------------------------
_usb_recv_packet:
;	../usb_api.c:71: while(!ep1_receive)
00101$:
	mov	dptr,#_ep1_receive
	movx	a,@dptr
	mov	r2,a
	jz	00101$
;	../usb_api.c:74: ep1_receive = false;
	mov	dptr,#_ep1_receive
	clr	a
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'device_req_cb'
;------------------------------------------------------------
;data_ptr                  Allocated to stack - offset -5
;size                      Allocated to stack - offset -8
;req                       Allocated to registers 
;------------------------------------------------------------
;	../usb_api.c:77: static hal_usb_dev_req_resp_t device_req_cb(hal_usb_device_req* req, uint8_t** data_ptr, uint16_t* size) reentrant
;	-----------------------------------------
;	 function device_req_cb
;	-----------------------------------------
_device_req_cb:
	push	_bp
	mov	_bp,sp
;	../usb_api.c:80: return NAK;
	mov	dpl,#0x01
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'suspend_cb'
;------------------------------------------------------------
;allow_remote_wu           Allocated to registers r2 
;------------------------------------------------------------
;	../usb_api.c:84: static void suspend_cb(uint8_t allow_remote_wu) reentrant
;	-----------------------------------------
;	 function suspend_cb
;	-----------------------------------------
_suspend_cb:
	mov	r2,dpl
;	../usb_api.c:87: USBSLP = 1; // Disable USB clock (auto clear)
	mov	_USBSLP,#0x01
;	../usb_api.c:89: if (allow_remote_wu == 1)
	cjne	r2,#0x01,00102$
;	../usb_api.c:93: WUCONF = (BIT_5 | BIT_3 | BIT_1);
	mov	_WUCONF,#0x2A
;	../usb_api.c:94: usb_state = USB_REM_WU_ENABLE;
	mov	dptr,#_usb_state
	mov	a,#0x01
	movx	@dptr,a
	ret
00102$:
;	../usb_api.c:99: WUCONF = (BIT_3 | BIT_1);
	mov	_WUCONF,#0x0A
;	../usb_api.c:100: usb_state = USB_REM_WU_DISABLE;
	mov	dptr,#_usb_state
	mov	a,#0x02
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'resume_cb'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:104: static void resume_cb() reentrant
;	-----------------------------------------
;	 function resume_cb
;	-----------------------------------------
_resume_cb:
;	../usb_api.c:107: ep1_sent = true;
	mov	dptr,#_ep1_sent
	mov	a,#0x01
	movx	@dptr,a
;	../usb_api.c:108: ep1_receive = false;
	mov	dptr,#_ep1_receive
;	../usb_api.c:109: usb_state = USB_AWAKE;
	clr	a
	movx	@dptr,a
	mov	dptr,#_usb_state
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'reset_cb'
;------------------------------------------------------------
;------------------------------------------------------------
;	../usb_api.c:112: static void reset_cb() reentrant
;	-----------------------------------------
;	 function reset_cb
;	-----------------------------------------
_reset_cb:
;	../usb_api.c:115: ep1_sent = true;
	mov	dptr,#_ep1_sent
	mov	a,#0x01
	movx	@dptr,a
;	../usb_api.c:116: ep1_receive = false;
	mov	dptr,#_ep1_receive
;	../usb_api.c:117: usb_state = USB_AWAKE;
	clr	a
	movx	@dptr,a
	mov	dptr,#_usb_state
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ep_1_in_cb'
;------------------------------------------------------------
;size                      Allocated to stack - offset -5
;adr_ptr                   Allocated to registers 
;------------------------------------------------------------
;	../usb_api.c:121: static uint8_t ep_1_in_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
;	-----------------------------------------
;	 function ep_1_in_cb
;	-----------------------------------------
_ep_1_in_cb:
	push	_bp
	mov	_bp,sp
;	../usb_api.c:124: ep1_sent = true;
	mov	dptr,#_ep1_sent
	mov	a,#0x01
	movx	@dptr,a
;	../usb_api.c:125: return 0x60;
	mov	dpl,#0x60
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ep_1_out_cb'
;------------------------------------------------------------
;size                      Allocated to stack - offset -5
;adr_ptr                   Allocated to stack - offset 1
;i                         Allocated to registers r6 
;------------------------------------------------------------
;	../usb_api.c:128: static uint8_t ep_1_out_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
;	-----------------------------------------
;	 function ep_1_out_cb
;	-----------------------------------------
_ep_1_out_cb:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
;	../usb_api.c:134: usize = *size;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	dptr,#_usize
	movx	@dptr,a
;	../usb_api.c:136: for(i = 0;i < usize;i++)
	mov	r6,#0x00
00101$:
	clr	c
	mov	a,r6
	subb	a,r5
	jnc	00104$
;	../usb_api.c:137: ubuf[i] = adr_ptr[i];
	push	ar5
	mov	a,r6
	add	a,#_ubuf
	mov	r7,a
	clr	a
	addc	a,#(_ubuf >> 8)
	mov	r5,a
	mov	r0,_bp
	inc	r0
	mov	a,r6
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	dpl,r7
	mov	dph,r5
	movx	@dptr,a
;	../usb_api.c:136: for(i = 0;i < usize;i++)
	inc	r6
	pop	ar5
	sjmp	00101$
00104$:
;	../usb_api.c:146: ep1_receive = true;
	mov	dptr,#_ep1_receive
	mov	a,#0x01
	movx	@dptr,a
;	../usb_api.c:147: return 0xFF;
	mov	dpl,#0xFF
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
