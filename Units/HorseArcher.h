#pragma once

#include "Cavalry.h"
#include <memory>
#include <string>

class HorseArcher : public Cavalry {
public:
    HorseArcher();
    explicit HorseArcher(const Health& health, const Armor& armor, const Attack& attack);

    std::unique_ptr<Unit> clone() const override;
    std::string getType() const override;
};
