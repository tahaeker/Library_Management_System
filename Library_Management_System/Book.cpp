#include "Book.h"

void Book::setBookDetails(int i, const string& t, const string& a, bool s) {
    id = i;
    title = t;
    author = a;
    isBorrowed = s;
}

string Book::display() const {
    return "ID: " + to_string(id) +
        " | Title: " + title +
        " | Author: " + author +
        " [" + (isBorrowed ? "Borrowed" : "Available") + "]";
}

bool Book::borrowBook() {
    if (isBorrowed) return false;
    isBorrowed = true;
    return true;
}

bool Book::returnBook() {
    if (!isBorrowed) return false;
    isBorrowed = false;
    return true;
}

bool Book::isAvailable() const {
    return !isBorrowed;
}

int Book::getID() const {
    return id;
}

string Book::getSaveFormat() const {
    return to_string(id) + "," + title + "," + author + "," + (isBorrowed ? "1" : "0");
}
