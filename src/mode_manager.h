//
// Created by Tymoteusz Biziuk on 27/02/2026.
//

#pragma once
#include <WString.h>
#include "IMode.h"

class mode_manager {
public:
    void switchMode(const String& cmd);
    void tick() const;
    void start() const;
private:
    IMode* _current = nullptr;
};

extern mode_manager modeManager;