#include "Potion.h"
#include "Monster.h"
#include <vector>

Potion::Potion(Type type, int effect): type{type}, effect{effect} {}

Potion Potion::getRandomPotion()
{
    static std::vector<Potion> potion_vector{
        {Potion::Type::HEALTH, 3}, 
        {Potion::Type::STRENGTH, 1}, 
        {Potion::Type::POISON, -1}
    };

    int number = Monster::getRandomNumber(static_cast<int>(Potion::Type::MAX_TYPES) - 1);

    return Potion{potion_vector[number]};
}

Potion::Type Potion::getType() const {return type;}
int Potion::getEffect() const {return effect;}