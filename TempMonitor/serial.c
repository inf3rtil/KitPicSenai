#include "serial.h"
#include <stdint.h>
#include <xc.h>

void txByte(uint8_t data){
    TXREG = data;
    while(!TRMT){
        CLRWDT();
    }
}
