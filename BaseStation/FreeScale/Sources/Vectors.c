/******************************************************************************
 *
 *                      (c) Freescale  Inc. 2004 All rights reserved
 *
 * File Name     :Vectors.c
 * Description   :
 *
 * Version : 1.0
 * Date    : Jun/22/2004
 *
 ******************************************************************************/

extern void near _Startup(void);              /* Startup routine */
extern void near RealTimeInterrupt(void);    
extern void near emac_ec_isr(void);
extern void near emac_lc_isr(void);
extern void near emac_b_rx_error_isr(void);
extern void near emac_rx_b_b_o_isr(void);
extern void near emac_rx_b_a_o_isr(void);
extern void near emac_rx_error_isr(void);
extern void near emac_mii_mtc_isr(void);
extern void near emac_rx_fc_isr(void);
extern void near emac_f_tx_c_isr(void);
extern void near emac_rx_b_b_c_isr(void);
extern void near emac_rx_b_a_c_isr(void);
extern void near ephy_isr(void);
extern void near PortHInterrupt(void);
extern void near Timer4Interrupt(void);
extern void near Timer5Interrupt(void);
extern void near Timer6Interrupt(void);
extern void near Timer7Interrupt(void);
//extern void near SCI1Interrupt(void);
//************************************************************************
// SOFTWARE TRAP FUNCTION
// DESCRIPTION:
// Function that traps  all unexpected interrupts.  Used for debugging 
// software to find runaway code.
//************************************************************************

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Interrupt section for this module. Placement will be in NON_BANKED area. */        
__interrupt void software_trap(void){ for(;;); }
#pragma CODE_SEG DEFAULT               /* Change code section to DEFAULT. */

//************************************************************************


typedef void (*near tIsrFunc)(void);
const tIsrFunc _vect[] @0xFF80 = {     /* Interrupt table */
        software_trap,                 /* 0 Default (unused) interrupt */
        software_trap,                 /* 1 Default (unused) interrupt */
        software_trap,                 /* 2 Default (unused) interrupt */
        software_trap,                 /* 3 Default (unused) interrupt */
        software_trap,                 /* 4 Default (unused) interrupt */
        software_trap,                 /* 5 Default (unused) interrupt */
        software_trap,                 /* 6 Default (unused) interrupt */
        software_trap,                 /* 7 Default (unused) interrupt */
        software_trap,                 /* 8 Default (unused) interrupt */
        software_trap,                 /* 9 Default (unused) interrupt */
        software_trap,                 /* 10 Default (unused) interrupt */
        software_trap,                 /* 11 Default (unused) interrupt */
        software_trap,                 /* 12 Default (unused) interrupt */
        software_trap,                 /* 13 Default (unused) interrupt */
        software_trap,                 /* 14 Default (unused) interrupt */
        software_trap,                 /* 15 Default (unused) interrupt */
        emac_ec_isr,
        emac_lc_isr,
        emac_b_rx_error_isr,
        emac_rx_b_b_o_isr,
        emac_rx_b_a_o_isr,
        emac_rx_error_isr,
        emac_mii_mtc_isr,
        emac_rx_fc_isr,
        emac_f_tx_c_isr,
        emac_rx_b_b_c_isr,
        emac_rx_b_a_c_isr,
        ephy_isr,
        software_trap,                 /* 28 Default (unused) interrupt */
        software_trap,                 /* 29 Default (unused) interrupt */
        software_trap,                 /* 30 Default (unused) interrupt */
        software_trap,                 /* 31 Default (unused) interrupt */
        software_trap,                 /* 32 Default (unused) interrupt */
        software_trap,                 /* 33 Default (unused) interrupt */
        software_trap,                 /* 34 Default (unused) interrupt */
        software_trap,                 /* 35 Default (unused) interrupt */
        software_trap,                 /* 36 Default (unused) interrupt */
        software_trap,                 /* 37 Default (unused) interrupt */
        PortHInterrupt,                 /* 38 Default (unused) interrupt */
        software_trap,                 /* 39 Default (unused) interrupt */
        software_trap,                 /* 40 Default (unused) interrupt */
        software_trap,                 /* 41 Default (unused) interrupt */
       //  SCI1Interrupt,                   /* 42 Default (unused) interrupt */
     PortHInterrupt,                  /* 42 Default (unused) interrupt */
     software_trap,                /* 43 Default (unused) interrupt */
        software_trap,                 /* 44 Default (unused) interrupt */
        software_trap,                 /* 45 Default (unused) interrupt */
        software_trap,                 /* 46 Default (unused) interrupt */
         software_trap,                  /* standard timer overflow */
        Timer7Interrupt,                  /* 48 Default (unused) interrupt */
        Timer6Interrupt,                /* 49 Default (unused) interrupt */
        Timer5Interrupt,             /* 50 Default (unused) interrupt */
        Timer4Interrupt,                /* 51 Default (unused) interrupt */
        software_trap,                 /* 52 Default (unused) interrupt */
        software_trap,                 /* 53 Default (unused) interrupt */
        software_trap,                 /* 54 Default (unused) interrupt */
        software_trap,                 /* 55 Default (unused) interrupt */
        RealTimeInterrupt,             /* 56 Default (unused) interrupt */
        software_trap,                 /* 57 Default (unused) interrupt */
        software_trap,                 /* 58 Default (unused) interrupt */
        software_trap,                 /* 59 Default (unused) interrupt */
        software_trap,                 /* 60 Default (unused) interrupt */
        software_trap,                 /* 61 Default (unused) interrupt */
        software_trap,                 /* 62 Default (unused) interrupt */
        _Startup                    /* Reset vector */
   };
