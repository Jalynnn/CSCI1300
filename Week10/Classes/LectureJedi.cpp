/* Empty ready for lecture script */

#include <iostream>
#include <string>

using namespace std;

// Declare a class called Jedi

    // Public members here

        // let's write the func prototype for our mutator func we looked at today in the slides

        // Here is the func prototype for a helper func we are going to look at
        void helperFunction();
    
    // Private members here

        // Jedi name
        string name;

        // Jedi HP
        int hit_points;

        // Jedi mana
        int mana;

        // Jedi attack strength
        int attack_strength;

        // Jedi defense strength
        int defense_strength;

// What's missing here?



// Create a setTrain function 
// that takes in the number of hours the Jedi must train for 
// and returns nothing
[Rtn Type] [Class]::[FuncName](/*Define explicit param*/) {
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


// When might you call a member func from within another member func?
// Maybe you want the default training hours to be 5
void Jedi::helperFunction() {
    setTrain(5);
}


// Note that main doesn't use Jedi::
int main() {
    // We will talk more about how to initialize this object Wednesday
    // Note this object is an instance of the class Jedi
    Jedi obi("Obi-Wan", 100, 60, 12, 10);

    // Explicit param?
    obi.setTrain(5);

    return 0;
}
