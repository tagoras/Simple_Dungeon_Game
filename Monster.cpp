#include "Monster.h"
#include "Creature.h"
#include <array>
#include <random>
#include <iostream>
#include <ctime>

const Creature& Monster::getDefaultCreature(Type type)
{
    const static std::array<Creature, static_cast<int>(Monster::Type::MAX_TYPES)> monsterData {
        {{"Dragon", 'D', 20, 4, 100},
        {"Orc", 'O', 4, 2, 25},
        {"Slime", 'S', 1, 1, 10}}
    };

    return monsterData.at(static_cast<int>(type));
}

std::ostream& operator<<(std::ostream &os, const Monster &monster)
{
    os << monster.getName() << " " << monster.getHealth() << " " << monster.getDamage() << " " << monster.getGold()
    << " " << monster.getSymbol();
}

Monster::Monster(const Monster &original): Creature(original) {}

Monster::Monster(Monster::Type type): Creature{Monster::getDefaultCreature(type)} {}

Monster::Monster(const Creature &rhs): Creature(rhs) {}

const Creature Monster::getRandomMonster()
{
    int number{getRandomNumber(static_cast<int>(Monster::Type::MAX_TYPES))};
    return getDefaultCreature(static_cast<Monster::Type>(number));
}

int Monster::getRandomNumber(int N)
{
    int number = std::rand() % N;
    return number;
}