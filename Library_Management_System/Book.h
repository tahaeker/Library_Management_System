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
    Book() = default;
    void setBookDetails(int id, const string& title, const string& author, bool status);
    string display() const;         
    bool borrowBook();              
    bool returnBook();              
    bool isAvailable() const;
    int getID() const;
    string getSaveFormat() const;
};
