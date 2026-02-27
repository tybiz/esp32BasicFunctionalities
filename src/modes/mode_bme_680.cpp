//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_bme_680.h"

#include <HardwareSerial.h>
#include <utils/bme_680.h>

void mode_bme_680::setup() {
    bme680_sensor::begin();
}

void mode_bme_680::loop(){
    auto [temperature, pressure, humidity] = bme680_sensor::read();
    Serial.printf("temp:%.2f,pressure:%.2f,humidity:%.2f,\n", temperature , pressure, humidity );
    delay(1000);
}