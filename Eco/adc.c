#include "reg24e1.h"
#include <misc.h>

void adc_init(void)
{
	//ADCCON = 0x20;                  // Channel 0, NPD=1, ADCRUN=0, EXTREF=0
	ADCCON = 0x30;                  // Channel 0, NPD=1, ADCRUN=0, EXTREF=1
	
	ADCSTATIC &= 0x1c;
//	ADCSTATIC |= 0x03;              // 12bit
	ADCSTATIC |= 0x01;              // 8bit

	//ADCCON &= ~0x80;                // Start..
	//ADCCON |= 0x80;                 // ..new conversion
}

int adc_read(char pin)
//char adc_read(char pin)
{
	//char	tmp;
	int		value = 0;
	//char		value = 0;

	//tmp = ADCCON & 0xf0; 			//select channel	
	//ADCCON = tmp | (pin & 0x0f);
	//ADCCON = 0x30 + pin;
	ADCCON = 0xB0 + pin;	

	ADCCON &= ~0x80;				// Start.. CSTARTN ->  LOW
	ADCCON |= 0x80;					// ..new conversion	-> CSTARTN -> HIGH
	//delay10us(50);

	while((EXIF & 0x10) == 0);		// Wait until ADC conversion complete
	EXIF &= ~0x10;					// Clear ADC completion bit
	
	
	/*
	value = ADCDATAH;					// Read ADC data
	value <<= 4;
	value |= (ADCDATAL >> 4) & 0xf;
	*/
	
	/*								 	//Read 12 bits ADC
	value = ( ADCDATAH << 4);
	value +=  ( ADCDATAH >> 4);
	*/


	value = ADCDATAH;
	//ADCCON &= ~0x80;				// Start..
	//ADCCON |= 0x80;					// ..new conversion


	return value;
}
