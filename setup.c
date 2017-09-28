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
#include"setup.h"
#include<xc.h>

inline void init_pic(){
    ADCON1 = 0x06; //PORTA operando em modo digital
    TRISA = 0x00; //PORTA como saída
    PORTA = 0x00; //limpa PORTA
    TRISD = 0x00; //PORTD como saída
    PORTD = 0x00; //limpa PORTD
}

inline void config_interrupt(){
    GIE = 0; // habilita interrupções
    TMR0IE = 0; // timer0
    INTE = 0; // RB0, borda configurada no INTEDG, acorda do sleep
    RBIE = 0; // PORTB
    
    PEIE = 0; // habilita interrupção dos periféricos
    TMR1IE = 0; // Estouro do timer1
    TMR2IE = 0; // estouro do timer2
    EEIE = 0; // uma escrita na EEPROM termina
    CCP1IE = 0; // modo capture: quando faz captura
    SSPIE = 0; // spi
    TXIE = 0; //serial
    ADIE = 0; //adc finalizou a conversão
    RCIE = 1;
}