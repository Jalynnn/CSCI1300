/* The Blueprint */

#include<iostream>

// ADDED
#include"Lightsaber.h"

using namespace std;

class Jedi{
    public:
        // Constructors
        Jedi();

        // MODIFIED
        // Alt is pass a Lightsaber object
        Jedi(string nameInput, int h, int m, int d, int a, string saberColor, double powerLevel);
        
        // Getters
        string getName() const;
        int getHealth() const;
        int getMana() const;
        int getDefense() const;
        int getAttack() const;

        // Setters
        void setName(string newName);
        void setTrain(double hours);
        void getRest();
        int attackEnemy(int enemyDefense); //return how much attack damage is done
        void takeDamage(int damage); //take damage in a fight

    private:
        string name;
        int health, mana, defense, attack;

        // ADDED
        Lightsaber saber; // Composition
};
