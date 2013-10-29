// $Id: spi.h,v 1.1 2007/05/09 20:31:57 yoos Exp $
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
#ifndef _SPI_H
#define _SPI_H

#include "type.h"

#define SCK_2MHz		0
#define SCK_1MHz		1
#define SCK_500KHz		2
#define SCK_250KHz		3

#define SPI_DISABLE			0x0		// disable SPI
#define SPI_EXT_PORT		0x1		// SPI external port
#define SPI_RF_CH1			0x2		// RF CH1

#define connectSPITo(dev, clock) 	{\
			SPI_CTRL = SPI_DISABLE; \
			SPICLK = clock; \
			SPI_CTRL = dev;\
		}


#define spi_init()			(SPICLK = SCK_2MHz)			// Max SPI clock (XTAL/8)
//#define spi_isBusy()		spi_busy


//extern volatile char		spi_busy = 0;

uchar		spi_rwByte(uchar b);
char		spi_isBusy();


#endif // _SPI_H
