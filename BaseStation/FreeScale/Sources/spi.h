#ifndef _SPI_H_
#define _SPI_H_
UINT8 SPIconfig1(void);
void SPIinit(void);
void SPIsend1(UINT8 data, UINT8 port);
UINT8 SPIrecv(void);
void SPIsendbyte(UINT8 data);
#endif
