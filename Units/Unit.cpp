#include "Unit.h"

Unit::Unit(const Health& health, const Armor& armor, const Attack& attack)
    : health_(health), armor_(armor), attack_(attack) {
}

const Health& Unit::getHealth() const {
    return health_;
}

const Armor& Unit::getArmor() const {
    return armor_;
}

const Attack& Unit::getAttack() const {
    return attack_;
}

int Unit::getX() const {
    return x_;
}

int Unit::getY() const {
    return y_;
}

void Unit::setPosition(int x, int y) {
    x_ = x;
    y_ = y;
}

void Unit::move(int dx, int dy) {
    x_ += dx;
    y_ += dy;
}
