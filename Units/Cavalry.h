#pragma once

#include "Unit.h"

class Cavalry : public Unit {
public:
    Cavalry(const Health& health, const Armor& armor, const Attack& attack);
    virtual ~Cavalry() = default;
};
