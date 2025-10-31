#include "Library.h"
#include <fstream>
#include <sstream>

Library::Library(const string& filename) {
    bookFileName = filename;
    bookCount = 0;
    loadBooksFromFile();
}

bool Library::loadBooksFromFile() {
    ifstream file(bookFileName);
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, title, author, statusStr;
        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, statusStr, ',');

        int id = stoi(idStr);
        bool status = (statusStr == "1");

        bookCatalog[bookCount++].setBookDetails(id, title, author, status);
    }
    file.close();
    return true;
}

bool Library::saveBooksToFile() {
    ofstream file(bookFileName);
    if (!file.is_open()) return false;

    for (int i = 0; i < bookCount; ++i)
        file << bookCatalog[i].getSaveFormat() << endl;

    file.close();
    return true;
}

vector<string> Library::listAllBooks() const {
    vector<string> output;
    for (int i = 0; i < bookCount; ++i)
        output.push_back(bookCatalog[i].display());
    return output;
}

string Library::borrowBook(int bookID) {
    for (int i = 0; i < bookCount; ++i) {
        if (bookCatalog[i].getID() == bookID) {
            if (bookCatalog[i].borrowBook())
                return "Book borrowed successfully.";
            else
                return "Error: Book is already borrowed.";
        }
    }
    return "Error: Book not found.";
}

string Library::returnBook(int bookID) {
    for (int i = 0; i < bookCount; ++i) {
        if (bookCatalog[i].getID() == bookID) {
            if (bookCatalog[i].returnBook())
                return "Book returned successfully.";
            else
                return "Error: Book was not borrowed.";
        }
    }
    return "Error: Book not found.";
}
