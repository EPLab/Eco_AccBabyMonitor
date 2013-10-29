/*****************************************************************************
 *                      (c) Freescale  Inc. 2003 All rights reserved          
 *
 * File Name     : debug.h                                              
 *                                                                           
 * PURPOSE: Diagnostics output header file
 *                                                                           
 * Version : 2.1
 * Date    : 01/20/03
 *
 *****************************************************************************/

#ifndef _NE64_DEBUG_H
#define _NE64_DEBUG_H

#include "MOTTYPES.h"

//uncomment to enable debug mode
//set  ETH_DEBUG to 1 for detailed debug
//#define ETH_DEBUG  1



#ifdef ETH_DEBUG

void Debugt(tS08 *x);
void Debugi(tU16 x);
void Debugc(tU08 c);
void Debugnl(void);
void InitDebug(void);

#define _INIT_DEBUG()   InitDebug()
#define _DEBUGT(a)   Debugt(a)
#define _DEBUGI(a)   Debugi(a)
#define _DEBUGC(a)   Debugc(a)
#define _DEBUGNL     Debugnl()


#else
#define _INIT_DEBUG()
#define _DEBUGT(a)
#define _DEBUGI(a)
#define _DEBUGC(a)
#define _DEBUGNL

#endif						 

#endif