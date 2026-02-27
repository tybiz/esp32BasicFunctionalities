//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_MODE_CLOCK_SERVER_H
#define ESP32TEST_MODE_CLOCK_SERVER_H


#include <IMode.h>

class mode_clock_server final : public IMode {
    void setup() override;
    void loop() override;
};


#endif //ESP32TEST_MODE_CLOCK_SERVER_H