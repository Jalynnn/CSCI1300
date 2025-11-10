#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int COUNTRIES = 3;
    const int MEDALS = 4;

    // // Part 2
    // // Create a 2D vector of strings
    // vector<vector<string>> medalTable;

    // Part 1
    // Create a 2D vector of ints
    vector<vector<int>> medalTable;

    // Initialize rows
    for (int i = 0; i < COUNTRIES; i++) {
        // // Part 2
        // vector<string> row(MEDALS); // each element is a default string: ""

        // Part 1
        vector<int> row(MEDALS); // each element is a default int: 0

        medalTable.push_back(row);
    }

    // Print the table
    for (int i = 0; i < COUNTRIES; i++) {
        for (int j = 0; j < MEDALS; j++) {
            // // Part 2
            // cout << "\"" << medalTable[i][j] << "\" "; // quotes show empty strings

            // Part 1
            cout << medalTable[i][j] << " "; // 0s
        }
        cout << endl;
    }

    // Fill in one value to show how it works
    // // Part 2
    // medalTable[0][1] = "Gold";

    // Part 1
    medalTable[0][1] = 5;
    
    for (int i = 0; i < COUNTRIES; i++) {
        for (int j = 0; j < MEDALS; j++) {
            // // Part 2
            // cout << "\"" << medalTable[i][j] << "\" ";

            // Part 1
            cout << medalTable[i][j] << " "; // 0s
        }
        cout << endl;
    }

    return 0;
}
