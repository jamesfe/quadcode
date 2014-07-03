#include<stdint.h>

void  readBlock(uint8_t command, uint8_t size, uint8_t *data);

void selectDevice(int file, int addr);

void readACC(int  *a);

void readMAG(int  *m);

void readGYR(int *g);

void enableIMU();
