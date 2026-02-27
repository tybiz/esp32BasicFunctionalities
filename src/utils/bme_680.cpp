//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "bme_680.h"

bme680_sensor bme680;

bool bme680_sensor::begin() {

    return true;
}

SensorData bme680_sensor::read() {
    SensorData data{};

    data.temperature = 0.0f;
    data.pressure = 0.0f;
    data.humidity = 0.0f;
    return data;
}