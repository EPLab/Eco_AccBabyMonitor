/*****************************************************************************
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : ne64api.c
 *
 * PURPOSE: NE64 Ethernet API
 *
 * DESCRIPTION: Defines higher level routines for the EMAC module
 *
 * Version : 3.0
 * Date    : 06/07/04
 *
 *****************************************************************************/
#include "MOTTYPES.h"
#include "address.h"
#include "ne64config.h"
#include "ne64driver.h"
#include "ne64debug.h"          /* diagnostics - enabled when SCI_DEBUG defined */
#include "MC9S12NE64.h"

/* CALLBACK function from EMAC ISR */
extern UINT16 NE64Receive (void *PktBuffer, UINT16 len, UINT16 flags);

/* These structures/unions should NOT be exported! */
typedef union uMCHASHUnion
  {
  tU16 Word[4];         /* Multicast Hash Table bits 63 to 0 */
  tU08 Byte[8];
  }tMCHASHStr;

typedef union uMACADUnion
{
  tU16 Word[3];         /* MAC Address bits 47 to 0 */
  tU08 Byte[6];
} tMACADStr;

typedef struct
  {
   tU08 da[6]; /**< destination address */
   tU08 sa[6]; /**< source address */
   tU16 ft;    /**< frame type */
  }tFRHEAD;
  
typedef tFRHEAD * pFRHEAD;



#define RAM_START 0x2000    /**< RAM block starting address */

#if WORD_ACCESS
  tREG16 emacFIFOa[EMAC_RX_SZ/2] @ RAM_START;                     /**< Emac RX buffer A definition */
  tREG16 emacFIFOb[EMAC_RX_SZ/2] @ (RAM_START + EMAC_RX_SZ);      /**< Emac RX buffer B definition */
  tREG16 emacFIFOtx[EMAC_TX_SZ/2] @ (RAM_START + 2*EMAC_RX_SZ);   /**< Emac TX buffer definition */
#else
  tU08 emacFIFOa[EMAC_RX_SZ] @ RAM_START;                         /**< Emac RX buffer A definition */
  tU08 emacFIFOb[EMAC_RX_SZ] @ (RAM_START + EMAC_RX_SZ);          /**< Emac RX buffer B definition */
  tU08 emacFIFOtx[EMAC_TX_SZ] @ (RAM_START + 2*EMAC_RX_SZ);       /**< Emac TX buffer definition */
#endif

#if WORD_ACCESS
  extern   tREG16    *rxa_pointer;
  extern   tREG16    *rxb_pointer;
  extern   tREG16    *tx_pointer;
#else
  extern   tU08    *rxa_pointer;
  extern   tU08    *rxb_pointer;
  extern   tU08    *tx_pointer;
#endif		//WORD_ACCESS
#if USE_SWLED
extern tU16 LEDcounter;
#endif	 //USE_SWLED


tU16 gotxflowc;			/**<Global Variable For Determination of
                                      * Flow Control Packets are sent in Full Duplex
                                      * defined in "main.c" */

tU08	gotlink;   						/**<Global Variable For Determination if
                                      * link is active (1=active)
                                      * defined in "main.c" */
                                      

          //Intialize Ethernet Module
//===============================================
void EtherInit (void)
{

  //Variable
  tU16 myctr; 								//generic counter variable
  tU16 mymrdata, mymwdata;    //temp variable for MII read/write data
  tU08 angotduplex, 					//Auto negotiation control variable
       etypecontrol, 				  //Ethertype filter control variable
       addressfiltercontrol;	//address filter control variable

  //No link present
  gotlink = 0;

  //=========================
  //PHY Inits	 - enable EPHY module	and EPHY Interrupt
  //=========================

  //Write PHY address before EPHYEN is set; this will latch EPHY register 14 on reset
  //address PHY 0 (default address of internal PHY); PHYADD0 | PHYADD1 | PHYADD2 | PHYADD3| PHYADD4
  EPHYCTL1 = PHY_ADDRESS;	 //Modify in "ne64config.h"

  //Enable EPHY module with PHY clocks disabled
  //Do not trun on PHY clocks untill both EMAC and EPHY are completely setup (see Below)
  EPHYCTL0 = EPHYCTL0_DIS100_MASK | EPHYCTL0_DIS10_MASK;
#if  AUTO_NEG
  //Enable auto_neg at start-up
  EPHYCTL0 = EPHYCTL0 & (~EPHYCTL0_ANDIS_MASK);
#else				//ELSE AUTO_NEG
  //Disable auto_neg at start-up
  EPHYCTL0 = EPHYCTL0 | EPHYCTL0_ANDIS_MASK;
#endif	    //AUTO_NEG

  //Enable EPHY module
  EPHYCTL0 = EPHYCTL0_EPHYEN_MASK | EPHYCTL0;      //Enable PHY

  //Enable EPHY LEDs and Interrupts
#if USE_SWLED  

  EPHYCTL0 = EPHYCTL0 | (EPHYCTL0_EPHYIEN_MASK );
#if   ACTLED
  DDRL_DDRL0 = 1;
  PTL_PTL0 = 1; //turn off LED
#endif
#if   LNKLED
  DDRL_DDRL1 = 1;
  PTL_PTL1 = 1; //turn off LED
#endif
#if   SPDLED
  DDRL_DDRL2 = 1;
  PTL_PTL3 = 1; //turn off LED
#endif
#if   DUPLED
  DDRL_DDRL3 = 1;
  PTL_PTL3 = 1; //turn off LED
#endif
#if   COLLED
  DDRL_DDRL4 = 1;
  PTL_PTL4 = 1; //turn off LED
#endif

#else
  EPHYCTL0 = EPHYCTL0 | (EPHYCTL0_LEDEN_MASK | EPHYCTL0_EPHYIEN_MASK );
#endif

  //DELAY, Delay staret-up
  for (myctr=18000; myctr >0; myctr--);


  //=========================
  //EMAC Inits
  //========================

  //We do not duplex yet since auto_neg is not complete so use half as default
  angotduplex = 0; 				 //Auto negotiation control variable

  //Configure RX mode based on EtherInit() define settings
  addressfiltercontrol = 0;		 //address filter control variable
#if (BRODC_REJ)
    addressfiltercontrol = addressfiltercontrol | RXCT_BCREJ;
#endif
#if (CON_MULTIC)
    addressfiltercontrol = addressfiltercontrol | RXCT_CONMC;
#endif
#if (PROM_MODE)
    addressfiltercontrol = addressfiltercontrol | RXCT_PROM;
#endif

  //Configure Ethertype based on EtherInit() define settings
#pragma MESSAGE DISABLE C5917		//Warning: Dead assign
  etypecontrol = 0;				 //Ethertype filter control variable
#pragma MESSAGE DEFAULT C5917		//Warning: Dead assign      
#if (ETYPE_PET)
    etypecontrol = etypecontrol | T_PET;
#endif
#if (ETYPE_EMW)
    etypecontrol = etypecontrol | T_EMW;
#endif
#if (ETYPE_IPV6)
    etypecontrol = etypecontrol | T_IPV6;
#endif
#if (ETYPE_ARP)
    etypecontrol = etypecontrol | T_ARP;
#endif
#if (ETYPE_IPV4)
    etypecontrol = etypecontrol | T_IPV4;
#endif
#if (ETYPE_IEEE)
    etypecontrol = etypecontrol | T_IEEE;
#endif
#if (ETYPE_ALL)
#pragma MESSAGE DISABLE C5900		//Warning: Result is zero
    etypecontrol = etypecontrol & T_ALL;
#pragma MESSAGE DEFAULT C5900		//Warning: Result is zero       
#endif

  //Initialize EMAC including MII management Interface
  EtherOpen(MII_MDCSEL(BUS_CLOCK),
            BUFMAP,                   // defined in 'emacfifocfg.h'
            RX_MAX_FL,                // RX max packet lenght
            (void *)hard_addr,        // defined in 'address.h'
            etypecontrol,                // program ethertype fixed filter target */
            ETYPE_PRG,                // program prgramable ethertype value related to T_PET */
#if XFLOWC	 //this should be only enabled in auto negotiation if pause resolution confirms this (full duplex only)
            RXCT_RFCE | addressfiltercontrol,
#else             //ELSE XFLOWC
            addressfiltercontrol,
#endif						//XFLOWC

#if  AUTO_NEG
            //Configure Net Control: Duplex, external PHY, loopback, wait
            angotduplex		        //Half Duplex operation default until auto_neg is complete
#else			//ELSE AUTO_NEG (manual speed duplex settings)
#if FULL_DUPLEX
            NETCT_FDX           // full duplex operation */
#else     //ELSE FULL_DUPLEX
            angotduplex           //Half Duplex operation */
#endif	  //FULL_DUPLEX
#endif		//AUTO_NEG
            );

  //Enable Select EMAC interrrupt: 
  IMASK = IMASK_TXCIE_MASK | IMASK_ECIE_MASK | IMASK_LCIE_MASK;
#if (!RX_POLL_MODE)    //USE RX INTERRUPTS
  IMASK = IMASK | IMASK_RXACIE_MASK |  IMASK_RXBCIE_MASK;
#endif  // RX_POLL_MODE
  IMASK = IMASK | IMASK_RXAOIE_MASK|IMASK_RXBOIE_MASK | IMASK_RXEIE_MASK;				//Buffer Overruns & RX error
  IMASK = IMASK | IMASK_BREIE_MASK;             //Babbling Error		
  IMASK = IMASK | IMASK_RFCIE_MASK;							//RX flow Control								  


  //Transmit pause initialization: set bit and pause time  duration 
#if XFLOWC

#if AUTO_NEG
//   EtherPause(1,PAUSE_TIME);			 // PAUSE_TIME defined in "ne64config.h"
#endif	  //AUTO_NEG

#if FULL_DUPLEX
   gotxflowc = 1;
//   EtherPause(1,PAUSE_TIME);
#endif	  //FULL_DUPLEX

#endif		//XFLOWC

//===============================================
// Configure PHY through EMAC MII Serial Management now that MII clock is set (address PHY is 0x00)
//===============================================
   //READ  PHY_REG_IDX: PHY idenfitication which is composed from OUI and make/model/revision of PHY
#if READ_PHY_ID
   //read PHY_REG_ID1
   while ( !(MIIread(PHY_ADDRESS, PHY_REG_ID1 , &mymrdata)) );

   //read PHY_REG_ID2 - should be:
   while ( !(MIIread(PHY_ADDRESS, PHY_REG_ID2 , &mymrdata))  );

   //read PHY_REG_ADDR - should be: 0x00
   while ( !(MIIread(PHY_ADDRESS, PHY_REG_ADDR , &mymrdata)) );
#endif

//Read PHY_REG_ANAR then configure the PHY Link abilities for auto_negoigation 

#if AUTO_NEG
   while ( !(MIIread(PHY_ADDRESS, PHY_REG_ANAR, &mymrdata)) );

//Configure Flow Control PHY Link abilities advertisement
    mymwdata = mymrdata;
#if XFLOWC
   mymwdata = mymwdata | PHY_R4_FC;
#endif //#if XFLOWC

//Configure Speed and Duplex PHY Link abilities advertisement 
#if (~FULL10  & 1)
    mymwdata = mymwdata & ~PHY_R4_10F;
#endif
#if (~HALF10  & 1)
    mymwdata = mymwdata & ~PHY_R4_10H;
#endif
#if (~HALF100 & 1)  || (USE_EXTBUS)
    mymwdata = mymwdata & ~PHY_R4_100H;
#endif
#if (~FULL100  & 1)	 || (USE_EXTBUS)
    mymwdata = mymwdata & ~PHY_R4_100F;
#endif

   //Write PHY_REG_ANAR to configure PHY Link abilities advertisement
   //ALSO, DISABLE NEXT PAGE TO FOLLOW ADVERTISEMENT  (added 7/15/04)  
   while ( !(MIIwrite(PHY_ADDRESS, PHY_REG_ANAR, mymwdata  & ~PHY_R4_NP ))    );

#endif //#if AUTO_NEG

   //Enable PHY interrupts in Reg 16 (PHY Interrupt Control Register)
	 //Set PHY Interrupt Control Register
   mymwdata = PHY_R16_ACKIE | PHY_R16_PRIE | PHY_R16_LCIE | PHY_R16_ANIE;
   mymwdata = mymwdata | PHY_R16_PDFIE | PHY_R16_RFIE | PHY_R16_JABIE;
   while ( ! (MIIwrite(PHY_ADDRESS, PHY_REG_IR, mymwdata))   );

//===============================================
// Start up EPHY clocks (PLLs)
//===============================================

   //Read PHY Control Register 0
   while ( !(MIIread(PHY_ADDRESS, PHY_REG_CR, &mymrdata)) );

//Start up EPHY in auto negotiation
#if  AUTO_NEG

	 //Start PHY PLLs
     EPHYCTL0 = EPHYCTL0  & ~(EPHYCTL0_DIS100_MASK | EPHYCTL0_DIS10_MASK); //Let PHY PLLs be determined by PHY

//Start up EPHY without auto negotiation (CONFIGURE MANUALLY- SPEED AND DUPLEX)
#else	 //NO AUTO_NEG

//Set Duplex MANUALLY
#if FULL_DUPLEX
   mymwdata = mymrdata | PHY_R0_DPLX;		  //Set Full Duplex
#else                   //ELSE FULL_DUPLEX
   mymwdata = mymrdata & ~PHY_R0_DPLX;    //Set Half Duplex
#endif	                //FULL_DUPLEX

//Set Speed MANUALLY
#if SPEED100
#if USE_EXTBUS	 //OVERRIDE USER: Set SPEED10 since with Extbus&Ethernet speed limit is 10 Mbps
   mymwdata = mymwdata & ~PHY_R0_DR;
   //add warning		
#else
   mymwdata = mymwdata | PHY_R0_DR;		//Set SPEED100
#endif   
#else                   //ELSE SPEED100
   mymwdata = mymwdata & ~PHY_R0_DR;		//Set SPEED10
#endif	                //SPEED100

   //Write Config Register to set manually configure speed and duplex
   while ( !(MIIwrite(PHY_ADDRESS, PHY_REG_CR, mymwdata ))    );

	 //Start EPHY PLLs
   EPHYCTL0 = EPHYCTL0  & ~(EPHYCTL0_DIS100_MASK | EPHYCTL0_DIS10_MASK); //Let PHY PLLs be determined by PHY

#endif			      //AUTO_NEG

}

  
//===============================================
tU08 MIIwrite(tU08 _mpadr, tU08 _mradr, tU16 _mwdata) {
 
  tU16 temprdata;

  _DEBUGNL;_DEBUGT("-MIIWRITE-");
  if (MCMST_BUSY)
  {
   _DEBUGT("-MII_BUSY ");
   return 0; /* MII busy -> return with error  */
  }
  MPADR=_mpadr;
  MRADR=_mradr;
  MWDATA=_mwdata;
  MCMST_OP=MII_WRITE;

  //Wait for MII write
  while (!IEVENT_MMCIF); /* wait for transfer completed */
  IEVENT = IEVENT_MMCIF_MASK; /* Clear the flag in Emac */
  
  while ( ! (MIIread(PHY_ADDRESS, PHY_REG_IR, &temprdata))   );
    
  return 0xff; /* operation completed OK */
}

//===============================================
 tU08 MIIread(tU08 _mpadr, tU08 _mradr, tU16 * _mrdata)  {
 
  _DEBUGNL;_DEBUGT("-MIIREAD-");  
  if (MCMST_BUSY)
  {
   _DEBUGT("-MII_BUSY ");
   return 0; /* MII busy -> return with error */
  }

  MPADR=_mpadr;
  MRADR=_mradr;
  MCMST_OP=MII_READ;

  //Wait for MII read
  while (!IEVENT_MMCIF); /* wait for transfer completed */
  *_mrdata = MRDATA;
  IEVENT = IEVENT_MMCIF_MASK; /* Clear the flag in Emac */

  _DEBUGT("DATA= "); _DEBUGI(*_mrdata);	 _DEBUGNL;
  return 0xff; /* operation completed OK */
}



//===============================================
#if RX_POLL_MODE
tU16 EtherReceive(void * buffer)
{
  tU08 * pOut;
  tU08 * pIn;
  tU16 ctr;

  /* check FIFO buffer A flag */
  if (IEVENT_RXACIF)
  { /* frame in buffer A 		 */
    _DEBUGT("-RXA-");
    pOut=(tU08 *)buffer;
    pIn=emacFIFOa;
    /* copy data from FIFO to output buffer */
    for (ctr=0; ctr <= RXAEFP; ctr++)
    {
      *pOut=*pIn;
      pOut++;
      pIn++;
    }
    IEVENT = IEVENT_RXACIF_MASK;
    return ctr; /* return number of bytes copied */
  }
  /* check FIFO buffer B flag */
  if (IEVENT_RXBCIF)
  { /* frame in buffer B */
    _DEBUGT("-RXB-");
    pOut=(tU08 *)buffer;
    pIn=emacFIFOb;
    /* copy data from FIFO to output buffer */
    for (ctr=0; ctr <= RXBEFP; ctr++)
    {
      *pOut=*pIn;
      pOut++;
      pIn++;
    }
    IEVENT = IEVENT_RXBCIF_MASK;
    return ctr; /* return number of bytes copied */
  }
  return 0; /* neither A or B buffer filled */
}

//===============================================
tU16 EtherReceiveZeroCopy(tU08 * whichbuffer)
{

  /* check FIFO buffer A flag */
  if (IEVENT_RXACIF)
  { /* frame in buffer A */
    _DEBUGT("-RXA-");
    *whichbuffer = BUFA_FULL;
    return (RXAEFP); /* return number of bytes copied */
  }

  /* check FIFO buffer B flag */
  if (IEVENT_RXBCIF)
  { /* frame in buffer B */
    _DEBUGT("-RXB-");
    *whichbuffer = BUFB_FULL;
    return (RXBEFP); /* return number of bytes copied
    */
  }
  return 0; /* neither A or B buffer filled */
}

//===============================================
#else //RX_POLL_MODE

#endif  // RX_POLL_MODE


//===============================================
void EtherSend(void * databuf, tU16 datalen)
{

  tU16 ctr;
#if WORD_ACCESS
  tREG16 * pIn;
  tREG16 * pOut;
#else
  tU08 * pIn;
  tU08 * pOut;
#endif


  _DEBUGT("-TXSTART-");
  /* check & fix the length if incorrect
 */
#if EMAC_TX_SZ > 1514
  /* truncate if longer than Ethernet limit */
  if (datalen > 1514) datalen=1514;
#else
 /* truncate if longer than TX FIFO buffer limit */
  if (datalen > EMAC_TX_SZ) datalen=EMAC_TX_SZ;
#endif
  /* extend if shorter -> however this might be security flaw
  as we do not know what data are stored beyond our frame */
  if (datalen < 60) datalen=60;

#if WORD_ACCESS
  pIn=(tREG16 *) databuf;
#else
  pIn=(tU08 *) databuf;
#endif

  pOut=emacFIFOtx;
  /* copy input buffer to TX FIFO */

#if WORD_ACCESS
  if  ((datalen % 2) == 0)	 {
     for (ctr=datalen/2; ctr >0; ctr--)
     {
        *pOut=*pIn;
        pOut++;
        pIn++;
     }
  } else {
     for (ctr=(datalen+1)/2; ctr >0; ctr--)
     {
        *pOut=*pIn;
        pOut++;
        pIn++;
     }
  }

#else
  for (ctr=datalen; ctr >0; ctr--)
  {
    *pOut=*pIn;
    pOut++;
    pIn++;
  }
#endif

  //Wait for  TX idle
  while (TXCTS_TXACT == 1);

  /* set the offset where the last frame byte resides in FIFO */
  TXEFP=datalen-1;
  
  /* issue a transmit command */
  TXCTS_TCMD=TCMD_START;

  _DEBUGT( "-TXEND-");
}



//===============================================
void EtherOpen(tU08 miisetup,  /* mii preamble & clock setup */
               tU08 bufmap,    /* buffer configuration) */
               tU16 maxfl,   /* initial max.frame length for receive */
               void * pmacad, /* pointer to MAC address definition */
               tU08 control,  /* the acceptance mask*/
               tU16 etype, /* programmable ethertype (16bit value)*/
               tU08 rxmode,  /* reception mode settings */
               tU08 netctl   /* network control setup (see NETCT_X)*/
                 )    {
                 
  tU08 ctr;
  tU16 * pIn;
  tMACADStr * pInMAC = (tMACADStr *)&MACAD2;  
  
  _DEBUGT("EtherOpen(start)\n\r");
  
  /* do EMAC software reset */
  SWRST = SWRST_MACRST_MASK;

  /* wait a while */
  for (ctr=16; ctr >0; ctr--);

  /* setup MDC clock */
  MCMST_MDCSEL=miisetup;
  _DEBUGT("mdcsel=");_DEBUGC(miisetup);

  /* setup FIFO memory configuration */
  BUFCFG_BUFMAP=bufmap;
  _DEBUGT("; bufmap=");_DEBUGC(bufmap);
  
  /* setup max. reception frame length */
  BUFCFG_MAXFL=maxfl;
  _DEBUGT("; maxfl=");_DEBUGI(maxfl);
  
  /* set hardware address */
  _DEBUGT("\n\rMAC ADDR");
  pIn=(tU16 *)pmacad;
  for (ctr=0; ctr < sizeof(tMACADStr)/2; ctr++)
  {
    pInMAC->Word[ctr] = *pIn;
    _DEBUGI(*pIn);
    pIn++;
  }
  _DEBUGNL;
  
  EtherType(control, etype);
  
  /* setup the reception mode */
  RXCTS=rxmode;
  _DEBUGT("rxmode=");_DEBUGC(rxmode);
#ifdef ETH_DEBUG
  if (rxmode & RXCT_RFCE) _DEBUGT("=RFCE |");
  if (rxmode & RXCT_PROM) _DEBUGT(" PROM |");
  if (rxmode & RXCT_CONMC) _DEBUGT(" CONMC |");
  if (rxmode & RXCT_BCREJ) _DEBUGT(" BCREJ");  
#endif

  /* and finally network control */
  EmacControl(netctl);

  /* after that the EMAC can be enabled */
  EmacEnable();

  _DEBUGT("\n\rEtherOpen(end)\n\r");
}


//===============================================
void EtherClose(void)
{
  _DEBUGT("EtherClose\n\r");
  /* disable EMAC */
  EmacDisable();
  /* mask all EMAC interrupts */
  IMASK=0;
}

//===============================================
void EmacDisable(void)
{
  /* disable EMAC */
  NETCTL_EMACE = 0;
}

//===============================================
void EmacEnable(void)
{
  /* Enable EMAC */
  NETCTL_EMACE = 1;
}

//===============================================
void EmacControl(tU08 netctl)
{
  /* Enable EMAC */
  NETCTL=netctl;
  _DEBUGT("\n\rnetctl"); _DEBUGC(netctl);
#ifdef ETH_DEBUG
  if (netctl & NETCT_ESWAI) _DEBUGT("= ESWAI |");
  if (netctl & NETCT_EXTPHY) _DEBUGT(" EXTPHY |");
  if (netctl & NETCT_MLB) _DEBUGT(" MLB |");
  if (netctl & NETCT_FDX) _DEBUGT(" FDX");
#endif
}

//===============================================
#define CRC32_POLY      0x04c11db7UL
#define SET_MCAST_LIST  0x01
#define SET_ALL_MCAST   0x02

void EtherIoctl(tU08 flag, void * optionPtr, tU08 optionLen)
{

    tU32               calcCRC;
    tU08               currByte;
    tU08               Byte, bit;
    tU32               hashEntry;
    tU08             * multiAddr;
    tU16               logicalAddrFilter[4];
    tMCHASHStr       * pHASH = (tMCHASHStr*)&MCHASH3;
    _DEBUGT("EtherIoctl(start)\n\r");

/* Setup our list of multicast addresses to receive.		  */
        if (flag & SET_MCAST_LIST)
        {
            _DEBUGT("SET_MCAST_LIST\n\r");
/* Clear the address filter (since this IOCTL call will add all the
 * entries we need.  */
            logicalAddrFilter[0] = 0;
            logicalAddrFilter[1] = 0;
            logicalAddrFilter[2] = 0;
            logicalAddrFilter[3] = 0;

/* Get the first address */
            multiAddr = (tU08 *) optionPtr;

            while (optionLen-- > 0)
            {
/* Initialize the calculated CRC (with all ones) */
                calcCRC = 0xffffffffUL;

/* For all the bytes in the (6 byte) address */
                for (Byte=0;Byte<6;Byte++)
                {
                    currByte = multiAddr[Byte];
/* For each bit in the current byte */
                    for (bit=0;bit<8;bit++)
                    {
/* Shift the calculated CRC left by one */
                        calcCRC <<= 1;
/* If the current bit is one... */
                        if ((currByte >> bit) & 0x01)
                        {
/* ... XOR the calculated CRC with the CRC-32 polynomial */
                            calcCRC ^= CRC32_POLY;
                        }
                    }
                }

/* Get the most significant 6 bits from the calculated CRC */
                hashEntry = (calcCRC & 0xfc000000UL) >> 26;

/* Decode the above number and set the appropriate bit in the EMAC logical
 * address filter */
                logicalAddrFilter[(tU08) (hashEntry >> 4)] |=
                    1 << ((tU08) (hashEntry % 16));
                multiAddr += 6;
            }
            for (currByte=3; currByte > 0; currByte--)
            {
              pHASH->Word[currByte]=logicalAddrFilter[currByte];
            }
        }
/* Set the EMAC to receive all multicast packets. */
        if (flag & SET_ALL_MCAST)
        {
            _DEBUGT("SET_ALL_MCAST\n\r");
            MCHASH0=0xffff;
            MCHASH1=0xffff;
            MCHASH2=0xffff;
            MCHASH3=0xffff;
        }
        _DEBUGT("EtherIoctl(end)\n\r");
}



//===============================================
void EtherGetPhysAddr(void * ethaddr)		 {

  tU08 ctr;
  tU16 * peth;
  tMACADStr * pethReg = (tMACADStr *)&MACAD2;

  _DEBUGT("EtherGetPhysAddr");
  peth=ethaddr;
  for (ctr=0; ctr < sizeof(tMACADStr)/2; ctr++)
  {
    *peth=pethReg->Word[ctr]; /* copy MAC address, word after word */
    _DEBUGI(*peth);
    peth++;
  }
  _DEBUGNL;
}


//===============================================
void EtherType(tU08 control, tU16 etype)
{
  _DEBUGT("EtherType = ");
  /* setup the ethertype control register */
  ETCTL=control;
  _DEBUGC(control);
#ifdef ETH_DEBUG
  if (control & T_PET)  _DEBUGT("= PET |");
  if (control & T_EMW)  _DEBUGT("EMW |");
  if (control & T_IPV6) _DEBUGT("IPV6 |");
  if (control & T_ARP)  _DEBUGT("ARP |");
  if (control & T_IPV4) _DEBUGT("IPV4 |");
  if (control & T_IEEE) _DEBUGT("IEEE ");
#endif

  /* setup the programmable ethertype */
  _DEBUGT(";  Programmable etype = ");_DEBUGI(etype);_DEBUGNL;
  ETYPE=etype;
}



//===============================================
void EtherAbortTx(void)
{
  _DEBUGT("EtherAbortTX\n\r");
  TXCTS_TCMD=TCMD_ABORT;
}


//===============================================
tU16 EtherPause(tU08 ptrc, tU16 ptime)
{

  _DEBUGT("EtherPause(start)\n\r");
  TXCTS_PTRC = ptrc;
  if (ptrc)
  {
    _DEBUGT("ptrc=1 (send pause)");
    PTIME=ptime;
    while (TXCTS_TXACT == 1);
   	TXCTS_TCMD=TCMD_PAUSE;			//send pause
  }
  else
  {
    _DEBUGT("ptrc=0 (read ptime) ");
    ptime=PTIME; /* return current PAUSE counter value */
  }
  _DEBUGT(" ptime = "); _DEBUGI(ptime); _DEBUGT("EtherPause(end)\n\r");
  return ptime;
}

//===============================================
void EtherOtherTx(tU08 txpar)
{
  _DEBUGT("EtherOtherTx");
  TXCTS_PTRC = (txpar & TXCT_PTRC) ? 1:0;
#ifdef ETH_DEBUG
  if (TXCTS_PTRC) _DEBUGT(" PTRC");
#endif

  if (!TXCTS_TXACT)
  {
    TXCTS_SSB= (txpar & TXCT_SSB) ? 1 : 0;
#ifdef ETH_DEBUG
  if (TXCTS_SSB) _DEBUGT(" SSB");
#endif
  }
  else
  {
    _DEBUGT(" TX in progress - SSB not changed");
  }
}

//===============================================
void EtherStartFrameTransmission(tU16 datalen)
{

  datalen = datalen +14;

  _DEBUGT("-TXSTART-");
  /* check & fix the length if incorrect */
#if EMAC_TX_SZ > 1514
  /* truncate if longer than Ethernet limit */
  if (datalen > 1514) datalen=1514;
#else
  /* truncate if longer than TX FIFO buffer limit */
  if (datalen > EMAC_TX_SZ) datalen=EMAC_TX_SZ;
#endif
  /* extend if shorter -> however this might be security flaw
  as we do not know what data are stored beyond our frame */
  if (datalen < 60) datalen=60;

  //Wait for  TX idle
  while (TXCTS_TXACT == 1);

  /* set the offset where the last frame byte resides in FIFO */
  TXEFP=datalen-1;
  
  /* issue a transmit command */
  TXCTS_TCMD=TCMD_START;

  _DEBUGT( "-TXEND-"); 
}


//=======================================================================
//SW LED control 
#if USE_EXTBUS
void  ExternalBusCfg()  {
   //Change bus clock to external bus 16 Mhz maximum
  CLKSEL=0;
  CLKSEL_PLLSEL = 0;                   /* Select clock source from XTAL */
  PLLCTL_PLLON = 0;                    /* Disable the PLL */
  SYNR = 8;                           /* Set the multiplier register */
  REFDV = 13;                          /* Set the divider register */
  PLLCTL = 192;
  PLLCTL_PLLON = 1;                    /* Enable the PLL */
  while(!CRGFLG_LOCK);                 /* Wait */
  CLKSEL_PLLSEL = 1;                   /* Select clock source from PLL */   
  
  //Configure to External Bus Mode
  //The following must not use BSET instructions. 
  RDRIV = 0x00;
  PEAR   = 0x0C;      // ((LSTRE|RDWE)&~NECLK)
  EBICTL = 0x01;      // Enable clock stretching (ESTR)
  MISC   = 0x05;      // (~EXSTR1+EXSTR0+~ROMHM+ROMON)
  MODE   = 0xE2;      // (MODC+MODB+MODA+EMK+~EME)   
}
#endif


//=======================================================================
//SW LED control 
#if USE_SWLED
void  UseSWLedRun()  {
  LEDcounter = LEDcounter +1;  
  if (LEDcounter ==  9500) {
     LEDcounter = 0; 
  
#if  ACTLED 
     PTL_PTL0  = 1;			 //Turn off ACTLED   
#endif 
     
#if  COLLED  
     PTL_PTL4  = 1;			 //Turn off COLLED   
#endif 
  }
}
#endif


//==========================================================================
// NE64 Interrupts 
//==========================================================================
#pragma CODE_SEG NON_BANKED
//=======================================================================
///EPHY ISR - Type of EPHY interrupt detemined by MII read of PHY_REG_IR register
//=======================================================================
interrupt void ephy_isr(void)
{
  tU16 mymrdata, isr_read, temp, temp2;
  tU16 none_of_these;
	 temp=0;
	 temp2=0;
	none_of_these = 0;
  _DEBUGT("\r\n***EPHY_ISR\r\n ");

  //@@@@@@@@@@@@@@@@
  //STEP1: PHY interrupt flag clearing.	Read PHY_REG_IR to determine PHY intterrupt
  // Need to read MII Inter. register 22 before clearing  EPHYIF
  //@@@@@@@@@@@@@@@@
  while ( !(MIIread(PHY_ADDRESS, PHY_REG_IR, &isr_read)) );

  //@@@@@@@@@@@@@@@@
  //STEP2: Process PHY interrupt register 0x10 (PHY_REG_IR) contenets
  //handlers for different interrupts	 flags
  //@@@@@@@@@@@@@@@@
  _DEBUGT(" \r\nPHY Interrupt:\r\n"); _DEBUGT(" =================\r\n");

#if AUTO_NEG
  //***********************
  //Acknowledge Bit Received
  //***********************
  if ((isr_read & PHY_R16_ACKR) == PHY_R16_ACKR)		 {
     _DEBUGT("  ###PHY_R16_ACKR=ACK BIT RX###\r\n ");
     none_of_these = none_of_these + 1;
     //code here
  }

  //***********************
  //Link Partner Page Received
  //***********************
   if ((isr_read & PHY_R16_PGR) == PHY_R16_PGR)		 {
     _DEBUGT("  ###PHY_R16_PGR=LINK PARTERN PAGE###\r\n ");
     none_of_these = none_of_these + 1;

     //code here
     //Just checking what link partners ablility is!!!!!!! and Expansion Register
     while ( ! (MIIread(PHY_ADDRESS, PHY_REG_ANLPAR, &mymrdata)) );
     while ( ! (MIIread(PHY_ADDRESS, PHY_REG_ER, &mymrdata)) );

     _DEBUGNL;
  }

  //***********************
  //Auto-Negotiation Changed Enable
  //***********************
  if ((isr_read & PHY_R16_ANC) == PHY_R16_ANC)		 {

     _DEBUGT("  ###PHY_R16_ANC=AUTONEG CHANGE###\r\n ");
     none_of_these = none_of_these + 1;

     //Read Proprietary Status Register (PSR) for status
     while ( !(MIIread(PHY_ADDRESS, PHY_REG_PSR, &mymrdata))    );

     //CHECK PSR:Is auto_neg complete?
     if ((mymrdata & PHY_R17_ANNC) ==  PHY_R17_ANNC) {
     
          //AUTONEG COMPLETED
  	      _DEBUGT("\r\n  -AUTONEG COMPLETED ");

         //CHECK PSR: Was a commom mode found?
         if ((mymrdata & PHY_R17_ANCM) == PHY_R17_ANCM ) _DEBUGT(" - &&&NO COMMON_MODE&&&\r\n");
         else _DEBUGT(" &&&COMMON_MODE&&&\r\n");

         //CHECK PSR: Duplex (verify/set EMAC duplex resolution
      	 //Use temp as temp to save duplex setting
      	 temp = 33;
         if ((mymrdata & PHY_R17_DPM) == PHY_R17_DPM ) {
          		//Set EMAC to FULL Duplex
              _DEBUGT(" ###AUTONEG:SET EMAC Full Duplex###\r\n");
          		EmacDisable();
      				EmacControl(NETCTL | NETCT_FDX);
          		EmacEnable();
          	  //Use temp as temp to save duplex setting
          	  temp = 55;
         }
         else {
          		//Set EMAC to HALF Duplex
              _DEBUGT("  ###AUTONEG:SET EMAC Half Duplex###\r\n");
          		EmacDisable();
      				EmacControl(NETCTL & ~NETCT_FDX);
          		EmacEnable();
          	  //Use temp as temp to save duplex setting
          	  temp = 11;
         }
         //Read PHY_REG_ANLPAR register to check if xflow abitily 
         while ( !(MIIread(PHY_ADDRESS, PHY_REG_ANLPAR, &mymrdata) )   );
#if XFLOWC
         if (  ((mymrdata & PHY_R5_FCTL) == PHY_R5_FCTL) && (temp == 55)) {
                gotxflowc = 1;  _DEBUGT("<<PAUSE RESOLVED>>\r\n");
             }
             else {
                gotxflowc = 0;  _DEBUGT("<<NO PAUSE>>\r\n");
             }
#endif	 //#if XFLOWC
         _DEBUGNL;
     } //if ((mymrdata & PHY_R17_ANNC) ==  PHY_R17_ANNC)
     else {
     //AUTONEG NOT COMPLETED
  	 _DEBUGT("\r\n AUTONEG NOT COMPLETED ");
     }
  }

#endif //#if AUTO_NEG


  //***********************
  //Link Changed
  //***********************

  if ((isr_read & PHY_R16_LKC) == PHY_R16_LKC)		 {
     _DEBUGT("  ###PHY_R16_LKC=LINK CHANGE###");
     none_of_these = none_of_these + 1;

     //Read Proprietary Status Register (PSR) for status
     while ( !(MIIread(PHY_ADDRESS, PHY_REG_PSR, &mymrdata)) );

     //CHECK PSR:Is link down???
     if ((mymrdata & PHY_R17_LNK) == PHY_R17_LNK)  {

         //No link present
         gotlink = 0;
         _DEBUGT("@@@@LINK IS DOWN@@@@\r\n ");
         
//Restart Autoneg is link is down
#if AUTO_NEG
         //Read EPHY control register
         while ( !(MIIread(PHY_ADDRESS, PHY_REG_CR, &mymrdata)) );
         _DEBUGT("@@@READ PHY_REG_CR WHEN LINK DOWN@@@\r\n");	 

         //Write EPHY control register to set and restart auto negotiation
         _DEBUGT("  \r\n@@@@SET AND RESTART AUTONEG@@@@\r\n ");
         while ( !(MIIwrite(PHY_ADDRESS, PHY_REG_CR, mymrdata | PHY_R0_ANE | PHY_R0_RAN ))  );
#endif //#if AUTO_NEG
#if USE_SWLED

#if   ACTLED
  PTL_PTL0 = 1; //turn off LED
#endif
#if   LNKLED
  PTL_PTL1 = 1; //turn off LED
#endif
#if   SPDLED
  PTL_PTL3 = 1; //turn off LED
#endif
#if   DUPLED
  PTL_PTL3 = 1; //turn off LED
#endif
#if   COLLED
  PTL_PTL4 = 1; //turn off LED
#endif

#endif
     }
     else
     {
         //No link present
         gotlink = 1;
         _DEBUGNL;_DEBUGT("@@@@LINK IS UP@@@@\r\n ");_DEBUGNL;
#if USE_SWLED
#if LNKLED
         PTL_PTL1 = 0; //turn LNKLED on
#endif
         //Read Proprietary Status Register (PSR) for status
         while ( !(MIIread(PHY_ADDRESS, PHY_REG_PSR, &mymrdata))    );

         //CHECK PSR:DUP?
#if DUPLED
         if ((mymrdata & PHY_R17_DPM) == PHY_R17_DPM ) {
           PTL_PTL3 = 0; //turn DUPLED on	 (Full Duplex)
         } else {
           PTL_PTL3 = 1; //turn DUPLED off (Half Duplex)
         }
#endif         
         //CHECK PSR:SPD?
#if SPDLED
         if ((mymrdata & PHY_R17_SPD) == PHY_R17_SPD ) {
            PTL_PTL2 = 0; //turn SPDLED on (100 Mbps)
         } else {
            PTL_PTL2 = 1; //turn SPDLED off (10 Mbps)
         }
#endif
#endif

   
     }
  }

  //***********************
  //Parallel Detect Fault Enable
  //***********************
  if ((isr_read & PHY_R16_PDF) == PHY_R16_PDF)		 {
     _DEBUGT("  ###PHY_R16_PDF = PARALLEL DETECTION FAULT###\r\n ");
     none_of_these = none_of_these + 1;

#if AUTO_NEG_TIMEOUT
 
    //Read PHY Control Register 0
    while ( !(MIIread(PHY_ADDRESS, PHY_REG_CR, &mymrdata)) );

    //Set temp2 to adjust EPHY Duplex to HALF duplex for as required by PARALLEL DETECTION
    _DEBUGT("***ADJUST EPHY and EMAC TO HALF-DUPLEX***\r\n");		 
    temp2 = mymrdata & ~PHY_R0_DPLX;    

 		//Set EMAC to HALF Duplex
 		EmacDisable();
		EmacControl(NETCTL & ~NETCT_FDX);
 		EmacEnable();
 		
//Set temp2 to adjust EPHY Speed MANUALLY 
#if SPEED100_P
    temp2 = temp2 | PHY_R0_DR;		//Set SPEED100
#else                   //ELSE SPEED100
    temp2 = temp2 & ~PHY_R0_DR;		//Set SPEED10
#endif	                //SPEED100

    //Set temp2 to Disable EPHY Auto negotiation
    temp2 = temp2 & ~PHY_R0_ANE;    

    //Write temp2 settings to EPHY Config Register 
    _DEBUGT("  ***DISABLE AUTONEG AND FIX SPEED?DUPLEX***\r\n");		 
    while ( !(MIIwrite(PHY_ADDRESS, PHY_REG_CR, temp2))    );

#endif	                //AUTO_NEG_TIMEOUT
      
  }

  //***********************
  //Remote Fault Interrupt Enable
  //***********************
  if ((isr_read & PHY_R16_RMTF) == PHY_R16_RMTF)		 {
     _DEBUGT("  ###PHY_R16_RMTF=REMOTE FAULT###\r\n ");
     none_of_these = none_of_these + 1;
    //code here
  }

  //***********************
  //Jabber Interrupt Enable
  //***********************
  if ((isr_read & PHY_R16_JABI) == PHY_R16_JABI)		 {
     _DEBUGT("  ###PHY_R16_JABI=JABBER###\r\n ");
     none_of_these = none_of_these + 1;
    //code here
  }

  //***********************
  if (none_of_these == 0) _DEBUGT("  - UNKNOWN PHY INT\r\n ");
  //***********************

  //@@@@@@@@@@@@@@@@
  //STEP 3: Clear Flag
  //@@@@@@@@@@@@@@@@
  EPHYSR = EPHYSR_EPHYIF_MASK;        /* Clear the Ephy interrupt flag */
  _DEBUGT("\r\n =================\r\n"); _DEBUGT("***EPHYisr_END");

}

//=======================================================================
///RX flow control ISR
//=======================================================================
interrupt void emac_rx_fc_isr(void)
{
  _DEBUGT("\r\n***EMAC_RX_XFLOW_ISR");
  IEVENT = IEVENT_RFCIF_MASK; /* Clear the flag in Emac */
  _DEBUGT("***isr_END");

  }

//=======================================================================
///Babbling Receive Error ISR
//=======================================================================
interrupt void emac_b_rx_error_isr(void)
{
  _DEBUGT("\r\n***EMAC_RX_BABBLE_ISR");
  IEVENT = IEVENT_BREIF_MASK; /* Clear the flag in Emac */
  _DEBUGT("***isr_END");

#if (DELETE_BFRAMES && ZERO_COPY)
         if (IEVENT & IEVENT_RXACIF_MASK)
         {
            IEVENT |= IEVENT_RXACIF_MASK;
         }

         if (IEVENT & IEVENT_RXBCIF_MASK)
         {
            IEVENT |= IEVENT_RXBCIF_MASK;
         }
#endif 
}

//=======================================================================
///Receive Error ISR
//=======================================================================
interrupt void emac_rx_error_isr(void)
{
  _DEBUGT("\r\n***EMAC_RX_ERROR_ISR");
  IEVENT = IEVENT_RXEIF_MASK; /* Clear the flag in Emac */
  _DEBUGT("***isr_END");

}

//=======================================================================
///RXAOIF — Receive Buffer A Overrun ISR
//=======================================================================
interrupt void emac_rx_b_a_o_isr(void)
{
  _DEBUGT("\r\n***EMAC_RXA_ORUN_ISR");
  IEVENT = IEVENT_RXAOIF_MASK; /* Clear the flag in Emac */
  _DEBUGT("***isr_END");

}

//=======================================================================
///RXAOIF — Receive Buffer B Overrun ISR
//=======================================================================
interrupt void emac_rx_b_b_o_isr(void)
{
  _DEBUGT("\r\n***EMAC_RXB_ORUN_ISR");
  IEVENT = IEVENT_RXBOIF_MASK; /* Clear the flag in Emac */
  _DEBUGT("***isr_END");

}

//=======================================================================
///Valid Frame Reception to Receive Buffer A Complete ISR
//=======================================================================
interrupt void emac_rx_b_a_c_isr(void)
{
#if RX_POLL_MODE
    //Polled mode used
#else
    //IRQ mode used
    _DEBUGT("\r\n***EMAC_RXA_GOOD_ISR");
     (void)NE64Receive (emacFIFOa, RXAEFP, IEVENT & (IEVENT_RXACIF_MASK));
    _DEBUGT("***isr_END");

#if (USE_SWLED && ACTLED)
    PTL_PTL0  = 0;			 //Turn on ACTLED
#endif    

#endif    /* #endif of RX_POLL_MODE */
}

//=======================================================================
///Valid Frame Reception to Receive Buffer B Complete ISR
//=======================================================================
interrupt void emac_rx_b_b_c_isr(void)
{

#if RX_POLL_MODE
    //Polled mode used
#else

    //IRQ mode used
    _DEBUGT("\r\n***EMAC_RXB_GOOD_ISR");
     (void)NE64Receive (emacFIFOb, RXBEFP, IEVENT & (IEVENT_RXBCIF_MASK));
    _DEBUGT("***isr_END");

#if (USE_SWLED && ACTLED)
    PTL_PTL0  = 0;			 //Turn on ACTLED
#endif  

#endif    /* #endif of RX_POLL_MODE */
}

//=======================================================================
///Management Transfer Complete ISR - MMCIF — MII Interrupt Flag
//=======================================================================
interrupt void emac_mii_mtc_isr(void)		 //MII complete
{
  //In polled mode bit is cleared in MIIread or MIIwrite routine
   _DEBUGT("\r\n***EMAC_MII_DONE_ISR");
   _DEBUGT("***isr_END");
}

//=======================================================================
///late collisions ISR - LCIF — Late Collision Interrupt Flag
//=======================================================================
interrupt void emac_lc_isr(void)
{
   _DEBUGT("\r\n***EMAC_LATE_COLL_ISR");
   IEVENT = IEVENT_LCIF_MASK; /* Clear the flag in Emac */
   _DEBUGT("***isr_END");

#if (USE_SWLED && COLLED)
    PTL_PTL4  = 0;			 //Turn on COLLED
#endif    
}

//=======================================================================
///excess collisions ISR - ECIF — Excessive Collision Interrupt Flag
//=======================================================================
interrupt void emac_ec_isr(void)
{
   _DEBUGT("\r\n***EMAC_EX_COLL_ISR");
   IEVENT = IEVENT_ECIF_MASK; /* Clear the flag in Emac */
   _DEBUGT("***isr_END");

#if (USE_SWLED && COLLED)
    PTL_PTL4  = 0;			 //Turn on COLLED
#endif    
}

//=======================================================================
///transmit complete ISR - TXCIF — Frame Transmission Complete Interrupt Flag
//=======================================================================
interrupt void emac_f_tx_c_isr(void)
{
   _DEBUGT("\r\n***EMAC_TX_COMPLETE_ISR");
   IEVENT = IEVENT_TXCIF_MASK; /* Clear the flag in Emac */
   _DEBUGT("***isr_END");

#if (USE_SWLED && ACTLED)
        PTL_PTL0  = 0;			 //Turn on ACTLED
#endif    

}
#pragma CODE_SEG DEFAULT


