#ifndef IO_H
#define IO_H
#include <stdint.h>

#define EN_IO_LATCH RC4
#define LATCH_BUS PORTD

typedef enum {
    OFF,
    BLUE,
    GREEN,
    RED,
    CYAN,
    MAGENTA,
    YELLOW
            
}BackgroundColor;

void setDisplayBack(BackgroundColor color);
void refreshIoLatch(void);

#endif