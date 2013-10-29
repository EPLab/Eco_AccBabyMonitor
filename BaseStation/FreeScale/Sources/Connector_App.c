/**************************************************************************                      
 *
 *       Copyright (C) 2003 Freescale Semiconductor, Inc. 
 *           and 2000-2002 Viola Systems Ltd. 
 *       All Rights Reserved
 *
 * File Name      : Connector_App.c
 * Project Name   : Connector_App.mcp
 * Description    : This file contains the application code using UDP 
 *                    protocol functions on the MC9S12NE64. It calls 
 *                    implementation code in udp.c.
 *
 * Version : 1.1
 * Date    : 7/21/04
 *
 ***************************************************************************/
 
/*
 *Redistribution and use in source and binary forms, with or without 
 *modification, are permitted provided that the following conditions 
 *are met:
 *
 *1. Redistributions of source code must retain the above copyright 
 *notice, this list of conditions and the following disclaimer.
 *
 *2. Redistributions in binary form must reproduce the above copyright 
 *notice, this list of conditions and the following disclaimer in the 
 *documentation and/or other materials provided with the distribution.
 *
 *3. The end-user documentation included with the redistribution, if 
 *any, must include the following acknowledgment:
 *	"This product includes software developed by Viola 
 *	Systems (http://www.violasystems.com/)."
 *
 *Alternately, this acknowledgment may appear in the software itself, 
 *if and wherever such third-party acknowledgments normally appear.
 *
 *4. The names "OpenTCP" and "Viola Systems" must not be used to 
 *endorse or promote products derived from this software without prior 
 *written permission. For written permission, please contact 
 *opentcp@opentcp.org.
 *
 *5. Products derived from this software may not be called "OpenTCP", 
 *nor may "OpenTCP" appear in their name, without prior written 
 *permission of the Viola Systems Ltd.
 *
 *THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED 
 *WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 *MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 *IN NO EVENT SHALL VIOLA SYSTEMS LTD. OR ITS CONTRIBUTORS BE LIABLE 
 *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 *WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
 *OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 *EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *====================================================================
 *
 *OpenTCP is the unified open source TCP/IP stack available on a series 
 *of 8/16-bit microcontrollers, please see <http://www.opentcp.org>.
 *
 *For more information on how to network-enable your devices, or how to 
 *obtain commercial technical support for OpenTCP, please see 
 *<http://www.violasystems.com/>.
 */
 

#include "debug.h"

#include "globalvariables.h"
#include "system.h"
#include "tcp_ip.h"
#include "parser.h"

#include "string.h"
#include "MOTTYPES.h"
#include "MC9S12NE64.h"
#include "Connector_App.h"

#include "rf24g-freescale.h"


/* The applications that use UDP must implement following function stubs			*/
/* void application_name_init (void) - call once when processor starts				*/
/* void application_name_run (void) - call periodically on main loop				*/
/* INT32 application_name_eventlistener (INT8, UINT8, UINT32, UINT16, UINT16, UINT16)	*/
/* - called by TCP input process to inform arriving data, errors etc 				*/

/* These will probably go to some include file */
void udp_demo_run(void);
INT32 udp_demo_eventlistener(INT8 , UINT8 , UINT32 , UINT16 , UINT16 , UINT16 );
INT16 parserData(char* buf, UINT16 datalen);
/** \brief Socket handle holder for this application
 *
 * This variable holds the assigned socket handle. Note that this application 
 * will reserve one UDP socket immediately and will not release it. For
 * saving resources, UDP sockets can also be allocated/deallocated 
 * dynamically.
 */
INT8 udp_demo_soch;

UINT8 udp_demo_senddata; /**< Used to trigger data sending */

#define UDP_DEMO_PORT	2001 /**< UDP_DEMO_RMTHOST_PRT number on which we'll work */

//#define UDP_DEMO_RMTHOST_IP	0xC0A80002	/**< Remote IP address this application will send data to 192.168.0.2*/
#define UDP_DEMO_RMTHOST_IP	0xC0A802C8	/**< Remote IP address this application will send data to  192.168.2.200*/



#define UDP_DEMO_RMTHOST_PRT	2001	/**< UDP_DEMO_RMTHOST_PRT number on remote server we'll send data to */

/* Internal function used for sending data to a predefined host */
void udp_demo_send(void);

void run_app(char **cmd);  

//============================================================
//============================================================
#define GAMEMODE  1
#define DEMOBOARD 1
#define MAX_CMD_SIZE 100
//#define CMD_BUFFER_SIZE 50

extern tU16 Pot;
extern tU16 OldPot;
extern tU08 OldSwitchValue;
extern tU08 OldB1;
extern tU08 OldB2;
extern UINT8 cmdinterface; 
signed char cvt[16]={ '0','1','2','3','4','5','6','7','8','9',
                      'A','B','C','D','E','F' };
signed char cvtd[10]={ '0','1','2','3','4','5','6','7','8','9'};

//============================================================
//============================================================
void ctoh (signed char * s, unsigned char c)  {
  *s= cvt[c / 16];
  s++;
  *s= cvt[c % 16];
}

//============================================================
//NEED TO MAKE THIS GENERIC FOR ANY SIZE DEC DIGIT
//============================================================
signed char* xxxxDEC_TO_ASCII(UINT16 c)	{
				
  signed char s[5];
  UINT16 divider;
  UINT8 leaddigit;
  UINT8 foundmsd;
  UINT8	 j;

  divider = 1000;
  j = 0;
  foundmsd = FALSE;
  //div 1000 
  leaddigit = (UINT8)(c / divider);
  if  (leaddigit == 0) {
    divider = divider/10;
  }
  else {
    s[j] = cvtd[leaddigit];
    c = c - leaddigit * divider;
    divider = divider/10;
    j=j+1;
    foundmsd = TRUE;
  }
  //div 100 
  leaddigit = (UINT8)(c / divider);
  if  ((leaddigit == 0) && (!foundmsd)) {
    divider = divider/10;	 
  }
  else {
    s[j] = cvtd[leaddigit];
    c = c - leaddigit * divider;
    divider = divider/10;
    j=j+1;
    foundmsd = TRUE;
  }
  //div 10 
  leaddigit = (UINT8)(c / divider);
  if  ((leaddigit == 0) && (!foundmsd)) {
    divider = divider/10;
  }
  else {
    s[j] = cvtd[leaddigit];
    c = c - leaddigit * divider;
    divider = divider/10;
    j=j+1;
    foundmsd = TRUE;
  }
  //div 1 
  leaddigit = (UINT8)(c / divider);
  s[j] = cvtd[leaddigit];
  j=j+1;
  s[j]=0;
  return s;

}


//============================================================
//============================================================
void check_switch() {

 		UINT8	temp, i;
		UINT16 datalen;

			datalen=13;
      i = 0;       net_buf[UDP_APP_OFFSET+i]='c';
      i = 1;       net_buf[UDP_APP_OFFSET+i]='o';
      i = 2;       net_buf[UDP_APP_OFFSET+i]='m';
      i = 3;       net_buf[UDP_APP_OFFSET+i]='m';
      i = 4;       net_buf[UDP_APP_OFFSET+i]='R';
      i = 5;       net_buf[UDP_APP_OFFSET+i]='C';
      i = 6;       net_buf[UDP_APP_OFFSET+i]='V';
      i = 7;       net_buf[UDP_APP_OFFSET+i]='@';
      i = 8;       net_buf[UDP_APP_OFFSET+i]='e';
      i = 9;       net_buf[UDP_APP_OFFSET+i]='q';
      i = 10;      net_buf[UDP_APP_OFFSET+i]='@';
      i = 11;			 net_buf[UDP_APP_OFFSET+i]='s';
      i = 12;
      if (PTG_PTG4 == 0) {
            net_buf[UDP_APP_OFFSET+i]='0';
      			temp = FALSE;
      }
      else {
            net_buf[UDP_APP_OFFSET+i]='1';
      			temp = TRUE;
      }
		  if (OldSwitchValue !=  temp)
		       temp = temp; //nothin
		      //udp_send(udp_demo_soch,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);
      OldSwitchValue =  temp;
}



//============================================================
/* Initialize resources needed for the UDP socket application */
//============================================================
void udp_demo_init(void){

	DEBUGOUT("Initializing UDP demo client\r\n");

	/* Get socket:
	 * 	0 - for now not type of service implemented in UDP
	 * 	udp_echo_eventlistener - pointer to listener function
	 *	UDP_OPT_SEND_CS|UDP_OPT_CHECK_CS - checksum options. Calculate
	 *		checksum for outgoing packets and check checksum for
	 *		received packets.
	 */
	udp_demo_soch=udp_getsocket(0 , udp_demo_eventlistener , UDP_OPT_SEND_CS | UDP_OPT_CHECK_CS);
		UDPsoc = udp_demo_soch; 
	if(udp_demo_soch == -1){
		DEBUGOUT("No free UDP sockets!! \r\n");
		RESET_SYSTEM();
	}
	
	/* open socket for receiving/sending of the data on defined UDP_DEMO_RMTHOST_PRT*/
	(void)udp_open(udp_demo_soch,UDP_DEMO_PORT);
	
	/* for now no data sending */
	udp_demo_senddata=0;
  tm_used[0] = 0;
  tm_used[1] = 0;
  tm_used[2] = 0;
  tm_used[3] = 0;
  cmd_len[0] = 0;
  cmd_len[1] = 0;
  cmd_len[2] = 0;
  cmd_len[3] = 0;
 
}


//============================================================
/*
 * Event listener invoked when TCP/IP stack receives UDP datagram for
 * a given socket. Parameters:
 * - cbhandle - handly of the socket this packet is intended for. Check it
 *	just to be sure, but in general case not needed
 * - event - event that is notified. For UDP, only UDP_EVENT_DATA
 * - UDP_DEMO_RMTHOST_IP - IP address of remote host who sent the UDP datagram
 * - UDP_DEMO_RMTHOST_PRT - UDP_DEMO_RMTHOST_PRT number of remote host who sent the UDP datagram
 * - buffindex - buffer index in RTL8019AS allowing you to read 
 * 	received data more than once from Ethernet controller by
 *	invoking NETWORK_RECEIVE_INITIALIZE(buffindex) and then start
 *	reading the bytes all over again
 */ 
//============================================================

INT32 udp_demo_eventlistener (INT8 cbhandle, UINT8 event, UINT32 ipaddr, UINT16 port, UINT16 buffindex, UINT16 datalen) {
  int i, j;
  int val;
  static char counter = 0;
  int len;
  INT16 result;
  ipaddr = 0;
  buffindex = 0;

	if(cbhandle!=udp_demo_soch){
  		DEBUGOUT("Not my handle!!!!");
	  	return (-1);
	}
	switch(event)
	{
		case UDP_EVENT_DATA:

set_debug_hi();/**/
			/* read data to transmit buffer and send response*/
			if(datalen>(NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET))
			  datalen=NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET;
			  RECEIVE_NETWORK_BUF(net_buf+UDP_APP_OFFSET,datalen);
			  len = datalen-3;
			  val = 0;
			  val = net_buf[UDP_APP_OFFSET+1]*256 +net_buf[UDP_APP_OFFSET+0]; 
			  cmdinterface = 0;
		    result = parser(&net_buf[UDP_APP_OFFSET+3],len, val);
set_debug_low();/**/

			break;
		default:
			/* should never get here */
			DEBUGOUT("Unknown UDP event :-(");
			break;
	}
	return 0;
}

INT16 parserData(char* databuf, UINT16 datalen) 
{
    UINT32 val = 0;
    UINT16 len;
    UINT16 i, j;
    char cmd[MAX_CMD_SIZE];
		//PTG_PTG0=1;
    len = datalen-3;
    //len = datalen;
    val = databuf[1]*256 +databuf[0];  
    //val = 0;
    j = 0;
    for(i=3; i<datalen; i++){
      //if(databuf[i] !=0x20 ||databuf[i] !='\n' ) cmd[j++] = databuf[i];
      //else len--;
      cmd[j++] = databuf[i];
    }
    PTG_PTG0= 1;
    return parser(cmd, len, val);
}		
  
//============================================================
//============================================================
void porth_isr_handler(void) {

		//PTG_PTG0= 1;
}

