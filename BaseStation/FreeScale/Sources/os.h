/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     : os.h
 * Description   : This file contains OS dependant ENTER and EXIT CRITICAL
 *
 * Version : 1.0
 * Date    : Apr/04/04
 *
 *
 ******************************************************************************/

#ifndef __OS_H_
#define __OS_H_

extern void os_enter_critical_section (void);
extern void os_exit_critical_section  (void);

#define OS_ENTER_CRITICAL()  os_enter_critical_section()
#define OS_EXIT_CRITICAL()   os_exit_critical_section()

#endif
