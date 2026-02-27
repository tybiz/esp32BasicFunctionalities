//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_bme_680.h"

#include <HardwareSerial.h>

void mode_bme_680::setup() {
    //Setup for bme_680 here
}

void mode_bme_680::loop(){
    // Get readings
    Serial.printf("temp:%.2f,pressure:%.2f,humidity:%.2f,\n", 0.1 , 0.1, 0.1 );
    delay(1000);
}