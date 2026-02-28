//
// Created by Tymoteusz Biziuk on 28/02/2026.
//

#include "mode_ap.h"

#include <utils/wifi_manager.h>

void mode_ap::setup() {
    wifi_manager::startAP();
}

void mode_ap::loop() {
    Serial.printf("Connected clients count: ");
    Serial.println(WiFi.softAPgetStationNum());
    delay(2000);
}