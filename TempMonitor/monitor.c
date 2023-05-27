#include "monitor.h"
#include <xc.h>
#include "setup.h"
#include <stdint.h>
#include <stdbool.h>
#include "ad.h"
#include "io.h"
#include "display.h"
#include "eeprom.h"
#include "serial.h"
#include "config.h"

uint8_t realValues[8];

bool compareSensor(uint8_t sensor, uint8_t value){
    return value > Config_maxValues[sensor] ? true : false;
}

void monitor(){
    static uint8_t sensor=0;
    static uint8_t index=0;
    static uint16_t totalValue = 0;
    
    totalValue += getTemp(sensor);
    index++;
    if(index > 10){
        index = 0;
        realValues[sensor] = (uint8_t)(totalValue / 10);
        totalValue = 0;
        sensor++;
    }
    if(sensor > Config_numberOfSensors){
        sensor = 0;
    }
}

void showRealValues(){
    static  index = 0;
    writeSensorValues(index,realValues[index], Config_maxValues[index]);
    index = index == (Config_numberOfSensors - 1) ? 0 : index + 1;
}