#pragma once

#include "Units/Unit.h"
#include <vector>
#include <memory>

class GameFieldIterator {
private:
    using Container = std::vector<std::unique_ptr<Unit>>;
    Container::iterator current_;
    Container::iterator end_;

public:
    GameFieldIterator(Container::iterator current, Container::iterator end);

    Unit& operator*();
    Unit* operator->();

    GameFieldIterator& operator++();

    bool operator!=(const GameFieldIterator& other) const;
    bool operator==(const GameFieldIterator& other) const;
};
