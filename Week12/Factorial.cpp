#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 1){
        return 1; //base case
    }
    else {
        return n*factorial(n-1); //recursive step
    }
}

int main(){
    cout << "4! = " << factorial(4) << endl;
}
