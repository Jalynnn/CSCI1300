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

// the default constructor
Library::Library() {
    _name = "";
    _current_books = 0;
    for (int i = 0; i < _MAX_BOOKS; i++) {
        _page_counts[i] = 0;
    }
}

//parameterized constructor
Library::Library(string name) {
    _name = name;
    _current_books = 0;
    for (int i = 0; i < _MAX_BOOKS; i++) {
        _page_counts[i] = 0;
    }
}

//parameterized constructor with name, page_counts array, and size
Library::Library(string name, int page_counts[], int arr_size) {
    _name = name;
    _current_books = (arr_size > _MAX_BOOKS) ? _MAX_BOOKS : arr_size;
    for (int i = 0; i < _current_books; i++) {
        _page_counts[i] = page_counts[i];
    }
    // Fill remaining slots with 0 if array size is smaller than _MAX_BOOKS
    for (int i = _current_books; i < _MAX_BOOKS; i++) {
        _page_counts[i] = 0;
    }
}


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
    if (_current_books == _MAX_BOOKS || pages <= 0) {
        return false;
    }
    _page_counts[_current_books] = pages;
    _current_books++;
    return true;
}