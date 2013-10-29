/* Based on CPU DB MC9S12NE64, version 2.87.029 (RegistersPrg V1.055) */
/* DataSheet : 9S12NE-FamilyDGV1/D V01.04 */

#include "MC9S12NE64.h"


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ARMCOPSTR _ARMCOP;                                /* CRG COP Timer Arm/Reset Register */
volatile ATDSTAT0STR _ATDSTAT0;                            /* ATD Status Register 0 */
volatile ATDSTAT1STR _ATDSTAT1;                            /* ATD Status Register 1 */
volatile ATDSTAT2STR _ATDSTAT2;                            /* ATD Status Register 2 */
volatile ATDTEST1STR _ATDTEST1;                            /* ATD Test Register */
volatile CFORCSTR _CFORC;                                  /* Timer Compare Force Register */
volatile CLKSELSTR _CLKSEL;                                /* CRG Clock Select Register */
volatile COPCTLSTR _COPCTL;                                /* CRG COP Control Register */
volatile CRGFLGSTR _CRGFLG;                                /* CRG Flags Register */
volatile CRGINTSTR _CRGINT;                                /* CRG Interrupt Enable Register */
volatile DBGC1STR _DBGC1;                                  /* Debug Control Register 1 */
volatile DBGC2STR _DBGC2;                                  /* Debug Control Register 2 */
volatile DBGC3STR _DBGC3;                                  /* Debug Control Register 3 */
volatile DBGCAXSTR _DBGCAX;                                /* Debug Comparator A Extended Register */
volatile DBGCBXSTR _DBGCBX;                                /* Debug Comparator B Extended Register */
volatile DBGCCXSTR _DBGCCX;                                /* Debug Comparator C Extended Register */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Register */
volatile DBGSCSTR _DBGSC;                                  /* Debug Status and Control Register */
volatile DDRESTR _DDRE;                                    /* Port E Data Direction Register */
volatile DDRGSTR _DDRG;                                    /* Port G Data Direction Register */
volatile DDRHSTR _DDRH;                                    /* Port H Data Direction Register */
volatile DDRJSTR _DDRJ;                                    /* Port J Data Direction Register */
volatile DDRKSTR _DDRK;                                    /* Port K Data Direction Register */
volatile DDRLSTR _DDRL;                                    /* Port L Data Direction Register */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register */
volatile EBICTLSTR _EBICTL;                                /* External Bus Interface Control */
volatile EPHYCTL0STR _EPHYCTL0;                            /* Ethernet Physical Transceiver Control Register 0 */
volatile EPHYCTL1STR _EPHYCTL1;                            /* Ethernet Physical Transceiver Control Register 1 */
volatile EPHYSRSTR _EPHYSR;                                /* Ethernet Physical Transceiver Status Register */
volatile ETCTLSTR _ETCTL;                                  /* Ethertype Control */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register */
volatile FCMDSTR _FCMD;                                    /* Flash Command Buffer and Register */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register */
volatile FSECSTR _FSEC;                                    /* Flash Security Register */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register */
volatile HPRIOSTR _HPRIO;                                  /* Highest Priority I Interrupt */
volatile IBADSTR _IBAD;                                    /* IIC Address Register */
volatile IBCRSTR _IBCR;                                    /* IIC Control Register */
volatile IBDRSTR _IBDR;                                    /* IIC Data I/O Register */
volatile IBFDSTR _IBFD;                                    /* IIC Frequency Divider Register */
volatile IBSRSTR _IBSR;                                    /* IIC Status Register */
volatile INITRGSTR _INITRG;                                /* Initialization of Internal Registers Position Register */
volatile INITRMSTR _INITRM;                                /* Initialization of Internal RAM Position Register */
volatile INTCRSTR _INTCR;                                  /* Interrupt Control Register */
volatile ITCRSTR _ITCR;                                    /* Interrupt Test Control Register */
volatile ITESTSTR _ITEST;                                  /* Interrupt Test Register */
volatile MCMSTSTR _MCMST;                                  /* MII Command and Status */
volatile MEMSIZ0STR _MEMSIZ0;                              /* Memory Size Register Zero */
volatile MEMSIZ1STR _MEMSIZ1;                              /* Memory Size Register One */
volatile MISCSTR _MISC;                                    /* Miscellaneous System Control Register */
volatile MODESTR _MODE;                                    /* Mode Register */
volatile MPADRSTR _MPADR;                                  /* MII PHY Address */
volatile MRADRSTR _MRADR;                                  /* MII Register Address */
volatile MTST0STR _MTST0;                                  /* MTST0 */
volatile MTST1STR _MTST1;                                  /* MTST1 */
volatile NETCTLSTR _NETCTL;                                /* Network Control */
volatile OC7DSTR _OC7D;                                    /* Output Compare 7 Data Register */
volatile OC7MSTR _OC7M;                                    /* Output Compare 7 Mask Register */
volatile PACTLSTR _PACTL;                                  /* 16-Bit Pulse Accumulator A Control Register */
volatile PAFLGSTR _PAFLG;                                  /* Pulse Accumulator A Flag Register */
volatile PARTIDHSTR _PARTIDH;                              /* Part ID Register High */
volatile PARTIDLSTR _PARTIDL;                              /* Part ID Register Low */
volatile PEARSTR _PEAR;                                    /* Port E Assignment Register */
volatile PERGSTR _PERG;                                    /* Port G Pull Device Enable Register */
volatile PERHSTR _PERH;                                    /* Port H Pull Device Enable Register */
volatile PERJSTR _PERJ;                                    /* Port J Pull Device Enable Register */
volatile PERLSTR _PERL;                                    /* Port L Pull Device Enable Register */
volatile PERSSTR _PERS;                                    /* Port S Pull Device Enable Register */
volatile PERTSTR _PERT;                                    /* Port T Pull Device Enable Register */
volatile PIEGSTR _PIEG;                                    /* Port G Interrupt Enable Register */
volatile PIEHSTR _PIEH;                                    /* Port H Interrupt Enable Register */
volatile PIEJSTR _PIEJ;                                    /* Port J Interrupt Enable Register */
volatile PIFGSTR _PIFG;                                    /* Port G Interrupt Flag Register */
volatile PIFHSTR _PIFH;                                    /* Port H Interrupt Flag Register */
volatile PIFJSTR _PIFJ;                                    /* Port J Interrupt Flag Register */
volatile PLLCTLSTR _PLLCTL;                                /* CRG PLL Control Register */
volatile PORTAD1STR _PORTAD;                                /* Port AD Data Register */
volatile PORTESTR _PORTE;                                  /* Port E Register */
volatile PORTKSTR _PORTK;                                  /* Port K Data Register */
volatile PPAGESTR _PPAGE;                                  /* Page Index Register */
volatile PPSGSTR _PPSG;                                    /* Port G Polarity Select Register */
volatile PPSHSTR _PPSH;                                    /* Port H Polarity Select Register */
volatile PPSJSTR _PPSJ;                                    /* Port J Polarity Select Register */
volatile PPSLSTR _PPSL;                                    /* Port L Polarity Select Register */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register */
volatile PTGSTR _PTG;                                      /* Port G I/O Register */
volatile PTHSTR _PTH;                                      /* Port H I/O Register */
volatile PTIGSTR _PTIG;                                    /* Port G Input Register */
volatile PTIHSTR _PTIH;                                    /* Port H Input Register Register */
volatile PTIJSTR _PTIJ;                                    /* Port J Input Register Register */
volatile PTILSTR _PTIL;                                    /* Port L Input Register */
volatile PTISSTR _PTIS;                                    /* Port S Input Register */
volatile PTITSTR _PTIT;                                    /* Port T Input Register */
volatile PTJSTR _PTJ;                                      /* Port J I/O Register */
volatile PTLSTR _PTL;                                      /* Port L I/O Register */
volatile PTSSTR _PTS;                                      /* Port S I/O Register */
volatile PTTSTR _PTT;                                      /* Port T I/O Register */
volatile PUCRSTR _PUCR;                                    /* Pull-Up Control Register */
volatile RDRGSTR _RDRG;                                    /* Port G Reduced Drive Register */
volatile RDRHSTR _RDRH;                                    /* Port H Reduced Drive Register */
volatile RDRIVSTR _RDRIV;                                  /* Reduced Drive of I/O Lines */
volatile RDRJSTR _RDRJ;                                    /* Port J Reduced Drive Register */
volatile RDRLSTR _RDRL;                                    /* Port L Reduced Drive Register */
volatile RDRSSTR _RDRS;                                    /* Port S Reduced Drive Register */
volatile RDRTSTR _RDRT;                                    /* Port T Reduced Drive Register */
volatile REFDVSTR _REFDV;                                  /* CRG Reference Divider Register */
volatile RTICTLSTR _RTICTL;                                /* CRG RTI Control Register */
volatile RXCTSSTR _RXCTS;                                  /* Receive Control and Status */
volatile SCI0CR1STR _SCI0CR1;                              /* SCI 0 Control Register 1 */
volatile SCI0CR2STR _SCI0CR2;                              /* SCI 0 Control Register 2 */
volatile SCI0DRHSTR _SCI0DRH;                              /* SCI 0 Data Register High */
volatile SCI0DRLSTR _SCI0DRL;                              /* SCI 0 Data Register Low */
volatile SCI0SR1STR _SCI0SR1;                              /* SCI 0 Status Register 1 */
volatile SCI0SR2STR _SCI0SR2;                              /* SCI 0 Status Register 2 */
volatile SCI1CR1STR _SCI1CR1;                              /* SCI 1 Control Register 1 */
volatile SCI1CR2STR _SCI1CR2;                              /* SCI 1 Control Register 2 */
volatile SCI1DRHSTR _SCI1DRH;                              /* SCI 1 Data Register High */
volatile SCI1DRLSTR _SCI1DRL;                              /* SCI 1 Data Register Low */
volatile SCI1SR1STR _SCI1SR1;                              /* SCI 1 Status Register 1 */
volatile SCI1SR2STR _SCI1SR2;                              /* SCI 1 Status Register 2 */
volatile SPIBRSTR _SPIBR;                                  /* SPI Baud Rate Register */
volatile SPICR1STR _SPICR1;                                /* SPI Control Register */
volatile SPICR2STR _SPICR2;                                /* SPI Control Register 2 */
volatile SPIDRSTR _SPIDR;                                  /* SPI Data Register */
volatile SPISRSTR _SPISR;                                  /* SPI Status Register */
volatile SWRSTSTR _SWRST;                                  /* Software Reset */
volatile SYNRSTR _SYNR;                                    /* CRG Synthesizer Register */
volatile TCTL1STR _TCTL1;                                  /* Timer Control Registers 1 */
volatile TCTL3STR _TCTL3;                                  /* Timer Control Register 3 */
volatile TFLG1STR _TFLG1;                                  /* Main Timer Interrupt Flag 1 */
volatile TFLG2STR _TFLG2;                                  /* Main Timer Interrupt Flag 2 */
volatile TIESTR _TIE;                                      /* Timer Interrupt Enable Register */
volatile TIOSSTR _TIOS;                                    /* Timer Input Capture/Output Compare Select */
volatile TSCR1STR _TSCR1;                                  /* Timer System Control Register1 */
volatile TSCR2STR _TSCR2;                                  /* Timer System Control Register 2 */
volatile TTOVSTR _TTOV;                                    /* Timer Toggle On Overflow Register */
volatile TXCTSSTR _TXCTS;                                  /* Transmit Control and Status */
volatile WOMLSTR _WOML;                                    /* Port L Wired-Or Mode Register */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ATDCTL23STR _ATDCTL23;                            /* ATD Control Register 23 */
volatile ATDCTL45STR _ATDCTL45;                            /* ATD Control Register 45 */
volatile ATDDIENSTR _ATDDIEN;                              /* ATD Input Enable Register */
volatile ATDDR0STR _ATDDR0;                                /* ATD Conversion Result Register 0 */
volatile ATDDR1STR _ATDDR1;                                /* ATD Conversion Result Register 1 */
volatile ATDDR2STR _ATDDR2;                                /* ATD Conversion Result Register 2 */
volatile ATDDR3STR _ATDDR3;                                /* ATD Conversion Result Register 3 */
volatile ATDDR4STR _ATDDR4;                                /* ATD Conversion Result Register 4 */
volatile ATDDR5STR _ATDDR5;                                /* ATD Conversion Result Register 5 */
volatile ATDDR6STR _ATDDR6;                                /* ATD Conversion Result Register 6 */
volatile ATDDR7STR _ATDDR7;                                /* ATD Conversion Result Register 7 */
volatile BUFCFGSTR _BUFCFG;                                /* FIFO Buffer Configuration */
volatile DBGCASTR _DBGCA;                                  /* Debug Comparator A Register */
volatile DBGCBSTR _DBGCB;                                  /* Debug Comparator B Register */
volatile DBGCCSTR _DBGCC;                                  /* Debug Comparator C Register */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register */
volatile DDRABSTR _DDRAB;                                  /* Port AB Data Direction Register */
volatile EMISCSTR _EMISC;                                  /* MAC Address Register 3 */
volatile ETYPESTR _ETYPE;                                  /* Programmable Ethertype */
volatile IEVENTSTR _IEVENT;                                /* Interrupt Event */
volatile IMASKSTR _IMASK;                                  /* Interrupt Mask */
volatile MACAD0STR _MACAD0;                                /* MAC Address Register 0 */
volatile MACAD1STR _MACAD1;                                /* MAC Address Register 1 */
volatile MACAD2STR _MACAD2;                                /* MAC Address Register 2 */
volatile MCHASH0STR _MCHASH0;                              /* Multicast Hash Table Register 0 */
volatile MCHASH1STR _MCHASH1;                              /* Multicast Hash Table Register 1 */
volatile MCHASH2STR _MCHASH2;                              /* Multicast Hash Table Register 2 */
volatile MCHASH3STR _MCHASH3;                              /* Multicast Hash Table Register 3 */
volatile MRDATASTR _MRDATA;                                /* MII Read Data */
volatile MWDATASTR _MWDATA;                                /* MII Write Data */
volatile PACNTSTR _PACNT;                                  /* Pulse Accumulators Count Register */
volatile PORTABSTR _PORTAB;                                /* Port AB Register */
volatile PTIMESTR _PTIME;                                  /* PAUSE Timer Value and Counter */
volatile RXAEFPSTR _RXAEFP;                                /* Receive A End of Frame Pointer */
volatile RXBEFPSTR _RXBEFP;                                /* Receive B End of Frame Pointer */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register */
volatile SCI1BDSTR _SCI1BD;                                /* SCI 1 Baud Rate Register */
volatile TC4STR _TC4;                                      /* Timer Input Capture/Output Compare Register 4 */
volatile TC5STR _TC5;                                      /* Timer Input Capture/Output Compare Register 5 */
volatile TC6STR _TC6;                                      /* Timer Input Capture/Output Compare Register 6 */
volatile TC7STR _TC7;                                      /* Timer Input Capture/Output Compare Register 7 */
volatile TCNTSTR _TCNT;                                    /* Timer Count Register */
volatile TXEFPSTR _TXEFP;                                  /* Transmit End of Frame Pointer */
