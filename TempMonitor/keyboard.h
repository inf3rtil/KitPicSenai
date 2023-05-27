#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdint.h>

#define KBD_PORT PORTB
#define COL1 RB7
#define COL2 RB6
#define COL3 RB5
#define COL4 RB4
#define L1 RB3
#define L2 RB2
#define L3 RB1
#define L4 RB0

uint8_t scanKeys(void);

#endif