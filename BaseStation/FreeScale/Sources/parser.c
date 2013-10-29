/**************************************       
              parser.c
    Author: Qiang Xie
    Date: 05/11/2005
    

        ECO Pulling Command
    Author : Chongjing Chen
    Date: 08/25/2006  

  
        Eco Retransmission Protocol
    Author : Chongjing Chen
    Date: 06/26/2007  
        

				RTI-based Pulling (RIPE-MAC)
    Author : Vahid Salmani
    Date: 08/20/2008  


***************************************/              

#include "debug.h"
#include "datatypes.h"
#include "globalvariables.h"
#include "system.h"
#include "tcp_ip.h"

#include "string.h"
#include "MOTTYPES.h"
#include "MC9S12NE64.h"


#include "parser.h"
//#include "thread.h"
#include "io.h"
#include "timerM.h"
#include "i2c.h"
#include "spi.h"
#include "buffer.h"
#include "nvm.h"
#include "rf24g-freescale.h"/**/

//#include "rf24g.h"
#include "sci.h"
#include "fdpmapp.h"
#include "time.h"

#define ONEMS 100
#define NUMCH 4
#define STK_LEN 20

extern UINT8 cmdinterface; 
extern UINT8 seq = 0;

INT16 parseSingleCmd(unsigned char* cmd, UINT16 datalen, UINT16 cmdid);
uchar parseVar(uchar* cmd, UINT16 datalen, UINT16 cmdid);

char digit[16] = { '0','1','2','3','4','5','6','7','8','9',
                      'A','B','C','D','E','F' };

unsigned char sharedatabuf[BUF_LEN];
unsigned char operand_stack[STK_LEN];
unsigned char op_pointer=0;
unsigned char in_loop = 0;
unsigned char in_flash = 0;
UINT16 buflen = 0;
unsigned char isData;

/**/
int sw = 1;
UINT8 status[30];/* moved here from 'parseSingleCmd' */
UINT8 tempbuf[20][32];/* moved here from 'parseSingleCmd' */
int ID_count = 0;
/**/

UINT8 isDigit(char s){
  UINT8 i;
  for(i=0; i<16; i++)
    if(s==digit[i])return i;
  return i;
}
 
void help(void){
    PTG_PTG1 = 0;	 
		PTG_PTG0 = 0;
}

void clearBuf(void){
 int i;
 for(i=0; i<BUF_LEN; i++)sharedatabuf[i]=0; 
}
//void delay_us(t) UINT32 t;

void delay_us(UINT32 t)
{
  t =  (t-19)*10/12; 
  for(t; t>0; t--);  
}


void delay_ms(UINT32 t)
{
  t=((t*1000)-19)*10/12;
  for(t; t>0; t--); 
}


//============================================================
// Poll ATD and send new values via UDP
//============================================================
UINT16 get_a2d(char channel)			{
		tU16 Pot=0;
    tU16 OldPot=1050;
    UINT16 temp;
 		
    UINT16 i = 0;
   
	  //temp =   ATDDR0;
	  for(i=0; i<2; i++) {
	    
	    ATDCTL5 = channel | ATDCTL5_SCAN; //Start new scan

	    while(ATDSTAT0_SCF==0){};  
	    temp =   ATDDR0;// 10-bit					
	  }
	  Pot = temp >> 6;
	  return Pot;
}


UINT8 queryThread(void){
  UINT8 mask = 0;
  UINT8 i = 3;
  mask = tm_used[i--];
  mask = mask*2+ tm_used[i--];
  mask = mask*2+ tm_used[i--];
  mask = mask*2+ tm_used[i--];
  return mask;     
}
 
void sendShareBuf(){
    int i;
    if(!cmdinterface){
      for(i=0; i<BUF_LEN; i++)	 
        net_buf[UDP_APP_OFFSET+i]=sharedatabuf[i];
      udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,BUF_LEN);
    }else{
    		  //for(i=0; i<buflen; i++)	SCIsendC(sharedatabuf[i]); 
        sharedatabuf[buflen]='\n';
        sharedatabuf[buflen+1]=0;
         //SCIsendC(sharedatabuf[0]);
        SCIsendC(0xff);
        SCIsendC(0xfe);
        for(i=0; i<buflen+1; i++)	 SCIsendC(sharedatabuf[i]);
        SCIsendC(0xfe);
        SCIsendC(0xff);
    }
} 


void result_send(UINT16 cmdid, UINT16 result){
  int i;
  char buf[5];																						
  UINT16 datalen;
  datalen = 5;
  if(!cmdinterface){
    
    i = 0;	net_buf[UDP_APP_OFFSET+i]= (UINT8) (cmdid>>8);
	  i = 1;	net_buf[UDP_APP_OFFSET+i]=(UINT8) cmdid;
	  i = 2;	net_buf[UDP_APP_OFFSET+i]=isData;
	  i = 3;  net_buf[UDP_APP_OFFSET+i]=(UINT8) (result>>8);
	 
	  i = 4;  net_buf[UDP_APP_OFFSET+i]=(UINT8) result;
  
    udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);   
  }else{
    SCIsendC(0xff);
    SCIsendC(0xfe);
    i = 0;	buf[i]= (UINT8) (cmdid>>8); SCIsendC(buf[i]);
	  i = 1;	buf[i]= (UINT8) cmdid;SCIsendC(buf[i]);
	  i = 2;	buf[i]= isData; SCIsendC(buf[i]);
	  i = 3;  buf[i]=(UINT8) (result>>8); SCIsendC(buf[i]);
	  i = 4;  buf[i]=(UINT8) result; SCIsendC(buf[i]);
    SCIsendC(0xfe);
    SCIsendC(0xff);
  }
  if(result ==0x0fff )sendShareBuf();
}

void result_block_send(UINT16 cmdid, UINT16 result, char done){
  static UINT16  i=0;
 																					
  UINT16 datalen;
   datalen = 5;
		 
		//if((i+datalen>=BUF_LEN || done)&&i){
		if((i+datalen>=BUF_LEN)&&i){    //move done to below? qx
		    i=0;
		    result_send(cmdid, 0x0fff)  ;
		    clearBuf();
		}
		sharedatabuf[i++]=   	 (UINT8) (cmdid>>8);
	  sharedatabuf[i++]=   	 (UINT8)  cmdid;
    sharedatabuf[i++]= 		 isData;
    sharedatabuf[i++]= 		 (UINT8) (result>>8);
    sharedatabuf[i++]= 		 (UINT8) result;
		if(done){
		  
			  i=0;
		    result_send(cmdid, 0x0fff)  ;
		    clearBuf();
		}
    //udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);   
	 
  //if(result ==0x0fff )sendShareBuf();
}

//============================================================
/* Parse input command data
 */
//============================================================
INT16 flashparser(unsigned int addr, UINT16 datalen, UINT16 cmdid){
  UINT16 result;
  unsigned int tmp;
  UINT16 i,j, k,c;
  char subcmd[80];
  uchar cmdword[2];
  uchar l;
  in_flash += 1;
  c=0;
  i=0;j = 0; k=0;
  for(i=0; i<datalen-2; i+=2){
    tmp = Flash_Read_Word(addr+i);
    cmdword[0] = (UINT8) (tmp>>8); 
    cmdword[1] = (UINT8) tmp; 
    for(l=0; l<2; l++){
        if(cmdword[l]!=';' || k) {
          if(cmdword[l] == '(') k++;
    	    else if(cmdword[l] == ')') k--;
          if(cmdword[l]!=0x20)subcmd[j++] = cmdword[l];
        }
        else{
          if(j){
            result = parseSingleCmd(subcmd, j, cmdid);
            if(result!=0xffff){
              c++;
              result_block_send(cmdid, result, 0);
            }
          }
          j = 0;
        }
    }
  }
  if(j>1){
    result = parseSingleCmd(subcmd, j, cmdid);
    if((result!=0xffff ||isData)&& !in_loop){
      result_block_send(cmdid, result, 1);
    }
    else if((result>=0 ||isData)&& in_loop){
      result_block_send(cmdid, result, 0); 
    }
    in_flash -=1;
  }
  return result;
}

INT16 parser(unsigned char* cmd, UINT16 datalen, UINT16 cmdid){
  INT16 result;
  UINT16 i, j, k;
  uchar m = 0;
  char subcmd[80];
  i=0;j = 0; k=0;
  for(i=0; i<datalen; i++){
    if(cmd[i] =='"'){
      m=m+1;
    }
    else if((cmd[i] ==';'&&(m&0x1))||cmd[i]!=';' || k) {
      if(cmd[i] == '(') k++;
    	else if(cmd[i] == ')') k--;
      subcmd[j++] = cmd[i];
    }
    else{
      result = parseSingleCmd(subcmd, j, cmdid);
      if((result>=0||isData)&&in_loop)result_block_send(cmdid, result,0);
      if((result>=0||isData)&&!in_loop)result_block_send(cmdid, result,1);
      else if((result>=0||isData)&&!in_flash)result_send(cmdid, result);
      j = 0;
    }
  }
  if(j>1){
    result = parseSingleCmd(subcmd, j, cmdid);
    if((result!=0xffff ||isData)&&in_flash&&!in_loop)
      result_block_send(cmdid, result, 1);
    else if((result>0||isData)&&in_flash&&in_loop)
      result_block_send(cmdid, result, 0);   // result_send(cmdid, result);
    else if((result>=0 ||isData)&&!in_flash)
      result_send(cmdid, result);
  }
  return result;
}

INT16 parseSingleCmd(unsigned char* cmd, UINT16 datalen, UINT16 cmdid){
    char port;
    char port1;
    UINT8 pin, pin1;
    UINT8 tval;
    unsigned int val;
    int digitlen;
    memUnit* cur_script;
    UINT16 result;
    UINT32 ts, td;
    int tstep;
    unsigned int addr;
    char subcmd[40];
    //UINT8 databuf[30] =  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    UINT8 databuf[30];
//    UINT8 status[30];/**/
//    UINT8 tempbuf[20][32];
    int i, j, k;
//    int temp, count,number;
    int temp, count, number;
    result = 1;			
    i = 0;
    isData = 0;
    switch(cmd[i]){
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'a':
      case 'A':
      //get adc value
        if(datalen!=2){
          help();
          result = 0;
          break;
        }
        i = 1;
        port = isDigit(cmd[i]);
        if(port >7){
          if(cmd[i] == '$'){
              do{
                op_pointer--;
                port = operand_stack[op_pointer%STK_LEN];
          		  port = isDigit(port);
              }while(operand_stack[(op_pointer-1)%STK_LEN] !=':');
              //op_pointer --; //we know that adc only has 1 argument 
          }
          else{
            help();
            result = 0;
            break;
          }
        }
        result = get_a2d(port); 
        //result = op_pointer;
        isData = 1;
        break;
      
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'c':
        // isData = 0;
        i =1;
        if(cmd[i]=='p'){
             //PTG_PTG1=1;
             j = 0;
             i=2;
             while(i!=datalen){
                 sharedatabuf[j++] = cmd[i++];
             }
             sharedatabuf[j] = 0;
             buflen = j;
        }
        else if(cmd[i] == 'r'){
            val = 0;
            i = i+1;
            while(i<datalen){
             if(isDigit(cmd[i])<16)  val = val*16+isDigit(cmd[i]);
              else if(isDigit((cmd[i]-0x20))<16)val = val*16+isDigit(cmd[i]-0x20);
              i++;
            }
            for(j=0; j<BUF_LEN; j=j+2){
              result = Flash_Read_Word(val);
              val +=2;
          //    PTG_PTG0=1;
             sharedatabuf[j+1] = (unsigned char) result;
             sharedatabuf[j] = (unsigned char) (result>>8); 
            }
            result = 0x0fff;
            isData = 1;
        }
        else{
          help();
          result=0;
        }
        break;
        							 
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'e':
        i = 2;
        val = cmd[i]*256+cmd[i+1];
        i = 4;
        result = cmd[i]*256+cmd[i+1];
        if(datalen>7&&(cmd[6] == ':')){
             //get the operand 
             i = 7;
             if(cmd[i]!='$'){
                operand_stack[op_pointer%STK_LEN] = ':';
                op_pointer++;
                for(j=datalen-1; j>=i;j--) {
                  operand_stack[op_pointer%STK_LEN] = cmd[j];
                  op_pointer++;
                }
                //op_len = op_pointer - op_len; 
             } else{
              //do nothing?    
             }
        }
        result = flashparser(val, result, cmdid);
        result = -1;
        isData = 0;
        break;

      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'D':
      case 'd':
        if (datalen <3){
          help();
          result = 0;
          break;
        }
        i = 1;
        port = cmd[i];
        i = i+1;
        digitlen=datalen-i;
        ts = 0;
        for(j=0; j<digitlen; j++){
          val = isDigit(cmd[i++]);
          if(val>9)
					{
					  help();
					  result = 0;
					  break;
					} ;
          ts = ts*10+val;
        }
        if(port == 'm' || port == 'M'){
          delay_ms(ts);
          result = -1;
          break;
        }
        else if( port == 'u' || port == 'U')
        {
          delay_us(ts);
          result = -1;
          break;
        }
        else{
          help();
          result = 0;
          break;
        }             
        break;

      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'f':
      case 'F':
        // isData = 0;
        i = 1;
        port = cmd[i];
        //*********************************************************************/
        switch(port){
          case 'f':
          case 'F':
            /* Channel Change */
            status[0]= cmd[2];
 						status[1]= seq;
 						//status[1]= datalen;
 						status[2]= cmd[3];
 						//status[2]= datalen;
 						status[3]= cmd[4];
 						status[4]= cmd[5];
 						status[5]= cmd[6];
 						status[6]= cmd[7];
 						status[7]= cmd[8];
 						status[8]= cmd[9];
 						if(cmd[2] == 192){  // 192 == '\xc0'
              fast_init_rf24g_send();
              //for(i=0;i<10;i++)
  		        rf24g_send(status,101,9);	
              rf24g_send(status,101,9);	
              rf24g_send(status,101,9);	
              j = cmd[8];
              set_channel(j);
 						}
            i = read_channel(); 		          
            datalen = 1;        
            net_buf[UDP_APP_OFFSET]=i;       
            udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);   
            result = -1;
            break;	
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'm':
          case 'M':
            /* DAC setting */
 						status[0]= cmd[2];
 						status[1]= seq;
 						//status[1]= datalen;
 						status[2]= cmd[3];
 						//status[2]= datalen;
 						status[3]= cmd[4];
 						status[4]= cmd[5];
 						status[5]= cmd[6];
 						status[6]= cmd[7];
 						status[7]= cmd[8];
 						status[8]= cmd[9];
            fast_init_rf24g_send();
            //for(i=0;i<10;i++)
		        rf24g_send(status,101,9);	
		        rf24g_send(status,101,9);
		        rf24g_send(status,101,9);      
            datalen = 1;        
            i=0;
            net_buf[UDP_APP_OFFSET+i]=1;       
            udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);   
  					result = -1;
            break;        
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'l':
          case 'L':
            /* data pulling */
           seq++;

 						status[0]= cmd[2];
 						status[1]= seq;
 						status[2]= cmd[3];
 						status[3]= cmd[4];
 						status[4]= cmd[5];
 						status[5]= cmd[6];
 						status[6]= cmd[7];
 						status[7]= cmd[8];
 						status[8]= cmd[9];
 						status[9]= 192 + cmd[10];			// [10]: last index shows the length (3rd parameter in 'rf24g_send' function)
 						
            count = cmd[7]; 
            number = cmd[10]; 
            datalen = 27*cmd[7]*cmd[10];/**/
            i = 0;
 						
            while( i != count ){        // 'count' is served in retransmission protocol 
              i = count;
              j = 0;
              fast_init_rf24g_send();
              rf24g_send(status,101,11);
   					  fast_init_rf24g_recv();
              while(j != count)
              {
                  i= i - rf24g_recv(tempbuf[j]);
                  j++;
              }//while
            }//while

            for(j=0;j<count;j++){
              for(i=0;i<27;i++){
                net_buf[UDP_APP_OFFSET+i+(27*j)]= tempbuf[j][i];
              } //for(i)
            } //for(j)//

            udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);   
							
						result = -1;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'b':
          case 'B':
            
            if(CRGINT_RTIE == 0) RTI_Enable();    //Enable RTI
            
						result = -1;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'e':
          case 'E':
            
            RTI_Disable();    //Disable RTI
            
						result = -1;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'c':
          case 'C':
            //payload
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
            
              val = val*10+isDigit(cmd[i++]);			 
            }
            pin = val;
            //frequency
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }   
            pin1 = val;
            //channel
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }   
            tval = val;
            //power
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }   
            port1 = val;
            //tx/rx
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }   
            //init_rf24g_parameter(pin, pin1, tval, port1, val); 
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 's':
          case 'S':
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }
            i = i+1;
            j = 0;
            for(; i< datalen; i++) databuf[j++] = cmd[i];
            rf24g_send(databuf, val, j);
						isData = 1;
            result = (UINT16) val;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'o':
          case 'O':
            i = i+1;
            ts = td = tstep = 0;
            if(cmd[i] == 'r' || cmd[i] == 'R'){
              i = i+2;
              while(cmd[i]!=','&& i<datalen){
                val = isDigit(cmd[i++]);
                if(val>9)
		            {
		               help();
		               result = 0;
		               break;
		            }
		            ts = ts*10+val;  
              }
              i = i+1;
              while(cmd[i]!=','&& i<datalen){
                val = isDigit(cmd[i++]);
                if(val>9)
		            {
		              help();
		              result = 0;
		              break;
                }
				        td = td*10+val;  
              }     
              i = i+1;
              while(cmd[i]!=')'&& i<datalen){
                val = isDigit(cmd[i++]);
                if(val>9)
				        {
				          help();
				          result = 0;
				          break;
				        }
  	            tstep = tstep*10+val;  
              }                     
              k = 1;
              j = 0;
              i = i+2;
              while(k&&i<datalen){
                if(cmd[i] == '(') k++;
                else if(cmd[i] == ')') k--;
                if(k) subcmd[j++] = cmd[i++];
              }
              in_loop += 1;
              if(ts>td){
                for(i = ts; i>= td; i = i-tstep){
                  operand_stack[op_pointer%STK_LEN] = ':';
                  op_pointer++;
                  val = i;
                  do{
                    k = val - (val/10)*10;
                    operand_stack[op_pointer%STK_LEN] = digit[k];
                    op_pointer++;
                    val = val/10;
                  }while(val);
                  result = parser(subcmd, j, cmdid);   
                } 
              }
              else{
                for(i = ts; i<= td; i=i+tstep){
                  operand_stack[op_pointer%STK_LEN] = ':';
                  op_pointer++;
                  val = i;
                  do{
                    k = val - (val/10)*10;
                    operand_stack[op_pointer%STK_LEN] = digit[k];
                    op_pointer++;
                    val = val/10;
                  }while(val);
                  result = parser(subcmd, j, cmdid);   
                }
              } 
              result = i;
              isData = 0;
              in_loop -= 1;
            }
            else help();
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'r':
          case 'R':
            val = 0;
            i = i+1;
            while(i<datalen){
              if(isDigit(cmd[i])<16)  val = val*16+isDigit(cmd[i]);
              else if(isDigit((cmd[i]-0x20))<16)val = val*16+isDigit(cmd[i]-0x20);
              i++;
            }
            result = Flash_Read_Word(val);
            isData = 1;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'w':
          case 'W':
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              if(isDigit(cmd[i])<16)  val = val*16+isDigit(cmd[i]);
              else if(isDigit((cmd[i]-0x20))<16)val = val*16+isDigit(cmd[i]-0x20);
              i++;
            }
            i = i+1;
            j = 0;
            for(; i< datalen; i++) databuf[j++] = cmd[i];
            if(j&0x1)
               databuf[j++]=';';
            i = j;
            j=0;
            addr = val;
            while(j<i){
              val =  databuf[j]<<8| ((UINT16) databuf[j+1]);
              port =Flash_Write_Word(addr,val);
              j+=2;
              addr+=2;
            } 
            result =i;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 't':
          case 'T':
            for(i=0;i<27;i++){
              net_buf[UDP_APP_OFFSET+i]=i;
            }
            datalen = 27;
            udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);
            result = -1;
            break;
        //*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
          case 'i':
          case 'I':
            val = 0;
            i = i+1;
            while(cmd[i] != ':'){
              val = val*10+isDigit(cmd[i++]);
            }
            init_rf24g_parameter(val, 118, 101, 3, 1);
            SPIinit();
            break;            
        }
        //*********************************************************************/
        break;        
        
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'i':
      case 'I':
        i = 1;
        tval = isDigit(cmd[i++]);
        port = cmd[i];
        if(port == 'r' || port == 'R'){
        //recrive
            result = I2Crecv();
            break;  
        }
        else if (port == 's' || port == 'S')
        {
        //send
          i = i+1;
          if(datalen<=2){
            help();
            result = 0;
            break;
          }
          val = 0;
          while(i < datalen){
            val = val*10+isDigit(cmd[i++]);
          }
          I2Csend(val, tval);
          result = tval;
          break;
        }
        else{
          help();
          result = 0;
          break;
        }
        break;  
      
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'k':
      case 'K':
        // isData = 0; 
        i = 1;
        pin = isDigit(cmd[i]);
        result = 1;
        if(i<NUMCH) {
            tm_used[pin] = 0;
            cmd_len[pin] = 0;
            disbale_Timer(pin);
        } 
  			else{
  			    help();
  			    result = 0;
  			}
  			break;
      
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 's':
      case 'S':
        // isData = 0;
        //SPI
        i = 1;
        port = cmd[i];
        if(port == 'r' || port == 'R'){
          //recrive
          result = SPIrecv(); 
          break; 
        }
        else if(port == 'c' || port == 'C'){
          //recrive
          result = SPIconfig1();
          break;  
        }
        else if (port == 's' || port == 'S'){
          //send
          i = i+1;
          if(datalen<=2){
            help();
            result = 0;
            break;
          }
          val = 0;
          port = 0;
          if(cmd[i] == '$'){
            do{
              op_pointer--;
              port = operand_stack[op_pointer%STK_LEN];
        		  val = val*10+isDigit(port);
            }while(operand_stack[(op_pointer-1)%STK_LEN] !=':');
            op_pointer--;
            port = val-(val/10)*10;
            val = val/10;
          }
          else{
            while(i < datalen-1){
              val = val*10+isDigit(cmd[i]);
              i = i+1;
            }
            port = isDigit(cmd[i]);
          }
          SPIsend1(val,port);
          result = port;
          break;
            
        }
        else{
          help();
          result = 0;
          break;
        }
        break;  
        
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 't':
      case 'T':
        if(datalen == 1){
          result = queryThread();
          break;
        }
        i = 1;
        ts = 0;
        while(cmd[i]!='('&& i<datalen){
          val = isDigit(cmd[i++]);
          if(val>9)
					{
					  help();
					  result = 0;
					  break;
					} ;
					ts = ts*10+val;  
        }  
        if(i>= datalen-1){
          help();
          result = 0;
          break;
        }
        k = 1;
        j = 0;
        i = i+1;
        while(k&&i<datalen){
            if(cmd[i] == '(') k++;
    	      else if(cmd[i] == ')') k--;
            if(k) subcmd[j++] = cmd[i++];
         }
        ts = ts*ONEMS;
        result = processThread(subcmd, j, ts, cmdid);
     		result = -1;
        break;
        
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'R':
      case 'r':
         // isData = 0;
        i = 1;
        ts = 0;
        if(cmd[i]=='v'){
            result = 0x0fff;
            break; 
        }
        else if(cmd[i]=='$'){
          do{
            op_pointer--;
            port = operand_stack[op_pointer%STK_LEN];
            ts = ts*10+isDigit(port);
          }while(operand_stack[(op_pointer-1)%STK_LEN] !=':');
          op_pointer--;
          i=i+1;
        }
        else{
          while(cmd[i]!='('&& i<datalen){
            val = isDigit(cmd[i++]);
            if(val>9)
            {
              help();
              result = 0;
              break;
            } ;
            ts = ts*10+val;  
          }
          if(i>= datalen-1){
            help();
            result = 0;
            break;
          }
  			}
        k = 1;
        j = 0;
        i = i+1;
        while(k&&i<datalen){
          if(cmd[i] == '(') k++;
  	      else if(cmd[i] == ')') k--;
          if(k) subcmd[j++] = cmd[i++];
          }
        in_loop += 1;    
        while(ts){
          result = parser(subcmd, j, cmdid);   
          ts--;
        }
        result = 1;
        isData = 0;
        in_loop -=1;  
        break;
        
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'P':
      case 'p':
         // isData = 0;
        if(datalen<2){
          help();
          result = 0;
          break;
        }
        else{
          i = 1;
   				port = cmd[i];
          if(port<'A' || port >'z' || (port>'Z' && port <'a')){
            help();
            result = 0;
            break;
          }
          else{
            if(datalen == 2){
              result = query_IO(port, 8);
              if(result<0)result = 0;
              break;
            }
            i = 2;
            pin = cmd[i];
            pin = pin - 48;
            if(datalen <4){
              result = query_IO(port, pin);
              if(result<0) result = 0;
              break;
            }
            else{  //IO assignment
              if(!(pin-13)){// 			 "="
                //assign I/O value
                 i = 3;
                if(cmd[i] =='p' || cmd[i] == 'P'){
                    port1 = cmd[i+1];
                    result = query_IO(port1, 8);
                    assign_IOval(port, 8, result);
                    break;
                 } else if(cmd[i] =='!'){
                    port1 = cmd[i+2];
                    result = ~query_IO(port1, 8);
                    assign_IOval(port, 8, result);
                    break;
                 }
                 digitlen=datalen-i;
                 if(digitlen == 1) //decimal number
                 {
                    i = i+1;
                    if(cmd[i] == 'i' || cmd[i] == 'I' 
                       || cmd[i] == 'o' || cmd[i] =='O'){
                        if(cmd[i] == 'i' || cmd[i] =='I') val = 0;
                        else val = 1;
                        result = assign_IODir(port, 8, val);
                        break;
                      }else{
                        val = isDigit(cmd[i]);
                        if( val == 16){
                            help();
                            result = 0;
                            break;
                        }
                        result = assign_IOval(port, 8, val);
                        break;
                      }
                       
                 }else{
                    i = i+1;
                    if(cmd[i+1]=='x' || cmd[i+1] =='X') //hexical number
                    {
                      i = i+2;  //skip '0x'
                      digitlen=datalen-i;
                      val = isDigit(cmd[i]);
                      if(digitlen >2){
                          help();
                          result = 0;
                          break;
                      } else if(digitlen == 1) {
                        
                        if( val == 16){
                            help();
                            result = 0;
                            break;
                        }
                        result = assign_IOval(port, 8, val);
                        break;
                      }
                      val = val*16;
                      i = i+1;
                      tval = isDigit(cmd[i]);
                      if( tval == 16){
                            help();
                            result = 0;
                            break;
                       }
                       val +=tval;
                       result = assign_IOval(port, 8, val);
                       break;
                    }else if(digitlen == 8){
                      for(j=0; j<8; j++){
                        val = isDigit(cmd[i++]);
                        if(val>1) val = 1;
                        result = assign_IOval(port, j, val);
                      } 
                        
                    }else{
                      help();
                      result = 0;
                      break;
                    }    
                 }
              }else//assign value to pin
              {
                if(pin>8 || pin<0){
                  help();
                  result = 0;
                  break;
                }
                i = i+1;
                if(cmd[i]!='='){
                  
                  help();
                  result = 0;
                  break;
                }
                i = i+1;
                if(cmd[i] == 'i' || cmd[i] == 'I' 
                       || cmd[i] == 'o' || cmd[i] =='O'){
                        if(cmd[i] == 'i' || cmd[i] =='I') val = 0;
                        else val = 1;
                        result = assign_IODir(port, pin, val);
                        break;
                      }
                if(cmd[i] == 'P' || cmd[i] == 'p'){
                  port1 = cmd[i+1];
                  pin1 = isDigit(cmd[i+2]);
               
                  result = query_IO(port1, pin1);
                  assign_IOval(port, pin, result);
                  break;
                }
                if(cmd[i] == '!'){
                  port1 = cmd[i+2];
                  pin1 = isDigit(cmd[i+3]);
                  if(query_IO(port1, pin1)) result = 0;
                  else result = 1;
                  assign_IOval(port, pin, result);
                  break;  
                }
                val = isDigit(cmd[i]);
                if(val ==16){
                  help();
                  result = 0;
                  break;
                }
                if(val >1) val = 1;
                if(!(result=assign_IOval(port, pin, val))){
                  help();
                  result = 0;
                  break;
                }
              }
            }     
          }
        }
        break;
    
			
      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
			case '#':  //call FDPM application
			    //remove a script
		    if(datalen<13){
          help();
          result = 0;
          break;
        }
        else{
            //datalen = datalen-1;
            i = 1;
            ts = cmd[i+1]*256+cmd[i];   // start freq
            i = 3;
            td = cmd[i+1]*256+cmd[i];   // end freq
            i = 5;
            port =cmd[i];                  //freq step
            i = 6;
            pin = cmd[i];    							//samples per iteration
            i = 7;
            PTG_PTG0=1;
            isData =1;
            result = MiniFDPMAPP(ts, td, port, pin, cmd+i, cmd+i+4, cmdid);
            isData = 0;
        }
			  break;

      //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
      case 'H':
      case 'h':
      default:
        //  isData = 0;
        help();
        break;
    //}
    }
    return result;
}

uchar getVar(uchar* cmd, uchar* var){
    //uchar len;
    uchar i;
    i = 0;
    while(cmd[i]!='+' && cmd[i]!=';'){
        if(cmd[i]!=' ')var[i] = cmd[i++];     
    }
    var[i] = 0;
    return i;
}

uchar parseVar(uchar* cmd, UINT16 datalen, UINT16 cmdid){
    uchar i, j, k;
    uchar var[80];
    uchar arglen;
    //define variables
    UINT16 result;
    uchar isArg = 0;
    uchar isAssign = 0;
    memUnit* var_Unit;
    uchar var1id[KEY_LEN];
    uchar var2id[KEY_LEN];
    uchar varlen = 0;
    i = 0;
    k = 0;
    while(cmd[i] !=';' && cmd[i]!='\r' && cmd[i] !='\n'){
        if(cmd[i++] == '$'){
            while(cmd[i]!='=' && cmd[i]!=','){
                if(cmd[i]!=' ')var[k++] = cmd[i++];     
            }
            var[k++]=0;
            if(cmd[i] == ','){//pop argument
                isArg=1;
                arglen = len_stack[len_top++];
                for(j=0; j<arglen; j++)var[k++]=op_stack[op_top++];
                result = addScript(DATA, var, k-1);
                k = 0;
            } else if(cmd[i]=='='){//assignment
                isAssign = 1;
                if((var_Unit=findScript(DATA, var))){
                    //already in the table
                    //remove previous one
                    rmScript(DATA, var);
                }
                i = i+1;
                while(cmd[i++]==' ');
                if(cmd[i]=='$'){  //var assignment
                    //caculate var len 1
                    i = i+1;
                    k=getVar(&cmd[i], var1id);
                    i+=k;
                    if((var_Unit=findScript(DATA, var1id))){
                        varlen = var_Unit->end-var_Unit->start+1;
                        
                    }else return 0;
                    while(cmd[i]==' ')i++;
                    if(cmd[i++] == '$'){
                        k=getVar(&cmd[i], var2id);    
                    
                        if((var_Unit=findScript(DATA, var2id))){
                            varlen += var_Unit->end-var_Unit->start+1;
                        
                        }else return 0;
                    }
                    result = addScript(DATA, var, varlen);
                     //caculate var len 1
                }
                else{ //func assignment
                }
            }
        }
    }
    if(isArg){
        arglen = len_stack[len_top++];
        for(j=0; j<arglen; j++)var[k++]=op_stack[op_top++];
        result = addScript(DATA, var, k-1);
        len_top = 0;
        op_top = 0;
    }
    return;
}		

void timer4_isr_handler(void){
	 
   if(tm_used[0]){
    
		if(cmd_len[0]){
		  parser(tcmd[0], cmd_len[0], cmd_id[0]); 
	  }
	}
		TC4 = TCNT+TC4;

}

void timer5_isr_handler(void){
	 if(tm_used[1]){
    
		if(cmd_len[1]){
		  parser(tcmd[1], cmd_len[1], cmd_id[1]); 
	  }
	}
		TC5 = TCNT+TC5;
}

void timer6_isr_handler(void){
	os_enter_critical_section(); 
	 if(tm_used[2]){
    
		if(cmd_len[2]){
		  parser(tcmd[2], cmd_len[2], cmd_id[2]); 
	  }
	}
		TC6 = TCNT+TC6;
}

void timer7_isr_handler(void){
	 if(tm_used[3]){
    
		if(cmd_len[3]){
		  parser(tcmd[3], cmd_len[3], cmd_id[3]); 
	  }
	}
		TC7 = TCNT+TC7;
}





void pullData(void){
  UINT16 datalen;
  int count;
  int i,k;


  for(k=0; k<3; k++){
    status[k]= ID_count;
    ID_count++;
    if(ID_count >=25) ID_count = 0;
  }
    
/*    
  if(sw==1){
    status[0]= 0;
    status[1]= 1;
    status[2]= 2;
    sw = 0;
  }
  else{
    status[0]= 3;
    status[1]= 4;
    status[2]= 5;
    sw = 1;
  }
*/
  seq++;
  status[3]= seq;
  status[4]= 0x20;
  status[5]= 0x05;
  status[6]= 0x33;
  status[7]= 0x54;
  status[8]= 0x01;
  status[9]= 0x01;
  status[10]= 0x01;
  status[11]= 192 + 1;

  count = 1; 
  datalen = 27;
   
  fast_init_rf24g_send();
  //rf24g_send(status,101,10);	
  rf24g_send(status,101,12);
  
  for(k=0; k<3; k++){
    i = -1;
    //SET_PIN_HIGH(DEBUG_SIG2);
    fast_init_rf24g_recv();
    i= rf24g_recv(tempbuf[0]);
    if(i==0){ //transmission successful
      for(i=0;i<27;i++){
        net_buf[UDP_APP_OFFSET+i]=tempbuf[0][i];
      }
      udp_send(UDPsoc,UDP_DEMO_RMTHOST_IP,UDP_DEMO_RMTHOST_PRT,net_buf+UDP_APP_OFFSET,NETWORK_TX_BUFFER_SIZE-UDP_APP_OFFSET,datalen);
      //SET_PIN_LOW(DEBUG_SIG2);
    }
    else{
      // to be added
    }
  }
  //SET_PIN_LOW(DEBUG_SIG2);
}

