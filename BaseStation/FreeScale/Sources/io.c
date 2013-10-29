#include "MOTTYPES.h"
#include "MC9S12NE64.h"
#include "io.h"

INT16 query_IO(char port, UINT8 pin){
  INT16 value;
  
  switch(port){
    case 'A':
    case 'a':
       if((pin<0) || (pin >WIDTH-1)) value = PORTA;
       else value = (PORTA>>pin)&0x01;
       break;
    case 'B':
    case 'b':
       if(pin<0 || pin >WIDTH-1) value = PORTB;
       else value = (PORTB>>pin)&0x01;
       break;
    case 'K':
    case 'k':
       if(pin<0 || pin >WIDTH-1) value = PORTK;
       else value = (PORTK>>pin)&0x01;
       break;
    case 'E':
    case 'e':
       if(pin<0 || pin >WIDTH-1) value = PORTE;
       else value = (PORTE>>pin)&0x01;
       break;
       
    case 'G':
    case 'g':
       if(pin<0 || pin >WIDTH-1) value = PTG;
       else value = (PTG>>pin)&0x01;
       break;       
    case 'H':
    case 'h':
       if(pin<0 || pin >WIDTH-1) value = PTH;
       else value = (PTH>>pin)&0x01;
       break;
    case 'J':
    case 'j':
       if(pin<0 || pin >WIDTH-1) value = PTJ;
       else value = (PTJ>>pin)&0x01;
       break;
    case 'S':
    case 's':
       if(pin<0 || pin >WIDTH-1) value = PTS;
       else value = (PTS>>pin)&0x01;
       break;      
      
    default:
       value = -1;
       break;         
       
  }
  return value;
};


UINT8 assign_IODir(char port, UINT8 pin, UINT8 val){
  UINT8 value;
  value = 1;
  
  switch(port){
    case 'A':
    case 'a':
       if(pin<0 || pin >WIDTH-1) DDRA = val;
       else if(val) DDRA = DDRA | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRA = DDRA & val;
       }
       break;
    case 'B':
    case 'b':
       if(pin<0 || pin >WIDTH-1) DDRB = val;
       else if(val) DDRB = DDRB | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRB = DDRB & val;
       }
       break;
    case 'K':
    case 'k':
       if(pin<0 || pin >WIDTH-1) DDRK = val;
       else if(val) DDRK = DDRK | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRK = DDRK & val;
       }
       break;
    case 'E':
    case 'e':
       if(pin<0 || pin >WIDTH-1) DDRE = val;
       else if(val) DDRE = DDRE | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRE = DDRE & val;
       }
       break;
       
    case 'G':
    case 'g':
       if(pin<0 || pin >WIDTH-1) DDRG = val;
       else if(val) DDRG = DDRG | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRG = DDRG & val;
       }
       break;        
    case 'H':
    case 'h':
       if(pin<0 || pin >WIDTH-1) DDRH = val;
       else if(val) DDRH = DDRH | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRH = DDRH & val;
       }
       break;        
    case 'J':
    case 'j':
       if(pin<0 || pin >WIDTH-1) DDRJ = val;
       else if(val) DDRJ = DDRJ | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRJ = DDRJ & val;
       }
       break;        
    
    case 'S':
    case 's':
       if(pin<0 || pin >WIDTH-1) DDRS = val;
       else if(val) DDRS = DDRS | (1<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          DDRS = DDRS & val;
       }
       break;        
         
    default:
       value = 0;     
       break;         
       
  }
  return value;
};

UINT8 assign_IOval(unsigned char port, UINT8 pin, UINT8 val){
  
  UINT8 value;
  
 
  //value = 1;
  
  switch(port){
    case 'A':
    case 'a':
       if(pin<0 || pin >WIDTH-1) PORTA = val;
       else if(val) PORTA = PORTA | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PORTA = PORTA & val;
       }
       break;
    case 'B':
    case 'b':
       if(pin<0 || pin >WIDTH-1) PORTB = val;
       else if(val) PORTB = PORTB | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PORTB = PORTB & val;
       }
       break;
    case 'K':
    case 'k':
       if(pin<0 || pin >WIDTH-1) PORTK = val;
       else if(val) PORTK = PORTK | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PORTK = PORTK & val;
       }
       break;
    case 'E':
    case 'e':
       if(pin<0 || pin >WIDTH-1) PORTE = val;
       else if(val) PORTE = PORTE | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PORTE = PORTE & val;
       }
       
       break;
       
    case 'G':
    case 'g':
       if(pin<0 || pin >WIDTH-1) PTG = val;
       else if(val) PTG = PTG | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PTG = PTG & val;
       }
     
       break;        
    case 'H':
    case 'h':
       if(pin<0 || pin >WIDTH-1) PTH = val;
       else if(val) PTH = PTH | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PTH = PTH & val;
       }
       break;        
    case 'J':
    case 'j':
       if(pin<0 || pin >WIDTH-1) PTJ = val;
       else if(val) PTJ = PTJ | (val<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PTJ = PTJ & val;
       }
       break;  
    
    case 'S':
    case 's':
       if(pin<0 || pin >WIDTH-1) PTS = val;
       else if(val) PTS = PTS | (1<<pin);
       else{
          val=(0xff<<(pin+1))|(val<<pin)|(0xff>>(WIDTH-pin));
          PTS = PTS & val;
       }
       break;               
      
    default:
   
       value = 0;
       break;         
       
  }
  return port;
};

