//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_WIFI_MANAGER_H
#define ESP32TEST_WIFI_MANAGER_H

#include <WiFi.h>

class wifi_manager {
public:
    static void connectSTA(const char* ssid, const char* pass);
    static void promptAndConnect();

    static void startAP(const char* ssid, const char* pass);
    static bool isConnected();
};

extern wifi_manager wifiManager;


#endif //ESP32TEST_WIFI_MANAGER_H