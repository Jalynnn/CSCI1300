/* The story that uses the Jedi */

#include <iostream>
#include "Jedi.h"

using namespace std;

// Note objects are based by value by default 
// Creates copies of the objects
// Both objects are destroyed at the end of the function
// the luke and annikin in main are unchanged
// I would use & if I did want them to change
int battle(Jedi &firstJedi, Jedi secondJedi){ 
    int damage; 
    while (firstJedi.getHealth() > 0 && secondJedi.getHealth() > 0){ 
        damage = firstJedi.attackEnemy(secondJedi.getDefense()); 
        secondJedi.takeDamage(damage); 
        damage = secondJedi.attackEnemy(firstJedi.getDefense()); 
        firstJedi.takeDamage(damage); 
    } 
    
    if (firstJedi.getHealth() > 0){ 
        return 1; 
    } else { 
        return 2; 
    } 
}

// Train for a week (mutates the Jedi)
void trainForWeek(Jedi &j, double hoursPerDay = 1.0) {
    for (int days = 0; days < 7; ++days) {
        j.getRest();
        j.setTrain(hoursPerDay);
    }
}

// Print summary after training
void printTrainingResult(const Jedi &j) {
    cout << "After a week of training, " << j.getName()
         << " has built up health of " << j.getHealth()
         << " and attack strength of " << j.getAttack()
         << " and defense strength of " << j.getDefense()
         << endl;
}

int main() {
    // Create Luke and train him
    Jedi luke("Luke Skywalker", 100, 60, 12, 10);
    trainForWeek(luke);
    printTrainingResult(luke);

    // Create opponent
    Jedi annikin("Annikin Skywalker", 50, 50, 50, 50);
    cout << "Meanwhile, " << annikin.getName() << " has a great deal of power." << endl;
    cout << "Unfortunately, the dark side is calling..." << endl;

    annikin.setName("Darth Vader");
    cout << "Now, he is known as " << annikin.getName() << " and is one of the Sith." << endl;
    cout << luke.getName() << " must defeat " << annikin.getName() << "!" << endl;

    // Fight and announce
    int result = battle(luke, annikin);
    if (result == 1) {
        cout << luke.getName() << " is victorious!" << endl;
    } else {
        cout << annikin.getName() << " is victorious!" << endl;
    }

    return 0;
}
