#include "library.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

library::library(int capacity) : capacity(capacity), counter(0) {
    books = new book[capacity];
}

library::~library() {
    delete[] books;
}

void library::resize() {
    capacity *= 2;
    book* new_books = new book[capacity];
    for (int i = 0; i < counter; i++) {
        new_books[i] = books[i];
    }
    delete[] books;
    books = new_books;
}

void library::addbook() {
    if (counter == capacity) {
        resize();
    }
    int id;
    string author, title;
    int year;
    bool available;
    double price;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Author: ";
    cin >> author;
    cout << "Enter Title: ";
    cin >> title;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Is the book available? (1 for yes, 0 for no): ";
    cin >> available;
    cout << "Enter Price: ";
    cin >> price;


    books[counter] = book(id, author, title, year, available, price);
    counter++;
    cout << "Book added successfully!" << endl;
}

void library::deletebook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    int index = search_by_id(id);
    if (index != -1) {

        for (int i = index; i < counter - 1; i++) {
            books[i] = books[i + 1];
        }
        counter--;
        cout << "Book deleted successfully!" << endl;
    } else {
        cout << "Book not found!" << endl;
    }
}

int library::search_by_id(int id) {
    for (int i = 0; i < counter; i++) {
        if (books[i].getid() == id) {
            return i;
        }
    }
    return -1;
}
void library::displayBookById(int id) {
    int index = search_by_id(id);
    if (index != -1) {
        books[index].display();
    } else {
        cout << "Book not found!" << endl;
    }
}

void library::display_all_books() {
    for (int i = 0; i < counter; i++) {
        books[i].display();
    }
}
void library::save_to_file(const string& filename)  {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "File could not be opened." << endl;
        return;
    }

    for (int i = 0; i < counter; ++i) {
        file << books[i].getid() << "\n"
             << books[i].getauthor() << "\n"
             << books[i].gettitle() << "\n"
             << books[i].getyear() << "\n"
             << books[i].getavailable() << "\n"
             << books[i].getprice() << "\n";
    }
    file.close();
    cout << "Books saved to " << filename << "." << endl;
}

void library::load_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File could not be opened." << endl;
        return;
    }

    counter = 0;
    while (true) {
        if (counter >= capacity) {
            resize();
        }

        int id, year;
        string author, title;
        bool available;
        double price;

        if (!(file >> id >> author >> title >> year >> available >> price)) {
            break;
        }

        books[counter] = book(id, author, title, year, available, price);
        counter++;
    }

    file.close();
    cout << "Books loaded from " << filename << "." << endl;
}
void library::updatebook(int id) {
    int index = search_by_id(id);
    if (index != -1) {
        string author, title;
        int year;
        bool available;
        double price;

        cout << "enter new author: ";
        cin >> author;
        cout << "enter new title: ";
        cin >> title;
        cout << "enter new year: ";
        cin >> year;
        cout << "is available (1 for Yes, 0 for No): ";
        cin >> available;
        cout << "enter new price: ";
        cin >> price;


        books[index].setauthor(author);
        books[index].settitle(title);
        books[index].setyear(year);
        books[index].setavailable(available);
        books[index].setprice(price);

        cout << "book updated successfully." << endl;
    } else {
        cout << "book not found." << endl;
    }
}

