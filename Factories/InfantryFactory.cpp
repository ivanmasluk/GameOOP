#include "InfantryFactory.h"
#include "../Units/Swordsman.h"
#include "../Units/Spearman.h"

std::unique_ptr<Unit> InfantryFactory::createUnit(const std::string& type) {
    if (type == "Swordsman") {
        return std::make_unique<Swordsman>();
    }
    
    if (type == "Spearman") {
        return std::make_unique<Spearman>();
    }

    return nullptr;
}
