#ifndef __BUFFER__H__
#define __BUFFER__H__
#include <stdio.h>
#include "ne64debug.h"
#include "MOTTYPES.h"
#include "MC9S12NE64.h"

#define BUF_LEN 256
#define STACK_LEN 32
#define KEY_BUF_LEN 128
#define KEY_LEN 5
#define SEPARATOR ':'
#define CODE 0
#define DATA 1

typedef struct
{	
	unsigned char key[KEY_LEN];
	//unsigned char* operand;	
	//unsigned char* op_len;
	tU16 start;
	tU16 end;	
	struct memUnit* next;
}memUnit;

//typedef struct memUnit;
extern unsigned char mem_buf[];
extern unsigned char op_stack[];
extern unsigned char len_stack[];
extern unsigned char sharedatabuf[];
extern unsigned char script_key_buf[];
extern unsigned char var_key_buf[];
extern unsigned char sharedatabuf[];

extern unsigned char op_top;
extern unsigned char len_top;
extern tU16 buf_head;
extern tU16 buf_tail;
extern struct memUnit first_script;
extern unsigned char script_key_index;


char addScript(char mode, unsigned char* cmd, char len);
struct memUnit* findScript(char mode, unsigned char* cmd);
char rmScript(char mode, unsigned char* cmd);
void initBuffer(void);
char defragMem(char mode, char* buf);
void getKeys(void);
#endif
