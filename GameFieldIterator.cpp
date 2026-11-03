#include "GameFieldIterator.h"

GameFieldIterator::GameFieldIterator(Container::iterator current, Container::iterator end)
    : current_(current), end_(end) {
}

Unit& GameFieldIterator::operator*() {
    return **current_;
}

Unit* GameFieldIterator::operator->() {
    return current_->get();
}

GameFieldIterator& GameFieldIterator::operator++() {
    if (current_ != end_) {
        ++current_;
    }
    return *this;
}

bool GameFieldIterator::operator!=(const GameFieldIterator& other) const {
    return current_ != other.current_;
}

bool GameFieldIterator::operator==(const GameFieldIterator& other) const {
    return current_ == other.current_;
}
