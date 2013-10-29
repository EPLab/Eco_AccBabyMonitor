#include <Nordic/reg24lu1.h>
//#include <nRF24LU1/cklf.h>
//#include <nRF24LU1/cpu.h>
#include "HAL/hal_usb.h"
#include <HAL/nordic_common.h>
#include "usb_api.h"
#include <EPL/epl_uart.h>


//static uint8_t usize,ubuf[33];

extern uint8_t usize,ubuf[65];

static hal_usb_dev_req_resp_t device_req_cb(hal_usb_device_req* req, uint8_t** data_ptr, uint16_t* size) reentrant;
static void suspend_cb(uint8_t allow_remote_wu) reentrant;
static void resume_cb() reentrant;
static void reset_cb() reentrant;
static uint8_t ep_1_in_cb(uint8_t *adr_ptr, uint8_t* size) reentrant;
static uint8_t ep_1_out_cb(uint8_t *adr_ptr, uint8_t* size) reentrant;

bool ep1_sent, ep1_receive;
volatile usb_state_t usb_state;

void usb_init(void)
{
        hal_usb_init(true, device_req_cb, reset_cb, resume_cb, suspend_cb);
   
        hal_usb_endpoint_config(0x81, 32, ep_1_in_cb);          //bulk EP IN  1
        hal_usb_endpoint_config(0x01, 32, ep_1_out_cb);         //bulk EP OUT 1

        ep1_sent = true;
        ep1_receive = false;
  
        usb_state = USB_AWAKE;
}

void usb_wakeup(void)
{
        hal_usb_wakeup();
        usb_state = USB_AWAKE;
}

usb_state_t usb_get_state()
{
        return usb_state;
}

void usb_wait_for_configuration(void)
{
	int i=0;
        volatile hal_usb_state_t usb_hal_state;
        do
        {
            usb_hal_state = hal_usb_get_state();
			if(i>10)
				usb_hal_state=CONFIGURED;
			i++;
		}
        while(usb_hal_state != CONFIGURED);
}

void usb_send_packet(uint8_t* in_data, uint8_t size)
{
    while(!ep1_sent)
        ;
    ep1_sent = false;
    hal_usb_send_data(0x81, in_data, size);
}

void usb_recv_packet(){ 
    while(!ep1_receive)
        ;
        
    ep1_receive = false;
}

static hal_usb_dev_req_resp_t device_req_cb(hal_usb_device_req* req, uint8_t** data_ptr, uint16_t* size) reentrant
{
        //epl_uart_putstr("driver dec req resp\r\n");
    return NAK;
}


static void suspend_cb(uint8_t allow_remote_wu) reentrant
{
        //epl_uart_putstr("driver suspend\r\n");
        USBSLP = 1; // Disable USB clock (auto clear)

        if (allow_remote_wu == 1)
        {
                // Enable wake-up on USB and USBWU (bit3:0=1010)
                // Enable MCU_WU (bit5:4=10 ) on RTC
                WUCONF = (BIT_5 | BIT_3 | BIT_1);
                usb_state = USB_REM_WU_ENABLE;
        }
        else
        {
                // Enable wake-up on USB and USBWU (bit3:0=1010)
                WUCONF = (BIT_3 | BIT_1);
                usb_state = USB_REM_WU_DISABLE;
        }
}

static void resume_cb() reentrant
{
        //epl_uart_putstr("driver resume\r\n");
        ep1_sent = true;
        ep1_receive = false;
        usb_state = USB_AWAKE;
}

static void reset_cb() reentrant
{
        //epl_uart_putstr("driver reset\r\n");
        ep1_sent = true;
        ep1_receive = false;
        usb_state = USB_AWAKE;
}


static uint8_t ep_1_in_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
{
        //epl_uart_putstr("driver send\r\n");
        ep1_sent = true;
        return 0x60;
}

static uint8_t ep_1_out_cb(uint8_t *adr_ptr, uint8_t* size) reentrant
{
        uint8_t i;
        
        //epl_uart_putstr("driver recv\r\n");
        
        usize = *size;

        for(i = 0;i < usize;i++)
                ubuf[i] = adr_ptr[i];

        /*
        ubuf[usize] = '\0';
        epl_uart_putstr("recv:");
        epl_uart_putstr(ubuf);
        epl_uart_putstr("\r\n");
        */
        
        ep1_receive = true;
        return 0xFF;
}


/** @} */
