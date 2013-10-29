/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : ne64config.h
 * Description    : This file contains configuration modes for NE64 start-up
 *
 * Version : 2.1
 * Date    : 02/04/04
 *
 *
 ******************************************************************************/


#ifdef ETHER_INIT_H
#else
#define ETHER_INIT_H

//============================================================
//Optimization
//============================================================
#define WORD_ACCESS   1			/**< Word Acess Mode. This mode allows word access to buffers instead of
                              *  byte acess to increase overall system preformance.                    */
#define ZERO_COPY     1     /**< Zero Copy Mode. Setting this mode not only can conserve RAM
                              *  but can also increase performance.  In this mode, no copy of the
                              *  recieve buffer is created, so the data is processed in the buffer     */
#define RX_POLL_MODE   0     /**< 1 = polling; Set to 0 to make RX interrupt driven >> Not implemented into Viola Stack */                         


//============================================================
//LINK SPEED/DUPLEX CONTROL
//============================================================
//Configure for manual or auto_neg configuration
#define AUTO_NEG     0			/**< 1 - enable AUTO_NEG / 0 - disable AUTO_NEG			 */

#if  AUTO_NEG

//define what I addvertise in auto negotiation
#define HALF100   1					/**< Configure mode that the device should advertise in auto negotiation (advertise=1)  */
#define FULL100   1					/**< Configure mode that the device should advertise in auto negotiation (advertise=1)  */
#define HALF10    1					/**< Configure mode that the device should advertise in auto negotiation (advertise=1) */
#define FULL10    1					/**< Configure mode that the device should advertise in auto negotiation (advertise=1) */

//auto neg_patch
#define AUTO_NEG_TIMEOUT   0	/**< 1 - NOT IMPLEMENTED			*/
#if     AUTO_NEG_TIMEOUT				  
#define SPEED100_P    1   /**< 1 - enable 100 MBps / 0 - enable 10MBps */
#endif		//AUTO_NEG_TIMEOUT

#else				//AUTO_NEG
#define SPEED100    1     /**< 1 - enable 100 MBps / 0 - enable 10 MBps */
#define FULL_DUPLEX 1     /**< 1 - enable full duplex / 0 - disable			 */

#endif			//AUTO_NEG


//============================================================
//Buffer Configuration
//============================================================
#define BUFMAP 4								 /**<User select BUFMAP based on application buffer requirements      */
#if BUFMAP > 4
#error Illegal FIFO buffer size
#endif
#if BUFMAP == 0
#define EMAC_RX_SZ 128					  /**<BUFMAP == 0      */
#define EMAC_TX_SZ 128					  /**<BUFMAP == 0      */
#elif BUFMAP == 1
#define EMAC_RX_SZ 256					  /**<BUFMAP == 1      */
#define EMAC_TX_SZ 256						/**<BUFMAP == 1      */
#elif BUFMAP == 2
#define EMAC_RX_SZ 512						/**<BUFMAP == 2      */
#define EMAC_TX_SZ 512						/**<BUFMAP == 2      */
#elif BUFMAP == 3
#define EMAC_RX_SZ 1024						/**<BUFMAP == 3      */
#define EMAC_TX_SZ 1024						/**<BUFMAP == 3      */
#elif BUFMAP == 4
#define EMAC_RX_SZ 1536						/**<BUFMAP == 4      */
#define EMAC_TX_SZ 1536						/**<BUFMAP == 4      */
#endif


//============================================================
//EMAC FILTERING CONTROL
//============================================================
//Address Filtering; RXMODE setting: PAUSE frame supported, Accept Unique, Brodcast, MultiCast
#define		BRODC_REJ	  0	        /**<  1 = All broadcast address frames are rejected.					 */
#define   CON_MULTIC 	0         /**<  1 = Multicast hash table is used for checking multicast addresses. */
#define   PROM_MODE		0         /**<  1 = All frames are received regardless of address.									 */

//Ethertype Control
#define ETYPE_PET   0 /**<  1 = accept Programmable Ethertype, 'etype' parameter is used */
#define ETYPE_EMW   0 /**<  1 = accept Emware Ethertype  */
#define ETYPE_IPV6  0 /**<  1 = accept Internet IP version (IPV6) Ethertype */
#define ETYPE_ARP   0 /**<  1 = accept Address Resolution Protocol (ARP) Ethertype */
#define ETYPE_IPV4  0 /**<  1 = accept Internet IP version 4 (IPV6) Ethertype */
#define ETYPE_IEEE  0 /**<  1 = accept IEEE802.3 Length Field Ethertype 	 */
#define ETYPE_ALL   1 /**<  1 = accept Accept all ethertypes. THIS OVERRIDES OTHER SETTINGS */

//Programable Ethertype
#define ETYPE_PRG	  0     /**< Enter Value if ETYPE_PET is set for filter target	 */

//Recieve maxiuim frame length																						 
#define RX_MAX_FL	        1536    /**< Recieve maxiuim frame length	 */
#define DELETE_BFRAMES    0				/**< set to 1 to delete packets larger the maxiuim frame length (babbling error)	 */

//============================================================
//PAUSE CONTROL
//============================================================
//Configure support for flow control in auto neg or manually
#define XFLOWC          0    /**< 1 - enable flow control in full dueplex / 0 - disable		*/
#define PAUSE_TIME      5    /**< Enter value for PAUSE duration parameter in units of slot times (512 bit times) */
#define SEND_PAUSE 1			/**<define for EtherPause function ptrc variable  */
#define READ_PTIME 0			/**<define for EtherPause function ptrc variable  */

//============================================================
//PHY config defines
//============================================================
#define PHY_ADDRESS     0						 /**< PHY address used by the MII serial management interface   */
#define BUS_CLOCK       25000000		 /**< Busclock setting set be the CRG/PLL   */

//============================================================
//LED SW control option (ADDED 061604)
//============================================================
#define USE_SWLED   1		  /**< 1 = use user software to drive EPHY status indicators on port L
                            *  0 = use EPHY hardware LED drive function to drive 5 EPHY status indicators*/

#if 	USE_SWLED
#define ACTLED		 1			/**<If USE_SWLED=1, use software to drive an EPHY activity LED */
#define LNKLED		 1			/**<If USE_SWLED=1, use software to drive an EPHY link LED */
#define SPDLED		 1			/**<If USE_SWLED=1, use software to drive an EPHY speed LED */
#define DUPLED		 1			/**<If USE_SWLED=1, use software to drive an EPHY duplex LED */
#define COLLED		 1			/**<If USE_SWLED=1, use software to drive an EPHY collision LED */
#else							
#define ACTLED		 0			//else define as zero to prevent warning message.
#define LNKLED		 0			//else define as zero to prevent warning message.
#define SPDLED		 0			//else define as zero to prevent warning message.
#define DUPLED		 0			//else define as zero to prevent warning message.
#define COLLED		 0			//else define as zero to prevent warning message.
#endif		//USE_SWLED

//============================================================
//External Bus Configuartion Option (ADDED 061604)
//============================================================
#define USE_EXTBUS   0	 /**< 1 = External Bus will be used.
                            *  Change PLL setting to Force bus clock configuration to maximum 16 MHz bus clock	 
                            *  Forces Configuration EPHY speed to 10 Mbps maximum */

//============================================================
//Mode for UNH IOL testing (Echo IEEE packets)
//============================================================
#define IEEE_PKT        0		/**< Mode for UNH IOL testing (Do not use for gerneral use)   */
#define ON_OFF_AUTONEG  0		/**< Mode for UNH IOL testing (Do not use for gerneral use)   */
#define READ_PHY_ID     0   /**< Mode for UNH IOL testing (Do not use for gerneral use)   */
#define READ_ALL_REGS   0   /**< Mode for UNH IOL testing (Do not use for gerneral use)   */

#endif