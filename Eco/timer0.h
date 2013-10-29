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
#ifndef _TIMER0_H
#define _TIMER0_H

#include "type.h"		// uchar

//#define T0M_UNSET		0

#if defined(T0M_UNSET)	// T0M == 0, means CPU_clk/12
// counting 1333 clocks takes 1 ms
// counting 13333 (0x3415) takes 10 ms
// 0x10000 - 0x3415 = 0xcbeb
// -> 10 ms
#define TIMER0_10MS_HIGH			0xCB
#define TIMER0_10MS_LOW				0xEB

// counting 1333 clocks takes 1 ms
// counting 6666 (0x1A0A) takes 5 ms
// 0x10000 - 0x1A0A = 0xE5F6
// -> 5 ms
#define TIMER0_5MS_HIGH				0xE5
#define TIMER0_5MS_LOW				0xF6

// counting 1333 clocks takes 1 ms
// counting 5333 (0x14D5) takes 4 ms
// 0x10000 - 0x14D5 = 0xEB2B
// -> 4 ms
#define TIMER0_4MS_HIGH				0xEB
#define TIMER0_4MS_LOW				0x2B

// counting 1333 clocks takes 1 ms
// counting 4000 (0x0FA0) takes 3 ms
// 0x10000 - 0x0FA0 = 0xF060
// -> 3 ms
#define TIMER0_3MS_HIGH				0xF0
#define TIMER0_3MS_LOW				0x60

// counting 1333 clocks takes 1 ms
// counting 2667 (0x0A6A) takes 2 ms
// 0x10000 - 0x0A6A = 0xF596
// -> 2 ms
#define TIMER0_2MS_HIGH				0xF5
#define TIMER0_2MS_LOW				0x96

// counting 1333 (0x0535) clocks takes 1 ms
// 0x10000 - 0x0535 = 0xFACB
// -> 1 ms
#define TIMER0_1MS_HIGH				0xFA
#define TIMER0_1MS_LOW				0xCB

#else		// T0M == 1, means CPU_clk/4

// counting 2000 (0x07D0) clocks takes 0.5 ms
// 0x10000 - 0x07D0 = 0xF830
// -> 0.5 ms
#define TIMER0_500US					0xF830
#define TIMER0_500US_HIGH				0xF8
#define TIMER0_500US_LOW				0x30

// counting 4000 (0x0FA0) clocks takes 1 ms
// 0x10000 - 0x0FA0 = 0xF060
// -> 1 ms
#define TIMER0_1MS					0xF071
#define TIMER0_1MS_HIGH				0xF0
//#define TIMER0_1MS_LOW				0x60
#define TIMER0_1MS_LOW				0x71

// counting 6000 (0x1770) clocks takes 1.5 ms
// 0x10000 - 0x1770 = 0xE890
// -> 1.5 ms
#define TIMER0_1500US					0xE890
#define TIMER0_1500US_HIGH				0xE8
//#define TIMER0_1500US_LOW				0x90
#define TIMER0_1500US_LOW				0xA7

// counting 8000 (0x1F40) clocks takes 2 ms
// 0x10000 - 0x1F40 = 0xE0C0
// -> 2 ms
#define TIMER0_2MS					0xE0D5
#define TIMER0_2MS_HIGH				0xE0
//#define TIMER0_2MS_LOW				0xC0
#define TIMER0_2MS_LOW				0xD5

// counting 12000 (0x2EE0) clocks takes 3 ms
// 0x10000 - 0x2EE0 = 0xD120
// -> 3 ms
#define TIMER0_3MS					0xD120
#define TIMER0_3MS_HIGH				0xD1
#define TIMER0_3MS_LOW				0x20

// counting 16000 (0x3E80) clocks takes 4 ms
// 0x10000 - 0x3E80 = 0xC180
// -> 4 ms
#define TIMER0_4MS					0xC180
#define TIMER0_4MS_HIGH				0xC1
#define TIMER0_4MS_LOW				0x80

// counting 20000 (0x4E20) clocks takes 5 ms
// 0x10000 - 0x4E20 = 0xB1E0
// -> 5 ms
#define TIMER0_5MS					0xB1E0
#define TIMER0_5MS_HIGH				0xB1
#define TIMER0_5MS_LOW				0xE0

// counting 40000 (0x9C40) clocks takes 10 ms
// 0x10000 - 0x9C40 = 0x63C0
// -> 10 ms
#define TIMER0_10MS					0x63ED
#define TIMER0_10MS_HIGH			0x63
//#define TIMER0_10MS_LOW				0xC0
#define TIMER0_10MS_LOW				0xED


#endif

#define timer0_stop()			{TR0 = 0;}

typedef struct
{
	uchar		low;
	uchar		high;
} timer_t;

void timer0_init();
void timer0_start();
timer_t *timer0_getRegVal(uchar unit);

#endif // _TIMER0_H