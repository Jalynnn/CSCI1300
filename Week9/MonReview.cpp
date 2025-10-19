#include <iostream>

using namespace std;

const int CAPACITY = 10;
const int ROWS = 3;
const int COLS = 4;

// Helper Functions - Print Arrays

void print1D(const int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i + 1 < size) cout << ", ";
    }
    cout << " ]\n";
}

void print2D(const int arr[][COLS], int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        cout << "[ ";
        for (int c = 0; c < cols; ++c) {
            cout << arr[r][c];
            if (c + 1 < cols) cout << ", ";
        }
        cout << " ]\n";
    }
}

// Focus on 1D Arrays

void init1D(int arr[], int size, int start = 1, int step = 1) {
    for (int i = 0; i < size; ++i) arr[i] = start + i * step;
}

bool insertInto1D(int arr[], int &size, int capacity, int index, int value) {
    if (index < 0 || index > size) return false;    // invalid index
    if (size >= capacity) return false;             // no room
    for (int i = size - 1; i >= index; --i) arr[i + 1] = arr[i];
    arr[index] = value;
    ++size;
    return true;
}

void demo1D_insert_example() {
    cout << "=== 1D demo ===\n";
    int a[CAPACITY];
    int size = 5;

    init1D(a, size, 10, 10); // 10,20,30,40,50
    cout << "Initial array (size=" << size << "): ";
    print1D(a, size);

    cout << "Insert 25 at index 2:\n";
    bool ok = insertInto1D(a, size, CAPACITY, 2, 25);
    cout << (ok ? "Insert succeeded. " : "Insert failed. ");
    cout << "Now size=" << size << ", array: ";
    print1D(a, size);

    cout << "Append 99 at end:\n";
    insertInto1D(a, size, CAPACITY, size, 99); // append
    print1D(a, size);

    cout << "Fill remainder to show full-capacity behavior:\n";
    while (size < CAPACITY) insertInto1D(a, size, CAPACITY, size, 0);
    cout << "After filling to capacity (size=" << size << "): ";
    print1D(a, size);
    cout << "Try insertion when full (should fail): ";
    bool fail = insertInto1D(a, size, CAPACITY, 1, 555);
    cout << (fail ? "Unexpected success\n" : "Expected failure (no room)\n");
    print1D(a, size);
}

// Focus on 2D Arrays

void init2D(int arr[][COLS], int rows, int cols, int start = 1) {
    int v = start;
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            arr[r][c] = v++;
}

bool set2D(int arr[][COLS], int rows, int cols, int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
    arr[r][c] = value;
    return true;
}

void demo2D_set_and_print() {
    cout << "\n=== 2D demo ===\n";
    int m[ROWS][COLS];
    init2D(m, ROWS, COLS, 1);
    cout << "Initial 2D array:\n";
    print2D(m, ROWS, COLS);

    cout << "Set cell (1,2) to 99:\n";
    if (set2D(m, ROWS, COLS, 1, 2, 99)) {
        print2D(m, ROWS, COLS);
    } else {
        cout << "Bad indexes for set2D\n";
    }
}

// Main

int main() {
    demo1D_insert_example();
    demo2D_set_and_print();

    cout << "\nDone.\n";
    return 0;
}
