/*****************************************************************************
 *                      (c) Freescale  Inc. 2004 All rights reserved       
 *   
 * File Name     : debug.c                                              
 *                                                                           
 * PURPOSE: Diagnostics output through SCI                                   
 *                                                                           
 *                                                                           
 * DESCRIPTION: Implementation of the diagnostics output - enabled when
 *              ETH_DEBUG keyword is defined (-DETH_DEBUG) 
 *              _SCI_BASE must be set to SCI0 or SCI1
 *              (see compiler command line arguments)
 *
 * Version : 2.1
 * Date    : 02/04/04 
 *
 *****************************************************************************/

#include <stdio.h>
#include "ne64debug.h"
#include "MC9S12NE64.h"

#ifdef ETH_DEBUG

#define _BASE 0x0000  /**< Base on register map */

#define ECLK 25000000 /**< this is BUSCLK */

#define reg(x)  *((volatile tU08 *)(_BASE+x))
#define regw(x)  *((volatile tU16 *)(_BASE+x))

#define SCI0    0x00c8
#define SCI1    0x00d0

#ifndef _SCI_BASE
#error _SCI_BASE not defined, use SCI0 or SCI1
#endif

#define SCIBD  regw(_SCI_BASE+0x00)
#define SCICR1 reg(_SCI_BASE+0x02)
#define SCICR2 reg(_SCI_BASE+0x03)
#define SCISR1 reg(_SCI_BASE+0x04)
#define SCIDRL reg(_SCI_BASE+0x07)

//===================================================
void InitDebug(void)
{

#define BAUD_RATE    115200
  
#define BAUD_DIV     ECLK/16/BAUD_RATE
 
  SCIBD= BAUD_DIV;
  SCICR1= 0;
  SCICR2= SCI1CR2_TE_MASK | SCI1CR2_RE_MASK | SCI1CR2_RWU_MASK ;
}



//===================================================
/* send string via SCI */
//===================================================
void Debugt(tS08 * s)
{
  while (*s != 0)
  {
    while (!(SCISR1 & 0x80));
    SCIDRL=*s;
    s++;
  }
}


//===================================================
/* convert 8bit number to 2 hexadecimal ascii characters */
//===================================================
tS08 cvt[16]={ '0','1','2','3','4','5','6','7','8','9',
                      'A','B','C','D','E','F' };

//===================================================
void Ctoh (tS08 * s, tU08 c)
{
  *s= cvt[c / 16];
  s++;
  *s= cvt[c % 16];
}


//===================================================
/* send 16bit number in hexa via SCI */
//===================================================
void Debugi(tU16 i)
{
  tS08 s[6];
  s[0]=' ';
  Ctoh(s+1,(tU08)(i / 256));
  Ctoh(s+3,i % 256);
  s[5]=0;
  Debugt(s);
}

//===================================================
/* send 8bit number in hexa via SCI */
//===================================================
void Debugc(tU08 c)
{
  tS08 s[4];
  s[0]=' ';
  Ctoh(s+1,c);
  s[3]=0;
  Debugt(s);
}

//===================================================
/* send newline and return characters via SCI */
//===================================================
void Debugnl(void)
{
  Debugt("\r\n");
}
#endif
