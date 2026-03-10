//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_ntp_clock.h"

#include <ctime>
#include <utils/lcd.h>
#include <utils/wifi_manager.h>
#include <utils/ntp.h>

void mode_ntp_clock::setup() {
    wifi_manager::promptAndConnect();
    ntp::config_local_time();
    lcd_display.begin();
}

void mode_ntp_clock::loop(){
    tm ti{};
    ntp::get_current_time(ti);

    Serial.printf("%02d:%02d:%02d\n", ti.tm_hour, ti.tm_min, ti.tm_sec);
    char buf[9];
    snprintf(buf, sizeof(buf), "%02d:%02d:%02d", ti.tm_hour, ti.tm_min, ti.tm_sec);
    lcd_display.print(0, 0, buf);
    delay(1000);
}

