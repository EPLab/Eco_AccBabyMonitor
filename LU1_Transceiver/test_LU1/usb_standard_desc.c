#include <HAL/nordic_common.h>
#include <HAL/hal_usb_desc.h>
#include <HAL/usb_desc.h>


//must define this
#define MAX_PACKET_SIZE_EP0 0x0020
#define EP1_PACKET_SIZE         0x0040

#define UPID 0x5677

code const hal_usb_dev_desc_t g_usb_dev_desc =
{
  sizeof(hal_usb_dev_desc_t),         // bLength
  0x01,                               // bDescriptorType
  0x0200,                                 // bcdUSB
  //SWAP(0x0200),
  0x00,                               // bDeviceClass
  0x00,                               // bDeviceSubClass
  0x00,                               // bDeviceProtocol
  MAX_PACKET_SIZE_EP0,                // bMaxPacketSize0
  //SWAP(MAX_PACKET_SIZE_EP0),
  VID,                          // idVendor (Nordic )
  UPID,                         // idProduct
  0x0100,                       // bcdDevice version
  0x01,                               // iManufacturer
  0x02,                               // iProduct
  0x00,                               // iSerialNumber
  0x01                                // bNumConfigurations
};

/*
code const hal_usb_dev_desc2_t g_usb_dev_desc2 =
{
  sizeof(hal_usb_dev_desc2_t),         // bLength
  0x01,                               // bDescriptorType
  0x0200,                                 // bcdUSB
  0x00,                               // bDeviceClass
  0x00,                               // bDeviceSubClass
  0x00,                               // bDeviceProtocol
  MAX_PACKET_SIZE_EP0,                // bMaxPacketSize0
  0x01,                                // bNumConfigurations
  0x00
};
*/

code const usb_conf_desc_templ_t g_usb_conf_desc =
{
  { // configuration_descriptor hid_configuration_descriptor
    sizeof(hal_usb_conf_desc_t),         // Length
    0x02,                                                               // Type 
    //32,
    sizeof(usb_conf_desc_templ_t),     // Total length
    0x01,                               // NumInterfaces
    0x01,                               // bConfigurationValue
    0x00,                               // iConfiguration
    0xA0,                               // bmAttributes (self-powered + Remote Wakeup)
    0x32                                // MaxPower (in 2mA units) = 50 * 2mA = 100mA
  },
  { // interface_descriptor
    sizeof(hal_usb_if_desc_t),          // Length
    0x04,                               // bDescriptorType
    0x00,                               // bInterfaceNumber
    0x00,                               // bAlternateSetting
    0x02,                               // bNumEndpoints
    0xFF,                               // bInterfaceClass 
    0x01,                               // bInterfaceSubClass
    0x00,                               // bInterfaceProcotol
    0x00                                // iInterface
  },
  { // endpoint_descriptor hid_endpoint_in_descriptor
    sizeof(hal_usb_ep_desc_t),          // Length
    0x05,                               // bDescriptorType
    0x81,                               // bEndpointAddress IN
    0x02,                               // bmAttributes - transfer type
    EP1_PACKET_SIZE,                    // MaxPacketSize (LITTLE ENDIAN)
    //SWAP(EP1_PACKET_SIZE),
    0x00                                   // bInterval
  },
  { // endpoint_descriptor hid_endpoint_in_descriptor
    sizeof(hal_usb_ep_desc_t),          // Length
    0x05,                               // bDescriptorType
    0x01,                               // bEndpointAddress OUT
    0x02,                               // bmAttributes - transfer type
    EP1_PACKET_SIZE,              // MaxPacketSize (LITTLE ENDIAN)
    //SWAP(EP1_PACKET_SIZE),
    0x00                                   // bInterval
  }
};



#define USB_STRING_IDX_1_DESC "Nordic Semiconductor"
#define USB_STRING_IDX_2_DESC "Eco Uploader"

code uint8_t g_usb_string_desc_1[] = {
    sizeof(USB_STRING_IDX_1_DESC) * 2, 
    0x03, 
    'N',00,
    'o',00,
    'r',00,
    'd',00,
    'i',00,
    'c',00,
    ' ',00,
    'S',00,
    'e',00,
    'm',00,
    'i',00,
    'c',00,
    'o',00,
    'n',00,
    'd',00,
    'u',00,
    'c',00,
    't',00,
    'o',00,
    'r',00
};

code uint8_t g_usb_string_desc_2[] = {
    sizeof(USB_STRING_IDX_2_DESC) * 2, 
    0x03, 
    'E',00,
    'c',00,
    'o',00,
    ' ',00,
    'U',00,
    'p',00,
    'l',00,
    'o',00,
    'a',00,
    'd',00,
    'e',00,
    'r',00
};

code usb_string_desc_templ_t g_usb_string_desc = {{
    g_usb_string_desc_1,
    g_usb_string_desc_2
}};



/** @} */
