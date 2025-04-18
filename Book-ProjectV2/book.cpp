
#include "Book.h"


book::book() : id(0), author(" "), title(" "), year(0), available(true), price(0) {}


book::book(int id) : id(id), author(" "), title(" "), year(0), available(true), price(0) {}


book::book(int id, string author, string title, int year, bool available, double price)
    : id(id), author(author), title(title), year(year), available(available), price(price) {}


book::book(const book &b) : id(b.id), author(b.author), title(b.title), year(b.year),
   available(b.available), price(b.price) {}


book::~book() {
    cout << "book object with id " << id << " is add" << endl;
}


int book::getid() { return id; }
void book::setid(int id) { this->id = id; }
string book::getauthor() { return author; }
void book::setauthor(string author) { this->author = author; }
string book::gettitle() { return title; }
void book::settitle(string title) { this->title = title; }
int book::getyear() { return year; }
void book::setyear(int year) { this->year = year; }
bool book::getavailable() { return available; }
void book::setavailable(bool available) { this->available = available; }
double book::getprice() { return price; }
void book::setprice(double price) { this->price = price; }


void book::display() {
    cout << " id: " << id
         << " author: " << author
         << " title: " << title
         << " year: " << year
         << " available: " << (available ? "yes" : "no")
         << " price: " << price
         << endl;
}
