/*****************************************************************************
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : ne64api.c
 * Description   : This file contains the implementation of the ethernet 
 *                 abstraction layer used by the OpenTCP stack.
 * Version : 1.0
 * Date    : Jun/14/2004
 *
 ******************************************************************************/
#include "MotTypes.h"
#include <string.h>
#include "MC9S12NE64.h"
#include "ne64api.h"
#include "mBuf.h"
/****************** I M P O R T E D   D A T A *******************************/
extern void* emacFIFOa [];
extern void* emacFIFOb [];
extern void* emacFIFOtx[];
extern MBUF  mBufTx;
/****************** L O C A L  D A T A *******************************/
MBUF*	pCurrentMBuf     = (void *)0;
MBUF*	pCurrentSendMBuf = (void *)0;
/* Structures moved here from ethernet.c, defined in ethernet.h */
struct TEthernetFrame received_frame;
struct TEthernetFrame send_frame;
/****************************************************************************/
void NE64InitializeOffsetToReadRxBuffer (UINT16 offset)
{
	pCurrentMBuf->working_ptr = &pCurrentMBuf->data[0] + offset;
}
/*****************************************************************************/
UINT8 NE64ReadByte (void)
{
 	UINT8 temp = 0;
	temp = *pCurrentMBuf->working_ptr++; 	
	 	
 	return(temp);
}
/*****************************************************************************/
UINT16 NE64ReadWord (void)
{
 	UINT16 temp = 0;
	temp = ( (*((UINT16 *)pCurrentMBuf->working_ptr)) );
	pCurrentMBuf->working_ptr += 2;
 	return(temp);
}
/*****************************************************************************/
void NE64ReadBytes (UINT8* buf, UINT16 len)
{
	(void)memcpy (buf ,pCurrentMBuf->working_ptr, len);
	pCurrentMBuf->working_ptr += len;
}
/**************************************************************************/
void NE64InitializeTransmissionBuffer (UINT8 page)
{
    page=0;
    
    pCurrentSendMBuf = &mBufTx;
   
   /* TODO: Add extra security when accessing the emac Tx buffer!! */
    pCurrentSendMBuf->data        = (UINT8 *)emacFIFOtx;
    pCurrentSendMBuf->working_ptr = pCurrentSendMBuf->data;
    pCurrentSendMBuf->status      = MBUF_NOTEMPTY;
    pCurrentSendMBuf->len         = 0;
}
/**************************************************************************/
void NE64WriteEthernetHeaderToTxBuffer (struct TEthernetFrame* frame)
{
	INT8 i;
	
	/* Write destination Ethernet Address	*/	
	for(i=0; i <ETH_ADDRS_LEN; i++) {
		NE64WriteByte(frame->destination[i]);
	}
	/* Write sender (our) Ethernet address	*/	
	for(i=0; i <ETH_ADDRS_LEN; i++) {
		NE64WriteByte(frame->source[i]);
	}
	
	/* Write protocol						*/	
	NE64WriteByte( (UINT8)(frame->protocol >> 8) );
	NE64WriteByte( (UINT8)frame->protocol );
}
/**************************************************************************/
void NE64StartFrameTransmission ( UINT16 len )
{
    extern void EtherStartFrameTransmission(tU16 datalen);
    
    EtherStartFrameTransmission(len);
}
/*************************************************************************/
void NE64WriteByte (UINT8 dat)
{
  if (pCurrentSendMBuf)
 	*pCurrentSendMBuf->working_ptr++ = dat;
}
/**************************************************************************/
void NE64WriteWord (UINT16 dat)
{
    if (pCurrentSendMBuf)  
	{
		(*((UINT16 *)pCurrentSendMBuf->working_ptr)) = (dat);
		pCurrentSendMBuf->working_ptr += 2;
    }
}
/****************************************************************************/
void NE64WriteBytes (UINT8* buf, UINT16 len)
{
	if (pCurrentSendMBuf == NULL)
		return;
	(void)memcpy (pCurrentSendMBuf->working_ptr, buf, len);
	pCurrentSendMBuf->working_ptr += len;
}
/******************************************************************************
* WARNING!: This function is called at Interrupt Service Routine context!, it 
*           is assumed interrupts are dissabled when executing code within this 
*           function. This is to maintain atomic access to pCurrentMBuf 
*           pointers.
******************************************************************************/
UINT16 NE64Receive (void *PktBuffer, UINT16 len, UINT16 flags)
{
  MBUF mp;
    
    mp.data        = (UINT8 *)PktBuffer;
    mp.working_ptr = mp.data;
    mp.len         = len;
    mp.status      = (MBUF_NOTEMPTY | flags);
    
    if (mp.status & IEVENT_RXACIF_MASK)  
    {
        IMASK_RXACIE = 0;   /* Block IRQs on buffer A */
    }
    else
    {
        IMASK_RXBCIE = 0;   /* Block IRQs on buffer B */
    }
    
    (void)mENQUEUE (&mp);
    return 0;
}
/****************************************************************************/
UINT16 NE64ValidFrameReception (void)
{
    if (pCurrentMBuf = mDEQUEUE())
        return TRUE;
    
    return FALSE;
}
/**************************************************************************/
void NE64FreeReceiveBuffer (void)
{
    if (pCurrentMBuf->status & IEVENT_RXACIF_MASK)
    {
        pCurrentMBuf->status = 0;
        IEVENT = IEVENT_RXACIF_MASK;
        IMASK_RXACIE         = 1;
    }
    
    if (pCurrentMBuf->status & IEVENT_RXBCIF_MASK)
    {
        pCurrentMBuf->status = 0;
        IEVENT = IEVENT_RXBCIF_MASK;
        IMASK_RXBCIE         = 1;
    }        
}
/***************************************************************************/
void* NE64GetCurrentReceivedFrame (void)
{
    return (void *)pCurrentMBuf;
}