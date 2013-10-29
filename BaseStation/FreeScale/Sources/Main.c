 /**************************************************************************                      
 *							 
 *       Copyright (C) 2003 Freescale Semiconductor, Inc. 
 *           and 2000-2002 Viola Systems Ltd. 
 *       All Rights Reserved
 *				 
 * File Name      : Main.c
 * Project Name   : Connector_App.mcp
 * Description    : This file contains main() for the Connector_App demo 
 *                    code for the MC9S12NE64.
 *                  It does initializations and calls functions in the
 *                    Connector_App.c application code. The Connector_App.c 
 *                    file contains code for IO communication and UDP
 *                    protocol functions on the MC9S12NE64.
 * 
 * *** NOTE: This project is for demonstration purposes only. It excludes
 *             portions of the complete OpenTCP Stack for other protocols, 
 *             such as http, bootp, dns, etc. The complete version of this 
 *             stack is also included in the MC9S12NE64 Resource CD.
 *                 
 * *** NOTE: All header files have been removed from the Connector_App.mcp
 *             project due to the 32-file limit of CodeWarrior Special  
 *             Edition. However, all the header files are included in your 
 *             working folder and can be viewed by highlighting it's name 
 *             in a source file, right clicking, and choosing "Find and 
 *             Open File..." You may also just type the name of the file 
 *						 in any source file and do this.
 *
 * Version : 1.1
 * Date    : 07/21/04
 *
 ***************************************************************************/



#include "ne64api.h"
#include "ne64config.h"
#include "ne64debug.h"
#include "ne64driver.h"
#include "mBuf.h"
#include "parser.h"
#include "debug.h"
#include "datatypes.h"
#include "timers.h"
#include "Connector_App.h"
//#include "timerM.h"
#include "system.h"
#include "ethernet.h"
#include "arp.h"
#include "icmp.h"
#include "ip.h"
#include "udp.h"  
//#include "sci.h"
#include "nvm.h"

#include "address.h"

#include "MC9S12NE64.h"

#include "rf24g-freescale.h"/**/

/* Including used modules for compiling procedure */

/* Network Interface definition. Must be somewhere so why not here? :-)*/
struct netif localmachine;

extern void RTI_Init (void);
extern void RTI_Enable (void);
extern void porth_isr_handler (void);
extern void timer0_isr_handler (void);
extern int interrupt_counter;
extern void pullData(void);


extern	tU08	gotlink; 
#define MAX_CMD_SIZE 100

#if USE_SWLED
tU16 LEDcounter=0;
#endif

#pragma LINK_INFO DERIVATIVE "1"
//============================================================
tU08 OldSwitchValue=255;
tU16 Pot=0;
tU16 OldPot=1050;
tU08 OldB1=255; 
tU08 OldB2=255;
UINT8 cmdinterface = 0;
char scibuf[MAX_CMD_SIZE];


void sci1_interrupr_handler (void);
//============================================================
#pragma CODE_SEG NON_BANKED
interrupt void PortHInterrupt (void)
{			   
  porth_isr_handler();
}

interrupt void Timer4Interrupt(void) {
  timer4_isr_handler (); 
}

interrupt void Timer5Interrupt(void) {
  timer5_isr_handler (); 
}

interrupt void Timer6Interrupt(void) {
  timer6_isr_handler (); 
}

interrupt void Timer7Interrupt(void) {
  timer7_isr_handler (); 

}

interrupt void SCI1Interrupt(void) {
  PTG_PTG0 = 1;
  //sci1_interrupr_handler ();

} 
#pragma CODE_SEG DEFAULT

void sci1_interrupr_handler (void){
  INT16 slen;
  char c;
  
  c=SCIDRL; 
  SCIsend("ddd");
 
  return;
  
  slen = 0;
  slen = SCIrecv(scibuf);
  SCIsend("ddd");
  if(slen) {       //data input
      SCIsend(scibuf);
     parserData(scibuf, slen); 
    }   
 }
//============================================================
//Initialize ATD
//============================================================
void ATD_init(void)
{
    ATDCTL2 =  ATDCTL2_ADPU_MASK | ATDCTL2_AFFC_MASK;
    ATDCTL3_S1C = 8;    // 8 ch seq. 
    ATDCTL3_FIFO = 0;    // no FIFO
    ATDCTL3_FRZ = 3;     // Freeze immediately in BDM  
    ATDCTL4 =  ATDCTL4_PRS2_MASK |ATDCTL4_PRS1_MASK | ATDCTL4_PRS0_MASK;
    ATDCTL4 = ATDCTL4 & ~ATDCTL4_SRES8_MASK; //10 bit
    ATDCTL5 = ATDCTL5_SCAN_MASK;
}


//============================================================
// Initialize Port for LEDs, Switch, and Buttons
//============================================================
void demoinit(void) 
 {
     //LEDS
    DDRG_DDRG0 = 1;
    DDRG_DDRG1 = 0;
 		PTG_PTG0 = 0;	//turn off		
 	//	PTG_PTG1 = 0;	//turn off		

    //SWITCH (RUN/LOAD)		 0:input
    //DDRG_DDRG4 = 0;

    //BUTTON2 
    
    //DDRH_DDRH4 = 0;
    PIEH_PIEH4 = 0;      //PIEH4 Interrupt Enable
   
 }


//============================================================
/* main */
//============================================================
void main(void)
{
  INT16 len;
  INT16 slen;
  UINT8 i =0;
  //UINT8 status[30];/**/
  UINT32 ts;
  int seq;
  
  interrupt_counter = 0;/**/

  /* System clock initialization */
  CLKSEL=0;
  CLKSEL_PLLSEL = 0;                   /* Select clock source from XTAL */
  PLLCTL_PLLON = 0;                    /* Disable the PLL */
  SYNR = 0;                           /* Set the multiplier register */
  REFDV = 0;                          /* Set the divider register */
  PLLCTL = 192;
  PLLCTL_PLLON = 1;                    /* Enable the PLL */
  while(!CRGFLG_LOCK);                 /* Wait */
  CLKSEL_PLLSEL = 1;                   /* Select clock source from PLL */

  INTCR_IRQEN = 0;                     /* Disable the IRQ interrupt. IRQ interrupt is enabled after CPU reset by default. */
	
	DDRG_DDRG5 = 1;
	PTG_PTG5 = 0;
	//DDRG_DDRG7 = 1;
	//PTG_PTG7 = 0;
	/* initialize processor-dependant stuff (I/O ports, timers...).
	 * Most important things to do in this function as far as the TCP/IP 
	 * stack concerns:
	 *  - initializing some timer so it executes decrement_timers
	 * 	on every 10ms (TODO: Throw out this dependency from several files
	 *	so that frequency can be adjusted more freely!!!)
	 *  - not mess too much with ports allocated for Ethernet controller
	 */
  //  _INIT_DEBUG();

    demoinit();

    ATD_init();


	//	Flash_Init(25000);
   	/* Set our network information. This is for static configuration.
     * if using BOOTP or DHCP this will be a bit different.
     */
   	/* IP address */
 	  localmachine.localip = *((UINT32 *)ip_address);
   	/* Default gateway */
   	localmachine.defgw   = *((UINT32 *)ip_gateway);
   	/* Subnet mask */
   	localmachine.netmask = *((UINT32 *)ip_netmask);

   	/* Ethernet (MAC) address */
   	localmachine.localHW[0] = hard_addr[0];
   	localmachine.localHW[1] = hard_addr[1];
   	localmachine.localHW[2] = hard_addr[2];
   	localmachine.localHW[3] = hard_addr[3];
   	localmachine.localHW[4] = hard_addr[4];
   	localmachine.localHW[5] = hard_addr[5];

	
	/* Init system services		*/    
	timer_pool_init();
  initTimerM();
 // SCIinit();	


    /* Initialize all buffer descriptors */
	mBufInit ();
	
	

  //initBuffer();
	/*interrupts can be enabled AFTER timer pool has been initialized */
    	
  /* Initialize all network layers	*/
  EtherInit();
  

  //Initialize required network protocols 	
  arp_init();
  (void) udp_init();
  udp_demo_init();
  //init_rf24g_parameter(27, 118, 101, 3, 1);	 //Init Sending

 
  
	/* main loop */
	//DEBUGOUT(">>>>>>>>>Entering to MAIN LOOP>>>>>>>>>\n\r");
  slen = 0;
  
  
  SPIinit();
   
 
  init_rf24g_parameter(27, 118, 101, 3, 0);	 //Init Sending
  init_rf24g_parameter(27, 118, 101, 3,1);	 //Init Receiving
  //SPIinit();
   ts =100000;
  
	//initializing RTI
	RTI_Init();/**/
	//RTI_Enable();/**/ moved to parser.c
 
	 // DDRG_DDRG4=1;
	for (;;)
	{
  
	  if (gotlink) {

      if(interrupt_counter >= 11) {
        set_debug_hi();
        interrupt_counter = 0;
        set_debug_low();
        pullData();
      }

	  	//set_debug_hi();
   		/* Try to receive Ethernet Frame	*/    	
   		if( NETWORK_CHECK_IF_RECEIVED() == TRUE ) {  		   		
   			switch( received_frame.protocol)
			  {
   				case PROTOCOL_ARP:
					  process_arp (&received_frame);
	    			break;
   				case PROTOCOL_IP:
   					len = process_ip_in(&received_frame);
  					if(len < 0)
     						break;
     				switch (received_ip_packet.protocol)
  					{
     						case IP_ICMP:
      						//set_debug_hi();
      						process_icmp_in (&received_ip_packet, len);
  							  //set_debug_low();
  							  break;
     						case IP_UDP:
                  //PTG_PTG1 = 1;
                  process_udp_in (&received_ip_packet,len);   							
                  //set_debug_low();
                  break;
     						default:
  	  						break;
    				}//end switch
       			break;
				  default:
   				  break;
			  }//end switch
			/* discard received frame */    		
   			NETWORK_RECEIVE_END();
   		}//end if

      arp_manage(); 
      
			//set_debug_low();
	  }//end if

	}
}
