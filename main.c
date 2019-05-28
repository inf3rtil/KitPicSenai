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


void main(void) {
    init_pic();
    init_lcd();
    text_lcd("      2019      ");
    cmd_lcd(0xC0);
    text_lcd("FernandoFerreira");
    while(1){
        
    }
    
    return;
}
