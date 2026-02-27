//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_serial.h"
#include <HardwareSerial.h>

void mode_serial::setup(){
    //Serial prt is already initialized in main.cpp
}

void mode_serial::loop(){
    Serial.printlf("Time: " + String(millis()) + "ms\n");
    delay(1000);
}