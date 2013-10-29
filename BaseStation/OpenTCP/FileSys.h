/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : FileSys.h
 * Description   : 
 *
 * Version : 1.0
 * Date    : Mar/05/2004
 *
 *
 ******************************************************************************/
#ifndef __FILE_SYS_H__
#define __FILE_SYS_H__

typedef struct TFileEntry
{
	unsigned char	      hash;		/* hash value for this entry file name */
    const unsigned char*  file_start_address;
	unsigned short        file_length;
} TFileEntry;

extern const TFileEntry FAT [];

#endif
