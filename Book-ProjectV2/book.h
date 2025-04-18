#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class book {
private:
    int id;
    string author;
    string title;
    int year;
    bool available;
    double price;

public:

    book();


    book(int id);


    book(int id, string author, string title, int year, bool available, double price);


    book(const book &b);

    ~book();

    int getid();
    void setid(int id);
    string getauthor();
    void setauthor(string author);
    string gettitle();
    void settitle(string title);
    int getyear();
    void setyear(int year);
    bool getavailable();
    void setavailable(bool available);
    double getprice();
    void setprice(double price);

    void display();
};

#endif

