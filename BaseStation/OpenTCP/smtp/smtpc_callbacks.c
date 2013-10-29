#include "datatypes.h"
#include "smtp_client.h"

#include <string.h>

char *my_domain   = "Freescale.com";
char *my_sender   = "NE64EVB@Freescale.com";
char *my_receiver = "Somebody@freescale.com"; 
char *my_subject  = "This is a test:";
char *my_data     = "TEST!!!!!.\r\n\r\nTHIS IS AN AUTOMATIC NOTIFICATION, DO NOT REPLY TO THIS EMAIL.\r\n.\r\n";


/** \brief SMTP client error handler
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 20.08.2002
 *
 *	This callback function is called by SMTP Client when there 
 *	happens error of some kind (timeout, losing of connection etc.). It 
 *	indicates that e-mail was not delivered to server.
 */
void smtpc_error (void)
{


}



/** \brief SMTP client success handler
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *
 *	This callback function is called by SMTP Client when the packet
 *	is succesfully delivered to E-mail server.
 */
void smtpc_allok (void)
{
}


/** \brief Fills in local domain information
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *	\param dbuf pointer to buffer to which the domain name will be stored
 *	\return
 *		\li -1 - Error
 *		\li >0 - Number of bytes inserted
 *
 *	This callback function is called by SMTP Client when it wants
 *	to know the local domain. The user is responsible of storing that
 *	domain to destbuf without NULL termination ('\0') and returning
 *	number of bytes on domain.
 */
INT8 smtpc_getdomain (UINT8* dbuf)
{
	(void)memcpy (dbuf, my_domain, strlen(my_domain));
	return (char)strlen(my_domain);
}

 
/** \brief Returns senders' e-mail address
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *	\param dbuf pointer to buffer to which the sender will be stored
 *	\return
 *		\li -1 - Error
 *		\li >0 - Number of bytes inserted
 *
 *	This callback function is called by SMTP Client when it wants
 *	to know the E-mail address of sender. The user is responsible of 
 *	storing that address to destbuf without NULL termination ('\0') 
 *	and returning number of bytes on E-mail address.
 */
INT8 smtpc_getsender (UINT8* dbuf)
{
	(void)memcpy (dbuf, my_sender, strlen(my_sender));
	return (char)strlen(my_sender);
}



/** \brief Returns receivers' e-mail address
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *	\param dbuf pointer to buffer to which the receiver will be stored
 *	\return 
 *		\li -1 - Error
 *		\li >0 - Number of bytes inserted
 *
 *	This callback function is called by SMTP Client when it wants
 *	to know the E-mail address of receiver. The user is responsible of 
 *	storing that address to destbuf without NULL termination ('\0') 
 *	and returning number of bytes on E-mail address.
 */
INT8 smtpc_getreceiver (UINT8* dbuf)
{

	(void)memcpy (dbuf, my_receiver, strlen(my_receiver));
	return (char)strlen(my_receiver);

}

/** \brief Returns subject of the E-mail
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *	\param dbuf pointer to buffer to which the subject will be stored
 *	\return
 *		\li -1 - Error
 *		\li >0 - Number of bytes inserted
 *
 *	This callback function is called by SMTP Client when it wants
 *	to know the subject of E-mail to be sent. The user is responsible 
 *	of storing subject to destbuf without NULL termination ('\0') 
 *	and returning number of bytes inserted.
 */
INT8 smtpc_getsubject (UINT8* dbuf)
{
	(void)memcpy (dbuf, my_subject, strlen(my_subject));
	return (char)strlen(my_subject);	

}


/** \brief Returns e-mail data (message) to be sent
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *	\param dbuf pointer to buffer to which the data will be stored
 *	\param buflen length of data buffer
 *	\return
 *		\li -1 - Error
 *		\li >0 - Number of bytes inserted
 *
 *	This callback function is called by SMTP Client when it wants
 *	to get mail plain data from user. The user is responsible of 
 *	filling dbuf and returning number of bytes assembled. When data
 *	end is reached the function must return (-1) without storing
 *	any bytes to buffer (so just send data untill you don't have
 *	any bytes to sent when callback is made to that function and 
 *	return -1). Do not move read pointer of your data forward before
 *	SMTP makes callback to smtpc_dataacked!
 */
INT16 smtpc_getdata (UINT8* dbuf, UINT16 buflen)
{
buflen++;
	(void)memcpy (dbuf, my_data, strlen(my_data));
	return (short)strlen(my_data);	
}


/** \brief Last data received by remote host
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 12.08.2002
 *
 *	This callback function is called by SMTP Client when TCP has
 *	ensured that the last packet was transmitted succesfully and
 *	next time when smtpc_getdata callback is made new data should be 
 *	assembled
 */
void smtpc_dataacked (void)
{

}

