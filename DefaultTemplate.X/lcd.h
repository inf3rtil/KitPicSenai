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
#ifndef _LCD
#define _LCD

//pinos de saída
#define RS RD4
#define RW RD5
#define EN RD6
#define PORT PORTD
#define LATCH RA4

enum lcd{
    LCD_CHAR_OFFSET = 0x30,
    LCD_ENABLE_TIME_US = 15
};

//comandos do lcd

void init_lcd(void);
void clr_lcd(void);
void char_lcd(uint8_t);
void cmd_lcd(uint8_t);
void text_lcd(const uint8_t *str);
void number_lcd(uint8_t add, uint8_t data);

#endif