#include "Swordsman.h"

Swordsman::Swordsman()
    : Infantry(Health(180), Armor(23), Attack(38)) {
}

Swordsman::Swordsman(const Health& health, const Armor& armor, const Attack& attack)
    : Infantry(health, armor, attack) {
}

std::unique_ptr<Unit> Swordsman::clone() const {
    return std::make_unique<Swordsman>(health_, armor_, attack_);
}

std::string Swordsman::getType() const {
    return "Swordsman";
}
