#ifndef _TIMERM_H_
#define _TIMERM_H_
void initTimerM(void);
void enable_Timer(UINT8 ch, UINT32);
void disbale_Timer(UINT8 ch);
UINT32 get_Timer(UINT8 ch);
//UINT8 get_Timer(void);


#endif
