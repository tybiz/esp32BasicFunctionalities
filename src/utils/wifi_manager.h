//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_WIFI_MANAGER_H
#define ESP32TEST_WIFI_MANAGER_H

#include <WiFi.h>

class wifi_manager {
public:
    void connectSTA(const char* ssid, const char* pass); // join existing network (2.3)
    void startAP(const char* ssid, const char* pass);    // become access point (2.2)
    bool isConnected();
};

extern wifi_manager wifiManager;


#endif //ESP32TEST_WIFI_MANAGER_H