#include "menu.h"
#include "display.h"
#include "keyboard.h"
#include <stdbool.h>
#include "io.h"
#include "eeprom.h"
#include <stdint.h>
#include "config.h"
#include "lcd.h"

bool (*menuPtr)(void);
bool (*changeValuePtr)(uint8_t, bool *, bool *); 
uint8_t key = '$';

void configMenu(void){
    GIE = 0;
    setDisplayBack(YELLOW);
    if(Config_coldStart){
        menuPtr = configQuantityMenu;
    }
    else{
        menuPtr = configLimitsMenu;
    }
        
    while(!menuPtr());
    setDisplayBack(GREEN);
}

bool configLimitsMenu(void){
    showConfigLimitsMenu();
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
    // next Item
    if(key == 'A'){
        menuPtr=configQuantityMenu;
        return false;
    }
    // exit
    else if(key == '*'){
        return true;
    }
    // enter menu
    else if(key == '#'){
        menuPtr=configSensors;
        return false;
    }
    return false;
}

bool configQuantityMenu(void){
    showConfigNsensors();
    setSensorQuantity(Config_numberOfSensors);
    key = '$';
    static uint8_t decimal = 0;
    static uint8_t quantity = 0;
    quantity = !decimal ? 0 : quantity;
    while(key == '$'){
        key = scanKeys();
    }
    // next Item
    if(key == 'A'){
        menuPtr=configLimitsMenu;
        decimal = 0;
        return false;
    }
    // exit
    else if(key == '*'){
        decimal = 0;
        return true;
    }
    // enter menu
    else if((key >= '0') & (key <= '9')){
        key -= 0x30;
        if(!decimal){
            decimal = 1;
            quantity = key;
        }
        else if(decimal == 1){
            decimal = 0;
            quantity = quantity*10 + key;
        }
        quantity = quantity > 8 ? 8 : quantity;
        quantity = quantity < 1 ? 1 : quantity;
        Config_numberOfSensors = quantity;
        writeSensorQuantity(quantity);
    }
    return false;
}
bool changeQuantity(void){
    
}

bool changeMaxValue(uint8_t sensor, bool *exit, bool *hasChanges){
    byte_lcd(LCD_CMD, 0xC6);
    byte_lcd(LCD_CHAR, '>');
    byte_lcd(LCD_CMD, 0x86);
    byte_lcd(LCD_CHAR, ' ');
    static uint8_t decimal = 0;
    static uint8_t maxValue = 0;
    maxValue = !decimal ? 0 : maxValue;
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
    if (key == '*'){
        *exit = true;
        decimal = 0;
        return false;
    }
    else if(key == '#'){
        changeValuePtr = changeTimeValue;
        decimal = 0;
        return false;
    }
    else if(key == 'A'){
        decimal = 0;
        return true;
    }
    else if((key >= '0') & (key <= '9')){
        key -= 0x30;
        if(!decimal){
            decimal = 1;
            maxValue = key;
        }
        else if(decimal == 1){
            decimal = 2;
            maxValue = maxValue*10 + key;
        }
        else if(decimal == 2){
            decimal = 0;
            maxValue = (maxValue/10)*100 + (maxValue%10)*10 + key;
        }
        maxValue = maxValue > 150 ? 150 : maxValue;
        setConfigMaxValue(sensor, maxValue);
        setChangeMaxValue(maxValue);
        *hasChanges = true;
    }
    return false;
}

bool changeTimeValue(uint8_t sensor, bool *exit, bool *hasChanges){
    byte_lcd(LCD_CMD, 0xC6);
    byte_lcd(LCD_CHAR, ' ');
    byte_lcd(LCD_CMD, 0x86);
    byte_lcd(LCD_CHAR, '>');
    static uint8_t decimal = 0;
    static uint8_t TimeValue = 0;
    TimeValue = !decimal ? 0 : TimeValue;
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
        if (key == '*'){
        *exit = true;
        decimal = 0;
        return false;
    }
    else if(key == '#'){
        changeValuePtr = changeMaxValue;
        decimal = 0;
        return false;
    }
    else if(key == 'A'){
        return true;
    }
    else if((key >= '0') & (key <= '9')){
        key -= 0x30;
        if(!decimal){
            decimal = 1;
            TimeValue = key;
        }
        else if(decimal == 1){
            decimal = 2;
            TimeValue = TimeValue*10 + key;
        }
        else if(decimal == 2){
            decimal = 0;
            TimeValue = (TimeValue/10)*100 + (TimeValue%10)*10 + key;
        }
        TimeValue = TimeValue > 120 ? 120 : TimeValue;
        setConfigTimeOut(sensor, TimeValue);
        setChangeTimeout(TimeValue);
        *hasChanges = true;
    }
    return false;
}

bool configSensors(void){
    showChangeParam();
    key = '$';
    bool exit = false;
    bool hasChanges = false;
    changeValuePtr = changeMaxValue;
    for(uint8_t i=0; i < Config_numberOfSensors; i++){
        setConfigSensorParam(i,Config_timeOut[i],Config_maxValues[i]);
        while(!changeValuePtr(i, &exit, &hasChanges)){
            if(exit){
                return true;
            } 
        }
        changeValuePtr = changeMaxValue;
    }
    if(hasChanges){
        menuPtr = saveConfig;
        return false;
    }
    else{
        return true;
    }
}

bool saveConfig(void){
    showSaveConfig();
    key = '$';
    while(key == '$'){
        key = scanKeys();
    }
    if(key == '*'){
        return true;
    }
    else if(key == '#'){
        writeConfigSensors();
        return true;
    }
    else{
        return false;
    }
}

