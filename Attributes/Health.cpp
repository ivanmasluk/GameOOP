#include "Health.h"

Health::Health(int value) {
    setValue(value);
}

int Health::getValue() const {
    return value_;
}

void Health::setValue(int value) {
    if (value < 0) {
        value_ = 0;
    } else {
        value_ = value;
    }
}

void Health::decrease(int amount) {
    if (amount < 0) {
        amount = 0;
    }
    setValue(value_ - amount);
}

void Health::increase(int amount) {
    if (amount < 0) {
        amount = 0;
    }
    setValue(value_ + amount);
}

bool Health::isZero() const {
    return value_ == 0;
}
