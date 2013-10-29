#ifndef INCLUDE_HTTP_SERVER_H
#define INCLUDE_HTTP_SERVER_H

#include "datatypes.h"

/**	\def NO_OF_HTTP_SESSIONS
 *	\brief Defines number of simultaneous HTTP sessions
 *
 *	Change this define to change how many simultaneous HTTP sessions will
 *	be possible at any given time. Note that this will require at least
 *	as much TCP sockets, so change #NO_OF_TCPSOCKETS also!
 */
#define NO_OF_HTTP_SESSIONS		3

/**	\def HTTPS_SERVERPORT
 *	\brief HTTP server port on which we'll listen
 *
 *	This defines on what TCP port the HTTP server will listen for incoming
 *	connections/requests. For HTTP standard port is 80.
 */
#define HTTPS_SERVERPORT		80


#define HTTPS_STATE_FREE		1	/**< HTTP Server state: session entry free
									 *	and available
									 */
#define HTTPS_STATE_RESERVED	2	/**< HTTP Server state: session entry is
									 *	reserved and therefore not available
									 */
#define HTTPS_STATE_ACTIVE		3	/**< HTTP Server state: session entry (and
									 *	the session itself) are active.
									 */
									 
/** \struct http_server_state http_server.h
 *	\brief Structure that holds all the necessary state information for 
 *		session management
 *
 *	All the necessary information for HTTP session state management by the
 *	HTTP server is stored here. See individual field documentation for more
 *	info.
 */
struct http_server_state
{
	/**	\brief Session state
	 *
	 *	This variable holds current sessions' state which can be one of the
	 *	following:
	 *		\li #HTTPS_STATE_FREE
	 *		\li	#HTTPS_STATE_RESERVED
	 *		\li #HTTPS_STATE_ACTIVE
	 */
	UINT8 state;
	
	/**	\brief TCP socket used for TCP communication
	 *
	 *	This variable holds a handle to TCP socket that is used to achieve
	 *	data transfer.
	 */
	UINT8 ownersocket;
	
	/**	\brief File start
	 *
	 *	This variable holds information about the file start address. This 
	 * 	is highlyconfiguration-dependant (file system chosen, etc..)
	 *
	 *	<b> File address can not start from zero!!! (Data won't be sent
	 *	by HTTP server in this case) </b>
	 */
#if defined(_HCS12)
	UINT8 *fstart;
#else
	UINT32 fstart;
#endif

	/**	\brief File length
	 *
	 *	This variable holds file length information. It is used by the HTTP
	 *	server to determine when the entire file has been sent.
	 */
	UINT32 flen;

	/**	\brief File pointer
	 *
	 *	Pointer to a current position inside the file that is beeing sent 
	 *	over the appropriate HTTP session.
	 */	
	UINT32 fpoint;
	
	/**	\brief Number of unacknowledged HTTP bytes previously sent
	 *
	 *	This variable holds information about the number of previously sent
	 *	and still unacknowledged bytes. This is needed to reliably determine,
	 *	in case data needs to be regenerated, how much bytes to regenerate or,
	 *	in case data has been acknowledged, how much to advance the fpoint
	 *	variable.
	 */	
	UINT16 funacked;

};

extern struct http_server_state https[];

INT32 https_eventlistener   (INT8, UINT8, UINT32, UINT32);
INT8  https_init            (void);
void  https_run             (void);
void  https_deletesession   (UINT8);
INT16 https_searchsession   (UINT8);
INT16 https_bindsession     (UINT8);
void  https_activatesession (UINT8);
INT16 https_calculatehash   (UINT32);
INT16 https_findfile        (UINT8, UINT8);
INT16 https_loadbuffer      (UINT8, UINT8*, UINT16);

#endif
