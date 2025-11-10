#include <iostream>
#include <string>
using namespace std;

class Lightsaber {
    public:
        // TODO 1. member vars can be public - refer to TODO 2
        string color;
        int power;

        // TODO 3. Discuss Initializer Lists
        Lightsaber(string c, int p) 
        : color(c), power(p) {}
        
        void ignite() const {
            cout << "Igniting " << color << " lightsaber (power " << power << ")." << endl;
        }
};

class Jedi {
    public:
        string name;
        int rank;
        // TODO 4. Composition: Jedi has-a Lightsaber
        Lightsaber saber;

        // TODO 5. Initializer list here too
        Jedi(string n, Lightsaber s, int r)
        : name(n), saber(s), rank(r) {}

        // TODO 2. We call public member vars directly here
        void show() const {
            cout << name << " (rank " << rank << ") - "
                << saber.color << " saber, power " << saber.power << endl;
        }

        void train() {
            saber.power += 5;
        }
};

class JediAcademy {
    public:
        // TODO 6 Array of Jedis in Class
        Jedi jedi[3];

        // TODO 7 Initialize array with initializer list
        JediAcademy()
        : jedi{
            {"Luke Skywalker", Lightsaber("Green", 120), 4},
            {"Ahsoka Tano", Lightsaber("White", 110), 3},
            {"Rey", Lightsaber("Blue", 130), 2}
            }
        {}

        // TODO 8 Looping through array members
        // Using dot notation
        // access member functions 
        void showAll() const {
            for (int i = 0; i < 3; ++i) {
                cout << "[" << i << "] ";
                jedi[i].show();
            }
        }
};

int main() {
    JediAcademy academy; // constructs internal array of Jedis
    cout << "Initial academy roster: " << endl;
    academy.showAll();

    cout << endl << "Direct modification using dot notation" << endl;
    // Example: change name and lightsaber power of index 1
    academy.jedi[1].name = "Ahsoka T.";
    academy.jedi[1].saber.power = 125; // dot notation into inner object
    academy.jedi[1].train(); // method that modifies inner state

    cout << "After modification: " << endl;
    academy.showAll();

    // Demo of calling a Lightsaber method via dot-notation:
    cout << endl << "Ignite second Jedi's saber: " << endl;
    academy.jedi[1].saber.ignite();

    return 0;
}
