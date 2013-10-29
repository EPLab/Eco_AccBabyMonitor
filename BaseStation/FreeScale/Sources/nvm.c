/*******************************************************************
 *
 *    Source file nvm.c
 *    AUTHOR: George Wong
 *    Date Created:	12/08/2005 
 *    REV. HISTORY: 25/08/05 Added - EEPROM_Erase_Sector,
 *                                   Flash_Erase_Block
 *                           Codes tweaked  
 *
 *******************************************************************/
 
#include "MC9S12NE64.h"

#define Odd_Access -1
#define Access_Error -2
#define Protection_Error -3
#define FLASH_NOT_ERASED
#define PROG 0x20
#define ERASE 0x40
#define Flash_Sector_Size 512
#define Not_StartofSector_Error -6
extern DoOnStack(unsigned int * address);
/* setup EEPROM control unit */
//void EEPROM_Init(unsigned long oscclk)
//{
//  unsigned char eclk_val;
	
  /* Next, initialize FCLKDIV register to ensure we can program/erase */
//	if (oscclk >= 12000) {
//		eclk_val = oscclk/8/200 - 1; /* FDIV8 set since above 12MHz clock */
//		ECLKDIV = ECLKDIV | eclk_val| ECLKDIV_PRDIV8_MASK;
//	} else {
//		eclk_val = oscclk/200 - 1;
//		ECLKDIV = ECLKDIV | eclk_val;
//	}

	//FPROT = 0xFF; /* Disable all protection (only in special modes)*/
//	ESTAT = ESTAT | (ESTAT_PVIOL_MASK|ESTAT_ACCERR_MASK);/* Clear any errors  */
//} 



/* write a single word (16-bit) to EEPROM */
//signed char EEPROM_Write_Word(unsigned int address,unsigned int data)
//{
 // while(!ESTAT_CBEIF);                 				          // ready?
//	ESTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK);       // clear errors
//	if(address & 0x0001) {return Odd_Access;}             // Aligned word?
//	(*(unsigned int *)address) = data;	                  // Store desired data to address being programmed 
//	ECMD = ECMD_CMDB5_MASK;	                              // Store programming command in FCMD
//	ESTAT_CBEIF = 1;
//	if(ESTAT_ACCERR) {return Access_Error;}
//	if(ESTAT_PVIOL) {return Protection_Error;}
//	return 1;
//}



/* Erase a EEPROM sector (4 bytes) */
//signed char EEPROM_Erase_Sector(unsigned int address)
//{
 // while(!ESTAT_CBEIF);                 				          // ready?
 	//ESTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK);       // clear errors
	//if(address & 0x0001) {return Odd_Access;}             // Aligned word?
//	(*(unsigned int *)address) = 0xFFFF;	                // Store desired data to address being programmed 
//	ECMD = ECMD_CMDB6_MASK;	                              // Store programming command in FCMD
 // ESTAT_CBEIF = 1;
 //	if(ESTAT_ACCERR) {return Access_Error;}
	//if(ESTAT_PVIOL) {return Protection_Error;}
	//return 1;

//}



/* read a single word (16-bit) from EEPROM */
//unsigned int EEPROM_Read_Word(unsigned int address)
//{
//  while(!ESTAT_CCIF);										// ready?
//	return (unsigned int)*(unsigned int *)address;
//}

//*****************************************************************************
//* Function Name: Flash_Erase_Sector
//* Description : Erases a given Flash sector using address
//* passed from calling function.
//*
//*****************************************************************************
signed char Flash_Erase_Sector(unsigned int address)
{
//unsigned int* address;
//address = (unsigned int*)far_address; // strip page off
if((unsigned int)address & 0x0001) {return Odd_Access;} // Aligned word?
if((unsigned int)address % Flash_Sector_Size !=0) {return Not_StartofSector_Error;}
FSTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK); // clear errors
(*(unsigned int *)address) = 0xFFFF;/* Dummy store to page to be erased */
FCMD=ERASE;
(void)DoOnStack(&address);
if(FSTAT_ACCERR) {return Access_Error;}
	if(FSTAT_PVIOL) {return Protection_Error;}
return 1;
}


/* setup Flash ROM control unit */
void Flash_Init(unsigned long oscclk)
{
unsigned char fclk_val;
	
/* Next, initialize FCLKDIV register to ensure we can program/erase */
	if (oscclk >= 12000) {
		fclk_val = oscclk/8/200 - 1; /* FDIV8 set since above 12MHz clock */
		FCLKDIV = FCLKDIV | fclk_val| FCLKDIV_PRDIV8_MASK;
	} else {
		fclk_val = oscclk/200 - 1;
		FCLKDIV = FCLKDIV | fclk_val;
	}

	//FPROT = 0xFF; /* Disable all protection (only in special modes)*/
	FSTAT = FSTAT | (FSTAT_PVIOL_MASK|FSTAT_ACCERR_MASK);/* Clear any errors  */
}



/* write a single word (16-bit) to Flash ROM */
signed char Flash_Write_Word(
                             unsigned int addr,
                             unsigned int data)
{
 // PPAGE = 0x3E;
 
  //unsigned int addr;
  //addr = (unsigned int*)address;
  if((*(unsigned int *)addr)  != 0xFFFF) {Flash_Erase_Sector(addr&0xfe00);}
  FSTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK);  
  while(!FSTAT_CBEIF);                										// ready?
	
	FSTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK);         // clear errors
	if(addr & 0x0001) {return Odd_Access;}               // Aligned word?
	
	(*(unsigned int *)addr) = data;	                    // Store desired data to address being programmed 
	//PTG_PTG0=1;
	 
	FCMD = PROG;	                                // Store programming command in FCMD
	//	PTG_PTG0=1;
	//FSTAT_CBEIF = 1 ;
	(void) DoOnStack(&addr);
	if(FSTAT_ACCERR) {return Access_Error;}
	if(FSTAT_PVIOL) {return Protection_Error;}

	while(FSTAT_CCIF !=1);

	return 1;
}



/* Erase a Flash ROM block (64k bytes) */
signed char Flash_Erase_Block(unsigned char block)
{
  //FCNFG = block;
  while(!FSTAT_CBEIF);										                // ready?
          // clear errors
  (*(unsigned int *)0x8000) = 0xFFFF;
	FSTAT = (FSTAT_ACCERR_MASK | FSTAT_PVIOL_MASK);
	FCMD = 0x41;	                 // Store programming command in FCMD
	FSTAT_CBEIF = 1;
	if(FSTAT_ACCERR) {return Access_Error;}
	if(FSTAT_PVIOL) {return Protection_Error;}
	return 1;
}



/* read a single word (16-bit) from Flash ROM */
unsigned int Flash_Read_Word(unsigned int address)
{
  //FCNFG = (~ppage & 0x0C)>>2;
  //PPAGE = ppage;
 //  PPAGE = 0x3E;
  while(!FSTAT_CCIF);										// ready?
	return (unsigned int)*(unsigned int *)address;
}