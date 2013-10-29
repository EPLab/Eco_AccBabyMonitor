#ifndef EPL_TRANSCEIVER_ACTION_H__
#define EPL_TRANSCEIVER_ACTION_H__

/*
 * Register Definition
 */
#define RX_PIPE0 	0x00
#define RX_PIPE1	0x01
#define RX_PIPE2	0x02
#define RX_PIPE3	0x03
#define RX_PIPE4	0x04
#define RX_PIPE5 	0x05



/*
 * customized pload or not
 */
#define USRS_PLOAD		0x00
#define AUTO_PLOAD		0x01



/*
 * Action Map
 */
#define EPL_OUTPUT_POWER 	0x01
#define EPL_CHANNEL 		0x02
#define EPL_DATARATE 		0x03
#define EPL_ADDR_WIDTH		0x04
#define EPL_CRC_MODE 		0x05
#define EPL_ARD 			0x06
#define EPL_ARC 			0x07

#define EPL_RX_ADDR_P0		0x10  /**< nRF24L01 receive address data pipe0 */
#define EPL_RX_ADDR_P1		0x11  /**< nRF24L01 receive address data pipe1 */
#define EPL_RX_ADDR_P2		0x12  /**< nRF24L01 receive address data pipe2 */
#define EPL_RX_ADDR_P3		0x13  /**< nRF24L01 receive address data pipe3 */
#define EPL_RX_ADDR_P4		0x14  /**< nRF24L01 receive address data pipe4 */
#define EPL_RX_ADDR_P5		0x15  /**< nRF24L01 receive address data pipe5 */
#define EPL_TX_ADDR			0x16  /**< nRF24L01 transmit address */

#define EPL_RX_PW_P0		0x20  /**< nRF24L01 \# of bytes in rx payload for pipe0 */
#define EPL_RX_PW_P1		0x21  /**< nRF24L01 \# of bytes in rx payload for pipe1 */
#define EPL_RX_PW_P2		0x22  /**< nRF24L01 \# of bytes in rx payload for pipe2 */
#define EPL_RX_PW_P3		0x23  /**< nRF24L01 \# of bytes in rx payload for pipe3 */
#define EPL_RX_PW_P4		0x24  /**< nRF24L01 \# of bytes in rx payload for pipe4 */
#define EPL_RX_PW_P5		0x25  /**< nRF24L01 \# of bytes in rx payload for pipe5 */


#define EPL_AUTOACK_P0		0x30	  /**< nRF24L01 autoack for pipe0 */
#define EPL_AUTOACK_P1		0x31	  /**< nRF24L01 autoack for pipe1 */
#define EPL_AUTOACK_P2		0x32	  /**< nRF24L01 autoack for pipe2 */
#define EPL_AUTOACK_P3		0x33	  /**< nRF24L01 autoack for pipe3 */
#define EPL_AUTOACK_P4		0x34	  /**< nRF24L01 autoack for pipe4 */
#define EPL_AUTOACK_P5		0x35	  /**< nRF24L01 autoack for pipe5 */

#define EPL_DATA_LENGTH_P0 	0x40	  /**< nRF24L01 data_length for pipe0 */
#define EPL_DATA_LENGTH_P1 	0x41	  /**< nRF24L01 data_length for pipe1 */
#define EPL_DATA_LENGTH_P2 	0x42	  /**< nRF24L01 data_length for pipe2 */
#define EPL_DATA_LENGTH_P3 	0x43	  /**< nRF24L01 data_length for pipe3 */
#define EPL_DATA_LENGTH_P4 	0x44	  /**< nRF24L01 data_length for pipe4 */
#define EPL_DATA_LENGTH_P5 	0x45	  /**< nRF24L01 data_length for pipe5 */

#define EPL_DYNPD_LENGTH_P0	0x60  /**< nRF24L01 dynamic payload length for pipe0 */
#define EPL_DYNPD_LENGTH_P1		0x61  /**< nRF24L01 dynamic payload length for pipe1 */
#define EPL_DYNPD_LENGTH_P2	0x62  /**< nRF24L01 dynamic payload length for pipe2*/
#define EPL_DYNPD_LENGTH_P3	0x63  /**< nRF24L01 dynamic payload length for pipe3 */
#define EPL_DYNPD_LENGTH_P4	0x64  /**< nRF24L01 dynamic payload length for pipe4 */
#define EPL_DYNPD_LENGTH_P5	0x65  /**< nRF24L01 dynamic payload length for pipe5 */


#define EPL_GET_PIPE_STATUS	0x50
#define EPL_OPEN_PIPE		0x51
#define EPL_CLOSE_PIPE		0x52

#define EPL_RUN 			0xF1
#define EPL_SHOW_CONFIG		0xF2
#define EPL_SENDER_MODE		0xF3
#define EPL_DUMPER_MODE 	0xF4
#define EPL_EXIT_DUMPER 	0xF5
#define EPL_RUN_SENDER		0xF6
#define EPL_RUN_DUMPER		0xF7
#define EPL_NEW_COUNTER		0xF8
#define EPL_USER_PLOAD		0xF9
/*20110221 celine -add EPL_DYNAMIC_PD */
#define EPL_DYNAMIC_PD	0xFA
#define EPL_QUIT 			0xFF


#endif
