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
#include "mssp.h"

void master_spi(){
    SSPM3 = 0; //seleciona o modo de operação
    SSPM2 = 0; //modo master, clock = Fosc/4
    SSPM1 = 0;
    SSPM0 = 0;
    
    CKE = 1; //transmissão ocorre de idle para active
    
    SSPEN = 1; //habilita spi
}

void master_i2c(){
//    TRISC4 = TRISC3 = 1;
//    SSPEN = 1; //habilita módulo MSSP
//    SSPM3 = 1; //modo mestre, clock = Fosc / (4 x (SSPAD + 1))
//    SSPM2 = 0;
//    SSPM1 = 0;
//    SSPM0 = 0;
//    ACKDT = 0;
//    SMP = 1; //controle slow rate desabilitado
//    CKE = 0; //nível de entrada conforme especificação i2c
//    SSPADD = 99; //para Fosc = 4Mhz, clock = 100kHz
    TRISC = 0b00011000;
    SSPCON = 0b00101000;
    SSPADD = 99;
    SSPSTAT = 0b10000000;
}

char i2c_livre(void){
    if(R_W) return 0; //retorna 0 se existe transmissão em andamento
    if (SSPCON2 & 0x1F) return 0;
    else return 1; //retorna 1 se livre
}

void i2c_start(void){
    SEN = 1; //inicia condição start
    ACKDT = 0;
    while (SEN ==1); //aguarda terminar
}

void i2c_restart(void){
    RSEN = 1; //inicia restart
    ACKDT = 0;
    while(RSEN == 1); //aguarda terminar
}

void i2c_send(char dado){
    SSPBUF = dado; //carrega dado no SSPBUF
    while (BF == 1); //aguarda buffer esvaziar
    while (R_W); //aguarda transmissão terminar
}

char i2c_testa_ack(void){
    if(ACKSTAT) return 1; //recebeu com sucesso
    else return 0; //erro
}

void i2c_stop (void){
    PEN = 1; //inicia stop
    while (PEN); // aguarda terminar
}

char i2c_recebe (void){
    RCEN = 1;
    while(RCEN);
    return SSPBUF;
}

void i2c_ack(void){
    ACKDT = 0;
    ACKEN = 1;
    while(ACKEN);
}

void i2c_nack(void){
    ACKDT = 0;
    ACKEN = 1;
    while(ACKEN);
}

char i2c_escreve(unsigned int add, char dado){
    if (i2c_livre()){
        i2c_stop();
        return -1;
    }
    else {
        i2c_start();
        add <<= 1;
        i2c_send(add);
        if(!i2c_testa_ack()){
            i2c_stop();
            return -1;
        }
        i2c_send(dado);
        if(!i2c_testa_ack()){
            i2c_stop();
            return -1;
        }
        i2c_stop();
        return 0;
    }
}

char i2c_leitura(unsigned int add){
    if (i2c_livre()){
        i2c_stop();
        return -1;
    }
    i2c_start();
    add <<= 1;
    add++;
    i2c_send(add);
    if(!i2c_testa_ack()){
            i2c_stop();
            return -1;
        }
    char dado = i2c_recebe();
    i2c_nack();
    i2c_stop();
    return dado;
}

