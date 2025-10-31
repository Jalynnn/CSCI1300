/* Complete solution for lecture jedi - does not use the entire completeJedi yet
    Will not compile without constructors to initalize the object */

#include <iostream>
#include <string>

using namespace std;

class Jedi {
    public:
        // Mutators (Setters)
        void setTrain(double hours); // trains and improves stats

        void helperFunction(); // Temp func to show calling another member func

    private:
        string name;
        int hit_points; // HP
        int mana; // Energy for attacks/training
        int attack_strength; // Power when attacking
        int defense_strength; // Power when defending
};

// Create a setTrain function 
// that takes in the number of hours the Jedi must train for 
// and returns nothing
void Jedi::setTrain(double hours) {
    // Print a warning if the hours is not positive and exit
    if (hours <= 0) {
        cout << name << " must train for positive hours." << endl;
        return;
    }

    // Print a warning if the hours doubled is greater than the mana available and exit
    if (mana < hours * 2) {
        cout << name << " is too tired to train that long." << endl;
        return;
    }

    cout << name << " trains for " << hours << " hours." << endl;

    // Subtract from mana the hours doubled
    mana -= hours * 2;

    // Add to the attack_strength the hours doubled
    attack_strength += hours / 2;

    // Add to the defense_strength the hours doubled
    defense_strength += hours / 3;
}

// Maybe you want the default training hours to be 5
void Jedi::helperFunction() {
    setTrain(5);
}

int main() {
    // We will talk more about how to initialize this object Wednesday
    // Note this object is an instance of the class Jedi
    Jedi obi("Obi-Wan", 100, 60, 12, 10);

    obi.setTrain(5);

    return 0;
}
