#ifndef _I2C_H_
#define _I2C_H_
void I2Csend(UINT8 data, UINT8 addr);
//void I2Csend(UINT8 data);
UINT8 I2Crecv(void);
#endif
