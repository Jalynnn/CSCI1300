#include<iostream>
using namespace std;


// Option 1
// Write a recursive function shrinkToFive(int n)
// Keep dividing n by 2
// Until the value reaches 5 or below
string shrinkToFive(int n) {
    if(n <= 5) {
        return "Base case reached";
    }
    else {
        return shrinkToFive(n / 2);
    }
}

// Option 2
// Write a recursive function growUntilHundred(int n)
// Keep multiplying by 2
// Until the number becomes 100 or greater
int growUntilHundred(int n) {
    if (n >= 100) {
        return n;
    }
    return growUntilHundred(n * 2);
}

// Option 3 -- Textbook 5.10 Ex. 5
// Complete this recursive function
// Print n '[]' in a row
// Example: n = 5; [] [] [] [] []
void print_boxes(int n) {
    cout << "[] ";
    if (n == 0) {
        return;
    }
    print_boxes(n-1);
}

// Option 4 -- Textbook 5.10 Ex. 3
// Complete this recursive function
// When given a string, yields a string with every second char removed
// Example: Hello --> Hlo
string every_second(string s) {
    // Hint: What is the result when the length is 0 or 1? 
    if (s.length() <= 1) {
        return s;
    }
    else {
        // Hint: s.substr(k) returns "" when k = s.length()
        string simpler = every_second(s.substr(2));
        return s[0] + simpler;
    }
}

int main() {
    // Option 1
    cout << "Enter a number for shrinkToFive: ";
    int n1;
    cin >> n1;
    cout << "Result: " << shrinkToFive(n1) << endl << endl;

    // Option 2
    cout << "Enter a number for growUntilHundred: ";
    int n2;
    cin >> n2;
    cout << "Result: " << growUntilHundred(n2) << endl << endl;

    // Option 3
    cout << "Enter how many boxes to print: ";
    int n3;
    cin >> n3;
    cout << "Result: ";
    print_boxes(n3);
    cout << endl << endl;

    // Option 4
    cout << "Enter a string for every_second: ";
    string input;
    cin >> input;
    cout << "Result: " << every_second(input) << endl;

    return 0;
}