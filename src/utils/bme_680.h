//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_BME_680_H
#define ESP32TEST_BME_680_H

#include <bsec.h>

struct SensorData {
    float temperature;
    float pressure;
    float humidity;
};

class bme680_sensor {
public:
    static bool begin();
    static SensorData read();
};

extern bme680_sensor bme680;


#endif //ESP32TEST_BME_680_H