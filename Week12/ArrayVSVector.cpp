#include<iostream>
// TODO Include the std vector header file

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
        Car cars[3]; // Array of Car objects
        // TODO Declare a vector instead

    public:
        // TODO We no longer have to use an initializer list
        Garage() : cars { {"Tesla"}, {"Ford"}, {"Toyota"} } {}

        void displayAll() {
            // TODO We can't use int
            // And we no longer have a hard coded size
            for (int i = 0; i < 3; i++) {
                // TODO Do I need to make change here?
                cars[i].show();
            }
        }

        // TODO Create a function so we can add cars to the garage later
};

int main() {
    Garage g;
    
    // TODO Add cars

    g.displayAll();
    return 0;
}