/* This example was provided by the following link: 
https://www.youtube.com/watch?v=ObUUe9ujYoY */

#include <iostream>

using namespace std;

// Define stuct 
struct student {
    string name;
    double gpa;
    bool enrolled; // True or False
};

int main() {
    // Struct: "A structure that group related variables under one name"
        // "Structs can contain many different data types"
        // "Variables in a struct are known as "members""
        // Members are accessed using dot notation

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    cout << student1.name << endl;
    cout << student1.gpa << endl;
    cout << student1.enrolled << endl;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;

    cout << student2.name << endl;
    cout << student2.gpa << endl;
    cout << student2.enrolled << endl;

    student student3;
    student3.name = "Squidward";
    student3.gpa = 1.5;
    student3.enrolled = false;

    cout << student3.name << endl;
    cout << student3.gpa << endl;
    cout << student3.enrolled << endl;


    return 0;
}