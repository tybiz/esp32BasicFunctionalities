//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_NTP_H
#define ESP32TEST_NTP_H
#include <ctime>


class ntp {
public:
    static void get_current_time(tm &ti);
    static void config_local_time();
};

extern ntp ntpClient;


#endif //ESP32TEST_NTP_H
