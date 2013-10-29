#ifndef	__RF24G-FREESCALE__H__
#define	__RF24G-FREESCALE__H__

#include "io.h" 


// macros to join symbols
#define	DDR(x)	DDR##x
#define	PORT(x)	PORT##x
#define	PIN(x)	PIN##x

// define pins
#define RF24G_DATA1_OUT    'S'
#define RF24G_DATA1_OUT_PIN 5 

#define RF24G_DATA1_IN      'S' 
#define RF24G_DATA1_IN_PIN   4 

#define RF24G_CLK1      'S' 
#define RF24G_CLK1_PIN   6 

#define RF24G_DR1       'G' 
#define RF24G_DR1_PIN    2 

#define RF24G_CS        'G'
#define RF24G_CS_PIN    5

#define RF24G_CE        'G'
#define RF24G_CE_PIN    0

#define DEBUG_SIG       'G'
#define DEBUG_SIG_PIN    7

/**/
#define DEBUG_SIG2       'S'
#define DEBUG_SIG2_PIN    7
/**/


// not used so far, make it the same as channel 1
#define RF24G_DATA2	RF24G_DATA1
#define RF24G_DATA2_PIN	RF24G_DATA1_PIN

#define RF24G_CLK2	RF24G_CLK1
#define RF24G_CLK2_PIN	RF24G_CLK1_PIN

#define RF24G_DR2	RF24G_DR1
#define RF24G_DR2_PIN	RF24G_DR1_PIN


#define	SET_PIN_HIGH(signal)	assign_IOval(signal, signal##_PIN, 1)
#define	SET_PIN_LOW(signal)	assign_IOval(signal, signal##_PIN, 0)
#define	BIT_TEST(port,bit)	((port & (1<<bit)) >> bit)	// get bit in port


#define	IN	0
#define	OUT	1

#define	SET_DDR(signal, value)  assign_IODir(signal, signal##_PIN, value) 	
#define SET_PIN(signal, value)	assign_IOval(signal, signal##_PIN, value)
#define	GET_PIN(signal)   query_IO(signal, signal##_PIN)

#define	RF24G_CLOCK_DELAY	// do nothing here, already slow enough

#endif
