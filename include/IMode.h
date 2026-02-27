//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#ifndef ESP32TEST_IMODE_H
#define ESP32TEST_IMODE_H

#pragma once

class IMode {
public:
  virtual void setup() = 0;
  virtual void loop() = 0;
  virtual ~IMode() = default;
};

#endif //ESP32TEST_IMODE_H