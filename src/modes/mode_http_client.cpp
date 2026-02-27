//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "mode_http_client.h"

#include <utils/wifi_manager.h>
#include <HTTPClient.h>

String url;

void mode_http_client::setup() {
    wifi_manager::promptAndConnect();
    while (true) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == '\n'){ Serial.print(c);  break; };
            url += c;
            Serial.print(c);
        }
    }
}

void mode_http_client::loop(){
    HTTPClient http;
    http.begin(url);
    int code = http.GET();
    Serial.printf("[%lu] HTTP %d\n", millis(), code);
    if (code == 200) Serial.println(http.getString());
    else Serial.printf("Error: %s\n", HTTPClient::errorToString(code).c_str());
    http.end();
}