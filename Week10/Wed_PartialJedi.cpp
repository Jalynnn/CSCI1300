/* Complete solution for lecture jedi - does not use the entire completeJedi yet
    Will not compile without constructors to initalize the object */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Jedi {
    public:
        // TODO: Constructors
        Jedi();
        Jedi(string name, int hit_points, int mana, int attack_strength, int defense_strength);

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

// TODO
Jedi::Jedi(){
	name = "Unknown Jedi";
	hit_points = rand() % 101;
	mana = rand() % 101;
	attack_strength = rand() % 26;
	defense_strength = rand() % 26;
}

// TODO
Jedi::Jedi(string name, int hit_points, int mana, int attack_strength, int defense_strength){
	name = name;
	hit_points = hit_points;
	mana = mana;
	attack_strength = attack_strength;
	defense_strength = defense_strength;
}

/* Modifies private variables based on the number of hours
the Jedi has trained for */
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

/* A helper function specifically to show implicit/explicit params 
when calling one member func from another */
void Jedi::helperFunction() {
    setTrain(5);
}

int main() {
    // TODO
    srand(time(0));

    // TODO
    // We will talk more about how to initialize this object Wednesday
    // Note this object is an instance of the class Jedi
    Jedi obiwan("Obi-Wan", 100, 60, 12, 10);
    // Note 
    // Jedi obiwan();

    obiwan.setTrain(5);

    return 0;
}
