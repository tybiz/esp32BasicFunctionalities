#include <Arduino.h>
#include <mode_manager.h>

mode_manager manager;
bool init_now = true;

void setup() {
    Serial.begin(115200);
    Serial.printf("Select mode:  ");
}

void loop() {
    if (init_now && Serial.available()){
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        try {
            manager.switchMode(cmd);
            init_now = false;
            manager.start();
        }
        catch (...) {
            Serial.println("Error reading command!");
        }
    }
    manager.tick();
}