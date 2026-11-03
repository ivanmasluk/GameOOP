#include "GameField.h"
#include <utility>

bool GameField::isCellFree(int x, int y) const {
    for (const auto& unit : units_) {
        if (unit->getX() == x && unit->getY() == y) {
            return false;
        }
    }
    return true;
}

int GameField::findUnitIndex(int x, int y) const {
    for (size_t i = 0; i < units_.size(); ++i) {
        if (units_[i]->getX() == x && units_[i]->getY() == y) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

GameField::GameField(int width, int height, size_t maxUnits)
    : width_(width > 0 ? width : 1),
    height_(height > 0 ? height : 1),
    maxUnits_(maxUnits) {
}

GameField::GameField(const GameField& other)
    : width_(other.width_),
    height_(other.height_),
    maxUnits_(other.maxUnits_) {

    for (const auto& unit : other.units_) {
        auto copiedUnit = unit->clone();

        copiedUnit->setPosition(
            unit->getX(),
            unit->getY()
        );

        units_.push_back(std::move(copiedUnit));
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this == &other) {
        return *this;
    }

    std::vector<std::unique_ptr<Unit>> copiedUnits;
    copiedUnits.reserve(other.units_.size());

    for (const auto& unit : other.units_) {
        auto copiedUnit = unit->clone();

        copiedUnit->setPosition(
            unit->getX(),
            unit->getY()
        );

        copiedUnits.push_back(std::move(copiedUnit));
    }

    width_ = other.width_;
    height_ = other.height_;
    maxUnits_ = other.maxUnits_;
    units_ = std::move(copiedUnits);

    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width_(other.width_),
    height_(other.height_),
    maxUnits_(other.maxUnits_),
    units_(std::move(other.units_)) {

    other.width_ = 0;
    other.height_ = 0;
    other.maxUnits_ = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    width_ = other.width_;
    height_ = other.height_;
    maxUnits_ = other.maxUnits_;
    units_ = std::move(other.units_);

    other.width_ = 0;
    other.height_ = 0;
    other.maxUnits_ = 0;

    return *this;
}

int GameField::getWidth() const {
    return width_;
}

int GameField::getHeight() const {
    return height_;
}

size_t GameField::getMaxUnits() const {
    return maxUnits_;
}

size_t GameField::getUnitCount() const {
    return units_.size();
}

bool GameField::isEmpty() const {
    return units_.empty();
}

bool GameField::addUnit(std::unique_ptr<Unit> unit, int x, int y) {
    if (!unit) {
        return false;
    }

    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return false;
    }

    if (units_.size() >= maxUnits_) {
        return false;
    }

    if (!isCellFree(x, y)) {
        return false;
    }

    unit->setPosition(x, y);
    units_.push_back(std::move(unit));

    return true;
}

bool GameField::removeUnit(int x, int y) {
    int index = findUnitIndex(x, y);

    if (index == -1) {
        return false;
    }

    units_.erase(units_.begin() + index);

    return true;
}

void GameField::moveAllUnits(int dx, int dy) {
    for (auto it = begin(); it != end(); ++it) {
        it->move(dx, dy);
    }
}

size_t GameField::removeUnitsByType(const std::string& type) {
    size_t removedCount = 0;

    for (auto it = units_.begin(); it != units_.end();) {

        if ((*it)->getType() == type) {
            it = units_.erase(it);
            ++removedCount;
        }
        else {
            ++it;
        }
    }

    return removedCount;
}

Unit* GameField::getUnit(int x, int y) {
    int index = findUnitIndex(x, y);

    if (index == -1) {
        return nullptr;
    }

    return units_[index].get();
}

const Unit* GameField::getUnit(int x, int y) const {
    int index = findUnitIndex(x, y);

    if (index == -1) {
        return nullptr;
    }

    return units_[index].get();
}

void GameField::clear() {
    units_.clear();
}

GameFieldIterator GameField::begin() {
    return GameFieldIterator(units_.begin(), units_.end());
}

GameFieldIterator GameField::end() {
    return GameFieldIterator(units_.end(), units_.end());
}