#pragma once

#include "../Attributes/Health.h"
#include "../Attributes/Armor.h"
#include "../Attributes/Attack.h"
#include <memory>
#include <string>

class Unit {
protected:
    Health health_;
    Armor armor_;
    Attack attack_;
    int x_ = 0;
    int y_ = 0;

public:
    Unit(const Health& health, const Armor& armor, const Attack& attack);
    virtual ~Unit() = default;

    const Health& getHealth() const;
    const Armor& getArmor() const;
    const Attack& getAttack() const;
    int getX() const;
    int getY() const;

    void setPosition(int x, int y);
    void move(int dx, int dy);

    virtual std::unique_ptr<Unit> clone() const = 0;
    virtual std::string getType() const = 0;
};
