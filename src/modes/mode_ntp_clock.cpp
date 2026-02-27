//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_ntp_clock.h"

#include <ctime>
#include <utils/wifi_manager.h>
#include <utils/ntp.h>

void mode_ntp_clock::setup() {
    wifi_manager::promptAndConnect();
    ntp::config_local_time();
}

void mode_ntp_clock::loop(){
    tm ti{};
    ntp::get_current_time(ti);

    Serial.printf("%02d:%02d:%02d\n", ti.tm_hour, ti.tm_min, ti.tm_sec);
    // TO DO: Upload time to lcd too
    delay(1000);
}

