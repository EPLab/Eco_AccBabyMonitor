// $Id: $
/*
 * (C) 2007 The Regents of the University of California. All Rights Reserved.
 * Created by Seung-mok Yoo, Department of Electrical Engineering & Computer
 * Science
 *
 * Copyright (C) 2007 The Regents of the University of California. All Rights
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
#include "reg24e1.h"
#include "rf.h"
#include "timer0.h"

/*
static const unsigned int	const1ms = TIMER0_1MS;
static const unsigned int	const2ms = TIMER0_2MS;
static const unsigned int	const3ms = TIMER0_3MS;
static const unsigned int	const4ms = TIMER0_4MS;
static const unsigned int	const5ms = TIMER0_5MS;
static const unsigned int	const10ms = TIMER0_10MS;
*/

static const timer_t const500us = {TIMER0_500US_LOW, TIMER0_500US_HIGH};
static const timer_t const1500us = {TIMER0_1500US_LOW, TIMER0_1500US_HIGH};
static const timer_t const1ms = {TIMER0_1MS_LOW, TIMER0_1MS_HIGH};
static const timer_t const2ms = {TIMER0_2MS_LOW, TIMER0_2MS_HIGH};
static const timer_t const3ms = {TIMER0_3MS_LOW, TIMER0_3MS_HIGH};
static const timer_t const4ms = {TIMER0_4MS_LOW, TIMER0_4MS_HIGH};
static const timer_t const5ms = {TIMER0_5MS_LOW, TIMER0_5MS_HIGH};
static const timer_t const10ms = {TIMER0_10MS_LOW, TIMER0_10MS_HIGH};

//	Set Timer0 for 16-bit timer mode.  The
//	timer counts to 65535, overflows, and
//	generates an interrupt.
//	Set the Timer0 Run control bit.
void timer0_init(void)
{
	TMOD = (TMOD & 0xF0) | 0x01;	// Set T/C0 Mode
	//CKCON &= 0xF7;					// T0M=0 (/12 timer clock)
	CKCON |= 0x0F;					// T0M=1 (/4 timer clock)
	PT0 = 1;						// raise intr0 high
	ET0 = 1;						// Enable Timer 0 Interrupts
	EA = 1;							// Global Interrupt Enable
} // timer0_init

void timer0_start(void)
{
	// initial value
	//TH0 = TIMER0_5MS_HIGH;
	//TL0 = TIMER0_5MS_LOW;

	TH0 = TIMER0_2MS_HIGH;
	TL0 = TIMER0_2MS_LOW;

	TR0 = 1;						// start timer0
} // timer0_start


timer_t *timer0_getRegVal(uchar unit)
{
	switch (unit)
	{
	case 1:
		return &const1ms;
	case 2:
		return &const2ms;
	case 3:
		return &const3ms;
	case 4:
		return &const4ms;
	case 5:
		return &const5ms;
	case 10:
		return &const10ms;
	case 11:
		return &const500us;
	case 15:
		return &const1500us;
	default:
		return 0;
	} // switch
} // timer0_getRegVal


