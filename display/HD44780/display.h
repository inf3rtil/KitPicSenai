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

#ifndef DISPLAY_H
#define DISPLAY_H

#define _XTAL_FREQ  8000000 //fosc in hertz, used for delay functions
#define LCD_PORT    PORTD //port of lcd, in 4 bits mode connect RD[0:4] in DB[4:8]
#define LCD_EN      PORTDbits.RD6 //enable pin
#define LCD_RS      PORTDbits.RD4 //RS pin
#define LCD_RW	    PORTDbits.RD5 //RW pin

enum lcd_instruction{
    lcd_cmd = 0,
    lcd_txt = 1,
    lcd_4bit = 0x28,
    lcd_4bit_510 = 0x24, 
    lcd_clear = 0x01,
    lcd_home = 0x02,
    lcd_inc_address = 0x06,
    lcd_dec_address = 0x04,
    lcd_rot_left = 0x05,
    lcd_rot_right = 0x07,
    lcd_inc_cursor = 0x14,
    lcd_dec_cursor = 0x10,
    lcd_off = 0x08,
    lcd_cursor_on_blink_on = 0x0F,
    lcd_cursor_on_blink_off = 0x0E,
    lcd_cursor_off_blink_on = 0x0D,
    lcd_cursor_off_blink_off = 0x0C
    
};

void init_lcd();
void clr_lcd();
void byte_lcd(char mode, char data); //mode = lcd_cmd or lcd_txt, data = instruction or address
inline void enable_lcd();
void create_custom_char(const char *data, char address);
void text_lcd(const char *);

#endif
