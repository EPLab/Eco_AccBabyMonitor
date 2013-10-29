/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : ne64api.h
 * Description   : This file contains the definitions for the ethernet 
 *                 abstraction layer used by the OpenTCP stack.
 * Version : 1.0
 * Date    : Jun/14/2004
 *
 ******************************************************************************/
#ifndef __NE64_API_DEFS__
#define __NE64_API_DEFS__

#include "MotTypes.h"

#define ETH_ADDRS_LEN   6
#define ETH_HDR_LEN     14

/* WARNING: The definition of the following structure MUST not change if compatibility with 
   OpenTCP is desirable! */   
typedef struct TEthernetFrame
{
	UINT8	destination[ETH_ADDRS_LEN];	    /**< destination hardware address
											 *	 as read from the received
											 *	 ethernet packet  											 */
	UINT8	source[ETH_ADDRS_LEN];	    	/**< source hardware address
											 *	 as read from the received
											 *	 ethernet packet 											 */
	UINT16	frame_size;						/**< size of the received
											 *	 Ethernet packet  											 */	
	UINT16	protocol;						/**< protocol field of the
											 * 	 Ethernet header. For now we
											 *	 work with:
											 *		\li PROTOCOL_IP	- 0x0800
											 *		\li PROTOCOL_ARP - 0x0806													 */
	UINT16	buf_index;						/**< Address in the Ethernet
											 * 	 controllers buffer where
											 *	 data can be read from														 */
} TEthernetFrame;

											
/* Alias #definitions of actual driver API functions for OpenTCP */

/** \brief NE64WriteByte: Writes a byte to the TX buffer
 *	\ingroup ne64api
 *
 *	This function writes a byte to the TX buffer
 *  This function also increments the pointer of to the next byte in the TX buffer.
 *
 *  \param  dat -  data byte to write to the TX buffer
 *  \return
 *	No return value
 *  \todo This function need more testing
 *   Use word access instead of byte access to speed performance
 *  \bug
 *  \warning  This functions need a global variable to point to the TX buffer
*/
extern void   NE64WriteByte                       (tU08 dat);
extern void   NE64WriteWord                       (tU16 dat);

/** \brief NE64WriteBytes: Writes a given number of data, len, to the TX buffer.
 *	\ingroup ne64api
 *
 *	This function writes a given number of data, len, to the TX buffer.
 *  This function also increments the pointer of to the next byte in the TX buffer.
 *
 *  \param  buf -  pointer to data to write to the TX buffer
 *  \param  len -  number of bytes to write to the TX buffer
 *  \return
 *	No return value
 *  \todo This function need more testing
 *   Use word access instead of byte access to speed performance
 *  \bug
 *  \warning This function need a global variable to point to the TX buffer
*/
extern void   NE64WriteBytes                      (tU08* buf, tU16 len);

/** \brief NE64ReadByte: Read a byte from the RX buffer
 *	\ingroup ne64api
 *
 *	This function reads a byte from the RX buffer and increments the RX buffer pointer.
 *  The buffer read is buffer that triggered reception of valid data.
 *
 *  \param  none
 *  \return	 Data read from buffer
 *  \todo This function need more testing
 *  \bug
 *  \warning Do not clear the data in the recieve buffer until the data is not
 *  needed.  This function needs a global variable to point to the RX buffer
*/
extern UINT8  NE64ReadByte  (void);
extern UINT16 NE64ReadWord  (void);



/** \brief NE64ReadBytes: Reads a specified number of bytes from the RX buffer
 *	\ingroup ne64api
 *
 *	This function reads a specified number of bytes, length, from the RX buffer and
 *  increments the RX buffer pointer.
 *  The buffer read is buffer that triggered reception of valid data.
 *
 *  \param  buf  - pointer to a buffer were the read data is placed
 *  \param  len  - number of bytes to read
 *  \return
 *    None
 *  \todo This function needs more testing
 *   Use word access instead of byte access to speed performance
 *  \bug
 *  \warning Do not clear the data in the recieve buffer until the data is not
 *  needed.  This function needs a global variable to point to the RX buffer
*/
extern void   NE64ReadBytes                       (tU08* buf, tU16 len);

/** \brief NE64InitializeTransmissionBuffer: Initializes the TX buffer pointer so that
 *  it points to the first byte location in the buffer
 *
 *	\ingroup ne64api
 *
 *	This function initializes the TX buffer pointer to point so that
 *  it points to the first byte location in the buffer.  This function needs a
 *  global variable to point to the Tx buffer.
 *
 *  \param  page
 *  \return
 *	No return value
 *  \todo This function need more testing
 *  \bug
 *  \warning  This function needs a global variable to point to the Tx buffer
*/
extern void   NE64InitializeTransmissionBuffer    (tU08 page);


/** \brief NE64InitializeOffsetToReadRxBuffer: Initializes the offset in the
 *  receieve buffer to start reading data from.
 *	\ingroup ne64api
 *
 *	This function initializes the offset in the receieve buffer to start
 *  reading data from by incrementing the RX buffer pointer to the desired location.
 *  The buffer initilized is set to the last buffer that triggered reception of
 *  valid data
 *
 *  \param  pos -  offset for receive buffer pointer
 *  \return
 *	No return value
 *  \todo This function need more testing
 *  \bug
 *  \warning Do not clear the data in the RX buffer until the data is not
 *  needed.  This function needs a global variable to point to the RX buffer
*/
extern void   NE64InitializeOffsetToReadRxBuffer  (tU16 pos);

/** \brief NE64StartFrameTransmission: Start Transmission of data in TX buffer
 *	\ingroup ne64api
 *
 *	This function start Transmission of data in TX buffer
 *
 *  \param  len -  Length of data to transmit (NOTE: this value does NOT include
 *  the nuber of byte in the MAC Ethernet Header.
 *  \return
 *	No return value
 *  \todo This function need more testing
 *  \bug
 *  \warning This function need a global variable to point to the TX buffer
*/
extern void   NE64StartFrameTransmission          (tU16 len );

/** \brief NE64WriteEthernetHeaderToTxBuffer: Writes the Ethernet Header into the
 *  TX buffer
 *
 *	This function Writes the MAC Ethernet Header into the TX buffer. The  Ethernet Header
 *  includes the MAC destination addres, MAC source addres, and the length/type fields.
 *  This function also increments the pointer of to the next byte in the TX buffer after
 *  the MAC Ethernet Header.
 *
 *  \param  frame -  Pointer to ethernet_frame
 *  \return
 *	No return value
 *  \todo This function need more testing
 *  \bug
 *  \warning  NE64InitializeTransmissionBuffer needs to be called before NE64WriteEthernetHeaderToTxBuffer
*/
extern void   NE64WriteEthernetHeaderToTxBuffer   (struct ethernet_frame* frame);

/** \brief NE64ValidFrameReception: Checks for valid reception of data in the RX buffers.
 *	\ingroup ne64api
 *
 *	This function checks for valid reception of data in the RX buffers.  This function also
 *  records which buffer has the valid data in a global variable.
 *
 *  Moreover, this function stores the packet data
 *  including: the destination MAC HW address, the source MAC HW address, the packet length/type
 *  field, and the size in bytes of the Ethernet MAC header.  This information
 *  is stored in a global variable/received_frame structure .
 *
 *  \param  None
 *  \return
 *	Returns TRUE of the RX buffers have valid data in the buffers
 *  \todo This function need more testing
 *  \bug
 *  \warning Do not clear the data in the recieve buffer until the data is not
 *  needed.  This function needs a global variable to point to the receive buffer
*/
extern UINT16 NE64ValidFrameReception             (void);


/** \brief NE64FreeReceiveBuffer: Clear RX receive flag
 *	\ingroup ne64api
 *
 *	This function clears the RX receive flag and makes the buffer availible
 *  for the next packet to be recieved. This function also initializes the
 *  RX buffer pointers
 *
 *  \param  None
 *  \return
 *    None
 *  \todo 
 *  \bug
 *  \warning Do not clear the data in the recieve buffer until the data is not
 *  needed.  This function needs a global variable to point to the RX buffer
*/
extern void   NE64FreeReceiveBuffer               (void);


/** \brief NE64FreeReceiveBuffer: Clear RX receive flag
 *	\ingroup ne64api
 *
 *  \param  None
 *  \return	 None
 *  \todo This function needs more testing
 *  \bug
 *  \warning None
*/
extern void*  NE64GetCurrentReceivedFrame         (void);

#endif

