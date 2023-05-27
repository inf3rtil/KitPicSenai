#include "display.h"
#include "lcd.h"
#include "io.h"

void showSplashScreen(void){
    clr_lcd();
    setDisplayBack(CYAN);
    text_lcd("  TEMP MONITOR");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("  VERSAO:0.1.0");
}

void writeOperationMask(void){
    clr_lcd();
    setDisplayBack(GREEN);
    text_lcd("SENSOR MAX:    C");
    byte_lcd(LCD_CMD, 0x8E);
    byte_lcd(LCD_CHAR, 0b11011111);
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("       TMP:    C");
    byte_lcd(LCD_CMD, 0xCE);
    byte_lcd(LCD_CHAR, 0b11011111);
}

void writeSensorValues(uint8_t sensor, uint8_t value, uint8_t max){
    setSensorNumber(sensor);
    byte_lcd(LCD_CMD, 0xCB);
    byte_lcd(LCD_CHAR, value/100 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)%10 + 0x30);
    byte_lcd(LCD_CMD, 0x8B);
    byte_lcd(LCD_CHAR, max/100 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (max%100)%10 + 0x30);
}

void showConfigLimitsMenu(){
    clr_lcd();
    text_lcd("CONFIGURAR");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("SENSORES");
}

void showConfigNsensors(){
    clr_lcd();
    text_lcd("QUANTIDADE DE");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd("SENSORES >");
}

void showChangePassword(void){
    clr_lcd();
    text_lcd("ALTERAR SENHA");
}

void showChangeParam(void){
    clr_lcd();
    text_lcd("SENSOR TIME:   s");
    byte_lcd(LCD_CMD, 0xC7);
    text_lcd("MAX:    C");
    byte_lcd(LCD_CMD, 0xCE);
    byte_lcd(LCD_CHAR, 0b11011111);
}

void setSensorNumber(uint8_t sensor){
    byte_lcd(LCD_CMD, 0xC2);
    byte_lcd(LCD_CHAR, 0x30);
    byte_lcd(LCD_CHAR, sensor+0x31);
}

void setConfigSensorParam(uint8_t sensor, uint8_t time, uint8_t max){
    setSensorNumber(sensor);
    setChangeTimeout(time);
    setChangeMaxValue(max);
}

void setChangeTimeout(uint8_t value){
    byte_lcd(LCD_CMD, 0x8C);
    byte_lcd(LCD_CHAR, value/100 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)%10 + 0x30);
}

void setChangeMaxValue(uint8_t value){
    byte_lcd(LCD_CMD, 0xCB);
    byte_lcd(LCD_CHAR, value/100 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)/10 + 0x30);
    byte_lcd(LCD_CHAR, (value%100)%10 + 0x30);
}

void showSaveConfig(void){
    clr_lcd();
    text_lcd("SALVAR CONFIG.?");
    byte_lcd(LCD_CMD, 0xC0);
    text_lcd(" #-SIM    *-NAO ");
}

void setSensorQuantity(uint8_t value){
    byte_lcd(LCD_CMD, 0xCA);
    byte_lcd(LCD_CHAR, value/10 + 0x30);
    byte_lcd(LCD_CHAR, value%10 + 0x30);
}