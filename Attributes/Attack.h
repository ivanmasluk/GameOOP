#pragma once

class Armor;  // forward declaration

class Attack {
private:
    int value_;

public:
    explicit Attack(int value = 10);

    int getValue() const;
    void setValue(int value);
    int calculateDamage(const Armor& targetArmor) const;
};
