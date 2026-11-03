#pragma once

#include "UnitFactory.h"
#include <memory>
#include <string>

class CavalryFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(const std::string& type) override;
};
