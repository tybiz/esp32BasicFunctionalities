//
// Created by Tymoteusz Biziuk on 01/03/2026.
//

#include "input.h"

#include <HardwareSerial.h>
#include <WString.h>

String inputHandler::echo_input(const String& prompt) {
    String inp;
    Serial.print(prompt);
    while (true) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == '\n'){ Serial.print(c);  break; };
            inp += c;
            Serial.print(c);
        }
    }
    inp.trim();
    return inp;
}
