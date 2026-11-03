#pragma once

#include "Infantry.h"
#include <memory>
#include <string>

class Spearman : public Infantry {
public:
    Spearman();
    explicit Spearman(const Health& health, const Armor& armor, const Attack& attack);

    std::unique_ptr<Unit> clone() const override;
    std::string getType() const override;
};
