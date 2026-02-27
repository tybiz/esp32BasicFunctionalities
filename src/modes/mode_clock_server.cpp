//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_clock_server.h"

#include <utils/ntp.h>
#include <utils/wifi_manager.h>
#include <WebServer.h>

static WebServer server(80);

void mode_clock_server::setup() {
    wifi_manager::promptAndConnect();

    ntp::config_local_time();

    server.on("/", []() {
        tm ti{};
        ntp::get_current_time(ti);
        server.send(200, "text/plain",
            String(ti.tm_hour) + ":" + String(ti.tm_min) + ":" + String(ti.tm_sec));
    });
    server.begin();

    wifi_manager::printIP();
}

void mode_clock_server::loop() {
    server.handleClient();
}
