/* Based on CPU DB MC9S12NE64, version 2.87.029 (RegistersPrg V1.055) */
/*
** ###################################################################
**     Filename  : MC9S12NE64.h
**     Processor : MC9S12NE64CPV
**     FileFormat: V1.055
**     DataSheet : 9S12NE-FamilyDGV1/D V01.04
**     Compiler  : Metrowerks C compiler
**     Date/Time : 10.03.2004, 15:30
**     Abstract  :
**         This implements an IO devices mapping.
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2003
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################
*/

#ifndef _MC9S12NE64_H
#define _MC9S12NE64_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector table ****************/
#define VReserved63             0x0000FF80
#define VReserved62             0x0000FF82
#define VReserved61             0x0000FF84
#define VReserved60             0x0000FF86
#define VReserved59             0x0000FF88
#define VReserved58             0x0000FF8A
#define VReserved57             0x0000FF8C
#define VReserved56             0x0000FF8E
#define VReserved55             0x0000FF90
#define VReserved54             0x0000FF92
#define VReserved53             0x0000FF94
#define VReserved52             0x0000FF96
#define VReserved51             0x0000FF98
#define VReserved50             0x0000FF9A
#define VReserved49             0x0000FF9C
#define VReserved48             0x0000FF9E
#define Vemacec                 0x0000FFA0
#define Vemaclc                 0x0000FFA2
#define Vemacbrxerr             0x0000FFA4
#define Vemacrxbbo              0x0000FFA6
#define Vemacrxbao              0x0000FFA8
#define Vemacrxerr              0x0000FFAA
#define Vemacmii                0x0000FFAC
#define Vemacrxfc               0x0000FFAE
#define Vemactxc                0x0000FFB0
#define Vemacrxbbc              0x0000FFB2
#define Vemacrxbac              0x0000FFB4
#define Vephy                   0x0000FFB6
#define Vflash                  0x0000FFB8
#define VReserved34             0x0000FFBA
#define VReserved33             0x0000FFBC
#define VReserved32             0x0000FFBE
#define Viic                    0x0000FFC0
#define VReserved30             0x0000FFC2
#define Vcrgscm                 0x0000FFC4
#define Vcrgplllck              0x0000FFC6
#define VReserved27             0x0000FFC8
#define Vportg                  0x0000FFCA
#define Vporth                  0x0000FFCC
#define Vportj                  0x0000FFCE
#define VReserved23             0x0000FFD0
#define Vatd                    0x0000FFD2
#define Vsci1                   0x0000FFD4
#define Vsci0                   0x0000FFD6
#define Vspi                    0x0000FFD8
#define Vtimpaie                0x0000FFDA
#define Vtimpaovf               0x0000FFDC
#define Vtimovf                 0x0000FFDE
#define Vtimch7                 0x0000FFE0
#define Vtimch6                 0x0000FFE2
#define Vtimch5                 0x0000FFE4
#define Vtimch4                 0x0000FFE6
#define VReserved11             0x0000FFE8
#define VReserved10             0x0000FFEA
#define VReserved9              0x0000FFEC
#define VReserved8              0x0000FFEE
#define Vrti                    0x0000FFF0
#define Virq                    0x0000FFF2
#define Vxirq                   0x0000FFF4
#define Vswi                    0x0000FFF6
#define Vtrap                   0x0000FFF8
#define Vcop                    0x0000FFFA
#define Vclkmon                 0x0000FFFC
#define Vreset                  0x0000FFFE

/**************** registers I/O map ****************/

/*** PORTAB - Port AB Register; 0x00000000 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PORTA - Port A Register; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port A Bit 0 */
        byte BIT1        :1;                                       /* Port A Bit 1 */
        byte BIT2        :1;                                       /* Port A Bit 2 */
        byte BIT3        :1;                                       /* Port A Bit 3 */
        byte BIT4        :1;                                       /* Port A Bit 4 */
        byte BIT5        :1;                                       /* Port A Bit 5 */
        byte BIT6        :1;                                       /* Port A Bit 6 */
        byte BIT7        :1;                                       /* Port A Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } PORTASTR;
    #define PORTA                       _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_BIT0                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT0
    #define PORTA_BIT1                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT1
    #define PORTA_BIT2                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT2
    #define PORTA_BIT3                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT3
    #define PORTA_BIT4                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT4
    #define PORTA_BIT5                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT5
    #define PORTA_BIT6                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT6
    #define PORTA_BIT7                  _PORTAB.Overlap_STR.PORTASTR.Bits.BIT7
    
    
    #define PORTA_BIT0_MASK             1
    #define PORTA_BIT1_MASK             2
    #define PORTA_BIT2_MASK             4
    #define PORTA_BIT3_MASK             8
    #define PORTA_BIT4_MASK             16
    #define PORTA_BIT5_MASK             32
    #define PORTA_BIT6_MASK             64
    #define PORTA_BIT7_MASK             128


    /*** PORTB - Port B Register; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Port B Bit 0 */
        byte BIT1        :1;                                       /* Port B Bit 1 */
        byte BIT2        :1;                                       /* Port B Bit 2 */
        byte BIT3        :1;                                       /* Port B Bit 3 */
        byte BIT4        :1;                                       /* Port B Bit 4 */
        byte BIT5        :1;                                       /* Port B Bit 5 */
        byte BIT6        :1;                                       /* Port B Bit 6 */
        byte BIT7        :1;                                       /* Port B Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } PORTBSTR;
    #define PORTB                       _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_BIT0                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT0
    #define PORTB_BIT1                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT1
    #define PORTB_BIT2                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT2
    #define PORTB_BIT3                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT3
    #define PORTB_BIT4                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT4
    #define PORTB_BIT5                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT5
    #define PORTB_BIT6                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT6
    #define PORTB_BIT7                  _PORTAB.Overlap_STR.PORTBSTR.Bits.BIT7
    
    
    #define PORTB_BIT0_MASK             1
    #define PORTB_BIT1_MASK             2
    #define PORTB_BIT2_MASK             4
    #define PORTB_BIT3_MASK             8
    #define PORTB_BIT4_MASK             16
    #define PORTB_BIT5_MASK             32
    #define PORTB_BIT6_MASK             64
    #define PORTB_BIT7_MASK             128

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Port AB Bit 0 */
    word BIT1        :1;                                       /* Port AB Bit 1 */
    word BIT2        :1;                                       /* Port AB Bit 2 */
    word BIT3        :1;                                       /* Port AB Bit 3 */
    word BIT4        :1;                                       /* Port AB Bit 4 */
    word BIT5        :1;                                       /* Port AB Bit 5 */
    word BIT6        :1;                                       /* Port AB Bit 6 */
    word BIT7        :1;                                       /* Port AB Bit 7 */
    word BIT8        :1;                                       /* Port AB Bit 8 */
    word BIT9        :1;                                       /* Port AB Bit 9 */
    word BIT10       :1;                                       /* Port AB Bit 10 */
    word BIT11       :1;                                       /* Port AB Bit 11 */
    word BIT12       :1;                                       /* Port AB Bit 12 */
    word BIT13       :1;                                       /* Port AB Bit 13 */
    word BIT14       :1;                                       /* Port AB Bit 14 */
    word BIT15       :1;                                       /* Port AB Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000);
#define PORTAB                          _PORTAB.Word
#define PORTAB_BIT0                     _PORTAB.Bits.BIT0
#define PORTAB_BIT1                     _PORTAB.Bits.BIT1
#define PORTAB_BIT2                     _PORTAB.Bits.BIT2
#define PORTAB_BIT3                     _PORTAB.Bits.BIT3
#define PORTAB_BIT4                     _PORTAB.Bits.BIT4
#define PORTAB_BIT5                     _PORTAB.Bits.BIT5
#define PORTAB_BIT6                     _PORTAB.Bits.BIT6
#define PORTAB_BIT7                     _PORTAB.Bits.BIT7
#define PORTAB_BIT8                     _PORTAB.Bits.BIT8
#define PORTAB_BIT9                     _PORTAB.Bits.BIT9
#define PORTAB_BIT10                    _PORTAB.Bits.BIT10
#define PORTAB_BIT11                    _PORTAB.Bits.BIT11
#define PORTAB_BIT12                    _PORTAB.Bits.BIT12
#define PORTAB_BIT13                    _PORTAB.Bits.BIT13
#define PORTAB_BIT14                    _PORTAB.Bits.BIT14
#define PORTAB_BIT15                    _PORTAB.Bits.BIT15

#define PORTAB_BIT0_MASK                1
#define PORTAB_BIT1_MASK                2
#define PORTAB_BIT2_MASK                4
#define PORTAB_BIT3_MASK                8
#define PORTAB_BIT4_MASK                16
#define PORTAB_BIT5_MASK                32
#define PORTAB_BIT6_MASK                64
#define PORTAB_BIT7_MASK                128
#define PORTAB_BIT8_MASK                256
#define PORTAB_BIT9_MASK                512
#define PORTAB_BIT10_MASK               1024
#define PORTAB_BIT11_MASK               2048
#define PORTAB_BIT12_MASK               4096
#define PORTAB_BIT13_MASK               8192
#define PORTAB_BIT14_MASK               16384
#define PORTAB_BIT15_MASK               32768


/*** DDRAB - Port AB Data Direction Register; 0x00000002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRA - Port A Data Direction Register; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port A Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port A Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port A Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port A Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port A Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port A Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port A Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port A Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DDRASTR;
    #define DDRA                        _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_BIT0                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT0
    #define DDRA_BIT1                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT1
    #define DDRA_BIT2                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT2
    #define DDRA_BIT3                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT3
    #define DDRA_BIT4                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT4
    #define DDRA_BIT5                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT5
    #define DDRA_BIT6                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT6
    #define DDRA_BIT7                   _DDRAB.Overlap_STR.DDRASTR.Bits.BIT7
    
    
    #define DDRA_BIT0_MASK              1
    #define DDRA_BIT1_MASK              2
    #define DDRA_BIT2_MASK              4
    #define DDRA_BIT3_MASK              8
    #define DDRA_BIT4_MASK              16
    #define DDRA_BIT5_MASK              32
    #define DDRA_BIT6_MASK              64
    #define DDRA_BIT7_MASK              128


    /*** DDRB - Port B Data Direction Register; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Data Direction Port B Bit 0 */
        byte BIT1        :1;                                       /* Data Direction Port B Bit 1 */
        byte BIT2        :1;                                       /* Data Direction Port B Bit 2 */
        byte BIT3        :1;                                       /* Data Direction Port B Bit 3 */
        byte BIT4        :1;                                       /* Data Direction Port B Bit 4 */
        byte BIT5        :1;                                       /* Data Direction Port B Bit 5 */
        byte BIT6        :1;                                       /* Data Direction Port B Bit 6 */
        byte BIT7        :1;                                       /* Data Direction Port B Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DDRBSTR;
    #define DDRB                        _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_BIT0                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT0
    #define DDRB_BIT1                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT1
    #define DDRB_BIT2                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT2
    #define DDRB_BIT3                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT3
    #define DDRB_BIT4                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT4
    #define DDRB_BIT5                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT5
    #define DDRB_BIT6                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT6
    #define DDRB_BIT7                   _DDRAB.Overlap_STR.DDRBSTR.Bits.BIT7
    
    
    #define DDRB_BIT0_MASK              1
    #define DDRB_BIT1_MASK              2
    #define DDRB_BIT2_MASK              4
    #define DDRB_BIT3_MASK              8
    #define DDRB_BIT4_MASK              16
    #define DDRB_BIT5_MASK              32
    #define DDRB_BIT6_MASK              64
    #define DDRB_BIT7_MASK              128

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Data Direction Port AB Bit 0 */
    word BIT1        :1;                                       /* Data Direction Port AB Bit 1 */
    word BIT2        :1;                                       /* Data Direction Port AB Bit 2 */
    word BIT3        :1;                                       /* Data Direction Port AB Bit 3 */
    word BIT4        :1;                                       /* Data Direction Port AB Bit 4 */
    word BIT5        :1;                                       /* Data Direction Port AB Bit 5 */
    word BIT6        :1;                                       /* Data Direction Port AB Bit 6 */
    word BIT7        :1;                                       /* Data Direction Port AB Bit 7 */
    word BIT8        :1;                                       /* Data Direction Port AB Bit 8 */
    word BIT9        :1;                                       /* Data Direction Port AB Bit 9 */
    word BIT10       :1;                                       /* Data Direction Port AB Bit 10 */
    word BIT11       :1;                                       /* Data Direction Port AB Bit 11 */
    word BIT12       :1;                                       /* Data Direction Port AB Bit 12 */
    word BIT13       :1;                                       /* Data Direction Port AB Bit 13 */
    word BIT14       :1;                                       /* Data Direction Port AB Bit 14 */
    word BIT15       :1;                                       /* Data Direction Port AB Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002);
#define DDRAB                           _DDRAB.Word
#define DDRAB_BIT0                      _DDRAB.Bits.BIT0
#define DDRAB_BIT1                      _DDRAB.Bits.BIT1
#define DDRAB_BIT2                      _DDRAB.Bits.BIT2
#define DDRAB_BIT3                      _DDRAB.Bits.BIT3
#define DDRAB_BIT4                      _DDRAB.Bits.BIT4
#define DDRAB_BIT5                      _DDRAB.Bits.BIT5
#define DDRAB_BIT6                      _DDRAB.Bits.BIT6
#define DDRAB_BIT7                      _DDRAB.Bits.BIT7
#define DDRAB_BIT8                      _DDRAB.Bits.BIT8
#define DDRAB_BIT9                      _DDRAB.Bits.BIT9
#define DDRAB_BIT10                     _DDRAB.Bits.BIT10
#define DDRAB_BIT11                     _DDRAB.Bits.BIT11
#define DDRAB_BIT12                     _DDRAB.Bits.BIT12
#define DDRAB_BIT13                     _DDRAB.Bits.BIT13
#define DDRAB_BIT14                     _DDRAB.Bits.BIT14
#define DDRAB_BIT15                     _DDRAB.Bits.BIT15

#define DDRAB_BIT0_MASK                 1
#define DDRAB_BIT1_MASK                 2
#define DDRAB_BIT2_MASK                 4
#define DDRAB_BIT3_MASK                 8
#define DDRAB_BIT4_MASK                 16
#define DDRAB_BIT5_MASK                 32
#define DDRAB_BIT6_MASK                 64
#define DDRAB_BIT7_MASK                 128
#define DDRAB_BIT8_MASK                 256
#define DDRAB_BIT9_MASK                 512
#define DDRAB_BIT10_MASK                1024
#define DDRAB_BIT11_MASK                2048
#define DDRAB_BIT12_MASK                4096
#define DDRAB_BIT13_MASK                8192
#define DDRAB_BIT14_MASK                16384
#define DDRAB_BIT15_MASK                32768


/*** PORTE - Port E Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port E Bit 0 */
    byte BIT1        :1;                                       /* Port E Bit 1 */
    byte BIT2        :1;                                       /* Port E Bit 2 */
    byte BIT3        :1;                                       /* Port E Bit 3 */
    byte BIT4        :1;                                       /* Port E Bit 4 */
    byte BIT5        :1;                                       /* Port E Bit 5 */
    byte BIT6        :1;                                       /* Port E Bit 6 */
    byte BIT7        :1;                                       /* Port E Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008);
#define PORTE                           _PORTE.Byte
#define PORTE_BIT0                      _PORTE.Bits.BIT0
#define PORTE_BIT1                      _PORTE.Bits.BIT1
#define PORTE_BIT2                      _PORTE.Bits.BIT2
#define PORTE_BIT3                      _PORTE.Bits.BIT3
#define PORTE_BIT4                      _PORTE.Bits.BIT4
#define PORTE_BIT5                      _PORTE.Bits.BIT5
#define PORTE_BIT6                      _PORTE.Bits.BIT6
#define PORTE_BIT7                      _PORTE.Bits.BIT7

#define PORTE_BIT0_MASK                 1
#define PORTE_BIT1_MASK                 2
#define PORTE_BIT2_MASK                 4
#define PORTE_BIT3_MASK                 8
#define PORTE_BIT4_MASK                 16
#define PORTE_BIT5_MASK                 32
#define PORTE_BIT6_MASK                 64
#define PORTE_BIT7_MASK                 128


/*** DDRE - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte BIT2        :1;                                       /* Data Direction Port A Bit 2 */
    byte BIT3        :1;                                       /* Data Direction Port A Bit 3 */
    byte BIT4        :1;                                       /* Data Direction Port A Bit 4 */
    byte BIT5        :1;                                       /* Data Direction Port A Bit 5 */
    byte BIT6        :1;                                       /* Data Direction Port A Bit 6 */
    byte BIT7        :1;                                       /* Data Direction Port A Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpBIT_2 :6;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009);
#define DDRE                            _DDRE.Byte
#define DDRE_BIT2                       _DDRE.Bits.BIT2
#define DDRE_BIT3                       _DDRE.Bits.BIT3
#define DDRE_BIT4                       _DDRE.Bits.BIT4
#define DDRE_BIT5                       _DDRE.Bits.BIT5
#define DDRE_BIT6                       _DDRE.Bits.BIT6
#define DDRE_BIT7                       _DDRE.Bits.BIT7
#define DDRE_BIT_2                      _DDRE.MergedBits.grpBIT_2
#define DDRE_BIT                        DDRE_BIT_2

#define DDRE_BIT2_MASK                  4
#define DDRE_BIT3_MASK                  8
#define DDRE_BIT4_MASK                  16
#define DDRE_BIT5_MASK                  32
#define DDRE_BIT6_MASK                  64
#define DDRE_BIT7_MASK                  128
#define DDRE_BIT_2_MASK                 252
#define DDRE_BIT_2_BITNUM               2


/*** PEAR - Port E Assignment Register; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RDWE        :1;                                       /* Read / Write Enable */
    byte LSTRE       :1;                                       /* Lw Strobe (LSTRB) Enable */
    byte NECLK       :1;                                       /* No External E Clock */
    byte PIPOE       :1;                                       /* Pipe Status Signal Output Enable */
    byte             :1; 
    byte NOACCE      :1;                                       /* CPU No Access Output Enable */
  } Bits;
} PEARSTR;
extern volatile PEARSTR _PEAR @(REG_BASE + 0x0000000A);
#define PEAR                            _PEAR.Byte
#define PEAR_RDWE                       _PEAR.Bits.RDWE
#define PEAR_LSTRE                      _PEAR.Bits.LSTRE
#define PEAR_NECLK                      _PEAR.Bits.NECLK
#define PEAR_PIPOE                      _PEAR.Bits.PIPOE
#define PEAR_NOACCE                     _PEAR.Bits.NOACCE

#define PEAR_RDWE_MASK                  4
#define PEAR_LSTRE_MASK                 8
#define PEAR_NECLK_MASK                 16
#define PEAR_PIPOE_MASK                 32
#define PEAR_NOACCE_MASK                128


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte EME         :1;                                       /* Emulate Port E */
    byte EMK         :1;                                       /* Emulate Port K */
    byte             :1; 
    byte IVIS        :1;                                       /* Internal Visibility */
    byte             :1; 
    byte MODA        :1;                                       /* Mode Select Bit A */
    byte MODB        :1;                                       /* Mode Select Bit B */
    byte MODC        :1;                                       /* Mode Select Bit C */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpMOD  :3;
  } MergedBits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000B);
#define MODE _MODE.Byte
#define MODE_EME _MODE.Bits.EME
#define MODE_EMK _MODE.Bits.EMK
#define MODE_IVIS _MODE.Bits.IVIS
#define MODE_MODA _MODE.Bits.MODA
#define MODE_MODB _MODE.Bits.MODB
#define MODE_MODC _MODE.Bits.MODC
#define MODE_MOD _MODE.MergedBits.grpMOD

#define MODE_EME_MASK  1
#define MODE_EMK_MASK  2
#define MODE_IVIS_MASK  8
#define MODE_MODA_MASK  32
#define MODE_MODB_MASK  64
#define MODE_MODC_MASK  128
#define MODE_MOD_MASK  224
#define MODE_MOD_BITNUM  5


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PUPAE       :1;                                       /* Pull-Up Port A Enable */
    byte PUPBE       :1;                                       /* Pull-Up Port B Enable */
    byte             :1; 
    byte             :1; 
    byte PUPEE       :1;                                       /* Pull-Up Port E Enable */
    byte             :1; 
    byte             :1; 
    byte PUPKE       :1;                                       /* Pull-Up Port K Enable */
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000C);
#define PUCR _PUCR.Byte
#define PUCR_PUPAE _PUCR.Bits.PUPAE
#define PUCR_PUPBE _PUCR.Bits.PUPBE
#define PUCR_PUPEE _PUCR.Bits.PUPEE
#define PUCR_PUPKE _PUCR.Bits.PUPKE

#define PUCR_PUPAE_MASK  1
#define PUCR_PUPBE_MASK  2
#define PUCR_PUPEE_MASK  16
#define PUCR_PUPKE_MASK  128


/*** RDRIV - Reduced Drive of I/O Lines; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte RDPA        :1;                                       /* Reduced Drive of Port A */
    byte RDPB        :1;                                       /* Reduced Drive of Port B */
    byte             :1; 
    byte             :1; 
    byte RDPE        :1;                                       /* Reduced Drive of Port E */
    byte             :1; 
    byte             :1; 
    byte RDPK        :1;                                       /* Reduced Drive of Port K */
  } Bits;
  struct {
    byte grpRDPx :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000D);
#define RDRIV _RDRIV.Byte
#define RDRIV_RDPA _RDRIV.Bits.RDPA
#define RDRIV_RDPB _RDRIV.Bits.RDPB
#define RDRIV_RDPE _RDRIV.Bits.RDPE
#define RDRIV_RDPK _RDRIV.Bits.RDPK
#define RDRIV_RDPx _RDRIV.MergedBits.grpRDPx

#define RDRIV_RDPA_MASK  1
#define RDRIV_RDPB_MASK  2
#define RDRIV_RDPE_MASK  16
#define RDRIV_RDPK_MASK  128
#define RDRIV_RDPx_MASK  3
#define RDRIV_RDPx_BITNUM  0


/*** EBICTL - External Bus Interface Control; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte ESTR        :1;                                       /* E Stretches */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} EBICTLSTR;
extern volatile EBICTLSTR _EBICTL @(REG_BASE + 0x0000000E);
#define EBICTL _EBICTL.Byte
#define EBICTL_ESTR _EBICTL.Bits.ESTR

#define EBICTL_ESTR_MASK  1


/*** RM - Initialization of Internal RAM Position Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte RAMHAL      :1;                                       /* Internal RAM map alignment */
    byte             :1; 
    byte             :1; 
    byte RAM11       :1;                                       /* Internal RAM map position Bit 11 */
    byte RAM12       :1;                                       /* Internal RAM map position Bit 12 */
    byte RAM13       :1;                                       /* Internal RAM map position Bit 13 */
    byte RAM14       :1;                                       /* Internal RAM map position Bit 14 */
    byte RAM15       :1;                                       /* Internal RAM map position Bit 15 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRAM_11 :5;
  } MergedBits;
} INITRMSTR;
extern volatile INITRMSTR _INITRM @(REG_BASE + 0x00000010);
#define INITRM _INITRM.Byte
#define INITRM_RAMHAL _INITRM.Bits.RAMHAL
#define INITRM_RAM11 _INITRM.Bits.RAM11
#define INITRM_RAM12 _INITRM.Bits.RAM12
#define INITRM_RAM13 _INITRM.Bits.RAM13
#define INITRM_RAM14 _INITRM.Bits.RAM14
#define INITRM_RAM15 _INITRM.Bits.RAM15
#define INITRM_RAM_11 _INITRM.MergedBits.grpRAM_11
#define INITRM_RAM INITRM_RAM_11

#define INITRM_RAMHAL_MASK  1
#define INITRM_RAM11_MASK  8
#define INITRM_RAM12_MASK  16
#define INITRM_RAM13_MASK  32
#define INITRM_RAM14_MASK  64
#define INITRM_RAM15_MASK  128
#define INITRM_RAM_11_MASK  248
#define INITRM_RAM_11_BITNUM  3


/*** INITRG - Initialization of Internal Register Position Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte REG11       :1;                                       /* Internal register map position REG11 */
    byte REG12       :1;                                       /* Internal register map position REG12 */
    byte REG13       :1;                                       /* Internal register map position REG13 */
    byte REG14       :1;                                       /* Internal register map position REG14 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpREG_11 :4;
    byte         :1;
  } MergedBits;
} INITRGSTR;
extern volatile INITRGSTR _INITRG @(REG_BASE + 0x00000011);
#define INITRG _INITRG.Byte
#define INITRG_REG11 _INITRG.Bits.REG11
#define INITRG_REG12 _INITRG.Bits.REG12
#define INITRG_REG13 _INITRG.Bits.REG13
#define INITRG_REG14 _INITRG.Bits.REG14
#define INITRG_REG_11 _INITRG.MergedBits.grpREG_11
#define INITRG_REG INITRG_REG_11

#define INITRG_REG11_MASK  8
#define INITRG_REG12_MASK  16
#define INITRG_REG13_MASK  32
#define INITRG_REG14_MASK  64
#define INITRG_REG_11_MASK  120
#define INITRG_REG_11_BITNUM  3


/*** MISC - Miscellaneous Mapping Control Register; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte ROMON       :1;                                       /* Enable Flash EEPROM */
    byte ROMHM       :1;                                       /* Flash EEPROM only in second half of memory map */
    byte EXSTR0      :1;                                       /* External Access Stretch Bit 0 */
    byte EXSTR1      :1;                                       /* External Access Stretch Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpEXSTR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MISCSTR;
extern volatile MISCSTR _MISC @(REG_BASE + 0x00000013);
#define MISC _MISC.Byte
#define MISC_ROMON _MISC.Bits.ROMON
#define MISC_ROMHM _MISC.Bits.ROMHM
#define MISC_EXSTR0 _MISC.Bits.EXSTR0
#define MISC_EXSTR1 _MISC.Bits.EXSTR1
#define MISC_EXSTR _MISC.MergedBits.grpEXSTR

#define MISC_ROMON_MASK  1
#define MISC_ROMHM_MASK  2
#define MISC_EXSTR0_MASK  4
#define MISC_EXSTR1_MASK  8
#define MISC_EXSTR_MASK  12
#define MISC_EXSTR_BITNUM  2


/*** MTST0 - MTST0; 0x00000014 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* MTST0 Bit 0 */
    byte BIT1        :1;                                       /* MTST0 Bit 1 */
    byte BIT2        :1;                                       /* MTST0 Bit 2 */
    byte BIT3        :1;                                       /* MTST0 Bit 3 */
    byte BIT4        :1;                                       /* MTST0 Bit 4 */
    byte BIT5        :1;                                       /* MTST0 Bit 5 */
    byte BIT6        :1;                                       /* MTST0 Bit 6 */
    byte BIT7        :1;                                       /* MTST0 Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} MTST0STR;
extern volatile MTST0STR _MTST0 @(REG_BASE + 0x00000014);
#define MTST0 _MTST0.Byte
#define MTST0_BIT0 _MTST0.Bits.BIT0
#define MTST0_BIT1 _MTST0.Bits.BIT1
#define MTST0_BIT2 _MTST0.Bits.BIT2
#define MTST0_BIT3 _MTST0.Bits.BIT3
#define MTST0_BIT4 _MTST0.Bits.BIT4
#define MTST0_BIT5 _MTST0.Bits.BIT5
#define MTST0_BIT6 _MTST0.Bits.BIT6
#define MTST0_BIT7 _MTST0.Bits.BIT7
#define MTST0_BIT _MTST0.MergedBits.grpBIT

#define MTST0_BIT0_MASK  1
#define MTST0_BIT1_MASK  2
#define MTST0_BIT2_MASK  4
#define MTST0_BIT3_MASK  8
#define MTST0_BIT4_MASK  16
#define MTST0_BIT5_MASK  32
#define MTST0_BIT6_MASK  64
#define MTST0_BIT7_MASK  128
#define MTST0_BIT_MASK  255
#define MTST0_BIT_BITNUM  0


/*** ITCR - Interrupt Test Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte ADR0        :1;                                       /* Test register select Bit 0 */
    byte ADR1        :1;                                       /* Test register select Bit 1 */
    byte ADR2        :1;                                       /* Test register select Bit 2 */
    byte ADR3        :1;                                       /* Test register select Bit 3 */
    byte WRTINT      :1;                                       /* Write to the Interrupt Test Registers */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADR  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ITCRSTR;
extern volatile ITCRSTR _ITCR @(REG_BASE + 0x00000015);
#define ITCR _ITCR.Byte
#define ITCR_ADR0 _ITCR.Bits.ADR0
#define ITCR_ADR1 _ITCR.Bits.ADR1
#define ITCR_ADR2 _ITCR.Bits.ADR2
#define ITCR_ADR3 _ITCR.Bits.ADR3
#define ITCR_WRTINT _ITCR.Bits.WRTINT
#define ITCR_ADR _ITCR.MergedBits.grpADR

#define ITCR_ADR0_MASK  1
#define ITCR_ADR1_MASK  2
#define ITCR_ADR2_MASK  4
#define ITCR_ADR3_MASK  8
#define ITCR_WRTINT_MASK  16
#define ITCR_ADR_MASK  15
#define ITCR_ADR_BITNUM  0


/*** ITEST - Interrupt Test Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte INT0        :1;                                       /* Interrupt Test Register Bit 0 */
    byte INT2        :1;                                       /* Interrupt Test Register Bit 1 */
    byte INT4        :1;                                       /* Interrupt Test Register Bit 2 */
    byte INT6        :1;                                       /* Interrupt Test Register Bit 3 */
    byte INT8        :1;                                       /* Interrupt Test Register Bit 4 */
    byte INTA        :1;                                       /* Interrupt Test Register Bit 5 */
    byte INTC        :1;                                       /* Interrupt Test Register Bit 6 */
    byte INTE        :1;                                       /* Interrupt Test Register Bit 7 */
  } Bits;
} ITESTSTR;
extern volatile ITESTSTR _ITEST @(REG_BASE + 0x00000016);
#define ITEST _ITEST.Byte
#define ITEST_INT0 _ITEST.Bits.INT0
#define ITEST_INT2 _ITEST.Bits.INT2
#define ITEST_INT4 _ITEST.Bits.INT4
#define ITEST_INT6 _ITEST.Bits.INT6
#define ITEST_INT8 _ITEST.Bits.INT8
#define ITEST_INTA _ITEST.Bits.INTA
#define ITEST_INTC _ITEST.Bits.INTC
#define ITEST_INTE _ITEST.Bits.INTE

#define ITEST_INT0_MASK  1
#define ITEST_INT2_MASK  2
#define ITEST_INT4_MASK  4
#define ITEST_INT6_MASK  8
#define ITEST_INT8_MASK  16
#define ITEST_INTA_MASK  32
#define ITEST_INTC_MASK  64
#define ITEST_INTE_MASK  128


/*** MTST1 - MTST1; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* MTST1 Bit 0 */
    byte BIT1        :1;                                       /* MTST1 Bit 1 */
    byte BIT2        :1;                                       /* MTST1 Bit 2 */
    byte BIT3        :1;                                       /* MTST1 Bit 3 */
    byte BIT4        :1;                                       /* MTST1 Bit 4 */
    byte BIT5        :1;                                       /* MTST1 Bit 5 */
    byte BIT6        :1;                                       /* MTST1 Bit 6 */
    byte BIT7        :1;                                       /* MTST1 Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} MTST1STR;
extern volatile MTST1STR _MTST1 @(REG_BASE + 0x00000017);
#define MTST1 _MTST1.Byte
#define MTST1_BIT0 _MTST1.Bits.BIT0
#define MTST1_BIT1 _MTST1.Bits.BIT1
#define MTST1_BIT2 _MTST1.Bits.BIT2
#define MTST1_BIT3 _MTST1.Bits.BIT3
#define MTST1_BIT4 _MTST1.Bits.BIT4
#define MTST1_BIT5 _MTST1.Bits.BIT5
#define MTST1_BIT6 _MTST1.Bits.BIT6
#define MTST1_BIT7 _MTST1.Bits.BIT7
#define MTST1_BIT _MTST1.MergedBits.grpBIT

#define MTST1_BIT0_MASK  1
#define MTST1_BIT1_MASK  2
#define MTST1_BIT2_MASK  4
#define MTST1_BIT3_MASK  8
#define MTST1_BIT4_MASK  16
#define MTST1_BIT5_MASK  32
#define MTST1_BIT6_MASK  64
#define MTST1_BIT7_MASK  128
#define MTST1_BIT_MASK  255
#define MTST1_BIT_BITNUM  0


/*** PARTIDH - Part ID Register High; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte ID8         :1;                                       /* Part ID Register Bit 8 */
    byte ID9         :1;                                       /* Part ID Register Bit 9 */
    byte ID10        :1;                                       /* Part ID Register Bit 10 */
    byte ID11        :1;                                       /* Part ID Register Bit 11 */
    byte ID12        :1;                                       /* Part ID Register Bit 12 */
    byte ID13        :1;                                       /* Part ID Register Bit 13 */
    byte ID14        :1;                                       /* Part ID Register Bit 14 */
    byte ID15        :1;                                       /* Part ID Register Bit 15 */
  } Bits;
  struct {
    byte grpID_8 :8;
  } MergedBits;
} PARTIDHSTR;
extern volatile PARTIDHSTR _PARTIDH @(REG_BASE + 0x0000001A);
#define PARTIDH _PARTIDH.Byte
#define PARTIDH_ID8 _PARTIDH.Bits.ID8
#define PARTIDH_ID9 _PARTIDH.Bits.ID9
#define PARTIDH_ID10 _PARTIDH.Bits.ID10
#define PARTIDH_ID11 _PARTIDH.Bits.ID11
#define PARTIDH_ID12 _PARTIDH.Bits.ID12
#define PARTIDH_ID13 _PARTIDH.Bits.ID13
#define PARTIDH_ID14 _PARTIDH.Bits.ID14
#define PARTIDH_ID15 _PARTIDH.Bits.ID15
#define PARTIDH_ID_8 _PARTIDH.MergedBits.grpID_8
#define PARTIDH_ID PARTIDH_ID_8

#define PARTIDH_ID8_MASK  1
#define PARTIDH_ID9_MASK  2
#define PARTIDH_ID10_MASK  4
#define PARTIDH_ID11_MASK  8
#define PARTIDH_ID12_MASK  16
#define PARTIDH_ID13_MASK  32
#define PARTIDH_ID14_MASK  64
#define PARTIDH_ID15_MASK  128
#define PARTIDH_ID_8_MASK  255
#define PARTIDH_ID_8_BITNUM  0


/*** PARTIDL - Part ID Register Lw; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Part ID Register Bit 0 */
    byte ID1         :1;                                       /* Part ID Register Bit 1 */
    byte ID2         :1;                                       /* Part ID Register Bit 2 */
    byte ID3         :1;                                       /* Part ID Register Bit 3 */
    byte ID4         :1;                                       /* Part ID Register Bit 4 */
    byte ID5         :1;                                       /* Part ID Register Bit 5 */
    byte ID6         :1;                                       /* Part ID Register Bit 6 */
    byte ID7         :1;                                       /* Part ID Register Bit 7 */
  } Bits;
  struct {
    byte grpID   :8;
  } MergedBits;
} PARTIDLSTR;
extern volatile PARTIDLSTR _PARTIDL @(REG_BASE + 0x0000001B);
#define PARTIDL _PARTIDL.Byte
#define PARTIDL_ID0 _PARTIDL.Bits.ID0
#define PARTIDL_ID1 _PARTIDL.Bits.ID1
#define PARTIDL_ID2 _PARTIDL.Bits.ID2
#define PARTIDL_ID3 _PARTIDL.Bits.ID3
#define PARTIDL_ID4 _PARTIDL.Bits.ID4
#define PARTIDL_ID5 _PARTIDL.Bits.ID5
#define PARTIDL_ID6 _PARTIDL.Bits.ID6
#define PARTIDL_ID7 _PARTIDL.Bits.ID7
#define PARTIDL_ID _PARTIDL.MergedBits.grpID

#define PARTIDL_ID0_MASK  1
#define PARTIDL_ID1_MASK  2
#define PARTIDL_ID2_MASK  4
#define PARTIDL_ID3_MASK  8
#define PARTIDL_ID4_MASK  16
#define PARTIDL_ID5_MASK  32
#define PARTIDL_ID6_MASK  64
#define PARTIDL_ID7_MASK  128
#define PARTIDL_ID_MASK  255
#define PARTIDL_ID_BITNUM  0


/*** MEMSIZ0 - Memory Size Register Zero; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte ram_sw0     :1;                                       /* Allocated RAM Memory Space Bit 0 */
    byte ram_sw1     :1;                                       /* Allocated RAM Memory Space Bit 1 */
    byte ram_sw2     :1;                                       /* Allocated RAM Memory Space Bit 2 */
    byte             :1; 
    byte eep_sw0     :1;                                       /* Allocated EEPROM Memory Space Bit 0 */
    byte eep_sw1     :1;                                       /* Allocated EEPROM Memory Space Bit 1 */
    byte             :1; 
    byte reg_sw0     :1;                                       /* Allocated System Register Space */
  } Bits;
  struct {
    byte grpram_sw :3;
    byte         :1;
    byte grpeep_sw :2;
    byte         :1;
    byte grpreg_sw :1;
  } MergedBits;
} MEMSIZ0STR;
extern volatile MEMSIZ0STR _MEMSIZ0 @(REG_BASE + 0x0000001C);
#define MEMSIZ0 _MEMSIZ0.Byte
#define MEMSIZ0_ram_sw0 _MEMSIZ0.Bits.ram_sw0
#define MEMSIZ0_ram_sw1 _MEMSIZ0.Bits.ram_sw1
#define MEMSIZ0_ram_sw2 _MEMSIZ0.Bits.ram_sw2
#define MEMSIZ0_eep_sw0 _MEMSIZ0.Bits.eep_sw0
#define MEMSIZ0_eep_sw1 _MEMSIZ0.Bits.eep_sw1
#define MEMSIZ0_reg_sw0 _MEMSIZ0.Bits.reg_sw0
#define MEMSIZ0_ram_sw _MEMSIZ0.MergedBits.grpram_sw
#define MEMSIZ0_eep_sw _MEMSIZ0.MergedBits.grpeep_sw

#define MEMSIZ0_ram_sw0_MASK  1
#define MEMSIZ0_ram_sw1_MASK  2
#define MEMSIZ0_ram_sw2_MASK  4
#define MEMSIZ0_eep_sw0_MASK  16
#define MEMSIZ0_eep_sw1_MASK  32
#define MEMSIZ0_reg_sw0_MASK  128
#define MEMSIZ0_ram_sw_MASK  7
#define MEMSIZ0_ram_sw_BITNUM  0
#define MEMSIZ0_eep_sw_MASK  48
#define MEMSIZ0_eep_sw_BITNUM  4


/*** MEMSIZ1 - Memory Size Register One; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte pag_sw0     :1;                                       /* Allocated Off-Chip Memory Options Bit 0 */
    byte pag_sw1     :1;                                       /* Allocated Off-Chip Memory Options Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte rom_sw0     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 0 */
    byte rom_sw1     :1;                                       /* Allocated Flash EEPROM/ROM Physical Memory Space Bit 1 */
  } Bits;
  struct {
    byte grppag_sw :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grprom_sw :2;
  } MergedBits;
} MEMSIZ1STR;
extern volatile MEMSIZ1STR _MEMSIZ1 @(REG_BASE + 0x0000001D);
#define MEMSIZ1 _MEMSIZ1.Byte
#define MEMSIZ1_pag_sw0 _MEMSIZ1.Bits.pag_sw0
#define MEMSIZ1_pag_sw1 _MEMSIZ1.Bits.pag_sw1
#define MEMSIZ1_rom_sw0 _MEMSIZ1.Bits.rom_sw0
#define MEMSIZ1_rom_sw1 _MEMSIZ1.Bits.rom_sw1
#define MEMSIZ1_pag_sw _MEMSIZ1.MergedBits.grppag_sw
#define MEMSIZ1_rom_sw _MEMSIZ1.MergedBits.grprom_sw

#define MEMSIZ1_pag_sw0_MASK  1
#define MEMSIZ1_pag_sw1_MASK  2
#define MEMSIZ1_rom_sw0_MASK  64
#define MEMSIZ1_rom_sw1_MASK  128
#define MEMSIZ1_pag_sw_MASK  3
#define MEMSIZ1_pag_sw_BITNUM  0
#define MEMSIZ1_rom_sw_MASK  192
#define MEMSIZ1_rom_sw_BITNUM  6


/*** INTCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} INTCRSTR;
extern volatile INTCRSTR _INTCR @(REG_BASE + 0x0000001E);
#define INTCR _INTCR.Byte
#define INTCR_IRQEN _INTCR.Bits.IRQEN
#define INTCR_IRQE _INTCR.Bits.IRQE

#define INTCR_IRQEN_MASK  64
#define INTCR_IRQE_MASK  128


/*** HPRIO - Highest Priority I Interrupt; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PSEL1       :1;                                       /* Highest Priority I Interrupt Bit 1 */
    byte PSEL2       :1;                                       /* Highest Priority I Interrupt Bit 2 */
    byte PSEL3       :1;                                       /* Highest Priority I Interrupt Bit 3 */
    byte PSEL4       :1;                                       /* Highest Priority I Interrupt Bit 4 */
    byte PSEL5       :1;                                       /* Highest Priority I Interrupt Bit 5 */
    byte PSEL6       :1;                                       /* Highest Priority I Interrupt Bit 6 */
    byte PSEL7       :1;                                       /* Highest Priority I Interrupt Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpPSEL_1 :7;
  } MergedBits;
} HPRIOSTR;
extern volatile HPRIOSTR _HPRIO @(REG_BASE + 0x0000001F);
#define HPRIO _HPRIO.Byte
#define HPRIO_PSEL1 _HPRIO.Bits.PSEL1
#define HPRIO_PSEL2 _HPRIO.Bits.PSEL2
#define HPRIO_PSEL3 _HPRIO.Bits.PSEL3
#define HPRIO_PSEL4 _HPRIO.Bits.PSEL4
#define HPRIO_PSEL5 _HPRIO.Bits.PSEL5
#define HPRIO_PSEL6 _HPRIO.Bits.PSEL6
#define HPRIO_PSEL7 _HPRIO.Bits.PSEL7
#define HPRIO_PSEL_1 _HPRIO.MergedBits.grpPSEL_1
#define HPRIO_PSEL HPRIO_PSEL_1

#define HPRIO_PSEL1_MASK  2
#define HPRIO_PSEL2_MASK  4
#define HPRIO_PSEL3_MASK  8
#define HPRIO_PSEL4_MASK  16
#define HPRIO_PSEL5_MASK  32
#define HPRIO_PSEL6_MASK  64
#define HPRIO_PSEL7_MASK  128
#define HPRIO_PSEL_1_MASK  254
#define HPRIO_PSEL_1_BITNUM  1


/*** DBGC1 - Debug Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte CAPMOD0     :1;                                       /* Capture Mode Field, bit 0 */
    byte CAPMOD1     :1;                                       /* Capture Mode Field, bit 1 */
    byte             :1; 
    byte DBGBRK      :1;                                       /* DBG Breakpoint Enable Bit */
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Mode Enable Bit */
  } Bits;
  struct {
    byte grpCAPMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020);
#define DBGC1 _DBGC1.Byte
#define DBGC1_CAPMOD0 _DBGC1.Bits.CAPMOD0
#define DBGC1_CAPMOD1 _DBGC1.Bits.CAPMOD1
#define DBGC1_DBGBRK _DBGC1.Bits.DBGBRK
#define DBGC1_BEGIN _DBGC1.Bits.BEGIN
#define DBGC1_TRGSEL _DBGC1.Bits.TRGSEL
#define DBGC1_ARM _DBGC1.Bits.ARM
#define DBGC1_DBGEN _DBGC1.Bits.DBGEN
#define DBGC1_CAPMOD _DBGC1.MergedBits.grpCAPMOD

#define DBGC1_CAPMOD0_MASK  1
#define DBGC1_CAPMOD1_MASK  2
#define DBGC1_DBGBRK_MASK  8
#define DBGC1_BEGIN_MASK  16
#define DBGC1_TRGSEL_MASK  32
#define DBGC1_ARM_MASK  64
#define DBGC1_DBGEN_MASK  128
#define DBGC1_CAPMOD_MASK  3
#define DBGC1_CAPMOD_BITNUM  0


/*** DBGSC - Debug Status and Control Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bits, bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bits, bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bits, bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bits, bit 3 */
    byte             :1; 
    byte CF          :1;                                       /* Comparator C Match Flag */
    byte BF          :1;                                       /* Trigger B Match Flag */
    byte AF          :1;                                       /* Trigger A Match Flag */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSCSTR;
extern volatile DBGSCSTR _DBGSC @(REG_BASE + 0x00000021);
#define DBGSC _DBGSC.Byte
#define DBGSC_TRG0 _DBGSC.Bits.TRG0
#define DBGSC_TRG1 _DBGSC.Bits.TRG1
#define DBGSC_TRG2 _DBGSC.Bits.TRG2
#define DBGSC_TRG3 _DBGSC.Bits.TRG3
#define DBGSC_CF _DBGSC.Bits.CF
#define DBGSC_BF _DBGSC.Bits.BF
#define DBGSC_AF _DBGSC.Bits.AF
#define DBGSC_TRG _DBGSC.MergedBits.grpTRG

#define DBGSC_TRG0_MASK  1
#define DBGSC_TRG1_MASK  2
#define DBGSC_TRG2_MASK  4
#define DBGSC_TRG3_MASK  8
#define DBGSC_CF_MASK  32
#define DBGSC_BF_MASK  64
#define DBGSC_AF_MASK  128
#define DBGSC_TRG_MASK  15
#define DBGSC_TRG_BITNUM  0


/*** DBGTB - Debug Trace Buffer Register; 0x00000022 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGTBH - Debug Trace Buffer Register High; 0x00000022 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
        byte BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
        byte BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
        byte BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
        byte BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
        byte BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
        byte BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
        byte BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } DBGTBHSTR;
    #define DBGTBH _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    #define DBGTBH_BIT_8 _DBGTB.Overlap_STR.DBGTBHSTR.MergedBits.grpBIT_8
    #define DBGTBH_BIT DBGTBH_BIT_8
    
    #define DBGTBH_BIT8_MASK  1
    #define DBGTBH_BIT9_MASK  2
    #define DBGTBH_BIT10_MASK  4
    #define DBGTBH_BIT11_MASK  8
    #define DBGTBH_BIT12_MASK  16
    #define DBGTBH_BIT13_MASK  32
    #define DBGTBH_BIT14_MASK  64
    #define DBGTBH_BIT15_MASK  128
    #define DBGTBH_BIT_8_MASK  255
    #define DBGTBH_BIT_8_BITNUM  0


    /*** DBGTBL - Debug Trace Buffer Register Low; 0x00000023 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Trace Buffer Data Bit 0 */
        byte BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
        byte BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
        byte BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
        byte BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
        byte BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
        byte BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
        byte BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DBGTBLSTR;
    #define DBGTBL _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    #define DBGTBL_BIT _DBGTB.Overlap_STR.DBGTBLSTR.MergedBits.grpBIT
    
    #define DBGTBL_BIT0_MASK  1
    #define DBGTBL_BIT1_MASK  2
    #define DBGTBL_BIT2_MASK  4
    #define DBGTBL_BIT3_MASK  8
    #define DBGTBL_BIT4_MASK  16
    #define DBGTBL_BIT5_MASK  32
    #define DBGTBL_BIT6_MASK  64
    #define DBGTBL_BIT7_MASK  128
    #define DBGTBL_BIT_MASK  255
    #define DBGTBL_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bit 0 */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000022);
#define DBGTB _DBGTB.Word
#define DBGTB_BIT0 _DBGTB.Bits.BIT0
#define DBGTB_BIT1 _DBGTB.Bits.BIT1
#define DBGTB_BIT2 _DBGTB.Bits.BIT2
#define DBGTB_BIT3 _DBGTB.Bits.BIT3
#define DBGTB_BIT4 _DBGTB.Bits.BIT4
#define DBGTB_BIT5 _DBGTB.Bits.BIT5
#define DBGTB_BIT6 _DBGTB.Bits.BIT6
#define DBGTB_BIT7 _DBGTB.Bits.BIT7
#define DBGTB_BIT8 _DBGTB.Bits.BIT8
#define DBGTB_BIT9 _DBGTB.Bits.BIT9
#define DBGTB_BIT10 _DBGTB.Bits.BIT10
#define DBGTB_BIT11 _DBGTB.Bits.BIT11
#define DBGTB_BIT12 _DBGTB.Bits.BIT12
#define DBGTB_BIT13 _DBGTB.Bits.BIT13
#define DBGTB_BIT14 _DBGTB.Bits.BIT14
#define DBGTB_BIT15 _DBGTB.Bits.BIT15
#define DBGTB_BIT _DBGTB.MergedBits.grpBIT

#define DBGTB_BIT0_MASK  1
#define DBGTB_BIT1_MASK  2
#define DBGTB_BIT2_MASK  4
#define DBGTB_BIT3_MASK  8
#define DBGTB_BIT4_MASK  16
#define DBGTB_BIT5_MASK  32
#define DBGTB_BIT6_MASK  64
#define DBGTB_BIT7_MASK  128
#define DBGTB_BIT8_MASK  256
#define DBGTB_BIT9_MASK  512
#define DBGTB_BIT10_MASK  1024
#define DBGTB_BIT11_MASK  2048
#define DBGTB_BIT12_MASK  4096
#define DBGTB_BIT13_MASK  8192
#define DBGTB_BIT14_MASK  16384
#define DBGTB_BIT15_MASK  32768
#define DBGTB_BIT_MASK  65535
#define DBGTB_BIT_BITNUM  0


/*** DBGCNT - Debug Count Register; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* Count Value, bit 0 */
    byte CNT1        :1;                                       /* Count Value, bit 1 */
    byte CNT2        :1;                                       /* Count Value, bit 2 */
    byte CNT3        :1;                                       /* Count Value, bit 3 */
    byte CNT4        :1;                                       /* Count Value, bit 4 */
    byte CNT5        :1;                                       /* Count Value, bit 5 */
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpCNT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000024);
#define DBGCNT _DBGCNT.Byte
#define DBGCNT_CNT0 _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1 _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2 _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3 _DBGCNT.Bits.CNT3
#define DBGCNT_CNT4 _DBGCNT.Bits.CNT4
#define DBGCNT_CNT5 _DBGCNT.Bits.CNT5
#define DBGCNT_TBF _DBGCNT.Bits.TBF
#define DBGCNT_CNT _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK  1
#define DBGCNT_CNT1_MASK  2
#define DBGCNT_CNT2_MASK  4
#define DBGCNT_CNT3_MASK  8
#define DBGCNT_CNT4_MASK  16
#define DBGCNT_CNT5_MASK  32
#define DBGCNT_TBF_MASK  128
#define DBGCNT_CNT_MASK  63
#define DBGCNT_CNT_BITNUM  0


/*** DBGCCX - Debug Comparator C Extended Register; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCMP0     :1;                                       /* Comparator C Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator C Extended Compare Bits, bit 1 */
    byte EXTCMP2     :1;                                       /* Comparator C Extended Compare Bits, bit 2 */
    byte EXTCMP3     :1;                                       /* Comparator C Extended Compare Bits, bit 3 */
    byte EXTCMP4     :1;                                       /* Comparator C Extended Compare Bits, bit 4 */
    byte EXTCMP5     :1;                                       /* Comparator C Extended Compare Bits, bit 5 */
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
  } Bits;
  struct {
    byte grpEXTCMP :6;
    byte grpPAGSEL :2;
  } MergedBits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @(REG_BASE + 0x00000025);
#define DBGCCX _DBGCCX.Byte
#define DBGCCX_EXTCMP0 _DBGCCX.Bits.EXTCMP0
#define DBGCCX_EXTCMP1 _DBGCCX.Bits.EXTCMP1
#define DBGCCX_EXTCMP2 _DBGCCX.Bits.EXTCMP2
#define DBGCCX_EXTCMP3 _DBGCCX.Bits.EXTCMP3
#define DBGCCX_EXTCMP4 _DBGCCX.Bits.EXTCMP4
#define DBGCCX_EXTCMP5 _DBGCCX.Bits.EXTCMP5
#define DBGCCX_PAGSEL0 _DBGCCX.Bits.PAGSEL0
#define DBGCCX_PAGSEL1 _DBGCCX.Bits.PAGSEL1
#define DBGCCX_EXTCMP _DBGCCX.MergedBits.grpEXTCMP
#define DBGCCX_PAGSEL _DBGCCX.MergedBits.grpPAGSEL

#define DBGCCX_EXTCMP0_MASK  1
#define DBGCCX_EXTCMP1_MASK  2
#define DBGCCX_EXTCMP2_MASK  4
#define DBGCCX_EXTCMP3_MASK  8
#define DBGCCX_EXTCMP4_MASK  16
#define DBGCCX_EXTCMP5_MASK  32
#define DBGCCX_PAGSEL0_MASK  64
#define DBGCCX_PAGSEL1_MASK  128
#define DBGCCX_EXTCMP_MASK  63
#define DBGCCX_EXTCMP_BITNUM  0
#define DBGCCX_PAGSEL_MASK  192
#define DBGCCX_PAGSEL_BITNUM  6


/*** DBGCC - Debug Comparator C Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C Register High; 0x00000026 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator C Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator C Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator C Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator C Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator C Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator C Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator C Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator C Compare Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } DBGCCHSTR;
    #define DBGCCH _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_BIT8 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT8
    #define DBGCCH_BIT9 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT9
    #define DBGCCH_BIT10 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT10
    #define DBGCCH_BIT11 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT11
    #define DBGCCH_BIT12 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT12
    #define DBGCCH_BIT13 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT13
    #define DBGCCH_BIT14 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT14
    #define DBGCCH_BIT15 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.BIT15
    
    #define DBGCCH_BIT_8 _DBGCC.Overlap_STR.DBGCCHSTR.MergedBits.grpBIT_8
    #define DBGCCH_BIT DBGCCH_BIT_8
    
    #define DBGCCH_BIT8_MASK  1
    #define DBGCCH_BIT9_MASK  2
    #define DBGCCH_BIT10_MASK  4
    #define DBGCCH_BIT11_MASK  8
    #define DBGCCH_BIT12_MASK  16
    #define DBGCCH_BIT13_MASK  32
    #define DBGCCH_BIT14_MASK  64
    #define DBGCCH_BIT15_MASK  128
    #define DBGCCH_BIT_8_MASK  255
    #define DBGCCH_BIT_8_BITNUM  0


    /*** DBGCCL - Debug Comparator C Register Low; 0x00000027 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator C Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator C Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator C Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator C Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator C Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator C Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator C Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator C Compare Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DBGCCLSTR;
    #define DBGCCL _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_BIT0 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT0
    #define DBGCCL_BIT1 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT1
    #define DBGCCL_BIT2 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT2
    #define DBGCCL_BIT3 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT3
    #define DBGCCL_BIT4 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT4
    #define DBGCCL_BIT5 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT5
    #define DBGCCL_BIT6 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT6
    #define DBGCCL_BIT7 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.BIT7
    
    #define DBGCCL_BIT _DBGCC.Overlap_STR.DBGCCLSTR.MergedBits.grpBIT
    
    #define DBGCCL_BIT0_MASK  1
    #define DBGCCL_BIT1_MASK  2
    #define DBGCCL_BIT2_MASK  4
    #define DBGCCL_BIT3_MASK  8
    #define DBGCCL_BIT4_MASK  16
    #define DBGCCL_BIT5_MASK  32
    #define DBGCCL_BIT6_MASK  64
    #define DBGCCL_BIT7_MASK  128
    #define DBGCCL_BIT_MASK  255
    #define DBGCCL_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator C Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator C Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator C Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator C Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator C Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator C Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator C Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator C Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator C Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator C Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator C Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator C Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator C Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator C Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator C Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator C Compare Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @(REG_BASE + 0x00000026);
#define DBGCC _DBGCC.Word
#define DBGCC_BIT0 _DBGCC.Bits.BIT0
#define DBGCC_BIT1 _DBGCC.Bits.BIT1
#define DBGCC_BIT2 _DBGCC.Bits.BIT2
#define DBGCC_BIT3 _DBGCC.Bits.BIT3
#define DBGCC_BIT4 _DBGCC.Bits.BIT4
#define DBGCC_BIT5 _DBGCC.Bits.BIT5
#define DBGCC_BIT6 _DBGCC.Bits.BIT6
#define DBGCC_BIT7 _DBGCC.Bits.BIT7
#define DBGCC_BIT8 _DBGCC.Bits.BIT8
#define DBGCC_BIT9 _DBGCC.Bits.BIT9
#define DBGCC_BIT10 _DBGCC.Bits.BIT10
#define DBGCC_BIT11 _DBGCC.Bits.BIT11
#define DBGCC_BIT12 _DBGCC.Bits.BIT12
#define DBGCC_BIT13 _DBGCC.Bits.BIT13
#define DBGCC_BIT14 _DBGCC.Bits.BIT14
#define DBGCC_BIT15 _DBGCC.Bits.BIT15
#define DBGCC_BIT _DBGCC.MergedBits.grpBIT

#define DBGCC_BIT0_MASK  1
#define DBGCC_BIT1_MASK  2
#define DBGCC_BIT2_MASK  4
#define DBGCC_BIT3_MASK  8
#define DBGCC_BIT4_MASK  16
#define DBGCC_BIT5_MASK  32
#define DBGCC_BIT6_MASK  64
#define DBGCC_BIT7_MASK  128
#define DBGCC_BIT8_MASK  256
#define DBGCC_BIT9_MASK  512
#define DBGCC_BIT10_MASK  1024
#define DBGCC_BIT11_MASK  2048
#define DBGCC_BIT12_MASK  4096
#define DBGCC_BIT13_MASK  8192
#define DBGCC_BIT14_MASK  16384
#define DBGCC_BIT15_MASK  32768
#define DBGCC_BIT_MASK  65535
#define DBGCC_BIT_BITNUM  0


/*** DBGC2 - Debug Control Register 2; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
    byte TAGC        :1;                                       /* Comparator C Tag Select */
    byte BKCEN       :1;                                       /* Breakpoint Comparator C Enable Bit */
    byte TAGAB       :1;                                       /* Comparator A/B Tag Select */
    byte BDM         :1;                                       /* Background Debug Mode Enable */
    byte FULL        :1;                                       /* Full Breakpoint Mode Enable */
    byte BKABEN      :1;                                       /* Breakpoint Using Comparator A and B Enable */
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000028);
#define DBGC2 _DBGC2.Byte
#define DBGC2_RWC _DBGC2.Bits.RWC
#define DBGC2_RWCEN _DBGC2.Bits.RWCEN
#define DBGC2_TAGC _DBGC2.Bits.TAGC
#define DBGC2_BKCEN _DBGC2.Bits.BKCEN
#define DBGC2_TAGAB _DBGC2.Bits.TAGAB
#define DBGC2_BDM _DBGC2.Bits.BDM
#define DBGC2_FULL _DBGC2.Bits.FULL
#define DBGC2_BKABEN _DBGC2.Bits.BKABEN

#define DBGC2_RWC_MASK  1
#define DBGC2_RWCEN_MASK  2
#define DBGC2_TAGC_MASK  4
#define DBGC2_BKCEN_MASK  8
#define DBGC2_TAGAB_MASK  16
#define DBGC2_BDM_MASK  32
#define DBGC2_FULL_MASK  64
#define DBGC2_BKABEN_MASK  128


/*** DBGC3 - Debug Control Register 3; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
    byte BKBMBL      :1;                                       /* Breakpoint Mask Low Byte for Second Address */
    byte BKBMBH      :1;                                       /* Breakpoint Mask High Byte for Second Address */
    byte BKAMBL      :1;                                       /* Breakpoint Mask Low Byte for First Address */
    byte BKAMBH      :1;                                       /* Breakpoint Mask High Byte for First Address */
  } Bits;
} DBGC3STR;
extern volatile DBGC3STR _DBGC3 @(REG_BASE + 0x00000029);
#define DBGC3 _DBGC3.Byte
#define DBGC3_RWB _DBGC3.Bits.RWB
#define DBGC3_RWBEN _DBGC3.Bits.RWBEN
#define DBGC3_RWA _DBGC3.Bits.RWA
#define DBGC3_RWAEN _DBGC3.Bits.RWAEN
#define DBGC3_BKBMBL _DBGC3.Bits.BKBMBL
#define DBGC3_BKBMBH _DBGC3.Bits.BKBMBH
#define DBGC3_BKAMBL _DBGC3.Bits.BKAMBL
#define DBGC3_BKAMBH _DBGC3.Bits.BKAMBH

#define DBGC3_RWB_MASK  1
#define DBGC3_RWBEN_MASK  2
#define DBGC3_RWA_MASK  4
#define DBGC3_RWAEN_MASK  8
#define DBGC3_BKBMBL_MASK  16
#define DBGC3_BKBMBH_MASK  32
#define DBGC3_BKAMBL_MASK  64
#define DBGC3_BKAMBH_MASK  128


/*** DBGCAX - Debug Comparator A Extended Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
    byte PAGSEL2     :1;                                       /* Page Selector Field, bit 2 */
    byte PAGSEL3     :1;                                       /* Page Selector Field, bit 3 */
    byte PAGSEL4     :1;                                       /* Page Selector Field, bit 4 */
    byte PAGSEL5     :1;                                       /* Page Selector Field, bit 5 */
    byte EXTCMP0     :1;                                       /* Comparator A Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator A Extended Compare Bits, bit 1 */
  } Bits;
  struct {
    byte grpPAGSEL :6;
    byte grpEXTCMP :2;
  } MergedBits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @(REG_BASE + 0x0000002A);
#define DBGCAX _DBGCAX.Byte
#define DBGCAX_PAGSEL0 _DBGCAX.Bits.PAGSEL0
#define DBGCAX_PAGSEL1 _DBGCAX.Bits.PAGSEL1
#define DBGCAX_PAGSEL2 _DBGCAX.Bits.PAGSEL2
#define DBGCAX_PAGSEL3 _DBGCAX.Bits.PAGSEL3
#define DBGCAX_PAGSEL4 _DBGCAX.Bits.PAGSEL4
#define DBGCAX_PAGSEL5 _DBGCAX.Bits.PAGSEL5
#define DBGCAX_EXTCMP0 _DBGCAX.Bits.EXTCMP0
#define DBGCAX_EXTCMP1 _DBGCAX.Bits.EXTCMP1
#define DBGCAX_PAGSEL _DBGCAX.MergedBits.grpPAGSEL
#define DBGCAX_EXTCMP _DBGCAX.MergedBits.grpEXTCMP

#define DBGCAX_PAGSEL0_MASK  1
#define DBGCAX_PAGSEL1_MASK  2
#define DBGCAX_PAGSEL2_MASK  4
#define DBGCAX_PAGSEL3_MASK  8
#define DBGCAX_PAGSEL4_MASK  16
#define DBGCAX_PAGSEL5_MASK  32
#define DBGCAX_EXTCMP0_MASK  64
#define DBGCAX_EXTCMP1_MASK  128
#define DBGCAX_PAGSEL_MASK  63
#define DBGCAX_PAGSEL_BITNUM  0
#define DBGCAX_EXTCMP_MASK  192
#define DBGCAX_EXTCMP_BITNUM  6


/*** DBGCA - Debug Comparator A Register; 0x0000002B ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A Register High; 0x0000002B ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator A Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator A Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator A Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator A Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator A Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator A Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator A Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator A Compare Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } DBGCAHSTR;
    #define DBGCAH _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_BIT8 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT8
    #define DBGCAH_BIT9 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT9
    #define DBGCAH_BIT10 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT10
    #define DBGCAH_BIT11 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT11
    #define DBGCAH_BIT12 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT12
    #define DBGCAH_BIT13 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT13
    #define DBGCAH_BIT14 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT14
    #define DBGCAH_BIT15 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.BIT15
    
    #define DBGCAH_BIT_8 _DBGCA.Overlap_STR.DBGCAHSTR.MergedBits.grpBIT_8
    #define DBGCAH_BIT DBGCAH_BIT_8
    
    #define DBGCAH_BIT8_MASK  1
    #define DBGCAH_BIT9_MASK  2
    #define DBGCAH_BIT10_MASK  4
    #define DBGCAH_BIT11_MASK  8
    #define DBGCAH_BIT12_MASK  16
    #define DBGCAH_BIT13_MASK  32
    #define DBGCAH_BIT14_MASK  64
    #define DBGCAH_BIT15_MASK  128
    #define DBGCAH_BIT_8_MASK  255
    #define DBGCAH_BIT_8_BITNUM  0


    /*** DBGCAL - Debug Comparator A Register Low; 0x0000002C ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator A Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator A Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator A Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator A Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator A Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator A Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator A Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator A Compare Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DBGCALSTR;
    #define DBGCAL _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_BIT0 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT0
    #define DBGCAL_BIT1 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT1
    #define DBGCAL_BIT2 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT2
    #define DBGCAL_BIT3 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT3
    #define DBGCAL_BIT4 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT4
    #define DBGCAL_BIT5 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT5
    #define DBGCAL_BIT6 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT6
    #define DBGCAL_BIT7 _DBGCA.Overlap_STR.DBGCALSTR.Bits.BIT7
    
    #define DBGCAL_BIT _DBGCA.Overlap_STR.DBGCALSTR.MergedBits.grpBIT
    
    #define DBGCAL_BIT0_MASK  1
    #define DBGCAL_BIT1_MASK  2
    #define DBGCAL_BIT2_MASK  4
    #define DBGCAL_BIT3_MASK  8
    #define DBGCAL_BIT4_MASK  16
    #define DBGCAL_BIT5_MASK  32
    #define DBGCAL_BIT6_MASK  64
    #define DBGCAL_BIT7_MASK  128
    #define DBGCAL_BIT_MASK  255
    #define DBGCAL_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator A Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator A Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator A Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator A Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator A Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator A Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator A Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator A Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator A Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator A Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator A Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator A Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator A Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator A Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator A Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator A Compare Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DBGCASTR;
extern volatile DBGCASTR _DBGCA @(REG_BASE + 0x0000002B);
#define DBGCA _DBGCA.Word
#define DBGCA_BIT0 _DBGCA.Bits.BIT0
#define DBGCA_BIT1 _DBGCA.Bits.BIT1
#define DBGCA_BIT2 _DBGCA.Bits.BIT2
#define DBGCA_BIT3 _DBGCA.Bits.BIT3
#define DBGCA_BIT4 _DBGCA.Bits.BIT4
#define DBGCA_BIT5 _DBGCA.Bits.BIT5
#define DBGCA_BIT6 _DBGCA.Bits.BIT6
#define DBGCA_BIT7 _DBGCA.Bits.BIT7
#define DBGCA_BIT8 _DBGCA.Bits.BIT8
#define DBGCA_BIT9 _DBGCA.Bits.BIT9
#define DBGCA_BIT10 _DBGCA.Bits.BIT10
#define DBGCA_BIT11 _DBGCA.Bits.BIT11
#define DBGCA_BIT12 _DBGCA.Bits.BIT12
#define DBGCA_BIT13 _DBGCA.Bits.BIT13
#define DBGCA_BIT14 _DBGCA.Bits.BIT14
#define DBGCA_BIT15 _DBGCA.Bits.BIT15
#define DBGCA_BIT _DBGCA.MergedBits.grpBIT

#define DBGCA_BIT0_MASK  1
#define DBGCA_BIT1_MASK  2
#define DBGCA_BIT2_MASK  4
#define DBGCA_BIT3_MASK  8
#define DBGCA_BIT4_MASK  16
#define DBGCA_BIT5_MASK  32
#define DBGCA_BIT6_MASK  64
#define DBGCA_BIT7_MASK  128
#define DBGCA_BIT8_MASK  256
#define DBGCA_BIT9_MASK  512
#define DBGCA_BIT10_MASK  1024
#define DBGCA_BIT11_MASK  2048
#define DBGCA_BIT12_MASK  4096
#define DBGCA_BIT13_MASK  8192
#define DBGCA_BIT14_MASK  16384
#define DBGCA_BIT15_MASK  32768
#define DBGCA_BIT_MASK  65535
#define DBGCA_BIT_BITNUM  0


/*** DBGCBX - Debug Comparator B Extended Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCMP0     :1;                                       /* Comparator B Extended Compare Bits, bit 0 */
    byte EXTCMP1     :1;                                       /* Comparator B Extended Compare Bits, bit 1 */
    byte EXTCMP2     :1;                                       /* Comparator B Extended Compare Bits, bit 2 */
    byte EXTCMP3     :1;                                       /* Comparator B Extended Compare Bits, bit 3 */
    byte EXTCMP4     :1;                                       /* Comparator B Extended Compare Bits, bit 4 */
    byte EXTCMP5     :1;                                       /* Comparator B Extended Compare Bits, bit 5 */
    byte PAGSEL0     :1;                                       /* Page Selector Field, bit 0 */
    byte PAGSEL1     :1;                                       /* Page Selector Field, bit 1 */
  } Bits;
  struct {
    byte grpEXTCMP :6;
    byte grpPAGSEL :2;
  } MergedBits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @(REG_BASE + 0x0000002D);
#define DBGCBX _DBGCBX.Byte
#define DBGCBX_EXTCMP0 _DBGCBX.Bits.EXTCMP0
#define DBGCBX_EXTCMP1 _DBGCBX.Bits.EXTCMP1
#define DBGCBX_EXTCMP2 _DBGCBX.Bits.EXTCMP2
#define DBGCBX_EXTCMP3 _DBGCBX.Bits.EXTCMP3
#define DBGCBX_EXTCMP4 _DBGCBX.Bits.EXTCMP4
#define DBGCBX_EXTCMP5 _DBGCBX.Bits.EXTCMP5
#define DBGCBX_PAGSEL0 _DBGCBX.Bits.PAGSEL0
#define DBGCBX_PAGSEL1 _DBGCBX.Bits.PAGSEL1
#define DBGCBX_EXTCMP _DBGCBX.MergedBits.grpEXTCMP
#define DBGCBX_PAGSEL _DBGCBX.MergedBits.grpPAGSEL

#define DBGCBX_EXTCMP0_MASK  1
#define DBGCBX_EXTCMP1_MASK  2
#define DBGCBX_EXTCMP2_MASK  4
#define DBGCBX_EXTCMP3_MASK  8
#define DBGCBX_EXTCMP4_MASK  16
#define DBGCBX_EXTCMP5_MASK  32
#define DBGCBX_PAGSEL0_MASK  64
#define DBGCBX_PAGSEL1_MASK  128
#define DBGCBX_EXTCMP_MASK  63
#define DBGCBX_EXTCMP_BITNUM  0
#define DBGCBX_PAGSEL_MASK  192
#define DBGCBX_PAGSEL_BITNUM  6


/*** DBGCB - Debug Comparator B Register; 0x0000002E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B Register High; 0x0000002E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte BIT9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte BIT10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte BIT11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte BIT12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte BIT13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte BIT14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte BIT15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } DBGCBHSTR;
    #define DBGCBH _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_BIT8 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT8
    #define DBGCBH_BIT9 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT9
    #define DBGCBH_BIT10 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT10
    #define DBGCBH_BIT11 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT11
    #define DBGCBH_BIT12 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT12
    #define DBGCBH_BIT13 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT13
    #define DBGCBH_BIT14 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT14
    #define DBGCBH_BIT15 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.BIT15
    
    #define DBGCBH_BIT_8 _DBGCB.Overlap_STR.DBGCBHSTR.MergedBits.grpBIT_8
    #define DBGCBH_BIT DBGCBH_BIT_8
    
    #define DBGCBH_BIT8_MASK  1
    #define DBGCBH_BIT9_MASK  2
    #define DBGCBH_BIT10_MASK  4
    #define DBGCBH_BIT11_MASK  8
    #define DBGCBH_BIT12_MASK  16
    #define DBGCBH_BIT13_MASK  32
    #define DBGCBH_BIT14_MASK  64
    #define DBGCBH_BIT15_MASK  128
    #define DBGCBH_BIT_8_MASK  255
    #define DBGCBH_BIT_8_BITNUM  0


    /*** DBGCBL - Debug Comparator B Register Low; 0x0000002F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Comparator B High Compare Bit 0 */
        byte BIT1        :1;                                       /* Comparator B High Compare Bit 1 */
        byte BIT2        :1;                                       /* Comparator B High Compare Bit 2 */
        byte BIT3        :1;                                       /* Comparator B High Compare Bit 3 */
        byte BIT4        :1;                                       /* Comparator B High Compare Bit 4 */
        byte BIT5        :1;                                       /* Comparator B High Compare Bit 5 */
        byte BIT6        :1;                                       /* Comparator B High Compare Bit 6 */
        byte BIT7        :1;                                       /* Comparator B High Compare Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } DBGCBLSTR;
    #define DBGCBL _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_BIT0 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT0
    #define DBGCBL_BIT1 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT1
    #define DBGCBL_BIT2 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT2
    #define DBGCBL_BIT3 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT3
    #define DBGCBL_BIT4 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT4
    #define DBGCBL_BIT5 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT5
    #define DBGCBL_BIT6 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT6
    #define DBGCBL_BIT7 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.BIT7
    
    #define DBGCBL_BIT _DBGCB.Overlap_STR.DBGCBLSTR.MergedBits.grpBIT
    
    #define DBGCBL_BIT0_MASK  1
    #define DBGCBL_BIT1_MASK  2
    #define DBGCBL_BIT2_MASK  4
    #define DBGCBL_BIT3_MASK  8
    #define DBGCBL_BIT4_MASK  16
    #define DBGCBL_BIT5_MASK  32
    #define DBGCBL_BIT6_MASK  64
    #define DBGCBL_BIT7_MASK  128
    #define DBGCBL_BIT_MASK  255
    #define DBGCBL_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Comparator B High Compare Bit 0 */
    word BIT1        :1;                                       /* Comparator B High Compare Bit 1 */
    word BIT2        :1;                                       /* Comparator B High Compare Bit 2 */
    word BIT3        :1;                                       /* Comparator B High Compare Bit 3 */
    word BIT4        :1;                                       /* Comparator B High Compare Bit 4 */
    word BIT5        :1;                                       /* Comparator B High Compare Bit 5 */
    word BIT6        :1;                                       /* Comparator B High Compare Bit 6 */
    word BIT7        :1;                                       /* Comparator B High Compare Bit 7 */
    word BIT8        :1;                                       /* Comparator B High Compare Bit 8 */
    word BIT9        :1;                                       /* Comparator B High Compare Bit 9 */
    word BIT10       :1;                                       /* Comparator B High Compare Bit 10 */
    word BIT11       :1;                                       /* Comparator B High Compare Bit 11 */
    word BIT12       :1;                                       /* Comparator B High Compare Bit 12 */
    word BIT13       :1;                                       /* Comparator B High Compare Bit 13 */
    word BIT14       :1;                                       /* Comparator B High Compare Bit 14 */
    word BIT15       :1;                                       /* Comparator B High Compare Bit 15 */
  } Bits;
  struct {
    word grpBIT  :16;
  } MergedBits;
} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @(REG_BASE + 0x0000002E);
#define DBGCB _DBGCB.Word
#define DBGCB_BIT0 _DBGCB.Bits.BIT0
#define DBGCB_BIT1 _DBGCB.Bits.BIT1
#define DBGCB_BIT2 _DBGCB.Bits.BIT2
#define DBGCB_BIT3 _DBGCB.Bits.BIT3
#define DBGCB_BIT4 _DBGCB.Bits.BIT4
#define DBGCB_BIT5 _DBGCB.Bits.BIT5
#define DBGCB_BIT6 _DBGCB.Bits.BIT6
#define DBGCB_BIT7 _DBGCB.Bits.BIT7
#define DBGCB_BIT8 _DBGCB.Bits.BIT8
#define DBGCB_BIT9 _DBGCB.Bits.BIT9
#define DBGCB_BIT10 _DBGCB.Bits.BIT10
#define DBGCB_BIT11 _DBGCB.Bits.BIT11
#define DBGCB_BIT12 _DBGCB.Bits.BIT12
#define DBGCB_BIT13 _DBGCB.Bits.BIT13
#define DBGCB_BIT14 _DBGCB.Bits.BIT14
#define DBGCB_BIT15 _DBGCB.Bits.BIT15
#define DBGCB_BIT _DBGCB.MergedBits.grpBIT

#define DBGCB_BIT0_MASK  1
#define DBGCB_BIT1_MASK  2
#define DBGCB_BIT2_MASK  4
#define DBGCB_BIT3_MASK  8
#define DBGCB_BIT4_MASK  16
#define DBGCB_BIT5_MASK  32
#define DBGCB_BIT6_MASK  64
#define DBGCB_BIT7_MASK  128
#define DBGCB_BIT8_MASK  256
#define DBGCB_BIT9_MASK  512
#define DBGCB_BIT10_MASK  1024
#define DBGCB_BIT11_MASK  2048
#define DBGCB_BIT12_MASK  4096
#define DBGCB_BIT13_MASK  8192
#define DBGCB_BIT14_MASK  16384
#define DBGCB_BIT15_MASK  32768
#define DBGCB_BIT_MASK  65535
#define DBGCB_BIT_BITNUM  0


/*** PPAGE - Page Index Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Page Index Register Bit 0 */
    byte PIX1        :1;                                       /* Page Index Register Bit 1 */
    byte PIX2        :1;                                       /* Page Index Register Bit 2 */
    byte PIX3        :1;                                       /* Page Index Register Bit 3 */
    byte PIX4        :1;                                       /* Page Index Register Bit 4 */
    byte PIX5        :1;                                       /* Page Index Register Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIX  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000030);
#define PPAGE _PPAGE.Byte
#define PPAGE_PIX0 _PPAGE.Bits.PIX0
#define PPAGE_PIX1 _PPAGE.Bits.PIX1
#define PPAGE_PIX2 _PPAGE.Bits.PIX2
#define PPAGE_PIX3 _PPAGE.Bits.PIX3
#define PPAGE_PIX4 _PPAGE.Bits.PIX4
#define PPAGE_PIX5 _PPAGE.Bits.PIX5
#define PPAGE_PIX _PPAGE.MergedBits.grpPIX

#define PPAGE_PIX0_MASK  1
#define PPAGE_PIX1_MASK  2
#define PPAGE_PIX2_MASK  4
#define PPAGE_PIX3_MASK  8
#define PPAGE_PIX4_MASK  16
#define PPAGE_PIX5_MASK  32
#define PPAGE_PIX_MASK  63
#define PPAGE_PIX_BITNUM  0


/*** PORTK - Port K Data Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port K Bit 0 */
    byte BIT1        :1;                                       /* Port K Bit 1 */
    byte BIT2        :1;                                       /* Port K Bit 2 */
    byte BIT3        :1;                                       /* Port K Bit 3 */
    byte BIT4        :1;                                       /* Port K Bit 4 */
    byte BIT5        :1;                                       /* Port K Bit 5 */
    byte BIT6        :1;                                       /* Port K Bit 6 */
    byte BIT7        :1;                                       /* Port K Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} PORTKSTR;
extern volatile PORTKSTR _PORTK @(REG_BASE + 0x00000032);
#define PORTK _PORTK.Byte
#define PORTK_BIT0 _PORTK.Bits.BIT0
#define PORTK_BIT1 _PORTK.Bits.BIT1
#define PORTK_BIT2 _PORTK.Bits.BIT2
#define PORTK_BIT3 _PORTK.Bits.BIT3
#define PORTK_BIT4 _PORTK.Bits.BIT4
#define PORTK_BIT5 _PORTK.Bits.BIT5
#define PORTK_BIT6 _PORTK.Bits.BIT6
#define PORTK_BIT7 _PORTK.Bits.BIT7
#define PORTK_BIT _PORTK.MergedBits.grpBIT

#define PORTK_BIT0_MASK  1
#define PORTK_BIT1_MASK  2
#define PORTK_BIT2_MASK  4
#define PORTK_BIT3_MASK  8
#define PORTK_BIT4_MASK  16
#define PORTK_BIT5_MASK  32
#define PORTK_BIT6_MASK  64
#define PORTK_BIT7_MASK  128
#define PORTK_BIT_MASK  255
#define PORTK_BIT_BITNUM  0


/*** DDRK - Port K Data Direction Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Port K Data Direction Bit 0 */
    byte BIT1        :1;                                       /* Port K Data Direction Bit 1 */
    byte BIT2        :1;                                       /* Port K Data Direction Bit 2 */
    byte BIT3        :1;                                       /* Port K Data Direction Bit 3 */
    byte BIT4        :1;                                       /* Port K Data Direction Bit 4 */
    byte BIT5        :1;                                       /* Port K Data Direction Bit 5 */
    byte BIT6        :1;                                       /* Port K Data Direction Bit 6 */
    byte BIT7        :1;                                       /* Port K Data Direction Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} DDRKSTR;
extern volatile DDRKSTR _DDRK @(REG_BASE + 0x00000033);
#define DDRK _DDRK.Byte
#define DDRK_BIT0 _DDRK.Bits.BIT0
#define DDRK_BIT1 _DDRK.Bits.BIT1
#define DDRK_BIT2 _DDRK.Bits.BIT2
#define DDRK_BIT3 _DDRK.Bits.BIT3
#define DDRK_BIT4 _DDRK.Bits.BIT4
#define DDRK_BIT5 _DDRK.Bits.BIT5
#define DDRK_BIT6 _DDRK.Bits.BIT6
#define DDRK_BIT7 _DDRK.Bits.BIT7
#define DDRK_BIT _DDRK.MergedBits.grpBIT

#define DDRK_BIT0_MASK  1
#define DDRK_BIT1_MASK  2
#define DDRK_BIT2_MASK  4
#define DDRK_BIT3_MASK  8
#define DDRK_BIT4_MASK  16
#define DDRK_BIT5_MASK  32
#define DDRK_BIT6_MASK  64
#define DDRK_BIT7_MASK  128
#define DDRK_BIT_MASK  255
#define DDRK_BIT_BITNUM  0


/*** SYNR - CRG Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYN0        :1;                                       /* CRG Synthesizer Bit 0 */
    byte SYN1        :1;                                       /* CRG Synthesizer Bit 1 */
    byte SYN2        :1;                                       /* CRG Synthesizer Bit 2 */
    byte SYN3        :1;                                       /* CRG Synthesizer Bit 3 */
    byte SYN4        :1;                                       /* CRG Synthesizer Bit 4 */
    byte SYN5        :1;                                       /* CRG Synthesizer Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpSYN  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} SYNRSTR;
extern volatile SYNRSTR _SYNR @(REG_BASE + 0x00000034);
#define SYNR _SYNR.Byte
#define SYNR_SYN0 _SYNR.Bits.SYN0
#define SYNR_SYN1 _SYNR.Bits.SYN1
#define SYNR_SYN2 _SYNR.Bits.SYN2
#define SYNR_SYN3 _SYNR.Bits.SYN3
#define SYNR_SYN4 _SYNR.Bits.SYN4
#define SYNR_SYN5 _SYNR.Bits.SYN5
#define SYNR_SYN _SYNR.MergedBits.grpSYN

#define SYNR_SYN0_MASK  1
#define SYNR_SYN1_MASK  2
#define SYNR_SYN2_MASK  4
#define SYNR_SYN3_MASK  8
#define SYNR_SYN4_MASK  16
#define SYNR_SYN5_MASK  32
#define SYNR_SYN_MASK  63
#define SYNR_SYN_BITNUM  0


/*** REFDV - CRG Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDV0      :1;                                       /* CRG Reference Divider Bit 0 */
    byte REFDV1      :1;                                       /* CRG Reference Divider Bit 1 */
    byte REFDV2      :1;                                       /* CRG Reference Divider Bit 2 */
    byte REFDV3      :1;                                       /* CRG Reference Divider Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREFDV :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} REFDVSTR;
extern volatile REFDVSTR _REFDV @(REG_BASE + 0x00000035);
#define REFDV _REFDV.Byte
#define REFDV_REFDV0 _REFDV.Bits.REFDV0
#define REFDV_REFDV1 _REFDV.Bits.REFDV1
#define REFDV_REFDV2 _REFDV.Bits.REFDV2
#define REFDV_REFDV3 _REFDV.Bits.REFDV3
#define REFDV_REFDV _REFDV.MergedBits.grpREFDV

#define REFDV_REFDV0_MASK  1
#define REFDV_REFDV1_MASK  2
#define REFDV_REFDV2_MASK  4
#define REFDV_REFDV3_MASK  8
#define REFDV_REFDV_MASK  15
#define REFDV_REFDV_BITNUM  0


/*** CRGFLG - CRG Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte SCM         :1;                                       /* Self-clock mode Status */
    byte SCMIF       :1;                                       /* Self-clock mode Interrupt Flag */
    byte TRACK       :1;                                       /* Track Status */
    byte LOCK        :1;                                       /* Lck Status */
    byte LOCKIF      :1;                                       /* PLL Lck Interrupt Flag */
    byte             :1; 
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CRGFLGSTR;
extern volatile CRGFLGSTR _CRGFLG @(REG_BASE + 0x00000037);
#define CRGFLG _CRGFLG.Byte
#define CRGFLG_SCM _CRGFLG.Bits.SCM
#define CRGFLG_SCMIF _CRGFLG.Bits.SCMIF
#define CRGFLG_TRACK _CRGFLG.Bits.TRACK
#define CRGFLG_LOCK _CRGFLG.Bits.LOCK
#define CRGFLG_LOCKIF _CRGFLG.Bits.LOCKIF
#define CRGFLG_PORF _CRGFLG.Bits.PORF
#define CRGFLG_RTIF _CRGFLG.Bits.RTIF

#define CRGFLG_SCM_MASK  1
#define CRGFLG_SCMIF_MASK  2
#define CRGFLG_TRACK_MASK  4
#define CRGFLG_LOCK_MASK  8
#define CRGFLG_LOCKIF_MASK  16
#define CRGFLG_PORF_MASK  64
#define CRGFLG_RTIF_MASK  128


/*** CRGINT - CRG Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SCMIE       :1;                                       /* Self-clock mode Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lck Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable */
  } Bits;
} CRGINTSTR;
extern volatile CRGINTSTR _CRGINT @(REG_BASE + 0x00000038);
#define CRGINT _CRGINT.Byte
#define CRGINT_SCMIE _CRGINT.Bits.SCMIE
#define CRGINT_LOCKIE _CRGINT.Bits.LOCKIE
#define CRGINT_RTIE _CRGINT.Bits.RTIE

#define CRGINT_SCMIE_MASK  2
#define CRGINT_LOCKIE_MASK  16
#define CRGINT_RTIE_MASK  128


/*** CLKSEL - CRG Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPWAI      :1;                                       /* COP stops in WAIT mode */
    byte RTIWAI      :1;                                       /* RTI stops in WAIT mode */
    byte CWAI        :1;                                       /* CLK24 and CLK23 stop in WAIT mode */
    byte PLLWAI      :1;                                       /* PLL stops in WAIT mode */
    byte ROAWAI      :1;                                       /* Reduced Oscillator Amplitude in WAIT mode */
    byte SYSWAI      :1;                                       /* System clocks stop in WAIT mode */
    byte PSTP        :1;                                       /* Pseudo Stop */
    byte PLLSEL      :1;                                       /* PLL selected for system clock */
  } Bits;
} CLKSELSTR;
extern volatile CLKSELSTR _CLKSEL @(REG_BASE + 0x00000039);
#define CLKSEL _CLKSEL.Byte
#define CLKSEL_COPWAI _CLKSEL.Bits.COPWAI
#define CLKSEL_RTIWAI _CLKSEL.Bits.RTIWAI
#define CLKSEL_CWAI _CLKSEL.Bits.CWAI
#define CLKSEL_PLLWAI _CLKSEL.Bits.PLLWAI
#define CLKSEL_ROAWAI _CLKSEL.Bits.ROAWAI
#define CLKSEL_SYSWAI _CLKSEL.Bits.SYSWAI
#define CLKSEL_PSTP _CLKSEL.Bits.PSTP
#define CLKSEL_PLLSEL _CLKSEL.Bits.PLLSEL

#define CLKSEL_COPWAI_MASK  1
#define CLKSEL_RTIWAI_MASK  2
#define CLKSEL_CWAI_MASK  4
#define CLKSEL_PLLWAI_MASK  8
#define CLKSEL_ROAWAI_MASK  16
#define CLKSEL_SYSWAI_MASK  32
#define CLKSEL_PSTP_MASK  64
#define CLKSEL_PLLSEL_MASK  128


/*** PLLCTL - CRG PLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte SCME        :1;                                       /* Self-clock mode enable */
    byte PCE         :1;                                       /* COP Enable during Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable during Pseudo Stop Bit */
    byte             :1; 
    byte ACQ         :1;                                       /* Acquisition */
    byte AUTO        :1;                                       /* Automatic Bandwidth Control */
    byte PLLON       :1;                                       /* Phase Lck Loop On */
    byte CME         :1;                                       /* Crystal Monitor Enable */
  } Bits;
} PLLCTLSTR;
extern volatile PLLCTLSTR _PLLCTL @(REG_BASE + 0x0000003A);
#define PLLCTL _PLLCTL.Byte
#define PLLCTL_SCME _PLLCTL.Bits.SCME
#define PLLCTL_PCE _PLLCTL.Bits.PCE
#define PLLCTL_PRE _PLLCTL.Bits.PRE
#define PLLCTL_ACQ _PLLCTL.Bits.ACQ
#define PLLCTL_AUTO _PLLCTL.Bits.AUTO
#define PLLCTL_PLLON _PLLCTL.Bits.PLLON
#define PLLCTL_CME _PLLCTL.Bits.CME

#define PLLCTL_SCME_MASK  1
#define PLLCTL_PCE_MASK  2
#define PLLCTL_PRE_MASK  4
#define PLLCTL_ACQ_MASK  16
#define PLLCTL_AUTO_MASK  32
#define PLLCTL_PLLON_MASK  64
#define PLLCTL_CME_MASK  128


/*** RTICTL - CRG RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} RTICTLSTR;
extern volatile RTICTLSTR _RTICTL @(REG_BASE + 0x0000003B);
#define RTICTL _RTICTL.Byte
#define RTICTL_RTR0 _RTICTL.Bits.RTR0
#define RTICTL_RTR1 _RTICTL.Bits.RTR1
#define RTICTL_RTR2 _RTICTL.Bits.RTR2
#define RTICTL_RTR3 _RTICTL.Bits.RTR3
#define RTICTL_RTR4 _RTICTL.Bits.RTR4
#define RTICTL_RTR5 _RTICTL.Bits.RTR5
#define RTICTL_RTR6 _RTICTL.Bits.RTR6
#define RTICTL_RTR _RTICTL.MergedBits.grpRTR

#define RTICTL_RTR0_MASK  1
#define RTICTL_RTR1_MASK  2
#define RTICTL_RTR2_MASK  4
#define RTICTL_RTR3_MASK  8
#define RTICTL_RTR4_MASK  16
#define RTICTL_RTR5_MASK  32
#define RTICTL_RTR6_MASK  64
#define RTICTL_RTR_MASK  127
#define RTICTL_RTR_BITNUM  0


/*** COPCTL - CRG COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} COPCTLSTR;
extern volatile COPCTLSTR _COPCTL @(REG_BASE + 0x0000003C);
#define COPCTL _COPCTL.Byte
#define COPCTL_CR0 _COPCTL.Bits.CR0
#define COPCTL_CR1 _COPCTL.Bits.CR1
#define COPCTL_CR2 _COPCTL.Bits.CR2
#define COPCTL_RSBCK _COPCTL.Bits.RSBCK
#define COPCTL_WCOP _COPCTL.Bits.WCOP
#define COPCTL_CR _COPCTL.MergedBits.grpCR

#define COPCTL_CR0_MASK  1
#define COPCTL_CR1_MASK  2
#define COPCTL_CR2_MASK  4
#define COPCTL_RSBCK_MASK  64
#define COPCTL_WCOP_MASK  128
#define COPCTL_CR_MASK  7
#define COPCTL_CR_BITNUM  0


/*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRG COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CRG COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CRG COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CRG COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CRG COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CRG COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CRG COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CRG COP Timer Arm/Reset Bit 7 */
  } Bits;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} ARMCOPSTR;
extern volatile ARMCOPSTR _ARMCOP @(REG_BASE + 0x0000003F);
#define ARMCOP _ARMCOP.Byte
#define ARMCOP_BIT0 _ARMCOP.Bits.BIT0
#define ARMCOP_BIT1 _ARMCOP.Bits.BIT1
#define ARMCOP_BIT2 _ARMCOP.Bits.BIT2
#define ARMCOP_BIT3 _ARMCOP.Bits.BIT3
#define ARMCOP_BIT4 _ARMCOP.Bits.BIT4
#define ARMCOP_BIT5 _ARMCOP.Bits.BIT5
#define ARMCOP_BIT6 _ARMCOP.Bits.BIT6
#define ARMCOP_BIT7 _ARMCOP.Bits.BIT7
#define ARMCOP_BIT _ARMCOP.MergedBits.grpBIT

#define ARMCOP_BIT0_MASK  1
#define ARMCOP_BIT1_MASK  2
#define ARMCOP_BIT2_MASK  4
#define ARMCOP_BIT3_MASK  8
#define ARMCOP_BIT4_MASK  16
#define ARMCOP_BIT5_MASK  32
#define ARMCOP_BIT6_MASK  64
#define ARMCOP_BIT7_MASK  128
#define ARMCOP_BIT_MASK  255
#define ARMCOP_BIT_BITNUM  0


/*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte IOS6        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 6 */
    byte IOS7        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpIOS_4 :4;
  } MergedBits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(REG_BASE + 0x00000040);
#define TIOS _TIOS.Byte
#define TIOS_IOS4 _TIOS.Bits.IOS4
#define TIOS_IOS5 _TIOS.Bits.IOS5
#define TIOS_IOS6 _TIOS.Bits.IOS6
#define TIOS_IOS7 _TIOS.Bits.IOS7
#define TIOS_IOS_4 _TIOS.MergedBits.grpIOS_4
#define TIOS_IOS TIOS_IOS_4

#define TIOS_IOS4_MASK  16
#define TIOS_IOS5_MASK  32
#define TIOS_IOS6_MASK  64
#define TIOS_IOS7_MASK  128
#define TIOS_IOS_4_MASK  240
#define TIOS_IOS_4_BITNUM  4


/*** CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte FOC6        :1;                                       /* Force Output Compare Action for Channel 6 */
    byte FOC7        :1;                                       /* Force Output Compare Action for Channel 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFOC_4 :4;
  } MergedBits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(REG_BASE + 0x00000041);
#define CFORC _CFORC.Byte
#define CFORC_FOC4 _CFORC.Bits.FOC4
#define CFORC_FOC5 _CFORC.Bits.FOC5
#define CFORC_FOC6 _CFORC.Bits.FOC6
#define CFORC_FOC7 _CFORC.Bits.FOC7
#define CFORC_FOC_4 _CFORC.MergedBits.grpFOC_4
#define CFORC_FOC CFORC_FOC_4

#define CFORC_FOC4_MASK  16
#define CFORC_FOC5_MASK  32
#define CFORC_FOC6_MASK  64
#define CFORC_FOC7_MASK  128
#define CFORC_FOC_4_MASK  240
#define CFORC_FOC_4_BITNUM  4


/*** OC7M - Output Compare 7 Mask Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OC7M4       :1;                                       /* Output Compare 7 Mask Bit 4 */
    byte OC7M5       :1;                                       /* Output Compare 7 Mask Bit 5 */
    byte OC7M6       :1;                                       /* Output Compare 7 Mask Bit 6 */
    byte OC7M7       :1;                                       /* Output Compare 7 Mask Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpOC7M_4 :4;
  } MergedBits;
} OC7MSTR;
extern volatile OC7MSTR _OC7M @(REG_BASE + 0x00000042);
#define OC7M _OC7M.Byte
#define OC7M_OC7M4 _OC7M.Bits.OC7M4
#define OC7M_OC7M5 _OC7M.Bits.OC7M5
#define OC7M_OC7M6 _OC7M.Bits.OC7M6
#define OC7M_OC7M7 _OC7M.Bits.OC7M7
#define OC7M_OC7M_4 _OC7M.MergedBits.grpOC7M_4

#define OC7M_OC7M4_MASK  16
#define OC7M_OC7M5_MASK  32
#define OC7M_OC7M6_MASK  64
#define OC7M_OC7M7_MASK  128
#define OC7M_OC7M_4_MASK  240
#define OC7M_OC7M_4_BITNUM  4


/*** OC7D - Output Compare 7 Data Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OC7D4       :1;                                       /* Output Compare 7 Bit 4 */
    byte OC7D5       :1;                                       /* Output Compare 7 Bit 5 */
    byte OC7D6       :1;                                       /* Output Compare 7 Bit 6 */
    byte OC7D7       :1;                                       /* Output Compare 7 Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpOC7D_4 :4;
  } MergedBits;
} OC7DSTR;
extern volatile OC7DSTR _OC7D @(REG_BASE + 0x00000043);
#define OC7D _OC7D.Byte
#define OC7D_OC7D4 _OC7D.Bits.OC7D4
#define OC7D_OC7D5 _OC7D.Bits.OC7D5
#define OC7D_OC7D6 _OC7D.Bits.OC7D6
#define OC7D_OC7D7 _OC7D.Bits.OC7D7
#define OC7D_OC7D_4 _OC7D.MergedBits.grpOC7D_4

#define OC7D_OC7D4_MASK  16
#define OC7D_OC7D5_MASK  32
#define OC7D_OC7D6_MASK  64
#define OC7D_OC7D7_MASK  128
#define OC7D_OC7D_4_MASK  240
#define OC7D_OC7D_4_BITNUM  4


/*** TCNT - Timer Count Register; 0x00000044 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TCNTHi - Timer Count Register High; 0x00000044 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Count Register Bit 8 */
        byte BIT9        :1;                                       /* Timer Count Register Bit 9 */
        byte BIT10       :1;                                       /* Timer Count Register Bit 10 */
        byte BIT11       :1;                                       /* Timer Count Register Bit 11 */
        byte BIT12       :1;                                       /* Timer Count Register Bit 12 */
        byte BIT13       :1;                                       /* Timer Count Register Bit 13 */
        byte BIT14       :1;                                       /* Timer Count Register Bit 14 */
        byte BIT15       :1;                                       /* Timer Count Register Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } TCNTHiSTR;
    #define TCNTHi _TCNT.Overlap_STR.TCNTHiSTR.Byte
    #define TCNTHi_BIT8 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT8
    #define TCNTHi_BIT9 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT9
    #define TCNTHi_BIT10 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT10
    #define TCNTHi_BIT11 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT11
    #define TCNTHi_BIT12 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT12
    #define TCNTHi_BIT13 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT13
    #define TCNTHi_BIT14 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT14
    #define TCNTHi_BIT15 _TCNT.Overlap_STR.TCNTHiSTR.Bits.BIT15
    
    #define TCNTHi_BIT_8 _TCNT.Overlap_STR.TCNTHiSTR.MergedBits.grpBIT_8
    #define TCNTHi_BIT TCNTHi_BIT_8
    
    #define TCNTHi_BIT8_MASK  1
    #define TCNTHi_BIT9_MASK  2
    #define TCNTHi_BIT10_MASK  4
    #define TCNTHi_BIT11_MASK  8
    #define TCNTHi_BIT12_MASK  16
    #define TCNTHi_BIT13_MASK  32
    #define TCNTHi_BIT14_MASK  64
    #define TCNTHi_BIT15_MASK  128
    #define TCNTHi_BIT_8_MASK  255
    #define TCNTHi_BIT_8_BITNUM  0


    /*** TCNTL - Timer Count Register Lw; 0x00000045 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Count Register Bit 0 */
        byte BIT1        :1;                                       /* Timer Count Register Bit 1 */
        byte BIT2        :1;                                       /* Timer Count Register Bit 2 */
        byte BIT3        :1;                                       /* Timer Count Register Bit 3 */
        byte BIT4        :1;                                       /* Timer Count Bit Register 4 */
        byte BIT5        :1;                                       /* Timer Count Bit Register 5 */
        byte BIT6        :1;                                       /* Timer Count Bit Register 6 */
        byte BIT7        :1;                                       /* Timer Count Bit Register 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } TCNTLSTR;
    #define TCNTL _TCNT.Overlap_STR.TCNTLSTR.Byte
    #define TCNTL_BIT0 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT0
    #define TCNTL_BIT1 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT1
    #define TCNTL_BIT2 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT2
    #define TCNTL_BIT3 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT3
    #define TCNTL_BIT4 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT4
    #define TCNTL_BIT5 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT5
    #define TCNTL_BIT6 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT6
    #define TCNTL_BIT7 _TCNT.Overlap_STR.TCNTLSTR.Bits.BIT7
    
    #define TCNTL_BIT _TCNT.Overlap_STR.TCNTLSTR.MergedBits.grpBIT
    
    #define TCNTL_BIT0_MASK  1
    #define TCNTL_BIT1_MASK  2
    #define TCNTL_BIT2_MASK  4
    #define TCNTL_BIT3_MASK  8
    #define TCNTL_BIT4_MASK  16
    #define TCNTL_BIT5_MASK  32
    #define TCNTL_BIT6_MASK  64
    #define TCNTL_BIT7_MASK  128
    #define TCNTL_BIT_MASK  255
    #define TCNTL_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word grpBIT  :16;
  } MergedBits;
} TCNTSTR;
extern volatile TCNTSTR _TCNT @(REG_BASE + 0x00000044);
#define TCNT _TCNT.Word
#define TCNT_BIT _TCNT.MergedBits.grpBIT

#define TCNT_BIT_MASK  65535
#define TCNT_BIT_BITNUM  0


/*** TSCR1 - Timer System Control Register1; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(REG_BASE + 0x00000046);
#define TSCR1 _TSCR1.Byte
#define TSCR1_TFFCA _TSCR1.Bits.TFFCA
#define TSCR1_TSFRZ _TSCR1.Bits.TSFRZ
#define TSCR1_TSWAI _TSCR1.Bits.TSWAI
#define TSCR1_TEN _TSCR1.Bits.TEN

#define TSCR1_TFFCA_MASK  16
#define TSCR1_TSFRZ_MASK  32
#define TSCR1_TSWAI_MASK  64
#define TSCR1_TEN_MASK  128


/*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte TOV6        :1;                                       /* Toggle On Overflow Bit 6 */
    byte TOV7        :1;                                       /* Toggle On Overflow Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTOV_4 :4;
  } MergedBits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(REG_BASE + 0x00000047);
#define TTOV _TTOV.Byte
#define TTOV_TOV4 _TTOV.Bits.TOV4
#define TTOV_TOV5 _TTOV.Bits.TOV5
#define TTOV_TOV6 _TTOV.Bits.TOV6
#define TTOV_TOV7 _TTOV.Bits.TOV7
#define TTOV_TOV_4 _TTOV.MergedBits.grpTOV_4
#define TTOV_TOV TTOV_TOV_4

#define TTOV_TOV4_MASK  16
#define TTOV_TOV5_MASK  32
#define TTOV_TOV6_MASK  64
#define TTOV_TOV7_MASK  128
#define TTOV_TOV_4_MASK  240
#define TTOV_TOV_4_BITNUM  4


/*** TCTL1 - Timer Control Registers 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte OL6         :1;                                       /* Output Level Bit 6 */
    byte OM6         :1;                                       /* Output Mode Bit 6 */
    byte OL7         :1;                                       /* Output Level Bit 7 */
    byte OM7         :1;                                       /* Output Mode Bit 7 */
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(REG_BASE + 0x00000048);
#define TCTL1 _TCTL1.Byte
#define TCTL1_OL4 _TCTL1.Bits.OL4
#define TCTL1_OM4 _TCTL1.Bits.OM4
#define TCTL1_OL5 _TCTL1.Bits.OL5
#define TCTL1_OM5 _TCTL1.Bits.OM5
#define TCTL1_OL6 _TCTL1.Bits.OL6
#define TCTL1_OM6 _TCTL1.Bits.OM6
#define TCTL1_OL7 _TCTL1.Bits.OL7
#define TCTL1_OM7 _TCTL1.Bits.OM7

#define TCTL1_OL4_MASK  1
#define TCTL1_OM4_MASK  2
#define TCTL1_OL5_MASK  4
#define TCTL1_OM5_MASK  8
#define TCTL1_OL6_MASK  16
#define TCTL1_OM6_MASK  32
#define TCTL1_OL7_MASK  64
#define TCTL1_OM7_MASK  128


/*** TCTL3 - Timer Control Register 3; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte EDG6A       :1;                                       /* Input Capture Edge Control 6A */
    byte EDG6B       :1;                                       /* Input Capture Edge Control 6B */
    byte EDG7A       :1;                                       /* Input Capture Edge Control 7A */
    byte EDG7B       :1;                                       /* Input Capture Edge Control 7B */
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte         :1;
    byte         :1;
    byte grpEDG6x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TCTL3STR;
extern volatile TCTL3STR _TCTL3 @(REG_BASE + 0x0000004A);
#define TCTL3 _TCTL3.Byte
#define TCTL3_EDG4A _TCTL3.Bits.EDG4A
#define TCTL3_EDG4B _TCTL3.Bits.EDG4B
#define TCTL3_EDG5A _TCTL3.Bits.EDG5A
#define TCTL3_EDG5B _TCTL3.Bits.EDG5B
#define TCTL3_EDG6A _TCTL3.Bits.EDG6A
#define TCTL3_EDG6B _TCTL3.Bits.EDG6B
#define TCTL3_EDG7A _TCTL3.Bits.EDG7A
#define TCTL3_EDG7B _TCTL3.Bits.EDG7B
#define TCTL3_EDG4x _TCTL3.MergedBits.grpEDG4x
#define TCTL3_EDG6x _TCTL3.MergedBits.grpEDG6x

#define TCTL3_EDG4A_MASK  1
#define TCTL3_EDG4B_MASK  2
#define TCTL3_EDG5A_MASK  4
#define TCTL3_EDG5B_MASK  8
#define TCTL3_EDG6A_MASK  16
#define TCTL3_EDG6B_MASK  32
#define TCTL3_EDG7A_MASK  64
#define TCTL3_EDG7B_MASK  128
#define TCTL3_EDG4x_MASK  3
#define TCTL3_EDG4x_BITNUM  0
#define TCTL3_EDG6x_MASK  48
#define TCTL3_EDG6x_BITNUM  4


/*** TIE - Timer Interrupt Enable Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
    byte C6I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 6 */
    byte C7I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 7 */
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(REG_BASE + 0x0000004C);
#define TIE _TIE.Byte
#define TIE_C4I _TIE.Bits.C4I
#define TIE_C5I _TIE.Bits.C5I
#define TIE_C6I _TIE.Bits.C6I
#define TIE_C7I _TIE.Bits.C7I

#define TIE_C4I_MASK  16
#define TIE_C5I_MASK  32
#define TIE_C6I_MASK  64
#define TIE_C7I_MASK  128


/*** TSCR2 - Timer System Control Register 2; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(REG_BASE + 0x0000004D);
#define TSCR2 _TSCR2.Byte
#define TSCR2_PR0 _TSCR2.Bits.PR0
#define TSCR2_PR1 _TSCR2.Bits.PR1
#define TSCR2_PR2 _TSCR2.Bits.PR2
#define TSCR2_TCRE _TSCR2.Bits.TCRE
#define TSCR2_TOI _TSCR2.Bits.TOI
#define TSCR2_PR _TSCR2.MergedBits.grpPR

#define TSCR2_PR0_MASK  1
#define TSCR2_PR1_MASK  2
#define TSCR2_PR2_MASK  4
#define TSCR2_TCRE_MASK  8
#define TSCR2_TOI_MASK  128
#define TSCR2_PR_MASK  7
#define TSCR2_PR_BITNUM  0


/*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
    byte C6F         :1;                                       /* Input Capture/Output Compare Channel Flag 6 */
    byte C7F         :1;                                       /* Input Capture/Output Compare Channel Flag 7 */
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(REG_BASE + 0x0000004E);
#define TFLG1 _TFLG1.Byte
#define TFLG1_C4F _TFLG1.Bits.C4F
#define TFLG1_C5F _TFLG1.Bits.C5F
#define TFLG1_C6F _TFLG1.Bits.C6F
#define TFLG1_C7F _TFLG1.Bits.C7F

#define TFLG1_C4F_MASK  16
#define TFLG1_C5F_MASK  32
#define TFLG1_C6F_MASK  64
#define TFLG1_C7F_MASK  128


/*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(REG_BASE + 0x0000004F);
#define TFLG2 _TFLG2.Byte
#define TFLG2_TOF _TFLG2.Bits.TOF

#define TFLG2_TOF_MASK  128


/*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } TC4HiSTR;
    #define TC4Hi _TC4.Overlap_STR.TC4HiSTR.Byte
    #define TC4Hi_BIT8 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT8
    #define TC4Hi_BIT9 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT9
    #define TC4Hi_BIT10 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT10
    #define TC4Hi_BIT11 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT11
    #define TC4Hi_BIT12 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT12
    #define TC4Hi_BIT13 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT13
    #define TC4Hi_BIT14 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT14
    #define TC4Hi_BIT15 _TC4.Overlap_STR.TC4HiSTR.Bits.BIT15
    
    #define TC4Hi_BIT_8 _TC4.Overlap_STR.TC4HiSTR.MergedBits.grpBIT_8
    #define TC4Hi_BIT TC4Hi_BIT_8
    
    #define TC4Hi_BIT8_MASK  1
    #define TC4Hi_BIT9_MASK  2
    #define TC4Hi_BIT10_MASK  4
    #define TC4Hi_BIT11_MASK  8
    #define TC4Hi_BIT12_MASK  16
    #define TC4Hi_BIT13_MASK  32
    #define TC4Hi_BIT14_MASK  64
    #define TC4Hi_BIT15_MASK  128
    #define TC4Hi_BIT_8_MASK  255
    #define TC4Hi_BIT_8_BITNUM  0


    /*** TC4L - Timer Input Capture/Output Compare Register 4 Lw; 0x00000059 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 4 Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } TC4LSTR;
    #define TC4L _TC4.Overlap_STR.TC4LSTR.Byte
    #define TC4L_BIT0 _TC4.Overlap_STR.TC4LSTR.Bits.BIT0
    #define TC4L_BIT1 _TC4.Overlap_STR.TC4LSTR.Bits.BIT1
    #define TC4L_BIT2 _TC4.Overlap_STR.TC4LSTR.Bits.BIT2
    #define TC4L_BIT3 _TC4.Overlap_STR.TC4LSTR.Bits.BIT3
    #define TC4L_BIT4 _TC4.Overlap_STR.TC4LSTR.Bits.BIT4
    #define TC4L_BIT5 _TC4.Overlap_STR.TC4LSTR.Bits.BIT5
    #define TC4L_BIT6 _TC4.Overlap_STR.TC4LSTR.Bits.BIT6
    #define TC4L_BIT7 _TC4.Overlap_STR.TC4LSTR.Bits.BIT7
    
    #define TC4L_BIT _TC4.Overlap_STR.TC4LSTR.MergedBits.grpBIT
    
    #define TC4L_BIT0_MASK  1
    #define TC4L_BIT1_MASK  2
    #define TC4L_BIT2_MASK  4
    #define TC4L_BIT3_MASK  8
    #define TC4L_BIT4_MASK  16
    #define TC4L_BIT5_MASK  32
    #define TC4L_BIT6_MASK  64
    #define TC4L_BIT7_MASK  128
    #define TC4L_BIT_MASK  255
    #define TC4L_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word grpBIT  :16;
  } MergedBits;
} TC4STR;
extern volatile TC4STR _TC4 @(REG_BASE + 0x00000058);
#define TC4 _TC4.Word
#define TC4_BIT _TC4.MergedBits.grpBIT

#define TC4_BIT_MASK  65535
#define TC4_BIT_BITNUM  0


/*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } TC5HiSTR;
    #define TC5Hi _TC5.Overlap_STR.TC5HiSTR.Byte
    #define TC5Hi_BIT8 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT8
    #define TC5Hi_BIT9 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT9
    #define TC5Hi_BIT10 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT10
    #define TC5Hi_BIT11 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT11
    #define TC5Hi_BIT12 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT12
    #define TC5Hi_BIT13 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT13
    #define TC5Hi_BIT14 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT14
    #define TC5Hi_BIT15 _TC5.Overlap_STR.TC5HiSTR.Bits.BIT15
    
    #define TC5Hi_BIT_8 _TC5.Overlap_STR.TC5HiSTR.MergedBits.grpBIT_8
    #define TC5Hi_BIT TC5Hi_BIT_8
    
    #define TC5Hi_BIT8_MASK  1
    #define TC5Hi_BIT9_MASK  2
    #define TC5Hi_BIT10_MASK  4
    #define TC5Hi_BIT11_MASK  8
    #define TC5Hi_BIT12_MASK  16
    #define TC5Hi_BIT13_MASK  32
    #define TC5Hi_BIT14_MASK  64
    #define TC5Hi_BIT15_MASK  128
    #define TC5Hi_BIT_8_MASK  255
    #define TC5Hi_BIT_8_BITNUM  0


    /*** TC5L - Timer Input Capture/Output Compare Register 5 Lw; 0x0000005B ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 5 Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } TC5LSTR;
    #define TC5L _TC5.Overlap_STR.TC5LSTR.Byte
    #define TC5L_BIT0 _TC5.Overlap_STR.TC5LSTR.Bits.BIT0
    #define TC5L_BIT1 _TC5.Overlap_STR.TC5LSTR.Bits.BIT1
    #define TC5L_BIT2 _TC5.Overlap_STR.TC5LSTR.Bits.BIT2
    #define TC5L_BIT3 _TC5.Overlap_STR.TC5LSTR.Bits.BIT3
    #define TC5L_BIT4 _TC5.Overlap_STR.TC5LSTR.Bits.BIT4
    #define TC5L_BIT5 _TC5.Overlap_STR.TC5LSTR.Bits.BIT5
    #define TC5L_BIT6 _TC5.Overlap_STR.TC5LSTR.Bits.BIT6
    #define TC5L_BIT7 _TC5.Overlap_STR.TC5LSTR.Bits.BIT7
    
    #define TC5L_BIT _TC5.Overlap_STR.TC5LSTR.MergedBits.grpBIT
    
    #define TC5L_BIT0_MASK  1
    #define TC5L_BIT1_MASK  2
    #define TC5L_BIT2_MASK  4
    #define TC5L_BIT3_MASK  8
    #define TC5L_BIT4_MASK  16
    #define TC5L_BIT5_MASK  32
    #define TC5L_BIT6_MASK  64
    #define TC5L_BIT7_MASK  128
    #define TC5L_BIT_MASK  255
    #define TC5L_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word grpBIT  :16;
  } MergedBits;
} TC5STR;
extern volatile TC5STR _TC5 @(REG_BASE + 0x0000005A);
#define TC5 _TC5.Word
#define TC5_BIT _TC5.MergedBits.grpBIT

#define TC5_BIT_MASK  65535
#define TC5_BIT_BITNUM  0


/*** TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } TC6HiSTR;
    #define TC6Hi _TC6.Overlap_STR.TC6HiSTR.Byte
    #define TC6Hi_BIT8 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT8
    #define TC6Hi_BIT9 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT9
    #define TC6Hi_BIT10 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT10
    #define TC6Hi_BIT11 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT11
    #define TC6Hi_BIT12 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT12
    #define TC6Hi_BIT13 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT13
    #define TC6Hi_BIT14 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT14
    #define TC6Hi_BIT15 _TC6.Overlap_STR.TC6HiSTR.Bits.BIT15
    
    #define TC6Hi_BIT_8 _TC6.Overlap_STR.TC6HiSTR.MergedBits.grpBIT_8
    #define TC6Hi_BIT TC6Hi_BIT_8
    
    #define TC6Hi_BIT8_MASK  1
    #define TC6Hi_BIT9_MASK  2
    #define TC6Hi_BIT10_MASK  4
    #define TC6Hi_BIT11_MASK  8
    #define TC6Hi_BIT12_MASK  16
    #define TC6Hi_BIT13_MASK  32
    #define TC6Hi_BIT14_MASK  64
    #define TC6Hi_BIT15_MASK  128
    #define TC6Hi_BIT_8_MASK  255
    #define TC6Hi_BIT_8_BITNUM  0


    /*** TC6L - Timer Input Capture/Output Compare Register 6 Lw; 0x0000005D ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 6 Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } TC6LSTR;
    #define TC6L _TC6.Overlap_STR.TC6LSTR.Byte
    #define TC6L_BIT0 _TC6.Overlap_STR.TC6LSTR.Bits.BIT0
    #define TC6L_BIT1 _TC6.Overlap_STR.TC6LSTR.Bits.BIT1
    #define TC6L_BIT2 _TC6.Overlap_STR.TC6LSTR.Bits.BIT2
    #define TC6L_BIT3 _TC6.Overlap_STR.TC6LSTR.Bits.BIT3
    #define TC6L_BIT4 _TC6.Overlap_STR.TC6LSTR.Bits.BIT4
    #define TC6L_BIT5 _TC6.Overlap_STR.TC6LSTR.Bits.BIT5
    #define TC6L_BIT6 _TC6.Overlap_STR.TC6LSTR.Bits.BIT6
    #define TC6L_BIT7 _TC6.Overlap_STR.TC6LSTR.Bits.BIT7
    
    #define TC6L_BIT _TC6.Overlap_STR.TC6LSTR.MergedBits.grpBIT
    
    #define TC6L_BIT0_MASK  1
    #define TC6L_BIT1_MASK  2
    #define TC6L_BIT2_MASK  4
    #define TC6L_BIT3_MASK  8
    #define TC6L_BIT4_MASK  16
    #define TC6L_BIT5_MASK  32
    #define TC6L_BIT6_MASK  64
    #define TC6L_BIT7_MASK  128
    #define TC6L_BIT_MASK  255
    #define TC6L_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word grpBIT  :16;
  } MergedBits;
} TC6STR;
extern volatile TC6STR _TC6 @(REG_BASE + 0x0000005C);
#define TC6 _TC6.Word
#define TC6_BIT _TC6.MergedBits.grpBIT

#define TC6_BIT_MASK  65535
#define TC6_BIT_BITNUM  0


/*** TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 8 */
        byte BIT9        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 9 */
        byte BIT10       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 10 */
        byte BIT11       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 11 */
        byte BIT12       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 12 */
        byte BIT13       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 13 */
        byte BIT14       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 14 */
        byte BIT15       :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } TC7HiSTR;
    #define TC7Hi _TC7.Overlap_STR.TC7HiSTR.Byte
    #define TC7Hi_BIT8 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT8
    #define TC7Hi_BIT9 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT9
    #define TC7Hi_BIT10 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT10
    #define TC7Hi_BIT11 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT11
    #define TC7Hi_BIT12 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT12
    #define TC7Hi_BIT13 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT13
    #define TC7Hi_BIT14 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT14
    #define TC7Hi_BIT15 _TC7.Overlap_STR.TC7HiSTR.Bits.BIT15
    
    #define TC7Hi_BIT_8 _TC7.Overlap_STR.TC7HiSTR.MergedBits.grpBIT_8
    #define TC7Hi_BIT TC7Hi_BIT_8
    
    #define TC7Hi_BIT8_MASK  1
    #define TC7Hi_BIT9_MASK  2
    #define TC7Hi_BIT10_MASK  4
    #define TC7Hi_BIT11_MASK  8
    #define TC7Hi_BIT12_MASK  16
    #define TC7Hi_BIT13_MASK  32
    #define TC7Hi_BIT14_MASK  64
    #define TC7Hi_BIT15_MASK  128
    #define TC7Hi_BIT_8_MASK  255
    #define TC7Hi_BIT_8_BITNUM  0


    /*** TC7L - Timer Input Capture/Output Compare Register 7 Lw; 0x0000005F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 0 */
        byte BIT1        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 1 */
        byte BIT2        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 2 */
        byte BIT3        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 3 */
        byte BIT4        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 4 */
        byte BIT5        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 5 */
        byte BIT6        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 6 */
        byte BIT7        :1;                                       /* Timer Input Capture/Output Compare Register 7 Bit 7 */
      } Bits;
      struct {
        byte grpBIT :8;
      } MergedBits;
    } TC7LSTR;
    #define TC7L _TC7.Overlap_STR.TC7LSTR.Byte
    #define TC7L_BIT0 _TC7.Overlap_STR.TC7LSTR.Bits.BIT0
    #define TC7L_BIT1 _TC7.Overlap_STR.TC7LSTR.Bits.BIT1
    #define TC7L_BIT2 _TC7.Overlap_STR.TC7LSTR.Bits.BIT2
    #define TC7L_BIT3 _TC7.Overlap_STR.TC7LSTR.Bits.BIT3
    #define TC7L_BIT4 _TC7.Overlap_STR.TC7LSTR.Bits.BIT4
    #define TC7L_BIT5 _TC7.Overlap_STR.TC7LSTR.Bits.BIT5
    #define TC7L_BIT6 _TC7.Overlap_STR.TC7LSTR.Bits.BIT6
    #define TC7L_BIT7 _TC7.Overlap_STR.TC7LSTR.Bits.BIT7
    
    #define TC7L_BIT _TC7.Overlap_STR.TC7LSTR.MergedBits.grpBIT
    
    #define TC7L_BIT0_MASK  1
    #define TC7L_BIT1_MASK  2
    #define TC7L_BIT2_MASK  4
    #define TC7L_BIT3_MASK  8
    #define TC7L_BIT4_MASK  16
    #define TC7L_BIT5_MASK  32
    #define TC7L_BIT6_MASK  64
    #define TC7L_BIT7_MASK  128
    #define TC7L_BIT_MASK  255
    #define TC7L_BIT_BITNUM  0

  } Overlap_STR;

  struct {
    word grpBIT  :16;
  } MergedBits;
} TC7STR;
extern volatile TC7STR _TC7 @(REG_BASE + 0x0000005E);
#define TC7 _TC7.Word
#define TC7_BIT _TC7.MergedBits.grpBIT

#define TC7_BIT_MASK  65535
#define TC7_BIT_BITNUM  0


/*** PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte PAI         :1;                                       /* Pulse Accumulator Input Interrupt enable */
    byte PAOVI       :1;                                       /* Pulse Accumulator A Overflow Interrupt enable */
    byte CLK0        :1;                                       /* Clock Select Bit 0 */
    byte CLK1        :1;                                       /* Clock Select Bit 1 */
    byte PEDGE       :1;                                       /* Pulse Accumulator Edge Control */
    byte PAMOD       :1;                                       /* Pulse Accumulator Mode */
    byte PAEN        :1;                                       /* Pulse Accumulator A System Enable */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PACTLSTR;
extern volatile PACTLSTR _PACTL @(REG_BASE + 0x00000060);
#define PACTL _PACTL.Byte
#define PACTL_PAI _PACTL.Bits.PAI
#define PACTL_PAOVI _PACTL.Bits.PAOVI
#define PACTL_CLK0 _PACTL.Bits.CLK0
#define PACTL_CLK1 _PACTL.Bits.CLK1
#define PACTL_PEDGE _PACTL.Bits.PEDGE
#define PACTL_PAMOD _PACTL.Bits.PAMOD
#define PACTL_PAEN _PACTL.Bits.PAEN
#define PACTL_CLK _PACTL.MergedBits.grpCLK

#define PACTL_PAI_MASK  1
#define PACTL_PAOVI_MASK  2
#define PACTL_CLK0_MASK  4
#define PACTL_CLK1_MASK  8
#define PACTL_PEDGE_MASK  16
#define PACTL_PAMOD_MASK  32
#define PACTL_PAEN_MASK  64
#define PACTL_CLK_MASK  12
#define PACTL_CLK_BITNUM  2


/*** PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte PAIF        :1;                                       /* Pulse Accumulator Input edge Flag */
    byte PAOVF       :1;                                       /* Pulse Accumulator A Overflow Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PAFLGSTR;
extern volatile PAFLGSTR _PAFLG @(REG_BASE + 0x00000061);
#define PAFLG _PAFLG.Byte
#define PAFLG_PAIF _PAFLG.Bits.PAIF
#define PAFLG_PAOVF _PAFLG.Bits.PAOVF

#define PAFLG_PAIF_MASK  1
#define PAFLG_PAOVF_MASK  2


/*** PACNT - TIM Pulse Accumulators Count Register; 0x00000062 ***/
typedef union {
  word Word;
  struct {
    word grpBIT  :16;
  } MergedBits;
} PACNTSTR;
extern volatile PACNTSTR _PACNT @(REG_BASE + 0x00000062);
#define PACNT _PACNT.Word
#define PACNT_BIT _PACNT.MergedBits.grpBIT

#define PACNT_BIT_MASK  65535
#define PACNT_BIT_BITNUM  0


/*** ATDCTL23 - ATD Control Register 23; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL2 - ATD Control Register 2; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte ASCIF       :1;                                       /* ATD Sequence Complete Interrupt Flag */
        byte ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte AWAI        :1;                                       /* ATD Wait Mode */
        byte AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
        byte ADPU        :1;                                       /* ATD Disable / Power Down */
      } Bits;
    } ATDCTL2STR;
    #define ATDCTL2 _ATDCTL23.Overlap_STR.ATDCTL2STR.Byte
    #define ATDCTL2_ASCIF _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIF
    #define ATDCTL2_ASCIE _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIE
    #define ATDCTL2_ETRIGE _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGE
    #define ATDCTL2_ETRIGP _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGP
    #define ATDCTL2_ETRIGLE _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGLE
    #define ATDCTL2_AWAI _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AWAI
    #define ATDCTL2_AFFC _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AFFC
    #define ATDCTL2_ADPU _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ADPU
    
    
    #define ATDCTL2_ASCIF_MASK  1
    #define ATDCTL2_ASCIE_MASK  2
    #define ATDCTL2_ETRIGE_MASK  4
    #define ATDCTL2_ETRIGP_MASK  8
    #define ATDCTL2_ETRIGLE_MASK  16
    #define ATDCTL2_AWAI_MASK  32
    #define ATDCTL2_AFFC_MASK  64
    #define ATDCTL2_ADPU_MASK  128


    /*** ATDCTL3 - ATD Control Register 3; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte             :1; 
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL3STR;
    #define ATDCTL3 _ATDCTL23.Overlap_STR.ATDCTL3STR.Byte
    #define ATDCTL3_FRZ0 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ0
    #define ATDCTL3_FRZ1 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ1
    #define ATDCTL3_FIFO _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FIFO
    #define ATDCTL3_S1C _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S1C
    #define ATDCTL3_S2C _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S2C
    #define ATDCTL3_S4C _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S4C
    #define ATDCTL3_S8C _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S8C
    
    #define ATDCTL3_FRZ _ATDCTL23.Overlap_STR.ATDCTL3STR.MergedBits.grpFRZ
    
    #define ATDCTL3_FRZ0_MASK  1
    #define ATDCTL3_FRZ1_MASK  2
    #define ATDCTL3_FIFO_MASK  4
    #define ATDCTL3_S1C_MASK  8
    #define ATDCTL3_S2C_MASK  16
    #define ATDCTL3_S4C_MASK  32
    #define ATDCTL3_S8C_MASK  64
    #define ATDCTL3_FRZ_MASK  3
    #define ATDCTL3_FRZ_BITNUM  0

  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word             :1; 
    word ASCIF       :1;                                       /* ATD Sequence Complete Interrupt Flag */
    word ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word AWAI        :1;                                       /* ATD Wait Mode */
    word AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
    word ADPU        :1;                                       /* ATD Disable / Power Down */
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL23STR;
extern volatile ATDCTL23STR _ATDCTL23 @(REG_BASE + 0x00000082);
#define ATDCTL23 _ATDCTL23.Word
#define ATDCTL23_FRZ0 _ATDCTL23.Bits.FRZ0
#define ATDCTL23_FRZ1 _ATDCTL23.Bits.FRZ1
#define ATDCTL23_FIFO _ATDCTL23.Bits.FIFO
#define ATDCTL23_S1C _ATDCTL23.Bits.S1C
#define ATDCTL23_S2C _ATDCTL23.Bits.S2C
#define ATDCTL23_S4C _ATDCTL23.Bits.S4C
#define ATDCTL23_S8C _ATDCTL23.Bits.S8C
#define ATDCTL23_ASCIF _ATDCTL23.Bits.ASCIF
#define ATDCTL23_ASCIE _ATDCTL23.Bits.ASCIE
#define ATDCTL23_ETRIGE _ATDCTL23.Bits.ETRIGE
#define ATDCTL23_ETRIGP _ATDCTL23.Bits.ETRIGP
#define ATDCTL23_ETRIGLE _ATDCTL23.Bits.ETRIGLE
#define ATDCTL23_AWAI _ATDCTL23.Bits.AWAI
#define ATDCTL23_AFFC _ATDCTL23.Bits.AFFC
#define ATDCTL23_ADPU _ATDCTL23.Bits.ADPU
#define ATDCTL23_FRZ _ATDCTL23.MergedBits.grpFRZ

#define ATDCTL23_FRZ0_MASK  1
#define ATDCTL23_FRZ1_MASK  2
#define ATDCTL23_FIFO_MASK  4
#define ATDCTL23_S1C_MASK  8
#define ATDCTL23_S2C_MASK  16
#define ATDCTL23_S4C_MASK  32
#define ATDCTL23_S8C_MASK  64
#define ATDCTL23_ASCIF_MASK  256
#define ATDCTL23_ASCIE_MASK  512
#define ATDCTL23_ETRIGE_MASK  1024
#define ATDCTL23_ETRIGP_MASK  2048
#define ATDCTL23_ETRIGLE_MASK  4096
#define ATDCTL23_AWAI_MASK  8192
#define ATDCTL23_AFFC_MASK  16384
#define ATDCTL23_ADPU_MASK  32768
#define ATDCTL23_FRZ_MASK  3
#define ATDCTL23_FRZ_BITNUM  0


/*** ATDCTL45 - ATD Control Register 45; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL4 - ATD Control Register 4; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SRES8       :1;                                       /* ATD Resolution Select */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :2;
        byte grpSRES_8 :1;
      } MergedBits;
    } ATDCTL4STR;
    #define ATDCTL4 _ATDCTL45.Overlap_STR.ATDCTL4STR.Byte
    #define ATDCTL4_PRS0 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS0
    #define ATDCTL4_PRS1 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS1
    #define ATDCTL4_PRS2 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS2
    #define ATDCTL4_PRS3 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS3
    #define ATDCTL4_PRS4 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS4
    #define ATDCTL4_SMP0 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP0
    #define ATDCTL4_SMP1 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP1
    #define ATDCTL4_SRES8 _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SRES8
    
    #define ATDCTL4_PRS _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpPRS
    #define ATDCTL4_SMP _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpSMP
    
    #define ATDCTL4_PRS0_MASK  1
    #define ATDCTL4_PRS1_MASK  2
    #define ATDCTL4_PRS2_MASK  4
    #define ATDCTL4_PRS3_MASK  8
    #define ATDCTL4_PRS4_MASK  16
    #define ATDCTL4_SMP0_MASK  32
    #define ATDCTL4_SMP1_MASK  64
    #define ATDCTL4_SRES8_MASK  128
    #define ATDCTL4_PRS_MASK  31
    #define ATDCTL4_PRS_BITNUM  0
    #define ATDCTL4_SMP_MASK  96
    #define ATDCTL4_SMP_BITNUM  5


    /*** ATDCTL5 - ATD Control Register 5; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte             :1; 
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
        byte DJM         :1;                                       /* Result Register Data Justification Mode */
      } Bits;
      struct {
        byte grpCx :3;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL5STR;
    #define ATDCTL5 _ATDCTL45.Overlap_STR.ATDCTL5STR.Byte
    #define ATDCTL5_CA _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CA
    #define ATDCTL5_CB _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CB
    #define ATDCTL5_CC _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CC
    #define ATDCTL5_MULT _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.MULT
    #define ATDCTL5_SCAN _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SCAN
    #define ATDCTL5_DSGN _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.DSGN
    #define ATDCTL5_DJM _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.DJM
    
    #define ATDCTL5_Cx _ATDCTL45.Overlap_STR.ATDCTL5STR.MergedBits.grpCx
    
    #define ATDCTL5_CA_MASK  1
    #define ATDCTL5_CB_MASK  2
    #define ATDCTL5_CC_MASK  4
    #define ATDCTL5_MULT_MASK  16
    #define ATDCTL5_SCAN_MASK  32
    #define ATDCTL5_DSGN_MASK  64
    #define ATDCTL5_DJM_MASK  128
    #define ATDCTL5_Cx_MASK  7
    #define ATDCTL5_Cx_BITNUM  0

  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word             :1; 
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word DSGN        :1;                                       /* Signed/Unsigned Result Data Mode */
    word DJM         :1;                                       /* Result Register Data Justification Mode */
    word PRS0        :1;                                       /* ATD Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SRES8       :1;                                       /* ATD Resolution Select */
  } Bits;
  struct {
    word grpCx   :3;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :2;
    word grpSRES_8 :1;
  } MergedBits;
} ATDCTL45STR;
extern volatile ATDCTL45STR _ATDCTL45 @(REG_BASE + 0x00000084);
#define ATDCTL45 _ATDCTL45.Word
#define ATDCTL45_CA _ATDCTL45.Bits.CA
#define ATDCTL45_CB _ATDCTL45.Bits.CB
#define ATDCTL45_CC _ATDCTL45.Bits.CC
#define ATDCTL45_MULT _ATDCTL45.Bits.MULT
#define ATDCTL45_SCAN _ATDCTL45.Bits.SCAN
#define ATDCTL45_DSGN _ATDCTL45.Bits.DSGN
#define ATDCTL45_DJM _ATDCTL45.Bits.DJM
#define ATDCTL45_PRS0 _ATDCTL45.Bits.PRS0
#define ATDCTL45_PRS1 _ATDCTL45.Bits.PRS1
#define ATDCTL45_PRS2 _ATDCTL45.Bits.PRS2
#define ATDCTL45_PRS3 _ATDCTL45.Bits.PRS3
#define ATDCTL45_PRS4 _ATDCTL45.Bits.PRS4
#define ATDCTL45_SMP0 _ATDCTL45.Bits.SMP0
#define ATDCTL45_SMP1 _ATDCTL45.Bits.SMP1
#define ATDCTL45_SRES8 _ATDCTL45.Bits.SRES8
#define ATDCTL45_Cx _ATDCTL45.MergedBits.grpCx
#define ATDCTL45_PRS _ATDCTL45.MergedBits.grpPRS
#define ATDCTL45_SMP _ATDCTL45.MergedBits.grpSMP

#define ATDCTL45_CA_MASK  1
#define ATDCTL45_CB_MASK  2
#define ATDCTL45_CC_MASK  4
#define ATDCTL45_MULT_MASK  16
#define ATDCTL45_SCAN_MASK  32
#define ATDCTL45_DSGN_MASK  64
#define ATDCTL45_DJM_MASK  128
#define ATDCTL45_PRS0_MASK  256
#define ATDCTL45_PRS1_MASK  512
#define ATDCTL45_PRS2_MASK  1024
#define ATDCTL45_PRS3_MASK  2048
#define ATDCTL45_PRS4_MASK  4096
#define ATDCTL45_SMP0_MASK  8192
#define ATDCTL45_SMP1_MASK  16384
#define ATDCTL45_SRES8_MASK  32768
#define ATDCTL45_Cx_MASK  7
#define ATDCTL45_Cx_BITNUM  0
#define ATDCTL45_PRS_MASK  7936
#define ATDCTL45_PRS_BITNUM  8
#define ATDCTL45_SMP_MASK  24576
#define ATDCTL45_SMP_BITNUM  13


/*** ATDSTAT0 - ATD Status Register 0; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte             :1; 
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1; 
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATDSTAT0STR;
extern volatile ATDSTAT0STR _ATDSTAT0 @(REG_BASE + 0x00000086);
#define ATDSTAT0 _ATDSTAT0.Byte
#define ATDSTAT0_CC0 _ATDSTAT0.Bits.CC0
#define ATDSTAT0_CC1 _ATDSTAT0.Bits.CC1
#define ATDSTAT0_CC2 _ATDSTAT0.Bits.CC2
#define ATDSTAT0_FIFOR _ATDSTAT0.Bits.FIFOR
#define ATDSTAT0_ETORF _ATDSTAT0.Bits.ETORF
#define ATDSTAT0_SCF _ATDSTAT0.Bits.SCF
#define ATDSTAT0_CC _ATDSTAT0.MergedBits.grpCC

#define ATDSTAT0_CC0_MASK  1
#define ATDSTAT0_CC1_MASK  2
#define ATDSTAT0_CC2_MASK  4
#define ATDSTAT0_FIFOR_MASK  16
#define ATDSTAT0_ETORF_MASK  32
#define ATDSTAT0_SCF_MASK  128
#define ATDSTAT0_CC_MASK  7
#define ATDSTAT0_CC_BITNUM  0


/*** ATDTEST1 - ATD Test Register; 0x00000089 ***/
typedef union {
  byte Byte;
  struct {
    byte SC          :1;                                       /* Special Channel Conversion Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ATDTEST1STR;
extern volatile ATDTEST1STR _ATDTEST1 @(REG_BASE + 0x00000089);
#define ATDTEST1 _ATDTEST1.Byte
#define ATDTEST1_SC _ATDTEST1.Bits.SC

#define ATDTEST1_SC_MASK  1


/*** ATDSTAT2 - ATD Status Register 2; 0x0000008A ***/
typedef union {
  byte Byte;
  struct {
    byte CCF8        :1;                                       /* Conversion Complete Flag 8 */
    byte CCF9        :1;                                       /* Conversion Complete Flag 9 */
    byte CCF10       :1;                                       /* Conversion Complete Flag 10 */
    byte CCF11       :1;                                       /* Conversion Complete Flag 11 */
    byte CCF12       :1;                                       /* Conversion Complete Flag 12 */
    byte CCF13       :1;                                       /* Conversion Complete Flag 13 */
    byte CCF14       :1;                                       /* Conversion Complete Flag 14 */
    byte CCF15       :1;                                       /* Conversion Complete Flag 15 */
  } Bits;
  struct {
    byte grpCCF_8 :8;
  } MergedBits;
} ATDSTAT2STR;
extern volatile ATDSTAT2STR _ATDSTAT2 @(REG_BASE + 0x0000008A);
#define ATDSTAT2 _ATDSTAT2.Byte
#define ATDSTAT2_CCF8 _ATDSTAT2.Bits.CCF8
#define ATDSTAT2_CCF9 _ATDSTAT2.Bits.CCF9
#define ATDSTAT2_CCF10 _ATDSTAT2.Bits.CCF10
#define ATDSTAT2_CCF11 _ATDSTAT2.Bits.CCF11
#define ATDSTAT2_CCF12 _ATDSTAT2.Bits.CCF12
#define ATDSTAT2_CCF13 _ATDSTAT2.Bits.CCF13
#define ATDSTAT2_CCF14 _ATDSTAT2.Bits.CCF14
#define ATDSTAT2_CCF15 _ATDSTAT2.Bits.CCF15
#define ATDSTAT2_CCF_8 _ATDSTAT2.MergedBits.grpCCF_8
#define ATDSTAT2_CCF ATDSTAT2_CCF_8

#define ATDSTAT2_CCF8_MASK  1
#define ATDSTAT2_CCF9_MASK  2
#define ATDSTAT2_CCF10_MASK  4
#define ATDSTAT2_CCF11_MASK  8
#define ATDSTAT2_CCF12_MASK  16
#define ATDSTAT2_CCF13_MASK  32
#define ATDSTAT2_CCF14_MASK  64
#define ATDSTAT2_CCF15_MASK  128
#define ATDSTAT2_CCF_8_MASK  255
#define ATDSTAT2_CCF_8_BITNUM  0


/*** ATDSTAT1 - ATD Status Register 1; 0x0000008B ***/
typedef union {
  byte Byte;
  struct {
    byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
    byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
    byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
    byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
    byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
    byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
    byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
    byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
  } Bits;
  struct {
    byte grpCCF  :8;
  } MergedBits;
} ATDSTAT1STR;
extern volatile ATDSTAT1STR _ATDSTAT1 @(REG_BASE + 0x0000008B);
#define ATDSTAT1 _ATDSTAT1.Byte
#define ATDSTAT1_CCF0 _ATDSTAT1.Bits.CCF0
#define ATDSTAT1_CCF1 _ATDSTAT1.Bits.CCF1
#define ATDSTAT1_CCF2 _ATDSTAT1.Bits.CCF2
#define ATDSTAT1_CCF3 _ATDSTAT1.Bits.CCF3
#define ATDSTAT1_CCF4 _ATDSTAT1.Bits.CCF4
#define ATDSTAT1_CCF5 _ATDSTAT1.Bits.CCF5
#define ATDSTAT1_CCF6 _ATDSTAT1.Bits.CCF6
#define ATDSTAT1_CCF7 _ATDSTAT1.Bits.CCF7
#define ATDSTAT1_CCF _ATDSTAT1.MergedBits.grpCCF

#define ATDSTAT1_CCF0_MASK  1
#define ATDSTAT1_CCF1_MASK  2
#define ATDSTAT1_CCF2_MASK  4
#define ATDSTAT1_CCF3_MASK  8
#define ATDSTAT1_CCF4_MASK  16
#define ATDSTAT1_CCF5_MASK  32
#define ATDSTAT1_CCF6_MASK  64
#define ATDSTAT1_CCF7_MASK  128
#define ATDSTAT1_CCF_MASK  255
#define ATDSTAT1_CCF_BITNUM  0


/*** ATDDIEN - ATD Input Enable Register; 0x0000008C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDIEN0 - ATD Input Enable Register 0; 0x0000008C ***/
    union {
      byte Byte;
      struct {
        byte IEN8        :1;                                       /* ATD Digital Input Enable on channel 8 */
        byte IEN9        :1;                                       /* ATD Digital Input Enable on channel 9 */
        byte IEN10       :1;                                       /* ATD Digital Input Enable on channel 10 */
        byte IEN11       :1;                                       /* ATD Digital Input Enable on channel 11 */
        byte IEN12       :1;                                       /* ATD Digital Input Enable on channel 12 */
        byte IEN13       :1;                                       /* ATD Digital Input Enable on channel 13 */
        byte IEN14       :1;                                       /* ATD Digital Input Enable on channel 14 */
        byte IEN15       :1;                                       /* ATD Digital Input Enable on channel 15 */
      } Bits;
      struct {
        byte grpIEN_8 :8;
      } MergedBits;
    } ATDDIEN0STR;
    #define ATDDIEN0 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Byte
    #define ATDDIEN0_IEN8 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN8
    #define ATDDIEN0_IEN9 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN9
    #define ATDDIEN0_IEN10 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN10
    #define ATDDIEN0_IEN11 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN11
    #define ATDDIEN0_IEN12 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN12
    #define ATDDIEN0_IEN13 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN13
    #define ATDDIEN0_IEN14 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN14
    #define ATDDIEN0_IEN15 _ATDDIEN.Overlap_STR.ATDDIEN0STR.Bits.IEN15
    
    #define ATDDIEN0_IEN_8 _ATDDIEN.Overlap_STR.ATDDIEN0STR.MergedBits.grpIEN_8
    #define ATDDIEN0_IEN ATDDIEN0_IEN_8
    
    #define ATDDIEN0_IEN8_MASK  1
    #define ATDDIEN0_IEN9_MASK  2
    #define ATDDIEN0_IEN10_MASK  4
    #define ATDDIEN0_IEN11_MASK  8
    #define ATDDIEN0_IEN12_MASK  16
    #define ATDDIEN0_IEN13_MASK  32
    #define ATDDIEN0_IEN14_MASK  64
    #define ATDDIEN0_IEN15_MASK  128
    #define ATDDIEN0_IEN_8_MASK  255
    #define ATDDIEN0_IEN_8_BITNUM  0


    /*** ATDDIEN1 - ATD Input Enable Register 1; 0x0000008D ***/
    union {
      byte Byte;
      struct {
        byte IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
        byte IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
        byte IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
        byte IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
        byte IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
        byte IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
        byte IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
        byte IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
      } Bits;
      struct {
        byte grpIEN :8;
      } MergedBits;
    } ATDDIEN1STR;
    #define ATDDIEN1 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Byte
    #define ATDDIEN1_IEN0 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN0
    #define ATDDIEN1_IEN1 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN1
    #define ATDDIEN1_IEN2 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN2
    #define ATDDIEN1_IEN3 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN3
    #define ATDDIEN1_IEN4 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN4
    #define ATDDIEN1_IEN5 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN5
    #define ATDDIEN1_IEN6 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN6
    #define ATDDIEN1_IEN7 _ATDDIEN.Overlap_STR.ATDDIEN1STR.Bits.IEN7
    
    #define ATDDIEN1_IEN _ATDDIEN.Overlap_STR.ATDDIEN1STR.MergedBits.grpIEN
    
    #define ATDDIEN1_IEN0_MASK  1
    #define ATDDIEN1_IEN1_MASK  2
    #define ATDDIEN1_IEN2_MASK  4
    #define ATDDIEN1_IEN3_MASK  8
    #define ATDDIEN1_IEN4_MASK  16
    #define ATDDIEN1_IEN5_MASK  32
    #define ATDDIEN1_IEN6_MASK  64
    #define ATDDIEN1_IEN7_MASK  128
    #define ATDDIEN1_IEN_MASK  255
    #define ATDDIEN1_IEN_BITNUM  0

  } Overlap_STR;

  struct {
    word IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    word IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    word IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    word IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    word IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    word IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    word IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
    word IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
    word IEN8        :1;                                       /* ATD Digital Input Enable on channel 8 */
    word IEN9        :1;                                       /* ATD Digital Input Enable on channel 9 */
    word IEN10       :1;                                       /* ATD Digital Input Enable on channel 10 */
    word IEN11       :1;                                       /* ATD Digital Input Enable on channel 11 */
    word IEN12       :1;                                       /* ATD Digital Input Enable on channel 12 */
    word IEN13       :1;                                       /* ATD Digital Input Enable on channel 13 */
    word IEN14       :1;                                       /* ATD Digital Input Enable on channel 14 */
    word IEN15       :1;                                       /* ATD Digital Input Enable on channel 15 */
  } Bits;
  struct {
    word grpIEN  :16;
  } MergedBits;
} ATDDIENSTR;
extern volatile ATDDIENSTR _ATDDIEN @(REG_BASE + 0x0000008C);
#define ATDDIEN _ATDDIEN.Word
#define ATDDIEN_IEN0 _ATDDIEN.Bits.IEN0
#define ATDDIEN_IEN1 _ATDDIEN.Bits.IEN1
#define ATDDIEN_IEN2 _ATDDIEN.Bits.IEN2
#define ATDDIEN_IEN3 _ATDDIEN.Bits.IEN3
#define ATDDIEN_IEN4 _ATDDIEN.Bits.IEN4
#define ATDDIEN_IEN5 _ATDDIEN.Bits.IEN5
#define ATDDIEN_IEN6 _ATDDIEN.Bits.IEN6
#define ATDDIEN_IEN7 _ATDDIEN.Bits.IEN7
#define ATDDIEN_IEN8 _ATDDIEN.Bits.IEN8
#define ATDDIEN_IEN9 _ATDDIEN.Bits.IEN9
#define ATDDIEN_IEN10 _ATDDIEN.Bits.IEN10
#define ATDDIEN_IEN11 _ATDDIEN.Bits.IEN11
#define ATDDIEN_IEN12 _ATDDIEN.Bits.IEN12
#define ATDDIEN_IEN13 _ATDDIEN.Bits.IEN13
#define ATDDIEN_IEN14 _ATDDIEN.Bits.IEN14
#define ATDDIEN_IEN15 _ATDDIEN.Bits.IEN15
#define ATDDIEN_IEN _ATDDIEN.MergedBits.grpIEN

#define ATDDIEN_IEN0_MASK  1
#define ATDDIEN_IEN1_MASK  2
#define ATDDIEN_IEN2_MASK  4
#define ATDDIEN_IEN3_MASK  8
#define ATDDIEN_IEN4_MASK  16
#define ATDDIEN_IEN5_MASK  32
#define ATDDIEN_IEN6_MASK  64
#define ATDDIEN_IEN7_MASK  128
#define ATDDIEN_IEN8_MASK  256
#define ATDDIEN_IEN9_MASK  512
#define ATDDIEN_IEN10_MASK  1024
#define ATDDIEN_IEN11_MASK  2048
#define ATDDIEN_IEN12_MASK  4096
#define ATDDIEN_IEN13_MASK  8192
#define ATDDIEN_IEN14_MASK  16384
#define ATDDIEN_IEN15_MASK  32768
#define ATDDIEN_IEN_MASK  65535
#define ATDDIEN_IEN_BITNUM  0


/*** PORTAD1 - Port AD1 Data Register; 0x0000008F ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* A/D Channel 0 (AN0) Digital Input */
    byte PTAD1       :1;                                       /* A/D Channel 1 (AN1) Digital Input */
    byte PTAD2       :1;                                       /* A/D Channel 2 (AN2) Digital Input */
    byte PTAD3       :1;                                       /* A/D Channel 3 (AN3) Digital Input */
    byte PTAD4       :1;                                       /* A/D Channel 4 (AN4) Digital Input */
    byte PTAD5       :1;                                       /* A/D Channel 5 (AN5) Digital Input */
    byte PTAD6       :1;                                       /* A/D Channel 6 (AN6) Digital Input */
    byte PTAD7       :1;                                       /* A/D Channel 7 (AN7) Digital Input */
  } Bits;
  struct {
    byte grpPTAD :8;
  } MergedBits;
} PORTAD1STR;
extern volatile PORTAD1STR _PORTAD1 @(REG_BASE + 0x0000008F);
#define PORTAD1 _PORTAD1.Byte
#define PORTAD1_PTAD0 _PORTAD1.Bits.PTAD0
#define PORTAD1_PTAD1 _PORTAD1.Bits.PTAD1
#define PORTAD1_PTAD2 _PORTAD1.Bits.PTAD2
#define PORTAD1_PTAD3 _PORTAD1.Bits.PTAD3
#define PORTAD1_PTAD4 _PORTAD1.Bits.PTAD4
#define PORTAD1_PTAD5 _PORTAD1.Bits.PTAD5
#define PORTAD1_PTAD6 _PORTAD1.Bits.PTAD6
#define PORTAD1_PTAD7 _PORTAD1.Bits.PTAD7
#define PORTAD1_PTAD _PORTAD1.MergedBits.grpPTAD

#define PORTAD1_PTAD0_MASK  1
#define PORTAD1_PTAD1_MASK  2
#define PORTAD1_PTAD2_MASK  4
#define PORTAD1_PTAD3_MASK  8
#define PORTAD1_PTAD4_MASK  16
#define PORTAD1_PTAD5_MASK  32
#define PORTAD1_PTAD6_MASK  64
#define PORTAD1_PTAD7_MASK  128
#define PORTAD1_PTAD_MASK  255
#define PORTAD1_PTAD_BITNUM  0


/*** ATDDR0 - ATD Conversion Result Register 0; 0x00000090 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR0H - ATD Conversion Result Register 0 High; 0x00000090 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR0HSTR;
    #define ATDDR0H _ATDDR0.Overlap_STR.ATDDR0HSTR.Byte
    #define ATDDR0H_BIT8 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT8
    #define ATDDR0H_BIT9 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT9
    #define ATDDR0H_BIT10 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT10
    #define ATDDR0H_BIT11 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT11
    #define ATDDR0H_BIT12 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT12
    #define ATDDR0H_BIT13 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT13
    #define ATDDR0H_BIT14 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT14
    #define ATDDR0H_BIT15 _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT15
    
    #define ATDDR0H_BIT_8 _ATDDR0.Overlap_STR.ATDDR0HSTR.MergedBits.grpBIT_8
    #define ATDDR0H_BIT ATDDR0H_BIT_8
    
    #define ATDDR0H_BIT8_MASK  1
    #define ATDDR0H_BIT9_MASK  2
    #define ATDDR0H_BIT10_MASK  4
    #define ATDDR0H_BIT11_MASK  8
    #define ATDDR0H_BIT12_MASK  16
    #define ATDDR0H_BIT13_MASK  32
    #define ATDDR0H_BIT14_MASK  64
    #define ATDDR0H_BIT15_MASK  128
    #define ATDDR0H_BIT_8_MASK  255
    #define ATDDR0H_BIT_8_BITNUM  0


    /*** ATDDR0L - ATD Conversion Result Register 0 Lw; 0x00000091 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR0LSTR;
    #define ATDDR0L _ATDDR0.Overlap_STR.ATDDR0LSTR.Byte
    #define ATDDR0L_BIT6 _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT6
    #define ATDDR0L_BIT7 _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT7
    
    #define ATDDR0L_BIT_6 _ATDDR0.Overlap_STR.ATDDR0LSTR.MergedBits.grpBIT_6
    #define ATDDR0L_BIT ATDDR0L_BIT_6
    
    #define ATDDR0L_BIT6_MASK  64
    #define ATDDR0L_BIT7_MASK  128
    #define ATDDR0L_BIT_6_MASK  192
    #define ATDDR0L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR0STR;
extern volatile ATDDR0STR _ATDDR0 @(REG_BASE + 0x00000090);
#define ATDDR0 _ATDDR0.Word
#define ATDDR0_BIT6 _ATDDR0.Bits.BIT6
#define ATDDR0_BIT7 _ATDDR0.Bits.BIT7
#define ATDDR0_BIT8 _ATDDR0.Bits.BIT8
#define ATDDR0_BIT9 _ATDDR0.Bits.BIT9
#define ATDDR0_BIT10 _ATDDR0.Bits.BIT10
#define ATDDR0_BIT11 _ATDDR0.Bits.BIT11
#define ATDDR0_BIT12 _ATDDR0.Bits.BIT12
#define ATDDR0_BIT13 _ATDDR0.Bits.BIT13
#define ATDDR0_BIT14 _ATDDR0.Bits.BIT14
#define ATDDR0_BIT15 _ATDDR0.Bits.BIT15
#define ATDDR0_BIT_6 _ATDDR0.MergedBits.grpBIT_6
#define ATDDR0_BIT ATDDR0_BIT_6

#define ATDDR0_BIT6_MASK  64
#define ATDDR0_BIT7_MASK  128
#define ATDDR0_BIT8_MASK  256
#define ATDDR0_BIT9_MASK  512
#define ATDDR0_BIT10_MASK  1024
#define ATDDR0_BIT11_MASK  2048
#define ATDDR0_BIT12_MASK  4096
#define ATDDR0_BIT13_MASK  8192
#define ATDDR0_BIT14_MASK  16384
#define ATDDR0_BIT15_MASK  32768
#define ATDDR0_BIT_6_MASK  65472
#define ATDDR0_BIT_6_BITNUM  6


/*** ATDDR1 - ATD Conversion Result Register 1; 0x00000092 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR1H - ATD Conversion Result Register 1 High; 0x00000092 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR1HSTR;
    #define ATDDR1H _ATDDR1.Overlap_STR.ATDDR1HSTR.Byte
    #define ATDDR1H_BIT8 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT8
    #define ATDDR1H_BIT9 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT9
    #define ATDDR1H_BIT10 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT10
    #define ATDDR1H_BIT11 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT11
    #define ATDDR1H_BIT12 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT12
    #define ATDDR1H_BIT13 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT13
    #define ATDDR1H_BIT14 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT14
    #define ATDDR1H_BIT15 _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT15
    
    #define ATDDR1H_BIT_8 _ATDDR1.Overlap_STR.ATDDR1HSTR.MergedBits.grpBIT_8
    #define ATDDR1H_BIT ATDDR1H_BIT_8
    
    #define ATDDR1H_BIT8_MASK  1
    #define ATDDR1H_BIT9_MASK  2
    #define ATDDR1H_BIT10_MASK  4
    #define ATDDR1H_BIT11_MASK  8
    #define ATDDR1H_BIT12_MASK  16
    #define ATDDR1H_BIT13_MASK  32
    #define ATDDR1H_BIT14_MASK  64
    #define ATDDR1H_BIT15_MASK  128
    #define ATDDR1H_BIT_8_MASK  255
    #define ATDDR1H_BIT_8_BITNUM  0


    /*** ATDDR1L - ATD Conversion Result Register 1 Lw; 0x00000093 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR1LSTR;
    #define ATDDR1L _ATDDR1.Overlap_STR.ATDDR1LSTR.Byte
    #define ATDDR1L_BIT6 _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT6
    #define ATDDR1L_BIT7 _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT7
    
    #define ATDDR1L_BIT_6 _ATDDR1.Overlap_STR.ATDDR1LSTR.MergedBits.grpBIT_6
    #define ATDDR1L_BIT ATDDR1L_BIT_6
    
    #define ATDDR1L_BIT6_MASK  64
    #define ATDDR1L_BIT7_MASK  128
    #define ATDDR1L_BIT_6_MASK  192
    #define ATDDR1L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR1STR;
extern volatile ATDDR1STR _ATDDR1 @(REG_BASE + 0x00000092);
#define ATDDR1 _ATDDR1.Word
#define ATDDR1_BIT6 _ATDDR1.Bits.BIT6
#define ATDDR1_BIT7 _ATDDR1.Bits.BIT7
#define ATDDR1_BIT8 _ATDDR1.Bits.BIT8
#define ATDDR1_BIT9 _ATDDR1.Bits.BIT9
#define ATDDR1_BIT10 _ATDDR1.Bits.BIT10
#define ATDDR1_BIT11 _ATDDR1.Bits.BIT11
#define ATDDR1_BIT12 _ATDDR1.Bits.BIT12
#define ATDDR1_BIT13 _ATDDR1.Bits.BIT13
#define ATDDR1_BIT14 _ATDDR1.Bits.BIT14
#define ATDDR1_BIT15 _ATDDR1.Bits.BIT15
#define ATDDR1_BIT_6 _ATDDR1.MergedBits.grpBIT_6
#define ATDDR1_BIT ATDDR1_BIT_6

#define ATDDR1_BIT6_MASK  64
#define ATDDR1_BIT7_MASK  128
#define ATDDR1_BIT8_MASK  256
#define ATDDR1_BIT9_MASK  512
#define ATDDR1_BIT10_MASK  1024
#define ATDDR1_BIT11_MASK  2048
#define ATDDR1_BIT12_MASK  4096
#define ATDDR1_BIT13_MASK  8192
#define ATDDR1_BIT14_MASK  16384
#define ATDDR1_BIT15_MASK  32768
#define ATDDR1_BIT_6_MASK  65472
#define ATDDR1_BIT_6_BITNUM  6


/*** ATDDR2 - ATD Conversion Result Register 2; 0x00000094 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR2H - ATD Conversion Result Register 2 High; 0x00000094 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR2HSTR;
    #define ATDDR2H _ATDDR2.Overlap_STR.ATDDR2HSTR.Byte
    #define ATDDR2H_BIT8 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT8
    #define ATDDR2H_BIT9 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT9
    #define ATDDR2H_BIT10 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT10
    #define ATDDR2H_BIT11 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT11
    #define ATDDR2H_BIT12 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT12
    #define ATDDR2H_BIT13 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT13
    #define ATDDR2H_BIT14 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT14
    #define ATDDR2H_BIT15 _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT15
    
    #define ATDDR2H_BIT_8 _ATDDR2.Overlap_STR.ATDDR2HSTR.MergedBits.grpBIT_8
    #define ATDDR2H_BIT ATDDR2H_BIT_8
    
    #define ATDDR2H_BIT8_MASK  1
    #define ATDDR2H_BIT9_MASK  2
    #define ATDDR2H_BIT10_MASK  4
    #define ATDDR2H_BIT11_MASK  8
    #define ATDDR2H_BIT12_MASK  16
    #define ATDDR2H_BIT13_MASK  32
    #define ATDDR2H_BIT14_MASK  64
    #define ATDDR2H_BIT15_MASK  128
    #define ATDDR2H_BIT_8_MASK  255
    #define ATDDR2H_BIT_8_BITNUM  0


    /*** ATDDR2L - ATD Conversion Result Register 2 Lw; 0x00000095 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR2LSTR;
    #define ATDDR2L _ATDDR2.Overlap_STR.ATDDR2LSTR.Byte
    #define ATDDR2L_BIT6 _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT6
    #define ATDDR2L_BIT7 _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT7
    
    #define ATDDR2L_BIT_6 _ATDDR2.Overlap_STR.ATDDR2LSTR.MergedBits.grpBIT_6
    #define ATDDR2L_BIT ATDDR2L_BIT_6
    
    #define ATDDR2L_BIT6_MASK  64
    #define ATDDR2L_BIT7_MASK  128
    #define ATDDR2L_BIT_6_MASK  192
    #define ATDDR2L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR2STR;
extern volatile ATDDR2STR _ATDDR2 @(REG_BASE + 0x00000094);
#define ATDDR2 _ATDDR2.Word
#define ATDDR2_BIT6 _ATDDR2.Bits.BIT6
#define ATDDR2_BIT7 _ATDDR2.Bits.BIT7
#define ATDDR2_BIT8 _ATDDR2.Bits.BIT8
#define ATDDR2_BIT9 _ATDDR2.Bits.BIT9
#define ATDDR2_BIT10 _ATDDR2.Bits.BIT10
#define ATDDR2_BIT11 _ATDDR2.Bits.BIT11
#define ATDDR2_BIT12 _ATDDR2.Bits.BIT12
#define ATDDR2_BIT13 _ATDDR2.Bits.BIT13
#define ATDDR2_BIT14 _ATDDR2.Bits.BIT14
#define ATDDR2_BIT15 _ATDDR2.Bits.BIT15
#define ATDDR2_BIT_6 _ATDDR2.MergedBits.grpBIT_6
#define ATDDR2_BIT ATDDR2_BIT_6

#define ATDDR2_BIT6_MASK  64
#define ATDDR2_BIT7_MASK  128
#define ATDDR2_BIT8_MASK  256
#define ATDDR2_BIT9_MASK  512
#define ATDDR2_BIT10_MASK  1024
#define ATDDR2_BIT11_MASK  2048
#define ATDDR2_BIT12_MASK  4096
#define ATDDR2_BIT13_MASK  8192
#define ATDDR2_BIT14_MASK  16384
#define ATDDR2_BIT15_MASK  32768
#define ATDDR2_BIT_6_MASK  65472
#define ATDDR2_BIT_6_BITNUM  6


/*** ATDDR3 - ATD Conversion Result Register 3; 0x00000096 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR3H - ATD Conversion Result Register 3 High; 0x00000096 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR3HSTR;
    #define ATDDR3H _ATDDR3.Overlap_STR.ATDDR3HSTR.Byte
    #define ATDDR3H_BIT8 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT8
    #define ATDDR3H_BIT9 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT9
    #define ATDDR3H_BIT10 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT10
    #define ATDDR3H_BIT11 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT11
    #define ATDDR3H_BIT12 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT12
    #define ATDDR3H_BIT13 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT13
    #define ATDDR3H_BIT14 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT14
    #define ATDDR3H_BIT15 _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT15
    
    #define ATDDR3H_BIT_8 _ATDDR3.Overlap_STR.ATDDR3HSTR.MergedBits.grpBIT_8
    #define ATDDR3H_BIT ATDDR3H_BIT_8
    
    #define ATDDR3H_BIT8_MASK  1
    #define ATDDR3H_BIT9_MASK  2
    #define ATDDR3H_BIT10_MASK  4
    #define ATDDR3H_BIT11_MASK  8
    #define ATDDR3H_BIT12_MASK  16
    #define ATDDR3H_BIT13_MASK  32
    #define ATDDR3H_BIT14_MASK  64
    #define ATDDR3H_BIT15_MASK  128
    #define ATDDR3H_BIT_8_MASK  255
    #define ATDDR3H_BIT_8_BITNUM  0


    /*** ATDDR3L - ATD Conversion Result Register 3 Lw; 0x00000097 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR3LSTR;
    #define ATDDR3L _ATDDR3.Overlap_STR.ATDDR3LSTR.Byte
    #define ATDDR3L_BIT6 _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT6
    #define ATDDR3L_BIT7 _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT7
    
    #define ATDDR3L_BIT_6 _ATDDR3.Overlap_STR.ATDDR3LSTR.MergedBits.grpBIT_6
    #define ATDDR3L_BIT ATDDR3L_BIT_6
    
    #define ATDDR3L_BIT6_MASK  64
    #define ATDDR3L_BIT7_MASK  128
    #define ATDDR3L_BIT_6_MASK  192
    #define ATDDR3L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR3STR;
extern volatile ATDDR3STR _ATDDR3 @(REG_BASE + 0x00000096);
#define ATDDR3 _ATDDR3.Word
#define ATDDR3_BIT6 _ATDDR3.Bits.BIT6
#define ATDDR3_BIT7 _ATDDR3.Bits.BIT7
#define ATDDR3_BIT8 _ATDDR3.Bits.BIT8
#define ATDDR3_BIT9 _ATDDR3.Bits.BIT9
#define ATDDR3_BIT10 _ATDDR3.Bits.BIT10
#define ATDDR3_BIT11 _ATDDR3.Bits.BIT11
#define ATDDR3_BIT12 _ATDDR3.Bits.BIT12
#define ATDDR3_BIT13 _ATDDR3.Bits.BIT13
#define ATDDR3_BIT14 _ATDDR3.Bits.BIT14
#define ATDDR3_BIT15 _ATDDR3.Bits.BIT15
#define ATDDR3_BIT_6 _ATDDR3.MergedBits.grpBIT_6
#define ATDDR3_BIT ATDDR3_BIT_6

#define ATDDR3_BIT6_MASK  64
#define ATDDR3_BIT7_MASK  128
#define ATDDR3_BIT8_MASK  256
#define ATDDR3_BIT9_MASK  512
#define ATDDR3_BIT10_MASK  1024
#define ATDDR3_BIT11_MASK  2048
#define ATDDR3_BIT12_MASK  4096
#define ATDDR3_BIT13_MASK  8192
#define ATDDR3_BIT14_MASK  16384
#define ATDDR3_BIT15_MASK  32768
#define ATDDR3_BIT_6_MASK  65472
#define ATDDR3_BIT_6_BITNUM  6


/*** ATDDR4 - ATD Conversion Result Register 4; 0x00000098 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR4H - ATD Conversion Result Register 4 High; 0x00000098 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR4HSTR;
    #define ATDDR4H _ATDDR4.Overlap_STR.ATDDR4HSTR.Byte
    #define ATDDR4H_BIT8 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT8
    #define ATDDR4H_BIT9 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT9
    #define ATDDR4H_BIT10 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT10
    #define ATDDR4H_BIT11 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT11
    #define ATDDR4H_BIT12 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT12
    #define ATDDR4H_BIT13 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT13
    #define ATDDR4H_BIT14 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT14
    #define ATDDR4H_BIT15 _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT15
    
    #define ATDDR4H_BIT_8 _ATDDR4.Overlap_STR.ATDDR4HSTR.MergedBits.grpBIT_8
    #define ATDDR4H_BIT ATDDR4H_BIT_8
    
    #define ATDDR4H_BIT8_MASK  1
    #define ATDDR4H_BIT9_MASK  2
    #define ATDDR4H_BIT10_MASK  4
    #define ATDDR4H_BIT11_MASK  8
    #define ATDDR4H_BIT12_MASK  16
    #define ATDDR4H_BIT13_MASK  32
    #define ATDDR4H_BIT14_MASK  64
    #define ATDDR4H_BIT15_MASK  128
    #define ATDDR4H_BIT_8_MASK  255
    #define ATDDR4H_BIT_8_BITNUM  0


    /*** ATDDR4L - ATD Conversion Result Register 4 Lw; 0x00000099 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR4LSTR;
    #define ATDDR4L _ATDDR4.Overlap_STR.ATDDR4LSTR.Byte
    #define ATDDR4L_BIT6 _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT6
    #define ATDDR4L_BIT7 _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT7
    
    #define ATDDR4L_BIT_6 _ATDDR4.Overlap_STR.ATDDR4LSTR.MergedBits.grpBIT_6
    #define ATDDR4L_BIT ATDDR4L_BIT_6
    
    #define ATDDR4L_BIT6_MASK  64
    #define ATDDR4L_BIT7_MASK  128
    #define ATDDR4L_BIT_6_MASK  192
    #define ATDDR4L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR4STR;
extern volatile ATDDR4STR _ATDDR4 @(REG_BASE + 0x00000098);
#define ATDDR4 _ATDDR4.Word
#define ATDDR4_BIT6 _ATDDR4.Bits.BIT6
#define ATDDR4_BIT7 _ATDDR4.Bits.BIT7
#define ATDDR4_BIT8 _ATDDR4.Bits.BIT8
#define ATDDR4_BIT9 _ATDDR4.Bits.BIT9
#define ATDDR4_BIT10 _ATDDR4.Bits.BIT10
#define ATDDR4_BIT11 _ATDDR4.Bits.BIT11
#define ATDDR4_BIT12 _ATDDR4.Bits.BIT12
#define ATDDR4_BIT13 _ATDDR4.Bits.BIT13
#define ATDDR4_BIT14 _ATDDR4.Bits.BIT14
#define ATDDR4_BIT15 _ATDDR4.Bits.BIT15
#define ATDDR4_BIT_6 _ATDDR4.MergedBits.grpBIT_6
#define ATDDR4_BIT ATDDR4_BIT_6

#define ATDDR4_BIT6_MASK  64
#define ATDDR4_BIT7_MASK  128
#define ATDDR4_BIT8_MASK  256
#define ATDDR4_BIT9_MASK  512
#define ATDDR4_BIT10_MASK  1024
#define ATDDR4_BIT11_MASK  2048
#define ATDDR4_BIT12_MASK  4096
#define ATDDR4_BIT13_MASK  8192
#define ATDDR4_BIT14_MASK  16384
#define ATDDR4_BIT15_MASK  32768
#define ATDDR4_BIT_6_MASK  65472
#define ATDDR4_BIT_6_BITNUM  6


/*** ATDDR5 - ATD Conversion Result Register 5; 0x0000009A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR5H - ATD Conversion Result Register 5 High; 0x0000009A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR5HSTR;
    #define ATDDR5H _ATDDR5.Overlap_STR.ATDDR5HSTR.Byte
    #define ATDDR5H_BIT8 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT8
    #define ATDDR5H_BIT9 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT9
    #define ATDDR5H_BIT10 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT10
    #define ATDDR5H_BIT11 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT11
    #define ATDDR5H_BIT12 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT12
    #define ATDDR5H_BIT13 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT13
    #define ATDDR5H_BIT14 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT14
    #define ATDDR5H_BIT15 _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT15
    
    #define ATDDR5H_BIT_8 _ATDDR5.Overlap_STR.ATDDR5HSTR.MergedBits.grpBIT_8
    #define ATDDR5H_BIT ATDDR5H_BIT_8
    
    #define ATDDR5H_BIT8_MASK  1
    #define ATDDR5H_BIT9_MASK  2
    #define ATDDR5H_BIT10_MASK  4
    #define ATDDR5H_BIT11_MASK  8
    #define ATDDR5H_BIT12_MASK  16
    #define ATDDR5H_BIT13_MASK  32
    #define ATDDR5H_BIT14_MASK  64
    #define ATDDR5H_BIT15_MASK  128
    #define ATDDR5H_BIT_8_MASK  255
    #define ATDDR5H_BIT_8_BITNUM  0


    /*** ATDDR5L - ATD Conversion Result Register 5 Lw; 0x0000009B ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR5LSTR;
    #define ATDDR5L _ATDDR5.Overlap_STR.ATDDR5LSTR.Byte
    #define ATDDR5L_BIT6 _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT6
    #define ATDDR5L_BIT7 _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT7
    
    #define ATDDR5L_BIT_6 _ATDDR5.Overlap_STR.ATDDR5LSTR.MergedBits.grpBIT_6
    #define ATDDR5L_BIT ATDDR5L_BIT_6
    
    #define ATDDR5L_BIT6_MASK  64
    #define ATDDR5L_BIT7_MASK  128
    #define ATDDR5L_BIT_6_MASK  192
    #define ATDDR5L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR5STR;
extern volatile ATDDR5STR _ATDDR5 @(REG_BASE + 0x0000009A);
#define ATDDR5 _ATDDR5.Word
#define ATDDR5_BIT6 _ATDDR5.Bits.BIT6
#define ATDDR5_BIT7 _ATDDR5.Bits.BIT7
#define ATDDR5_BIT8 _ATDDR5.Bits.BIT8
#define ATDDR5_BIT9 _ATDDR5.Bits.BIT9
#define ATDDR5_BIT10 _ATDDR5.Bits.BIT10
#define ATDDR5_BIT11 _ATDDR5.Bits.BIT11
#define ATDDR5_BIT12 _ATDDR5.Bits.BIT12
#define ATDDR5_BIT13 _ATDDR5.Bits.BIT13
#define ATDDR5_BIT14 _ATDDR5.Bits.BIT14
#define ATDDR5_BIT15 _ATDDR5.Bits.BIT15
#define ATDDR5_BIT_6 _ATDDR5.MergedBits.grpBIT_6
#define ATDDR5_BIT ATDDR5_BIT_6

#define ATDDR5_BIT6_MASK  64
#define ATDDR5_BIT7_MASK  128
#define ATDDR5_BIT8_MASK  256
#define ATDDR5_BIT9_MASK  512
#define ATDDR5_BIT10_MASK  1024
#define ATDDR5_BIT11_MASK  2048
#define ATDDR5_BIT12_MASK  4096
#define ATDDR5_BIT13_MASK  8192
#define ATDDR5_BIT14_MASK  16384
#define ATDDR5_BIT15_MASK  32768
#define ATDDR5_BIT_6_MASK  65472
#define ATDDR5_BIT_6_BITNUM  6


/*** ATDDR6 - ATD Conversion Result Register 6; 0x0000009C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR6H - ATD Conversion Result Register 6 High; 0x0000009C ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR6HSTR;
    #define ATDDR6H _ATDDR6.Overlap_STR.ATDDR6HSTR.Byte
    #define ATDDR6H_BIT8 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT8
    #define ATDDR6H_BIT9 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT9
    #define ATDDR6H_BIT10 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT10
    #define ATDDR6H_BIT11 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT11
    #define ATDDR6H_BIT12 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT12
    #define ATDDR6H_BIT13 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT13
    #define ATDDR6H_BIT14 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT14
    #define ATDDR6H_BIT15 _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT15
    
    #define ATDDR6H_BIT_8 _ATDDR6.Overlap_STR.ATDDR6HSTR.MergedBits.grpBIT_8
    #define ATDDR6H_BIT ATDDR6H_BIT_8
    
    #define ATDDR6H_BIT8_MASK  1
    #define ATDDR6H_BIT9_MASK  2
    #define ATDDR6H_BIT10_MASK  4
    #define ATDDR6H_BIT11_MASK  8
    #define ATDDR6H_BIT12_MASK  16
    #define ATDDR6H_BIT13_MASK  32
    #define ATDDR6H_BIT14_MASK  64
    #define ATDDR6H_BIT15_MASK  128
    #define ATDDR6H_BIT_8_MASK  255
    #define ATDDR6H_BIT_8_BITNUM  0


    /*** ATDDR6L - ATD Conversion Result Register 6 Lw; 0x0000009D ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR6LSTR;
    #define ATDDR6L _ATDDR6.Overlap_STR.ATDDR6LSTR.Byte
    #define ATDDR6L_BIT6 _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT6
    #define ATDDR6L_BIT7 _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT7
    
    #define ATDDR6L_BIT_6 _ATDDR6.Overlap_STR.ATDDR6LSTR.MergedBits.grpBIT_6
    #define ATDDR6L_BIT ATDDR6L_BIT_6
    
    #define ATDDR6L_BIT6_MASK  64
    #define ATDDR6L_BIT7_MASK  128
    #define ATDDR6L_BIT_6_MASK  192
    #define ATDDR6L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR6STR;
extern volatile ATDDR6STR _ATDDR6 @(REG_BASE + 0x0000009C);
#define ATDDR6 _ATDDR6.Word
#define ATDDR6_BIT6 _ATDDR6.Bits.BIT6
#define ATDDR6_BIT7 _ATDDR6.Bits.BIT7
#define ATDDR6_BIT8 _ATDDR6.Bits.BIT8
#define ATDDR6_BIT9 _ATDDR6.Bits.BIT9
#define ATDDR6_BIT10 _ATDDR6.Bits.BIT10
#define ATDDR6_BIT11 _ATDDR6.Bits.BIT11
#define ATDDR6_BIT12 _ATDDR6.Bits.BIT12
#define ATDDR6_BIT13 _ATDDR6.Bits.BIT13
#define ATDDR6_BIT14 _ATDDR6.Bits.BIT14
#define ATDDR6_BIT15 _ATDDR6.Bits.BIT15
#define ATDDR6_BIT_6 _ATDDR6.MergedBits.grpBIT_6
#define ATDDR6_BIT ATDDR6_BIT_6

#define ATDDR6_BIT6_MASK  64
#define ATDDR6_BIT7_MASK  128
#define ATDDR6_BIT8_MASK  256
#define ATDDR6_BIT9_MASK  512
#define ATDDR6_BIT10_MASK  1024
#define ATDDR6_BIT11_MASK  2048
#define ATDDR6_BIT12_MASK  4096
#define ATDDR6_BIT13_MASK  8192
#define ATDDR6_BIT14_MASK  16384
#define ATDDR6_BIT15_MASK  32768
#define ATDDR6_BIT_6_MASK  65472
#define ATDDR6_BIT_6_BITNUM  6


/*** ATDDR7 - ATD Conversion Result Register 7; 0x0000009E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR7H - ATD Conversion Result Register 7 High; 0x0000009E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
      struct {
        byte grpBIT_8 :8;
      } MergedBits;
    } ATDDR7HSTR;
    #define ATDDR7H _ATDDR7.Overlap_STR.ATDDR7HSTR.Byte
    #define ATDDR7H_BIT8 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT8
    #define ATDDR7H_BIT9 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT9
    #define ATDDR7H_BIT10 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT10
    #define ATDDR7H_BIT11 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT11
    #define ATDDR7H_BIT12 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT12
    #define ATDDR7H_BIT13 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT13
    #define ATDDR7H_BIT14 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT14
    #define ATDDR7H_BIT15 _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT15
    
    #define ATDDR7H_BIT_8 _ATDDR7.Overlap_STR.ATDDR7HSTR.MergedBits.grpBIT_8
    #define ATDDR7H_BIT ATDDR7H_BIT_8
    
    #define ATDDR7H_BIT8_MASK  1
    #define ATDDR7H_BIT9_MASK  2
    #define ATDDR7H_BIT10_MASK  4
    #define ATDDR7H_BIT11_MASK  8
    #define ATDDR7H_BIT12_MASK  16
    #define ATDDR7H_BIT13_MASK  32
    #define ATDDR7H_BIT14_MASK  64
    #define ATDDR7H_BIT15_MASK  128
    #define ATDDR7H_BIT_8_MASK  255
    #define ATDDR7H_BIT_8_BITNUM  0


    /*** ATDDR7L - ATD Conversion Result Register 7 Lw; 0x0000009F ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpBIT_6 :2;
      } MergedBits;
    } ATDDR7LSTR;
    #define ATDDR7L _ATDDR7.Overlap_STR.ATDDR7LSTR.Byte
    #define ATDDR7L_BIT6 _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT6
    #define ATDDR7L_BIT7 _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT7
    
    #define ATDDR7L_BIT_6 _ATDDR7.Overlap_STR.ATDDR7LSTR.MergedBits.grpBIT_6
    #define ATDDR7L_BIT ATDDR7L_BIT_6
    
    #define ATDDR7L_BIT6_MASK  64
    #define ATDDR7L_BIT7_MASK  128
    #define ATDDR7L_BIT_6_MASK  192
    #define ATDDR7L_BIT_6_BITNUM  6

  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
  struct {
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpBIT_6 :10;
  } MergedBits;
} ATDDR7STR;
extern volatile ATDDR7STR _ATDDR7 @(REG_BASE + 0x0000009E);
#define ATDDR7 _ATDDR7.Word
#define ATDDR7_BIT6 _ATDDR7.Bits.BIT6
#define ATDDR7_BIT7 _ATDDR7.Bits.BIT7
#define ATDDR7_BIT8 _ATDDR7.Bits.BIT8
#define ATDDR7_BIT9 _ATDDR7.Bits.BIT9
#define ATDDR7_BIT10 _ATDDR7.Bits.BIT10
#define ATDDR7_BIT11 _ATDDR7.Bits.BIT11
#define ATDDR7_BIT12 _ATDDR7.Bits.BIT12
#define ATDDR7_BIT13 _ATDDR7.Bits.BIT13
#define ATDDR7_BIT14 _ATDDR7.Bits.BIT14
#define ATDDR7_BIT15 _ATDDR7.Bits.BIT15
#define ATDDR7_BIT_6 _ATDDR7.MergedBits.grpBIT_6
#define ATDDR7_BIT ATDDR7_BIT_6

#define ATDDR7_BIT6_MASK  64
#define ATDDR7_BIT7_MASK  128
#define ATDDR7_BIT8_MASK  256
#define ATDDR7_BIT9_MASK  512
#define ATDDR7_BIT10_MASK  1024
#define ATDDR7_BIT11_MASK  2048
#define ATDDR7_BIT12_MASK  4096
#define ATDDR7_BIT13_MASK  8192
#define ATDDR7_BIT14_MASK  16384
#define ATDDR7_BIT15_MASK  32768
#define ATDDR7_BIT_6_MASK  65472
#define ATDDR7_BIT_6_BITNUM  6


/*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0BDH - SCI 0 Baud Rate Register High; 0x000000C8 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* SCI 0 baud rate Bit 8 */
        byte SBR9        :1;                                       /* SCI 0 baud rate Bit 9 */
        byte SBR10       :1;                                       /* SCI 0 baud rate Bit 10 */
        byte SBR11       :1;                                       /* SCI 0 baud rate Bit 11 */
        byte SBR12       :1;                                       /* SCI 0 baud rate Bit 12 */
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI0BDHSTR;
    #define SCI0BDH _SCI0BD.Overlap_STR.SCI0BDHSTR.Byte
    #define SCI0BDH_SBR8 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR8
    #define SCI0BDH_SBR9 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR9
    #define SCI0BDH_SBR10 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR10
    #define SCI0BDH_SBR11 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR11
    #define SCI0BDH_SBR12 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.SBR12
    #define SCI0BDH_TNP0 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.TNP0
    #define SCI0BDH_TNP1 _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.TNP1
    #define SCI0BDH_IREN _SCI0BD.Overlap_STR.SCI0BDHSTR.Bits.IREN
    
    #define SCI0BDH_SBR_8 _SCI0BD.Overlap_STR.SCI0BDHSTR.MergedBits.grpSBR_8
    #define SCI0BDH_TNP _SCI0BD.Overlap_STR.SCI0BDHSTR.MergedBits.grpTNP
    #define SCI0BDH_SBR SCI0BDH_SBR_8
    
    #define SCI0BDH_SBR8_MASK  1
    #define SCI0BDH_SBR9_MASK  2
    #define SCI0BDH_SBR10_MASK  4
    #define SCI0BDH_SBR11_MASK  8
    #define SCI0BDH_SBR12_MASK  16
    #define SCI0BDH_TNP0_MASK  32
    #define SCI0BDH_TNP1_MASK  64
    #define SCI0BDH_IREN_MASK  128
    #define SCI0BDH_SBR_8_MASK  31
    #define SCI0BDH_SBR_8_BITNUM  0
    #define SCI0BDH_TNP_MASK  96
    #define SCI0BDH_TNP_BITNUM  5


    /*** SCI0BDL - SCI 0 Baud Rate Register Lw; 0x000000C9 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* SCI 0 baud rate Bit 0 */
        byte SBR1        :1;                                       /* SCI 0 baud rate Bit 1 */
        byte SBR2        :1;                                       /* SCI 0 baud rate Bit 2 */
        byte SBR3        :1;                                       /* SCI 0 baud rate Bit 3 */
        byte SBR4        :1;                                       /* SCI 0 baud rate Bit 4 */
        byte SBR5        :1;                                       /* SCI 0 baud rate Bit 5 */
        byte SBR6        :1;                                       /* SCI 0 baud rate Bit 6 */
        byte SBR7        :1;                                       /* SCI 0 baud rate Bit 7 */
      } Bits;
      struct {
        byte grpSBR :8;
      } MergedBits;
    } SCI0BDLSTR;
    #define SCI0BDL _SCI0BD.Overlap_STR.SCI0BDLSTR.Byte
    #define SCI0BDL_SBR0 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR0
    #define SCI0BDL_SBR1 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR1
    #define SCI0BDL_SBR2 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR2
    #define SCI0BDL_SBR3 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR3
    #define SCI0BDL_SBR4 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR4
    #define SCI0BDL_SBR5 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR5
    #define SCI0BDL_SBR6 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR6
    #define SCI0BDL_SBR7 _SCI0BD.Overlap_STR.SCI0BDLSTR.Bits.SBR7
    
    #define SCI0BDL_SBR _SCI0BD.Overlap_STR.SCI0BDLSTR.MergedBits.grpSBR
    
    #define SCI0BDL_SBR0_MASK  1
    #define SCI0BDL_SBR1_MASK  2
    #define SCI0BDL_SBR2_MASK  4
    #define SCI0BDL_SBR3_MASK  8
    #define SCI0BDL_SBR4_MASK  16
    #define SCI0BDL_SBR5_MASK  32
    #define SCI0BDL_SBR6_MASK  64
    #define SCI0BDL_SBR7_MASK  128
    #define SCI0BDL_SBR_MASK  255
    #define SCI0BDL_SBR_BITNUM  0

  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI 0 baud rate Bit 0 */
    word SBR1        :1;                                       /* SCI 0 baud rate Bit 1 */
    word SBR2        :1;                                       /* SCI 0 baud rate Bit 2 */
    word SBR3        :1;                                       /* SCI 0 baud rate Bit 3 */
    word SBR4        :1;                                       /* SCI 0 baud rate Bit 4 */
    word SBR5        :1;                                       /* SCI 0 baud rate Bit 5 */
    word SBR6        :1;                                       /* SCI 0 baud rate Bit 6 */
    word SBR7        :1;                                       /* SCI 0 baud rate Bit 7 */
    word SBR8        :1;                                       /* SCI 0 baud rate Bit 8 */
    word SBR9        :1;                                       /* SCI 0 baud rate Bit 9 */
    word SBR10       :1;                                       /* SCI 0 baud rate Bit 10 */
    word SBR11       :1;                                       /* SCI 0 baud rate Bit 11 */
    word SBR12       :1;                                       /* SCI 0 baud rate Bit 12 */
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @(REG_BASE + 0x000000C8);
#define SCI0BD _SCI0BD.Word
#define SCI0BD_SBR0 _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1 _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2 _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3 _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4 _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5 _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6 _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7 _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8 _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9 _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10 _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11 _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12 _SCI0BD.Bits.SBR12
#define SCI0BD_TNP0 _SCI0BD.Bits.TNP0
#define SCI0BD_TNP1 _SCI0BD.Bits.TNP1
#define SCI0BD_IREN _SCI0BD.Bits.IREN
#define SCI0BD_SBR _SCI0BD.MergedBits.grpSBR
#define SCI0BD_TNP _SCI0BD.MergedBits.grpTNP

#define SCI0BD_SBR0_MASK  1
#define SCI0BD_SBR1_MASK  2
#define SCI0BD_SBR2_MASK  4
#define SCI0BD_SBR3_MASK  8
#define SCI0BD_SBR4_MASK  16
#define SCI0BD_SBR5_MASK  32
#define SCI0BD_SBR6_MASK  64
#define SCI0BD_SBR7_MASK  128
#define SCI0BD_SBR8_MASK  256
#define SCI0BD_SBR9_MASK  512
#define SCI0BD_SBR10_MASK  1024
#define SCI0BD_SBR11_MASK  2048
#define SCI0BD_SBR12_MASK  4096
#define SCI0BD_TNP0_MASK  8192
#define SCI0BD_TNP1_MASK  16384
#define SCI0BD_IREN_MASK  32768
#define SCI0BD_SBR_MASK  8191
#define SCI0BD_SBR_BITNUM  0
#define SCI0BD_TNP_MASK  24576
#define SCI0BD_TNP_BITNUM  13


/*** SCI0CR1 - SCI 0 Control Register 1; 0x000000CA ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type Bit */
    byte PE          :1;                                       /* Parity Enable Bit */
    byte ILT         :1;                                       /* Idle Line Type Bit */
    byte WAKE        :1;                                       /* Wakeup Condition Bit */
    byte M           :1;                                       /* Data Format Mode Bit */
    byte RSRC        :1;                                       /* Receiver Source Bit */
    byte SCISWAI     :1;                                       /* SCI 0 Stop in Wait Mode Bit */
    byte LOOPS       :1;                                       /* Lop Select Bit */
  } Bits;
} SCI0CR1STR;
extern volatile SCI0CR1STR _SCI0CR1 @(REG_BASE + 0x000000CA);
#define SCI0CR1 _SCI0CR1.Byte
#define SCI0CR1_PT _SCI0CR1.Bits.PT
#define SCI0CR1_PE _SCI0CR1.Bits.PE
#define SCI0CR1_ILT _SCI0CR1.Bits.ILT
#define SCI0CR1_WAKE _SCI0CR1.Bits.WAKE
#define SCI0CR1_M _SCI0CR1.Bits.M
#define SCI0CR1_RSRC _SCI0CR1.Bits.RSRC
#define SCI0CR1_SCISWAI _SCI0CR1.Bits.SCISWAI
#define SCI0CR1_LOOPS _SCI0CR1.Bits.LOOPS

#define SCI0CR1_PT_MASK  1
#define SCI0CR1_PE_MASK  2
#define SCI0CR1_ILT_MASK  4
#define SCI0CR1_WAKE_MASK  8
#define SCI0CR1_M_MASK  16
#define SCI0CR1_RSRC_MASK  32
#define SCI0CR1_SCISWAI_MASK  64
#define SCI0CR1_LOOPS_MASK  128


/*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte SCTIE       :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @(REG_BASE + 0x000000CB);
#define SCI0CR2 _SCI0CR2.Byte
#define SCI0CR2_SBK _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU _SCI0CR2.Bits.RWU
#define SCI0CR2_RE _SCI0CR2.Bits.RE
#define SCI0CR2_TE _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE _SCI0CR2.Bits.TCIE
#define SCI0CR2_SCTIE _SCI0CR2.Bits.SCTIE

#define SCI0CR2_SBK_MASK  1
#define SCI0CR2_RWU_MASK  2
#define SCI0CR2_RE_MASK  4
#define SCI0CR2_TE_MASK  8
#define SCI0CR2_ILIE_MASK  16
#define SCI0CR2_RIE_MASK  32
#define SCI0CR2_TCIE_MASK  64
#define SCI0CR2_SCTIE_MASK  128


/*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @(REG_BASE + 0x000000CC);
#define SCI0SR1 _SCI0SR1.Byte
#define SCI0SR1_PF _SCI0SR1.Bits.PF
#define SCI0SR1_FE _SCI0SR1.Bits.FE
#define SCI0SR1_NF _SCI0SR1.Bits.NF
#define SCI0SR1_OR _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE _SCI0SR1.Bits.TDRE

#define SCI0SR1_PF_MASK  1
#define SCI0SR1_FE_MASK  2
#define SCI0SR1_NF_MASK  4
#define SCI0SR1_OR_MASK  8
#define SCI0SR1_IDLE_MASK  16
#define SCI0SR1_RDRF_MASK  32
#define SCI0SR1_TC_MASK  64
#define SCI0SR1_TDRE_MASK  128


/*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @(REG_BASE + 0x000000CD);
#define SCI0SR2 _SCI0SR2.Byte
#define SCI0SR2_RAF _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13 _SCI0SR2.Bits.BRK13

#define SCI0SR2_RAF_MASK  1
#define SCI0SR2_TXDIR_MASK  2
#define SCI0SR2_BRK13_MASK  4


/*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @(REG_BASE + 0x000000CE);
#define SCI0DRH _SCI0DRH.Byte
#define SCI0DRH_T8 _SCI0DRH.Bits.T8
#define SCI0DRH_R8 _SCI0DRH.Bits.R8

#define SCI0DRH_T8_MASK  64
#define SCI0DRH_R8_MASK  128


/*** SCI0DRL - SCI 0 Data Register Lw; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @(REG_BASE + 0x000000CF);
#define SCI0DRL _SCI0DRL.Byte
#define SCI0DRL_R0_T0 _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1 _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2 _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3 _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4 _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5 _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6 _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7 _SCI0DRL.Bits.R7_T7

#define SCI0DRL_R0_T0_MASK  1
#define SCI0DRL_R1_T1_MASK  2
#define SCI0DRL_R2_T2_MASK  4
#define SCI0DRL_R3_T3_MASK  8
#define SCI0DRL_R4_T4_MASK  16
#define SCI0DRL_R5_T5_MASK  32
#define SCI0DRL_R6_T6_MASK  64
#define SCI0DRL_R7_T7_MASK  128


/*** SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI 1 Baud Rate Register High; 0x000000D0 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* SCI 1 baud rate Bit 8 */
        byte SBR9        :1;                                       /* SCI 1 baud rate Bit 9 */
        byte SBR10       :1;                                       /* SCI 1 baud rate Bit 10 */
        byte SBR11       :1;                                       /* SCI 1 baud rate Bit 11 */
        byte SBR12       :1;                                       /* SCI 1 baud rate Bit 12 */
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_TNP0 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.TNP0
    #define SCI1BDH_TNP1 _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.TNP1
    #define SCI1BDH_IREN _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.IREN
    
    #define SCI1BDH_SBR_8 _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_TNP _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpTNP
    #define SCI1BDH_SBR SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK  1
    #define SCI1BDH_SBR9_MASK  2
    #define SCI1BDH_SBR10_MASK  4
    #define SCI1BDH_SBR11_MASK  8
    #define SCI1BDH_SBR12_MASK  16
    #define SCI1BDH_TNP0_MASK  32
    #define SCI1BDH_TNP1_MASK  64
    #define SCI1BDH_IREN_MASK  128
    #define SCI1BDH_SBR_8_MASK  31
    #define SCI1BDH_SBR_8_BITNUM  0
    #define SCI1BDH_TNP_MASK  96
    #define SCI1BDH_TNP_BITNUM  5


    /*** SCI1BDL - SCI 1 Baud Rate Register Lw; 0x000000D1 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* SCI 1 baud rate Bit 0 */
        byte SBR1        :1;                                       /* SCI 1 baud rate Bit 1 */
        byte SBR2        :1;                                       /* SCI 1 baud rate Bit 2 */
        byte SBR3        :1;                                       /* SCI 1 baud rate Bit 3 */
        byte SBR4        :1;                                       /* SCI 1 baud rate Bit 4 */
        byte SBR5        :1;                                       /* SCI 1 baud rate Bit 5 */
        byte SBR6        :1;                                       /* SCI 1 baud rate Bit 6 */
        byte SBR7        :1;                                       /* SCI 1 baud rate Bit 7 */
      } Bits;
      struct {
        byte grpSBR :8;
      } MergedBits;
    } SCI1BDLSTR;
    #define SCI1BDL _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7 _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    #define SCI1BDL_SBR _SCI1BD.Overlap_STR.SCI1BDLSTR.MergedBits.grpSBR
    
    #define SCI1BDL_SBR0_MASK  1
    #define SCI1BDL_SBR1_MASK  2
    #define SCI1BDL_SBR2_MASK  4
    #define SCI1BDL_SBR3_MASK  8
    #define SCI1BDL_SBR4_MASK  16
    #define SCI1BDL_SBR5_MASK  32
    #define SCI1BDL_SBR6_MASK  64
    #define SCI1BDL_SBR7_MASK  128
    #define SCI1BDL_SBR_MASK  255
    #define SCI1BDL_SBR_BITNUM  0

  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI 1 baud rate Bit 0 */
    word SBR1        :1;                                       /* SCI 1 baud rate Bit 1 */
    word SBR2        :1;                                       /* SCI 1 baud rate Bit 2 */
    word SBR3        :1;                                       /* SCI 1 baud rate Bit 3 */
    word SBR4        :1;                                       /* SCI 1 baud rate Bit 4 */
    word SBR5        :1;                                       /* SCI 1 baud rate Bit 5 */
    word SBR6        :1;                                       /* SCI 1 baud rate Bit 6 */
    word SBR7        :1;                                       /* SCI 1 baud rate Bit 7 */
    word SBR8        :1;                                       /* SCI 1 baud rate Bit 8 */
    word SBR9        :1;                                       /* SCI 1 baud rate Bit 9 */
    word SBR10       :1;                                       /* SCI 1 baud rate Bit 10 */
    word SBR11       :1;                                       /* SCI 1 baud rate Bit 11 */
    word SBR12       :1;                                       /* SCI 1 baud rate Bit 12 */
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @(REG_BASE + 0x000000D0);
#define SCI1BD _SCI1BD.Word
#define SCI1BD_SBR0 _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1 _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2 _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3 _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4 _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5 _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6 _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7 _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8 _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9 _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10 _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11 _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12 _SCI1BD.Bits.SBR12
#define SCI1BD_TNP0 _SCI1BD.Bits.TNP0
#define SCI1BD_TNP1 _SCI1BD.Bits.TNP1
#define SCI1BD_IREN _SCI1BD.Bits.IREN
#define SCI1BD_SBR _SCI1BD.MergedBits.grpSBR
#define SCI1BD_TNP _SCI1BD.MergedBits.grpTNP

#define SCI1BD_SBR0_MASK  1
#define SCI1BD_SBR1_MASK  2
#define SCI1BD_SBR2_MASK  4
#define SCI1BD_SBR3_MASK  8
#define SCI1BD_SBR4_MASK  16
#define SCI1BD_SBR5_MASK  32
#define SCI1BD_SBR6_MASK  64
#define SCI1BD_SBR7_MASK  128
#define SCI1BD_SBR8_MASK  256
#define SCI1BD_SBR9_MASK  512
#define SCI1BD_SBR10_MASK  1024
#define SCI1BD_SBR11_MASK  2048
#define SCI1BD_SBR12_MASK  4096
#define SCI1BD_TNP0_MASK  8192
#define SCI1BD_TNP1_MASK  16384
#define SCI1BD_IREN_MASK  32768
#define SCI1BD_SBR_MASK  8191
#define SCI1BD_SBR_BITNUM  0
#define SCI1BD_TNP_MASK  24576
#define SCI1BD_TNP_BITNUM  13


/*** SCI1CR1 - SCI 1 Control Register 1; 0x000000D2 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type Bit */
    byte PE          :1;                                       /* Parity Enable Bit */
    byte ILT         :1;                                       /* Idle Line Type Bit */
    byte WAKE        :1;                                       /* Wakeup Condition Bit */
    byte M           :1;                                       /* Data Format Mode Bit */
    byte RSRC        :1;                                       /* Receiver Source Bit */
    byte SCISWAI     :1;                                       /* SCI 1 Stop in Wait Mode Bit */
    byte LOOPS       :1;                                       /* Lop Select Bit */
  } Bits;
} SCI1CR1STR;
extern volatile SCI1CR1STR _SCI1CR1 @(REG_BASE + 0x000000D2);
#define SCI1CR1 _SCI1CR1.Byte
#define SCI1CR1_PT _SCI1CR1.Bits.PT
#define SCI1CR1_PE _SCI1CR1.Bits.PE
#define SCI1CR1_ILT _SCI1CR1.Bits.ILT
#define SCI1CR1_WAKE _SCI1CR1.Bits.WAKE
#define SCI1CR1_M _SCI1CR1.Bits.M
#define SCI1CR1_RSRC _SCI1CR1.Bits.RSRC
#define SCI1CR1_SCISWAI _SCI1CR1.Bits.SCISWAI
#define SCI1CR1_LOOPS _SCI1CR1.Bits.LOOPS

#define SCI1CR1_PT_MASK  1
#define SCI1CR1_PE_MASK  2
#define SCI1CR1_ILT_MASK  4
#define SCI1CR1_WAKE_MASK  8
#define SCI1CR1_M_MASK  16
#define SCI1CR1_RSRC_MASK  32
#define SCI1CR1_SCISWAI_MASK  64
#define SCI1CR1_LOOPS_MASK  128


/*** SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte SCTIE       :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCI1CR2STR;
extern volatile SCI1CR2STR _SCI1CR2 @(REG_BASE + 0x000000D3);
#define SCI1CR2 _SCI1CR2.Byte
#define SCI1CR2_SBK _SCI1CR2.Bits.SBK
#define SCI1CR2_RWU _SCI1CR2.Bits.RWU
#define SCI1CR2_RE _SCI1CR2.Bits.RE
#define SCI1CR2_TE _SCI1CR2.Bits.TE
#define SCI1CR2_ILIE _SCI1CR2.Bits.ILIE
#define SCI1CR2_RIE _SCI1CR2.Bits.RIE
#define SCI1CR2_TCIE _SCI1CR2.Bits.TCIE
#define SCI1CR2_SCTIE _SCI1CR2.Bits.SCTIE

#define SCI1CR2_SBK_MASK  1
#define SCI1CR2_RWU_MASK  2
#define SCI1CR2_RE_MASK  4
#define SCI1CR2_TE_MASK  8
#define SCI1CR2_ILIE_MASK  16
#define SCI1CR2_RIE_MASK  32
#define SCI1CR2_TCIE_MASK  64
#define SCI1CR2_SCTIE_MASK  128


/*** SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1SR1STR;
extern volatile SCI1SR1STR _SCI1SR1 @(REG_BASE + 0x000000D4);
#define SCI1SR1 _SCI1SR1.Byte
#define SCI1SR1_PF _SCI1SR1.Bits.PF
#define SCI1SR1_FE _SCI1SR1.Bits.FE
#define SCI1SR1_NF _SCI1SR1.Bits.NF
#define SCI1SR1_OR _SCI1SR1.Bits.OR
#define SCI1SR1_IDLE _SCI1SR1.Bits.IDLE
#define SCI1SR1_RDRF _SCI1SR1.Bits.RDRF
#define SCI1SR1_TC _SCI1SR1.Bits.TC
#define SCI1SR1_TDRE _SCI1SR1.Bits.TDRE

#define SCI1SR1_PF_MASK  1
#define SCI1SR1_FE_MASK  2
#define SCI1SR1_NF_MASK  4
#define SCI1SR1_OR_MASK  8
#define SCI1SR1_IDLE_MASK  16
#define SCI1SR1_RDRF_MASK  32
#define SCI1SR1_TC_MASK  64
#define SCI1SR1_TDRE_MASK  128


/*** SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCI1SR2STR;
extern volatile SCI1SR2STR _SCI1SR2 @(REG_BASE + 0x000000D5);
#define SCI1SR2 _SCI1SR2.Byte
#define SCI1SR2_RAF _SCI1SR2.Bits.RAF
#define SCI1SR2_TXDIR _SCI1SR2.Bits.TXDIR
#define SCI1SR2_BRK13 _SCI1SR2.Bits.BRK13

#define SCI1SR2_RAF_MASK  1
#define SCI1SR2_TXDIR_MASK  2
#define SCI1SR2_BRK13_MASK  4


/*** SCI1DRH - SCI 1 Data Register High; 0x000000D6 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI1DRHSTR;
extern volatile SCI1DRHSTR _SCI1DRH @(REG_BASE + 0x000000D6);
#define SCI1DRH _SCI1DRH.Byte
#define SCI1DRH_T8 _SCI1DRH.Bits.T8
#define SCI1DRH_R8 _SCI1DRH.Bits.R8

#define SCI1DRH_T8_MASK  64
#define SCI1DRH_R8_MASK  128


/*** SCI1DRL - SCI 1 Data Register Lw; 0x000000D7 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI1DRLSTR;
extern volatile SCI1DRLSTR _SCI1DRL @(REG_BASE + 0x000000D7);
#define SCI1DRL _SCI1DRL.Byte
#define SCI1DRL_R0_T0 _SCI1DRL.Bits.R0_T0
#define SCI1DRL_R1_T1 _SCI1DRL.Bits.R1_T1
#define SCI1DRL_R2_T2 _SCI1DRL.Bits.R2_T2
#define SCI1DRL_R3_T3 _SCI1DRL.Bits.R3_T3
#define SCI1DRL_R4_T4 _SCI1DRL.Bits.R4_T4
#define SCI1DRL_R5_T5 _SCI1DRL.Bits.R5_T5
#define SCI1DRL_R6_T6 _SCI1DRL.Bits.R6_T6
#define SCI1DRL_R7_T7 _SCI1DRL.Bits.R7_T7

#define SCI1DRL_R0_T0_MASK  1
#define SCI1DRL_R1_T1_MASK  2
#define SCI1DRL_R2_T2_MASK  4
#define SCI1DRL_R3_T3_MASK  8
#define SCI1DRL_R4_T4_MASK  16
#define SCI1DRL_R5_T5_MASK  32
#define SCI1DRL_R6_T6_MASK  64
#define SCI1DRL_R7_T7_MASK  128


/*** SPICR1 - SPI Control Register; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPICR1STR;
extern volatile SPICR1STR _SPICR1 @(REG_BASE + 0x000000D8);
#define SPICR1 _SPICR1.Byte
#define SPICR1_LSBFE _SPICR1.Bits.LSBFE
#define SPICR1_SSOE _SPICR1.Bits.SSOE
#define SPICR1_CPHA _SPICR1.Bits.CPHA
#define SPICR1_CPOL _SPICR1.Bits.CPOL
#define SPICR1_MSTR _SPICR1.Bits.MSTR
#define SPICR1_SPTIE _SPICR1.Bits.SPTIE
#define SPICR1_SPE _SPICR1.Bits.SPE
#define SPICR1_SPIE _SPICR1.Bits.SPIE

#define SPICR1_LSBFE_MASK  1
#define SPICR1_SSOE_MASK  2
#define SPICR1_CPHA_MASK  4
#define SPICR1_CPOL_MASK  8
#define SPICR1_MSTR_MASK  16
#define SPICR1_SPTIE_MASK  32
#define SPICR1_SPE_MASK  64
#define SPICR1_SPIE_MASK  128


/*** SPICR2 - SPI Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPICR2STR;
extern volatile SPICR2STR _SPICR2 @(REG_BASE + 0x000000D9);
#define SPICR2 _SPICR2.Byte
#define SPICR2_SPC0 _SPICR2.Bits.SPC0
#define SPICR2_SPISWAI _SPICR2.Bits.SPISWAI
#define SPICR2_BIDIROE _SPICR2.Bits.BIDIROE
#define SPICR2_MODFEN _SPICR2.Bits.MODFEN

#define SPICR2_SPC0_MASK  1
#define SPICR2_SPISWAI_MASK  2
#define SPICR2_BIDIROE_MASK  8
#define SPICR2_MODFEN_MASK  16


/*** SPIBR - SPI Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @(REG_BASE + 0x000000DA);
#define SPIBR _SPIBR.Byte
#define SPIBR_SPR0 _SPIBR.Bits.SPR0
#define SPIBR_SPR1 _SPIBR.Bits.SPR1
#define SPIBR_SPR2 _SPIBR.Bits.SPR2
#define SPIBR_SPPR0 _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1 _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2 _SPIBR.Bits.SPPR2
#define SPIBR_SPR _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK  1
#define SPIBR_SPR1_MASK  2
#define SPIBR_SPR2_MASK  4
#define SPIBR_SPPR0_MASK  16
#define SPIBR_SPPR1_MASK  32
#define SPIBR_SPPR2_MASK  64
#define SPIBR_SPR_MASK  7
#define SPIBR_SPR_BITNUM  0
#define SPIBR_SPPR_MASK  112
#define SPIBR_SPPR_BITNUM  4


/*** SPISR - SPI Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPISRSTR;
extern volatile SPISRSTR _SPISR @(REG_BASE + 0x000000DB);
#define SPISR _SPISR.Byte
#define SPISR_MODF _SPISR.Bits.MODF
#define SPISR_SPTEF _SPISR.Bits.SPTEF
#define SPISR_SPIF _SPISR.Bits.SPIF

#define SPISR_MODF_MASK  16
#define SPISR_SPTEF_MASK  32
#define SPISR_SPIF_MASK  128


/*** SPIDR - SPI Data Register; 0x000000DD ***/
typedef union {
  byte Byte;
  struct {
    byte grpBIT  :8;
  } MergedBits;
} SPIDRSTR;
extern volatile SPIDRSTR _SPIDR @(REG_BASE + 0x000000DD);
#define SPIDR _SPIDR.Byte
#define SPIDR_BIT _SPIDR.MergedBits.grpBIT

#define SPIDR_BIT_MASK  255
#define SPIDR_BIT_BITNUM  0


/*** IBAD - IIC Address Register; 0x000000E0 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte ADR1        :1;                                       /* Slave Address Bit 1 */
    byte ADR2        :1;                                       /* Slave Address Bit 2 */
    byte ADR3        :1;                                       /* Slave Address Bit 3 */
    byte ADR4        :1;                                       /* Slave Address Bit 4 */
    byte ADR5        :1;                                       /* Slave Address Bit 5 */
    byte ADR6        :1;                                       /* Slave Address Bit 6 */
    byte ADR7        :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpADR_1 :7;
  } MergedBits;
} IBADSTR;
extern volatile IBADSTR _IBAD @(REG_BASE + 0x000000E0);
#define IBAD _IBAD.Byte
#define IBAD_ADR1 _IBAD.Bits.ADR1
#define IBAD_ADR2 _IBAD.Bits.ADR2
#define IBAD_ADR3 _IBAD.Bits.ADR3
#define IBAD_ADR4 _IBAD.Bits.ADR4
#define IBAD_ADR5 _IBAD.Bits.ADR5
#define IBAD_ADR6 _IBAD.Bits.ADR6
#define IBAD_ADR7 _IBAD.Bits.ADR7
#define IBAD_ADR_1 _IBAD.MergedBits.grpADR_1
#define IBAD_ADR IBAD_ADR_1

#define IBAD_ADR1_MASK  2
#define IBAD_ADR2_MASK  4
#define IBAD_ADR3_MASK  8
#define IBAD_ADR4_MASK  16
#define IBAD_ADR5_MASK  32
#define IBAD_ADR6_MASK  64
#define IBAD_ADR7_MASK  128
#define IBAD_ADR_1_MASK  254
#define IBAD_ADR_1_BITNUM  1


/*** IBFD - IIC Frequency Divider Register; 0x000000E1 ***/
typedef union {
  byte Byte;
  struct {
    byte IBC0        :1;                                       /* I-Bus Clock Rate 0 */
    byte IBC1        :1;                                       /* I-Bus Clock Rate 1 */
    byte IBC2        :1;                                       /* I-Bus Clock Rate 2 */
    byte IBC3        :1;                                       /* I-Bus Clock Rate 3 */
    byte IBC4        :1;                                       /* I-Bus Clock Rate 4 */
    byte IBC5        :1;                                       /* I-Bus Clock Rate 5 */
    byte IBC6        :1;                                       /* I-Bus Clock Rate 6 */
    byte IBC7        :1;                                       /* I-Bus Clock Rate 7 */
  } Bits;
  struct {
    byte grpIBC  :8;
  } MergedBits;
} IBFDSTR;
extern volatile IBFDSTR _IBFD @(REG_BASE + 0x000000E1);
#define IBFD _IBFD.Byte
#define IBFD_IBC0 _IBFD.Bits.IBC0
#define IBFD_IBC1 _IBFD.Bits.IBC1
#define IBFD_IBC2 _IBFD.Bits.IBC2
#define IBFD_IBC3 _IBFD.Bits.IBC3
#define IBFD_IBC4 _IBFD.Bits.IBC4
#define IBFD_IBC5 _IBFD.Bits.IBC5
#define IBFD_IBC6 _IBFD.Bits.IBC6
#define IBFD_IBC7 _IBFD.Bits.IBC7
#define IBFD_IBC _IBFD.MergedBits.grpIBC

#define IBFD_IBC0_MASK  1
#define IBFD_IBC1_MASK  2
#define IBFD_IBC2_MASK  4
#define IBFD_IBC3_MASK  8
#define IBFD_IBC4_MASK  16
#define IBFD_IBC5_MASK  32
#define IBFD_IBC6_MASK  64
#define IBFD_IBC7_MASK  128
#define IBFD_IBC_MASK  255
#define IBFD_IBC_BITNUM  0


/*** IBCR - IIC Control Register; 0x000000E2 ***/
typedef union {
  byte Byte;
  struct {
    byte IBSWAI      :1;                                       /* I-Bus Interface Stop in WAIT mode */
    byte             :1; 
    byte RSTA        :1;                                       /* Repeat Start */
    byte TXAK        :1;                                       /* Transmit Acknowledge enable */
    byte TX_RX       :1;                                       /* Transmit/Receive mode select bit */
    byte MS_SL       :1;                                       /* Master/Slave mode select bit */
    byte IBIE        :1;                                       /* I-Bus Interrupt Enable */
    byte IBEN        :1;                                       /* I-Bus Enable */
  } Bits;
} IBCRSTR;
extern volatile IBCRSTR _IBCR @(REG_BASE + 0x000000E2);
#define IBCR _IBCR.Byte
#define IBCR_IBSWAI _IBCR.Bits.IBSWAI
#define IBCR_RSTA _IBCR.Bits.RSTA
#define IBCR_TXAK _IBCR.Bits.TXAK
#define IBCR_TX_RX _IBCR.Bits.TX_RX
#define IBCR_MS_SL _IBCR.Bits.MS_SL
#define IBCR_IBIE _IBCR.Bits.IBIE
#define IBCR_IBEN _IBCR.Bits.IBEN

#define IBCR_IBSWAI_MASK  1
#define IBCR_RSTA_MASK  4
#define IBCR_TXAK_MASK  8
#define IBCR_TX_RX_MASK  16
#define IBCR_MS_SL_MASK  32
#define IBCR_IBIE_MASK  64
#define IBCR_IBEN_MASK  128


/*** IBSR - IIC Status Register; 0x000000E3 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Received Acknowledge */
    byte IBIF        :1;                                       /* I-Bus Interrupt */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte IBAL        :1;                                       /* Arbitration Lst */
    byte IBB         :1;                                       /* Bus busy bit */
    byte IAAS        :1;                                       /* Addressed as a slave bit */
    byte TCF         :1;                                       /* Data transferring bit */
  } Bits;
} IBSRSTR;
extern volatile IBSRSTR _IBSR @(REG_BASE + 0x000000E3);
#define IBSR _IBSR.Byte
#define IBSR_RXAK _IBSR.Bits.RXAK
#define IBSR_IBIF _IBSR.Bits.IBIF
#define IBSR_SRW _IBSR.Bits.SRW
#define IBSR_IBAL _IBSR.Bits.IBAL
#define IBSR_IBB _IBSR.Bits.IBB
#define IBSR_IAAS _IBSR.Bits.IAAS
#define IBSR_TCF _IBSR.Bits.TCF

#define IBSR_RXAK_MASK  1
#define IBSR_IBIF_MASK  2
#define IBSR_SRW_MASK  4
#define IBSR_IBAL_MASK  16
#define IBSR_IBB_MASK  32
#define IBSR_IAAS_MASK  64
#define IBSR_TCF_MASK  128


/*** IBDR - IIC Data I/O Register; 0x000000E4 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* IIC Data Bit 0 */
    byte D1          :1;                                       /* IIC Data Bit 1 */
    byte D2          :1;                                       /* IIC Data Bit 2 */
    byte D3          :1;                                       /* IIC Data Bit 3 */
    byte D4          :1;                                       /* IIC Data Bit 4 */
    byte D5          :1;                                       /* IIC Data Bit 5 */
    byte D6          :1;                                       /* IIC Data Bit 6 */
    byte D7          :1;                                       /* IIC Data Bit 7 */
  } Bits;
  struct {
    byte grpD    :8;
  } MergedBits;
} IBDRSTR;
extern volatile IBDRSTR _IBDR @(REG_BASE + 0x000000E4);
#define IBDR _IBDR.Byte
#define IBDR_D0 _IBDR.Bits.D0
#define IBDR_D1 _IBDR.Bits.D1
#define IBDR_D2 _IBDR.Bits.D2
#define IBDR_D3 _IBDR.Bits.D3
#define IBDR_D4 _IBDR.Bits.D4
#define IBDR_D5 _IBDR.Bits.D5
#define IBDR_D6 _IBDR.Bits.D6
#define IBDR_D7 _IBDR.Bits.D7
#define IBDR_D _IBDR.MergedBits.grpD

#define IBDR_D0_MASK  1
#define IBDR_D1_MASK  2
#define IBDR_D2_MASK  4
#define IBDR_D3_MASK  8
#define IBDR_D4_MASK  16
#define IBDR_D5_MASK  32
#define IBDR_D6_MASK  64
#define IBDR_D7_MASK  128
#define IBDR_D_MASK  255
#define IBDR_D_BITNUM  0


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Flash Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Flash Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Flash Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Flash Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Flash Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Flash Clock Divider Bit 5 */
    byte PRDIV8      :1;                                       /* Enable Prescaler by 8 */
    byte FDIVLD      :1;                                       /* Flash Clock Divider Laded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100);
#define FCLKDIV _FCLKDIV.Byte
#define FCLKDIV_FDIV0 _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1 _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2 _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3 _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4 _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5 _FCLKDIV.Bits.FDIV5
#define FCLKDIV_PRDIV8 _FCLKDIV.Bits.PRDIV8
#define FCLKDIV_FDIVLD _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK  1
#define FCLKDIV_FDIV1_MASK  2
#define FCLKDIV_FDIV2_MASK  4
#define FCLKDIV_FDIV3_MASK  8
#define FCLKDIV_FDIV4_MASK  16
#define FCLKDIV_FDIV5_MASK  32
#define FCLKDIV_PRDIV8_MASK  64
#define FCLKDIV_FDIVLD_MASK  128
#define FCLKDIV_FDIV_MASK  63
#define FCLKDIV_FDIV_BITNUM  0


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Memory security bit 0 */
    byte SEC1        :1;                                       /* Memory security bit 1 */
    byte NV2         :1;                                       /* Non Volatile flag bit 2 */
    byte NV3         :1;                                       /* Non Volatile flag bit 3 */
    byte NV4         :1;                                       /* Non Volatile flag bit 4 */
    byte NV5         :1;                                       /* Non Volatile flag bit 5 */
    byte NV6         :1;                                       /* Non Volatile flag bit 6 */
    byte KEYEN       :1;                                       /* Enable backdoor key to security */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpNV_2 :5;
    byte         :1;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101);
#define FSEC _FSEC.Byte
#define FSEC_SEC0 _FSEC.Bits.SEC0
#define FSEC_SEC1 _FSEC.Bits.SEC1
#define FSEC_NV2 _FSEC.Bits.NV2
#define FSEC_NV3 _FSEC.Bits.NV3
#define FSEC_NV4 _FSEC.Bits.NV4
#define FSEC_NV5 _FSEC.Bits.NV5
#define FSEC_NV6 _FSEC.Bits.NV6
#define FSEC_KEYEN _FSEC.Bits.KEYEN
#define FSEC_SEC _FSEC.MergedBits.grpSEC
#define FSEC_NV_2 _FSEC.MergedBits.grpNV_2
#define FSEC_NV FSEC_NV_2

#define FSEC_SEC0_MASK  1
#define FSEC_SEC1_MASK  2
#define FSEC_NV2_MASK  4
#define FSEC_NV3_MASK  8
#define FSEC_NV4_MASK  16
#define FSEC_NV5_MASK  32
#define FSEC_NV6_MASK  64
#define FSEC_KEYEN_MASK  128
#define FSEC_SEC_MASK  3
#define FSEC_SEC_BITNUM  0
#define FSEC_NV_2_MASK  124
#define FSEC_NV_2_BITNUM  2


/*** FCNFG - Flash Configuration Register; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
    byte CBEIE       :1;                                       /* Command Buffers Empty Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000103);
#define FCNFG _FCNFG.Byte
#define FCNFG_KEYACC _FCNFG.Bits.KEYACC
#define FCNFG_CCIE _FCNFG.Bits.CCIE
#define FCNFG_CBEIE _FCNFG.Bits.CBEIE

#define FCNFG_KEYACC_MASK  32
#define FCNFG_CCIE_MASK  64
#define FCNFG_CBEIE_MASK  128


/*** FPROT - Flash Protection Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lwer Address size 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lwer Address size 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lwer address range disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher address size 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher address size 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher address range disable */
    byte NV6         :1;                                       /* Non Volatile Flag Bit */
    byte FPOPEN      :1;                                       /* Opens the flash block or subsections of it for program or erase */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000104);
#define FPROT _FPROT.Byte
#define FPROT_FPLS0 _FPROT.Bits.FPLS0
#define FPROT_FPLS1 _FPROT.Bits.FPLS1
#define FPROT_FPLDIS _FPROT.Bits.FPLDIS
#define FPROT_FPHS0 _FPROT.Bits.FPHS0
#define FPROT_FPHS1 _FPROT.Bits.FPHS1
#define FPROT_FPHDIS _FPROT.Bits.FPHDIS
#define FPROT_NV6 _FPROT.Bits.NV6
#define FPROT_FPOPEN _FPROT.Bits.FPOPEN
#define FPROT_FPLS _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK  1
#define FPROT_FPLS1_MASK  2
#define FPROT_FPLDIS_MASK  4
#define FPROT_FPHS0_MASK  8
#define FPROT_FPHS1_MASK  16
#define FPROT_FPHDIS_MASK  32
#define FPROT_NV6_MASK  64
#define FPROT_FPOPEN_MASK  128
#define FPROT_FPLS_MASK  3
#define FPROT_FPLS_BITNUM  0
#define FPROT_FPHS_MASK  24
#define FPROT_FPHS_BITNUM  3


/*** FSTAT - Flash Status Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte BLANK       :1;                                       /* Blank Verify Flag */
    byte             :1; 
    byte ACCERR      :1;                                       /* Access error */
    byte PVIOL       :1;                                       /* Protection violation */
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
    byte CBEIF       :1;                                       /* Command Buffers Empty Interrupt Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000105);
#define FSTAT _FSTAT.Byte
#define FSTAT_BLANK _FSTAT.Bits.BLANK
#define FSTAT_ACCERR _FSTAT.Bits.ACCERR
#define FSTAT_PVIOL _FSTAT.Bits.PVIOL
#define FSTAT_CCIF _FSTAT.Bits.CCIF
#define FSTAT_CBEIF _FSTAT.Bits.CBEIF

#define FSTAT_BLANK_MASK  4
#define FSTAT_ACCERR_MASK  16
#define FSTAT_PVIOL_MASK  32
#define FSTAT_CCIF_MASK  64
#define FSTAT_CBEIF_MASK  128


/*** FCMD - Flash Command Buffer and Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDB0       :1;                                       /* NVM User Mode Command Bit 0 */
    byte             :1; 
    byte CMDB2       :1;                                       /* NVM User Mode Command Bit 2 */
    byte             :1; 
    byte             :1; 
    byte CMDB5       :1;                                       /* NVM User Mode Command Bit 5 */
    byte CMDB6       :1;                                       /* NVM User Mode Command Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpCMDB :1;
    byte         :1;
    byte grpCMDB_2 :1;
    byte         :1;
    byte         :1;
    byte grpCMDB_5 :2;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @(REG_BASE + 0x00000106);
#define FCMD _FCMD.Byte
#define FCMD_CMDB0 _FCMD.Bits.CMDB0
#define FCMD_CMDB2 _FCMD.Bits.CMDB2
#define FCMD_CMDB5 _FCMD.Bits.CMDB5
#define FCMD_CMDB6 _FCMD.Bits.CMDB6
#define FCMD_CMDB_5 _FCMD.MergedBits.grpCMDB_5
#define FCMD_CMDB FCMD_CMDB_5

#define FCMD_CMDB0_MASK  1
#define FCMD_CMDB2_MASK  4
#define FCMD_CMDB5_MASK  32
#define FCMD_CMDB6_MASK  64
#define FCMD_CMDB_5_MASK  96
#define FCMD_CMDB_5_BITNUM  5


/*** EPHYCTL0 - Ethernet Physical Transceiver Control Register 0; 0x00000120 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHYIEN     :1;                                       /* EPHY Interrupt Enable */
    byte             :1; 
    byte EPHYWAI     :1;                                       /* EPHY Module Stops While in Wait */
    byte LEDEN       :1;                                       /* LED Drive Enable */
    byte DIS10       :1;                                       /* Disable 10BaseT PLL */
    byte DIS100      :1;                                       /* Disable 100 Base-TX PLL */
    byte ANDIS       :1;                                       /* Auto Negotiation Disable */
    byte EPHYEN      :1;                                       /* EPHY Enable */
  } Bits;
} EPHYCTL0STR;
extern volatile EPHYCTL0STR _EPHYCTL0 @(REG_BASE + 0x00000120);
#define EPHYCTL0 _EPHYCTL0.Byte
#define EPHYCTL0_EPHYIEN _EPHYCTL0.Bits.EPHYIEN
#define EPHYCTL0_EPHYWAI _EPHYCTL0.Bits.EPHYWAI
#define EPHYCTL0_LEDEN _EPHYCTL0.Bits.LEDEN
#define EPHYCTL0_DIS10 _EPHYCTL0.Bits.DIS10
#define EPHYCTL0_DIS100 _EPHYCTL0.Bits.DIS100
#define EPHYCTL0_ANDIS _EPHYCTL0.Bits.ANDIS
#define EPHYCTL0_EPHYEN _EPHYCTL0.Bits.EPHYEN

#define EPHYCTL0_EPHYIEN_MASK  1
#define EPHYCTL0_EPHYWAI_MASK  4
#define EPHYCTL0_LEDEN_MASK  8
#define EPHYCTL0_DIS10_MASK  16
#define EPHYCTL0_DIS100_MASK  32
#define EPHYCTL0_ANDIS_MASK  64
#define EPHYCTL0_EPHYEN_MASK  128


/*** EPHYCTL1 - Ethernet Physical Transceiver Control Register 1; 0x00000121 ***/
typedef union {
  byte Byte;
  struct {
    byte PHYADD0     :1;                                       /* EPHY Address for MII Request Bit 0 */
    byte PHYADD1     :1;                                       /* EPHY Address for MII Request Bit 1 */
    byte PHYADD2     :1;                                       /* EPHY Address for MII Request Bit 2 */
    byte PHYADD3     :1;                                       /* EPHY Address for MII Request Bit 3 */
    byte PHYADD4     :1;                                       /* EPHY Address for MII Request Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPHYADD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} EPHYCTL1STR;
extern volatile EPHYCTL1STR _EPHYCTL1 @(REG_BASE + 0x00000121);
#define EPHYCTL1 _EPHYCTL1.Byte
#define EPHYCTL1_PHYADD0 _EPHYCTL1.Bits.PHYADD0
#define EPHYCTL1_PHYADD1 _EPHYCTL1.Bits.PHYADD1
#define EPHYCTL1_PHYADD2 _EPHYCTL1.Bits.PHYADD2
#define EPHYCTL1_PHYADD3 _EPHYCTL1.Bits.PHYADD3
#define EPHYCTL1_PHYADD4 _EPHYCTL1.Bits.PHYADD4
#define EPHYCTL1_PHYADD _EPHYCTL1.MergedBits.grpPHYADD

#define EPHYCTL1_PHYADD0_MASK  1
#define EPHYCTL1_PHYADD1_MASK  2
#define EPHYCTL1_PHYADD2_MASK  4
#define EPHYCTL1_PHYADD3_MASK  8
#define EPHYCTL1_PHYADD4_MASK  16
#define EPHYCTL1_PHYADD_MASK  31
#define EPHYCTL1_PHYADD_BITNUM  0


/*** EPHYSR - Ethernet Physical Transceiver Status Register; 0x00000122 ***/
typedef union {
  byte Byte;
  struct {
    byte EPHYIF      :1;                                       /* EPHY Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte _10DIS      :1;                                       /* EPHY Port Base 10X mode status */
    byte _100DIS     :1;                                       /* EPHY Port Base 100X mode status */
    byte             :1; 
    byte             :1; 
  } Bits;
} EPHYSRSTR;
extern volatile EPHYSRSTR _EPHYSR @(REG_BASE + 0x00000122);
#define EPHYSR _EPHYSR.Byte
#define EPHYSR_EPHYIF _EPHYSR.Bits.EPHYIF
#define EPHYSR__10DIS _EPHYSR.Bits._10DIS
#define EPHYSR__100DIS _EPHYSR.Bits._100DIS

#define EPHYSR_EPHYIF_MASK  1
#define EPHYSR__10DIS_MASK  16
#define EPHYSR__100DIS_MASK  32


/*** NETCTL - Network Control; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte FDX         :1;                                       /* Full Duplex */
    byte MLB         :1;                                       /* MAC Lopback */
    byte EXTPHY      :1;                                       /* External PHY */
    byte ESWAI       :1;                                       /* EMAC Disabled during WAIT Mode */
    byte             :1; 
    byte             :1; 
    byte EMACE       :1;                                       /* EMAC Enable */
  } Bits;
} NETCTLSTR;
extern volatile NETCTLSTR _NETCTL @(REG_BASE + 0x00000140);
#define NETCTL _NETCTL.Byte
#define NETCTL_FDX _NETCTL.Bits.FDX
#define NETCTL_MLB _NETCTL.Bits.MLB
#define NETCTL_EXTPHY _NETCTL.Bits.EXTPHY
#define NETCTL_ESWAI _NETCTL.Bits.ESWAI
#define NETCTL_EMACE _NETCTL.Bits.EMACE

#define NETCTL_FDX_MASK  2
#define NETCTL_MLB_MASK  4
#define NETCTL_EXTPHY_MASK  8
#define NETCTL_ESWAI_MASK  16
#define NETCTL_EMACE_MASK  128


/*** RXCTS - Receive Control and Status; 0x00000143 ***/
typedef union {
  byte Byte;
  struct {
    byte BCREJ       :1;                                       /* Broadcast Reject */
    byte CONMC       :1;                                       /* Conditional Multicast */
    byte PROM        :1;                                       /* Promiscuous Mode */
    byte             :1; 
    byte RFCE        :1;                                       /* Reception Flow Control Enable */
    byte             :1; 
    byte             :1; 
    byte RXACT       :1;                                       /* Receiver Active Status */
  } Bits;
} RXCTSSTR;
extern volatile RXCTSSTR _RXCTS @(REG_BASE + 0x00000143);
#define RXCTS _RXCTS.Byte
#define RXCTS_BCREJ _RXCTS.Bits.BCREJ
#define RXCTS_CONMC _RXCTS.Bits.CONMC
#define RXCTS_PROM _RXCTS.Bits.PROM
#define RXCTS_RFCE _RXCTS.Bits.RFCE
#define RXCTS_RXACT _RXCTS.Bits.RXACT

#define RXCTS_BCREJ_MASK  1
#define RXCTS_CONMC_MASK  2
#define RXCTS_PROM_MASK  4
#define RXCTS_RFCE_MASK  16
#define RXCTS_RXACT_MASK  128


/*** TXCTS - Transmit Control and Status; 0x00000144 ***/
typedef union {
  byte Byte;
  struct {
    byte TCMD0       :1;                                       /* Transmit Command Bit 0 */
    byte TCMD1       :1;                                       /* Transmit Command Bit 1 */
    byte             :1; 
    byte SSB         :1;                                       /* Single Slot Backoff */
    byte PTRC        :1;                                       /* PAUSE Timer Register Control */
    byte CSLF        :1;                                       /* Carrier Sense Lst Flag */
    byte             :1; 
    byte TXACT       :1;                                       /* Transmitter Active */
  } Bits;
  struct {
    byte grpTCMD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TXCTSSTR;
extern volatile TXCTSSTR _TXCTS @(REG_BASE + 0x00000144);
#define TXCTS _TXCTS.Byte
#define TXCTS_TCMD0 _TXCTS.Bits.TCMD0
#define TXCTS_TCMD1 _TXCTS.Bits.TCMD1
#define TXCTS_SSB _TXCTS.Bits.SSB
#define TXCTS_PTRC _TXCTS.Bits.PTRC
#define TXCTS_CSLF _TXCTS.Bits.CSLF
#define TXCTS_TXACT _TXCTS.Bits.TXACT
#define TXCTS_TCMD _TXCTS.MergedBits.grpTCMD

#define TXCTS_TCMD0_MASK  1
#define TXCTS_TCMD1_MASK  2
#define TXCTS_SSB_MASK  8
#define TXCTS_PTRC_MASK  16
#define TXCTS_CSLF_MASK  32
#define TXCTS_TXACT_MASK  128
#define TXCTS_TCMD_MASK  3
#define TXCTS_TCMD_BITNUM  0


/*** ETCTL - Ethertype Control; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte FIEEE       :1;                                       /* IEEE802.3 Length Field Ethertype */
    byte FIPV4       :1;                                       /* Internet Protocol Version 4 (IPv4) Ethertype */
    byte FARP        :1;                                       /* Address Resolution Protocol (ARP) Ethertype */
    byte FIPV6       :1;                                       /* Internet Protocol Version 6 (IPv6) Ethertype */
    byte FEMW        :1;                                       /* Emware Ethertype */
    byte             :1; 
    byte             :1; 
    byte FPET        :1;                                       /* Programmable Ethertype */
  } Bits;
} ETCTLSTR;
extern volatile ETCTLSTR _ETCTL @(REG_BASE + 0x00000145);
#define ETCTL                           _ETCTL.Byte
#define ETCTL_FIEEE                     _ETCTL.Bits.FIEEE
#define ETCTL_FIPV4                     _ETCTL.Bits.FIPV4
#define ETCTL_FARP                      _ETCTL.Bits.FARP
#define ETCTL_FIPV6                     _ETCTL.Bits.FIPV6
#define ETCTL_FEMW                      _ETCTL.Bits.FEMW
#define ETCTL_FPET                      _ETCTL.Bits.FPET

#define ETCTL_FIEEE_MASK                1
#define ETCTL_FIPV4_MASK                2
#define ETCTL_FARP_MASK                 4
#define ETCTL_FIPV6_MASK                8
#define ETCTL_FEMW_MASK                 16
#define ETCTL_FPET_MASK                 128


/*** ETYPE - Programmable Ethertype; 0x00000146 ***/
typedef union {
  word Word;
  struct {
    word ETYPE0      :1;                                       /* Programmable Ethertype Bit 0 */
    word ETYPE1      :1;                                       /* Programmable Ethertype Bit 1 */
    word ETYPE2      :1;                                       /* Programmable Ethertype Bit 2 */
    word ETYPE3      :1;                                       /* Programmable Ethertype Bit 3 */
    word ETYPE4      :1;                                       /* Programmable Ethertype Bit 4 */
    word ETYPE5      :1;                                       /* Programmable Ethertype Bit 5 */
    word ETYPE6      :1;                                       /* Programmable Ethertype Bit 6 */
    word ETYPE7      :1;                                       /* Programmable Ethertype Bit 7 */
    word ETYPE8      :1;                                       /* Programmable Ethertype Bit 8 */
    word ETYPE9      :1;                                       /* Programmable Ethertype Bit 9 */
    word ETYPE10     :1;                                       /* Programmable Ethertype Bit 10 */
    word ETYPE11     :1;                                       /* Programmable Ethertype Bit 11 */
    word ETYPE12     :1;                                       /* Programmable Ethertype Bit 12 */
    word ETYPE13     :1;                                       /* Programmable Ethertype Bit 13 */
    word ETYPE14     :1;                                       /* Programmable Ethertype Bit 14 */
    word ETYPE15     :1;                                       /* Programmable Ethertype Bit 15 */
  } Bits;
  struct {
    word grpETYPE :16;
  } MergedBits;
} ETYPESTR;
extern volatile ETYPESTR _ETYPE @(REG_BASE + 0x00000146);
#define ETYPE _ETYPE.Word
#define ETYPE_ETYPE0 _ETYPE.Bits.ETYPE0
#define ETYPE_ETYPE1 _ETYPE.Bits.ETYPE1
#define ETYPE_ETYPE2 _ETYPE.Bits.ETYPE2
#define ETYPE_ETYPE3 _ETYPE.Bits.ETYPE3
#define ETYPE_ETYPE4 _ETYPE.Bits.ETYPE4
#define ETYPE_ETYPE5 _ETYPE.Bits.ETYPE5
#define ETYPE_ETYPE6 _ETYPE.Bits.ETYPE6
#define ETYPE_ETYPE7 _ETYPE.Bits.ETYPE7
#define ETYPE_ETYPE8 _ETYPE.Bits.ETYPE8
#define ETYPE_ETYPE9 _ETYPE.Bits.ETYPE9
#define ETYPE_ETYPE10 _ETYPE.Bits.ETYPE10
#define ETYPE_ETYPE11 _ETYPE.Bits.ETYPE11
#define ETYPE_ETYPE12 _ETYPE.Bits.ETYPE12
#define ETYPE_ETYPE13 _ETYPE.Bits.ETYPE13
#define ETYPE_ETYPE14 _ETYPE.Bits.ETYPE14
#define ETYPE_ETYPE15 _ETYPE.Bits.ETYPE15
#define ETYPE_ETYPE _ETYPE.MergedBits.grpETYPE

#define ETYPE_ETYPE0_MASK  1
#define ETYPE_ETYPE1_MASK  2
#define ETYPE_ETYPE2_MASK  4
#define ETYPE_ETYPE3_MASK  8
#define ETYPE_ETYPE4_MASK  16
#define ETYPE_ETYPE5_MASK  32
#define ETYPE_ETYPE6_MASK  64
#define ETYPE_ETYPE7_MASK  128
#define ETYPE_ETYPE8_MASK  256
#define ETYPE_ETYPE9_MASK  512
#define ETYPE_ETYPE10_MASK  1024
#define ETYPE_ETYPE11_MASK  2048
#define ETYPE_ETYPE12_MASK  4096
#define ETYPE_ETYPE13_MASK  8192
#define ETYPE_ETYPE14_MASK  16384
#define ETYPE_ETYPE15_MASK  32768
#define ETYPE_ETYPE_MASK  65535
#define ETYPE_ETYPE_BITNUM  0


/*** PTIME - PAUSE Timer Value and Counter; 0x00000148 ***/
typedef union {
  word Word;
  struct {
    word PTIME0      :1;                                       /* PAUSE Timer Value and Counter Bit 0 */
    word PTIME1      :1;                                       /* PAUSE Timer Value and Counter Bit 1 */
    word PTIME2      :1;                                       /* PAUSE Timer Value and Counter Bit 2 */
    word PTIME3      :1;                                       /* PAUSE Timer Value and Counter Bit 3 */
    word PTIME4      :1;                                       /* PAUSE Timer Value and Counter Bit 4 */
    word PTIME5      :1;                                       /* PAUSE Timer Value and Counter Bit 5 */
    word PTIME6      :1;                                       /* PAUSE Timer Value and Counter Bit 6 */
    word PTIME7      :1;                                       /* PAUSE Timer Value and Counter Bit 7 */
    word PTIME8      :1;                                       /* PAUSE Timer Value and Counter Bit 8 */
    word PTIME9      :1;                                       /* PAUSE Timer Value and Counter Bit 9 */
    word PTIME10     :1;                                       /* PAUSE Timer Value and Counter Bit 10 */
    word PTIME11     :1;                                       /* PAUSE Timer Value and Counter Bit 11 */
    word PTIME12     :1;                                       /* PAUSE Timer Value and Counter Bit 12 */
    word PTIME13     :1;                                       /* PAUSE Timer Value and Counter Bit 13 */
    word PTIME14     :1;                                       /* PAUSE Timer Value and Counter Bit 14 */
    word PTIME15     :1;                                       /* PAUSE Timer Value and Counter Bit 15 */
  } Bits;
  struct {
    word grpPTIME :16;
  } MergedBits;
} PTIMESTR;
extern volatile PTIMESTR _PTIME @(REG_BASE + 0x00000148);
#define PTIME _PTIME.Word
#define PTIME_PTIME0 _PTIME.Bits.PTIME0
#define PTIME_PTIME1 _PTIME.Bits.PTIME1
#define PTIME_PTIME2 _PTIME.Bits.PTIME2
#define PTIME_PTIME3 _PTIME.Bits.PTIME3
#define PTIME_PTIME4 _PTIME.Bits.PTIME4
#define PTIME_PTIME5 _PTIME.Bits.PTIME5
#define PTIME_PTIME6 _PTIME.Bits.PTIME6
#define PTIME_PTIME7 _PTIME.Bits.PTIME7
#define PTIME_PTIME8 _PTIME.Bits.PTIME8
#define PTIME_PTIME9 _PTIME.Bits.PTIME9
#define PTIME_PTIME10 _PTIME.Bits.PTIME10
#define PTIME_PTIME11 _PTIME.Bits.PTIME11
#define PTIME_PTIME12 _PTIME.Bits.PTIME12
#define PTIME_PTIME13 _PTIME.Bits.PTIME13
#define PTIME_PTIME14 _PTIME.Bits.PTIME14
#define PTIME_PTIME15 _PTIME.Bits.PTIME15
#define PTIME_PTIME _PTIME.MergedBits.grpPTIME

#define PTIME_PTIME0_MASK  1
#define PTIME_PTIME1_MASK  2
#define PTIME_PTIME2_MASK  4
#define PTIME_PTIME3_MASK  8
#define PTIME_PTIME4_MASK  16
#define PTIME_PTIME5_MASK  32
#define PTIME_PTIME6_MASK  64
#define PTIME_PTIME7_MASK  128
#define PTIME_PTIME8_MASK  256
#define PTIME_PTIME9_MASK  512
#define PTIME_PTIME10_MASK  1024
#define PTIME_PTIME11_MASK  2048
#define PTIME_PTIME12_MASK  4096
#define PTIME_PTIME13_MASK  8192
#define PTIME_PTIME14_MASK  16384
#define PTIME_PTIME15_MASK  32768
#define PTIME_PTIME_MASK  65535
#define PTIME_PTIME_BITNUM  0


/*** IEVENT - Interrupt Event; 0x0000014A ***/
typedef union {
  word Word;
  struct {
#if (__VERSION__ == 5023) //Version 3.0 compiler treats word structure differently
    word             :1; 
    word TXCIF       :1;                                       /* Frame Transmission Complete Interrupt Flag */
    word             :1; 
    word             :1; 
    word ECIF        :1;                                       /* Excessive Collision Interrupt Flag */
    word LCIF        :1;                                       /* Late Collision Interrupt Flag */
    word             :1; 
    word MMCIF       :1;                                       /* MII Management Transfer Complete Interrupt Flag */
    word RXBCIF      :1;                                       /* Valid Frame Reception to Receive Buffer B Complete Interrupt Flag */
    word RXACIF      :1;                                       /* Valid Frame Reception to Receive Buffer A Complete Interrupt Flag */
    word RXBOIF      :1;                                       /* Receive Buffer B Overrun Interrupt Flag */
    word RXAOIF      :1;                                       /* Receive Buffer A Overrun Interrupt Flag */
    word RXEIF       :1;                                       /* Receive Error Interrupt Flag */
    word BREIF       :1;                                       /* Babbling Receive Error Interrupt Flag */
    word             :1; 
    word RFCIF       :1;                                       /* Receive Flow Control Interrupt Flag */
#else
    word RXBCIF      :1;                                       /* Valid Frame Reception to Receive Buffer B Complete Interrupt Flag */
    word RXACIF      :1;                                       /* Valid Frame Reception to Receive Buffer A Complete Interrupt Flag */
    word RXBOIF      :1;                                       /* Receive Buffer B Overrun Interrupt Flag */
    word RXAOIF      :1;                                       /* Receive Buffer A Overrun Interrupt Flag */
    word RXEIF       :1;                                       /* Receive Error Interrupt Flag */
    word BREIF       :1;                                       /* Babbling Receive Error Interrupt Flag */
    word             :1; 
    word RFCIF       :1;                                       /* Receive Flow Control Interrupt Flag */
    word             :1; 
    word TXCIF       :1;                                       /* Frame Transmission Complete Interrupt Flag */
    word             :1; 
    word             :1; 
    word ECIF        :1;                                       /* Excessive Collision Interrupt Flag */
    word LCIF        :1;                                       /* Late Collision Interrupt Flag */
    word             :1; 
    word MMCIF       :1;                                       /* MII Management Transfer Complete Interrupt Flag */
#endif
  } Bits;
} IEVENTSTR;
extern volatile IEVENTSTR _IEVENT @(REG_BASE + 0x0000014A);
#define IEVENT _IEVENT.Word
#define IEVENT_TXCIF _IEVENT.Bits.TXCIF
#define IEVENT_ECIF _IEVENT.Bits.ECIF
#define IEVENT_LCIF _IEVENT.Bits.LCIF
#define IEVENT_MMCIF _IEVENT.Bits.MMCIF
#define IEVENT_RXBCIF _IEVENT.Bits.RXBCIF
#define IEVENT_RXACIF _IEVENT.Bits.RXACIF
#define IEVENT_RXBOIF _IEVENT.Bits.RXBOIF
#define IEVENT_RXAOIF _IEVENT.Bits.RXAOIF
#define IEVENT_RXEIF _IEVENT.Bits.RXEIF
#define IEVENT_BREIF _IEVENT.Bits.BREIF
#define IEVENT_RFCIF _IEVENT.Bits.RFCIF

#define IEVENT_TXCIF_MASK  2
#define IEVENT_ECIF_MASK  16
#define IEVENT_LCIF_MASK  32
#define IEVENT_MMCIF_MASK  128
#define IEVENT_RXBCIF_MASK  256
#define IEVENT_RXACIF_MASK  512
#define IEVENT_RXBOIF_MASK  1024
#define IEVENT_RXAOIF_MASK  2048
#define IEVENT_RXEIF_MASK  4096
#define IEVENT_BREIF_MASK  8192
#define IEVENT_RFCIF_MASK  32768


/*** IMASK - Interrupt Mask; 0x0000014C ***/
typedef union {
  word Word;
  struct {
#if (__VERSION__ == 5023) //Version 3.0 compiler treats word structure differently
    word             :1; 
    word TXCIE       :1;                                       /* Frame Transmission Complete Interrupt Enable */
    word             :1; 
    word             :1; 
    word ECIE        :1;                                       /* Excessive Collision Interrupt Enable */
    word LCIE        :1;                                       /* Late Collision Interrupt Enable */
    word             :1; 
    word MMCIE       :1;                                       /* MII Management Transfer Complete Interrupt Enable */
    word RXBCIE      :1;                                       /* Valid Frame Reception to Receive Buffer B Complete Interrupt Enable */
    word RXACIE      :1;                                       /* Valid Frame Reception to Receive Buffer A Complete Interrupt Enable */
    word RXBOIE      :1;                                       /* Receive Buffer B Overrun Interrupt Enable */
    word RXAOIE      :1;                                       /* Receive Buffer A Overrun Interrupt Enable */
    word RXEIE       :1;                                       /* Receive Error Interrupt Enable */
    word BREIE       :1;                                       /* Babbling Receive Error Interrupt Enable */
    word             :1; 
    word RFCIE       :1;                                       /* Receive Flow Control Interrupt Enable */
#else
    word RXBCIE      :1;                                       /* Valid Frame Reception to Receive Buffer B Complete Interrupt Enable */
    word RXACIE      :1;                                       /* Valid Frame Reception to Receive Buffer A Complete Interrupt Enable */
    word RXBOIE      :1;                                       /* Receive Buffer B Overrun Interrupt Enable */
    word RXAOIE      :1;                                       /* Receive Buffer A Overrun Interrupt Enable */
    word RXEIE       :1;                                       /* Receive Error Interrupt Enable */
    word BREIE       :1;                                       /* Babbling Receive Error Interrupt Enable */
    word             :1; 
    word RFCIE       :1;                                       /* Receive Flow Control Interrupt Enable */
    word             :1; 
    word TXCIE       :1;                                       /* Frame Transmission Complete Interrupt Enable */
    word             :1; 
    word             :1; 
    word ECIE        :1;                                       /* Excessive Collision Interrupt Enable */
    word LCIE        :1;                                       /* Late Collision Interrupt Enable */
    word             :1; 
    word MMCIE       :1;                                       /* MII Management Transfer Complete Interrupt Enable */
#endif
  } Bits;
} IMASKSTR;
extern volatile IMASKSTR _IMASK @(REG_BASE + 0x0000014C);
#define IMASK _IMASK.Word
#define IMASK_TXCIE _IMASK.Bits.TXCIE
#define IMASK_ECIE _IMASK.Bits.ECIE
#define IMASK_LCIE _IMASK.Bits.LCIE
#define IMASK_MMCIE _IMASK.Bits.MMCIE
#define IMASK_RXBCIE _IMASK.Bits.RXBCIE
#define IMASK_RXACIE _IMASK.Bits.RXACIE
#define IMASK_RXBOIE _IMASK.Bits.RXBOIE
#define IMASK_RXAOIE _IMASK.Bits.RXAOIE
#define IMASK_RXEIE _IMASK.Bits.RXEIE
#define IMASK_BREIE _IMASK.Bits.BREIE
#define IMASK_RFCIE _IMASK.Bits.RFCIE

#define IMASK_TXCIE_MASK  2
#define IMASK_ECIE_MASK  16
#define IMASK_LCIE_MASK  32
#define IMASK_MMCIE_MASK  128
#define IMASK_RXBCIE_MASK  256
#define IMASK_RXACIE_MASK  512
#define IMASK_RXBOIE_MASK  1024
#define IMASK_RXAOIE_MASK  2048
#define IMASK_RXEIE_MASK  4096
#define IMASK_BREIE_MASK  8192
#define IMASK_RFCIE_MASK  32768


/*** SWRST - Software Reset; 0x0000014E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MACRST      :1;                                       /* MAC Software Reset */
  } Bits;
} SWRSTSTR;
extern volatile SWRSTSTR _SWRST @(REG_BASE + 0x0000014E);
#define SWRST _SWRST.Byte
#define SWRST_MACRST _SWRST.Bits.MACRST

#define SWRST_MACRST_MASK  128


/*** MPADR - MII PHY Address; 0x00000150 ***/
typedef union {
  byte Byte;
  struct {
    byte PADDR0      :1;                                       /* MII PHY Address Bit 0 */
    byte PADDR1      :1;                                       /* MII PHY Address Bit 1 */
    byte PADDR2      :1;                                       /* MII PHY Address Bit 2 */
    byte PADDR3      :1;                                       /* MII PHY Address Bit 3 */
    byte PADDR4      :1;                                       /* MII PHY Address Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPADDR :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MPADRSTR;
extern volatile MPADRSTR _MPADR @(REG_BASE + 0x00000150);
#define MPADR _MPADR.Byte
#define MPADR_PADDR0 _MPADR.Bits.PADDR0
#define MPADR_PADDR1 _MPADR.Bits.PADDR1
#define MPADR_PADDR2 _MPADR.Bits.PADDR2
#define MPADR_PADDR3 _MPADR.Bits.PADDR3
#define MPADR_PADDR4 _MPADR.Bits.PADDR4
#define MPADR_PADDR _MPADR.MergedBits.grpPADDR

#define MPADR_PADDR0_MASK  1
#define MPADR_PADDR1_MASK  2
#define MPADR_PADDR2_MASK  4
#define MPADR_PADDR3_MASK  8
#define MPADR_PADDR4_MASK  16
#define MPADR_PADDR_MASK  31
#define MPADR_PADDR_BITNUM  0


/*** MRADR - MII Register Address; 0x00000151 ***/
typedef union {
  byte Byte;
  struct {
    byte RADDR0      :1;                                       /* MII Register Address Bit 0 */
    byte RADDR1      :1;                                       /* MII Register Address Bit 1 */
    byte RADDR2      :1;                                       /* MII Register Address Bit 2 */
    byte RADDR3      :1;                                       /* MII Register Address Bit 3 */
    byte RADDR4      :1;                                       /* MII Register Address Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpRADDR :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MRADRSTR;
extern volatile MRADRSTR _MRADR @(REG_BASE + 0x00000151);
#define MRADR _MRADR.Byte
#define MRADR_RADDR0 _MRADR.Bits.RADDR0
#define MRADR_RADDR1 _MRADR.Bits.RADDR1
#define MRADR_RADDR2 _MRADR.Bits.RADDR2
#define MRADR_RADDR3 _MRADR.Bits.RADDR3
#define MRADR_RADDR4 _MRADR.Bits.RADDR4
#define MRADR_RADDR _MRADR.MergedBits.grpRADDR

#define MRADR_RADDR0_MASK  1
#define MRADR_RADDR1_MASK  2
#define MRADR_RADDR2_MASK  4
#define MRADR_RADDR3_MASK  8
#define MRADR_RADDR4_MASK  16
#define MRADR_RADDR_MASK  31
#define MRADR_RADDR_BITNUM  0


/*** MWDATA - MII Write Data; 0x00000152 ***/
typedef union {
  word Word;
  struct {
    word WDATA0      :1;                                       /* MII Write Data Bit 0 */
    word WDATA1      :1;                                       /* MII Write Data Bit 1 */
    word WDATA2      :1;                                       /* MII Write Data Bit 2 */
    word WDATA3      :1;                                       /* MII Write Data Bit 3 */
    word WDATA4      :1;                                       /* MII Write Data Bit 4 */
    word WDATA5      :1;                                       /* MII Write Data Bit 5 */
    word WDATA6      :1;                                       /* MII Write Data Bit 6 */
    word WDATA7      :1;                                       /* MII Write Data Bit 7 */
    word WDATA8      :1;                                       /* MII Write Data Bit 8 */
    word WDATA9      :1;                                       /* MII Write Data Bit 9 */
    word WDATA10     :1;                                       /* MII Write Data Bit 10 */
    word WDATA11     :1;                                       /* MII Write Data Bit 11 */
    word WDATA12     :1;                                       /* MII Write Data Bit 12 */
    word WDATA13     :1;                                       /* MII Write Data Bit 13 */
    word WDATA14     :1;                                       /* MII Write Data Bit 14 */
    word WDATA15     :1;                                       /* MII Write Data Bit 15 */
  } Bits;
  struct {
    word grpWDATA :16;
  } MergedBits;
} MWDATASTR;
extern volatile MWDATASTR _MWDATA @(REG_BASE + 0x00000152);
#define MWDATA _MWDATA.Word
#define MWDATA_WDATA0 _MWDATA.Bits.WDATA0
#define MWDATA_WDATA1 _MWDATA.Bits.WDATA1
#define MWDATA_WDATA2 _MWDATA.Bits.WDATA2
#define MWDATA_WDATA3 _MWDATA.Bits.WDATA3
#define MWDATA_WDATA4 _MWDATA.Bits.WDATA4
#define MWDATA_WDATA5 _MWDATA.Bits.WDATA5
#define MWDATA_WDATA6 _MWDATA.Bits.WDATA6
#define MWDATA_WDATA7 _MWDATA.Bits.WDATA7
#define MWDATA_WDATA8 _MWDATA.Bits.WDATA8
#define MWDATA_WDATA9 _MWDATA.Bits.WDATA9
#define MWDATA_WDATA10 _MWDATA.Bits.WDATA10
#define MWDATA_WDATA11 _MWDATA.Bits.WDATA11
#define MWDATA_WDATA12 _MWDATA.Bits.WDATA12
#define MWDATA_WDATA13 _MWDATA.Bits.WDATA13
#define MWDATA_WDATA14 _MWDATA.Bits.WDATA14
#define MWDATA_WDATA15 _MWDATA.Bits.WDATA15
#define MWDATA_WDATA _MWDATA.MergedBits.grpWDATA

#define MWDATA_WDATA0_MASK  1
#define MWDATA_WDATA1_MASK  2
#define MWDATA_WDATA2_MASK  4
#define MWDATA_WDATA3_MASK  8
#define MWDATA_WDATA4_MASK  16
#define MWDATA_WDATA5_MASK  32
#define MWDATA_WDATA6_MASK  64
#define MWDATA_WDATA7_MASK  128
#define MWDATA_WDATA8_MASK  256
#define MWDATA_WDATA9_MASK  512
#define MWDATA_WDATA10_MASK  1024
#define MWDATA_WDATA11_MASK  2048
#define MWDATA_WDATA12_MASK  4096
#define MWDATA_WDATA13_MASK  8192
#define MWDATA_WDATA14_MASK  16384
#define MWDATA_WDATA15_MASK  32768
#define MWDATA_WDATA_MASK  65535
#define MWDATA_WDATA_BITNUM  0


/*** MRDATA - MII Read Data; 0x00000154 ***/
typedef union {
  word Word;
  struct {
    word RDATA0      :1;                                       /* MII Read Data Bit 0 */
    word RDATA1      :1;                                       /* MII Read Data Bit 1 */
    word RDATA2      :1;                                       /* MII Read Data Bit 2 */
    word RDATA3      :1;                                       /* MII Read Data Bit 3 */
    word RDATA4      :1;                                       /* MII Read Data Bit 4 */
    word RDATA5      :1;                                       /* MII Read Data Bit 5 */
    word RDATA6      :1;                                       /* MII Read Data Bit 6 */
    word RDATA7      :1;                                       /* MII Read Data Bit 7 */
    word RDATA8      :1;                                       /* MII Read Data Bit 8 */
    word RDATA9      :1;                                       /* MII Read Data Bit 9 */
    word RDATA10     :1;                                       /* MII Read Data Bit 10 */
    word RDATA11     :1;                                       /* MII Read Data Bit 11 */
    word RDATA12     :1;                                       /* MII Read Data Bit 12 */
    word RDATA13     :1;                                       /* MII Read Data Bit 13 */
    word RDATA14     :1;                                       /* MII Read Data Bit 14 */
    word RDATA15     :1;                                       /* MII Read Data Bit 15 */
  } Bits;
  struct {
    word grpRDATA :16;
  } MergedBits;
} MRDATASTR;
extern volatile MRDATASTR _MRDATA @(REG_BASE + 0x00000154);
#define MRDATA _MRDATA.Word
#define MRDATA_RDATA0 _MRDATA.Bits.RDATA0
#define MRDATA_RDATA1 _MRDATA.Bits.RDATA1
#define MRDATA_RDATA2 _MRDATA.Bits.RDATA2
#define MRDATA_RDATA3 _MRDATA.Bits.RDATA3
#define MRDATA_RDATA4 _MRDATA.Bits.RDATA4
#define MRDATA_RDATA5 _MRDATA.Bits.RDATA5
#define MRDATA_RDATA6 _MRDATA.Bits.RDATA6
#define MRDATA_RDATA7 _MRDATA.Bits.RDATA7
#define MRDATA_RDATA8 _MRDATA.Bits.RDATA8
#define MRDATA_RDATA9 _MRDATA.Bits.RDATA9
#define MRDATA_RDATA10 _MRDATA.Bits.RDATA10
#define MRDATA_RDATA11 _MRDATA.Bits.RDATA11
#define MRDATA_RDATA12 _MRDATA.Bits.RDATA12
#define MRDATA_RDATA13 _MRDATA.Bits.RDATA13
#define MRDATA_RDATA14 _MRDATA.Bits.RDATA14
#define MRDATA_RDATA15 _MRDATA.Bits.RDATA15
#define MRDATA_RDATA _MRDATA.MergedBits.grpRDATA

#define MRDATA_RDATA0_MASK  1
#define MRDATA_RDATA1_MASK  2
#define MRDATA_RDATA2_MASK  4
#define MRDATA_RDATA3_MASK  8
#define MRDATA_RDATA4_MASK  16
#define MRDATA_RDATA5_MASK  32
#define MRDATA_RDATA6_MASK  64
#define MRDATA_RDATA7_MASK  128
#define MRDATA_RDATA8_MASK  256
#define MRDATA_RDATA9_MASK  512
#define MRDATA_RDATA10_MASK  1024
#define MRDATA_RDATA11_MASK  2048
#define MRDATA_RDATA12_MASK  4096
#define MRDATA_RDATA13_MASK  8192
#define MRDATA_RDATA14_MASK  16384
#define MRDATA_RDATA15_MASK  32768
#define MRDATA_RDATA_MASK  65535
#define MRDATA_RDATA_BITNUM  0


/*** MCMST - MII Command and Status; 0x00000156 ***/
typedef union {
  byte Byte;
  struct {
    byte MDCSEL0     :1;                                       /* Management Clock Rate Select Bit 0 */
    byte MDCSEL1     :1;                                       /* Management Clock Rate Select Bit 1 */
    byte MDCSEL2     :1;                                       /* Management Clock Rate Select Bit 2 */
    byte MDCSEL3     :1;                                       /* Management Clock Rate Select Bit 3 */
    byte NOPRE       :1;                                       /* No Preamble */
    byte BUSY        :1;                                       /* Operation in Progress */
    byte OP0         :1;                                       /* Operation Code Bit 0 */
    byte OP1         :1;                                       /* Operation Code Bit 1 */
  } Bits;
  struct {
    byte grpMDCSEL :4;
    byte         :1;
    byte         :1;
    byte grpOP   :2;
  } MergedBits;
} MCMSTSTR;
extern volatile MCMSTSTR _MCMST @(REG_BASE + 0x00000156);
#define MCMST _MCMST.Byte
#define MCMST_MDCSEL0 _MCMST.Bits.MDCSEL0
#define MCMST_MDCSEL1 _MCMST.Bits.MDCSEL1
#define MCMST_MDCSEL2 _MCMST.Bits.MDCSEL2
#define MCMST_MDCSEL3 _MCMST.Bits.MDCSEL3
#define MCMST_NOPRE _MCMST.Bits.NOPRE
#define MCMST_BUSY _MCMST.Bits.BUSY
#define MCMST_OP0 _MCMST.Bits.OP0
#define MCMST_OP1 _MCMST.Bits.OP1
#define MCMST_MDCSEL _MCMST.MergedBits.grpMDCSEL
#define MCMST_OP _MCMST.MergedBits.grpOP

#define MCMST_MDCSEL0_MASK  1
#define MCMST_MDCSEL1_MASK  2
#define MCMST_MDCSEL2_MASK  4
#define MCMST_MDCSEL3_MASK  8
#define MCMST_NOPRE_MASK  16
#define MCMST_BUSY_MASK  32
#define MCMST_OP0_MASK  64
#define MCMST_OP1_MASK  128
#define MCMST_MDCSEL_MASK  15
#define MCMST_MDCSEL_BITNUM  0
#define MCMST_OP_MASK  192
#define MCMST_OP_BITNUM  6


/*** BUFCFG - FIFO Buffer Configuration; 0x00000158 ***/
typedef union {
  word Word;
  struct {
    word MAXFL0      :1;                                       /* Receive Maximum Frame Length Bit 0 */
    word MAXFL1      :1;                                       /* Receive Maximum Frame Length Bit 1 */
    word MAXFL2      :1;                                       /* Receive Maximum Frame Length Bit 2 */
    word MAXFL3      :1;                                       /* Receive Maximum Frame Length Bit 3 */
    word MAXFL4      :1;                                       /* Receive Maximum Frame Length Bit 4 */
    word MAXFL5      :1;                                       /* Receive Maximum Frame Length Bit 5 */
    word MAXFL6      :1;                                       /* Receive Maximum Frame Length Bit 6 */
    word MAXFL7      :1;                                       /* Receive Maximum Frame Length Bit 7 */
    word MAXFL8      :1;                                       /* Receive Maximum Frame Length Bit 8 */
    word MAXFL9      :1;                                       /* Receive Maximum Frame Length Bit 9 */
    word MAXFL10     :1;                                       /* Receive Maximum Frame Length Bit 10 */
    word             :1; 
    word BUFMAP0     :1;                                       /* Buffer Size and Starting Address Mapping Bit 0 */
    word BUFMAP1     :1;                                       /* Buffer Size and Starting Address Mapping Bit 1 */
    word BUFMAP2     :1;                                       /* Buffer Size and Starting Address Mapping Bit 2 */
    word BUFMAP3     :1;                                       /* Buffer Size and Starting Address Mapping Bit 3 */
  } Bits;
  struct {
    word grpMAXFL :11;
    word         :1;
    word grpBUFMAP :4;
  } MergedBits;
} BUFCFGSTR;
extern volatile BUFCFGSTR _BUFCFG @(REG_BASE + 0x00000158);
#define BUFCFG _BUFCFG.Word
#define BUFCFG_MAXFL0 _BUFCFG.Bits.MAXFL0
#define BUFCFG_MAXFL1 _BUFCFG.Bits.MAXFL1
#define BUFCFG_MAXFL2 _BUFCFG.Bits.MAXFL2
#define BUFCFG_MAXFL3 _BUFCFG.Bits.MAXFL3
#define BUFCFG_MAXFL4 _BUFCFG.Bits.MAXFL4
#define BUFCFG_MAXFL5 _BUFCFG.Bits.MAXFL5
#define BUFCFG_MAXFL6 _BUFCFG.Bits.MAXFL6
#define BUFCFG_MAXFL7 _BUFCFG.Bits.MAXFL7
#define BUFCFG_MAXFL8 _BUFCFG.Bits.MAXFL8
#define BUFCFG_MAXFL9 _BUFCFG.Bits.MAXFL9
#define BUFCFG_MAXFL10 _BUFCFG.Bits.MAXFL10
#define BUFCFG_BUFMAP0 _BUFCFG.Bits.BUFMAP0
#define BUFCFG_BUFMAP1 _BUFCFG.Bits.BUFMAP1
#define BUFCFG_BUFMAP2 _BUFCFG.Bits.BUFMAP2
#define BUFCFG_BUFMAP3 _BUFCFG.Bits.BUFMAP3
#define BUFCFG_MAXFL _BUFCFG.MergedBits.grpMAXFL
#define BUFCFG_BUFMAP _BUFCFG.MergedBits.grpBUFMAP

#define BUFCFG_MAXFL0_MASK  1
#define BUFCFG_MAXFL1_MASK  2
#define BUFCFG_MAXFL2_MASK  4
#define BUFCFG_MAXFL3_MASK  8
#define BUFCFG_MAXFL4_MASK  16
#define BUFCFG_MAXFL5_MASK  32
#define BUFCFG_MAXFL6_MASK  64
#define BUFCFG_MAXFL7_MASK  128
#define BUFCFG_MAXFL8_MASK  256
#define BUFCFG_MAXFL9_MASK  512
#define BUFCFG_MAXFL10_MASK  1024
#define BUFCFG_BUFMAP0_MASK  4096
#define BUFCFG_BUFMAP1_MASK  8192
#define BUFCFG_BUFMAP2_MASK  16384
#define BUFCFG_BUFMAP3_MASK  32768
#define BUFCFG_MAXFL_MASK  2047
#define BUFCFG_MAXFL_BITNUM  0
#define BUFCFG_BUFMAP_MASK  61440
#define BUFCFG_BUFMAP_BITNUM  12


/*** RXAEFP - Receive A End of Frame Pointer; 0x0000015A ***/
typedef union {
  word Word;
  struct {
    word RXAEFP0     :1;                                       /* Receive A End of Frame Pointer Bit 0 */
    word RXAEFP1     :1;                                       /* Receive A End of Frame Pointer Bit 1 */
    word RXAEFP2     :1;                                       /* Receive A End of Frame Pointer Bit 2 */
    word RXAEFP3     :1;                                       /* Receive A End of Frame Pointer Bit 3 */
    word RXAEFP4     :1;                                       /* Receive A End of Frame Pointer Bit 4 */
    word RXAEFP5     :1;                                       /* Receive A End of Frame Pointer Bit 5 */
    word RXAEFP6     :1;                                       /* Receive A End of Frame Pointer Bit 6 */
    word RXAEFP7     :1;                                       /* Receive A End of Frame Pointer Bit 7 */
    word RXAEFP8     :1;                                       /* Receive A End of Frame Pointer Bit 8 */
    word RXAEFP9     :1;                                       /* Receive A End of Frame Pointer Bit 9 */
    word RXAEFP10    :1;                                       /* Receive A End of Frame Pointer Bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpRXAEFP :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} RXAEFPSTR;
extern volatile RXAEFPSTR _RXAEFP @(REG_BASE + 0x0000015A);
#define RXAEFP _RXAEFP.Word
#define RXAEFP_RXAEFP0 _RXAEFP.Bits.RXAEFP0
#define RXAEFP_RXAEFP1 _RXAEFP.Bits.RXAEFP1
#define RXAEFP_RXAEFP2 _RXAEFP.Bits.RXAEFP2
#define RXAEFP_RXAEFP3 _RXAEFP.Bits.RXAEFP3
#define RXAEFP_RXAEFP4 _RXAEFP.Bits.RXAEFP4
#define RXAEFP_RXAEFP5 _RXAEFP.Bits.RXAEFP5
#define RXAEFP_RXAEFP6 _RXAEFP.Bits.RXAEFP6
#define RXAEFP_RXAEFP7 _RXAEFP.Bits.RXAEFP7
#define RXAEFP_RXAEFP8 _RXAEFP.Bits.RXAEFP8
#define RXAEFP_RXAEFP9 _RXAEFP.Bits.RXAEFP9
#define RXAEFP_RXAEFP10 _RXAEFP.Bits.RXAEFP10
#define RXAEFP_RXAEFP _RXAEFP.MergedBits.grpRXAEFP

#define RXAEFP_RXAEFP0_MASK  1
#define RXAEFP_RXAEFP1_MASK  2
#define RXAEFP_RXAEFP2_MASK  4
#define RXAEFP_RXAEFP3_MASK  8
#define RXAEFP_RXAEFP4_MASK  16
#define RXAEFP_RXAEFP5_MASK  32
#define RXAEFP_RXAEFP6_MASK  64
#define RXAEFP_RXAEFP7_MASK  128
#define RXAEFP_RXAEFP8_MASK  256
#define RXAEFP_RXAEFP9_MASK  512
#define RXAEFP_RXAEFP10_MASK  1024
#define RXAEFP_RXAEFP_MASK  2047
#define RXAEFP_RXAEFP_BITNUM  0


/*** RXBEFP - Receive B End of Frame Pointer; 0x0000015C ***/
typedef union {
  word Word;
  struct {
    word RXBEFP0     :1;                                       /* Receive B End of Frame Pointer Bit 0 */
    word RXBEFP1     :1;                                       /* Receive B End of Frame Pointer Bit 1 */
    word RXBEFP2     :1;                                       /* Receive B End of Frame Pointer Bit 2 */
    word RXBEFP3     :1;                                       /* Receive B End of Frame Pointer Bit 3 */
    word RXBEFP4     :1;                                       /* Receive B End of Frame Pointer Bit 4 */
    word RXBEFP5     :1;                                       /* Receive B End of Frame Pointer Bit 5 */
    word RXBEFP6     :1;                                       /* Receive B End of Frame Pointer Bit 6 */
    word RXBEFP7     :1;                                       /* Receive B End of Frame Pointer Bit 7 */
    word RXBEFP8     :1;                                       /* Receive B End of Frame Pointer Bit 8 */
    word RXBEFP9     :1;                                       /* Receive B End of Frame Pointer Bit 9 */
    word RXBEFP10    :1;                                       /* Receive B End of Frame Pointer Bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpRXBEFP :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} RXBEFPSTR;
extern volatile RXBEFPSTR _RXBEFP @(REG_BASE + 0x0000015C);
#define RXBEFP _RXBEFP.Word
#define RXBEFP_RXBEFP0 _RXBEFP.Bits.RXBEFP0
#define RXBEFP_RXBEFP1 _RXBEFP.Bits.RXBEFP1
#define RXBEFP_RXBEFP2 _RXBEFP.Bits.RXBEFP2
#define RXBEFP_RXBEFP3 _RXBEFP.Bits.RXBEFP3
#define RXBEFP_RXBEFP4 _RXBEFP.Bits.RXBEFP4
#define RXBEFP_RXBEFP5 _RXBEFP.Bits.RXBEFP5
#define RXBEFP_RXBEFP6 _RXBEFP.Bits.RXBEFP6
#define RXBEFP_RXBEFP7 _RXBEFP.Bits.RXBEFP7
#define RXBEFP_RXBEFP8 _RXBEFP.Bits.RXBEFP8
#define RXBEFP_RXBEFP9 _RXBEFP.Bits.RXBEFP9
#define RXBEFP_RXBEFP10 _RXBEFP.Bits.RXBEFP10
#define RXBEFP_RXBEFP _RXBEFP.MergedBits.grpRXBEFP

#define RXBEFP_RXBEFP0_MASK  1
#define RXBEFP_RXBEFP1_MASK  2
#define RXBEFP_RXBEFP2_MASK  4
#define RXBEFP_RXBEFP3_MASK  8
#define RXBEFP_RXBEFP4_MASK  16
#define RXBEFP_RXBEFP5_MASK  32
#define RXBEFP_RXBEFP6_MASK  64
#define RXBEFP_RXBEFP7_MASK  128
#define RXBEFP_RXBEFP8_MASK  256
#define RXBEFP_RXBEFP9_MASK  512
#define RXBEFP_RXBEFP10_MASK  1024
#define RXBEFP_RXBEFP_MASK  2047
#define RXBEFP_RXBEFP_BITNUM  0


/*** TXEFP - Transmit End of Frame Pointer; 0x0000015E ***/
typedef union {
  word Word;
  struct {
    word TXEFP0      :1;                                       /* Transmit End of Frame Pointer Bit 0 */
    word TXEFP1      :1;                                       /* Transmit End of Frame Pointer Bit 1 */
    word TXEFP2      :1;                                       /* Transmit End of Frame Pointer Bit 2 */
    word TXEFP3      :1;                                       /* Transmit End of Frame Pointer Bit 3 */
    word TXEFP4      :1;                                       /* Transmit End of Frame Pointer Bit 4 */
    word TXEFP5      :1;                                       /* Transmit End of Frame Pointer Bit 5 */
    word TXEFP6      :1;                                       /* Transmit End of Frame Pointer Bit 6 */
    word TXEFP7      :1;                                       /* Transmit End of Frame Pointer Bit 7 */
    word TXEFP8      :1;                                       /* Transmit End of Frame Pointer Bit 8 */
    word TXEFP9      :1;                                       /* Transmit End of Frame Pointer Bit 9 */
    word TXEFP10     :1;                                       /* Transmit End of Frame Pointer Bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpTXEFP :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} TXEFPSTR;
extern volatile TXEFPSTR _TXEFP @(REG_BASE + 0x0000015E);
#define TXEFP _TXEFP.Word
#define TXEFP_TXEFP0 _TXEFP.Bits.TXEFP0
#define TXEFP_TXEFP1 _TXEFP.Bits.TXEFP1
#define TXEFP_TXEFP2 _TXEFP.Bits.TXEFP2
#define TXEFP_TXEFP3 _TXEFP.Bits.TXEFP3
#define TXEFP_TXEFP4 _TXEFP.Bits.TXEFP4
#define TXEFP_TXEFP5 _TXEFP.Bits.TXEFP5
#define TXEFP_TXEFP6 _TXEFP.Bits.TXEFP6
#define TXEFP_TXEFP7 _TXEFP.Bits.TXEFP7
#define TXEFP_TXEFP8 _TXEFP.Bits.TXEFP8
#define TXEFP_TXEFP9 _TXEFP.Bits.TXEFP9
#define TXEFP_TXEFP10 _TXEFP.Bits.TXEFP10
#define TXEFP_TXEFP _TXEFP.MergedBits.grpTXEFP

#define TXEFP_TXEFP0_MASK  1
#define TXEFP_TXEFP1_MASK  2
#define TXEFP_TXEFP2_MASK  4
#define TXEFP_TXEFP3_MASK  8
#define TXEFP_TXEFP4_MASK  16
#define TXEFP_TXEFP5_MASK  32
#define TXEFP_TXEFP6_MASK  64
#define TXEFP_TXEFP7_MASK  128
#define TXEFP_TXEFP8_MASK  256
#define TXEFP_TXEFP9_MASK  512
#define TXEFP_TXEFP10_MASK  1024
#define TXEFP_TXEFP_MASK  2047
#define TXEFP_TXEFP_BITNUM  0


/*** MCHASH3 - Multicast Hash Table Register 3; 0x00000160 ***/
typedef union {
  word Word;
  struct {
    word MCHASH_48   :1;                                       /* Multicast Hash Table Index Bit 48 */
    word MCHASH_49   :1;                                       /* Multicast Hash Table Index Bit 49 */
    word MCHASH_50   :1;                                       /* Multicast Hash Table Index Bit 50 */
    word MCHASH_51   :1;                                       /* Multicast Hash Table Index Bit 51 */
    word MCHASH_52   :1;                                       /* Multicast Hash Table Index Bit 52 */
    word MCHASH_53   :1;                                       /* Multicast Hash Table Index Bit 53 */
    word MCHASH_54   :1;                                       /* Multicast Hash Table Index Bit 54 */
    word MCHASH_55   :1;                                       /* Multicast Hash Table Index Bit 55 */
    word MCHASH_56   :1;                                       /* Multicast Hash Table Index Bit 56 */
    word MCHASH_57   :1;                                       /* Multicast Hash Table Index Bit 57 */
    word MCHASH_58   :1;                                       /* Multicast Hash Table Index Bit 58 */
    word MCHASH_59   :1;                                       /* Multicast Hash Table Index Bit 59 */
    word MCHASH_60   :1;                                       /* Multicast Hash Table Index Bit 60 */
    word MCHASH_61   :1;                                       /* Multicast Hash Table Index Bit 61 */
    word MCHASH_62   :1;                                       /* Multicast Hash Table Index Bit 62 */
    word MCHASH_63   :1;                                       /* Multicast Hash Table Index Bit 63 */
  } Bits;
  struct {
    word grpMCHASH__48 :16;
  } MergedBits;
} MCHASH3STR;
extern volatile MCHASH3STR _MCHASH3 @(REG_BASE + 0x00000160);
#define MCHASH3 _MCHASH3.Word
#define MCHASH3_MCHASH_48 _MCHASH3.Bits.MCHASH_48
#define MCHASH3_MCHASH_49 _MCHASH3.Bits.MCHASH_49
#define MCHASH3_MCHASH_50 _MCHASH3.Bits.MCHASH_50
#define MCHASH3_MCHASH_51 _MCHASH3.Bits.MCHASH_51
#define MCHASH3_MCHASH_52 _MCHASH3.Bits.MCHASH_52
#define MCHASH3_MCHASH_53 _MCHASH3.Bits.MCHASH_53
#define MCHASH3_MCHASH_54 _MCHASH3.Bits.MCHASH_54
#define MCHASH3_MCHASH_55 _MCHASH3.Bits.MCHASH_55
#define MCHASH3_MCHASH_56 _MCHASH3.Bits.MCHASH_56
#define MCHASH3_MCHASH_57 _MCHASH3.Bits.MCHASH_57
#define MCHASH3_MCHASH_58 _MCHASH3.Bits.MCHASH_58
#define MCHASH3_MCHASH_59 _MCHASH3.Bits.MCHASH_59
#define MCHASH3_MCHASH_60 _MCHASH3.Bits.MCHASH_60
#define MCHASH3_MCHASH_61 _MCHASH3.Bits.MCHASH_61
#define MCHASH3_MCHASH_62 _MCHASH3.Bits.MCHASH_62
#define MCHASH3_MCHASH_63 _MCHASH3.Bits.MCHASH_63
#define MCHASH3_MCHASH__48 _MCHASH3.MergedBits.grpMCHASH__48
#define MCHASH3_MCHASH_ MCHASH3_MCHASH__48

#define MCHASH3_MCHASH_48_MASK  1
#define MCHASH3_MCHASH_49_MASK  2
#define MCHASH3_MCHASH_50_MASK  4
#define MCHASH3_MCHASH_51_MASK  8
#define MCHASH3_MCHASH_52_MASK  16
#define MCHASH3_MCHASH_53_MASK  32
#define MCHASH3_MCHASH_54_MASK  64
#define MCHASH3_MCHASH_55_MASK  128
#define MCHASH3_MCHASH_56_MASK  256
#define MCHASH3_MCHASH_57_MASK  512
#define MCHASH3_MCHASH_58_MASK  1024
#define MCHASH3_MCHASH_59_MASK  2048
#define MCHASH3_MCHASH_60_MASK  4096
#define MCHASH3_MCHASH_61_MASK  8192
#define MCHASH3_MCHASH_62_MASK  16384
#define MCHASH3_MCHASH_63_MASK  32768
#define MCHASH3_MCHASH__48_MASK  65535
#define MCHASH3_MCHASH__48_BITNUM  0


/*** MCHASH2 - Multicast Hash Table Register 2; 0x00000162 ***/
typedef union {
  word Word;
  struct {
    word MCHASH_32   :1;                                       /* Multicast Hash Table Index Bit 32 */
    word MCHASH_33   :1;                                       /* Multicast Hash Table Index Bit 33 */
    word MCHASH_34   :1;                                       /* Multicast Hash Table Index Bit 34 */
    word MCHASH_35   :1;                                       /* Multicast Hash Table Index Bit 35 */
    word MCHASH_36   :1;                                       /* Multicast Hash Table Index Bit 36 */
    word MCHASH_37   :1;                                       /* Multicast Hash Table Index Bit 37 */
    word MCHASH_38   :1;                                       /* Multicast Hash Table Index Bit 38 */
    word MCHASH_39   :1;                                       /* Multicast Hash Table Index Bit 39 */
    word MCHASH_40   :1;                                       /* Multicast Hash Table Index Bit 40 */
    word MCHASH_41   :1;                                       /* Multicast Hash Table Index Bit 41 */
    word MCHASH_42   :1;                                       /* Multicast Hash Table Index Bit 42 */
    word MCHASH_43   :1;                                       /* Multicast Hash Table Index Bit 43 */
    word MCHASH_44   :1;                                       /* Multicast Hash Table Index Bit 44 */
    word MCHASH_45   :1;                                       /* Multicast Hash Table Index Bit 45 */
    word MCHASH_46   :1;                                       /* Multicast Hash Table Index Bit 46 */
    word MCHASH_47   :1;                                       /* Multicast Hash Table Index Bit 47 */
  } Bits;
  struct {
    word grpMCHASH__32 :16;
  } MergedBits;
} MCHASH2STR;
extern volatile MCHASH2STR _MCHASH2 @(REG_BASE + 0x00000162);
#define MCHASH2 _MCHASH2.Word
#define MCHASH2_MCHASH_32 _MCHASH2.Bits.MCHASH_32
#define MCHASH2_MCHASH_33 _MCHASH2.Bits.MCHASH_33
#define MCHASH2_MCHASH_34 _MCHASH2.Bits.MCHASH_34
#define MCHASH2_MCHASH_35 _MCHASH2.Bits.MCHASH_35
#define MCHASH2_MCHASH_36 _MCHASH2.Bits.MCHASH_36
#define MCHASH2_MCHASH_37 _MCHASH2.Bits.MCHASH_37
#define MCHASH2_MCHASH_38 _MCHASH2.Bits.MCHASH_38
#define MCHASH2_MCHASH_39 _MCHASH2.Bits.MCHASH_39
#define MCHASH2_MCHASH_40 _MCHASH2.Bits.MCHASH_40
#define MCHASH2_MCHASH_41 _MCHASH2.Bits.MCHASH_41
#define MCHASH2_MCHASH_42 _MCHASH2.Bits.MCHASH_42
#define MCHASH2_MCHASH_43 _MCHASH2.Bits.MCHASH_43
#define MCHASH2_MCHASH_44 _MCHASH2.Bits.MCHASH_44
#define MCHASH2_MCHASH_45 _MCHASH2.Bits.MCHASH_45
#define MCHASH2_MCHASH_46 _MCHASH2.Bits.MCHASH_46
#define MCHASH2_MCHASH_47 _MCHASH2.Bits.MCHASH_47
#define MCHASH2_MCHASH__32 _MCHASH2.MergedBits.grpMCHASH__32
#define MCHASH2_MCHASH_ MCHASH2_MCHASH__32

#define MCHASH2_MCHASH_32_MASK  1
#define MCHASH2_MCHASH_33_MASK  2
#define MCHASH2_MCHASH_34_MASK  4
#define MCHASH2_MCHASH_35_MASK  8
#define MCHASH2_MCHASH_36_MASK  16
#define MCHASH2_MCHASH_37_MASK  32
#define MCHASH2_MCHASH_38_MASK  64
#define MCHASH2_MCHASH_39_MASK  128
#define MCHASH2_MCHASH_40_MASK  256
#define MCHASH2_MCHASH_41_MASK  512
#define MCHASH2_MCHASH_42_MASK  1024
#define MCHASH2_MCHASH_43_MASK  2048
#define MCHASH2_MCHASH_44_MASK  4096
#define MCHASH2_MCHASH_45_MASK  8192
#define MCHASH2_MCHASH_46_MASK  16384
#define MCHASH2_MCHASH_47_MASK  32768
#define MCHASH2_MCHASH__32_MASK  65535
#define MCHASH2_MCHASH__32_BITNUM  0


/*** MCHASH1 - Multicast Hash Table Register 1; 0x00000164 ***/
typedef union {
  word Word;
  struct {
    word MCHASH_16   :1;                                       /* Multicast Hash Table Index Bit 16 */
    word MCHASH_17   :1;                                       /* Multicast Hash Table Index Bit 17 */
    word MCHASH_18   :1;                                       /* Multicast Hash Table Index Bit 18 */
    word MCHASH_19   :1;                                       /* Multicast Hash Table Index Bit 19 */
    word MCHASH_20   :1;                                       /* Multicast Hash Table Index Bit 20 */
    word MCHASH_21   :1;                                       /* Multicast Hash Table Index Bit 21 */
    word MCHASH_22   :1;                                       /* Multicast Hash Table Index Bit 22 */
    word MCHASH_23   :1;                                       /* Multicast Hash Table Index Bit 23 */
    word MCHASH_24   :1;                                       /* Multicast Hash Table Index Bit 24 */
    word MCHASH_25   :1;                                       /* Multicast Hash Table Index Bit 25 */
    word MCHASH_26   :1;                                       /* Multicast Hash Table Index Bit 26 */
    word MCHASH_27   :1;                                       /* Multicast Hash Table Index Bit 27 */
    word MCHASH_28   :1;                                       /* Multicast Hash Table Index Bit 28 */
    word MCHASH_29   :1;                                       /* Multicast Hash Table Index Bit 29 */
    word MCHASH_30   :1;                                       /* Multicast Hash Table Index Bit 30 */
    word MCHASH_31   :1;                                       /* Multicast Hash Table Index Bit 31 */
  } Bits;
  struct {
    word grpMCHASH__16 :16;
  } MergedBits;
} MCHASH1STR;
extern volatile MCHASH1STR _MCHASH1 @(REG_BASE + 0x00000164);
#define MCHASH1 _MCHASH1.Word
#define MCHASH1_MCHASH_16 _MCHASH1.Bits.MCHASH_16
#define MCHASH1_MCHASH_17 _MCHASH1.Bits.MCHASH_17
#define MCHASH1_MCHASH_18 _MCHASH1.Bits.MCHASH_18
#define MCHASH1_MCHASH_19 _MCHASH1.Bits.MCHASH_19
#define MCHASH1_MCHASH_20 _MCHASH1.Bits.MCHASH_20
#define MCHASH1_MCHASH_21 _MCHASH1.Bits.MCHASH_21
#define MCHASH1_MCHASH_22 _MCHASH1.Bits.MCHASH_22
#define MCHASH1_MCHASH_23 _MCHASH1.Bits.MCHASH_23
#define MCHASH1_MCHASH_24 _MCHASH1.Bits.MCHASH_24
#define MCHASH1_MCHASH_25 _MCHASH1.Bits.MCHASH_25
#define MCHASH1_MCHASH_26 _MCHASH1.Bits.MCHASH_26
#define MCHASH1_MCHASH_27 _MCHASH1.Bits.MCHASH_27
#define MCHASH1_MCHASH_28 _MCHASH1.Bits.MCHASH_28
#define MCHASH1_MCHASH_29 _MCHASH1.Bits.MCHASH_29
#define MCHASH1_MCHASH_30 _MCHASH1.Bits.MCHASH_30
#define MCHASH1_MCHASH_31 _MCHASH1.Bits.MCHASH_31
#define MCHASH1_MCHASH__16 _MCHASH1.MergedBits.grpMCHASH__16
#define MCHASH1_MCHASH_ MCHASH1_MCHASH__16

#define MCHASH1_MCHASH_16_MASK  1
#define MCHASH1_MCHASH_17_MASK  2
#define MCHASH1_MCHASH_18_MASK  4
#define MCHASH1_MCHASH_19_MASK  8
#define MCHASH1_MCHASH_20_MASK  16
#define MCHASH1_MCHASH_21_MASK  32
#define MCHASH1_MCHASH_22_MASK  64
#define MCHASH1_MCHASH_23_MASK  128
#define MCHASH1_MCHASH_24_MASK  256
#define MCHASH1_MCHASH_25_MASK  512
#define MCHASH1_MCHASH_26_MASK  1024
#define MCHASH1_MCHASH_27_MASK  2048
#define MCHASH1_MCHASH_28_MASK  4096
#define MCHASH1_MCHASH_29_MASK  8192
#define MCHASH1_MCHASH_30_MASK  16384
#define MCHASH1_MCHASH_31_MASK  32768
#define MCHASH1_MCHASH__16_MASK  65535
#define MCHASH1_MCHASH__16_BITNUM  0


/*** MCHASH0 - Multicast Hash Table Register 0; 0x00000166 ***/
typedef union {
  word Word;
  struct {
    word MCHASH_0    :1;                                       /* Multicast Hash Table Index Bit 0 */
    word MCHASH_1    :1;                                       /* Multicast Hash Table Index Bit 1 */
    word MCHASH_2    :1;                                       /* Multicast Hash Table Index Bit 2 */
    word MCHASH_3    :1;                                       /* Multicast Hash Table Index Bit 3 */
    word MCHASH_4    :1;                                       /* Multicast Hash Table Index Bit 4 */
    word MCHASH_5    :1;                                       /* Multicast Hash Table Index Bit 5 */
    word MCHASH_6    :1;                                       /* Multicast Hash Table Index Bit 6 */
    word MCHASH_7    :1;                                       /* Multicast Hash Table Index Bit 7 */
    word MCHASH_8    :1;                                       /* Multicast Hash Table Index Bit 8 */
    word MCHASH_9    :1;                                       /* Multicast Hash Table Index Bit 9 */
    word MCHASH_10   :1;                                       /* Multicast Hash Table Index Bit 10 */
    word MCHASH_11   :1;                                       /* Multicast Hash Table Index Bit 11 */
    word MCHASH_12   :1;                                       /* Multicast Hash Table Index Bit 12 */
    word MCHASH_13   :1;                                       /* Multicast Hash Table Index Bit 13 */
    word MCHASH_14   :1;                                       /* Multicast Hash Table Index Bit 14 */
    word MCHASH_15   :1;                                       /* Multicast Hash Table Index Bit 15 */
  } Bits;
  struct {
    word grpMCHASH :16;
  } MergedBits;
} MCHASH0STR;
extern volatile MCHASH0STR _MCHASH0 @(REG_BASE + 0x00000166);
#define MCHASH0 _MCHASH0.Word
#define MCHASH0_MCHASH_0 _MCHASH0.Bits.MCHASH_0
#define MCHASH0_MCHASH_1 _MCHASH0.Bits.MCHASH_1
#define MCHASH0_MCHASH_2 _MCHASH0.Bits.MCHASH_2
#define MCHASH0_MCHASH_3 _MCHASH0.Bits.MCHASH_3
#define MCHASH0_MCHASH_4 _MCHASH0.Bits.MCHASH_4
#define MCHASH0_MCHASH_5 _MCHASH0.Bits.MCHASH_5
#define MCHASH0_MCHASH_6 _MCHASH0.Bits.MCHASH_6
#define MCHASH0_MCHASH_7 _MCHASH0.Bits.MCHASH_7
#define MCHASH0_MCHASH_8 _MCHASH0.Bits.MCHASH_8
#define MCHASH0_MCHASH_9 _MCHASH0.Bits.MCHASH_9
#define MCHASH0_MCHASH_10 _MCHASH0.Bits.MCHASH_10
#define MCHASH0_MCHASH_11 _MCHASH0.Bits.MCHASH_11
#define MCHASH0_MCHASH_12 _MCHASH0.Bits.MCHASH_12
#define MCHASH0_MCHASH_13 _MCHASH0.Bits.MCHASH_13
#define MCHASH0_MCHASH_14 _MCHASH0.Bits.MCHASH_14
#define MCHASH0_MCHASH_15 _MCHASH0.Bits.MCHASH_15
#define MCHASH0_MCHASH _MCHASH0.MergedBits.grpMCHASH

#define MCHASH0_MCHASH_0_MASK  1
#define MCHASH0_MCHASH_1_MASK  2
#define MCHASH0_MCHASH_2_MASK  4
#define MCHASH0_MCHASH_3_MASK  8
#define MCHASH0_MCHASH_4_MASK  16
#define MCHASH0_MCHASH_5_MASK  32
#define MCHASH0_MCHASH_6_MASK  64
#define MCHASH0_MCHASH_7_MASK  128
#define MCHASH0_MCHASH_8_MASK  256
#define MCHASH0_MCHASH_9_MASK  512
#define MCHASH0_MCHASH_10_MASK  1024
#define MCHASH0_MCHASH_11_MASK  2048
#define MCHASH0_MCHASH_12_MASK  4096
#define MCHASH0_MCHASH_13_MASK  8192
#define MCHASH0_MCHASH_14_MASK  16384
#define MCHASH0_MCHASH_15_MASK  32768
#define MCHASH0_MCHASH_MASK  65535
#define MCHASH0_MCHASH_BITNUM  0


/*** MACAD2 - MAC Address Register 2; 0x00000168 ***/
typedef union {
  word Word;
  struct {
    word MACAD_32    :1;                                       /* MAC Address Bit 32 */
    word MACAD_33    :1;                                       /* MAC Address Bit 33 */
    word MACAD_34    :1;                                       /* MAC Address Bit 34 */
    word MACAD_35    :1;                                       /* MAC Address Bit 35 */
    word MACAD_36    :1;                                       /* MAC Address Bit 36 */
    word MACAD_37    :1;                                       /* MAC Address Bit 37 */
    word MACAD_38    :1;                                       /* MAC Address Bit 38 */
    word MACAD_39    :1;                                       /* MAC Address Bit 39 */
    word MACAD_40    :1;                                       /* MAC Address Bit 40 */
    word MACAD_41    :1;                                       /* MAC Address Bit 41 */
    word MACAD_42    :1;                                       /* MAC Address Bit 42 */
    word MACAD_43    :1;                                       /* MAC Address Bit 43 */
    word MACAD_44    :1;                                       /* MAC Address Bit 44 */
    word MACAD_45    :1;                                       /* MAC Address Bit 45 */
    word MACAD_46    :1;                                       /* MAC Address Bit 46 */
    word MACAD_47    :1;                                       /* MAC Address Bit 47 */
  } Bits;
  struct {
    word grpMACAD__32 :16;
  } MergedBits;
} MACAD2STR;
extern volatile MACAD2STR _MACAD2 @(REG_BASE + 0x00000168);
#define MACAD2 _MACAD2.Word
#define MACAD2_MACAD_32 _MACAD2.Bits.MACAD_32
#define MACAD2_MACAD_33 _MACAD2.Bits.MACAD_33
#define MACAD2_MACAD_34 _MACAD2.Bits.MACAD_34
#define MACAD2_MACAD_35 _MACAD2.Bits.MACAD_35
#define MACAD2_MACAD_36 _MACAD2.Bits.MACAD_36
#define MACAD2_MACAD_37 _MACAD2.Bits.MACAD_37
#define MACAD2_MACAD_38 _MACAD2.Bits.MACAD_38
#define MACAD2_MACAD_39 _MACAD2.Bits.MACAD_39
#define MACAD2_MACAD_40 _MACAD2.Bits.MACAD_40
#define MACAD2_MACAD_41 _MACAD2.Bits.MACAD_41
#define MACAD2_MACAD_42 _MACAD2.Bits.MACAD_42
#define MACAD2_MACAD_43 _MACAD2.Bits.MACAD_43
#define MACAD2_MACAD_44 _MACAD2.Bits.MACAD_44
#define MACAD2_MACAD_45 _MACAD2.Bits.MACAD_45
#define MACAD2_MACAD_46 _MACAD2.Bits.MACAD_46
#define MACAD2_MACAD_47 _MACAD2.Bits.MACAD_47
#define MACAD2_MACAD__32 _MACAD2.MergedBits.grpMACAD__32
#define MACAD2_MACAD_ MACAD2_MACAD__32

#define MACAD2_MACAD_32_MASK  1
#define MACAD2_MACAD_33_MASK  2
#define MACAD2_MACAD_34_MASK  4
#define MACAD2_MACAD_35_MASK  8
#define MACAD2_MACAD_36_MASK  16
#define MACAD2_MACAD_37_MASK  32
#define MACAD2_MACAD_38_MASK  64
#define MACAD2_MACAD_39_MASK  128
#define MACAD2_MACAD_40_MASK  256
#define MACAD2_MACAD_41_MASK  512
#define MACAD2_MACAD_42_MASK  1024
#define MACAD2_MACAD_43_MASK  2048
#define MACAD2_MACAD_44_MASK  4096
#define MACAD2_MACAD_45_MASK  8192
#define MACAD2_MACAD_46_MASK  16384
#define MACAD2_MACAD_47_MASK  32768
#define MACAD2_MACAD__32_MASK  65535
#define MACAD2_MACAD__32_BITNUM  0


/*** MACAD1 - MAC Address Register 1; 0x0000016A ***/
typedef union {
  word Word;
  struct {
    word MACAD_16    :1;                                       /* MAC Address Bit 16 */
    word MACAD_17    :1;                                       /* MAC Address Bit 17 */
    word MACAD_18    :1;                                       /* MAC Address Bit 18 */
    word MACAD_19    :1;                                       /* MAC Address Bit 19 */
    word MACAD_20    :1;                                       /* MAC Address Bit 20 */
    word MACAD_21    :1;                                       /* MAC Address Bit 21 */
    word MACAD_22    :1;                                       /* MAC Address Bit 22 */
    word MACAD_23    :1;                                       /* MAC Address Bit 23 */
    word MACAD_24    :1;                                       /* MAC Address Bit 24 */
    word MACAD_25    :1;                                       /* MAC Address Bit 25 */
    word MACAD_26    :1;                                       /* MAC Address Bit 26 */
    word MACAD_27    :1;                                       /* MAC Address Bit 27 */
    word MACAD_28    :1;                                       /* MAC Address Bit 28 */
    word MACAD_29    :1;                                       /* MAC Address Bit 29 */
    word MACAD_30    :1;                                       /* MAC Address Bit 30 */
    word MACAD_31    :1;                                       /* MAC Address Bit 31 */
  } Bits;
  struct {
    word grpMACAD__16 :16;
  } MergedBits;
} MACAD1STR;
extern volatile MACAD1STR _MACAD1 @(REG_BASE + 0x0000016A);
#define MACAD1 _MACAD1.Word
#define MACAD1_MACAD_16 _MACAD1.Bits.MACAD_16
#define MACAD1_MACAD_17 _MACAD1.Bits.MACAD_17
#define MACAD1_MACAD_18 _MACAD1.Bits.MACAD_18
#define MACAD1_MACAD_19 _MACAD1.Bits.MACAD_19
#define MACAD1_MACAD_20 _MACAD1.Bits.MACAD_20
#define MACAD1_MACAD_21 _MACAD1.Bits.MACAD_21
#define MACAD1_MACAD_22 _MACAD1.Bits.MACAD_22
#define MACAD1_MACAD_23 _MACAD1.Bits.MACAD_23
#define MACAD1_MACAD_24 _MACAD1.Bits.MACAD_24
#define MACAD1_MACAD_25 _MACAD1.Bits.MACAD_25
#define MACAD1_MACAD_26 _MACAD1.Bits.MACAD_26
#define MACAD1_MACAD_27 _MACAD1.Bits.MACAD_27
#define MACAD1_MACAD_28 _MACAD1.Bits.MACAD_28
#define MACAD1_MACAD_29 _MACAD1.Bits.MACAD_29
#define MACAD1_MACAD_30 _MACAD1.Bits.MACAD_30
#define MACAD1_MACAD_31 _MACAD1.Bits.MACAD_31
#define MACAD1_MACAD__16 _MACAD1.MergedBits.grpMACAD__16
#define MACAD1_MACAD_ MACAD1_MACAD__16

#define MACAD1_MACAD_16_MASK  1
#define MACAD1_MACAD_17_MASK  2
#define MACAD1_MACAD_18_MASK  4
#define MACAD1_MACAD_19_MASK  8
#define MACAD1_MACAD_20_MASK  16
#define MACAD1_MACAD_21_MASK  32
#define MACAD1_MACAD_22_MASK  64
#define MACAD1_MACAD_23_MASK  128
#define MACAD1_MACAD_24_MASK  256
#define MACAD1_MACAD_25_MASK  512
#define MACAD1_MACAD_26_MASK  1024
#define MACAD1_MACAD_27_MASK  2048
#define MACAD1_MACAD_28_MASK  4096
#define MACAD1_MACAD_29_MASK  8192
#define MACAD1_MACAD_30_MASK  16384
#define MACAD1_MACAD_31_MASK  32768
#define MACAD1_MACAD__16_MASK  65535
#define MACAD1_MACAD__16_BITNUM  0


/*** MACAD0 - MAC Address Register 0; 0x0000016C ***/
typedef union {
  word Word;
  struct {
    word MACAD_0     :1;                                       /* MAC Address Bit 0 */
    word MACAD_1     :1;                                       /* MAC Address Bit 1 */
    word MACAD_2     :1;                                       /* MAC Address Bit 2 */
    word MACAD_3     :1;                                       /* MAC Address Bit 3 */
    word MACAD_4     :1;                                       /* MAC Address Bit 4 */
    word MACAD_5     :1;                                       /* MAC Address Bit 5 */
    word MACAD_6     :1;                                       /* MAC Address Bit 6 */
    word MACAD_7     :1;                                       /* MAC Address Bit 7 */
    word MACAD_8     :1;                                       /* MAC Address Bit 8 */
    word MACAD_9     :1;                                       /* MAC Address Bit 9 */
    word MACAD_10    :1;                                       /* MAC Address Bit 10 */
    word MACAD_11    :1;                                       /* MAC Address Bit 11 */
    word MACAD_12    :1;                                       /* MAC Address Bit 12 */
    word MACAD_13    :1;                                       /* MAC Address Bit 13 */
    word MACAD_14    :1;                                       /* MAC Address Bit 14 */
    word MACAD_15    :1;                                       /* MAC Address Bit 15 */
  } Bits;
  struct {
    word grpMACAD :16;
  } MergedBits;
} MACAD0STR;
extern volatile MACAD0STR _MACAD0 @(REG_BASE + 0x0000016C);
#define MACAD0 _MACAD0.Word
#define MACAD0_MACAD_0 _MACAD0.Bits.MACAD_0
#define MACAD0_MACAD_1 _MACAD0.Bits.MACAD_1
#define MACAD0_MACAD_2 _MACAD0.Bits.MACAD_2
#define MACAD0_MACAD_3 _MACAD0.Bits.MACAD_3
#define MACAD0_MACAD_4 _MACAD0.Bits.MACAD_4
#define MACAD0_MACAD_5 _MACAD0.Bits.MACAD_5
#define MACAD0_MACAD_6 _MACAD0.Bits.MACAD_6
#define MACAD0_MACAD_7 _MACAD0.Bits.MACAD_7
#define MACAD0_MACAD_8 _MACAD0.Bits.MACAD_8
#define MACAD0_MACAD_9 _MACAD0.Bits.MACAD_9
#define MACAD0_MACAD_10 _MACAD0.Bits.MACAD_10
#define MACAD0_MACAD_11 _MACAD0.Bits.MACAD_11
#define MACAD0_MACAD_12 _MACAD0.Bits.MACAD_12
#define MACAD0_MACAD_13 _MACAD0.Bits.MACAD_13
#define MACAD0_MACAD_14 _MACAD0.Bits.MACAD_14
#define MACAD0_MACAD_15 _MACAD0.Bits.MACAD_15
#define MACAD0_MACAD _MACAD0.MergedBits.grpMACAD

#define MACAD0_MACAD_0_MASK  1
#define MACAD0_MACAD_1_MASK  2
#define MACAD0_MACAD_2_MASK  4
#define MACAD0_MACAD_3_MASK  8
#define MACAD0_MACAD_4_MASK  16
#define MACAD0_MACAD_5_MASK  32
#define MACAD0_MACAD_6_MASK  64
#define MACAD0_MACAD_7_MASK  128
#define MACAD0_MACAD_8_MASK  256
#define MACAD0_MACAD_9_MASK  512
#define MACAD0_MACAD_10_MASK  1024
#define MACAD0_MACAD_11_MASK  2048
#define MACAD0_MACAD_12_MASK  4096
#define MACAD0_MACAD_13_MASK  8192
#define MACAD0_MACAD_14_MASK  16384
#define MACAD0_MACAD_15_MASK  32768
#define MACAD0_MACAD_MASK  65535
#define MACAD0_MACAD_BITNUM  0


/*** EMISC - MAC Address Register 3; 0x0000016E ***/
typedef union {
  word Word;
  struct {
    word EMISC0      :1;                                       /* EMISC Bit 0 */
    word EMISC1      :1;                                       /* EMISC Bit 1 */
    word EMISC2      :1;                                       /* EMISC Bit 2 */
    word EMISC3      :1;                                       /* EMISC Bit 3 */
    word EMISC4      :1;                                       /* EMISC Bit 4 */
    word EMISC5      :1;                                       /* EMISC Bit 5 */
    word EMISC6      :1;                                       /* EMISC Bit 6 */
    word EMISC7      :1;                                       /* EMISC Bit 7 */
    word EMISC8      :1;                                       /* EMISC Bit 8 */
    word EMISC9      :1;                                       /* EMISC Bit 9 */
    word EMISC10     :1;                                       /* EMISC Bit 10 */
    word             :1; 
    word             :1; 
    word INDEX0      :1;                                       /* Miscellaneous Index Bit 0 */
    word INDEX1      :1;                                       /* Miscellaneous Index Bit 1 */
    word INDEX2      :1;                                       /* Miscellaneous Index Bit 2 */
  } Bits;
  struct {
    word grpEMISC :11;
    word         :1;
    word         :1;
    word grpINDEX :3;
  } MergedBits;
} EMISCSTR;
extern volatile EMISCSTR _EMISC @(REG_BASE + 0x0000016E);
#define EMISC                           _EMISC.Word
#define EMISC_EMISC0                    _EMISC.Bits.EMISC0
#define EMISC_EMISC1                    _EMISC.Bits.EMISC1
#define EMISC_EMISC2                    _EMISC.Bits.EMISC2
#define EMISC_EMISC3                    _EMISC.Bits.EMISC3
#define EMISC_EMISC4                    _EMISC.Bits.EMISC4
#define EMISC_EMISC5                    _EMISC.Bits.EMISC5
#define EMISC_EMISC6                    _EMISC.Bits.EMISC6
#define EMISC_EMISC7                    _EMISC.Bits.EMISC7
#define EMISC_EMISC8                    _EMISC.Bits.EMISC8
#define EMISC_EMISC9                    _EMISC.Bits.EMISC9
#define EMISC_EMISC10                   _EMISC.Bits.EMISC10
#define EMISC_INDEX0                    _EMISC.Bits.INDEX0
#define EMISC_INDEX1                    _EMISC.Bits.INDEX1
#define EMISC_INDEX2                    _EMISC.Bits.INDEX2
#define EMISC_EMISC                     _EMISC.MergedBits.grpEMISC
#define EMISC_INDEX                     _EMISC.MergedBits.grpINDEX

#define EMISC_EMISC0_MASK               1
#define EMISC_EMISC1_MASK               2
#define EMISC_EMISC2_MASK               4
#define EMISC_EMISC3_MASK               8
#define EMISC_EMISC4_MASK               16
#define EMISC_EMISC5_MASK               32
#define EMISC_EMISC6_MASK               64
#define EMISC_EMISC7_MASK               128
#define EMISC_EMISC8_MASK               256
#define EMISC_EMISC9_MASK               512
#define EMISC_EMISC10_MASK              1024
#define EMISC_INDEX0_MASK               8192
#define EMISC_INDEX1_MASK               16384
#define EMISC_INDEX2_MASK               32768
#define EMISC_EMISC_MASK                2047
#define EMISC_EMISC_BITNUM              0
#define EMISC_INDEX_MASK                57344
#define EMISC_INDEX_BITNUM              13


/*** PTT - Port T I/O Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTT4        :1;                                       /* Port T Bit 4 */
    byte PTT5        :1;                                       /* Port T Bit 5 */
    byte PTT6        :1;                                       /* Port T Bit 6 */
    byte PTT7        :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTT_4 :4;
  } MergedBits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240);
#define PTT _PTT.Byte
#define PTT_PTT4 _PTT.Bits.PTT4
#define PTT_PTT5 _PTT.Bits.PTT5
#define PTT_PTT6 _PTT.Bits.PTT6
#define PTT_PTT7 _PTT.Bits.PTT7
#define PTT_PTT_4 _PTT.MergedBits.grpPTT_4

#define PTT_PTT4_MASK  16
#define PTT_PTT5_MASK  32
#define PTT_PTT6_MASK  64
#define PTT_PTT7_MASK  128
#define PTT_PTT_4_MASK  240
#define PTT_PTT_4_BITNUM  4


/*** PTIT - Port T Input; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTIT4       :1;                                       /* Port T Bit 4 */
    byte PTIT5       :1;                                       /* Port T Bit 5 */
    byte PTIT6       :1;                                       /* Port T Bit 6 */
    byte PTIT7       :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTIT_4 :4;
  } MergedBits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241);
#define PTIT _PTIT.Byte
#define PTIT_PTIT4 _PTIT.Bits.PTIT4
#define PTIT_PTIT5 _PTIT.Bits.PTIT5
#define PTIT_PTIT6 _PTIT.Bits.PTIT6
#define PTIT_PTIT7 _PTIT.Bits.PTIT7
#define PTIT_PTIT_4 _PTIT.MergedBits.grpPTIT_4

#define PTIT_PTIT4_MASK  16
#define PTIT_PTIT5_MASK  32
#define PTIT_PTIT6_MASK  64
#define PTIT_PTIT7_MASK  128
#define PTIT_PTIT_4_MASK  240
#define PTIT_PTIT_4_BITNUM  4


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DDRT4       :1;                                       /* Data Direction Port T Bit 4 */
    byte DDRT5       :1;                                       /* Data Direction Port T Bit 5 */
    byte DDRT6       :1;                                       /* Data Direction Port T Bit 6 */
    byte DDRT7       :1;                                       /* Data Direction Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDDRT_4 :4;
  } MergedBits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242);
#define DDRT _DDRT.Byte
#define DDRT_DDRT4 _DDRT.Bits.DDRT4
#define DDRT_DDRT5 _DDRT.Bits.DDRT5
#define DDRT_DDRT6 _DDRT.Bits.DDRT6
#define DDRT_DDRT7 _DDRT.Bits.DDRT7
#define DDRT_DDRT_4 _DDRT.MergedBits.grpDDRT_4

#define DDRT_DDRT4_MASK  16
#define DDRT_DDRT5_MASK  32
#define DDRT_DDRT6_MASK  64
#define DDRT_DDRT7_MASK  128
#define DDRT_DDRT_4_MASK  240
#define DDRT_DDRT_4_BITNUM  4


/*** RDRT - Port T Reduced Drive Register; 0x00000243 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RDRT4       :1;                                       /* Reduced Drive Port T Bit 4 */
    byte RDRT5       :1;                                       /* Reduced Drive Port T Bit 5 */
    byte RDRT6       :1;                                       /* Reduced Drive Port T Bit 6 */
    byte RDRT7       :1;                                       /* Reduced Drive Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDRT_4 :4;
  } MergedBits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243);
#define RDRT _RDRT.Byte
#define RDRT_RDRT4 _RDRT.Bits.RDRT4
#define RDRT_RDRT5 _RDRT.Bits.RDRT5
#define RDRT_RDRT6 _RDRT.Bits.RDRT6
#define RDRT_RDRT7 _RDRT.Bits.RDRT7
#define RDRT_RDRT_4 _RDRT.MergedBits.grpRDRT_4

#define RDRT_RDRT4_MASK  16
#define RDRT_RDRT5_MASK  32
#define RDRT_RDRT6_MASK  64
#define RDRT_RDRT7_MASK  128
#define RDRT_RDRT_4_MASK  240
#define RDRT_RDRT_4_BITNUM  4


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PERT4       :1;                                       /* Pull Device Enable Port T Bit 4 */
    byte PERT5       :1;                                       /* Pull Device Enable Port T Bit 5 */
    byte PERT6       :1;                                       /* Pull Device Enable Port T Bit 6 */
    byte PERT7       :1;                                       /* Pull Device Enable Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPERT_4 :4;
  } MergedBits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244);
#define PERT _PERT.Byte
#define PERT_PERT4 _PERT.Bits.PERT4
#define PERT_PERT5 _PERT.Bits.PERT5
#define PERT_PERT6 _PERT.Bits.PERT6
#define PERT_PERT7 _PERT.Bits.PERT7
#define PERT_PERT_4 _PERT.MergedBits.grpPERT_4

#define PERT_PERT4_MASK  16
#define PERT_PERT5_MASK  32
#define PERT_PERT6_MASK  64
#define PERT_PERT7_MASK  128
#define PERT_PERT_4_MASK  240
#define PERT_PERT_4_BITNUM  4


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPST4       :1;                                       /* Pull Select Port T Bit 4 */
    byte PPST5       :1;                                       /* Pull Select Port T Bit 5 */
    byte PPST6       :1;                                       /* Pull Select Port T Bit 6 */
    byte PPST7       :1;                                       /* Pull Select Port T Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPPST_4 :4;
  } MergedBits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245);
#define PPST _PPST.Byte
#define PPST_PPST4 _PPST.Bits.PPST4
#define PPST_PPST5 _PPST.Bits.PPST5
#define PPST_PPST6 _PPST.Bits.PPST6
#define PPST_PPST7 _PPST.Bits.PPST7
#define PPST_PPST_4 _PPST.MergedBits.grpPPST_4

#define PPST_PPST4_MASK  16
#define PPST_PPST5_MASK  32
#define PPST_PPST6_MASK  64
#define PPST_PPST7_MASK  128
#define PPST_PPST_4_MASK  240
#define PPST_PPST_4_BITNUM  4


/*** PTS - Port S I/O Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S Bit 0 */
    byte PTS1        :1;                                       /* Port S Bit 1 */
    byte PTS2        :1;                                       /* Port S Bit 2 */
    byte PTS3        :1;                                       /* Port S Bit 3 */
    byte PTS4        :1;                                       /* Port S Bit 4 */
    byte PTS5        :1;                                       /* Port S Bit 5 */
    byte PTS6        :1;                                       /* Port S Bit 6 */
    byte PTS7        :1;                                       /* Port S Bit 7 */
  } Bits;
  struct {
    byte grpPTS  :8;
  } MergedBits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248);
#define PTS _PTS.Byte
#define PTS_PTS0 _PTS.Bits.PTS0
#define PTS_PTS1 _PTS.Bits.PTS1
#define PTS_PTS2 _PTS.Bits.PTS2
#define PTS_PTS3 _PTS.Bits.PTS3
#define PTS_PTS4 _PTS.Bits.PTS4
#define PTS_PTS5 _PTS.Bits.PTS5
#define PTS_PTS6 _PTS.Bits.PTS6
#define PTS_PTS7 _PTS.Bits.PTS7
#define PTS_PTS _PTS.MergedBits.grpPTS

#define PTS_PTS0_MASK  1
#define PTS_PTS1_MASK  2
#define PTS_PTS2_MASK  4
#define PTS_PTS3_MASK  8
#define PTS_PTS4_MASK  16
#define PTS_PTS5_MASK  32
#define PTS_PTS6_MASK  64
#define PTS_PTS7_MASK  128
#define PTS_PTS_MASK  255
#define PTS_PTS_BITNUM  0


/*** PTIS - Port S Input; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S Bit 0 */
    byte PTIS1       :1;                                       /* Port S Bit 1 */
    byte PTIS2       :1;                                       /* Port S Bit 2 */
    byte PTIS3       :1;                                       /* Port S Bit 3 */
    byte PTIS4       :1;                                       /* Port S Bit 4 */
    byte PTIS5       :1;                                       /* Port S Bit 5 */
    byte PTIS6       :1;                                       /* Port S Bit 6 */
    byte PTIS7       :1;                                       /* Port S Bit 7 */
  } Bits;
  struct {
    byte grpPTIS :8;
  } MergedBits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249);
#define PTIS _PTIS.Byte
#define PTIS_PTIS0 _PTIS.Bits.PTIS0
#define PTIS_PTIS1 _PTIS.Bits.PTIS1
#define PTIS_PTIS2 _PTIS.Bits.PTIS2
#define PTIS_PTIS3 _PTIS.Bits.PTIS3
#define PTIS_PTIS4 _PTIS.Bits.PTIS4
#define PTIS_PTIS5 _PTIS.Bits.PTIS5
#define PTIS_PTIS6 _PTIS.Bits.PTIS6
#define PTIS_PTIS7 _PTIS.Bits.PTIS7
#define PTIS_PTIS _PTIS.MergedBits.grpPTIS

#define PTIS_PTIS0_MASK  1
#define PTIS_PTIS1_MASK  2
#define PTIS_PTIS2_MASK  4
#define PTIS_PTIS3_MASK  8
#define PTIS_PTIS4_MASK  16
#define PTIS_PTIS5_MASK  32
#define PTIS_PTIS6_MASK  64
#define PTIS_PTIS7_MASK  128
#define PTIS_PTIS_MASK  255
#define PTIS_PTIS_BITNUM  0


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Data Direction Port S Bit 0 */
    byte DDRS1       :1;                                       /* Data Direction Port S Bit 1 */
    byte DDRS2       :1;                                       /* Data Direction Port S Bit  2 */
    byte DDRS3       :1;                                       /* Data Direction Port S Bit 3 */
    byte DDRS4       :1;                                       /* Data Direction Port S Bit 4 */
    byte DDRS5       :1;                                       /* Data Direction Port S Bit 5 */
    byte DDRS6       :1;                                       /* Data Direction Port S Bit 6 */
    byte DDRS7       :1;                                       /* Data Direction Port S Bit 7 */
  } Bits;
  struct {
    byte grpDDRS :8;
  } MergedBits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024A);
#define DDRS _DDRS.Byte
#define DDRS_DDRS0 _DDRS.Bits.DDRS0
#define DDRS_DDRS1 _DDRS.Bits.DDRS1
#define DDRS_DDRS2 _DDRS.Bits.DDRS2
#define DDRS_DDRS3 _DDRS.Bits.DDRS3
#define DDRS_DDRS4 _DDRS.Bits.DDRS4
#define DDRS_DDRS5 _DDRS.Bits.DDRS5
#define DDRS_DDRS6 _DDRS.Bits.DDRS6
#define DDRS_DDRS7 _DDRS.Bits.DDRS7
#define DDRS_DDRS _DDRS.MergedBits.grpDDRS

#define DDRS_DDRS0_MASK  1
#define DDRS_DDRS1_MASK  2
#define DDRS_DDRS2_MASK  4
#define DDRS_DDRS3_MASK  8
#define DDRS_DDRS4_MASK  16
#define DDRS_DDRS5_MASK  32
#define DDRS_DDRS6_MASK  64
#define DDRS_DDRS7_MASK  128
#define DDRS_DDRS_MASK  255
#define DDRS_DDRS_BITNUM  0


/*** RDRS - Port S Reduced Drive Register; 0x0000024B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRS0       :1;                                       /* Reduced Drive Port S Bit 0 */
    byte RDRS1       :1;                                       /* Reduced Drive Port S Bit 1 */
    byte RDRS2       :1;                                       /* Reduced Drive Port S Bit 2 */
    byte RDRS3       :1;                                       /* Reduced Drive Port S Bit 3 */
    byte RDRS4       :1;                                       /* Reduced Drive Port S Bit 4 */
    byte RDRS5       :1;                                       /* Reduced Drive Port S Bit 5 */
    byte RDRS6       :1;                                       /* Reduced Drive Port S Bit 6 */
    byte RDRS7       :1;                                       /* Reduced Drive Port S Bit 7 */
  } Bits;
  struct {
    byte grpRDRS :8;
  } MergedBits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024B);
#define RDRS _RDRS.Byte
#define RDRS_RDRS0 _RDRS.Bits.RDRS0
#define RDRS_RDRS1 _RDRS.Bits.RDRS1
#define RDRS_RDRS2 _RDRS.Bits.RDRS2
#define RDRS_RDRS3 _RDRS.Bits.RDRS3
#define RDRS_RDRS4 _RDRS.Bits.RDRS4
#define RDRS_RDRS5 _RDRS.Bits.RDRS5
#define RDRS_RDRS6 _RDRS.Bits.RDRS6
#define RDRS_RDRS7 _RDRS.Bits.RDRS7
#define RDRS_RDRS _RDRS.MergedBits.grpRDRS

#define RDRS_RDRS0_MASK  1
#define RDRS_RDRS1_MASK  2
#define RDRS_RDRS2_MASK  4
#define RDRS_RDRS3_MASK  8
#define RDRS_RDRS4_MASK  16
#define RDRS_RDRS5_MASK  32
#define RDRS_RDRS6_MASK  64
#define RDRS_RDRS7_MASK  128
#define RDRS_RDRS_MASK  255
#define RDRS_RDRS_BITNUM  0


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Pull Device Enable Port S Bit 0 */
    byte PERS1       :1;                                       /* Pull Device Enable Port S Bit 1 */
    byte PERS2       :1;                                       /* Pull Device Enable Port S Bit 2 */
    byte PERS3       :1;                                       /* Pull Device Enable Port S Bit 3 */
    byte PERS4       :1;                                       /* Pull Device Enable Port S Bit 4 */
    byte PERS5       :1;                                       /* Pull Device Enable Port S Bit 5 */
    byte PERS6       :1;                                       /* Pull Device Enable Port S Bit 6 */
    byte PERS7       :1;                                       /* Pull Device Enable Port S Bit 7 */
  } Bits;
  struct {
    byte grpPERS :8;
  } MergedBits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024C);
#define PERS _PERS.Byte
#define PERS_PERS0 _PERS.Bits.PERS0
#define PERS_PERS1 _PERS.Bits.PERS1
#define PERS_PERS2 _PERS.Bits.PERS2
#define PERS_PERS3 _PERS.Bits.PERS3
#define PERS_PERS4 _PERS.Bits.PERS4
#define PERS_PERS5 _PERS.Bits.PERS5
#define PERS_PERS6 _PERS.Bits.PERS6
#define PERS_PERS7 _PERS.Bits.PERS7
#define PERS_PERS _PERS.MergedBits.grpPERS

#define PERS_PERS0_MASK  1
#define PERS_PERS1_MASK  2
#define PERS_PERS2_MASK  4
#define PERS_PERS3_MASK  8
#define PERS_PERS4_MASK  16
#define PERS_PERS5_MASK  32
#define PERS_PERS6_MASK  64
#define PERS_PERS7_MASK  128
#define PERS_PERS_MASK  255
#define PERS_PERS_BITNUM  0


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Pull Select Port S Bit 0 */
    byte PPSS1       :1;                                       /* Pull Select Port S Bit 1 */
    byte PPSS2       :1;                                       /* Pull Select Port S Bit 2 */
    byte PPSS3       :1;                                       /* Pull Select Port S Bit 3 */
    byte PPSS4       :1;                                       /* Pull Select Port S Bit 4 */
    byte PPSS5       :1;                                       /* Pull Select Port S Bit 5 */
    byte PPSS6       :1;                                       /* Pull Select Port S Bit 6 */
    byte PPSS7       :1;                                       /* Pull Select Port S Bit 7 */
  } Bits;
  struct {
    byte grpPPSS :8;
  } MergedBits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024D);
#define PPSS _PPSS.Byte
#define PPSS_PPSS0 _PPSS.Bits.PPSS0
#define PPSS_PPSS1 _PPSS.Bits.PPSS1
#define PPSS_PPSS2 _PPSS.Bits.PPSS2
#define PPSS_PPSS3 _PPSS.Bits.PPSS3
#define PPSS_PPSS4 _PPSS.Bits.PPSS4
#define PPSS_PPSS5 _PPSS.Bits.PPSS5
#define PPSS_PPSS6 _PPSS.Bits.PPSS6
#define PPSS_PPSS7 _PPSS.Bits.PPSS7
#define PPSS_PPSS _PPSS.MergedBits.grpPPSS

#define PPSS_PPSS0_MASK  1
#define PPSS_PPSS1_MASK  2
#define PPSS_PPSS2_MASK  4
#define PPSS_PPSS3_MASK  8
#define PPSS_PPSS4_MASK  16
#define PPSS_PPSS5_MASK  32
#define PPSS_PPSS6_MASK  64
#define PPSS_PPSS7_MASK  128
#define PPSS_PPSS_MASK  255
#define PPSS_PPSS_BITNUM  0


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Wired-Or Mode Port S Bit 0 */
    byte WOMS1       :1;                                       /* Wired-Or Mode Port S Bit 1 */
    byte WOMS2       :1;                                       /* Wired-Or Mode Port S Bit 2 */
    byte WOMS3       :1;                                       /* Wired-Or Mode Port S Bit 3 */
    byte WOMS4       :1;                                       /* Wired-Or Mode Port S Bit 4 */
    byte WOMS5       :1;                                       /* Wired-Or Mode Port S Bit 5 */
    byte WOMS6       :1;                                       /* Wired-Or Mode Port S Bit 6 */
    byte WOMS7       :1;                                       /* Wired-Or Mode Port S Bit 7 */
  } Bits;
  struct {
    byte grpWOMS :8;
  } MergedBits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024E);
#define WOMS _WOMS.Byte
#define WOMS_WOMS0 _WOMS.Bits.WOMS0
#define WOMS_WOMS1 _WOMS.Bits.WOMS1
#define WOMS_WOMS2 _WOMS.Bits.WOMS2
#define WOMS_WOMS3 _WOMS.Bits.WOMS3
#define WOMS_WOMS4 _WOMS.Bits.WOMS4
#define WOMS_WOMS5 _WOMS.Bits.WOMS5
#define WOMS_WOMS6 _WOMS.Bits.WOMS6
#define WOMS_WOMS7 _WOMS.Bits.WOMS7
#define WOMS_WOMS _WOMS.MergedBits.grpWOMS

#define WOMS_WOMS0_MASK  1
#define WOMS_WOMS1_MASK  2
#define WOMS_WOMS2_MASK  4
#define WOMS_WOMS3_MASK  8
#define WOMS_WOMS4_MASK  16
#define WOMS_WOMS5_MASK  32
#define WOMS_WOMS6_MASK  64
#define WOMS_WOMS7_MASK  128
#define WOMS_WOMS_MASK  255
#define WOMS_WOMS_BITNUM  0


/*** PTG - Port G I/O Register; 0x00000250 ***/
typedef union {
  byte Byte;
  struct {
    byte PTG0        :1;                                       /* Port T Bit 0 */
    byte PTG1        :1;                                       /* Port T Bit 1 */
    byte PTG2        :1;                                       /* Port T Bit 2 */
    byte PTG3        :1;                                       /* Port T Bit 3 */
    byte PTG4        :1;                                       /* Port T Bit 4 */
    byte PTG5        :1;                                       /* Port T Bit 5 */
    byte PTG6        :1;                                       /* Port T Bit 6 */
    byte PTG7        :1;                                       /* Port T Bit 7 */
  } Bits;
  struct {
    byte grpPTG  :8;
  } MergedBits;
} PTGSTR;
extern volatile PTGSTR _PTG @(REG_BASE + 0x00000250);
#define PTG _PTG.Byte
#define PTG_PTG0 _PTG.Bits.PTG0
#define PTG_PTG1 _PTG.Bits.PTG1
#define PTG_PTG2 _PTG.Bits.PTG2
#define PTG_PTG3 _PTG.Bits.PTG3
#define PTG_PTG4 _PTG.Bits.PTG4
#define PTG_PTG5 _PTG.Bits.PTG5
#define PTG_PTG6 _PTG.Bits.PTG6
#define PTG_PTG7 _PTG.Bits.PTG7
#define PTG_PTG _PTG.MergedBits.grpPTG

#define PTG_PTG0_MASK  1
#define PTG_PTG1_MASK  2
#define PTG_PTG2_MASK  4
#define PTG_PTG3_MASK  8
#define PTG_PTG4_MASK  16
#define PTG_PTG5_MASK  32
#define PTG_PTG6_MASK  64
#define PTG_PTG7_MASK  128
#define PTG_PTG_MASK  255
#define PTG_PTG_BITNUM  0


/*** PTIG - Port G Input; 0x00000251 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIG0       :1;                                       /* Port G Bit 0 */
    byte PTIG1       :1;                                       /* Port G Bit 1 */
    byte PTIG2       :1;                                       /* Port G Bit 2 */
    byte PTIG3       :1;                                       /* Port G Bit 3 */
    byte PTIG4       :1;                                       /* Port G Bit 4 */
    byte PTIG5       :1;                                       /* Port G Bit 5 */
    byte PTIG6       :1;                                       /* Port G Bit 6 */
    byte PTIG7       :1;                                       /* Port G Bit 7 */
  } Bits;
  struct {
    byte grpPTIG :8;
  } MergedBits;
} PTIGSTR;
extern volatile PTIGSTR _PTIG @(REG_BASE + 0x00000251);
#define PTIG _PTIG.Byte
#define PTIG_PTIG0 _PTIG.Bits.PTIG0
#define PTIG_PTIG1 _PTIG.Bits.PTIG1
#define PTIG_PTIG2 _PTIG.Bits.PTIG2
#define PTIG_PTIG3 _PTIG.Bits.PTIG3
#define PTIG_PTIG4 _PTIG.Bits.PTIG4
#define PTIG_PTIG5 _PTIG.Bits.PTIG5
#define PTIG_PTIG6 _PTIG.Bits.PTIG6
#define PTIG_PTIG7 _PTIG.Bits.PTIG7
#define PTIG_PTIG _PTIG.MergedBits.grpPTIG

#define PTIG_PTIG0_MASK  1
#define PTIG_PTIG1_MASK  2
#define PTIG_PTIG2_MASK  4
#define PTIG_PTIG3_MASK  8
#define PTIG_PTIG4_MASK  16
#define PTIG_PTIG5_MASK  32
#define PTIG_PTIG6_MASK  64
#define PTIG_PTIG7_MASK  128
#define PTIG_PTIG_MASK  255
#define PTIG_PTIG_BITNUM  0


/*** DDRG - Port G Data Direction Register; 0x00000252 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRG0       :1;                                       /* Data Direction Port G Bit 0 */
    byte DDRG1       :1;                                       /* Data Direction Port G Bit 1 */
    byte DDRG2       :1;                                       /* Data Direction Port G Bit 2 */
    byte DDRG3       :1;                                       /* Data Direction Port G Bit 3 */
    byte DDRG4       :1;                                       /* Data Direction Port G Bit 4 */
    byte DDRG5       :1;                                       /* Data Direction Port G Bit 5 */
    byte DDRG6       :1;                                       /* Data Direction Port G Bit 6 */
    byte DDRG7       :1;                                       /* Data Direction Port G Bit 7 */
  } Bits;
  struct {
    byte grpDDRG :8;
  } MergedBits;
} DDRGSTR;
extern volatile DDRGSTR _DDRG @(REG_BASE + 0x00000252);
#define DDRG _DDRG.Byte
#define DDRG_DDRG0 _DDRG.Bits.DDRG0
#define DDRG_DDRG1 _DDRG.Bits.DDRG1
#define DDRG_DDRG2 _DDRG.Bits.DDRG2
#define DDRG_DDRG3 _DDRG.Bits.DDRG3
#define DDRG_DDRG4 _DDRG.Bits.DDRG4
#define DDRG_DDRG5 _DDRG.Bits.DDRG5
#define DDRG_DDRG6 _DDRG.Bits.DDRG6
#define DDRG_DDRG7 _DDRG.Bits.DDRG7
#define DDRG_DDRG _DDRG.MergedBits.grpDDRG

#define DDRG_DDRG0_MASK  1
#define DDRG_DDRG1_MASK  2
#define DDRG_DDRG2_MASK  4
#define DDRG_DDRG3_MASK  8
#define DDRG_DDRG4_MASK  16
#define DDRG_DDRG5_MASK  32
#define DDRG_DDRG6_MASK  64
#define DDRG_DDRG7_MASK  128
#define DDRG_DDRG_MASK  255
#define DDRG_DDRG_BITNUM  0


/*** RDRG - Port G Reduced Drive Register; 0x00000253 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRG0       :1;                                       /* Reduced Drive Port G Bit 0 */
    byte RDRG1       :1;                                       /* Reduced Drive Port G Bit 1 */
    byte RDRG2       :1;                                       /* Reduced Drive Port G Bit 2 */
    byte RDRG3       :1;                                       /* Reduced Drive Port G Bit 3 */
    byte RDRG4       :1;                                       /* Reduced Drive Port G Bit 4 */
    byte RDRG5       :1;                                       /* Reduced Drive Port G Bit 5 */
    byte RDRG6       :1;                                       /* Reduced Drive Port G Bit 6 */
    byte RDRG7       :1;                                       /* Reduced Drive Port G Bit 7 */
  } Bits;
  struct {
    byte grpRDRG :8;
  } MergedBits;
} RDRGSTR;
extern volatile RDRGSTR _RDRG @(REG_BASE + 0x00000253);
#define RDRG _RDRG.Byte
#define RDRG_RDRG0 _RDRG.Bits.RDRG0
#define RDRG_RDRG1 _RDRG.Bits.RDRG1
#define RDRG_RDRG2 _RDRG.Bits.RDRG2
#define RDRG_RDRG3 _RDRG.Bits.RDRG3
#define RDRG_RDRG4 _RDRG.Bits.RDRG4
#define RDRG_RDRG5 _RDRG.Bits.RDRG5
#define RDRG_RDRG6 _RDRG.Bits.RDRG6
#define RDRG_RDRG7 _RDRG.Bits.RDRG7
#define RDRG_RDRG _RDRG.MergedBits.grpRDRG

#define RDRG_RDRG0_MASK  1
#define RDRG_RDRG1_MASK  2
#define RDRG_RDRG2_MASK  4
#define RDRG_RDRG3_MASK  8
#define RDRG_RDRG4_MASK  16
#define RDRG_RDRG5_MASK  32
#define RDRG_RDRG6_MASK  64
#define RDRG_RDRG7_MASK  128
#define RDRG_RDRG_MASK  255
#define RDRG_RDRG_BITNUM  0


/*** PERG - Port G Pull Device Enable Register; 0x00000254 ***/
typedef union {
  byte Byte;
  struct {
    byte PERG0       :1;                                       /* Pull Device Enable Port G Bit 0 */
    byte PERG1       :1;                                       /* Pull Device Enable Port G Bit 1 */
    byte PERG2       :1;                                       /* Pull Device Enable Port G Bit 2 */
    byte PERG3       :1;                                       /* Pull Device Enable Port G Bit 3 */
    byte PERG4       :1;                                       /* Pull Device Enable Port G Bit 4 */
    byte PERG5       :1;                                       /* Pull Device Enable Port G Bit 5 */
    byte PERG6       :1;                                       /* Pull Device Enable Port G Bit 6 */
    byte PERG7       :1;                                       /* Pull Device Enable Port G Bit 7 */
  } Bits;
  struct {
    byte grpPERG :8;
  } MergedBits;
} PERGSTR;
extern volatile PERGSTR _PERG @(REG_BASE + 0x00000254);
#define PERG _PERG.Byte
#define PERG_PERG0 _PERG.Bits.PERG0
#define PERG_PERG1 _PERG.Bits.PERG1
#define PERG_PERG2 _PERG.Bits.PERG2
#define PERG_PERG3 _PERG.Bits.PERG3
#define PERG_PERG4 _PERG.Bits.PERG4
#define PERG_PERG5 _PERG.Bits.PERG5
#define PERG_PERG6 _PERG.Bits.PERG6
#define PERG_PERG7 _PERG.Bits.PERG7
#define PERG_PERG _PERG.MergedBits.grpPERG

#define PERG_PERG0_MASK  1
#define PERG_PERG1_MASK  2
#define PERG_PERG2_MASK  4
#define PERG_PERG3_MASK  8
#define PERG_PERG4_MASK  16
#define PERG_PERG5_MASK  32
#define PERG_PERG6_MASK  64
#define PERG_PERG7_MASK  128
#define PERG_PERG_MASK  255
#define PERG_PERG_BITNUM  0


/*** PPSG - Port G Polarity Select Register; 0x00000255 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSG0       :1;                                       /* Pull Select Port G Bit 0 */
    byte PPSG1       :1;                                       /* Pull Select Port G Bit 1 */
    byte PPSG2       :1;                                       /* Pull Select Port G Bit 2 */
    byte PPSG3       :1;                                       /* Pull Select Port G Bit 3 */
    byte PPSG4       :1;                                       /* Pull Select Port G Bit 4 */
    byte PPSG5       :1;                                       /* Pull Select Port G Bit 5 */
    byte PPSG6       :1;                                       /* Pull Select Port G Bit 6 */
    byte PPSG7       :1;                                       /* Pull Select Port G Bit 7 */
  } Bits;
  struct {
    byte grpPPSG :8;
  } MergedBits;
} PPSGSTR;
extern volatile PPSGSTR _PPSG @(REG_BASE + 0x00000255);
#define PPSG _PPSG.Byte
#define PPSG_PPSG0 _PPSG.Bits.PPSG0
#define PPSG_PPSG1 _PPSG.Bits.PPSG1
#define PPSG_PPSG2 _PPSG.Bits.PPSG2
#define PPSG_PPSG3 _PPSG.Bits.PPSG3
#define PPSG_PPSG4 _PPSG.Bits.PPSG4
#define PPSG_PPSG5 _PPSG.Bits.PPSG5
#define PPSG_PPSG6 _PPSG.Bits.PPSG6
#define PPSG_PPSG7 _PPSG.Bits.PPSG7
#define PPSG_PPSG _PPSG.MergedBits.grpPPSG

#define PPSG_PPSG0_MASK  1
#define PPSG_PPSG1_MASK  2
#define PPSG_PPSG2_MASK  4
#define PPSG_PPSG3_MASK  8
#define PPSG_PPSG4_MASK  16
#define PPSG_PPSG5_MASK  32
#define PPSG_PPSG6_MASK  64
#define PPSG_PPSG7_MASK  128
#define PPSG_PPSG_MASK  255
#define PPSG_PPSG_BITNUM  0


/*** PIEG - Port G Interrupt Enable Register; 0x00000256 ***/
typedef union {
  byte Byte;
  struct {
    byte PIEG0       :1;                                       /* Interrupt Enable Port G Bit 0 */
    byte PIEG1       :1;                                       /* Interrupt Enable Port G Bit 1 */
    byte PIEG2       :1;                                       /* Interrupt Enable Port G Bit 2 */
    byte PIEG3       :1;                                       /* Interrupt Enable Port G Bit 3 */
    byte PIEG4       :1;                                       /* Interrupt Enable Port G Bit 4 */
    byte PIEG5       :1;                                       /* Interrupt Enable Port G Bit 5 */
    byte PIEG6       :1;                                       /* Interrupt Enable Port G Bit 6 */
    byte PIEG7       :1;                                       /* Interrupt Enable Port G Bit 7 */
  } Bits;
  struct {
    byte grpPIEG :8;
  } MergedBits;
} PIEGSTR;
extern volatile PIEGSTR _PIEG @(REG_BASE + 0x00000256);
#define PIEG _PIEG.Byte
#define PIEG_PIEG0 _PIEG.Bits.PIEG0
#define PIEG_PIEG1 _PIEG.Bits.PIEG1
#define PIEG_PIEG2 _PIEG.Bits.PIEG2
#define PIEG_PIEG3 _PIEG.Bits.PIEG3
#define PIEG_PIEG4 _PIEG.Bits.PIEG4
#define PIEG_PIEG5 _PIEG.Bits.PIEG5
#define PIEG_PIEG6 _PIEG.Bits.PIEG6
#define PIEG_PIEG7 _PIEG.Bits.PIEG7
#define PIEG_PIEG _PIEG.MergedBits.grpPIEG

#define PIEG_PIEG0_MASK  1
#define PIEG_PIEG1_MASK  2
#define PIEG_PIEG2_MASK  4
#define PIEG_PIEG3_MASK  8
#define PIEG_PIEG4_MASK  16
#define PIEG_PIEG5_MASK  32
#define PIEG_PIEG6_MASK  64
#define PIEG_PIEG7_MASK  128
#define PIEG_PIEG_MASK  255
#define PIEG_PIEG_BITNUM  0


/*** PIFG - Port G Interrupt Flag Register; 0x00000257 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFG0       :1;                                       /* Interrupt Flags Port G Bit 0 */
    byte PIFG1       :1;                                       /* Interrupt Flags Port G Bit 1 */
    byte PIFG2       :1;                                       /* Interrupt Flags Port G Bit 2 */
    byte PIFG3       :1;                                       /* Interrupt Flags Port G Bit 3 */
    byte PIFG4       :1;                                       /* Interrupt Flags Port G Bit 4 */
    byte PIFG5       :1;                                       /* Interrupt Flags Port G Bit 5 */
    byte PIFG6       :1;                                       /* Interrupt Flags Port G Bit 6 */
    byte PIFG7       :1;                                       /* Interrupt Flags Port G Bit 7 */
  } Bits;
  struct {
    byte grpPIFG :8;
  } MergedBits;
} PIFGSTR;
extern volatile PIFGSTR _PIFG @(REG_BASE + 0x00000257);
#define PIFG _PIFG.Byte
#define PIFG_PIFG0 _PIFG.Bits.PIFG0
#define PIFG_PIFG1 _PIFG.Bits.PIFG1
#define PIFG_PIFG2 _PIFG.Bits.PIFG2
#define PIFG_PIFG3 _PIFG.Bits.PIFG3
#define PIFG_PIFG4 _PIFG.Bits.PIFG4
#define PIFG_PIFG5 _PIFG.Bits.PIFG5
#define PIFG_PIFG6 _PIFG.Bits.PIFG6
#define PIFG_PIFG7 _PIFG.Bits.PIFG7
#define PIFG_PIFG _PIFG.MergedBits.grpPIFG

#define PIFG_PIFG0_MASK  1
#define PIFG_PIFG1_MASK  2
#define PIFG_PIFG2_MASK  4
#define PIFG_PIFG3_MASK  8
#define PIFG_PIFG4_MASK  16
#define PIFG_PIFG5_MASK  32
#define PIFG_PIFG6_MASK  64
#define PIFG_PIFG7_MASK  128
#define PIFG_PIFG_MASK  255
#define PIFG_PIFG_BITNUM  0


/*** PTH - Port H I/O Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTH0        :1;                                       /* Port H Bit 0 */
    byte PTH1        :1;                                       /* Port H Bit 1 */
    byte PTH2        :1;                                       /* Port H Bit 2 */
    byte PTH3        :1;                                       /* Port H Bit 3 */
    byte PTH4        :1;                                       /* Port H Bit 4 */
    byte PTH5        :1;                                       /* Port H Bit 5 */
    byte PTH6        :1;                                       /* Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTH  :7;
    byte         :1;
  } MergedBits;
} PTHSTR;
extern volatile PTHSTR _PTH @(REG_BASE + 0x00000258);
#define PTH _PTH.Byte
#define PTH_PTH0 _PTH.Bits.PTH0
#define PTH_PTH1 _PTH.Bits.PTH1
#define PTH_PTH2 _PTH.Bits.PTH2
#define PTH_PTH3 _PTH.Bits.PTH3
#define PTH_PTH4 _PTH.Bits.PTH4
#define PTH_PTH5 _PTH.Bits.PTH5
#define PTH_PTH6 _PTH.Bits.PTH6
#define PTH_PTH _PTH.MergedBits.grpPTH

#define PTH_PTH0_MASK  1
#define PTH_PTH1_MASK  2
#define PTH_PTH2_MASK  4
#define PTH_PTH3_MASK  8
#define PTH_PTH4_MASK  16
#define PTH_PTH5_MASK  32
#define PTH_PTH6_MASK  64
#define PTH_PTH_MASK  127
#define PTH_PTH_BITNUM  0


/*** PTIH - Port H Input Register; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIH0       :1;                                       /* Port H Bit 0 */
    byte PTIH1       :1;                                       /* Port H Bit 1 */
    byte PTIH2       :1;                                       /* Port H Bit 2 */
    byte PTIH3       :1;                                       /* Port H Bit 3 */
    byte PTIH4       :1;                                       /* Port H Bit 4 */
    byte PTIH5       :1;                                       /* Port H Bit 5 */
    byte PTIH6       :1;                                       /* Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIH :7;
    byte         :1;
  } MergedBits;
} PTIHSTR;
extern volatile PTIHSTR _PTIH @(REG_BASE + 0x00000259);
#define PTIH _PTIH.Byte
#define PTIH_PTIH0 _PTIH.Bits.PTIH0
#define PTIH_PTIH1 _PTIH.Bits.PTIH1
#define PTIH_PTIH2 _PTIH.Bits.PTIH2
#define PTIH_PTIH3 _PTIH.Bits.PTIH3
#define PTIH_PTIH4 _PTIH.Bits.PTIH4
#define PTIH_PTIH5 _PTIH.Bits.PTIH5
#define PTIH_PTIH6 _PTIH.Bits.PTIH6
#define PTIH_PTIH _PTIH.MergedBits.grpPTIH

#define PTIH_PTIH0_MASK  1
#define PTIH_PTIH1_MASK  2
#define PTIH_PTIH2_MASK  4
#define PTIH_PTIH3_MASK  8
#define PTIH_PTIH4_MASK  16
#define PTIH_PTIH5_MASK  32
#define PTIH_PTIH6_MASK  64
#define PTIH_PTIH_MASK  127
#define PTIH_PTIH_BITNUM  0


/*** DDRH - Port H Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRH0       :1;                                       /* Data Direction Port H Bit 0 */
    byte DDRH1       :1;                                       /* Data Direction Port H Bit 1 */
    byte DDRH2       :1;                                       /* Data Direction Port H Bit 2 */
    byte DDRH3       :1;                                       /* Data Direction Port H Bit 3 */
    byte DDRH4       :1;                                       /* Data Direction Port H Bit 4 */
    byte DDRH5       :1;                                       /* Data Direction Port H Bit 5 */
    byte DDRH6       :1;                                       /* Data Direction Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRH :7;
    byte         :1;
  } MergedBits;
} DDRHSTR;
extern volatile DDRHSTR _DDRH @(REG_BASE + 0x0000025A);
#define DDRH _DDRH.Byte
#define DDRH_DDRH0 _DDRH.Bits.DDRH0
#define DDRH_DDRH1 _DDRH.Bits.DDRH1
#define DDRH_DDRH2 _DDRH.Bits.DDRH2
#define DDRH_DDRH3 _DDRH.Bits.DDRH3
#define DDRH_DDRH4 _DDRH.Bits.DDRH4
#define DDRH_DDRH5 _DDRH.Bits.DDRH5
#define DDRH_DDRH6 _DDRH.Bits.DDRH6
#define DDRH_DDRH _DDRH.MergedBits.grpDDRH

#define DDRH_DDRH0_MASK  1
#define DDRH_DDRH1_MASK  2
#define DDRH_DDRH2_MASK  4
#define DDRH_DDRH3_MASK  8
#define DDRH_DDRH4_MASK  16
#define DDRH_DDRH5_MASK  32
#define DDRH_DDRH6_MASK  64
#define DDRH_DDRH_MASK  127
#define DDRH_DDRH_BITNUM  0


/*** RDRH - Port H Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRH0       :1;                                       /* Reduced Drive Port H Bit 0 */
    byte RDRH1       :1;                                       /* Reduced Drive Port H Bit 1 */
    byte RDRH2       :1;                                       /* Reduced Drive Port H Bit 2 */
    byte RDRH3       :1;                                       /* Reduced Drive Port H Bit 3 */
    byte RDRH4       :1;                                       /* Reduced Drive Port H Bit 4 */
    byte RDRH5       :1;                                       /* Reduced Drive Port H Bit 5 */
    byte RDRH6       :1;                                       /* Reduced Drive Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpRDRH :7;
    byte         :1;
  } MergedBits;
} RDRHSTR;
extern volatile RDRHSTR _RDRH @(REG_BASE + 0x0000025B);
#define RDRH _RDRH.Byte
#define RDRH_RDRH0 _RDRH.Bits.RDRH0
#define RDRH_RDRH1 _RDRH.Bits.RDRH1
#define RDRH_RDRH2 _RDRH.Bits.RDRH2
#define RDRH_RDRH3 _RDRH.Bits.RDRH3
#define RDRH_RDRH4 _RDRH.Bits.RDRH4
#define RDRH_RDRH5 _RDRH.Bits.RDRH5
#define RDRH_RDRH6 _RDRH.Bits.RDRH6
#define RDRH_RDRH _RDRH.MergedBits.grpRDRH

#define RDRH_RDRH0_MASK  1
#define RDRH_RDRH1_MASK  2
#define RDRH_RDRH2_MASK  4
#define RDRH_RDRH3_MASK  8
#define RDRH_RDRH4_MASK  16
#define RDRH_RDRH5_MASK  32
#define RDRH_RDRH6_MASK  64
#define RDRH_RDRH_MASK  127
#define RDRH_RDRH_BITNUM  0


/*** PERH - Port H Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERH0       :1;                                       /* Pull Device Enable Port H Bit 0 */
    byte PERH1       :1;                                       /* Pull Device Enable Port H Bit 1 */
    byte PERH2       :1;                                       /* Pull Device Enable Port H Bit 2 */
    byte PERH3       :1;                                       /* Pull Device Enable Port H Bit 3 */
    byte PERH4       :1;                                       /* Pull Device Enable Port H Bit 4 */
    byte PERH5       :1;                                       /* Pull Device Enable Port H Bit 5 */
    byte PERH6       :1;                                       /* Pull Device Enable Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPERH :7;
    byte         :1;
  } MergedBits;
} PERHSTR;
extern volatile PERHSTR _PERH @(REG_BASE + 0x0000025C);
#define PERH _PERH.Byte
#define PERH_PERH0 _PERH.Bits.PERH0
#define PERH_PERH1 _PERH.Bits.PERH1
#define PERH_PERH2 _PERH.Bits.PERH2
#define PERH_PERH3 _PERH.Bits.PERH3
#define PERH_PERH4 _PERH.Bits.PERH4
#define PERH_PERH5 _PERH.Bits.PERH5
#define PERH_PERH6 _PERH.Bits.PERH6
#define PERH_PERH _PERH.MergedBits.grpPERH

#define PERH_PERH0_MASK  1
#define PERH_PERH1_MASK  2
#define PERH_PERH2_MASK  4
#define PERH_PERH3_MASK  8
#define PERH_PERH4_MASK  16
#define PERH_PERH5_MASK  32
#define PERH_PERH6_MASK  64
#define PERH_PERH_MASK  127
#define PERH_PERH_BITNUM  0


/*** PPSH - Port H Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSH0       :1;                                       /* Pull Select Port H Bit 0 */
    byte PPSH1       :1;                                       /* Pull Select Port H Bit 1 */
    byte PPSH2       :1;                                       /* Pull Select Port H Bit 2 */
    byte PPSH3       :1;                                       /* Pull Select Port H Bit 3 */
    byte PPSH4       :1;                                       /* Pull Select Port H Bit 4 */
    byte PPSH5       :1;                                       /* Pull Select Port H Bit 5 */
    byte PPSH6       :1;                                       /* Pull Select Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSH :7;
    byte         :1;
  } MergedBits;
} PPSHSTR;
extern volatile PPSHSTR _PPSH @(REG_BASE + 0x0000025D);
#define PPSH _PPSH.Byte
#define PPSH_PPSH0 _PPSH.Bits.PPSH0
#define PPSH_PPSH1 _PPSH.Bits.PPSH1
#define PPSH_PPSH2 _PPSH.Bits.PPSH2
#define PPSH_PPSH3 _PPSH.Bits.PPSH3
#define PPSH_PPSH4 _PPSH.Bits.PPSH4
#define PPSH_PPSH5 _PPSH.Bits.PPSH5
#define PPSH_PPSH6 _PPSH.Bits.PPSH6
#define PPSH_PPSH _PPSH.MergedBits.grpPPSH

#define PPSH_PPSH0_MASK  1
#define PPSH_PPSH1_MASK  2
#define PPSH_PPSH2_MASK  4
#define PPSH_PPSH3_MASK  8
#define PPSH_PPSH4_MASK  16
#define PPSH_PPSH5_MASK  32
#define PPSH_PPSH6_MASK  64
#define PPSH_PPSH_MASK  127
#define PPSH_PPSH_BITNUM  0


/*** PIEH - Port H Interrupt Enable Register; 0x0000025E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEH0       :1;                                       /* Interrupt Enable Port H Bit 0 */
    byte PIEH1       :1;                                       /* Interrupt Enable Port H Bit 1 */
    byte PIEH2       :1;                                       /* Interrupt Enable Port H Bit 2 */
    byte PIEH3       :1;                                       /* Interrupt Enable Port H Bit 3 */
    byte PIEH4       :1;                                       /* Interrupt Enable Port H Bit 4 */
    byte PIEH5       :1;                                       /* Interrupt Enable Port H Bit 5 */
    byte PIEH6       :1;                                       /* Interrupt Enable Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPIEH :7;
    byte         :1;
  } MergedBits;
} PIEHSTR;
extern volatile PIEHSTR _PIEH @(REG_BASE + 0x0000025E);
#define PIEH _PIEH.Byte
#define PIEH_PIEH0 _PIEH.Bits.PIEH0
#define PIEH_PIEH1 _PIEH.Bits.PIEH1
#define PIEH_PIEH2 _PIEH.Bits.PIEH2
#define PIEH_PIEH3 _PIEH.Bits.PIEH3
#define PIEH_PIEH4 _PIEH.Bits.PIEH4
#define PIEH_PIEH5 _PIEH.Bits.PIEH5
#define PIEH_PIEH6 _PIEH.Bits.PIEH6
#define PIEH_PIEH _PIEH.MergedBits.grpPIEH

#define PIEH_PIEH0_MASK  1
#define PIEH_PIEH1_MASK  2
#define PIEH_PIEH2_MASK  4
#define PIEH_PIEH3_MASK  8
#define PIEH_PIEH4_MASK  16
#define PIEH_PIEH5_MASK  32
#define PIEH_PIEH6_MASK  64
#define PIEH_PIEH_MASK  127
#define PIEH_PIEH_BITNUM  0


/*** PIFH - Port H Interrupt Flag Register; 0x0000025F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFH0       :1;                                       /* Interrupt Flags Port H Bit 0 */
    byte PIFH1       :1;                                       /* Interrupt Flags Port H Bit 1 */
    byte PIFH2       :1;                                       /* Interrupt Flags Port H Bit 2 */
    byte PIFH3       :1;                                       /* Interrupt Flags Port H Bit 3 */
    byte PIFH4       :1;                                       /* Interrupt Flags Port H Bit 4 */
    byte PIFH5       :1;                                       /* Interrupt Flags Port H Bit 5 */
    byte PIFH6       :1;                                       /* Interrupt Flags Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPIFH :7;
    byte         :1;
  } MergedBits;
} PIFHSTR;
extern volatile PIFHSTR _PIFH @(REG_BASE + 0x0000025F);
#define PIFH _PIFH.Byte
#define PIFH_PIFH0 _PIFH.Bits.PIFH0
#define PIFH_PIFH1 _PIFH.Bits.PIFH1
#define PIFH_PIFH2 _PIFH.Bits.PIFH2
#define PIFH_PIFH3 _PIFH.Bits.PIFH3
#define PIFH_PIFH4 _PIFH.Bits.PIFH4
#define PIFH_PIFH5 _PIFH.Bits.PIFH5
#define PIFH_PIFH6 _PIFH.Bits.PIFH6
#define PIFH_PIFH _PIFH.MergedBits.grpPIFH

#define PIFH_PIFH0_MASK  1
#define PIFH_PIFH1_MASK  2
#define PIFH_PIFH2_MASK  4
#define PIFH_PIFH3_MASK  8
#define PIFH_PIFH4_MASK  16
#define PIFH_PIFH5_MASK  32
#define PIFH_PIFH6_MASK  64
#define PIFH_PIFH_MASK  127
#define PIFH_PIFH_BITNUM  0


/*** PTJ - Port J I/O Register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJ0        :1;                                       /* Port J Bit 0 */
    byte PTJ1        :1;                                       /* Port J Bit 1 */
    byte PTJ2        :1;                                       /* Port J Bit 2 */
    byte PTJ3        :1;                                       /* Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTJ6        :1;                                       /* Port J Bit 6 */
    byte PTJ7        :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte grpPTJ  :4;
    byte         :1;
    byte         :1;
    byte grpPTJ_6 :2;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000260);
#define PTJ _PTJ.Byte
#define PTJ_PTJ0 _PTJ.Bits.PTJ0
#define PTJ_PTJ1 _PTJ.Bits.PTJ1
#define PTJ_PTJ2 _PTJ.Bits.PTJ2
#define PTJ_PTJ3 _PTJ.Bits.PTJ3
#define PTJ_PTJ6 _PTJ.Bits.PTJ6
#define PTJ_PTJ7 _PTJ.Bits.PTJ7
#define PTJ_PTJ _PTJ.MergedBits.grpPTJ
#define PTJ_PTJ_6 _PTJ.MergedBits.grpPTJ_6

#define PTJ_PTJ0_MASK  1
#define PTJ_PTJ1_MASK  2
#define PTJ_PTJ2_MASK  4
#define PTJ_PTJ3_MASK  8
#define PTJ_PTJ6_MASK  64
#define PTJ_PTJ7_MASK  128
#define PTJ_PTJ_MASK  15
#define PTJ_PTJ_BITNUM  0
#define PTJ_PTJ_6_MASK  192
#define PTJ_PTJ_6_BITNUM  6


/*** PTIJ - Port J Input Register; 0x00000261 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIJ0       :1;                                       /* Port J Bit 0 */
    byte PTIJ1       :1;                                       /* Port J Bit 1 */
    byte PTIJ2       :1;                                       /* Port J Bit 2 */
    byte PTIJ3       :1;                                       /* Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PTIJ6       :1;                                       /* Port J Bit 6 */
    byte PTIJ7       :1;                                       /* Port J Bit 7 */
  } Bits;
  struct {
    byte grpPTIJ :4;
    byte         :1;
    byte         :1;
    byte grpPTIJ_6 :2;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000261);
#define PTIJ _PTIJ.Byte
#define PTIJ_PTIJ0 _PTIJ.Bits.PTIJ0
#define PTIJ_PTIJ1 _PTIJ.Bits.PTIJ1
#define PTIJ_PTIJ2 _PTIJ.Bits.PTIJ2
#define PTIJ_PTIJ3 _PTIJ.Bits.PTIJ3
#define PTIJ_PTIJ6 _PTIJ.Bits.PTIJ6
#define PTIJ_PTIJ7 _PTIJ.Bits.PTIJ7
#define PTIJ_PTIJ _PTIJ.MergedBits.grpPTIJ
#define PTIJ_PTIJ_6 _PTIJ.MergedBits.grpPTIJ_6

#define PTIJ_PTIJ0_MASK  1
#define PTIJ_PTIJ1_MASK  2
#define PTIJ_PTIJ2_MASK  4
#define PTIJ_PTIJ3_MASK  8
#define PTIJ_PTIJ6_MASK  64
#define PTIJ_PTIJ7_MASK  128
#define PTIJ_PTIJ_MASK  15
#define PTIJ_PTIJ_BITNUM  0
#define PTIJ_PTIJ_6_MASK  192
#define PTIJ_PTIJ_6_BITNUM  6


/*** DDRJ - Port J Data Direction Register; 0x00000262 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRJ0       :1;                                       /* Data Direction Port J Bit 0 */
    byte DDRJ1       :1;                                       /* Data Direction Port J Bit 1 */
    byte DDRJ2       :1;                                       /* Data Direction Port J Bit 2 */
    byte DDRJ3       :1;                                       /* Data Direction Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte DDRJ6       :1;                                       /* Data Direction Port J Bit 6 */
    byte DDRJ7       :1;                                       /* Data Direction Port J Bit 7 */
  } Bits;
  struct {
    byte grpDDRJ :4;
    byte         :1;
    byte         :1;
    byte grpDDRJ_6 :2;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x00000262);
#define DDRJ _DDRJ.Byte
#define DDRJ_DDRJ0 _DDRJ.Bits.DDRJ0
#define DDRJ_DDRJ1 _DDRJ.Bits.DDRJ1
#define DDRJ_DDRJ2 _DDRJ.Bits.DDRJ2
#define DDRJ_DDRJ3 _DDRJ.Bits.DDRJ3
#define DDRJ_DDRJ6 _DDRJ.Bits.DDRJ6
#define DDRJ_DDRJ7 _DDRJ.Bits.DDRJ7
#define DDRJ_DDRJ _DDRJ.MergedBits.grpDDRJ
#define DDRJ_DDRJ_6 _DDRJ.MergedBits.grpDDRJ_6

#define DDRJ_DDRJ0_MASK  1
#define DDRJ_DDRJ1_MASK  2
#define DDRJ_DDRJ2_MASK  4
#define DDRJ_DDRJ3_MASK  8
#define DDRJ_DDRJ6_MASK  64
#define DDRJ_DDRJ7_MASK  128
#define DDRJ_DDRJ_MASK  15
#define DDRJ_DDRJ_BITNUM  0
#define DDRJ_DDRJ_6_MASK  192
#define DDRJ_DDRJ_6_BITNUM  6


/*** RDRJ - Port J Reduced Drive Register; 0x00000263 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRJ0       :1;                                       /* Reduced Drive Port J Bit 0 */
    byte RDRJ1       :1;                                       /* Reduced Drive Port J Bit 1 */
    byte RDRJ2       :1;                                       /* Reduced Drive Port J Bit 2 */
    byte RDRJ3       :1;                                       /* Reduced Drive Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte RDRJ6       :1;                                       /* Reduced Drive Port J Bit 6 */
    byte RDRJ7       :1;                                       /* Reduced Drive Port J Bit 7 */
  } Bits;
  struct {
    byte grpRDRJ :4;
    byte         :1;
    byte         :1;
    byte grpRDRJ_6 :2;
  } MergedBits;
} RDRJSTR;
extern volatile RDRJSTR _RDRJ @(REG_BASE + 0x00000263);
#define RDRJ _RDRJ.Byte
#define RDRJ_RDRJ0 _RDRJ.Bits.RDRJ0
#define RDRJ_RDRJ1 _RDRJ.Bits.RDRJ1
#define RDRJ_RDRJ2 _RDRJ.Bits.RDRJ2
#define RDRJ_RDRJ3 _RDRJ.Bits.RDRJ3
#define RDRJ_RDRJ6 _RDRJ.Bits.RDRJ6
#define RDRJ_RDRJ7 _RDRJ.Bits.RDRJ7
#define RDRJ_RDRJ _RDRJ.MergedBits.grpRDRJ
#define RDRJ_RDRJ_6 _RDRJ.MergedBits.grpRDRJ_6

#define RDRJ_RDRJ0_MASK  1
#define RDRJ_RDRJ1_MASK  2
#define RDRJ_RDRJ2_MASK  4
#define RDRJ_RDRJ3_MASK  8
#define RDRJ_RDRJ6_MASK  64
#define RDRJ_RDRJ7_MASK  128
#define RDRJ_RDRJ_MASK  15
#define RDRJ_RDRJ_BITNUM  0
#define RDRJ_RDRJ_6_MASK  192
#define RDRJ_RDRJ_6_BITNUM  6


/*** PERJ - Port J Pull Device Enable Register; 0x00000264 ***/
typedef union {
  byte Byte;
  struct {
    byte PERJ0       :1;                                       /* Pull Device Enable Port J Bit 0 */
    byte PERJ1       :1;                                       /* Pull Device Enable Port J Bit 1 */
    byte PERJ2       :1;                                       /* Pull Device Enable Port J Bit 2 */
    byte PERJ3       :1;                                       /* Pull Device Enable Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PERJ6       :1;                                       /* Pull Device Enable Port J Bit 6 */
    byte PERJ7       :1;                                       /* Pull Device Enable Port J Bit 7 */
  } Bits;
  struct {
    byte grpPERJ :4;
    byte         :1;
    byte         :1;
    byte grpPERJ_6 :2;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x00000264);
#define PERJ _PERJ.Byte
#define PERJ_PERJ0 _PERJ.Bits.PERJ0
#define PERJ_PERJ1 _PERJ.Bits.PERJ1
#define PERJ_PERJ2 _PERJ.Bits.PERJ2
#define PERJ_PERJ3 _PERJ.Bits.PERJ3
#define PERJ_PERJ6 _PERJ.Bits.PERJ6
#define PERJ_PERJ7 _PERJ.Bits.PERJ7
#define PERJ_PERJ _PERJ.MergedBits.grpPERJ
#define PERJ_PERJ_6 _PERJ.MergedBits.grpPERJ_6

#define PERJ_PERJ0_MASK  1
#define PERJ_PERJ1_MASK  2
#define PERJ_PERJ2_MASK  4
#define PERJ_PERJ3_MASK  8
#define PERJ_PERJ6_MASK  64
#define PERJ_PERJ7_MASK  128
#define PERJ_PERJ_MASK  15
#define PERJ_PERJ_BITNUM  0
#define PERJ_PERJ_6_MASK  192
#define PERJ_PERJ_6_BITNUM  6


/*** PPSJ - PortJP Polarity Select Register; 0x00000265 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSJ0       :1;                                       /* Pull Select Port J Bit 0 */
    byte PPSJ1       :1;                                       /* Pull Select Port J Bit 1 */
    byte PPSJ2       :1;                                       /* Pull Select Port J Bit 2 */
    byte PPSJ3       :1;                                       /* Pull Select Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PPSJ6       :1;                                       /* Pull Select Port J Bit 6 */
    byte PPSJ7       :1;                                       /* Pull Select Port J Bit 7 */
  } Bits;
  struct {
    byte grpPPSJ :4;
    byte         :1;
    byte         :1;
    byte grpPPSJ_6 :2;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x00000265);
#define PPSJ _PPSJ.Byte
#define PPSJ_PPSJ0 _PPSJ.Bits.PPSJ0
#define PPSJ_PPSJ1 _PPSJ.Bits.PPSJ1
#define PPSJ_PPSJ2 _PPSJ.Bits.PPSJ2
#define PPSJ_PPSJ3 _PPSJ.Bits.PPSJ3
#define PPSJ_PPSJ6 _PPSJ.Bits.PPSJ6
#define PPSJ_PPSJ7 _PPSJ.Bits.PPSJ7
#define PPSJ_PPSJ _PPSJ.MergedBits.grpPPSJ
#define PPSJ_PPSJ_6 _PPSJ.MergedBits.grpPPSJ_6

#define PPSJ_PPSJ0_MASK  1
#define PPSJ_PPSJ1_MASK  2
#define PPSJ_PPSJ2_MASK  4
#define PPSJ_PPSJ3_MASK  8
#define PPSJ_PPSJ6_MASK  64
#define PPSJ_PPSJ7_MASK  128
#define PPSJ_PPSJ_MASK  15
#define PPSJ_PPSJ_BITNUM  0
#define PPSJ_PPSJ_6_MASK  192
#define PPSJ_PPSJ_6_BITNUM  6


/*** PIEJ - Port J Interrupt Enable Register; 0x00000266 ***/
typedef union {
  byte Byte;
  struct {
    byte PIEJ0       :1;                                       /* Interrupt Enable Port J Bit 0 */
    byte PIEJ1       :1;                                       /* Interrupt Enable Port J Bit 1 */
    byte PIEJ2       :1;                                       /* Interrupt Enable Port J Bit 2 */
    byte PIEJ3       :1;                                       /* Interrupt Enable Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PIEJ6       :1;                                       /* Interrupt Enable Port J Bit 6 */
    byte PIEJ7       :1;                                       /* Interrupt Enable Port J Bit 7 */
  } Bits;
  struct {
    byte grpPIEJ :4;
    byte         :1;
    byte         :1;
    byte grpPIEJ_6 :2;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x00000266);
#define PIEJ _PIEJ.Byte
#define PIEJ_PIEJ0 _PIEJ.Bits.PIEJ0
#define PIEJ_PIEJ1 _PIEJ.Bits.PIEJ1
#define PIEJ_PIEJ2 _PIEJ.Bits.PIEJ2
#define PIEJ_PIEJ3 _PIEJ.Bits.PIEJ3
#define PIEJ_PIEJ6 _PIEJ.Bits.PIEJ6
#define PIEJ_PIEJ7 _PIEJ.Bits.PIEJ7
#define PIEJ_PIEJ _PIEJ.MergedBits.grpPIEJ
#define PIEJ_PIEJ_6 _PIEJ.MergedBits.grpPIEJ_6

#define PIEJ_PIEJ0_MASK  1
#define PIEJ_PIEJ1_MASK  2
#define PIEJ_PIEJ2_MASK  4
#define PIEJ_PIEJ3_MASK  8
#define PIEJ_PIEJ6_MASK  64
#define PIEJ_PIEJ7_MASK  128
#define PIEJ_PIEJ_MASK  15
#define PIEJ_PIEJ_BITNUM  0
#define PIEJ_PIEJ_6_MASK  192
#define PIEJ_PIEJ_6_BITNUM  6


/*** PIFJ - Port J Interrupt Flag Register; 0x00000267 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFJ0       :1;                                       /* Interrupt Flags Port J Bit 0 */
    byte PIFJ1       :1;                                       /* Interrupt Flags Port J Bit 1 */
    byte PIFJ2       :1;                                       /* Interrupt Flags Port J Bit 2 */
    byte PIFJ3       :1;                                       /* Interrupt Flags Port J Bit 3 */
    byte             :1; 
    byte             :1; 
    byte PIFJ6       :1;                                       /* Interrupt Flags Port J Bit 6 */
    byte PIFJ7       :1;                                       /* Interrupt Flags Port J Bit 7 */
  } Bits;
  struct {
    byte grpPIFJ :4;
    byte         :1;
    byte         :1;
    byte grpPIFJ_6 :2;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x00000267);
#define PIFJ _PIFJ.Byte
#define PIFJ_PIFJ0 _PIFJ.Bits.PIFJ0
#define PIFJ_PIFJ1 _PIFJ.Bits.PIFJ1
#define PIFJ_PIFJ2 _PIFJ.Bits.PIFJ2
#define PIFJ_PIFJ3 _PIFJ.Bits.PIFJ3
#define PIFJ_PIFJ6 _PIFJ.Bits.PIFJ6
#define PIFJ_PIFJ7 _PIFJ.Bits.PIFJ7
#define PIFJ_PIFJ _PIFJ.MergedBits.grpPIFJ
#define PIFJ_PIFJ_6 _PIFJ.MergedBits.grpPIFJ_6

#define PIFJ_PIFJ0_MASK  1
#define PIFJ_PIFJ1_MASK  2
#define PIFJ_PIFJ2_MASK  4
#define PIFJ_PIFJ3_MASK  8
#define PIFJ_PIFJ6_MASK  64
#define PIFJ_PIFJ7_MASK  128
#define PIFJ_PIFJ_MASK  15
#define PIFJ_PIFJ_BITNUM  0
#define PIFJ_PIFJ_6_MASK  192
#define PIFJ_PIFJ_6_BITNUM  6


/*** PTL - Port L I/O Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte PTL0        :1;                                       /* Port L Bit 0 */
    byte PTL1        :1;                                       /* Port L Bit 1 */
    byte PTL2        :1;                                       /* Port L Bit 2 */
    byte PTL3        :1;                                       /* Port L Bit 3 */
    byte PTL4        :1;                                       /* Port L Bit 4 */
    byte PTL5        :1;                                       /* Port L Bit 5 */
    byte PTL6        :1;                                       /* Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTL  :7;
    byte         :1;
  } MergedBits;
} PTLSTR;
extern volatile PTLSTR _PTL @(REG_BASE + 0x00000268);
#define PTL _PTL.Byte
#define PTL_PTL0 _PTL.Bits.PTL0
#define PTL_PTL1 _PTL.Bits.PTL1
#define PTL_PTL2 _PTL.Bits.PTL2
#define PTL_PTL3 _PTL.Bits.PTL3
#define PTL_PTL4 _PTL.Bits.PTL4
#define PTL_PTL5 _PTL.Bits.PTL5
#define PTL_PTL6 _PTL.Bits.PTL6
#define PTL_PTL _PTL.MergedBits.grpPTL

#define PTL_PTL0_MASK  1
#define PTL_PTL1_MASK  2
#define PTL_PTL2_MASK  4
#define PTL_PTL3_MASK  8
#define PTL_PTL4_MASK  16
#define PTL_PTL5_MASK  32
#define PTL_PTL6_MASK  64
#define PTL_PTL_MASK  127
#define PTL_PTL_BITNUM  0


/*** PTIL - Port L Input; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIL0       :1;                                       /* Port L Bit 0 */
    byte PTIL1       :1;                                       /* Port L Bit 1 */
    byte PTIL2       :1;                                       /* Port L Bit 2 */
    byte PTIL3       :1;                                       /* Port L Bit 3 */
    byte PTIL4       :1;                                       /* Port L Bit 4 */
    byte PTIL5       :1;                                       /* Port L Bit 5 */
    byte PTIL6       :1;                                       /* Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIL :7;
    byte         :1;
  } MergedBits;
} PTILSTR;
extern volatile PTILSTR _PTIL @(REG_BASE + 0x00000269);
#define PTIL _PTIL.Byte
#define PTIL_PTIL0 _PTIL.Bits.PTIL0
#define PTIL_PTIL1 _PTIL.Bits.PTIL1
#define PTIL_PTIL2 _PTIL.Bits.PTIL2
#define PTIL_PTIL3 _PTIL.Bits.PTIL3
#define PTIL_PTIL4 _PTIL.Bits.PTIL4
#define PTIL_PTIL5 _PTIL.Bits.PTIL5
#define PTIL_PTIL6 _PTIL.Bits.PTIL6
#define PTIL_PTIL _PTIL.MergedBits.grpPTIL

#define PTIL_PTIL0_MASK  1
#define PTIL_PTIL1_MASK  2
#define PTIL_PTIL2_MASK  4
#define PTIL_PTIL3_MASK  8
#define PTIL_PTIL4_MASK  16
#define PTIL_PTIL5_MASK  32
#define PTIL_PTIL6_MASK  64
#define PTIL_PTIL_MASK  127
#define PTIL_PTIL_BITNUM  0


/*** DDRL - Port L Data Direction Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRL0       :1;                                       /* Data Direction Port L Bit 0 */
    byte DDRL1       :1;                                       /* Data Direction Port L Bit 1 */
    byte DDRL2       :1;                                       /* Data Direction Port L Bit  2 */
    byte DDRL3       :1;                                       /* Data Direction Port L Bit 3 */
    byte DDRL4       :1;                                       /* Data Direction Port L Bit 4 */
    byte DDRL5       :1;                                       /* Data Direction Port L Bit 5 */
    byte DDRL6       :1;                                       /* Data Direction Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRL :7;
    byte         :1;
  } MergedBits;
} DDRLSTR;
extern volatile DDRLSTR _DDRL @(REG_BASE + 0x0000026A);
#define DDRL _DDRL.Byte
#define DDRL_DDRL0 _DDRL.Bits.DDRL0
#define DDRL_DDRL1 _DDRL.Bits.DDRL1
#define DDRL_DDRL2 _DDRL.Bits.DDRL2
#define DDRL_DDRL3 _DDRL.Bits.DDRL3
#define DDRL_DDRL4 _DDRL.Bits.DDRL4
#define DDRL_DDRL5 _DDRL.Bits.DDRL5
#define DDRL_DDRL6 _DDRL.Bits.DDRL6
#define DDRL_DDRL _DDRL.MergedBits.grpDDRL

#define DDRL_DDRL0_MASK  1
#define DDRL_DDRL1_MASK  2
#define DDRL_DDRL2_MASK  4
#define DDRL_DDRL3_MASK  8
#define DDRL_DDRL4_MASK  16
#define DDRL_DDRL5_MASK  32
#define DDRL_DDRL6_MASK  64
#define DDRL_DDRL_MASK  127
#define DDRL_DDRL_BITNUM  0


/*** RDRL - Port L Reduced Drive Register; 0x0000026B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRL0       :1;                                       /* Reduced Drive Port L Bit 0 */
    byte RDRL1       :1;                                       /* Reduced Drive Port L Bit 1 */
    byte RDRL2       :1;                                       /* Reduced Drive Port L Bit 2 */
    byte RDRL3       :1;                                       /* Reduced Drive Port L Bit 3 */
    byte RDRL4       :1;                                       /* Reduced Drive Port L Bit 4 */
    byte RDRL5       :1;                                       /* Reduced Drive Port L Bit 5 */
    byte RDRL6       :1;                                       /* Reduced Drive Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpRDRL :7;
    byte         :1;
  } MergedBits;
} RDRLSTR;
extern volatile RDRLSTR _RDRL @(REG_BASE + 0x0000026B);
#define RDRL _RDRL.Byte
#define RDRL_RDRL0 _RDRL.Bits.RDRL0
#define RDRL_RDRL1 _RDRL.Bits.RDRL1
#define RDRL_RDRL2 _RDRL.Bits.RDRL2
#define RDRL_RDRL3 _RDRL.Bits.RDRL3
#define RDRL_RDRL4 _RDRL.Bits.RDRL4
#define RDRL_RDRL5 _RDRL.Bits.RDRL5
#define RDRL_RDRL6 _RDRL.Bits.RDRL6
#define RDRL_RDRL _RDRL.MergedBits.grpRDRL

#define RDRL_RDRL0_MASK  1
#define RDRL_RDRL1_MASK  2
#define RDRL_RDRL2_MASK  4
#define RDRL_RDRL3_MASK  8
#define RDRL_RDRL4_MASK  16
#define RDRL_RDRL5_MASK  32
#define RDRL_RDRL6_MASK  64
#define RDRL_RDRL_MASK  127
#define RDRL_RDRL_BITNUM  0


/*** PERL - Port L Pull Device Enable Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte PERL0       :1;                                       /* Pull Device Enable Port L Bit 0 */
    byte PERL1       :1;                                       /* Pull Device Enable Port L Bit 1 */
    byte PERL2       :1;                                       /* Pull Device Enable Port L Bit 2 */
    byte PERL3       :1;                                       /* Pull Device Enable Port L Bit 3 */
    byte PERL4       :1;                                       /* Pull Device Enable Port L Bit 4 */
    byte PERL5       :1;                                       /* Pull Device Enable Port L Bit 5 */
    byte PERL6       :1;                                       /* Pull Device Enable Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPERL :7;
    byte         :1;
  } MergedBits;
} PERLSTR;
extern volatile PERLSTR _PERL @(REG_BASE + 0x0000026C);
#define PERL _PERL.Byte
#define PERL_PERL0 _PERL.Bits.PERL0
#define PERL_PERL1 _PERL.Bits.PERL1
#define PERL_PERL2 _PERL.Bits.PERL2
#define PERL_PERL3 _PERL.Bits.PERL3
#define PERL_PERL4 _PERL.Bits.PERL4
#define PERL_PERL5 _PERL.Bits.PERL5
#define PERL_PERL6 _PERL.Bits.PERL6
#define PERL_PERL _PERL.MergedBits.grpPERL

#define PERL_PERL0_MASK  1
#define PERL_PERL1_MASK  2
#define PERL_PERL2_MASK  4
#define PERL_PERL3_MASK  8
#define PERL_PERL4_MASK  16
#define PERL_PERL5_MASK  32
#define PERL_PERL6_MASK  64
#define PERL_PERL_MASK  127
#define PERL_PERL_BITNUM  0


/*** PPSL - Port L Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSL0       :1;                                       /* Pull Select Port L Bit 0 */
    byte PPSL1       :1;                                       /* Pull Select Port L Bit 1 */
    byte PPSL2       :1;                                       /* Pull Select Port L Bit 2 */
    byte PPSL3       :1;                                       /* Pull Select Port L Bit 3 */
    byte PPSL4       :1;                                       /* Pull Select Port L Bit 4 */
    byte PPSL5       :1;                                       /* Pull Select Port L Bit 5 */
    byte PPSL6       :1;                                       /* Pull Select Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSL :7;
    byte         :1;
  } MergedBits;
} PPSLSTR;
extern volatile PPSLSTR _PPSL @(REG_BASE + 0x0000026D);
#define PPSL _PPSL.Byte
#define PPSL_PPSL0 _PPSL.Bits.PPSL0
#define PPSL_PPSL1 _PPSL.Bits.PPSL1
#define PPSL_PPSL2 _PPSL.Bits.PPSL2
#define PPSL_PPSL3 _PPSL.Bits.PPSL3
#define PPSL_PPSL4 _PPSL.Bits.PPSL4
#define PPSL_PPSL5 _PPSL.Bits.PPSL5
#define PPSL_PPSL6 _PPSL.Bits.PPSL6
#define PPSL_PPSL _PPSL.MergedBits.grpPPSL

#define PPSL_PPSL0_MASK  1
#define PPSL_PPSL1_MASK  2
#define PPSL_PPSL2_MASK  4
#define PPSL_PPSL3_MASK  8
#define PPSL_PPSL4_MASK  16
#define PPSL_PPSL5_MASK  32
#define PPSL_PPSL6_MASK  64
#define PPSL_PPSL_MASK  127
#define PPSL_PPSL_BITNUM  0


/*** WOML - Port L Wired-Or Mode Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte WOML0       :1;                                       /* Wired-Or Mode Port L Bit 0 */
    byte WOML1       :1;                                       /* Wired-Or Mode Port L Bit 1 */
    byte WOML2       :1;                                       /* Wired-Or Mode Port L Bit 2 */
    byte WOML3       :1;                                       /* Wired-Or Mode Port L Bit 3 */
    byte WOML4       :1;                                       /* Wired-Or Mode Port L Bit 4 */
    byte WOML5       :1;                                       /* Wired-Or Mode Port L Bit 5 */
    byte WOML6       :1;                                       /* Wired-Or Mode Port L Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpWOML :7;
    byte         :1;
  } MergedBits;
} WOMLSTR;
extern volatile WOMLSTR _WOML @(REG_BASE + 0x0000026E);
#define WOML _WOML.Byte
#define WOML_WOML0 _WOML.Bits.WOML0
#define WOML_WOML1 _WOML.Bits.WOML1
#define WOML_WOML2 _WOML.Bits.WOML2
#define WOML_WOML3 _WOML.Bits.WOML3
#define WOML_WOML4 _WOML.Bits.WOML4
#define WOML_WOML5 _WOML.Bits.WOML5
#define WOML_WOML6 _WOML.Bits.WOML6
#define WOML_WOML _WOML.MergedBits.grpWOML

#define WOML_WOML0_MASK  1
#define WOML_WOML1_MASK  2
#define WOML_WOML2_MASK  4
#define WOML_WOML3_MASK  8
#define WOML_WOML4_MASK  16
#define WOML_WOML5_MASK  32
#define WOML_WOML6_MASK  64
#define WOML_WOML_MASK  127
#define WOML_WOML_BITNUM  0


  /* Watchdog reset macro */
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() {asm sta COPCTL;}  /* Just write a byte to feed the dog */
#endif


#endif

