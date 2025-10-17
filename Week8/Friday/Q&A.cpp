#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Helper Functions */
/*********************************************************************************************/

// This first function is to print a 1d array
void printArray(const int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

// This second function is to print a 2d array (matrix)
// When would you use 2D Arrays? Spreadsheets, Games like chess boards, Images

const int cols = 3;

// void printMatrix(int mat[][], int rows, int cols) {
// While the matrix already defined elsewhere, the compiler still needs to know how to interpret the ref var
// Touch on ref var
// C++ needs to know the number of cols to correctly calculate memory offsets

void printMatrix(int mat[][cols], int rows) {
    cout << "[";
    for(int row = 0; row < rows; row++) {
        cout << "[";
        for(int col = 0; col < cols; col++) {
            cout << mat[row][col] << " ";
        }
        cout << "]";
    }
    cout << "]";
}

/* Inserting in Current and Copied Arrays */
/*********************************************************************************************/

void insertValue(double arr[], int &size, int capacity, double newValue, int insertIndex) {
    // Check if there's space
    if (size >= capacity) {
        cout << "Error: no room to insert.\n";
        return;
    }

    // Shift elements one position to the right
    for (int i = size; i > insertIndex; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new value
    arr[insertIndex] = newValue;

    // Update logical size
    size++;
}

void copyAndInsert(double oldArr[], double newArr[], int oldSize, int newSize, double newValue) {
    // Find the middle index of the oldArr
    int insertIndex = oldSize / 2;

    // Tracks where we are in the oldArr
    int oldIndex = 0;

    // i iterates through the elements of the new array
    for (int i = 0; i < newSize; i++) {
        // if we reach the new position
        if (i == insertIndex) {
            // Add that value to the new position
            newArr[i] = newValue;
        }
        // Continue copying elements from old array
        else {
            // As long as there are still numbers in the oldArr..
            if(oldIndex < oldSize) {
                // Add those old element values to the new array
                newArr[i] = oldArr[oldIndex];
                // Increase the old array's counter
                oldIndex++;
            }
            // If there are no more elements in the old array...
            else {
                // fill the rest of the new array with zeros
                newArr[i] = 0.0;
            }
        }
    }
}

/* Random Numbers */
/*********************************************************************************************/

void randomNumbers() {
    srand(time(0));

    int randBetween0And9 = rand()%10;
    int randBetween1And10 = rand()%10+1;
    int randBetween20And100 = rand()%(100-20+1)+20;
   
    double randBetween0and9p9 = (rand()%100) / 10.0;
        // rand() % 100 gives 0 to 99
        // divide by 10 gives 0 to 9.9
    double randBetween0and3p0 = (rand()%(3*10+1))/10.0;

    cout << "Random number between 0 and 9: " << randBetween0And9 << endl;
    cout << "Random number between 1 and 10: " << randBetween1And10 << endl;
    cout << "Random number between 20 and 100: " << randBetween20And100 << endl;
    cout << "Random number between 0 and 9.9: " << randBetween0and9p9 << endl;
    cout << "Random number with one decimal between 0 and 3: " << randBetween0and3p0 << endl;
}

/* Do While Loops */
/*********************************************************************************************/

void doWhile() {
    int number;

    do {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number <= 0);  // repeat if user enters 0 or a negative number

    cout << "You entered: " << number << endl;
}

/* String and Substring */
/*********************************************************************************************/

int date() {
    string date = "2025-10-17";  // format: YYYY-MM-DD

    // Extract parts using substr(startIndex, length)
    string year = date.substr(0, 4);   // characters 0–3
    string month = date.substr(5, 2);  // characters 5–6
    string day = date.substr(8, 2);    // characters 8–9

    cout << "Full date: " << date << endl;
    cout << "Year: " << year << endl;
    cout << "Month: " << month << endl;
    cout << "Day: " << day << endl;

    // You can convert them to numbers if needed
    int yearNum = stoi(year);
    int monthNum = stoi(month);
    int dayNum = stoi(day);

    // Practical use
    if (yearNum > 2025)
        cout << "This date is in the future!" << endl;
    else
        cout << "This date is in the past or this year." << endl;

}
