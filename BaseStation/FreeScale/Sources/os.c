/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : os.c
 * Description   : This file contains OS dependant ENTER and EXIT CRITICAL
 *
 * Version : 1.0
 * Date    : Apr/04/04
 *
 *
 ******************************************************************************/

#include "os.h"


/******************************************************************************
*
*
******************************************************************************/
void os_enter_critical_section (void)
{
    { __asm SEI; };    /* Disable Interrupts */
}

/******************************************************************************
*
*
******************************************************************************/
void os_exit_critical_section (void)
{
    { __asm CLI; };    /* Enable Interrupts */
}
