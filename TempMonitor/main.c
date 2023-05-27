#include <xc.h>
#include "setup.h"
#include "io.h"
#include "keyboard.h"
#include "lcd.h"
#include <stdint.h>
#include "display.h"
#include "ad.h"
#include "menu.h"
#include "monitor.h"
#include "serial.h"
#include "config.h"

void main(){
    setupPic();
    while(Config_coldStart){
        configMenu();
    }
    writeOperationMask();
    uint8_t key;
    GIE = 1;
    while(1){
        
        key = scanKeys();
        if(key=='A'){
            configMenu();
            writeOperationMask();
            GIE = 1;
        }
    }
}

void __interrupt() request(){
    static uint8_t counterToDisplay = 5;
    if(TMR1IF & TMR1IE){
        TMR1IF = 0;
        TMR1ON = 0;
        
        monitor();
        
        counterToDisplay--;
        if(!counterToDisplay){
            counterToDisplay = 5;
            showRealValues();
        }
        TMR1ON = 1;
    }
}