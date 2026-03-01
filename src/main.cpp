#include <Arduino.h>
#include <mode_manager.h>
#include <WebServer.h>
#include <utils/input.h>

mode_manager manager;
bool init_now = true;


void setup() {
    Serial.begin(115200);
}

void loop() {
    delay(100);
    while (init_now) {
        String cmd = "";
        cmd = inputHandler::echo_input("Select mode: ");
        cmd.trim();
        try {
            manager.switchMode(cmd);
            init_now = false;
            manager.start();
        } catch (const std::exception &e) {
            Serial.print(e.what());ijku
        }
    }
    manager.tick();
}
