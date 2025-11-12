#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;

    int prev1 = 0; // f(0)
    int prev2 = 1; // f(1)
    int current = 0;

    for (int i = 2; i <= n; i++) {
        // This should look familiar!
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
}

int main() {
    cout << "The eighth Fibonacci number is: " << fib(8) << endl;
}
