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