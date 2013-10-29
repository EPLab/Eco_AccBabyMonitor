#ifndef _SCI_H_
#define _SCI_H_

#include <stdio.h>
//#include "ne64debug.h"
#include "MOTTYPES.h"
#include "MC9S12NE64.h"


#define _BASE 0x0000  /**< Base on register map */

#define ECLK 25000000 /**< this is BUSCLK */

#define reg(x)  *((volatile tU08 *)(_BASE+x))
#define regw(x)  *((volatile tU16 *)(_BASE+x))

#define SCI0    0x00c8
#define SCI1    0x00d0

#define SCIBD  regw(_SCI_BASE+0x00)
#define SCICR1 reg(_SCI_BASE+0x02)
#define SCICR2 reg(_SCI_BASE+0x03)
#define SCISR1 reg(_SCI_BASE+0x04)
#define SCIDRL reg(_SCI_BASE+0x07)

void SCIinit(void);
void SCIsend(char* data);
INT16 SCIrecv(char* buf);
void SCIsendC(char c);
#endif
