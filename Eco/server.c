// $Id: server.c,v 1.3 2007/05/15 03:13:23 yoos Exp $
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
#include "io.h"
#include "spi.h"
#include "rf.h"
//#include "msp_if.h"
#include "commands.h"
#include "rf_packet.h"
#include "misc.h"				// delay2us()
#include "adc.h"
#include "reg24e1.h"

#include "timer0.h"
	
#define MYID			4

#define MSP				'M'
#define BASESTATION		0x20

#define BURST_TX		1

#define init_ioport()	{P0_DIR = 0; P0_ALT = 0;}


const int MyID _at_ 0x65;
MyID = MYID;

static char				Mode = 0;
static char				DAQ_mode = 0;
static int				BufferStatus;		// buffer status on MSP
static volatile char	Rf_flag = 1;
//static uchar			Timer0h, Timer0l;
//timer_t		*Timer0;

//static volatile char	Rf_flag = 1;
//static volatile char	port0;
static unsigned char 	Buffer[PAYLOAD_SZ+2];
//static unsigned char 	adcvalue[20];

#define bufferLength 9//24
static unsigned char 	adcvalue[bufferLength];
//static int *ptr16 = (int *)&adcvalue[0];
//static char *ptr16 = (char *)&adcvalue[0];
//static int adcvalue[12];
static unsigned char index = 0;

/* =
{
	 0,  0,
	 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24
};
*/

/*
static void warning(unsigned char num)
{
	unsigned char	i;
	unsigned char	maxblink;
	
	maxblink = num << 1;
	for (i = 0; i < maxblink; i++)
	{
		int		count = 0xffff;
		while (count--);
		led_toggle();
	} // for
} // warning
*/

static void sendto(char *packet)
{
	connectSPITo(SPI_RF_CH1, SCK_2MHz);
	rf_config(TX);
			//BUF_RDY = 1;/**/
	rf_txPacket(packet);
			//BUF_RDY = 0;/**/

} // sendto


static char readfrom(char dev, char *packet)
{
	if (dev == MSP)
	{
		// read data from the MSP
		connectSPITo(SPI_EXT_PORT, SCK_1MHz);
		//if (msp_rxPacket(packet) != 1)
			return 0;
	}
	else		// dev == BASESTATION
	{
		rf_rxOn();
		rf_rxPacket(packet);
	} // if-else
	
	return 1;
} // readfrom


static unsigned char getCommandType(unsigned char *packet)
{
	char		cmdtype;

	cmdtype = packet[0] & (unsigned char)((1 << PACKET_DEST) | (1 << REPLY_REQUEST));
	//cmdtype = packet[0] & (unsigned char)0xc0;
	
	return cmdtype;
} // getCommandType



void xmitdata()
{
	char i;
	Buffer[2] = MyID;
	if (index < 0) index = 0;
	for (i = 0; i < bufferLength; i++) {
		Buffer[i+3] = adcvalue[(i + index) % bufferLength];
//		adcvalue[(i + index) % bufferLength] = 0; //to see if sampling frequency is enough.
	}
 	sendto(Buffer);
} // xmitdata


/*
void xmitdata()
{
	char i;
	Buffer[2] = MyID;
	Buffer[3] = adcvalue[0];
	Buffer[4] = adcvalue[1];
	Buffer[5] = adcvalue[2];
 	sendto(Buffer);
} // xmitdata
*/

void main (void)
{
	//unsigned char i;
	unsigned char my_order;
	//static char		count_burst;
	init_ioport();
	spi_init();
	rf_init();
	//msp_init();
	//timer0_init();
	adc_init();
	timer0_init();
	timer0_start();


	//regCallbackFunc();

	//led_turnOn();
	BUF_RDY = 0;

	rf_config(RX);
	rf_rxOn();

/* initial blinking */
	//for(my_order=0; my_order<=MyID; my_order++)
	for(my_order=0; my_order<=1; my_order++)
	{
		led_turnOn();						
		delayms(10);
		led_turnOff();						
		delayms(1000);
	}
/**/


	for(;;)
	{
		rf_rxPacket(Buffer);

		if (Buffer[0] != MyID && Buffer[1] != MyID && Buffer[2] != MyID)
		{
			rf_rxOn();
			continue;
		}
		
		if(Buffer[0] == MyID)
			my_order = 0;
		else if(Buffer[1] == MyID)
			my_order = 1;
		else
			my_order = 2;

		Buffer[0] = Buffer[1] = Buffer[2] = -1;	// xmitdata() uses 'Buffer' to send data --> reset!

		//PWR_UP = 0;
		MSP_CS = 1;

		switch(my_order)
		{
			case 0:
				//_delay2us(150);
				_delay2us(170);	//350 us
				break;
			case 1:
				delayms(1);
				_delay2us(245);	//500 us
				//_delay2us(185);
				_delay2us(195);	//400
				break;
			case 2:
				delayms(2);
				_delay2us(245);	// 5oo us
				//_delay2us(185);
				_delay2us(205); // 420 us
				break;
		}

		timer0_stop();
		MSP_CS = 0;
		xmitdata();
		MSP_CS = 1;
		led_toggle();
		rf_config(RX);
		rf_rxOn();
		timer0_start();
		MSP_CS = 0;
	} // for
} // main


void timer0_ISR (void) interrupt 1
{
	//static unsigned int 	index = 0;
	//static unsigned char 	index = 0;
	//static unsigned int 	index_count =0;
	// counting 1333  clocks takes 1 ms
	// counting 6665  (0x1A09) take 5 ms 
	// counting 13333 (0x3415) takes 10 ms
	// counting 1333 * 50 = 66650 = (0x1045A) takes 50ms
	
	// 0x10000 - 0x3415 = 0x cbeb
	// 0x10000 - 0x1A09 = 0x E5F7
	// -> 50 ms
		
//MSP_CS = 1; /**/
	
	//TH0 = TIMER0_5MS_HIGH;
	//TL0 = TIMER0_5MS_LOW;

	TH0 = TIMER0_3MS_HIGH;
	TL0 = TIMER0_3MS_LOW;

	//if ( index_count == 0){
	//ptr16[index] =  adc_read(Y_AXIS);

	//ptr16[index] =  adc_read(X_AXIS);		  //for 12 bits ADC

	adcvalue[index] =  adc_read(X_AXIS);		  //for 8 bits ADC
	index = (index + 1) % bufferLength;	
/*
	adcvalue[0] =  adc_read(X_AXIS);
	adcvalue[1] =  adc_read(Y_AXIS);
	adcvalue[2] =  adc_read(Z_AXIS);
*/
//MSP_CS = 0; /**/
	//}

	//index_count = (index_count+1) % 5 ;

}