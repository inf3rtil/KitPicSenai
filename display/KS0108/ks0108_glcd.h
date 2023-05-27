#ifndef KS0108_GLCD
#define KS0108_GLCD

#define GLCD_PORT PORTD
#define CS1 PORTBbits.RB0
#define CS2 PORTBbits.RB1
#define RST PORTBbits.RB2
#define RW PORTBbits.RB3
#define RS PORTBbits.RB4
#define E PORTBbits.RB5
#define _XTAL_FREQ 11059200
#define DISPLAY_ON 0b00111111

void glcdCmd(unsigned char cmd);
void glcdData(unsigned char data);
unsigned char glcdRead();
void glcdStart(); 
void glcdClear();
void selectController1();
void selectController2();

#endif