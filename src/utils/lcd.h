#pragma once
#include <Wire.h>
#include <rgb_lcd.h>

#define LCD_COLS 16
#define LCD_ROWS 2

class lcd {
public:
    bool begin();
    void clear();
    void print(int col, int row, const char* text);

private:
    rgb_lcd _lcd;
};

extern lcd lcd_display;