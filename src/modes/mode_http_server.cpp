//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_http_server.h"

#include <utils/ntp.h>
#include <utils/wifi_manager.h>
#include <WebServer.h>
#include "utils/bme_680.h"

static WebServer server(80);

void mode_http_server::setup() {
    wifi_manager::promptAndConnect();

    bme680_sensor::begin();

    server.on("/", []() {
        auto [temperature, pressure, humidity] = bme680_sensor::read();
        server.send(200, "text/plain",
             "temp:" + String(temperature) + ",press:" + String(pressure) + ",hum:" + String(humidity));
    });
    server.begin();

    wifi_manager::printIP();
}

void mode_http_server::loop(){
    server.handleClient();
}