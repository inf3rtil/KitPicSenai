#ifndef AD_H
#define AD_H

#include <stdint.h>

void startAdConversion(void);
uint16_t readAdResult(void);
uint8_t getTemp(uint8_t sensor);

#endif