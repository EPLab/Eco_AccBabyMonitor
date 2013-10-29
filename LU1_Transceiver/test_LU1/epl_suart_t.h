/** @file
 * Interface functions for the soft UART serial interface
 *
 * @author Jackal Chen <wtg.design@gmail.com>
 * this lib use GPIO P04 & P05 so if you use this lib
 * remember not to use these two GPIO ports for other use
 *
 * version 1.0 at 2008/07/11 by Jackal
 */

#ifndef EPL_SUART_T_H__
#define EPL_SUART_T_H__

#define STX P04
#define SRX P05
//#define STX P02
//#define SRX P01

#include <stdint.h>

void timer_isr() interrupt 1;

/** Function to initialize the UART.
 * This function initializes the UART for interrupt operation. An 8 byte receive
 * buffer and an 8 byte transmit buffer is used.
 * @param baud a constant for the baud rate (0 = 600 Baud, ..., 7=57600 baud)
 */
void epl_suart_init();

/** Function to write a character to the UART transmit buffer.
 * @param ch Character to write
 */
void epl_suart_putchar(uint8_t ch);


/** Function to write a string to the UART transmit buffer.
 * @param str string to write
 */
void epl_suart_putstr(uint8_t* str);


/** Function to read a character from the UART receive buffer.
 * @return Character read
 */
uint8_t epl_suart_getchar(void);

/** Function to write a decimal number to UART transmit buffer (written by Jackal@EPL).
 *  * @param num the number to be written
 *   */
void epl_suart_putint(uint16_t num);


/** Function to write a hex humber to UART transmit buffer (written by Jackal@EPL).
 *  * @param num the number to be written
 *   */
void epl_suart_puthex(uint16_t num);


#endif
