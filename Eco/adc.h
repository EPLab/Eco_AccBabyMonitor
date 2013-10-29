#ifndef _ADC_H
#define _ADC_H

#define X_AXIS			3
#define Y_AXIS			4
#define Z_AXIS			6	

#define Light			7	
#define Temperature		5	 



void adc_init(void);
int adc_read(char pin);

#endif // _ADC_H