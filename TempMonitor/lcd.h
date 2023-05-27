#ifndef LCD_H
#define LCD_H

#define LCD_PORT    PORTD //port of lcd, in 4 bits mode connect RD[0:4] in DB[4:8]
#define LCD_EN      PORTDbits.RD6 //enable pin
#define LCD_RS      PORTDbits.RD4 //RS pin
#define LCD_RW	    PORTDbits.RD5 //RW pin
#define LCD_LATCH   PORTCbits.RC5 //Latch enable Pin

enum lcd_instruction{
    LCD_CMD = 0,
    LCD_CHAR = 1,
    lcd_4bit = 0x28,
    lcd_4bit_510 = 0x24, 
    lcd_clear = 0x01,
    lcd_home = 0x02,
    lcd_inc_address = 0x06,
    lcd_dec_address = 0x04,
    lcd_rot_left = 0x05,
    lcd_rot_right = 0x07,
    lcd_inc_cursor = 0x14,
    lcd_dec_cursor = 0x10,
    lcd_off = 0x08,
    lcd_cursor_on_blink_on = 0x0F,
    lcd_cursor_on_blink_off = 0x0E,
    lcd_cursor_off_blink_on = 0x0D,
    lcd_cursor_off_blink_off = 0x0C
    
};

void init_lcd(void);
void clr_lcd(void);
void byte_lcd(char mode, char data); //mode = lcd_cmd or lcd_txt, data = instruction or address
inline void enable_lcd();
void create_custom_char(const char *data, char address);
void text_lcd(const char *);

#endif