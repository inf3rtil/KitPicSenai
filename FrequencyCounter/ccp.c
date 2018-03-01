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
#include "ccp.h"
#include "timers.h"

void config_compare(){
    CCP1M3 = 1; //configura módulo ccp1 e resultado do capture
    CCP1M2 = 0; //gera interrupção e RC2 = 1
    CCP1M1 = 0;
    CCP1M0 = 0;
    
    TRISC2 = 0; //RC2 como saída
    CCPR1H = 0; //valor a ser comparado
    CCPR1L = 0;
    // o timer1 deve estar configurado no modo timer, ou contador sincrono
    config_timer1();
}

void config_capture(){
    CCP1M3 = 0; //configura módulo ccp1 e prescaler do capture
    CCP1M2 = 1; //captura a cada borda de descida
    CCP1M1 = 0;
    CCP1M0 = 0;
    
    TRISC2 = 1; //RC2 como entrada
    CCPR1H = 0; //limpa 
    CCPR1L = 0;
    // o timer1 deve estar configurado no modo timer, ou contador sincrono
    config_timer1();
    
}

void config_pwm(){
    config_timer2();
    TRISC2 = 0; //RC2 como saída
    PR2 = 249; //período do pwm = (PR2 + 1) * 4 * Tosc * (TMR2 prescale)
             //frequencia do pwm = 1/período do pwm
    CCPR1L = 50; //10 bits de duty cycle CCPR1L = 8 MSB,
    CCP1X = 0; // 2 LSB
    CCP1Y = 0; // Duty cycle = (CCPR1L:CCP1Y)*Tosc*(TMR2 prescale)
    
    CCP1M3 = 1; //configura módulo ccp1 para pwm
    CCP1M2 = 1;
    CCP1M1 = 0;
    CCP1M0 = 0;
}