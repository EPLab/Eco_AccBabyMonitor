/**************************************************************************                      
 *							 
 *       Copyright (C) 2003 Freescale Semiconductor, Inc. 
 *           and 2000-2002 Viola Systems Ltd. 
 *       All Rights Reserved
 *				 
 * File Name      : Connector_App.h
 * Project Name   : Connector_App.mcp
 * Description    : Header File for Connector_App.c.
 *                  Contains function prototypes.
 * 
 * Version : 1.0
 * Date    : 07/06/04
 *
 ***************************************************************************/ 
#ifndef _CONNECT_APP_H
#define _CONNECT_APP_H
#include "datatypes.h"
#include "sci.h"
/* Prototypes (i.e. Function Definitions) */
INT16 parserData(char* buf, UINT16 datalen); 
void udp_demo_run(void);  
void udp_demo_init(void);
#endif