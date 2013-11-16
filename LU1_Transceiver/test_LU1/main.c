/*
 * Celine Liu<tzuchung1030@gmail.com>
 * LU1_USB_Transceiver (multi pipe)
 *
 * First Edition: 2011/01/06
 */


#include <Nordic/reg24lu1.h>
#include <stdint.h>
#include "usb_api.h"
#include "HAL/hal_usb.h"
#include "HAL/usb_desc.h"
#include <EPL/epl_utils.h>
#include <HAL/hal_nrf.h>
#include "epl_rf_en.h"
#include <HAL/hal_flash.h>
#include <epl/epl_uart.h>
#include "transceiver_action.h"

#include <HAL/hal_spi.h>
//version
#define U_VERSION "v1.0 "

#define PLOAD_LEN 32

#define LED_Toggle()	do{P0 ^= 0x30;} while (0)
#define LED0_Toggle()	do{P0 ^= 0x10;} while (0)
#define LED1_Toggle()	do{P0 ^= 0x20;} while (0)
#define LED_Blink(ms)	do{ \
	P0 ^= 0x30;		\
	mdelay(ms);		\
	P0 ^= 0x30;		\
	mdelay(ms);		\
} while (0)

//global buffer for USB OUT data
uint8_t ubuf[65];
uint8_t usize;
uint8_t xdata packet[PLOAD_LEN]; // Buffer for sending

idata struct epl_lu1_rf_en_config rf_cfg_data = { { 118 }, //-- RF channel --//
		{ 5 }, //-- Address width --//
		{ 0x65, 0x65, 0x65, 0x65, 0x65 }, //-- The destination address. --//
		{ 0x65, 0x65, 0x65, 0x65, 0x65 }, //-- The address of pipe PRX, the default is pipe0. --//
		{ PLOAD_LEN }, //-- RX payload data length --//
		{ RF_EN_1MBPS }, //-- RF Datarate --//
		{ RF_EN_CRC_16BIT }, //-- CRC mode bit --//
		{ RF_EN_AUTO_ACK_ON }, //-- Auto ack bit --//
		{ 15 }, //-- Auto retransmit --//
		{ 250 } //-- Auto retransmit delay --//
};

idata struct epl_lu1_rf_en_config * idata cfg = &rf_cfg_data;

void array_cp(unsigned char *dst_array, unsigned char *src_array, int len);

void main(void) {
	int i = 0; // local counter
	int total_pkt_count = 1;
	int addr_width = 5;
	int customized_plen = 0;
	int pipe_num = 6;
	epl_rf_en_auto_ack_t auto_ack = 0;
	//int mode = 1;		// 1 for sender mode, 2 for dumper mode

	// new params
	unsigned char pipe_source;		// used to store pipe_source number
	unsigned char ACKbuf[] = "ACK";
	unsigned char temp_buf[34]; // used for dumper to get RF packets from RX FIFO
	unsigned char temp_addr[5];
	unsigned char data_length = 0;
	unsigned char dynpd_pipe;
	unsigned char addr_buf[5];
	// set pin direction
	P0EXP = 0x00;
	P0ALT = 0x00;
	P0DIR = 0x00;

	// uart init
	epl_uart_init(UART_BAUD_57K6);
	//init usb connection
	usb_init(); // Initialize USB
	EA = 1; // Enable global IRQ
	//Start RF tx mode
	epl_rf_en_quick_init(cfg);

	//Clear TX FIFO
	hal_nrf_write_reg(FLUSH_TX, 0);
	hal_nrf_write_reg(FLUSH_RX, 0);

	hal_nrf_lock_unlock();
	hal_nrf_enable_dynamic_pl();

	LED_Blink(20);
	epl_uart_putstr("start!");
	while (1) {
		usb_recv_packet();
		switch (ubuf[1]) {

		case EPL_SENDER_MODE:
			customized_plen = 0;
			for (i = 0; i < PLOAD_LEN; i++)
				packet[i] = i + 9;
			hal_nrf_close_pipe(HAL_NRF_PIPE1);
			hal_nrf_close_pipe(HAL_NRF_PIPE2);
			hal_nrf_close_pipe(HAL_NRF_PIPE3);
			hal_nrf_close_pipe(HAL_NRF_PIPE4);
			hal_nrf_close_pipe(HAL_NRF_PIPE5);
			break;

		case EPL_DUMPER_MODE:

			hal_nrf_close_pipe(HAL_NRF_PIPE1);
			hal_nrf_close_pipe(HAL_NRF_PIPE2);
			hal_nrf_close_pipe(HAL_NRF_PIPE3);
			hal_nrf_close_pipe(HAL_NRF_PIPE4);
			hal_nrf_close_pipe(HAL_NRF_PIPE5);
			break;

		case EPL_OUTPUT_POWER: 			//Host:set_output_power
			hal_nrf_set_output_power(ubuf[2]);
			epl_uart_putstr("EPL_OUTPUT_POWER\n");
			usb_send_packet(ACKbuf, 3);
			epl_uart_putstr("EPL_OUTPUT_POWER     END\n");
			break;

		case EPL_CHANNEL:
			hal_nrf_set_rf_channel(ubuf[2]);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATARATE:
			hal_nrf_set_datarate(ubuf[2]);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_ADDR_WIDTH:
			addr_width = (int) ubuf[2];
			hal_nrf_set_address_width(ubuf[2]);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P0:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P1:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P2:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P3:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P4:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_AUTOACK_P5:
			auto_ack = ubuf[2];
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATA_LENGTH_P0:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATA_LENGTH_P1:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE1, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATA_LENGTH_P2:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE2, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATA_LENGTH_P3:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE3, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;


		case EPL_DATA_LENGTH_P4:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE4, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_DATA_LENGTH_P5:
			data_length = (int) ubuf[2];
			epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE5, temp_addr, data_length, auto_ack);
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_CRC_MODE:
			if (ubuf[2] == 0)
				hal_nrf_set_crc_mode(HAL_NRF_CRC_OFF);
			else if (ubuf[2] == 2)
				hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT);
			else if (ubuf[2] == 3)
				hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);
			else
				;

			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_RX_ADDR_P0:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			hal_nrf_set_address(HAL_NRF_PIPE0, temp_addr);
			epl_rf_en_set_dst_addr(temp_addr);

			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_RX_ADDR_P1:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			usb_send_packet(ACKbuf, 3);
			break;
		case EPL_RX_ADDR_P2:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			usb_send_packet(ACKbuf, 3);
			break;
		case EPL_RX_ADDR_P3:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			usb_send_packet(ACKbuf, 3);
			break;
		case EPL_RX_ADDR_P4:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			usb_send_packet(ACKbuf, 3);
			break;
		case EPL_RX_ADDR_P5:
			for (i = 0; i < addr_width; i++) {
				temp_addr[i] = ubuf[i + 2];
			}
			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_USER_PLOAD:
			if (ubuf[2] == USRS_PLOAD) {
				customized_plen = (int) ubuf[3];

				for (i = 0; i < customized_plen; i++) {
					packet[i] = ubuf[i + 4];
				}
			} else {
				customized_plen = 0;

				for (i = 0; i < PLOAD_LEN; i++) {
					packet[i] = i + 9;
				}
			}

			usb_send_packet(ACKbuf, 3);
			break;

		case EPL_NEW_COUNTER:
			total_pkt_count = 1;
			usb_send_packet(ACKbuf, 3);
			break;

		/*20110221 celine*/
		case EPL_DYNAMIC_PD:
			dynpd_pipe = (int)ubuf[2];
			if ((int)ubuf[3] == 01){
				//hal_nrf_setup_dyn_pl(dynpd_pipe);
				hal_nrf_write_reg(DYNPD, (1<<dynpd_pipe) | hal_nrf_read_reg(DYNPD));
			} else {
				//hal_nrf_lock_unlock();
				//hal_nrf_enable_dynamic_pl();
				hal_nrf_write_reg(DYNPD, ~(1<<dynpd_pipe) & hal_nrf_read_reg(DYNPD));
			}

			usb_send_packet(ACKbuf, 3);
			break;
		/**/
		case EPL_RUN_SENDER:
			epl_rf_en_enter_tx_mode();
			// clear Tx irq
			hal_nrf_clear_irq_flag(HAL_NRF_TX_DS);
			hal_nrf_clear_irq_flag(HAL_NRF_MAX_RT);

			if (ubuf[2] == AUTO_PLOAD) {
				epl_uart_putstr("\nauto pload\r\n");
				packet[0] = total_pkt_count++;
				epl_rf_en_send(packet, data_length);

			} else {
				epl_uart_putstr("\nusrs pload\r\n");
				epl_rf_en_send(packet, customized_plen);
			}
			LED_Blink(10);

			array_cp(temp_buf, ACKbuf, 3);
			temp_buf[3] = hal_nrf_read_reg(OBSERVE_TX) & 0x0F;
			usb_send_packet(temp_buf, 4);
			epl_rf_en_enter_rx_mode();
			break;

		case EPL_RUN_DUMPER:
			hal_nrf_clear_irq_flag(HAL_NRF_RX_DR);
			hal_nrf_flush_rx();
			epl_rf_en_enter_rx_mode();
			while (1) {
				if (ubuf[1] == 0xf5) { // Host wants to terminate
					epl_uart_putstr("Terminate !\r\n");
					break;
				}else if (hal_nrf_rx_fifo_empty() == 0) { // Rx_fifo is not empty
					LED0_Toggle();
					pipe_source = hal_nrf_get_rx_data_source();
					hal_nrf_read_rx_pload(temp_buf);

					// pending the data source on last byte
					temp_buf[32] = pipe_source;
					if(hal_nrf_read_reg(DYNPD)>>(int)pipe_source)
						temp_buf[33] = hal_nrf_read_reg(RD_RX_PLOAD_W);
					else
						temp_buf[33] = hal_nrf_read_reg(RX_PW_P0+pipe_source);
//					epl_uart_putstr("temp_buf[33] = ");
//					epl_uart_puthex(temp_buf[33]);
//					epl_uart_putstr("\r\n");
					usb_send_packet(temp_buf, 34);

					if((hal_nrf_read_reg(STATUS))&0x10){
						hal_nrf_write_reg(FLUSH_TX, 0);
					}
					LED0_Toggle();
				}
			}
			break;

		case EPL_SHOW_CONFIG:
			epl_uart_putstr("\r\n0. CONFIG = ");
			epl_uart_puthex(hal_nrf_read_reg(CONFIG));
			epl_uart_putstr("\r\n1. RF_CH = ");
			epl_uart_puthex(hal_nrf_read_reg(RF_CH));
			epl_uart_putstr("\r\n2. EN_AA = ");
			epl_uart_puthex(hal_nrf_read_reg(EN_AA));
			epl_uart_putstr("\r\n3. EN_RXADDR = ");
			epl_uart_puthex(hal_nrf_read_reg(EN_RXADDR));
			epl_uart_putstr("\r\n4. TX_ADDR = ");
			hal_nrf_read_multibyte_reg(HAL_NRF_TX, addr_buf);
			epl_uart_puthex(addr_buf[0]);
			epl_uart_puthex(addr_buf[1]);
			epl_uart_puthex(addr_buf[2]);
			epl_uart_puthex(addr_buf[3]);
			epl_uart_puthex(addr_buf[4]);
			epl_uart_putstr("\r\n4. RX_ADDR_PO = ");
			hal_nrf_read_multibyte_reg(HAL_NRF_PIPE0, addr_buf);
			epl_uart_puthex(addr_buf[0]);
			epl_uart_puthex(addr_buf[1]);
			epl_uart_puthex(addr_buf[2]);
			epl_uart_puthex(addr_buf[3]);
			epl_uart_puthex(addr_buf[4]);
			epl_uart_putstr("\r\n   RX_ADDR_P1 = ");
			hal_nrf_read_multibyte_reg(HAL_NRF_PIPE1, addr_buf);
			epl_uart_puthex(addr_buf[0]);
			epl_uart_puthex(addr_buf[1]);
			epl_uart_puthex(addr_buf[2]);
			epl_uart_puthex(addr_buf[3]);
			epl_uart_puthex(addr_buf[4]);
			epl_uart_putstr("\r\n   RX_ADDR_P2 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P2));
			epl_uart_putstr("\r\n   RX_ADDR_P3 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P3));
			epl_uart_putstr("\r\n   RX_ADDR_P4 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P4));
			epl_uart_putstr("\r\n   RX_ADDR_P5 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_ADDR_P5));
			epl_uart_putstr("\r\n5. RX_PW_P0 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P0));
			epl_uart_putstr("\r\n   RX_PW_P1 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P1));
			epl_uart_putstr("\r\n   RX_PW_P2 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P2));
			epl_uart_putstr("\r\n   RX_PW_P3 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P3));
			epl_uart_putstr("\r\n   RX_PW_P4 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P4));
			epl_uart_putstr("\r\n   RX_PW_P5 = ");
			epl_uart_puthex(hal_nrf_read_reg(RX_PW_P5));
			epl_uart_putstr("\r\n6. RF_SETUP = ");
			epl_uart_puthex(hal_nrf_read_reg(RF_SETUP));
			epl_uart_putstr("\r\n7. STATUS = ");
			epl_uart_puthex(hal_nrf_read_reg(STATUS));
			epl_uart_putstr("\r\n8 .DYNPD = ");
			epl_uart_puthex(hal_nrf_read_reg(DYNPD));
			epl_uart_putstr("\r\n9. FEATURE = ");
			epl_uart_puthex(hal_nrf_read_reg(FEATURE));
		default:
			break;
		}// end switch case
		mdelay(5);


	}// end while
}

void array_cp(unsigned char *dst_array, unsigned char *src_array, int len) {
	int i = 0;

	for (i = 0; i < len; i++)
		dst_array[i] = src_array[i];
}
