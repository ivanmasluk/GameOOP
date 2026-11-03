#pragma once

#include "../Units/Unit.h"
#include <memory>
#include <string>

class UnitFactory {
public:
    virtual ~UnitFactory() = default;
    virtual std::unique_ptr<Unit> createUnit(const std::string& type) = 0;
};
