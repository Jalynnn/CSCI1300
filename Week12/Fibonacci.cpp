#include <iostream>
using namespace std;

int fib(int n){
    // Base Case
    if (n <= 1) {
        return n;
    }

    // Recursive Step
    // TODO
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main(){
    cout << "The eighth fibonacci number is: " << fib(8) << endl;
}
