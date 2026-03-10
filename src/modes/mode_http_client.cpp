//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_http_client.h"

#include <utils/wifi_manager.h>
#include <HTTPClient.h>
#include <utils/input.h>

String url;

void mode_http_client::setup() {
    wifi_manager::promptAndConnect();
    Serial.printf("Enter URL: ");
    url = inputHandler::echo_input("Enter URL: ");
}

void mode_http_client::loop(){
    HTTPClient http;
    http.begin(url);
    int code = http.GET();
    Serial.printf("[%lu] HTTP %d\n", millis(), code);
    if (code == 200) Serial.println(http.getString());
    else Serial.printf("Error: %s\n", HTTPClient::errorToString(code).c_str());
    http.end();
    delay(5000);
}