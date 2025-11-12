#include<iostream>
// TODO Include the std vector header file
#include<vector>
using namespace std;

class Car {
    private:
        string model;
    public:
        Car(string m) : model(m) {}
        void show() { cout << "Car model: " << model << endl; }
};

class Garage {
    private:
        // Car cars[3]; // Array of Car objects
        // TODO Declare a vector instead
        vector<Car> cars;

    public:
        // TODO We no longer have to use an initializer list
        // Garage() : cars { {"Tesla"}, {"Ford"}, {"Toyota"} } {}
        Garage() {}

        void displayAll() {
            // TODO We can't use int
            // And we no longer have a hard coded size
            for (size_t i = 0; i < cars.size(); i++) {
                // TODO Do I need to make change here?
                cars.at(i).show();
            }
        }

        // TODO Create a function so we can add cars to the garage later
        void addCar(string model) {
            cars.push_back(Car(model));
        }
};

int main() {
    Garage g;
    
    // TODO Add cars
    g.addCar("Tesla");
    g.addCar("Ford");
    g.addCar("Toyota");

    g.displayAll();
    return 0;
}