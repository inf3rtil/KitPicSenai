/*
 * File: main.c
 * Project: KitPicSenai
 ************************************************************************
 * Author: Fernando Ferreira Silva 
 * Email: fernando@ninodev.com
 * Site	: https://github.com/feferreira
 * GPG key: 2048D/CBB2DEEE 38C5 D8A1 2F13 6B92 BDCE  1478 4B4D F141 CBB2 DEEE
 ************************************************************************
 * Copyright (C) 2017,2018 Fernando Ferreira Silva
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************
 */
#include <xc.h>
#include <pic16f877a.h>
#include <stdint.h>
#include "lcd.h"
#include "setup.h"
#include "seg_7.h"
#include "keyboard.h"
#include "timers.h"
#include "ccp.h"
#include "mssp.h"
#include "usart.h"
#include "adc.h"

volatile uint16_t Rpm = 0;
volatile uint8_t needRecalc = 0;

void displayDriver(uint16_t rpm){
    char mil, cen, dec, uni;
    if(needRecalc){
        mil = rpm/1000;
        cen = (rpm%1000)/100;
        dec = ((rpm%1000)%100)/10;
        uni = ((rpm%1000)%100)%10;
        number_lcd(mil, 0xC0);
        number_lcd(cen, 0xC1);
        number_lcd(dec, 0xC2);
        number_lcd(uni, 0xC3);
        text_lcd("Hz");
        needRecalc = 0;
    }
    
}

void main(void) {
    init_pic();
    config_interrupt();
    config_timer0();
    config_timer1();
    __delay_ms(200);
    init_lcd();
    text_lcd("Frequencimetro");
    while(1){
        displayDriver(Rpm);
    }
    
    return;
}

void interrupt isr(){
    if(TMR1IE && TMR1IF){
        TMR1IF = 0;
        //Rpm = TMR0 * 30u;
        Rpm = TMR0 / 2;
        needRecalc = 1;
        TMR0 = 0;
    }
} 