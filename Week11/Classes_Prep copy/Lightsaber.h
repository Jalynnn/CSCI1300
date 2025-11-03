#include <string>
using namespace std;

class Lightsaber {
private:
    string color;
    double powerLevel;

public:
    Lightsaber(string c, double p);
    void ignite();
};
