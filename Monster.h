#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

class Monster : public Creature{
    public:
        enum class Type{
            DRAGON, ORC, SLIME, MAX_TYPES
        };
        Monster(Type type);

        Monster(const Monster &original);

        Monster(const Creature &rhs);

        static const Creature& getDefaultCreature(Type type);
        static const Creature getRandomMonster();
    
        static int getRandomNumber(int N);

        friend std::ostream& operator<<(std::ostream &os, const Monster &monster);
};

#endif