//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_serial.h"
#include <HardwareSerial.h>

void mode_serial::setup(){}

void mode_serial::loop() {
    Serial.print("Time: " + String(millis()) + "ms\n");
    delay(1000);
}