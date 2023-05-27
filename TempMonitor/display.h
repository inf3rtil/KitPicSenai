#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>

void showSplashScreen(void);
void writeOperationMask(void);
void writeSensorValues(uint8_t sensor, uint8_t value, uint8_t max);
void showConfigLimitsMenu(void);
void showConfigNsensors(void);
void showChangePassword(void);
void showChangeParam(void);
void setSensorNumber(uint8_t sensor);
void setConfigSensorParam(uint8_t sensor, uint8_t time, uint8_t max);
void setChangeTimeout(uint8_t value);
void setChangeMaxValue(uint8_t value);
void showSaveConfig(void);
void setSensorQuantity(uint8_t value);

#endif