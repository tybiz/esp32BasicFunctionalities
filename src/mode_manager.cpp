#include "mode_manager.h"
#pragma once
#include "Imode.h"
#include <WString.h>
#include <modes/mode_bme_680.h>
#include <modes/mode_clock_server.h>
#include <modes/mode_http_client.h>
#include <modes/mode_http_server.h>
#include <modes/mode_ntp_clock.h>
#include <modes/mode_serial.h>
#include <modes/mode_sinus.h>

class ModeManager {
    IMode *_current = nullptr;

    void switchMode(const String &cmd) {
        delete _current;
        if (cmd == "bme") _current = new mode_bme_680();
        else if (cmd == "clock server") _current = new mode_clock_server();
        else if (cmd == "http client") _current = new mode_http_client();
        else if (cmd == "http server") _current = new mode_http_server();
        else if (cmd == "ntp") _current = new mode_ntp_clock();
        else if (cmd == "serial") _current = new mode_serial();
        else if (cmd == "sinus") _current = new mode_sinus();
    }

    void tick() const {
        if (_current) _current->loop();
    }

    void start() const {
        if (_current) _current->setup();
    }
};
