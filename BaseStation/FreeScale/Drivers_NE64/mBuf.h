/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : mBuf.h
 * Description   : Implementation of a buffering scheme based on mBUFs
 *
 * Version : 1.0
 * Date    : Jun/22/2004
 *
 ******************************************************************************/
#ifndef _MBUF_H_
#define _MBUF_H_

#include "MotTypes.h"

#define MBUF_NOTEMPTY	0x0001

/*
 * MBUF - Type definition of an MBuf structure. All network frames are stored
 *        and processed using MBufs.
 */
typedef struct MBUF
{		
	INT16		status;
	INT16		len;			/* this MBuf len (in bytes)             */
	UINT8		*working_ptr;
    UINT8       *data;
} MBUF;	

/* mBUFTOPTR - Return mBuf's data pointer casted to type t. */
#define	mBUFTOPTR(n, t)	((t)((n)))

/***************** A P I **************************/
extern void  mBufInit (void);
extern INT16 mENQUEUE (MBUF *m);
extern MBUF* mDEQUEUE (void);

#endif