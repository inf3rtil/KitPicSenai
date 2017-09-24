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