#ifndef	__RF24G__H__
#define	__RF24G__H__

#include "MC9S12NE64.h"
#include "MOTTYPES.h"
//#include "io.h"

#define	RF24G_ESC	0	// disable esc by default

#define	RF24G_MAX_PAYLOAD	29

void	init_rf24g_send(void);

void	init_rf24g_recv(void);

void	rf24g_send(char *p, int, int);

int	rf24g_recv(char *p);

//void reset_recv(void);


char	init_rf24g_parameter(int, int, int, int, char);


//extern	unsigned char	config_string[];


#define	RF24G_CONFIG_LEN_RECEIVE	7
#define	RF24G_CONFIG_LEN_TRANSMIT	6
#define	RF24G_CONFIG_LEN	7

#define	RF24G_IDLE	-1
#define	RF24G_TX	0x00
#define	RF24G_RX	0x01

#define	RF24G_PAYLOAD	27


/*
#define	RF24G_PAYLOAD_BIT2	(config_string_receive[0])
#define	RF24G_PAYLOAD_BIT	(config_string_receive[4]*8)


#define	RF24G_CHANNEL2	(config_string[6])
#define	RF24G_CHANNEL	(config_string[11])
#define	RF24G_POWER	(config_string[13] & 0x03)
#define	RF24G_FREQ	(config_string[14] >> 1)
#define	RF24G_MODE	(config_string[14] & 0x01)

#define	SET_RF24G_PAYLOAD_BIT(payload)	(RF24G_PAYLOAD_BIT = payload)
#define	SET_RF24G_PAYLOAD_BIT2(payload)	(RF24G_PAYLOAD_BIT2 = payload)
#define	SET_RF24G_CHANNEL(channel)	(RF24G_CHANNEL = channel)
#define	SET_RF24G_CHANNEL2(channel)	(RF24G_CHANNEL2 = channel)
#define	SET_RF24G_POWER(power)	(config_string[13] &= 0xfc,  config_string[13] |= power)
#define	SET_RF24G_FREQ(freq)	(config_string[14] &= 0x01, config_string[14] |= (freq << 1))
#define	SET_RF24G_MODE(mode)	(config_string[14] &= 0xfe, config_string[14] |= mode)
*/

#define	RF24G_MODE_STR	(RF24G_MODE == RF24G_TX? "TX" : "RX")

#define	RF24G_CLOCK_TICK	{SET_PIN_HIGH(RF24G_CLK1); RF24G_CLOCK_DELAY; SET_PIN_LOW(RF24G_CLK1); RF24G_CLOCK_DELAY;}
#define	RF24G_CLOCK2_TICK	{SET_PIN_HIGH(RF24G_CLK2); RF24G_CLOCK_DELAY; SET_PIN_LOW(RF24G_CLK2); RF24G_CLOCK_DELAY;}

#endif
