#pragma once

#include "Infantry.h"
#include <memory>
#include <string>

class Swordsman : public Infantry {
public:
    Swordsman();
    explicit Swordsman(const Health& health, const Armor& armor, const Attack& attack);

    std::unique_ptr<Unit> clone() const override;
    std::string getType() const override;
};
