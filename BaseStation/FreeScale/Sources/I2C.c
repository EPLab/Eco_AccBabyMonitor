/**************************************       
              I2C.c
    Author: Qiang Xie
    Date: 05/24/2005
***************************************/
#include "MOTTYPES.h"
#include "MC9S12NE64.h"

#define SLAVEADDR 0x5C

/* Sending two bytes data*/
/*NOte: in future, should make this general to send anysize of data packet.*/
void I2Csend(UINT8 data, UINT8 slave){
		 UINT8 i;
		 UINT8 slaveaddr;
		 
		 switch(slave){
		  case 1:
		    slaveaddr = 0x5E;
		    break;
		  case 2:
		    slaveaddr = 0x5a;
		    break;
		  case 3:
		    slaveaddr = 0x5c;
		    break;
		  case 4:
		    slaveaddr = 0x58;
		    break;
		  default:
		    slaveaddr = 0x58;
		    break;
		 }
		// i = 1;
		 IBFD = 0x14;
     //IBSR = 0x00;
     IBCR_IBEN = 1;
    
	//wait until the master bus is free
	  //IBCR_IBIE = 0;
	  while(i){
	  while(IBSR_IBB);   
	  IBCR= 0xB0;
	 
	  IBDR =  slaveaddr; //slaveaddr;
	  while(!IBSR_IBB){};
	  
	  while(!IBSR_TCF){
	  };
	 
	   IBSR_TCF = 0;
	  
	  IBDR = 0x00;
	   
	  while(!IBSR_TCF);
	  
	  IBSR_TCF = 0;
	  IBDR = data;
	 
	  while(!IBSR_TCF){};
	  IBSR_TCF = 0;
	  i = IBSR_RXAK;
	  IBSR = 0x00;
	  IBCR = 0x80;
	 // delay_us(100);
	  }			 
	  
	  	
}

UINT8 I2Crecv(void){
    UINT8 temp;
    UINT8 temp2;
    while(IBSR_IBB); //wait until the master bus is free
    IBCR_MS_SL = 1;
    IBCR_TX_RX = 1;
    IBDR = SLAVEADDR|0x01;
    while(!IBSR_IBB){};
    while(!IBSR_TCF){
	  };
    IBSR_TCF = 0;
    IBCR_TX_RX = 0;
    temp = IBDR;
    //while((temp&0xfe)!=SLAVEADDR);
    temp = IBDR;
    while(!IBSR_TCF){
	  };
	  IBSR_TCF = 0;
	  IBCR_TXAK = 1;
	  temp = IBDR;
	  while(!IBSR_TCF){
	  };
	  IBSR_TCF = 0; 
	  IBCR_MS_SL = 0;
	  temp2 = IBDR;
	  //IBCR = 0xc0;
    return temp;
    
}
