#include "LightArcher.h"

LightArcher::LightArcher()
    : Archer(Health(120), Armor(8), Attack(45)) {
}

LightArcher::LightArcher(const Health& health, const Armor& armor, const Attack& attack)
    : Archer(health, armor, attack) {
}

std::unique_ptr<Unit> LightArcher::clone() const {
    return std::make_unique<LightArcher>(health_, armor_, attack_);
}

std::string LightArcher::getType() const {
    return "LightArcher";
}
