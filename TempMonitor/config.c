#include "config.h"
#include "eeprom.h"

void getConfig(){
    Config_numberOfSensors = readE2p(SENSOR_QUANTITY);
    Config_coldStart = readE2p(COLD_START);
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        Config_newMaxValues[i] = Config_maxValues[i] = readE2p(MAX_VALUES + i);
        Config_newTimeValues[i] = Config_timeOut[i] = readE2p(TIMEOUT_VALUES + i);
    }
}

void setConfigMaxValue(uint8_t sensor, uint8_t value){
    Config_newMaxValues[sensor] = value;
}
void setConfigTimeOut(uint8_t sensor, uint8_t value){
    Config_newMaxValues[sensor] = value;
}

void writeConfigSensors(void){
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        writeE2p(MAX_VALUES + i, Config_newMaxValues[i]);
        Config_maxValues[i] = Config_newMaxValues[i];
        writeE2p(TIMEOUT_VALUES + i, Config_newTimeValues[i]);
        Config_timeOut[i] = Config_newTimeValues[i];
    }
    if(Config_coldStart){
        Config_coldStart = 0;
        writeColdstart();
    }
}

void writeSensorQuantity(uint8_t value){
    writeE2p(SENSOR_QUANTITY, Config_numberOfSensors);
    if(!Config_coldStart){
        RESET();
    }
}

void writeColdstart(void){
    writeE2p(COLD_START, 0);
}