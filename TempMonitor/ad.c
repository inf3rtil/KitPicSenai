#include "ad.h"
#include <xc.h>
#include <stdint.h>

void startAdConversion(void){
    GO = 1;
    while(nDONE){
        
        CLRWDT();
    }
}
uint16_t readAdResult(void){
    uint16_t value = ADRESH;
    value = value << 8;
    value += ADRESL;
    return value;
    //return (((uint16_t)(ADRESH)) << 8) + ADRESL;
}

uint8_t convertToTemp(uint16_t adValue){
    //return (uint8_t)(adValue*0.488);
    return (uint8_t)((adValue*488)/1000);
}

uint8_t getTemp(uint8_t sensor){
    ADCON0bits.CHS = sensor;
    startAdConversion();
    return convertToTemp(readAdResult());
}