#include "ks0108_glcd.h"
#include <xc.h>

void glcdCmd(unsigned char cmd) {
    RS = 0;
    RW = 0;
    GLCD_PORT = cmd;
    E = 1;
    __delay_us(10);
    E = 0;
    __delay_ms(2);
}

void glcdData(unsigned char data) {
    RS = 1;
    RW = 0;
    GLCD_PORT = data;
    E = 1;
    __delay_us(10);
    E = 0;
    __delay_ms(2);
}

unsigned char glcdRead(){
    TRISD = 0xFF;
    RS = 1;
    RW = 1;
    __delay_us(10);
    unsigned char ramValue = PORTD;    
    TRISD = 0x00;
    return ramValue;
}
void glcdStart() {
    RST = 0;
    __delay_us(100);
    RST = 1;
    __delay_us(100);
    CS1 = 0;
    CS2 = 0;
    glcdCmd(DISPLAY_ON);
}

void glcdClear() {
    for (unsigned char y = 0xb8; y <= 0xbf; y++) {
        glcdCmd(y);
        for (unsigned char x = 0x40; x <= 0x7F; x++) {
            glcdCmd(x);
            glcdData(0);
        }
    }
}

void selectController1(){
    CS2 = 1;
    CS1 = 0;
}

void selectController2(){
    CS2 = 0;
    CS1 = 1;
}