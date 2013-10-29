// $Id: io.h,v 1.1 2007/05/09 20:31:57 yoos Exp $
/*
 * (C) 2006 The Regents of the University of California. All Rights Reserved.
 * Created by Seung-mok Yoo, Department of Electrical Engineering & Computer
 * Science
 *
 * Copyright (C) 2006 The Regents of the University of California. All Rights
 * Reserved. Permission to use, copy, modify, and distribute this software and
 * its documentation for educational, research and non-profit purposes, without
 * fee, and without a written agreement is hereby granted, provided that the
 * above copyright notice, this paragraph and the following two paragraphs
 * appear in all copies. This software program and documentation are
 * copyrighted by The Regents of the University of California ("The University
 * of California").
 *
 * THE SOFTWARE PROGRAM AND DOCUMENTATION ARE SUPPLIED "AS IS," WITHOUT ANY
 * ACCOMPANYING SERVICES FROM THE UNIVERSITY OF CALFORNIA. FURTHERMORE, THE
 * UNIVERSITY OF CALIFORNIA DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM
 * WILL BE UNINTERRUPTED OR ERROR-FREE. THE END-USER UNDERSTANDS THAT THE
 * PROGRAM WAS DEVELOPED FOR RESEARCH PURPOSES AND IS ADVISED NOT TO RELY
 * EXCLUSIVELY ON THE PROGRAM FOR ANY REASON.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING
 * LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
 * EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGES. THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED
 * HEREUNDER IS ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO
 * OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
 * MODIFICATIONS. 
 */
#ifndef _IO_H
#define _IO_H

#include <reg24e1.h>

sbit LED       = P0^5;

// for MSP430 interface
//sbit DIO3		= P0^1;
//sbit DIO4		= P0^2;
//sbit DIO5		= P0^3;

sbit BUF_RDY	= P0^1;
sbit MSP_CS		= P0^2;
sbit RTS		= P0^3;				// RTS active low

//#define setBit(port, bit)		(port |= 1 << bit)
//#define clearBit(port, bit)		(port &= ~(1 << bit))
//#define toggleBit(port, bit)	(port ^= 1 << bit)

//#define led_turnOn()	(P0 &= 0xdf)
//#define led_turnOff()	(P0 |= 0x20)
//#define led_toggle()	(P0 ^= 0x20)

#define led_turnOn()	(LED = 0)
#define led_turnOff()	(LED = 1)
#define led_toggle()	(LED ^= 1)

#define isRTSOn()		(RTS == 1)

#endif // _IO_H
