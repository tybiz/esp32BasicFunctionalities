//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_sinus.h"

#include <HardwareSerial.h>

void mode_sinus::setup(){}

void mode_sinus::loop()
{
    Serial.printf("sin:%.2f\n", sin(millis()));
    delay(100);
}