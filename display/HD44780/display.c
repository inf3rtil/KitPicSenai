/*
 * File: display.c
 * Project: HD44780forPIC
 * Version: 0.1
 * Date: 25/12/2017
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

#include "lcd.h"
#include <xc.h>

void init_lcd(){
    byte_lcd(lcd_cmd, lcd_4bit_510);
    byte_lcd(lcd_cmd, 0x06);
    byte_lcd(lcd_cmd, lcd_cursor_off_blink_on);
    clr_lcd();
}

void clr_lcd(){
    byte_lcd(lcd_cmd, lcd_clear);
    __delay_ms(500);
}

void byte_lcd(char mode, char data){
    LCD_RS = mode;
	LCD_PORT = (char)((data >> 4) & 0x0F);
    LCD_RS = mode;
    enable_lcd();
    LCD_PORT = (char)(data & 0x0F);
    LCD_RS = mode;
    enable_lcd();
    __delay_us(15);
}

inline void enable_lcd(){
    LCD_EN = 1;
    __delay_us(15);
    LCD_EN = 0;
}

void text_lcd(const char *str){
    while(*str){
          byte_lcd(lcd_txt, *str);
          ++str;
         }
}

void create_custom_char(const char *data, char address){
    byte_lcd(lcd_cmd,(unsigned char)(0x40 + (address * 8)));
    for(char i = 0; i < 8; ++i){
        byte_lcd(lcd_txt, data[i]);
    }
}
