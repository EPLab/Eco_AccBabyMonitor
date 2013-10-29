/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : FileSys.c
 * Description   : 
 *
 * Version : 1.0
 * Date    : Mar/05/2004
 *
 *
 ******************************************************************************/
 #include "FileSys.h"

/********* Include Web server files here *************/
#include "index.h"
#include "fs_anilogo.h"
/*****************************************************/

const TFileEntry FAT [] = {
     {  115,    index_file,      INDEX_FILE_LEN      },
     {	4,    fs_anilogo_file,      FS_ANILOGO_FILE_LEN  },

     {  0,      (unsigned char *)0,  0  }
};