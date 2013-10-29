#ifndef USB_API_H__
#define USB_API_H__

#include <stdint.h>
#include <stdbool.h>
#include <EPL/epl_flash.h>

typedef enum
{
 USB_AWAKE,
 USB_REM_WU_ENABLE,
 USB_REM_WU_DISABLE,
} usb_state_t;

void usb_init(void);

/** Initiates a remote wakeup of the USB Host.
 * This is a wrapper function for #hal_usb_wakeup
 */
void usb_wakeup(void);

usb_state_t usb_get_state();

/** Checks the USB wakeup status.
 * The check is perforemed on the Host Wakeup status bit.
 * @return The host has woken up (true or false)
 */
bool usb_has_woken(void);

/** Waits for the USB interface to be configured.
 * Calling this function will halt the program and wait until the USB interface
 * goes into the CONFIGURED state.
 */
void usb_wait_for_configuration(void);

/** Sends data to the host.
 * @param in_data Pointer to the buffer containg data to send
 * @param size Buffer size in bytes
 */
void usb_send_packet(uint8_t* in_data, uint8_t size);

/** Receive data from the host.
 */
void usb_recv_packet();

#endif // USB_API_H__

/** @} */
