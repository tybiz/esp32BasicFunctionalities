//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "ntp.h"

#include <Arduino.h>
#include <ctime>
#include <HardwareSerial.h>

ntp ntpClient;

void ntp::get_current_time(tm &ti) {
    const time_t t = time(nullptr);
    ti = *localtime(&t);
}

void ntp::config_local_time() {
    configTime(3600, 3600, "pl.pool.ntp.org");
    tm ti{};
    while (!getLocalTime(&ti)) {
        delay(500);
    }
}
