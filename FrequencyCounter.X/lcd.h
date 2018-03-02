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

//comandos do lcd

void init_lcd(void);
void clr_lcd(void);
void txt_lcd(char);
void cmd_lcd(char);
void text_lcd(const char *str);
void number_lcd(char data, char add);

#endif