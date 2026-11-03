#include "Armor.h"

Armor::Armor(int value) {
    setValue(value);
}

int Armor::getValue() const {
    return value_;
}

void Armor::setValue(int value) {
    if (value < 0) {
        value_ = 0;
    } else {
        value_ = value;
    }
}

int Armor::reduceDamage(int damage) const {
    if (damage < 0) {
        damage = 0;
    }

    int remaining = damage - value_;

    if (remaining > 0) {
        return remaining;
    } else {
        return 0;
    }
}
