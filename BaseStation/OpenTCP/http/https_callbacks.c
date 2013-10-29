#include"datatypes.h"
#include"debug.h"
#include"globalvariables.h"
#include"system.h"
#include"http_server.h"

#include "FileSys.h"

/** \brief File not found message
 *
 *	Message that will be displayed if a file with appropriate name (hash
 *	value) was not found.
 */
const char https_not_found_page[] = "HTTP/1.0 200 OK\r\nLast-modified: Mon, 17 May 2004 15:02:45 GMT\r\nServer: ESERV-10/1.0\nContent-type: text/html\r\nContent-length: 400\r\n\r\n<HEAD><TITLE>Viola Systems Embedded WEB Server</TITLE></HEAD><BODY><H2>HTTP 1.0 404 Error. File Not Found</H2>The requested URL was not found on this server.<HR><BR><I>Viola Systems Embedded WEB Server 2.01, 2004<BR><A HREF=http://192.168.2.3/index.htm>Did you wish 192.168.2.3/index.htm?</I></A><BR><A HREF=http://www.violasystems.com>www.violasystems.com - Embedding The Internet</A></BODY>";

/** \brief Brief function description here
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 09.10.2002
 *	\param hash Calculated file-name hash value. Used so that the whole
 *		file name doesn't need to be stored in RAM
 *	\param ses HTTP session identifier
 *	\return
 *		\li -1 - This function should return -1 if no file has been found
 *		\li 1 - This function should return 1 if a file with appropriate
 *			hash value has been found.
 *	\warning
 *		\li This function <b>MUST</b> be implemented by user application
 *		to work with local configuration
 *
 *	This function is invoked by the HTTP server once a hash value of a 
 *	requested file name has been calculated. User application uses this
 *	hash value to check if appropriate file is available to web server.
 *	Appropriate https session entry is then filled accordingly.	
 *
 */
INT16 https_findfile (UINT8 hash, UINT8 ses)
{
	
  /* Access the File table on FLASH with given hash key	*/ 
  unsigned char  file_not_found     = 1;
  unsigned char* file_start_address = (void *)0;
  unsigned short file_length        = 0;
  unsigned short file_pointer       = 0;
  
  unsigned char  i = 0;

	/* Access the File table on FLASH with given hash key	*/
	/* and modify session File parameters					*/		
	for (i=0; FAT[i].hash; i++)
	{
		if (hash == FAT[i].hash)
		{
			file_not_found     = 0;
			file_start_address = (unsigned char *)FAT[i].file_start_address;
			file_length        = FAT[i].file_length;
			file_pointer       = 0;
		}
		else
			continue;
	}
	
		
	if( file_not_found )
	{
		/* File not found, initialize return message */					
		//https[ses].fstart    = 0xFFFFFFFF;
		https[ses].fstart    = (void *)(~0);
		https[ses].funacked  = 0;
		https[ses].flen      = __strlen((UINT8 *)&https_not_found_page[0], 1000);
		https[ses].fpoint    = 0;
		
		return(-1);
	}
	
	/* OK, file found. */	
	
	/* Modify structure	*/
	https[ses].fstart   = file_start_address;
	https[ses].flen     = file_length;
	https[ses].fpoint   = file_pointer;
	https[ses].funacked = 0;
	
	return(1);  	
}

/** \brief Fill network transmit buffer with HTTP headers&data
 * 	\author
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 09.10.2002
 *	\param ses HTTP session identifier
 *	\param buf Pointer to buffer where data is to be stored
 *	\param buflen Length of the buffer in bytes
 *	\return
 *		\li >=0 - Number of bytes written to buffer
 *	\warning 
 *		\li This function <b>MUST</b> be implemented by user application
 *		to work with local configuration
 *
 *	This handlers' job is to fill the buffer with the data that web server
 *	should return back through the TCP connection. This is accomplished
 *	based session identifer and values of variables in appropriate
 *	https entry.
 */
INT16 https_loadbuffer (UINT8 ses, UINT8* buf, UINT16 buflen) 
{
	UINT16 i;
	
//	if( https[ses].fstart == 0xFFFFFFFF )
	if( https[ses].fstart == (void *)(~0) )
	{
		/* Error site asked	*/
		
		kick_WD();
		
		for(i=0; i < (https[ses].flen - https[ses].fpoint); i++)
		{
			if(i >= buflen)
				break;
		
			*buf++ = https_not_found_page[https[ses].fpoint + i];
		
		}
		
		return(i);
	
	}
	
	/* Access some storage media (internal/external flash...)*/
	
	for(i=0; i < (https[ses].flen - https[ses].fpoint); i++)
	{
		if(i >= buflen)
			break;	
		
		kick_WD();

		*buf++ = https[ses].fstart[ https[ses].fpoint + i ];
	
	}
	return(i);
}
