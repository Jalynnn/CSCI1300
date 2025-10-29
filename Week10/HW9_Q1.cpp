#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

class Library {
    private:
        string _name;
        static const int _MAX_BOOKS = 10;
        int _page_counts[_MAX_BOOKS];
        int _current_books;
    
    public:
        Library();
        Library(string);
        Library(string, int[], int);
        string getName();
        int getCurrentBooks();
        void setName(string);
        int getPageCount(int);
        bool addPageCount(int);
};

// TODO Implement constructors

string Library::getName() {
    return _name;
}

int Library::getCurrentBooks() {
    return _current_books;
}

void Library::setName(string name) {
    _name = name;
}

int Library::getPageCount(int index) {
    if (index < 0 || index >= _current_books) {
        return -1;
    }
    return _page_counts[index];
}

bool Library::addPageCount(int pages) {
    if (_current_books == _MAX_BOOKS) {
        return false;
    }
    _page_counts[_current_books] = pages;
    _current_books++;
    return true;
}