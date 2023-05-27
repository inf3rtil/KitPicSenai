#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>

uint8_t Config_coldStart;
uint8_t Config_newMaxValues[8];
uint8_t Config_newTimeValues[8];
uint8_t Config_maxValues[8];
uint8_t Config_timeOut[8];
volatile uint8_t Config_numberOfSensors = 0;

void getConfig(void);
void setConfigMaxValue(uint8_t sensor, uint8_t value);
void setConfigTimeOut(uint8_t sensor, uint8_t value);
void writeConfigSensors(void);
void writeSensorQuantity(uint8_t value);
void writeColdstart(void);

#endif