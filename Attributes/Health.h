#pragma once

class Health {
private:
    int value_;

public:
    explicit Health(int value = 100);

    int getValue() const;
    void setValue(int value);
    void decrease(int amount);
    void increase(int amount);
    bool isZero() const;
};
