#include <iostream>
using namespace std;

int fib(int n){
    cout << n << endl;
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
    cout << "The fourth fibonacci number is: " << fib(4) << endl;
}
