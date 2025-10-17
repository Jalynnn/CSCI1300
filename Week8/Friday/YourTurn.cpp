// In the comments, write down what each of these include statements are used for
#include <iostream> // ?
#include <fstream> // ?
#include <string> // ?
#include <cstdlib> // ?
#include <ctime> // ?

using namespace std;

// Global variables provided for you
// How do we know these are global variables?
const int row = 3;
const int col = 3;
const int new_row = row;
const int new_col = col + 1;


// TODO: Write a function that reads each line from input.txt
// Store each line in array of strings
// use getline and stop when there are no more lines
// return how many lines you read
int readInputFile(string filename, string lines[], int linesSize) {
    // linesSize is the companion variable - What does this mean?
    
    // HINTS:
    // 1. Open the file
    // 2. Check if it opened successfully
    // 3. Use a loop to read each line
    // 4. Store each line in lines[] array
    // 5. Return the number of lines (the counter for how many lines read)
    // 6. Close the file
    return 0; // Temporary - Replace this
}


// TODO: Extract the name from each line and write to output.txt
// Check out what input.txt contains
// Use substring to collect only the name before the first ','
// Use a do-while loop to write all names to the output file
void processAndWriteNames(string lines[], int nLines, string outFileName) {
    ofstream file_out(outFileName);
    if (!file_out) {
        cout << "Error: Could not open " << outFileName << endl;
        return;
    }

    int i = 0;
    // HINTS:
    // 1. Challenge yourself to use a do-while loop here 
    // 2. Find the first comma in lines[i]
    // 3. Write the names to file_out
    // 4. Repeat until i < nLines

    file_out.close();
}


// Fill a 2D array with random decimal numbers (one decimal place)
// row and col are globally defined, so we don't have to worry about the companion variable
// init is commonly seen in coding and stands for initialize
void init2DArray(double arr[row][col]) { 
    // HINTS:
    // 1. Use a nested for loop
    // 2. Stop at row and col
    // 3. How did we use random number to have one decimal place? Something with modulus and division
}


// Print the 2D array using nested loops
void print2DArray(double arr[row][col]) {
    // HINTS
    // 1. use a nested for loop
    // 2. Extremely similar to init2DArray but much simplier
    // 3. Use cout and endl!
}


// Copy the original array into a larger one
// With a larger capacity, we can insert a new random number in the middle
// We want to keep the organization so we shift all of the elements
void copyAndInsert(double oldArr[row][col], double newArr[new_row][new_col], double newValue) {
    // find the middle index of the old array (Provided):
    int totalOldSize = row * col;
    int insertIndex = totalOldSize / 2;

    // current index of the oldArr
    int oldIndex = 0;

    // As you copy values to the newArr, insert the newValue
    // How do we access each element in a 2D array? Nested for loops
    // Loop 1 through rows
        // Loop 2 through cols
            // What if the current index equals the insertIndex?
                // Enter new value
            // What if there are still values in the oldArr?
                // add the oldArr elements to the newArr
                // Increment the oldIndex counter
            // What if we used all the elements from the oldArr and there is still space in the newArr?
                // enter zeros

}

int main() {
    // What does this line do?
    // Does it only need to be declared once?
    srand(time(0));

    const int linesSize = 10;
    string lines[linesSize];

    // Read File
    // What will the readInputFile return and assign to 'n'?
    int n = readInputFile("input.txt", lines, linesSize);

    // Classic input validation
    // What am I validating here?
    if (n > 0){
        processAndWriteNames(lines, n, "output.txt");
    }
    else {
        cout << "No lines found" << endl;
    }

    double arr[row][col]; // 2D array declared
    init2DArray(arr); // Initialize the 2D array

    // Print the original array
    print2DArray(arr);

    // Copy the original to a larger array
    // Insert a new random value
    double newArr[new_row][new_col];
    double newValue = (rand() % 100) / 10.0;
    copyAndInsert(arr, newArr, newValue);

    // Print each element of the newArr
    // Iterate through rows 
        // Iterate through cols
            // Print each element

    return 0;
}