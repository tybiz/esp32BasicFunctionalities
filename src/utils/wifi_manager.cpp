//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#include "wifi_manager.h"

#include "input.h"


wifi_manager wifiManager;

void wifi_manager::promptAndConnect() {
    const String ssid = inputHandler::echo_input("Enter URL: ");
    String pass;
    while (true) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == '\n'){ Serial.print("*");  break; };
            pass += c;
            Serial.print(c);
        }
    }

    connectSTA(ssid.c_str(), pass.c_str());
}

void wifi_manager::connectSTA(const char* ssid, const char* pass) {
    WiFiClass::mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.printf("Connecting to WiFi\n");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected! IP: " + WiFi.localIP().toString());
}

void wifi_manager::startAP(const char* ssid, const char* pass) {
    WiFiClass::mode(WIFI_AP);
    WiFi.softAP(ssid, pass);
    Serial.println("AP started! IP: " + WiFi.softAPIP().toString());
}

bool wifi_manager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void wifi_manager::printIP() {
    Serial.println("IP: " + WiFi.localIP().toString());
}

