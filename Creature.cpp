#include "Creature.h"
#include <iostream>

Creature::Creature(const std::string &name, char symbol, int health, int damage, int gold):
    name{name}, symbol{symbol}, health{health}, damage{damage}, gold{gold} {}

const std::string& Creature::getName() const {return name;}
void Creature::setName(const std::string &new_name) {name = new_name;}

char Creature::getSymbol() const {return symbol;}
void Creature::setChar(char new_symbol) {symbol = new_symbol;}

int Creature::getHealth() const {return health;}
void Creature::setHealth(int new_health) {health = new_health;}

int Creature::getDamage() const {return damage;}
void Creature::setDamage(int new_damage) {damage = new_damage;}

int Creature::getGold() const {return gold;}
void Creature::setGold(int new_gold) {gold = new_gold;}

void Creature::reduceHealth(int damage) {health -= damage;}

bool Creature::isDead() const {return !(health > 0);}

void Creature::addGold(int amount) {gold += amount;}

Creature::Creature(const Creature &original): name{original.name}, symbol{original.symbol}, 
    health{original.health}, damage{original.damage}, gold{original.damage}
{

}