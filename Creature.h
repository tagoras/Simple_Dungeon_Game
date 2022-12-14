#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature{
    private:
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    public:
        Creature(const std::string &, char, int, int, int);
        Creature(const Creature &original);

        const std::string& getName() const;
        void setName(const std::string &);

        char getSymbol() const;
        void setChar(char);

        int getHealth() const;
        void setHealth(int);

        int getDamage() const;
        void setDamage(int);

        int getGold() const;
        void setGold(int);

        void reduceHealth(int);
        bool isDead() const;
        void addGold(int);
};

#endif