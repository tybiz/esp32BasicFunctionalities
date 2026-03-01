//
// Created by Tymoteusz Biziuk on 01/03/2026.
//

#ifndef ESP32TEST_INPUT_H
#define ESP32TEST_INPUT_H
#include <WString.h>


class inputHandler {
public:
    static String echo_input(const String &prompt);
};

extern inputHandler input;


#endif //ESP32TEST_INPUT_H
