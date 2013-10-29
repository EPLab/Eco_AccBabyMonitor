/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : mBuf.c
 * Description   : Implementation of a buffering scheme based on mBUFs
 *
 * Version : 1.0
 * Date    : Jun/22/2004
 *
 ******************************************************************************/
#include "mBuf.h"
#include "ne64api.h"
#include <string.h>
#define	MBUFS_NUM	2
MBUF mBufs  [MBUFS_NUM];	/* The static array of MBufs buffers! */
MBUF mBufTx;                /* MBUF buffer for transmissions */
unsigned char enq_index;
unsigned char deq_index;
extern struct TEthernetFrame received_frame;
/*****************************************************************************
* mBufInit ()
* 
*****************************************************************************/
void mBufInit (void) 
{
	mBufs[0].status      = 0x00;
    mBufs[0].len         = 0x0000;
	mBufs[0].data        = (void *)0x0000;
	mBufs[0].working_ptr = (void *)0x0000;
	
	mBufs[1].status      = 0x00;
    mBufs[1].len         = 0x0000;
	mBufs[1].data        = (void *)0x0000;
	mBufs[1].working_ptr = (void *)0x0000;
	mBufTx.status        = 0x00;
	mBufTx.len           = 0x00;
	mBufTx.data          = (void *)0x0000;
	mBufTx.working_ptr   = (void *)0x0000;
	enq_index = 0;
	deq_index = 0;
}
/******************************************************************************
*
* 
******************************************************************************/
INT16 mENQUEUE (MBUF *m) 
{
	if (!(mBufs[enq_index].status & MBUF_NOTEMPTY)) 
	{
		mBufs[enq_index].data        = m->data;
		mBufs[enq_index].working_ptr = m->working_ptr;
		mBufs[enq_index].len         = m->len;
		mBufs[enq_index].status      = m->status;
		
		enq_index++;
		enq_index = (unsigned char)(enq_index % MBUFS_NUM);
		return 0;
	}
   return (~0);
}
/******************************************************************************
*
* 
******************************************************************************/
MBUF* mDEQUEUE (void)
{ 
	MBUF *ret;
	if (mBufs[deq_index].status & MBUF_NOTEMPTY)
	{
		(void)memcpy (received_frame.destination, mBufs[deq_index].data, 2*ETH_ADDRS_LEN);
		received_frame.frame_size = mBufs[deq_index].len;
		received_frame.protocol   = (*((unsigned short *)&mBufs[deq_index].data[12]));
    received_frame.buf_index  = ETH_HDR_LEN;  
    	
		ret = (MBUF *)&mBufs[deq_index];
		deq_index++;
		deq_index = (unsigned char)(deq_index % MBUFS_NUM);
		return ret;
	}
	return (MBUF *)0;
}