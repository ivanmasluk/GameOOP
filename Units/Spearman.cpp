#include "Spearman.h"

Spearman::Spearman()
    : Infantry(Health(150), Armor(30), Attack(33)) {
}

Spearman::Spearman(const Health& health, const Armor& armor, const Attack& attack)
    : Infantry(health, armor, attack) {
}

std::unique_ptr<Unit> Spearman::clone() const {
    return std::make_unique<Spearman>(health_, armor_, attack_);
}

std::string Spearman::getType() const {
    return "Spearman";
}
