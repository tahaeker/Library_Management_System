#pragma once

#include "Book.h"
#include <string>
#include <vector>

using namespace std;

class Library {
private:
    Book bookCatalog[50];
    int bookCount;
    string bookFileName;

public:
    Library(const string& filename);
    bool loadBooksFromFile();
    bool saveBooksToFile();
    vector<string> listAllBooks() const;   // kitap listesi döner
    string borrowBook(int bookID);         // iþlem sonucu
    string returnBook(int bookID);
};
