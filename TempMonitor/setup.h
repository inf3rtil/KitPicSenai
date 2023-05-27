#ifndef SETUP_H
#define SETUP_H

#define _XTAL_FREQ 11059200
#pragma config MCLRE=OFF, FOSC=HS, WDTE=OFF, BOREN=ON, LVP=OFF, PWRTE=ON

// analog ports
#define S0 RA0
#define S1 RA1
#define S2 RA2
#define S3 RA3
#define S4 RA5
#define S5 RE0
#define S6 RE1
#define S7 RE2

#define KEYBOARD_PORT PORTB

void setupPic(void);
void setupPorts(void);
void setupAd(void);
void setupSerial(void);
void setupEeprom(void);
void setupDisplay(void);
void setupTimer1(void);


#endif