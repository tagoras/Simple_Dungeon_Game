#ifndef POTION_H
#define POTION_H

class Potion{
    public:
    enum class Type{
            HEALTH, STRENGTH, POISON, MAX_TYPES
        };

        Potion(Type type, int effect);
        
        static Potion getRandomPotion();

        Type getType() const;
        int getEffect() const;
    private:
        Type type;
        int effect;    
};

#endif