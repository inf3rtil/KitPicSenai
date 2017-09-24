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