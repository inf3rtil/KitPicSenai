/*
 * File: main.c
 * Project: KitPicSenai
 * Version: 0.1
 * Date: 27/09/2017
 ************************************************************************
 * Author: Fernando Ferreira Silva 
 * Email: fernando@ninodev.com
 * Site	: https://github.com/feferreira
 * GPG key: BAC8 57299 2EDC9 54F41 3A82 5705 0051 699E 5E69D 
 ************************************************************************
 * Copyright (C) 2017 Fernando Ferreira Silva
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
#include "lcd.h"
#include "setup.h"
#include "seg_7.h"
#include "keyboard.h"
#include "timers.h"
#include "ccp.h"
#include "mssp.h"
#include "usart.h"
#include "adc.h"


typedef union{
    unsigned byte;
    struct bits {
        unsigned bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
    };
}t_byte;

t_byte var;

char quebra_numero(char pos, int num){
    switch (pos){
        case 4:
            num = num/1000;
            break;
        case 3:
            num = num/100;
            break;
        case 2:
            num = (num%100)/10;
            break;
        case 1:
            num = (num%100)%10;
            break;
        default:
            num = 0;
            break;
    }
    
    return (char)num;
}


void teste_lcd(int *numero){
    cmd_lcd(0x80);
    txt_lcd(quebra_numero(3,numero)+LCD_START_ADDRESS);
    txt_lcd(quebra_numero(2,numero)+LCD_START_ADDRESS);
    txt_lcd(quebra_numero(1,numero)+LCD_START_ADDRESS);
    
}




void main(void) {
    init_pic();
    config_interrupt();
    config_usart();
    TRISD = 0x00;
    PORTD = 0xAA;
    RA5 = 1;
    while(1){
        if(RCIF){
            PORTD = 0x55;
            __delay_ms(500);
            char trash = RCREG;
        }
        PORTD = 0xAA;
    }
    
    return;
}
