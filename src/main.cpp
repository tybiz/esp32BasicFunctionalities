#include <Arduino.h>
#include <mode_manager.h>
#include <WebServer.h>

mode_manager manager;
bool init_now = true;


void setup() {
    Serial.begin(115200);
    Serial.printf("Select mode:  ");
}

void loop() {
    while (init_now) {
        if (Serial.available()){
            String cmd = "";
            while (true) {
                if (Serial.available()) {
                    char c = Serial.read();
                    if (c == '\n'){ Serial.print(c);  break; };
                    cmd += c;
                    Serial.print(c);
                }
            }
            cmd.trim();
            try {
                manager.switchMode(cmd);
                init_now = false;
                manager.start();
            }
            catch (...) {
                Serial.println("Error reading command!\n");
                Serial.printf("Select mode:  ");
            }
        }
    }
    manager.tick();
}