//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "bme_680.h"

bme680_sensor bme680;

bool bme680_sensor::begin() {
    if (!_bme.begin()) return false;
    _bme.setTemperatureOversampling(BME68X_OS_8X);
    _bme.setHumidityOversampling(BME68X_OS_2X);
    _bme.setPressureOversampling(BME68X_OS_4X);
    _bme.setIIRFilterSize(BME68X_FILTER_SIZE_3);
    return true;
}

SensorData bme680_sensor::read() {
    SensorData data{};
    data.temperature = _bme.readTemperature();
    data.humidity = _bme.readHumidity();
    data.pressure = _bme.readPressure();
    return data;
}
