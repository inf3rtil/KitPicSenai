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
#include <pic16f877a.h>
#include "setup.h"
#include "timers.h"

void config_timer0(){
    TMR0 = 0; //limpa timer0
    T0CS = 1; //incremento com oscilador ou clock externo
    T0SE = 0; //borda de subida ou descida
    PSA = 0; //prescaler do TIMER0 ou do WDT
    PS2 = 0; //prescaler
    PS1 = 0;
    PS0 = 0;
}

void config_timer1(){
    TMR1H = 0; //limpa timer1
    TMR1L = 0;
    T1CKPS1 = 0; //prescaler
    T1CKPS0 = 0;
    TMR1CS = 0; //clock interno(FOSC/4) ou externo
    nT1SYNC = 0; //sincronizar timer1 com clock interno
    T1OSCEN = 0; //habilita o oscilador do timer1
    TMR1ON = 1; //liga timer1
}

void config_timer2(){
    TMR2 = 0; //limpa timer2
    TOUTPS3 = 0; //postscaler
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;
    T2CKPS1 = 0; //prescaler
    T2CKPS0 = 1;
    TMR2ON = 1; //liga timer2
}