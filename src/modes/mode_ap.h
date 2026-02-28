//
// Created by Tymoteusz Biziuk on 28/02/2026.
//

#ifndef ESP32TEST_MODE_AP_H
#define ESP32TEST_MODE_AP_H
#include <IMode.h>


class mode_ap : public IMode {
    void setup() override;
    void loop() override;
};


#endif //ESP32TEST_MODE_AP_H