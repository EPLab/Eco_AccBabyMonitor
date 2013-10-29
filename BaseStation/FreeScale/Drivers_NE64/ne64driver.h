/*****************************************************************************
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : ne64API.h
 *
 * PURPOSE: NE64 Ethernet API header definitions
 *
 *
 * DESCRIPTION: Defines headers of higher level routines for the EMAC module
 *
 *
 * Version : 2.1
 * Date    : 02/04/04
 *
 *****************************************************************************/

#ifndef NE64_DRIVER_H
#define NE64_DRIVER_H

#include "MOTTYPES.h"
#include "ne64config.h"

/** \brief EtherInit: Start up EPHY and EMAC base on  etherinit.h user configuration
 *	\ingroup EtherInit
 *
 *	This function initializes the NE64 EMAC and EPHY and sets speed and duplex
 *  based on the users configuation in the "etherinit.h" file
 *
 *  \param  NONE 
 *  \return 
 *	NONE
 *
 *  \see ne64config.c
 *  \todo 
 *      \li  Validate Pause Resolution after lost link and re-autonegation
 *      \li  Validate Duplex Resolution after lost link and re-autonegation
 *      \li  Provide workaround for auto-negoitiation link issue 
 *  \bug 
 *      \li  Dummy MII read required after restart auto-negotiation
 *      \li  Dummy MII read required after MII write to PHY interrupt registers
 */
void EtherInit (void);


/** \brief MIIwrite: write data to PHY function
 *	\ingroup ne64api
 *
 *	Write internal EPHY registers through EMAC MII seiral management interface.
 *
 *  \param  _mpadr - address of the device
 *  \param  _mradr - address of the register within the device
 *  \param  _mwdata - data to write to the PHY register
 *  \return
 *	0xff = operation completed OK
 *    \li 0x00 = MII busy
 *  \todo Make this function repeat until it is sucessful
 *  \bug Before the MII write take affect a dummy read via the MII is required.
 *       This function could be made to do the dummy read
 *  \warning MII clock must be configured correctly and PHY PLLs must not be disabled for
 * 		MII seiral management communication
 */
tU08 MIIwrite(tU08 _mpadr, tU08 _mradr, tU16 _mwdata);


/** \brief MIIread: read data from PHY function
 *	\ingroup ne64api
 *
 * Read internal EPHY registers through EMAC MII seiral management interface.
 *
 *  \param  _mpadr - address of the device
 *  \param  _mradr - address of the register within the device
 *  \param  _mwdata - pointer to where to store the received contents of PHY register
 *  \return
 *	0xff = operation completed OK
 *    \li 0x00 = MII busy
 *  \warning MII clock must be configured correctly and PHY PLLs must not be disabled for
 * 		MII seiral management communication
 *  \see ne64api.h
 *  \todo Make this function repeat until it is sucessful
 *  \bug
 */
tU08 MIIread(tU08 _mpadr, tU08 _mradr, tU16 * _mrdata);


/** \brief EtherType: set the Ethertye acceptance registers
 *	\ingroup ne64api
 *
 *	This function set the Ethertye acceptance registers based on
 *  the users configuation in the "ne64config.h" file
 *
 *  \param  control - the acceptance mask (see definitons)
 *  \param  etype   - programmable ethertype (16bit value)
 *  \return
 *	No return value
 *  \warning It is recommend not to change the Ethertype when the EMAC is enabled
 *  \see ne64api.h
 *  \todo
 *  \bug
 */
void EtherType(tU08 control, tU16 etype);
#define T_PET   0x80 /**< Programmable Ethertype, 'etype' parameter is used */
#define T_EMW   0x10 /**< Emware Ethertype */
#define T_IPV6  0x08 /**< Internet IP version (IPV6) Ethertype */
#define T_ARP   0x04 /**< Address Resolution Protocol (ARP) Ethertype */
#define T_IPV4  0x02 /**< Internet IP version 4 (IPV6) Ethertype */
#define T_IEEE  0x01 /**< IEEE802.3 Length Field Ethertype */
#define T_ALL   0x00 /**< Accept all ethertypes */

/** \brief EtherIoctl: Setting of the multicast hash table
 *	\ingroup ne64api
 *
 *	Setting of the multicast hash table
 *
 *  \param  flag    - either MC_ALL or MC_LIST
 *  \param  listPtr - pointer to address list (valid only if flag == MC_LIST)
 *  \param  listLen - number of addresses in list (valid only if flag == MC_LIST)
 *  \return
 *	No return value
 *  \see ne64api.h
 *  \todo  This function need more testing
 *  \bug
*/
void EtherIoctl(tU08 flag, void * optionPtr, tU08 optionLen);
#define MC_ALL  0 /**< set hash to accept all multicast frames */
#define MC_LIST 1 /**< set hash to accept list of addresses */

/** \brief EtherGetPhysAddr: return EMAC current physical address
 *	\ingroup ne64api
 *
 *	return EMAC current physical address
 *
 *  \param  ethaddr - pointer to place (6 bytes) where the physical address will be stored to
 *	No return value
 *  \see ne64api.h
 *  \todo
 *  \bug
 */
void EtherGetPhysAddr(void * ethaddr);


/** \brief EtherSend: send one frame
 *	\ingroup ne64api
 *
 *	This function sends one frame
 *
 *  \param  databuf - pointer to data which should be sent
 *  \param  datalen - length of the data to be sent
 *  \return
 *	No return value
 *  \see ne64api.h
 *  \todo
 *  \bug
 */
void EtherSend(void * databuf, tU16 datalen);

/** \brief EtherReceive: read received frame
 *	\ingroup ne64api
 *
 *	This function reads the received frame
 *
 *  \param  buffer - pointer to place where the physical address will be stored to
 *  \return
 *	length of the received data (if 0 - then no data received)
 */
#if   RX_POLL_MODE
tU16 EtherReceive(void * buffer);
tU16 EtherReceiveZeroCopy(tU08 * whichbuffer);
#else	 //    RX_POLL_MODE
void ProcessPacket();
#endif //		 RX_POLL_MODE


/** \brief EtherOpen: prepare the EMAC for normal operation
 *	\ingroup ne64api
 *
 *	This function initializes the NE64 EMAC
 *
 *  \param  miisetup -  mii preamble & clock setup
 *  \param  bufmap - buffer configuration  (see tables 3-5&3-6 in EMAC doc.)
 *  \param  maxfl - initial max.frame length for receive
 *  \param  pmacad - pointer to MAC address definition
 *  \param  control - the acceptance mask (same as in EtherType function)
 *  \param  etype - programmable ethertype (16bit value)
 *  \param  rxmode - reception mode settings 	 (see RXCT_X possible values)
 *  \param  netctl - network control setup (see NETCT_X possible values)
 *  \return  NONE
 *  \see ne64api.h
 *  \todo
 *  \bug
 */
void EtherOpen(tU08 miisetup, /* */
               tU08 bufmap,   /*
                                         */
                 tU16 maxfl,   /*  */
                        void * pmacad, /*  */
                tU08 control,
                   tU16 etype, /* */
                 tU08 rxmode, /*  */
                 tU08 netctl /* */
                 );
/* miisetup values */
#define MII_NO_PREAM   0x10 /**< No preamble */
#define MII_C20     0x04    /**< 20Mhz IP Bus 2.5MHz MDC clock */
#define MII_C25     0x05		/**< 25Mhz IP Bus */
#define MII_C33     0x07		/**< 33Mhz IP Bus */
#define MII_C40     0x08		/**< 40Mhz IP Bus */
#define MII_C50     0x0a		/**< 50Mhz IP Bus */

/* network control setup values */
#define NETCT_ESWAI  0x10  /**< EMAC disabled during WAIT */
#define NETCT_EXTPHY 0x08  /**< external PHY mode */
#define NETCT_MLB    0x04  /**< MAC loopback mode */
#define NETCT_FDX    0x02  /**< full duplex mode */

/* rxmode setup values */
#define RXCT_RFCE   0x10 /**< PAUSE frame supported */
#define RXCT_PROM   0x04 /**< promiscuous mode */
#define RXCT_CONMC  0x02 /**< multicast hash table used for incoming frames chk */
#define RXCT_BCREJ  0x01 /**< all broadcast frames will be rejected */


/** \brief EtherClose: switch off the EMAC and clear interrupt flags
 *	\ingroup ne64api
 *
 *	This function switches off the EMAC and clear interrupt flags
 *
 *  \param  NONE
 *  \return NONE
 */
void EtherClose(void);


/** \brief EmacDisable: switch off the EMAC
 *	\ingroup ne64api
 *
 *	switch off the EMAC
 *
 *  \param  NONE
 *  \return NONE
 */
void EmacDisable(void);


/** \brief EmacEnable: switch on the EMAC
 *	\ingroup ne64api
 *
 *	switch on the EMAC
 *
 *  \param  NONE
 *  \return NONE
 */
void EmacEnable(void);


/** \brief EmacControl: Set control bits in EMAC netctl register
 *	\ingroup ne64api
 *
 *	Set control bits in EMAC netctl register
 *
 *  \param  NONE
 *  \return NONE
 */
void EmacControl(tU08 netctl);


/** \brief EtherAbortTx: abort TX in progress
 *	\ingroup ne64api
 *
 *	This function aborts TX in progress
 *
 *  \param  NONE
 *  \return NONE
 *  \todo This function need more testing
 *  \bug
 */
void EtherAbortTx(void);

/** \brief EtherOtherTx: EtherPause: send PAUSE frame
 *	\ingroup ne64api
 *
 *	This function sends PAUSE frame
 *
 *  \param  ptrc -  if 1 ptime used for PAUSE time setting, if 0 ptime not used
 *  \param  ptime - value of PAUSE timer
 *  \return
 *	returns current value of PAUSE timer when ptrc=0
 *  \todo This function need more testing
 *  \bug
 */
tU16 EtherPause(tU08 ptrc, tU16 ptime);



/** \brief EtherOtherTx: setup of other TX parameters
 *	\ingroup ne64api
 *
 *	This function sets up of other TX parameters
 *
 *  \param  txpar -  acceptable values (see TXCT_X possible values)
 *  \return
 *	No return value
 *  \todo This function need more testing
 *  \bug
*/
void EtherOtherTx(tU08 txpar);
#define TXCT_PTRC 0x10 /* same as ptrc in EtherPause function */
#define TXCT_SSB  0x08 /* set single slot back-off (otherwise random back-off)*/

/** \brief ExternalBusCfg: external bus mode configuration
 *	\ingroup ne64api
 *
 *	This function sets up external bus mode and forces the bus clock 
 *  to 16 Mhz which is the external bus mode maximum.	 The function needs
 *  to be located in main().
 *
 *  \param None
 *  \return None
 *  \todo 
 *  \bug
*/
void EtherStartFrameTransmission(tU16 datalen);


/** \brief ExternalBusCfg: external bus mode configuration
 *	\ingroup ne64api
 *
 *	This function sets up external bus mode and forces the bus clock 
 *  to 16 Mhz which is the external bus mode maximum.	 The function needs
 *  to be located in main().
 *
 *  \param None
 *  \return None
 *  \todo 
 *  \bug
*/
#if USE_EXTBUS
void  ExternalBusCfg(void);
#endif


/** \brief UseSWLedRun: Turn off EPHY indicator LED 
 *	\ingroup ne64api
 *
 *	This function turns off EPHY indicator LED when driven by software.  
 *  The function need to be located in main() and required a global 
 *  counter called, LEDcounter.  Alternatively, this code can be
 *  can be placed in a timer function
 *
 *  \param  None
 *  \return   None
 *  \todo 
 *  \bug
*/
#if USE_SWLED
void  UseSWLedRun(void);
#endif


//Register Mask and Other
//===============
/* Definition of allowed values for MDCSEL */
#define MII_MDCSEL(x) x/5000000

#define MII_WRITE   0x01
#define MII_READ    0x02

#define TCMD_START 0x01 /* Transmit buffer frame */
#define TCMD_PAUSE 0x02 /* Transmit PAUSE frame */
#define TCMD_ABORT 0x03 /* Abort transmission */

/* PHY registers symbolic names */
/* (located in MII memory map, accessible through MDIO) */
#define PHY_REG_CR      0x00 /* Control Register */
#define PHY_REG_SR      0x01 /* Status Register */
#define PHY_REG_ID1     0x02 /* PHY Identification Register 1 */
#define PHY_REG_ID2     0x03 /* PHY Identification Register 2 */
#define PHY_REG_ANAR    0x04 /* Auto-Negotiation Advertisement Register */
#define PHY_REG_ANLPAR  0x05 /* Auto-Negotiation Link Partner Ability Register */
#define PHY_REG_ER      0x06 /* Auto-Negotiation Expansion Register */
#define PHY_REG_NPTR    0x07 /* Auto-Negotiation Next Page Transfer Register */
#define PHY_REG_IR      0x10 /* Interrupt Register */
#define PHY_REG_PSR     0x11 /* Proprietary Status Register */
#define PHY_REG_PCR     0x12 /* Proprietary Control Register */
#define PHY_REG_10BTBC  0x13 /* 10Base-T Bypass Control Register */
#define PHY_REG_100BXBC 0x14 /* 100Base-X Bypass Control Register */
#define PHY_REG_ADDR    0x15 /* Test & Trim Control Register */
#define PHY_REG_DSPRC   0x17 /* DSP Reset Control */
#define PHY_REG_DSPRR1  0x18 /* 100Base-X DSP Read Registers */
#define PHY_REG_DSPRR2  0x19
#define PHY_REG_DSPRR3  0x1A
#define PHY_REG_DSPWR1  0x1B /* 100Base-X DSP Write Registers */
#define PHY_REG_DSPWR2  0x1C
#define PHY_REG_DSPWR3  0x1D

/* PHY registers structure */
/* 0 - Control Register */
#define PHY_R0_RESET    0x8000  /* Reset */
#define PHY_R0_LB       0x4000  /* Loop Back */
#define PHY_R0_DR       0x2000  /* Data Rate (100Mb/s) */
#define PHY_R0_ANE      0x1000  /* Auto-Negotiation Enable */
#define PHY_R0_PD       0x0800  /* Power Down */
#define PHY_R0_ISOLATE  0x0400  /* Isolate (MII is disconnected) */
#define PHY_R0_RAN      0x0200  /* Restart Auto-Negotiation */
#define PHY_R0_DPLX     0x0100  /* Duplex (Full duplex) */
#define PHY_R0_CT       0x0080  /* Collision Test (Enable) */

/* 1 - Status Register */
#define PHY_R1_100T4    0x8000  /* 100BASET4 Supported */
#define PHY_R1_100F     0x4000  /* 100Mb/s Full Duplex Supported */
#define PHY_R1_100H     0x2000  /* 100Mb/s Half Duplex Supported */
#define PHY_R1_10F      0x1000  /* 10Mb/s Full Duplex Supported */
#define PHY_R1_10H      0x0800  /* 10Mb/s Half Duplex Supported */
#define PHY_R1_SUP      0x0040  /* MI Preamble Supression (capable of) */
#define PHY_R1_ANC      0x0020  /* Auto Negotiation Complete */
#define PHY_R1_RF       0x0010  /* Remote Fault */
#define PHY_R1_ANA      0x0008  /* Auto-Negotiation Ability (present) */
#define PHY_R1_LS       0x0004  /* Link Status (Link is Up) */
#define PHY_R1_JD       0x0002  /* Jabber Detect (detected) */
#define PHY_R1_EC       0x0001  /* Extended Capability (regs 2 to 31 exists) */

/* 2 - PHY Identifier Register 1 */
/* 3 - PHY Identifier Register 2 */
/* read only - contains Manufacturer's info etc.
   see documentation for the detailed description */

/* 4 - Auto Negotiation Advertisement Register */
#define PHY_R4_NP       0x8000  /* Next Page (capable of sending next pages) */
#define PHY_R4_RF       0x2000  /* Remote Fault */
#define PHY_R4_FC       0x0400  /* Flow Control */
#define PHY_R4_100F     0x0100  /* 100Base-TX Full Duplex Capable */
#define PHY_R4_100H     0x0080  /* 100Base-TX Half Duplex Capable */
#define PHY_R4_10F      0x0040  /* 10Base-T Full Duplex Capable */
#define PHY_R4_10H      0x0020  /* 10Base-T Half Duplex Capable */
/* bits 4 to 0 are Selector Field (IEEE Std 802.3 = 00001) */

/* 5 - Auto Negotiation Link Partner Ability Register (Base Page & Next Page) */
/* read only - please consult PHY documentation */
#define PHY_R5_FCTL      0x0400  /* 10Base-T Half Duplex Capable */

/* 16 - Interrupt Control Register */
#define PHY_R16_ACKIE 	0x4000	//Acknowledge Bit Received Interrupt Enable
#define PHY_R16_PRIE 	0x2000	  //Page Received INT Enable
#define PHY_R16_LCIE 	0x1000	  //Link Changed Enable
#define PHY_R16_ANIE 	0x0800	  //Auto-Negotiation Changed Enable
#define PHY_R16_PDFIE 	0x0400	//Parallel Detect Fault Enable
#define PHY_R16_RFIE 	0x0200	  //Remote Fault Interrupt Enable
#define PHY_R16_JABIE	0x0100	  //Jabber Interrupt Enable

#define PHY_R16_ACKR 0x0040	  //Acknowledge Bit Received Interrupt
#define PHY_R16_PGR 	0x0020	//Page Received 
#define PHY_R16_LKC 	0x0010	//Link Changed 
#define PHY_R16_ANC 	0x0008	//Auto-Negotiation Changed 
#define PHY_R16_PDF 	0x0004	//Parallel Detect Fault
#define PHY_R16_RMTF 0x0002	  //Remote Fault Interrupt
#define PHY_R16_JABI	0x0001	//Jabber Interrupt

////Proprietary Status Register
#define PHY_R17_LNK 	 0x4000	//
#define PHY_R17_DPM   0x2000	//Duplex Mode
#define PHY_R17_SPD 	 0x1000	//Speed
#define PHY_R17_ANNC  0x0400	//Auto-Negotiation Complete
#define PHY_R17_PRCVD 0x0200	//
#define PHY_R17_ANCM  0x0100	// Auto-Negotiation (A-N) Common Operating Mode
#define PHY_R17_PLR   0x0020	//


#define BUFA_FULL    99					 /**<BUFA_FULL constant      */
#define BUFB_FULL    66					 /**<BUFB_FULL constant      */


#endif      /* NE64_DRIVER_H */
