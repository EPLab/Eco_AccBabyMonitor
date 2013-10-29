#include "buffer.h"
#include <stdlib.h>
//#include <malloc.h>
/***********************************************************
 *     Init Buffer 
 *
 * *********************************************************/



unsigned char mem_buf[BUF_LEN];
unsigned char op_stack[STACK_LEN];
unsigned char len_stack[STACK_LEN];
unsigned char  sharedatabuf[BUF_LEN];
unsigned char script_key_buf[KEY_BUF_LEN];
unsigned char var_key_buf[KEY_BUF_LEN];
unsigned char sharedatabuf[BUF_LEN];

unsigned char op_top;
unsigned char len_top;
//tU16 buf_head;
//tU16 buf_tail;
memUnit first_script;
memUnit first_var;
uchar script_key_index;
uchar var_key_index;

void *mymalloc(uchar* buf,uchar* index, uchar size) 
{
  	 uchar old_index;
  	 
  	 if(*index+size >KEY_BUF_LEN) return -1;
  	 else old_index= *index;
  	 (*index) =(*index)+ size;
  	 return buf+old_index;
}

void myfree(uchar* base, uchar* idx,  void* var, char size) 
{
    uchar i, index;
    index = (uint)var-(uint) base;
    //if(!index) PTG_PTG0=1;
    (*idx) =(*idx)-size;
    for(i=index; i<*idx; i++)
        base[i] =base[i+size];
}

char find_key(unsigned char* s1, unsigned char* s2)
{
	uchar i;
	for(i=0; i<KEY_LEN; i++)
	{
		
		if(s1[i] != s2[i]){
		 
		  return 0;
		}
		if(s1[i] == 0 ) return 1;
	}
	if(s2[i]!=0) return 0;
	return 1;
}

void initBuffer(void){
	int i;
	op_top   = 0;
	len_top  = 0;
	//buf_head = 0;
	//buf_tail = 0;
	script_key_index = 0;
  var_key_index	 = 0;
//	first_script = new memUnit;
	for(i=0; i<BUF_LEN; i++) {
	  mem_buf[i] = 0;
	  sharedatabuf[i] = 0;
	}
	for(i=0; i<KEY_LEN; i++){
	  first_script.key[i] = 0;
    first_var.key[i] = 0;
	}
  first_script.start = 0;
	first_script.end   = 0;
	first_script.next  = 0;	
	
	first_var.start = 0;
	first_var.end   = 0;
	first_var.next  = 0;	
}

char addScript(char mode, unsigned char* cmd, char len){
	char i,j ;
	memUnit* new_script;
	memUnit* prev_script;
	memUnit* first_Unit;
	uchar* buf;
	uchar* key_buf;
	char separator;
	uchar* index;
	if(mode ==0) {
	  first_Unit=&first_script;
	  separator = SEPARATOR;
	  buf = mem_buf;
	  key_buf = script_key_buf;
	  index = &script_key_index;
	}
	else {
	  first_Unit = &first_var;
	  separator = 0;
	  buf = sharedatabuf;
	  key_buf = var_key_buf;
	  index = &var_key_index;
	}	 
	if(first_Unit->start == first_Unit->end)//first one	
	{
	    i = 0;
    	
    	while(cmd[i]!=separator)
	    {
	        
	        first_Unit->key[i] = cmd[i];
  		    i++;
	    }	    
	    i = i+1;	
	    first_Unit->start = 0;	
      first_Unit->end = len-i-1;
      first_Unit->next = 0;
	    if(first_Unit->end >= BUF_LEN) return 0;
	    for(j=0; j<len-i; j++) buf[j] = cmd[i+j];
            	
	}
	else
	{
	    
	    new_script = (memUnit*) mymalloc(key_buf, index, sizeof(memUnit));
	    i = 0;
	    //new_script = new memUnit;
	    while(cmd[i]!=separator)
	    {
	        new_script->key[i] = cmd[i];
  		    i++;
	    }	   
	    for(prev_script=first_Unit; prev_script->next!=0; prev_script=prev_script->next){
	        if(find_key(prev_script->key, new_script->key)){
	          myfree(key_buf, index, (void*) new_script, sizeof(memUnit));
	          return 0;
	        }
	    };
	    for(j=i; j<KEY_LEN; j++) new_script->key[j] = 0;
	    i = i+1;
	    
	    new_script->start = prev_script->end+1;
	    new_script->end   = new_script->start+len-i-1;
	    if(new_script->end >= BUF_LEN) return 0;
	    new_script->next= 0;
	    prev_script->next  = new_script;
	    /*if(new_script->next!=0){
	      PTG_PTG0=1;
	      new_script->next= 0;
	      //return  (uchar) new_script->next;
	    } */
	    for(j=0; j<len-i; j++) buf[j+new_script->start] = cmd[i+j];
	}
	return *index;
}



memUnit* findScript(char mode,unsigned char* cmd){
	memUnit* prev_script;
	if(mode==CODE) prev_script =&first_script;
	else prev_script =&first_var; 
	for(prev_script=&first_script; prev_script!=0; prev_script=prev_script->next)
	{
		
		if(find_key(prev_script->key, cmd)) return prev_script;
	}
	return 0;
}

char rmScript(char mode, unsigned char* cmd){
	memUnit* prev_script;
	memUnit* cur_script;
	tU16 i;
	memUnit* first_Unit;
	uchar* buf;
	uchar* key_buf;
	char separator;
	uchar* index;
	if(mode ==0) {
	  first_Unit=&first_script;
	  separator = SEPARATOR;
	  buf = mem_buf;
	  key_buf = script_key_buf;
	  index = &script_key_index;
	}
	else {
	  first_Unit = &first_var;
	  separator = 0;
	  buf = sharedatabuf;
	  key_buf = var_key_buf;
	  index = &var_key_index;
	}	 
	for(cur_script= first_Unit; cur_script!=0; cur_script=cur_script->next)
	{
	
		if(find_key(cur_script->key, cmd))
		{
			 
			if(cur_script == first_Unit) {
			  //first_script =  *(first_script.next);
			  if(first_Unit->next ==0){
			      first_Unit->start =  0;
			      first_Unit->end   =  0;
			      for(i=0; i<KEY_LEN; i++) first_Unit->key[i] =0;
			      return 1;
			  }
			  cur_script= first_Unit->next;
			  first_Unit->start =  cur_script->start;
			  first_Unit->end   =  cur_script->end;
			  first_Unit->next  =  cur_script->next;
			  
			  for(i=0; i<KEY_LEN; i++) first_Unit->key[i] =  cur_script->key[i];
			  myfree(key_buf, index, (void*) cur_script, sizeof(memUnit));
			  
			  for(cur_script=first_Unit; cur_script->next!=0; cur_script=cur_script->next)
			      cur_script->next  =  (memUnit*) ((int)cur_script->next-sizeof(memUnit));
			}else{
			  prev_script->next =cur_script->next;
			  myfree(key_buf, index, (void*) cur_script, sizeof(memUnit));
			  for(cur_script=prev_script; cur_script->next!=0; cur_script=cur_script->next) {
			   // PTG_PTG0=1;
			    cur_script->next  =  (memUnit*) ((int)cur_script->next-sizeof(memUnit));
			  }
			}return 1;
		}; 
		prev_script = cur_script;
	}
	return 0;

}

char defragMem(char mode, char* buf){
	memUnit* next_script;
	memUnit* cur_script;
	tU16 next_start, end, next_end, i;
	//int j=0;
	if(mode ==0) cur_script=&first_script;
	else cur_script = &first_var;
	if(cur_script->start !=0)
	{
	    for(i=0; i<cur_script->end-cur_script->start+1; i++)buf[i]=buf[cur_script->start+i];	
	    
	    cur_script->end   = cur_script->end-cur_script->start;
	    cur_script->start = 0;	    
	}
	for(; cur_script!=0; cur_script=cur_script->next)
	{
	
		if(cur_script->next ==0) return 1;
		next_script = cur_script->next;
		next_start = next_script->start;
		next_end = next_script->end;
		end = cur_script->end;	
		if(next_start!=(end+1))
		{
		    //move buffer
		    //i= end+1;
		     //	j++;
		    for(i=0; i<next_end-next_start+1; i++)buf[end+1+i]=buf[next_start+i];	
		    next_script->start = end+1;
	     	next_script->end = end+next_end-next_start+1;	     
		}
	
	}
	return 1;
}

void getKeys(void) 
{
    memUnit* cur_script;
    tU16 i, j;
    i=0;
    
    for(cur_script=&first_script; cur_script!=0; 
        cur_script=cur_script->next){
        for(j=0; j<KEY_LEN; j++)
            sharedatabuf[i++]=cur_script->key[j];        
    }
}

