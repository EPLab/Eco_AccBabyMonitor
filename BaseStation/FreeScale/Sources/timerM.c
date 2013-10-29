/**************************************       
              TimerM.c
    Author: Qiang Xie
    Date: 05/24/2005
***************************************/
#include "MOTTYPES.h"
#include "MC9S12NE64.h"
//#include "timerM.h"


void initTimerM(void){
	//set prescaler value
 	TSCR2_PR2 = 1;
  TSCR2_PR1 = 1;
  TSCR2_PR0 = 1;
	TFLG1 = 0xff;	
}

void enable_Timer(UINT8 ch, UINT32 val){
	
	switch(ch){
		case 4:
			//PTG_PTG0=1;
			//initTimerM();
			TIOS_IOS4 =1;
			TIE_C4I = 1;
			TC4 =val;
			break;
		case 5:
			TIOS_IOS5 =1;
			TIE_C5I = 1;
			TC5 = val;
			break;
		case 6:
			TIOS_IOS6 =1;
			TIE_C6I = 1;
			TC6 = val;
			break;
		case 7:
			TIOS_IOS7 =1;
			TIE_C7I = 1;
			TC7 = val;
			break;	
	}
	TSCR1 = 0x90;
}

void disbale_Timer(UINT8 ch){
	switch(ch){
		case 4:
			TIE_C4I = 0;
			break;
		case 5:
			TIE_C5I = 0;
			break;
		case 6:
			TIE_C6I = 0;
			break;
		case 7:
			TIE_C7I = 0;
			break;	
	}
}
