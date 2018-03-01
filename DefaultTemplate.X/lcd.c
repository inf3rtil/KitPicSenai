/*This file is part of KitPicSenai.

    KitPicSenai is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    KitPicSenai is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with KitPicSenai.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <xc.h>
#include <stdint.h>
#include "lcd.h"
#include <pic16f877a.h>
#include "setup.h"

void init_lcd()
{
    LATCH = 1;
	RS = 0;
	RW = 0;
	EN = 0;

	cmd_lcd(0x28);
	cmd_lcd(0x06);
	cmd_lcd(0x0D);
	clr_lcd();
}

void clr_lcd()
{
	cmd_lcd(0x01);
	__delay_ms(500);
    LATCH = 0;
}
void char_lcd(uint8_t txt){
    LATCH = 1;
	__delay_ms(10);
	PORT = (uint8_t)((txt >> 4) & 0x0F);
	RS = 1;
	EN = 1;
    __delay_us(LCD_ENABLE_TIME_US);
    EN = 0;
	PORT = (uint8_t)(txt & 0x0F);
	RS = 1;
	EN = 1;
    __delay_us(LCD_ENABLE_TIME_US);
    EN = 0;
    LATCH = 0;
}

void cmd_lcd(uint8_t cmd){
    LATCH = 1;
	__delay_ms(10);
	PORT = (uint8_t)((cmd >> 4) & 0x0F);
	RS = 0;
	EN = 1;
    __delay_us(LCD_ENABLE_TIME_US);
    EN = 0;
	PORT = (uint8_t)(cmd & 0x0F);
	RS = 0;
	EN = 1;
    __delay_us(LCD_ENABLE_TIME_US);
    EN = 0;
    LATCH = 0;
}

void text_lcd(const uint8_t *str){
    while(*str){
          char_lcd(*str);
          ++str;
         }
}

void number_lcd(uint8_t add, uint8_t data){
    cmd_lcd(add);
    char_lcd((uint8_t)(data+LCD_CHAR_OFFSET));
}