#include "HorseArcher.h"

HorseArcher::HorseArcher()
    : Cavalry(Health(165), Armor(15), Attack(41)) {
}

HorseArcher::HorseArcher(const Health& health, const Armor& armor, const Attack& attack)
    : Cavalry(health, armor, attack) {
}

std::unique_ptr<Unit> HorseArcher::clone() const {
    return std::make_unique<HorseArcher>(health_, armor_, attack_);
}

std::string HorseArcher::getType() const {
    return "HorseArcher";
}
