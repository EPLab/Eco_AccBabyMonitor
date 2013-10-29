/**************************************       
    nRF24L01 Transceiver        
    
    Author : Chongjing Chen
    Date: 08/25/2006         


        Eco Retransmission Protocol
        
    Author : Chongjing Chen
    Date: 06/26/2007  
        
   
***************************************/

#include "rf24g.h"
#include "rf24g-freescale.h"
#include "spi.h"

unsigned	char	rf24g_current_mode = RF24G_IDLE;

char	rf_dr_intr = 1;
char	rf_dr2_intr = 1;


//int delay = 6700 ;  // for 4ms delay with 23 bytes payload
int delay = 0 ;
//int delay = 1000 ;


// delay 2160 for 1000 micro second delay with 27 bytes payload			 20KB/S ( Data payload speend)
// delay 1490 for 800 micro second delay with 27 bytes payload			 25KB/S ( Data payload speend)
// delay 1210 for 700 micro second delay with 27 bytes payload			 28.5KB/S ( Data payload speend)
// delay 930 for 600 micro second delay with 27 bytes payload			 33.3KB/S ( Data payload speend)
// delay 650 for 500 micro second delay with 27 bytes payload			 40KB/S ( Data payload speend)
// delay 370 for 400 micro second delay with 27 bytes payload			 50KB/S ( Data payload speend)
//delay 90 for 300 micro second delay with 27 bytes payload			 66KB/S ( Data payload speend)


//int pause = 1100;			 // pause 1100 for 550 us TX time	 , minimun for simulated ECO(freescale)
int pause = 50;
//Setup configuration array


unsigned int cmd_string_receive[RF24G_CONFIG_LEN_RECEIVE] = {
    0x20,		// PRX, 2 Bytes CRC enabled, mask a couple of ints=========
 		0x21,		//disable auto-ack, RX mode===
 	  0x23,		//address width = 3================
 	  0x26,		//data rate = 1MB=========
    0x31,   //27 byte payload ==
 		0x25,		//set channel 
};

unsigned int config_string_receive[RF24G_CONFIG_LEN_RECEIVE] = {
//  	0b00011101,		// PRX, 2 bytes CRC enabled, mask a couple of ints===
  	0b00111101,		// PRX, 2 bytes CRC enabled, mask a couple of ints===
  	0b00000000,		//auto retransmit off==========
  	0b00000001,	  //address width = 3================
  	0b00000111,   //data rate = 1MB=========		   
    0b00011011,		  //27 byte payload ==
  	//0b01110110,	  //set channel 118
  	0b00000110,	  //set channel 6
};

unsigned int cmd_string_transmit[RF24G_CONFIG_LEN_TRANSMIT] = {
    0x20,		// PTX, 2 Bytes CRC enabled, mask a couple of ints=========
 		0x24,   // auto retransmit off
 	  0x23,		//address width = 3================
 	  0x26,		//data rate = 1MB=========
 		0x25,		//set channel
 		0x21,		//disable auto-ack, TX mode===
//    0x31,   //27 byte payload ==

};

unsigned int config_string_transmit[RF24G_CONFIG_LEN_TRANSMIT] = {
//  	0b00111100,		// PRX, 2 bytes CRC enabled, mask a couple of ints===
    0b01011100,		// PRX, 2 bytes CRC enabled, mask a couple of ints===
    0b00000000,		//auto retransmit off==========  	
  	0b00000001,	  //address width = 3================
  	0b00000111,   //data rate = 1MB=========		   
  	//0b01110110,	  //set channel 118
  	0b00000110,	  //set channel 6
  	0b00000000,	  //disable auto-ack, TX mode===
//    0b00011011,		  //27 byte payload ==
};

void set_debug_hi(void){
  SET_PIN(DEBUG_SIG,1); 
}

void set_debug_low(void){
  SET_PIN(DEBUG_SIG,0); 
}

char	init_rf24g_parameter(int payload, int freq, int channel, int power, char mode)
{
  SET_DDR(DEBUG_SIG, OUT);
	SET_PIN(RF24G_CE, 0);		// clear all bits , enter configure mode
	SET_PIN(RF24G_CS, 0);
	SPIsendbyte(0x20);
	SPIsendbyte(0b00011101);								 
	SET_PIN(RF24G_CS, 1);
	SET_PIN(RF24G_CS, 0);
	if (mode == RF24G_TX)
		init_rf24g_send();
	else if (mode == RF24G_RX)
		init_rf24g_recv();
	else
		return 1;
  return 0;
}

void	init_rf24g_send(void)
{
  unsigned int	i, j,c,data,cmd;
  DDRG_DDRG1=1;
  SET_DDR(RF24G_CE, OUT);	// 1 as output
  SET_DDR(RF24G_CS, OUT);
  SET_DDR(RF24G_DR1, IN);	// DR is input
  SET_PIN(RF24G_CE, 0);		// clear all bits , enter configure mode
  SET_PIN(RF24G_CS, 0);
  SET_PIN(RF24G_DR1, 0);
  for (i = 0; i < RF24G_CONFIG_LEN_TRANSMIT; i++)
  {
    c = cmd_string_transmit[i];
    SPIsendbyte(c);
    c = config_string_transmit[i];
    SPIsendbyte(c);
    SET_PIN(RF24G_CS, 1);
    SET_PIN(RF24G_CS, 0);
  }
}

void	fast_init_rf24g_send(void)
{
	unsigned int data,cmd;
	SET_PIN(RF24G_CE, 0);		// clear all bits , enter configure mode
	SET_PIN(RF24G_CS, 0);
  SPIsendbyte(0x20);
  SPIsendbyte(0b01011100);
  SET_PIN(RF24G_CS, 1);
}

void	init_rf24g_recv(void)
{
  unsigned int	i, j,c,data,cmd;
  DDRG_DDRG1=1;
  SET_DDR(RF24G_CE, OUT);	// 1 as output
  SET_DDR(RF24G_CS, OUT);
  SET_DDR(RF24G_DR1, IN);	// DR is input
  SET_PIN(RF24G_CE, 0);		// clear all bits , enter configure mode
  SET_PIN(RF24G_CS, 0);
  SET_PIN(RF24G_DR1, 0);
  for (i = 0; i < RF24G_CONFIG_LEN_RECEIVE; i++)
  {
    c = cmd_string_receive[i];
    SPIsendbyte(c);
    c = config_string_receive[i];
    SPIsendbyte(c);
    SET_PIN(RF24G_CS, 1);
    SET_PIN(RF24G_CS, 0);
  }
  SET_PIN(RF24G_CS, 0);
  data = 101; //set address 101,101,101,101,101, also default...====================================================================
  //cmd = 0x30;
  cmd = 0x2A;
  SPIsendbyte(cmd);
  for (j = 0; j < 5; j++)
  {
    SPIsendbyte(data);
  }
  SET_PIN(RF24G_CS, 1);
  SET_PIN(RF24G_CS, 0);
  cmd = 0x20;
  data = 0b00111111;
  //data = 0x3F; //Power up  ================================================================================
  SPIsendbyte(cmd);
  SPIsendbyte(data);
  SET_PIN(RF24G_CS, 1);
  SET_PIN(RF24G_CE, 1);	// activate config
}

void	fast_init_rf24g_recv(void)
{
  unsigned int	j,data,cmd;
  SET_PIN(RF24G_CE, 0);		// clear all bits , enter configure mode
  SET_PIN(RF24G_CS, 0);
  cmd = 0x20;
  data = 0b00111111;
  //data = 0x3F; //Power up  ================================================================================
  SPIsendbyte(cmd);
  SPIsendbyte(data);
  SET_PIN(RF24G_CS, 1);
  SET_PIN(RF24G_CE, 1);	// activate config
}

void	rf24g_send(char *data, int ch, int datalen)
{
	int	i,k;
  int len;
  int data2,cmd;
  len = datalen;
  k = 0;
	SET_PIN(RF24G_CS, 0);
  cmd = 0x30;
  data2 = ch; //set address ch,ch,ch,ch,ch, also default...====================================================================
  SPIsendbyte(cmd); 
  for (i = 0; i < 5; i++)
  {
    SPIsendbyte(data2);
  }
  SET_PIN(RF24G_CS, 1);
  do{
    SET_PIN(RF24G_CS, 0);
    cmd = 0x27;//clear previous ints==============================================================================
    data2 = 0b01111110;
    SPIsendbyte(cmd);
    SPIsendbyte(data2);
    SET_PIN(RF24G_CS, 1);
    SET_PIN(RF24G_CS, 0);
    cmd = 0x20;// PWR_UP=1 clear previous ints==============================================================================
    data2 = 0b01011110;			 // debuging issue
    SPIsendbyte(cmd);
    SPIsendbyte(data2);
    SET_PIN(RF24G_CS, 1);
    //clear TX fifo===========================================================================================
    //the data sheet says that this is supposed to come up 0 after POR, but that doesn't seem to be the case
    SET_PIN(RF24G_CS, 0);
    cmd = 0xE1;
    SPIsendbyte(cmd);
    SET_PIN(RF24G_CS, 1); 
    SET_PIN(RF24G_CS, 0);
    cmd = 0xA0;//RF24G_PAYLOAD byte payload================================================================================
    SPIsendbyte(cmd);
    for (i = 0; i < RF24G_PAYLOAD; i ++) // n bytes
    {
      if((i+k)<len) data2 = data[i+k];
      else data2 = i;
      SPIsendbyte(data2);
    }
    k +=RF24G_PAYLOAD;
    SET_PIN(RF24G_CS, 1); 
    SET_PIN(RF24G_CE, 1); // start transmission
    i = pause;
    while(i)i--;
    SET_PIN(RF24G_CE, 0); // start transmission
  }
	while(k<len);		 
  while((GET_PIN(RF24G_DR1)));
}

// recv string
int	rf24g_recv(UINT8 *data)
{
  UINT8  i, cmd;
  //int loop = 0, ts =52;  // best value for Eco ts = 52;
  int loop = 0, ts = 40;  /**/
  //UINT32 delay=100;
  UINT32 delay=25;
//  set_debug_hi();/**/
  while(GET_PIN(RF24G_DR1))
  {
    delay_us(delay);
    if (loop>ts){
      PTG_PTG1=~PTG_PTG1;
      break;
    }
    else{
      loop++; 
    }
  }
//  set_debug_low();/**/
  if (loop > ts) return 1;
  //set_debug_hi();/**/
  SET_PIN_HIGH(DEBUG_SIG2);/**/			 /* it takes 132 us from here to the end of the function*/

  SET_PIN(RF24G_CS, 0);
  cmd = 0x61;
  SPIsendbyte(cmd);	
  (void) SPIrecv();  
  for (i = 0; i < RF24G_PAYLOAD; i ++) // n bytes
  {
    data[i] = SPIrecv();
  }
  SET_PIN(RF24G_CS, 1);
  SET_PIN(RF24G_CS, 0);
  cmd = 0x27; //reset int ===========================================================================================
  i = 0x40; 
  SPIsendbyte(cmd);
  SPIsendbyte(i);
  SET_PIN(RF24G_CS, 1);
  
  SET_PIN_LOW(DEBUG_SIG2);/**/

  return 0;
}



void enable_sending(void){
  while(!(GET_PIN(RF24G_DR1)));
}


void set_channel(int channel){
  SET_PIN(RF24G_CS, 0);
  SPIsendbyte(0x25);
  SPIsendbyte(channel);
  SET_PIN(RF24G_CS, 1);
}

int read_channel(void){
  int i;		  
  SET_PIN(RF24G_CS, 0);
  SPIsendbyte(0x05);
  (void) SPIrecv();  
  i = SPIrecv();
  SET_PIN(RF24G_CS, 1);
  return i;
}

void	rf24g_recv_test(void)
{
  int	i;
  SET_PIN(RF24G_CE, 1);  
  while(!(GET_PIN(RF24G_DR1)));
  (void)SPIrecv();
  (void)SPIrecv();
  for (i = 0; i < RF24G_PAYLOAD; i ++) // n bytes
  {
    (void) SPIrecv();
    (void) SPIrecv();
  }
}
