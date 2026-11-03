#include "CavalryFactory.h"
#include "../Units/Cataphract.h"
#include "../Units/HorseArcher.h"

std::unique_ptr<Unit> CavalryFactory::createUnit(const std::string& type) {
    if (type == "Cataphract") {
        return std::make_unique<Cataphract>();
    }
    
    if (type == "HorseArcher") {
        return std::make_unique<HorseArcher>();
    }

    return nullptr;
}
