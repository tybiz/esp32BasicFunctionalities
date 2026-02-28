#include "mode_manager.h"

#include <HardwareSerial.h>
#include <stdexcept>

#include "modes/mode_sinus.h"
#include "modes/mode_serial.h"
#include "modes/mode_bme_680.h"
#include "modes/mode_ntp_clock.h"
#include "modes/mode_http_client.h"
#include "modes/mode_http_server.h"
#include "modes/mode_clock_server.h"

mode_manager modeManager;

void mode_manager::switchMode(const String& cmd) {
    delete _current;
    if      (cmd == "sinus")       _current = new mode_sinus();
    else if (cmd == "serial")      _current = new mode_serial();
    else if (cmd == "bme")         _current = new mode_bme_680();
    else if (cmd == "ntp")         _current = new mode_ntp_clock();
    else if (cmd == "httpclient")  _current = new mode_http_client();
    else if (cmd == "httpserver")  _current = new mode_http_server();
    else if (cmd == "clockserver") _current = new mode_clock_server();
    else if (cmd == "ap")          _current = ;
    else if (cmd == "help")        Serial.println("Available modes: sinus, serial, bme, ntp, httpclient, httpserver, clockserver");
    else {
        throw std::runtime_error("Unknown mode!");
    };
}

void mode_manager::tick() const {
    if (_current) _current->loop();
}

void mode_manager::start() const {
    if (_current) _current->setup();
}
