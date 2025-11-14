#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> train_cars = {3, 5, 1, 8};

    // Remove the element at index 1
    // .begin is another member function
    // Essentially points us to the first element in a vector - index 0
    train_cars.erase(train_cars.begin() + 1);

    // Not pretty
    // Recall how we remove elements of an array though...
    // We had to use a for loop and shift elements

    // Print elements
    for (size_t i = 0; i < train_cars.size(); i++) {
        cout << train_cars[i] << " ";
    }
    cout << endl;

    cout << "Number of elements: " << train_cars.size() << endl;
}
