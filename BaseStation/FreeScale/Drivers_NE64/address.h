/******************************************************************************
 * 
 *                      (c) Freescale  Inc. 2004 All rights reserved          
 *
 * File Name     : address.h 
 * Description    : This file contains definition of hardware and protocol (IP) 
 *                  addresses of the device
 *
 * Version : 2.1
 * Date    : 02/04/04
 *
 ******************************************************************************/
   

#ifdef ADDRESS_H
#else
#define ADDRESS_H

extern const tU08 hard_addr []; /**< HW addr of our device */
extern const tU08 prot_addr []; /**< IP addr of our device */
extern const tU08 brcs_addr []; /**< IP subnet broadcast */
extern const tU08 netw_mask []; /**< network mask */
extern const tU08 dfgw_addr []; /**< subnet default gateway IP addr */

#define ip_address  prot_addr
#define ip_netmask  netw_mask
#define ip_gateway  dfgw_addr

#endif