/* The instructions */

#include "Jedi.h"
#include <iostream>
using namespace std;

// Default constructor
Jedi::Jedi() {
    name = "Unknown Jedi";
    health = 100;
    mana = 50;
    defense = 10;
    attack = 15;
}

// Overloaded constructor
Jedi::Jedi(string nameInput, int h, int m, int d, int a) {
    name = nameInput;
    health = h;
    mana = m;
    defense = d;
    attack = a;
}

// Getters
string Jedi::getName() const {
    return name;
}

int Jedi::getHealth() const {
    return health;
}

int Jedi::getMana() const {
    return mana;
}

int Jedi::getDefense() const {
    return defense;
}

int Jedi::getAttack() const {
    return attack;
}

// Setters
void Jedi::setName(string newName) {
    name = newName;
}

// Train increases attack and defense based on hours trained
void Jedi::setTrain(double hours) {
    if (hours <= 0) {
        cout << name << " must train for positive hours.\n";
        return;
    }

    if (mana < hours * 2) { // training consumes mana
        cout << name << " is too tired to train that long.\n";
        return;
    }

    cout << name << " trains for " << hours << " hours.\n";
    mana -= hours * 2; // consume mana
    if (mana < 0) mana = 0;

    attack += hours * 2; // small attack gain
    defense += hours * 2; // small defense gain
}

// Rest restores health and mana
void Jedi::getRest() {
    health += 10;
    mana += 10;
    if (health > 100) health = 100;
    if (mana > 100) mana = 100;
}

// Attack another Jedi – returns damage done
int Jedi::attackEnemy(int enemyDefense) {
    int damage = attack - (enemyDefense / 2);
    if (damage < 0) damage = 0;
    return damage;
}

// Take damage – lowers health
void Jedi::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}
