#include "ArcherFactory.h"
#include "../Units/LightArcher.h"
#include "../Units/HeavyArcher.h"

std::unique_ptr<Unit> ArcherFactory::createUnit(const std::string& type) {
    if (type == "LightArcher") {
        return std::make_unique<LightArcher>();
    }
    
    if (type == "HeavyArcher") {
        return std::make_unique<HeavyArcher>();
    }

    return nullptr;
}
