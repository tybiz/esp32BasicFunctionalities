//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_LCD_DISPLAY_H
#define ESP32TEST_LCD_DISPLAY_H

class lcd {
public:
    bool begin();
    void clear();
    void print(int col, int row, const char* text);

};

extern lcd lcd_display;

#endif //ESP32TEST_LCD_DISPLAY_H