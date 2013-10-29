/**************************************************************************                      
 	Parser.h
 	Author: Qiang Xie
 	Date:   05/11/2005
 	All rights reserved
 ***************************************************************************/ 

#ifndef _PARSER_H
#define _PARSER_H
#define UDP_DEMO_PORT	2001 /**< UDP_DEMO_RMTHOST_PRT number on which we'll work */

//#define UDP_DEMO_RMTHOST_IP	0xC0A80002	/**< Remote IP address this application will send data to 192.168.0.2*/
#define UDP_DEMO_RMTHOST_IP	0xC0A802C8	/**< Remote IP address this application will send data to  192.168.2.200*/

#define UDP_DEMO_RMTHOST_PRT	2001	/**< UDP_DEMO_RMTHOST_PRT number on remote server we'll send data to */


/* Prototypes (i.e. Function Definitions) */
 
extern INT16 parser(unsigned char*, UINT16, UINT16);  
extern void result_block_send(UINT16 cmdid, UINT16 result, char done);
extern void timer4_isr_handler(void);
extern void timer5_isr_handler(void);
extern void timer6_isr_handler(void);
extern void timer7_isr_handler(void);

extern char tcmd[4][80];
extern UINT16 cmd_len[4];
extern UINT8 tm_used[4];
extern UINT16 cmd_id[4];

extern INT8 UDPsoc;

#endif