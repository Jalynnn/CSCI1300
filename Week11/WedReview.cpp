#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

void saveAndLoad() {
    Student s1; 
    // TODO 1: Ask the user for the student's name and score (use cin) to initialize struct members

    // TODO 2: Open an ofstream to "student.txt"
    // TODO 3: Write the name and score to the file
    // TODO 4: Close the output file

    // TODO 5: Open an ifstream to read from "student.txt"
    // TODO 6: Read the data back into a new Student object and print it
}

int main() {
    saveAndLoad();
    return 0;
}




