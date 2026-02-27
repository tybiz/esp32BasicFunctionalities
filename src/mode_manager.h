//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_MODE_MANAGER_H
#define ESP32TEST_MODE_MANAGER_H
#include <WString.h>


class mode_manager {
public:
    void switchMode(const String & cmd);void tick();
    void start();
};


#endif //ESP32TEST_MODE_MANAGER_H