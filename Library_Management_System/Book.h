#pragma once

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isBorrowed;

public:
    void setBookDetails(int, string, string, bool);
    void display();
    void BorrowBookFromBook();
    void BookFromBorrowBook();
    bool isAvailable();
    int getID();
    string getSaveFormat();
};