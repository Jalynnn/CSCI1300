// In the comments, write down what each of these include statements are used for
#include <iostream> // used for console input/output (cin, cout)
#include <fstream> // used for file input/output (ifstream, ofstream)
#include <string> // used for std::string class and string operations like find and substr
#include <cstdlib> // used for rand(), srand(), and general-purpose C functions
#include <ctime> // used for time(), typically to seed srand()

using namespace std;

// Global variables provided for you
// How do we know these are global variables?
    // They are declared outside any function, at file scope, so every function in this file can use them.
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
        // It tells the function how big the 'lines' array is so we don't write past its bounds.

    ifstream fin(filename);
    if (!fin) {
        // Could not open file
        cout << "Error: could not open " << filename << endl;
        return 0;
    }

    int count = 0;
    string line;
    // Read until EOF or until we've filled the array
    while (count < linesSize && getline(fin, line)) {
        lines[count] = line;
        count++;
    }

    fin.close();
    return count;
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

    if (nLines <= 0) { // Caution: avoid running a do-while when there's nothing to process
        file_out.close();
        return;
    }

    int i = 0;
    do {
        string currentLine = lines[i];
        // find first comma
        size_t commaPos = currentLine.find(',');
        string name;
        if (commaPos != string::npos) { // npos means no position or not found. so if the comma is found here due to !
            name = currentLine.substr(0, commaPos); // everything before the comma
        } else {
            name = currentLine; // if no comma found, use the whole line
        }
        // Write the name to the file
        file_out << name << endl;
        i++;
    } while (i < nLines);

    file_out.close();
}


// Fill a 2D array with random decimal numbers (one decimal place)
// row and col are defined, so we don't have to worry about the companion variable
// init is commonly seen in coding and stands for initialize
void init2DArray(double arr[row][col]) { 
    // HINTS:
    // 1. Use a nested for loop
    // 2. Stop at row and col
    // 3. How did we use random number to have one decimal place? Something with modulus and division
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            // random number with one decimal place, e.g., 0.0 - 9.9
            arr[r][c] = (rand() % 100) / 10.0;
        }
    }
}


// Print the 2D array using nested loops
void print2DArray(double arr[row][col]) {
    // HINTS
    // 1. use a nested for loop
    // 2. Extremely similar to init2DArray but much simpler
    // 3. Use cout and endl!
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}


// Copy the original array into a larger one
// With a larger capacity, we can insert a new random number in the middle
// We want to keep the organization so we shift all of the elements
void copyAndInsert(double oldArr[row][col], double newArr[new_row][new_col], double newValue) {
    // find the middle index of the old array (Provided):
    int totalOldSize = row * col;
    int insertIndex = totalOldSize / 2;

    // current index of the oldArr
    // which element of the old array we should copy next
    int oldIndex = 0; 

    for (int r = 0; r < new_row; r++) {
        for (int c = 0; c < new_col; c++) {
            int flatIndex = r * new_col + c;

            if (flatIndex == insertIndex) {
                // place the new value in the middle
                newArr[r][c] = newValue;
            } else {
                if (oldIndex < totalOldSize) {
                    // map flat index back to 2D indices for old array
                    int oldR = oldIndex / col;
                    int oldC = oldIndex % col;
                    newArr[r][c] = oldArr[oldR][oldC];
                    oldIndex++;
                } else {
                    // if we run out of old elements,
                    // fill with 0.0
                    newArr[r][c] = 0.0;
                }
            }
        }
    }
}

int main() {
    // What does this line do?
    // --> Seeds the pseudo-random number generator with the current time.
    //     This makes rand() produce different sequences each run.
    // Does it only need to be declared once?
    // --> Yes, call srand once near program start (calling multiple times can reduce randomness).
    srand(time(0));

    const int linesSize = 10;
    string lines[linesSize];

    // Read File
    // What will the readInputFile return and assign to 'n'?
    // --> It returns the number of lines read from input.txt and assigns that to n.
    int n = readInputFile("input.txt", lines, linesSize);

    // Classic input validation
    // What am I validating here?
        // We're checking that at least one line was read before processing names.
    if (n > 0){
        processAndWriteNames(lines, n, "output.txt");
    } 
    else {
        cout << "No lines found" << endl;
    }

    double arr[row][col];
    init2DArray(arr); // Initialize the 2D array

    // Print the original array
    cout << "\nOriginal array (" << row << "x" << col << "):\n";
    print2DArray(arr);

    // Copy the original to a bigger array
    // Insert a new random value
    double newArr[new_row][new_col];
    double newValue = (rand() % 100) / 10.0;
    copyAndInsert(arr, newArr, newValue);

    // Print each element of the newArr
    cout << "\nNew " << new_row << "x" << new_col << " Array (inserted " << newValue << "):\n";

    for (int i = 0; i < new_row; i++) {
        for (int j = 0; j < new_col; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
