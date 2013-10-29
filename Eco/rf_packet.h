// $Id: rf_packet.h,v 1.3 2007/08/16 05:19:29 yoos Exp $
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
#ifndef _RF_PACKET_H
#define _RF_PACKET_H

// RF packet configuration
#define ADDR_W					3   // Number of address bytes
#define PAYLOAD_SZ				27
//  type: 1 byte
//  seq#: 1 byte
//  payload: 25 bytes
#define CRC_L					2	// 16 bit CRC
#define CRC_EN					1	// CRC enabled

// RF packet index
#define IDX_TYPE				0
#define IDX_SEQ					1
#define IDX_DATA				2
#define IDX_DATLEN				3
#define IDX_CMD					5
#define IDX_PARAM				6


// type (BS -> Eco)
#define PACKET_DEST				7
#define REPLY_REQUEST			6
#define LINK_ADDR				0
#define LINK_ADDR_MASK			(0x07 << LINK_ADDR)	// LS 3 bits



// flags & opcodes

// the following macros for indicating command types
#define CMD_ECO					((1 << PACKET_DEST) | (0 << REPLY_REQUEST))	// Eco
#define CMD_ECO_BS				((1 << PACKET_DEST) | (1 << REPLY_REQUEST))	// Eco -> BS
#define CMD_ECO_MSP				((0 << PACKET_DEST) | (0 << REPLY_REQUEST))	// Eco -> MSP
#define CMD_ECO_MSP_ECO_BS		((0 << PACKET_DEST) | (1 << REPLY_REQUEST))	// Eco -> MSP -> Eco -> BS

// commands from the base station


// type: Eco -> BS
// type: MSP -> Eco -> BS
#define GET_PARAM					0x41
#define SET_PARAM					0x42
#define XMIT						0x51
#define SLEEP						0x52
#define READ_SENSEDATA				0x53
#define XMIT_DATA					0x54
#define TEST						0x77		// for debugging

// type: Eco -> MSP -> Eco -> BS
#define GET_VERSION					0x12
#define GET_DAQ_MODE				0xa7
//#define ECHO						0xbe

// type: Eco -> MSP
#define SET_DAQ_MODE				0x21


#define ECO_COMMAND					0x01
#define ECO_REPLY_REQUIRED			0x03
#define ECO_REPLY_NOT_REQUIRED		0x01

#define MSP_COMMAND					0x10
#define MSP_REPLY_REQUIRED			0x30
#define MSP_REPLY_NOT_REQUIRED		0x10

#endif // _RF_PACKET_H
