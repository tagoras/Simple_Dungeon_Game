#include "Player.h"
#include <iostream>

Player::Player(const std::string &name, int health, int damage, int gold):
    Creature(name, '@', health, damage, gold) {}

int Player::getLevel() const {return level;}
void Player::setLevel(int new_level) {level = new_level;}

void Player::levelUp()
{
    ++level;
    setDamage(getDamage() + 1);
}

bool Player::hasWon() const {return level >= 20;}

std::ostream& operator<<(std::ostream &os, const Player &player)
{
    os << "Level: "<< player.getLevel() << ". Healthoints: " << player.getHealth() << ". Damage: " << player.getDamage();
    return os;
}
