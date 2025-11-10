#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> values = {1.5, 2.0, 3.5};

    for (int i = 0; i < values.size(); i++) {  // warning here
    // for (size_t i = 0; i < values.size(); i++) {
        values[i] *= 2;
    }

    for (double v : values) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
