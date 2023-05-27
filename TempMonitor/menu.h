#ifndef MENU_H
#define MENU_H
#include <stdbool.h>
#include <stdint.h>

void configMenu(void);
bool configLimitsMenu(void);
bool configSensors(void);
bool changeTimeValue(uint8_t sensor, bool *exit, bool *hasChanges);
bool saveConfig(void);
bool configQuantityMenu(void);
bool changeQuantity(void);

#endif