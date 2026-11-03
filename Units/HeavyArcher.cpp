#include "HeavyArcher.h"

HeavyArcher::HeavyArcher()
    : Archer(Health(135), Armor(18), Attack(42)) {
}

HeavyArcher::HeavyArcher(const Health& health, const Armor& armor, const Attack& attack)
    : Archer(health, armor, attack) {
}

std::unique_ptr<Unit> HeavyArcher::clone() const {
    return std::make_unique<HeavyArcher>(health_, armor_, attack_);
}

std::string HeavyArcher::getType() const {
    return "HeavyArcher";
}
