/* The Blueprint */

#include<iostream>

using namespace std;

class Jedi{
    public:
        // Constructors
        Jedi();
        Jedi(string nameInput, int h, int m, int d, int a);
        
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
};
