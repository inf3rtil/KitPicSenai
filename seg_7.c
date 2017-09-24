#include "setup.h"
#include "seg_7.h"
#include <xc.h>
#include <pic16f877a.h>



void start_display7(){
    TRISE = 0x00;
    PORTE = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
}

void write_display7(char centena, char dezena, char unidade){
    const static char num_seg7[]={0x3f,0x06,0x5B,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x67};
    PORTD = num_seg7[centena];
    display3 = 1;
    __delay_ms(5);
    display3 = 0;
    PORTD = num_seg7[dezena];
    display2 = 1;
    __delay_ms(5);
    display2 = 0;
    PORTD = num_seg7[unidade];
    display1 = 1;
    __delay_ms(5);
    display1 = 0;
}