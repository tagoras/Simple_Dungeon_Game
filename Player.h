#ifndef Player_H
#define Player_H

#include <string>
#include "Creature.h"

class Player : public Creature{
    private:
        int level = 1;
    public:
        Player(const std::string &name = "Nameless", int health = 10, int damage = 1, int gold = 0);

        int getLevel() const;
        void setLevel(int new_level);

        void levelUp();
        bool hasWon() const;

        friend std::ostream& operator<<(std::ostream &os, const Player &player);
};

#endif