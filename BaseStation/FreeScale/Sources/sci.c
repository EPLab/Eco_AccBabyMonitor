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

#include "sci.h"

//===================================================
void SCIinit(void)
{

#define BAUD_RATE    19200
  
#define BAUD_DIV     ECLK/16/BAUD_RATE
 
  SCIBD= BAUD_DIV;
  SCICR1= 0;
  //SCICR2 = 0x2c;
  //SCICR2= SCI1CR2_RIE_MASK| SCI1CR2_TE_MASK | SCI1CR2_RE_MASK ;
  SCICR2= SCI1CR2_TE_MASK | SCI1CR2_RE_MASK | SCI1CR2_RWU_MASK ;
}



//===================================================
/* send string via SCI */
//===================================================
void SCIsend(tS08 * s)
{
  while (*s != 0)
  {
    while (!(SCISR1 & 0x80));
    SCIDRL=*s;
    s++;
  }
}

void SCIsendC(char c)
{
 
    while (!(SCISR1 & 0x80));
    SCIDRL=c;
  
}
//===================================================
/* receive string via SCI */
//===================================================
INT16 SCIrecv(char* buf)
{ 
  //static char buf[100];
  static INT16 i = 0;
 static char newline=0;
 	INT16 len;
 	len = 0;
 	//if(!( SCISR1&0x20)) PTG_PTG0 = 1;
  while (!(SCISR1&0x20)) return 0;
  //PTG_PTG1 = 1;
   buf[i] = SCIDRL;
   //SCIsendC(buf[i-1]); 
   if(buf[i] == '\n'||buf[i] == '\r') {
       //newline = 0;
       newline =1 ;       
       //break;//return i;
   }
   i++;

  if(newline) {
      len = i-1;
      buf[i] = '\n';
      i++;
      buf[i] = 0x0;
     
      i = 0;
      newline = 0;
  }
 
  return len;
} 

//===================================================
/* convert 8bit number to 2 hexadecimal ascii characters */
//===================================================
tS08 cvt1[16]={ '0','1','2','3','4','5','6','7','8','9',
                      'A','B','C','D','E','F' };

//===================================================
void Ctoh (tS08 * s, tU08 c)
{
  *s= cvt1[c / 16];
  s++;
  *s= cvt1[c % 16];
}


//===================================================
/* send 16bit number in hexa via SCI */
//===================================================
void SCIsendi(tU16 i)
{
  tS08 s[6];
  s[0]=' ';
  Ctoh(s+1,(tU08)(i / 256));
  Ctoh(s+3,i % 256);
  s[5]=0;
  SCIsend(s);
}

//===================================================
/* send 8bit number in hexa via SCI */
//===================================================
void SCIsendc(tU08 c)
{
  tS08 s[4];
  s[0]=' ';
  Ctoh(s+1,c);
  s[3]=0;
  SCIsend(s);
}

//===================================================
/* send newline and return characters via SCI */
//===================================================
void SCIsendnl(void)
{
  SCIsend("\r\n");
}

