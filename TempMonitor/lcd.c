#include "lcd.h"
#include <xc.h>
#include "setup.h"

void init_lcd(){
    __delay_ms(1000);
    byte_lcd(LCD_CMD, lcd_4bit);
    byte_lcd(LCD_CMD, lcd_inc_address);
    byte_lcd(LCD_CMD, lcd_cursor_off_blink_off);
    clr_lcd();
}

void clr_lcd(){
    byte_lcd(LCD_CMD, lcd_clear);
    __delay_ms(100);
}

void byte_lcd(char mode, char data){
    LCD_LATCH = 1;
    LCD_RS = mode;
	LCD_PORT = (char)((data >> 4) & 0x0F);
    LCD_RS = mode;
    enable_lcd();
    LCD_PORT = (char)(data & 0x0F);
    LCD_RS = mode;
    enable_lcd();
    __delay_us(15);
    LCD_LATCH = 0;

}

inline void enable_lcd(){
    LCD_EN = 1;
    __delay_us(15);
    LCD_EN = 0;
}

void text_lcd(const char *str){
    while(*str){
          byte_lcd(LCD_CHAR, *str);
          ++str;
         }
}

void create_custom_char(const char *data, char address){
    byte_lcd(LCD_CMD,(unsigned char)(0x40 + (address * 8)));
    for(char i = 0; i < 8; ++i){
        byte_lcd(LCD_CHAR, data[i]);
    }
}