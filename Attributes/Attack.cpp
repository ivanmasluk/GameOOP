#include "Attack.h"
#include "Armor.h"

Attack::Attack(int value) {
    setValue(value);
}

int Attack::getValue() const {
    return value_;
}

void Attack::setValue(int value) {
    if (value < 0) {
        value_ = 0;
    } else {
        value_ = value;
    }
}

int Attack::calculateDamage(const Armor& targetArmor) const {
    return targetArmor.reduceDamage(value_);
}
