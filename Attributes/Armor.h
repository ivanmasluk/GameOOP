#pragma once

class Armor {
private:
    int value_;

public:
    explicit Armor(int value = 0);

    int getValue() const;
    void setValue(int value);
    int reduceDamage(int damage) const;
};
