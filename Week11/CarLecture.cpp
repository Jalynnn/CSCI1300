#include<iostream>
using namespace std;

class Engine{
	public:
	    Engine(int hp) { horsepower = hp; }
	    void start();
	private:
	    int horsepower;
};

void Engine::start() { 
	cout << "Engine started." << endl;
}

class Car{
	private:
	    Engine engine; // Object as data member (Composition)
	public:
	    Car() : engine(200) { 
		    cout << "Car constructor called." << endl;
	    } // initialize member object in initializer list
	    void drive(); 
};

void Car::drive() {
    engine.start(); // using the object’s function
	cout << "Car is moving!" << endl;
}

int main() {
    Car myCar;
    myCar.drive();
}




// PART TWO

// class Engine{
// 	public:
// 	    Engine(int hp) { horsepower = hp; }
// 	    void start();
// 	private:
// 	    int horsepower;
// };

// void Engine::start() { 
// 	cout << "Engine started." << endl;
// }

// class Vehicle{
// 	public:
// 	    Vehicle() { 
// 		    cout << "Vehicle constructor called." << endl;
// 	    }
// 	    void move() {
// 		    cout << "The vehicle moves forward." << endl;
// 	    }
// };

// class Car : public Vehicle {
// 	private:
// 	    Engine engine;
// 	public:
// 	    Car() : engine(200) { 
// 		    cout << "Car constructor called." << endl;
// 	    }
// 	    void drive();
// };

// void Car::drive() {
//     engine.start(); // using the object’s function
// 	cout << "Car is moving!" << endl;
// }

// int main() {
//     Car myCar;
//     myCar.drive();
//     myCar.move();
// }