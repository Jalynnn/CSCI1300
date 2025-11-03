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
    // TODO 1
    cout << "Enter name and score: ";
    cin >> s1.name >> s1.score;

    // TODO 2
    ofstream outFile("student.txt");
    // TODO 3
    outFile << s1.name << " " << s1.score << endl;
    // TODO 4
    outFile.close();

    // TODO 5
    ifstream inFile("student.txt");
    Student s2;
    // TODO 6
    inFile >> s2.name >> s2.score;
    cout << "Read from file: " 
         << s2.name << " scored " << s2.score << endl;
    inFile.close();
}

int main() {
    saveAndLoad();
    return 0;
}
