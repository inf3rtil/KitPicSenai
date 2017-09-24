#include <xc.h>
#include <pic16f877a.h>
#include "setup.h"
#include "usart.h"

void config_usart(){
    TRISC7 = 1;
    TRISC6 = 0;
    SYNC = 0; //modo assincrono
    SPBRG = 25; //baud rate de 9600
    BRGH = 1;
    TX9 = 0; //desabilita bit 9 (TX9D) de ser transmitido
    RX9 = 0; //desabilita bit 9 (RX9D) de ser recebido
    TXEN = 1; //habilita transmissão serial (TX)
    SPEN = 1; //habilita toda a porta serial
    CREN = 1;
}