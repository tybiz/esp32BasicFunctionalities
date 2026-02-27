//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_MODE_NTP_CLOCK_H
#define ESP32TEST_MODE_NTP_CLOCK_H


#include <IMode.h>
#include <time.h>

class mode_ntp_clock final : public IMode {
    void setup() override;

    static void get_current_time(const tm *&ti);

    void loop() override;
};


#endif //ESP32TEST_MODE_NTP_CLOCK_H