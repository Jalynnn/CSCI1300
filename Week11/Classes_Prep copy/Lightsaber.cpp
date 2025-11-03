#include "Lightsaber.h"
#include <iostream>
using namespace std;

Lightsaber::Lightsaber(string c, double p) {
    color = c;
    powerLevel = p;
}

void Lightsaber::ignite() {
    cout << "The " << color << " lightsaber ignites with power level "
         << powerLevel << "!" << endl;
}
