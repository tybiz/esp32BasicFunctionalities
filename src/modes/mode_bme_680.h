//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_MODE_BME_680_H
#define ESP32TEST_MODE_BME_680_H


#include <IMode.h>

class mode_bme_680 final : public IMode {
    void setup() override;
    void loop() override;
};


#endif //ESP32TEST_MODE_BME_680_H