#pragma once

#include "Archer.h"
#include <memory>
#include <string>

class LightArcher : public Archer {
public:
    LightArcher();
    explicit LightArcher(const Health& health, const Armor& armor, const Attack& attack);

    std::unique_ptr<Unit> clone() const override;
    std::string getType() const override;
};
