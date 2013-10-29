/**************************************       
              TimerM.c
    Author: Qiang Xie
    Date: 05/24/2005
***************************************/
#include "MOTTYPES.h"
#include "MC9S12NE64.h"
#include "timerM.h"
#include "globalvariables.h"
#include "parser.h"

#define NUMCH 4


UINT8 processThread(char* cmd, UINT16 datalen, UINT32 ts, UINT16 cmdid){
	UINT8 i, j;
	for(i= 0; i< NUMCH; i++){
	       if( tm_used[i] == 0) break;
	}
	if(i == NUMCH) return 0;
	tm_used[i] = 1;
  for(j=0; j < datalen; j++) tcmd[i][j] = cmd[j];
	cmd_len[i] = datalen;
		cmd_id[i] = cmdid;
	//i = i+4;
	
	enable_Timer(i+4, ts);	
	return ts;
}

