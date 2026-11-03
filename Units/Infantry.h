#pragma once

#include "Unit.h"

class Infantry : public Unit {
public:
    Infantry(const Health& health, const Armor& armor, const Attack& attack);
    virtual ~Infantry() = default;
};
