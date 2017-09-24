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
#ifndef _MSSP
#define _MSSP

void master_spi();
void master_i2c();
char i2c_livre(void);
void i2c_start(void);
void i2c_restart(void);
void i2c_send(char dado);
char i2c_testa_ack(void);
void i2c_stop (void);
char i2c_recebe (void);
void i2c_ack(void);
void i2c_nack(void);
char i2c_escreve(unsigned int add, char dado);
char i2c_leitura(unsigned int add);
char fala_com_rtc(unsigned int add, char dado);
#endif