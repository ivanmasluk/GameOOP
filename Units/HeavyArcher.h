#pragma once

#include "Archer.h"
#include <memory>
#include <string>

class HeavyArcher : public Archer {
public:
    HeavyArcher();
    explicit HeavyArcher(const Health& health, const Armor& armor, const Attack& attack);

    std::unique_ptr<Unit> clone() const override;
    std::string getType() const override;
};
