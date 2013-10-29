/**************************************       
    SPI Communication 
  
    Author : Chongjing Chen
    Date: 06/25/2006         
   
***************************************/


#include "MOTTYPES.h"
#include "MC9S12NE64.h"
#include "spi.h"
#define OSC1_EN PTG_PTG6
#define OSC2_EN PTG_PTG3
#define OSC3_EN PTG_PTG5
#define OSC1_EN_DDR DDRG_DDRG6
#define OSC2_EN_DDR DDRG_DDRG3
#define OSC3_EN_DDR DDRG_DDRG5

//pg2-pg3
//pg6-pg5
//pg1-pg6
void SPIsendC(INT8 data);
void SPIsend3(INT8 data, UINT8 port);
void SPIinit(void){
  
  DDRS = DDRS|0xE0;
  //PTS = PTS | 0x80;
  SPICR1 = 0b01010000;
  SPICR2 = 0; 
  
  //SPIBR= 0b00000111;         // lower speed 97.6kHz
  //SPIBR = 0x04;      //stable speed 781.25kHz
  //SPIBR= 0b00100010 ; //   stable speed 1MHz                                                                                                                                                                                                   SPIBR = 0b010010;		//just make  speed 1Mhz
  //SPIBR	=	0b01000001;	  //over clock speed 1.25Mhz
  //SPIBR	=	0b01110000;	  //over clock speed 1.56Mhz
  //SPIBR	=	0b01100000;	  //over clock speed 1.78Mhz
  //SPIBR	=	0b00100001;	  //over clock speed 2.08Mhz
  //SPIBR	=	0b01000000;	  //over clock speed 2.5Mhz
  //SPIBR	=	0b00000010;	  //over clock speed 3.125Mhz
  //SPIBR	=	0b00100000;	  //over clock speed 4.1667Mhz
  SPIBR	=	0b00000001;	  //over clock speed 6.25Mhz
  //SPIBR = 0b00000000;  // clock speed 12.5MHz
  
  
  
  //SPIconfig();
  
  ////OSC1_EN_DDR = 1;
  ////OSC2_EN_DDR = 1;
  ////OSC3_EN_DDR = 1;
  
  ////OSC1_EN = 1;
  ////OSC2_EN = 1;
  ////OSC3_EN = 1;
  //DDRE = DDRE |0x10;
  //DDRG_DDRG6 = 1;
  //DDRS_DDRS0 = 1;
}


void SPI_disable(void){
  
  SPICR1 = 0b00010000;
  }



UINT8 SPIconfig1st(void){
  UINT8 temp;
  //SPIinit();
  //PTG_PTG2 = 0; //PTS = PTS & ~0x80;		
 // OSC2_EN = 0;
  SPIDR = 0x00;
  

 while ((SPISR & 0x20) == 0) ;
 
 temp = SPIDR;  
  SPIDR = 0x00;	  
  while ((SPISR & 0x20) == 0) ;  
  temp = SPIDR;  
  SPIDR = 0x03;
 
 while ((SPISR & 0x20) == 0) ;
 
 
   temp = SPIDR;  
    temp = SPIDR; 
  //OSC2_EN = 1;
  // PTG_PTG2 = 1; // PTS = PTS | 0x80;	
}


UINT8 SPIconfig(void){
  UINT8 temp;
  //SPIinit(); 
  
//	delay_us(100);
  
  //PTG_PTG2 = 0; //PTS = PTS & ~0x80;		
  //OSC2_EN = 0;
  SPIDR = 0x00;	  
   while ((SPISR & 0x20) == 0) ;
    temp = SPIDR; 
  SPIDR = 0x03;
  while ((SPISR & 0x20) == 0) ;
  
  temp = SPIDR;  
  SPIDR = 0x82;
  
  while ((SPISR & 0x20) == 0) ;
  
 
	temp = SPIDR;  
	  temp = SPIDR; 
	//PTG_PTG2 = 1 ; // PTS = PTS | 0x80;	
	//OSC2_EN = 1;
	return 1;
}


 UINT8 SPIconfig2(void){
  UINT8 temp;
 
//	delay_us(100);
  
  //PTG_PTG2 = 0 ; //PTS = PTS & ~0x80;		
  //OSC2_EN = 0;
  SPIDR = 0x00;	  
   while ((SPISR & 0x20) == 0) ;
    temp = SPIDR; 
  SPIDR = 0x03;
  while ((SPISR & 0x20) == 0) ;
  
  temp = SPIDR;  
  SPIDR = 0xC2;
  
  while ((SPISR & 0x20) == 0) ;
  
 
	temp = SPIDR;  
	  temp = SPIDR; 
	//PTG_PTG2 = 1 ;  PTS = PTS | 0x80;	
	//OSC2_EN = 1;
	return 1;
}


UINT8 SPIconfig1(void){
  //PTG_PTG6 = 0;
  //PORTE = PORTE &~0x10;
  OSC1_EN = 0;
  OSC2_EN = 0;
  OSC3_EN = 0;
  //PTG_PTG1 = 0;
  //PTG_PTG3 = 0;
  
  SPIconfig1st();
  
  
  OSC1_EN = 1;
  OSC2_EN = 1;
  OSC3_EN = 1;
  //PTG_PTG3 = 1;
  //PTG_PTG1 = 1;//PORTE = PORTE | 0x10;
  
  //PTG_PTG6 = 1;
 
  //PTG_PTG6 = 0;
  OSC3_EN = 0;
  
  
  SPIconfig2();
  
  
  OSC3_EN = 1;
  //PTG_PTG6 = 1;
  
  OSC1_EN = 0;
  OSC2_EN = 0;
  //PTG_PTG1 = 0; //PORTE = PORTE &~0x10;
  //PTG_PTG3 = 0;
  SPIconfig();
  OSC1_EN = 1;
  OSC2_EN = 1;
  //PTG_PTG3 = 1;
  //PTG_PTG1 = 1;//PORTE = PORTE | 0x10;
   
  
  //PTG_PTG6 = 0;
  OSC3_EN = 0;
  SPIsendC((INT8) 0x29);
  OSC3_EN = 1;
  //PTG_PTG6 = 1;
  OSC3_EN = 0;
  // PTG_PTG6 = 0; 
  SPIsend3((INT8) 100,0);
  OSC3_EN = 1;
  //PTG_PTG6 = 1;
  
    
}  

	
		
/* Sending two bytes data*/
/*NOte: in future, should make this general to send anysize of data packet.*/
/* //general approach */
void SPIsendC(INT8 data){
   UINT8 temp; 
  // PTG_PTG2 = 0; //PTS = PTS & ~0x80;		
  //OSC2_EN = 0; 
  SPIDR = data;
  while ((SPISR & 0x20) == 0) ;
   temp = SPIDR;  
  
   temp = SPIDR;  
  
}


void SPIsendbyte(UINT8 data){
   UINT8 temp; 
 //  PTS = PTS & ~0x80;		
   
 // SPIDR = 0x24;
 // while ((SPISR & 0x20) == 0) ;
//   temp = SPIDR;  
//  SPIDR = 0x40;
//  while ((SPISR & 0x20) == 0) ;
 //  temp = SPIDR;  
  
  
  SPIDR = data;
  while ((SPISR & 0x20) == 0) ;
  temp = SPIDR; 
  //temp = SPIDR; 

//    PTS = PTS | 0x80;
    
}



void SPIsend(INT8 data, UINT8 port){
  UINT8 temp;
  UINT8 temp_data;
  

	if(port>=5) port = port-5;
	else port = port+5;
	if(data<56)temp_data = data+200;
	else temp_data = data-56;
	
	//PTG_PTG2 = 0 ; //PTS = PTS & ~0x80;
	//OSC2_EN = 0;
	if(data<56) SPIDR = temp_data>>2;
	else SPIDR = (1<<6)|(temp_data>>2);
  while ((SPISR & 0x20) == 0) ;		
	  temp = SPIDR;  
	 
	 SPIDR = temp_data<<6;
	
   while ((SPISR & 0x20) == 0) ; 
    temp = SPIDR;  
   SPIDR = port<<2;
   while ((SPISR & 0x20) == 0) ; 
   	
   temp = SPIDR;  
    temp = SPIDR; 
   //OSC2_EN = 1;
   //PTG_PTG2 = 1; //PTS = PTS | 0x80;
      
}

void SPIsend3(INT8 data, UINT8 port){
  UINT8 temp;
  UINT8 temp_data;
  

//	delay_us(100);
//change again for FDPM

	//SPIDR = 0x0;
	if(data<56)temp_data = data+200;
	else temp_data = data-56;
	
	//PTG_PTG2 = 0; //PTS = PTS & ~0x80;
	//OSC2_EN = 0;
	if(data<56) SPIDR = temp_data>>2;
	else SPIDR = (1<<6)|(temp_data>>2);
  while ((SPISR & 0x20) == 0) ;		
	  temp = SPIDR;  
	 
	 SPIDR = temp_data<<6;
	
   while ((SPISR & 0x20) == 0) ; 
    temp = SPIDR;  
   SPIDR = port<<2;
   while ((SPISR & 0x20) == 0) ; 
   	
   temp = SPIDR;  
    temp = SPIDR; 
   //PTG_PTG2 = 1; //PTS = PTS | 0x80;
   //OSC2_EN = 1;   
}
  
 
void SPIsend1(UINT8 data, UINT8 port){
  
  //PTG_PTG1 = 0; //PORTE = PORTE &~0x10;
  OSC1_EN = 0;
  SPIsendC((INT8) 0x29);
  //PTG_PTG1 = 1; //PORTE = PORTE | 0x10;
  OSC1_EN = 1;
  OSC1_EN = 0;
  //PTG_PTG1 = 0; //PORTE = PORTE &~0x10;
  SPIsend((INT8) ((data*10 -45+port)/10), port);
  OSC1_EN = 1;
 
  //PTG_PTG1 = 1;//PORTE = PORTE | 0x10;
 
  //PTG_PTG3 = 0;
  OSC2_EN = 0;
   SPIsendC((INT8) 0x29);
   OSC2_EN = 1;
   OSC2_EN = 0;
   //PTG_PTG3 = 1;
   //PTG_PTG3 = 0;
  SPIsend3(data, port);
  OSC2_EN = 1;
  //PTG_PTG3 = 1;
  
      
}
//for fdpm+
/*
void SPISend(UINT8 *data, UINT8 datalen){
  UINT8 temp;
 // UINT8 temp_data;
  UINT8 i;
  
  PTS = PTS & ~0x80;		
   
  for(i=0; i<datalen; i++) {
    
  SPIDR = *(data+i);
  while ((SPISR & 0x80) == 0) ;
   temp = SPIDR;  
  
   
  }
  PTS = PTS | 0x80;	
  // temp = SPIDR; 
      
}
//for fdpm+
*/

/*

UINT8 SPIrecv(void){
 
 UINT8 temp;
 UINT8 temp2=0;
 //SPIDR=0;
 
 SPIDR=0;
 //while ( ((SPISR && 0x80) == 0)  &  ( temp2 < 9999)) temp2++;
 while( (SPISR && 0x80) == 0);
 
 //(void)SPISR;
 temp=SPIDR;
 
 return temp;
}
*/


UINT8 SPIrecv(void){
    
    UINT8 temp;
    
    //UINT8 temp2=0;
    
    //SPIDR = SPIDR;
     SPIDR=0;
    
    //UINT8 i=10000;
    //PTG_PTG2 = 0; //PTS = PTS & ~0x80;
    //SPIDR = SPIDR;
    //PTG_PTG1=PTG_PTG0; 
    //while( (SPISR && 0x80) == 0);
    while( (SPISR & 0x80) == 0);
    
    //while( (SPISR && 0b10000000) == 0);
    
    //while ( (SPISR_SPIF == 0) | ( temp2 < 9999)) temp2++;
     
     //PTG_PTG0=0;
     //if(!PTG_PTG1)PTG_PTG1=1;
    
    
 
    //PTG_PTG0=~PTG_PTG0;	 
    
    
    //PTG_PTG0=0;
    
    
    //temp = SPIDR;
    
    
    
    
       //while(i) i--;
    //PTG_PTG2 = 0; //PTS = PTS | 0x80; 
    
    //if ( temp2 < 9996) temp = SPIDR; else temp = 0xff;
    //temp2 = SPISR && 0x7f;
    //SPIDR = 0 ;
    //temp2=SPISR ;
    //temp=SPIDR;
    
    
    //temp = SPIDR;
    
    //SPISR = SPISR && 0x7f;
    //(void)SPIDR;
    //temp = SPIDR;
    
    //return temp;
    return SPIDR;
    
}



