#ifndef INCLUDE_ETHERNET_H
#define INCLUDE_ETHERNET_H


/* Symbolic constants	*/

#define	ETH_ADDRESS_LEN	6

/* Protocol Constants	*/

#define	ETH_HEADER_LEN		14
#define ETH_CHIP_HEADER_LEN	4
#define	ETH_MTU				1500

#define	PROTOCOL_IP			0x0800			/**< IP over Ethernet	*/
#define PROTOCOL_IPv6		0x86DD			/**< IPv6 over Ethernet	*/
#define PROTOCOL_ARP		0x0806			/**< ARP over Ethernet 	*/

/* Buffer addresses */
#define	ARP_BUFFER	0x5F	/**< 256 byte Tx for ARP 		 */
#define	ICMP_BUF	0x4D	/**< 1536 byte Tx for ICMP	 */
#define	TCP_BUF		0x53	/**< 1536 byte Tx for TCP		 */
#define	UDP_BUF		0x59	/**< 1536 byte Tx for UDP		 */

/** \struct ethernet_frame ethernet.h
 *	\brief Ethernet packet header fields
 *
 *	This structure holds information about the Ethernet packets. In
 *	addition to standard Ethernet header (destination HW address, source
 *	HW address, frame size and protocol), buff_index is added. This variable
 *	is used by higher level protocols (IP, ARP or other) to initialize
 *	reading of the Ethernet packet by invoking NETWORK_RECEIVE_INITIALIZE
 *	macro to initialize reading of the data carried in the Ethernet packet (
 *	not the Ethernet header itself!).
 */
struct ethernet_frame
{
	UINT8	destination[ETH_ADDRESS_LEN];	/**< destination hardware address
											 *	 as read from the received
											 *	 ethernet packet
											 */
	UINT8	source[ETH_ADDRESS_LEN];		/**< source hardware address
											 *	 as read from the received
											 *	 ethernet packet
											 */
	UINT16	frame_size;						/**< size of the received
											 *	 Ethernet packet
											 */	
	UINT16	protocol;						/**< protocol field of the
											 * 	 Ethernet header. For now we
											 *	 work with:
											 *		\li PROTOCOL_IP	- 0x0800
											 *		\li PROTOCOL_ARP - 0x0806
											 */
	UINT16	buf_index;						/**< Address in the Ethernet
											 * 	 controllers buffer where
											 *	 data can be read from
											 */

};

/* API prototypes	 */

#endif


