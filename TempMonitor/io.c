#include <xc.h>
#include "io.h"
#include "setup.h"

union {
    struct {
    uint8_t ledB : 1;
    uint8_t ledG : 1;
    uint8_t ledR : 1;
    uint8_t reserved : 5;
    }bits;
    uint8_t value;
}ioLatch = {.value = 0x00};

void setDisplayBack(BackgroundColor color){
    switch(color){
        case OFF:
            ioLatch.bits.ledB = 0;
            ioLatch.bits.ledG = 0;
            ioLatch.bits.ledR = 0;
            break;
        case BLUE:
            ioLatch.bits.ledB = 1;
            ioLatch.bits.ledG = 0;
            ioLatch.bits.ledR = 0;
            break;
        case GREEN:
            ioLatch.bits.ledB = 0;
            ioLatch.bits.ledG = 1;
            ioLatch.bits.ledR = 0;
            break;
        case RED:
            ioLatch.bits.ledB = 0;
            ioLatch.bits.ledG = 0;
            ioLatch.bits.ledR = 1;
            break;
        case CYAN:
            ioLatch.bits.ledB = 1;
            ioLatch.bits.ledG = 1;
            ioLatch.bits.ledR = 0;
            break;
        case MAGENTA:
            ioLatch.bits.ledB = 1;
            ioLatch.bits.ledG = 0;
            ioLatch.bits.ledR = 1;
            break;
        case YELLOW:
            ioLatch.bits.ledB = 0;
            ioLatch.bits.ledG = 1;
            ioLatch.bits.ledR = 1;
            break;
        default:
            break;
    }
    refreshIoLatch();
}

void refreshIoLatch(void){
    LATCH_BUS = ioLatch.value;
    EN_IO_LATCH = 1;
    __delay_ms(10);
    EN_IO_LATCH = 0;
}