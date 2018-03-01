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
#include "adc.h"

void config_adc(){
    PCFG3 = 0; // modo de operação do conversor
    PCFG2 = 0;
    PCFG1 = 0;
    PCFG0 = 0;
    TRISA0 = 1;
    TRISA1 = 1;
    ADFM = 1; //resultado justificado a direita
    ADCS2 = 0; // clock de conversão 8 Tosc
    ADCS1 = 0;
    ADCS0 = 1;
    ADON = 1; //liga o conversor
    CHS2 = 0; //seleciona RA1 
    CHS1 = 0;
    CHS0 = 0;
}

int start_ad(){
    const float resol = 0.4887596;
    GO = 1;
    while (nDONE);
    int resultado = ADRESH;
    resultado = resultado << 2;
    resultado = resultado + ADRESL;
    int convert = resultado*resol;
    return convert;
}