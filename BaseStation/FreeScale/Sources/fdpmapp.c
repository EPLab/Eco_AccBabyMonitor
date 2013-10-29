/**************************************       
              FDPMAPP.c
    Author: Qiang Xie
    Date: 05/24/2006
***************************************/
#include "datatypes.h"
#include "MOTTYPES.h"
#include "MC9S12NE64.h"
#include "spi.h"
#include "I2C.h"
#include "parser.h"

#define J1_POS 5
#define J0_POS 4
#define H0_POS 3
#define H1_POS 2
#define H2_POS 1
#define H3_POS 0

unsigned char DB_DIGIT[] = {
  0x3F, 0x1F, 0x2F, 0x0F, 0x37, 0x17, 0x27, 0x07, 
  //0,   0.5, 1.0,   1.5, 2.0,   2.5, 3.0,  3.5
  0x3B, 0x1B, 0x2B, 0x0B, 0x33, 0x13, 0x23, 0x03, 
  //4.0, 4.5, 5.0,   5.5, 6.0,  6.5,  7.0, 7.5  
  0x3D, 0x1D, 0x2D, 0x0D, 0x35, 0x15, 0x25, 0x05,
  //8.0, 8.5, 9.0,   9.5, 10.0, 10.5, 11.0,11.5  
  0x39, 0x19, 0x29, 0x09, 0x31, 0x11, 0x21, 0x01,
  //12.0,12.5,13.0,  13.5,14.0, 14.5, 15.0,15.5  
  0x3E, 0x1E, 0x2E, 0x0E, 0x36, 0x16, 0x26, 0x06, 
	//16.0, 16.5,17.0, 17.5,18.0, 18.5, 19.0,19.5  
	0x3A, 0x1A, 0x2A, 0x0A, 0x32, 0x12, 0x22, 0x02,
  //20.0, 20.5,21.0, 21.5,22.0, 22.5, 23.0,23.5  
  0x3C, 0x1C, 0x2C, 0x0C, 0x34, 0x14, 0x24, 0x04,
  //24.0, 24.5,25.0, 25.5,26.0, 26.5, 27.0,27.5  
  0x38, 0x18, 0x28, 0x08, 0x30, 0x10, 0x20, 0x00
  //28.0, 28.5,29.0, 29.5,30.0, 30.5, 31.0,31.5  
};

void initFDPM(void){
    DDRJ_DDRJ0 = 1;		 //set to output
    DDRJ_DDRJ1 = 1;		 //set to output
    DDRH = DDRH|0x7F;  //Port H(0-6) output
    PTG_PTG1 = 1;
    PTG_PTG3 = 1;
    PTG_PTG5 = 1;
    PTG_PTG6 = 1;
    
    //set initial IO value
    PTJ_PTJ0 = 0;
    PTJ_PTJ1 = 0;
    PTH_PTH0 = 0;
    PTH_PTH1 = 0;
    PTH_PTH2 = 0;
    PTH_PTH3 = 0;
    
    //initialize frequency synthesizer
    SPIconfig1();
    
    //initialize all laser power(off)
    I2Csend(255, 1);
    I2Csend(255, 2);
    I2Csend(255, 3);
    I2Csend(255, 4);
    
    return;
};

void changeAttent(unsigned char atten)
{
    PTJ_PTJ1 = atten >> J1_POS;
		PTJ_PTJ0 = atten >> J0_POS;
		PTH_PTH0 = atten >> H0_POS;
		PTH_PTH1 = atten >> H1_POS;
		PTH_PTH2 = atten >> H2_POS;
		PTH_PTH3 = atten >> H3_POS;
		
		return;
};

UINT16 MiniFDPMAPP(UINT16 startfreq, UINT16 endfreq, UINT8 fstep, UINT8 samples,UINT8* laser, UINT8* atten, UINT16 cmdid){
    int i, step;
    uint8 j;
    UINT16 AdcVal;
    initFDPM();
    //if(startfreq>endfreq)	 step = -fstep;	 //we assume startf > endf
    //else step = fstep;
    
    //turn on laser 1
    if(*laser<255){
      changeAttent(*atten);  //111011
      PTH_PTH4 = 1;
      PTH_PTH5 = 1;
      I2Csend(*laser, 1);
      PTH_PTH6 = 1;
      //delay_ms(50);				 
      
      for(i=startfreq; i>=endfreq; i=i-fstep){
        j = i%10;
        //SPIsend1(i/10,j);
        for(j=0; j<samples; j++){
          
          AdcVal =get_a2d(2);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(4);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(6);		  
          result_block_send(cmdid, AdcVal, 0);
        }
      }
      I2Csend(255, 1);  //turn off laser
    }
    laser++;   //increase pointer
    atten++;   //incresae pointer
    
    
    //turn on laser 2
    if(*laser<255){
      changeAttent(*atten);  
      PTH_PTH4 = 1;
      PTH_PTH5 = 1;
      I2Csend(*laser, 2);
      PTH_PTH6 = 1;
      //delay_ms(50);				 
      
      for(i=startfreq; i>=endfreq; i=i-fstep){
        j = i%10;
        //SPIsend1(i/10,j);
        for(j=0; j<samples; j++){
          
          AdcVal =get_a2d(2);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(4);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(6);		  
          result_block_send(cmdid, AdcVal, 0);
        }
      }
      I2Csend(255, 2);  //turn off laser
    }
    laser++;   //increase pointer
    atten++;   //incresae pointer

		 //turn on laser 3
    if(*laser<255){
      changeAttent(*atten);  //111011
      PTH_PTH4 = 1;
      PTH_PTH5 = 1;
      I2Csend(*laser, 3);
      PTH_PTH6 = 1;
      //delay_ms(50);				 
      
      for(i=startfreq; i>=endfreq; i=i-fstep){
        j = i%10;
        //SPIsend1(i/10,j);
        for(j=0; j<samples; j++){
          
          AdcVal =get_a2d(2);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(4);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(6);		  
          result_block_send(cmdid, AdcVal, 0);
        }
      }
      I2Csend(255, 3);  //turn off laser
    }
    laser++;   //increase pointer
    atten++;   //incresae pointer
    
     //turn on laser 4
    if(*laser<255){
      changeAttent(*atten);  //111011
      PTH_PTH4 = 1;
      PTH_PTH5 = 1;
      I2Csend(*laser, 4);
      PTH_PTH6 = 1;
      //delay_ms(50);				 
      
      for(i=startfreq; i>=endfreq; i=i-fstep){
        j = i%10;
        //SPIsend1(i/10,j);
        for(j=0; j<samples; j++){
          
          AdcVal =get_a2d(2);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(4);	
          result_block_send(cmdid, AdcVal, 0);
          AdcVal =get_a2d(6);		  
          result_block_send(cmdid, AdcVal, 0);
        }
      }
      I2Csend(255, 4);  //turn off laser
    }
    
    //isData = 0;
    result_block_send(cmdid+1, 0, 1);
//main power off
    PTH_PTH6 = 0;
    return 1;
}

