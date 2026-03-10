#include "lcd.h"

lcd lcd_display;

bool lcd::begin() {
    Wire.begin(21, 22); // SDA=21, SCL=22
    _lcd.begin(LCD_COLS, LCD_ROWS);
    _lcd.clear();
    return true;
}

void lcd::clear() {
    _lcd.clear();
}

void lcd::print(int col, int row, const char* text) {
    if (col < 0 || col >= LCD_COLS) return;
    if (row < 0 || row >= LCD_ROWS) return;
    _lcd.setCursor(col, row);
    _lcd.print(text);
}