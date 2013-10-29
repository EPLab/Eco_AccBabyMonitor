// $Id: rf.c,v 1.2 2007/05/15 03:13:23 yoos Exp $
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
#include "io.h"
#include "spi.h"
#include "rf.h"
#include "misc.h"				// delayms

#define _TX_DELAY

#define CONFIG_LENGTH		15
#define ADDR_INDEX			9   // Index to address bytes in RFConfig.buf


const char txconf[CONFIG_LENGTH] =
{
	PAYLOAD_SZ << 3,				// DATA2_W
	PAYLOAD_SZ << 3,				// DATA1_W
	0x00, 0x00, 0x00, 0x00, 0x00,	// ADDR2
	//0x00, 0x12, 0x34, 0x56, 0x78,	// ADDR1
	0x00, 0x00, 0x65, 0x65, 0x65,	// ADDR1
	0x63,							// 32-bit address & 16 bit CRC enabled
	//(ADDR_W << 2) | CRC_L | CRC_EN,	// 32-bit address & 16 bit CRC enabled
	0x6f,							// one ch, shockburst, 1Mbps, 16MHz, 0dBm
	//0xf4							// CH#: 122 & TX
	//0x04							// CH#: 2 & TX
	//0xEC							// CH#: 118 & TX
	0x0C							// CH#: 6 & TX
};

const char rxconf[CONFIG_LENGTH] =
{
	PAYLOAD_SZ << 3,				// DATA2_W
	PAYLOAD_SZ << 3,				// DATA1_W
	0x00, 0x00, 0x00, 0x00, 0x00,	// ADDR2
	//0x00, 0x87, 0x65, 0x43, 0x21,	// ADDR1
	0x00, 0x00, 0x65, 0x65, 0x65,	// ADDR1
	0x63,							// 32-bit address & 16 bit CRC enabled
	//(ADDR_W << 2) | CRC_L | CRC_EN,	// 32-bit address & 16 bit CRC enabled
	0x6f,							// one ch, shockburst, 1Mbps, 16MHz, 0dBm
	//0xf5							// CH#: 122 & RX
	//0x05							// CH#: 2 & RX
	//0xED							// CH#: 118 & RX
	0x0D							// CH#: 6 & RX
};


// the following is redundant
// however the overall code size is reduced
static uchar spi_rwByte(uchar b)
{
	EXIF &= ~0x20;                  // Clear SPI interrupt
	SPI_DATA = b;                   // Move byte to send to SPI data register
	while((EXIF & 0x20) == 0x00);	// Wait until SPI hs finished transmitting

	return SPI_DATA;
} // spi_rwByte


void rf_init(void)
{
	PWR_UP = 1;                     // Turn on Radio
	delayms(3);						// Wait > 3ms 
	SPI_CTRL = 0x02;                // Connect the internal SPI controller to RF1
} // rf_init


void rf_config(char mode)
{
	char	i;
	char	*config;

	config = (mode == TX ? txconf : rxconf);
	CS = 1;
	// 5us Tcs2data delay is required
	// actually the below for loop and function call
	// takes about 5us. Thus no explicit Tcs2data is required.
	for (i = 0; i < CONFIG_LENGTH; i++)
		spi_rwByte(config[i]);
	CS = 0;
} // rf_config


void rf_txPacket(char *buf)
{
	char		i;
	CE = 1;
	// 5us Tce2data delay is required
	// actually the below for loop and function call
	// takes about 5us. Thus no explicit Tce2data is required.
	for (i = 0; i < ADDR_W; i++)
		spi_rwByte(rxconf[ADDR_INDEX+i]);

	for (i = 0; i < PAYLOAD_SZ; i++)
		spi_rwByte(buf[i]);
	CE = 0;
#ifdef _TX_DELAY
	// T_txdone = Tsby2txSB + Toa = 195us + (256 + 1)us = 452us
	// refer to the nRF24E1 data sheet
	//Delay100us(3);                  // actually more than 300us
	delay2us(150);
#endif // _TX_DELAY

} // rf_txPacket


char rf_rxPacket(char *buf)
{
	char		i;

	//CE = 1;
	while (DR1 == 0);
	//BUF_RDY = 1;	/**/
	CE = 0;
	for (i = 0; i < PAYLOAD_SZ; i++)
		buf[i] = spi_rwByte(0);

return 1;
} // rf_rxPacket
