#include <iostream>
using namespace std;

int exploreTunnel(int depth) {
    cout << "Exploring depth: " << depth << endl;
    return exploreTunnel(depth + 1);
}

int main() {
    exploreTunnel(1);
    return 0;
}
