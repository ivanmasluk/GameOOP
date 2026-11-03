#include "Cataphract.h"

Cataphract::Cataphract()
    : Cavalry(Health(225), Armor(45), Attack(53)) {
}

Cataphract::Cataphract(const Health& health, const Armor& armor, const Attack& attack)
    : Cavalry(health, armor, attack) {
}

std::unique_ptr<Unit> Cataphract::clone() const {
    return std::make_unique<Cataphract>(health_, armor_, attack_);
}

std::string Cataphract::getType() const {
    return "Cataphract";
}
