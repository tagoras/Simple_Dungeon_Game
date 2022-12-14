#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Potion.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

void game_flow();

void turn(Player &player, Monster &monster);

bool potionReceived();

std::string get_text_input();

void potion_action(Player &player,const Potion &potion);

void new_monster(Monster &monster);

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	game_flow();

	return 0;
}

void game_flow()
{
    Player player;

    std::cout << "Please enter your name:";
    std::string name = get_text_input();
    player.setName(name);

    Monster current_monster = Monster::getRandomMonster();
    std::cout << "You have encountered a " << current_monster.getName() << std::endl;

    while(player.getLevel() < 20 && player.getHealth() > 0)
    {
        if(current_monster.isDead())
        {
            new_monster(current_monster);
        }

        turn(player, current_monster);

        std::cout << player << std::endl;
    }
    if(player.getLevel() == 20) std::cout << "You won the game with " << player.getGold() << " gold.";
}

std::string get_text_input()
{
    std::string in;
    std::getline(std::cin, in);
    return in;
}

void turn(Player &player, Monster &monster)
{
    std::string user_choice;
  
    while(user_choice != "Run" && user_choice != "Fight")
    {
        std::cout << "(R)un or (F)ight: ";
        user_choice  = get_text_input();
        
    }
    
    if(user_choice == "Run")
    {
        int attempt = Monster::getRandomNumber(2);
        
        if(attempt)
        {
            std::cout << "You fled" << std::endl;

            new_monster(monster);
        }
        else
        {
            std::cout << "You failed to flee" << std::endl;

            player.reduceHealth(monster.getDamage());
            std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << std::endl;

            if(player.isDead())
            {
                std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold." << std::endl;
                std::cout << "Too bad you can't take it with you!" << std::endl;
            }
        }
        return;
    }
    else if(user_choice == "Fight")
    {
        monster.reduceHealth(player.getDamage());
        std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage." << std::endl;

        if(monster.isDead())
        {
            player.addGold(monster.getGold());
            player.levelUp();
            std::cout << "You killed the "<< monster.getName() << "." << std::endl;
            std::cout << "You are now level " << player.getLevel() << std::endl;
            std::cout << "You found " << monster.getGold() << " gold." << std::endl;

            // Potion thing
            if(potionReceived())
            {
                std::cout << "The monster dropped a potion! But will you drink it? (Yes/No)" << std::endl;
                getline(std::cin, user_choice);
                if(user_choice == "Yes")
                {
                    Potion potion = Potion::getRandomPotion();
                    potion_action(player, potion);
                }
                else
                {
                    std::cout << "You threw the potion away..." << std::endl;
                }
            }

            return;
        }

        std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << std::endl;
        player.reduceHealth(monster.getDamage());

        if(player.isDead())
        {
            std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold." << std::endl;
            std::cout << "Too bad you can't take it with you!" << std::endl;
            return;
        }
    }
    
}

bool potionReceived()
{
    int number;
    while(number == 0) number  = Monster::getRandomNumber(11);
    return number <= 3;
}

void new_monster(Monster &monster)
{
    monster = Monster::getRandomMonster();
    std::cout << "You have encountered a " << monster.getName() << std::endl;
}

void potion_action(Player &player,const Potion &potion)
{
    if(potion.getType() == Potion::Type::HEALTH)
    {
        player.setHealth(potion.getEffect() + player.getHealth());
        std::cout << "Player healed for " << potion.getEffect() << " health points." << std::endl;
    }
    else if(potion.getType() == Potion::Type::STRENGTH)
    {
        player.setDamage(potion.getEffect() + player.getDamage());
        std::cout << "Player damage increased by " << potion.getEffect() << " damage points." << std::endl;
    }
    else if(potion.getType() == Potion::Type::POISON)
    {
        player.reduceHealth(potion.getEffect());
        std::cout << "POISON!!! Player received " << potion.getEffect() << " damage";
    }
}