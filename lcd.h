/*This file is part of SerialLCD.

    SerialLCD is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SerialLCD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SerialLCD.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _LCD
#define _LCD

//pinos de saída
#define RS RD4
#define RW RD5
#define EN RD6
#define PORT PORTD
#define LATCH RA4

//comandos do lcd

enum{CLEAR_LCD = 9, LIGA_LCD=6};
inline void enable_lcd(void);
void init_lcd(void);
void clr_lcd(void);
void txt_lcd(char);
void cmd_lcd(char);
void lcd_texto(const char *str);

#endif