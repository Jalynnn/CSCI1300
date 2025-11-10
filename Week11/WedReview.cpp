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
    cout << "Please provide the student's name and score." << endl;
    cin >> s1.name >> s1.score;
    // TODO 2: Open an ofstream to "student.txt"
    ofstream outputFile;
    outputFile.open("student.txt");
    // TODO 3: Write the name and score to the file
    outputFile<<s1.name<<s1.score;
    // TODO 4: Close the output file
    outputFile.close();
    // TODO 5: Open an ifstream to read from "student.txt"
    ifstream inFile("student.txt");
    // TODO 6: Read the data back into a new Student object and print it
    Student s2;
    inFile >> s2.name >> s2.score;
    cout << "Student name: " << s2.name << " " << "Student score: " << s2.score << endl;
    inFIle.close()
}

int main() {
    saveAndLoad();
    return 0;
}




