#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

class library {
private:
    book* books;
    int counter;
    int capacity;
    void resize();

public:
    library(int capacity);
    ~library();

    void addbook();
    void deletebook();
    int search_by_id(int id);
    void display_all_books();
    void save_to_file(const string& filename) ;
    void load_from_file(const string& filename);
    void updatebook(int id);
    void displayBookById(int id);
};

#endif

