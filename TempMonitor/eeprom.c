#include "eeprom.h"
#include <xc.h>
#include <stdint.h>

void writeE2p(uint8_t address, uint8_t value){
    GIE = 0;
    EEPGD = 0;
    EEADR = address;
    EEDAT = value;
    WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    WR = 1;
    while(WR){
        CLRWDT();
    }
    WREN=0;
}
uint8_t readE2p(uint8_t address){
    GIE = 0;
    EEPGD = 0;
    EEADR = address;
    RD = 1;
    while(RD){
        CLRWDT();
    }
    uint8_t value = EEDAT;
    return value;
}
