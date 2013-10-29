/**************************************************************************                      
 *							 
 *       Copyright (C) 2003 Freescale Semiconductor, Inc. 
 *           and 2000-2002 Viola Systems Ltd. 
 *       All Rights Reserved
 *				 
 * File Name      : icmp.h
 * Project Name   : Connector_App.mcp
 * Description    : Header File for icmp.c.
 *                  Contains function prototypes.
 * 
 * Version : 1.0
 * Date    : 07/06/04
 *
 ***************************************************************************/ 

/* Prototypes (i.e. Function Definitions) */
INT16 process_icmp_in (struct ip_frame* frame, UINT16 len);	 
INT16 process_udp_in(struct ip_frame* frame, UINT16 len);		 