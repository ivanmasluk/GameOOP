#include <iostream>
#include <memory>
#include <string>
#include <clocale>

#include "GameField.h"
#include "Factories/InfantryFactory.h"
#include "Factories/ArcherFactory.h"
#include "Factories/CavalryFactory.h"

void printField(const GameField& field) {
    const int width = field.getWidth();
    const int height = field.getHeight();
    for (int i = 0; i < width + 2; ++i) {
        std::cout << "X ";
    }
    std::cout << '\n';
    for (int y = 0; y < height; ++y) {
        std::cout << "X ";
        for (int x = 0; x < width; ++x) {
            const Unit* unit = field.getUnit(x, y);

            if (unit) {
                std::cout << unit->getType()[0] << ' ';
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << "X\n";
    }
    for (int i = 0; i < width + 2; ++i) {
        std::cout << "X ";
    }
    std::cout << '\n';
}

int main() {
    setlocale(LC_ALL, ".utf8");

    std::cout << "  Сценарий 1: создание поля и фабрики \n";

    GameField field(8, 6, 10);

    InfantryFactory infantryFactory;
    ArcherFactory archerFactory;
    CavalryFactory cavalryFactory;

    field.addUnit(infantryFactory.createUnit("Swordsman"), 1, 1);
    field.addUnit(infantryFactory.createUnit("Spearman"), 2, 1);
    field.addUnit(archerFactory.createUnit("LightArcher"), 4, 2);
    field.addUnit(archerFactory.createUnit("HeavyArcher"), 5, 2);
    field.addUnit(cavalryFactory.createUnit("Cataphract"), 3, 4);
    field.addUnit(cavalryFactory.createUnit("HorseArcher"), 6, 4);

    std::cout << "Юнитов: " << field.getUnitCount() << "\n";
    printField(field);


    std::cout << "\n    Сценарий 2: глубокое копирование \n";

    GameField copy = field;

    field.removeUnit(1, 1);

    std::cout << "Оригинал после удаления: "
        << field.getUnitCount() << " юнитов\n";

    std::cout << "Копия: "
        << copy.getUnitCount() << " юнитов\n";

    std::cout << "Позиции юнитов в копии:\n";

    for (auto& unit : copy) {
        std::cout << unit.getType()
            << " (" << unit.getX()
            << "," << unit.getY() << ")\n";
    }


    std::cout << "\n    Сценарий 3: перемещение поля \n";

    GameField moved = std::move(copy);

    std::cout << "Перемещённое поле: "
        << moved.getUnitCount() << " юнитов\n";

    std::cout << "Источник после перемещения: "
        << copy.getUnitCount() << " юнитов\n";


    std::cout << "\n    Сценарий 4: обход итератором и массовое действие \n";

    std::cout << "До перемещения юнитов:\n";

    for (auto& unit : moved) {
        std::cout << unit.getType()
            << " (" << unit.getX()
            << "," << unit.getY() << ")\n";
    }

    moved.moveAllUnits(1, 0);

    std::cout << "После массового перемещения вправо:\n";

    for (auto& unit : moved) {
        std::cout << unit.getType()
            << " (" << unit.getX()
            << "," << unit.getY() << ")\n";
    }


    std::cout << "\n    Сценарий 5: удаление во время итерации \n";

    const size_t removedCataphracts =
        moved.removeUnitsByType("Cataphract");

    const size_t removedHorseArchers =
        moved.removeUnitsByType("HorseArcher");

    std::cout << "Удалено Cataphract: "
        << removedCataphracts << "\n";

    std::cout << "Удалено HorseArcher: "
        << removedHorseArchers << "\n";

    std::cout << "Осталось юнитов: "
        << moved.getUnitCount() << "\n";

    printField(moved);

    return 0;
}