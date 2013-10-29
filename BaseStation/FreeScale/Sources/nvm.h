/*******************************************************************
 *
 *    Source file nvm.h
 *    AUTHOR: George Wong
 *    Date Created:	12/08/2005 
 *    REV. HISTORY: 25/08/05 Added - EEPROM_Erase_Sector,
 *                                   Flash_Erase_Block
 *                           Codes tweaked  
 *
 *******************************************************************/
 
#ifndef _NVM_H_
#define _NVM_H_


/* prototypes EEPROM access */
//void          EEPROM_Init(unsigned long oscclk);
//unsigned int  EEPROM_Write_Word(unsigned int address,unsigned int data);
//unsigned int  EEPROM_Erase_Sector(unsigned int address);
//unsigned int  EEPROM_Read_Word(unsigned int address);


/* prototypes Flash ROM access */

void          Flash_Init(unsigned long oscclk);
unsigned int  Flash_Write_Word(
                               unsigned int address,
                               unsigned int data);
unsigned int  Flash_Erase_Block(unsigned char block);
unsigned int  Flash_Read_Word(unsigned int address);

#endif /* _NVM_H_ */
