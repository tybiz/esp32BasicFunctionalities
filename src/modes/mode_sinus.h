//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_MODE_SINUS_H
#define ESP32TEST_MODE_SINUS_H
#include <IMode.h>

class mode_sinus final : public IMode {
    void setup() override;
    void loop() override;
};


#endif //ESP32TEST_MODE_SINUS_H