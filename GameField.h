#pragma once

#include "Units/Unit.h"
#include "GameFieldIterator.h"
#include <vector>
#include <memory>
#include <string>

class GameField {
private:
    int width_;
    int height_;
    size_t maxUnits_;
    std::vector<std::unique_ptr<Unit>> units_;

    bool isCellFree(int x, int y) const;
    int findUnitIndex(int x, int y) const;

public:
    GameField(int width, int height, size_t maxUnits);

    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;
    ~GameField() = default;

    int getWidth() const;
    int getHeight() const;
    size_t getMaxUnits() const;
    size_t getUnitCount() const;
    bool isEmpty() const;

    bool addUnit(std::unique_ptr<Unit> unit, int x, int y);
    bool removeUnit(int x, int y);
    void moveAllUnits(int dx, int dy);
    size_t removeUnitsByType(const std::string& type);
    Unit* getUnit(int x, int y);
    const Unit* getUnit(int x, int y) const;
    void clear();

    GameFieldIterator begin();
    GameFieldIterator end();
};
