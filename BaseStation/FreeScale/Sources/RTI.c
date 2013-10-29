/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : Rti.c
 * Description   : RTI-based Pulling (RIPE-MAC)
 *
 * Version : 1.1
 * Author : Vahid Salmani
 * Date: 08/20/2008  
 * 				
 *
 ******************************************************************************/ 
#include "timers.h"
#include "MC9S12NE64.h"
#include "rf24g-freescale.h"/**/

int interrupt_counter;


/******************************************************************************
*
*
******************************************************************************/
void RTI_Init (void)
{
    CRGINT_RTIE = 0;                     /* Disable interrupt */
    RTICTL_RTR = 0x40;//0x50//0x71       /* Store given value to the prescaler */
    interrupt_counter = 0;
}

/******************************************************************************
*
*
******************************************************************************/
void RTI_Enable (void)
{
    //CRGFLG = CRGINT_RTIE_MASK;       /* Reset interrupt request flag */
    
    CRGFLG |= CRGINT_RTIE_MASK;/**/		 /* Set the RTIF bit to 1 */
    CRGINT_RTIE = 1;                   /* Enable interrupt */
}


/******************************************************************************
*
*
******************************************************************************/
void RTI_Disable (void)
{
    CRGINT_RTIE = 0;                   /* Disable interrupt */
}


/******************************************************************************
*
*
******************************************************************************/
#pragma CODE_SEG NON_BANKED
interrupt void RealTimeInterrupt (void)
{			   
//volatile static unsigned char state = 0;
    
    //static unsigned int count = 0;

    CRGFLG = CRGINT_RTIE_MASK;            /* Reset interrupt request flag */
    
  //set_debug_hi();
  interrupt_counter++;
  //set_debug_low();

    
    
    /*
    if (state = ~state)
    {
        //PTL_PTL0  = 0;			 //Turn on ACTLED
    }
    else
    {
        //PTL_PTL0  = 1;			 //Turn off ACTLED
    }
    */

}
#pragma CODE_SEG DEFAULT