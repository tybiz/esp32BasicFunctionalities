//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "bme_680.h"

#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5

bme680_sensor bme680;

bool bme680_sensor::begin() {
    _bme = Adafruit_BME680(BME_CS, BME_MOSI, BME_MISO, BME_SCK);
    if (!_bme.begin()) {
        return false;
    }
    _bme.setTemperatureOversampling(BME68X_OS_8X);
    _bme.setHumidityOversampling(BME68X_OS_2X);
    _bme.setPressureOversampling(BME68X_OS_4X);
    _bme.setIIRFilterSize(BME68X_FILTER_SIZE_3);
    return true;
}

SensorData bme680_sensor::read() {
    SensorData data{};
    if (!_bme.performReading()) {
        return data; // reading failed
    }
    data.temperature = _bme.temperature;
    data.humidity    = _bme.humidity;
    data.pressure    = _bme.pressure / 100.0F; // Pa → hPa
    return data;
}
