#pragma once

#include <string>
#include "Book.h"

using namespace std;

class Library {
private:
	Book bookCatalog[100];
	int bookCount;
	string bookFileName;
public:

	Library(string fileName);
	void loadBooksFromFile();
	void saveBooksToFile();
	void saveBooksToFile();
	void listAllBooks();
	void BorrowBookFromBook(int bookID);
	void returnBookFromBorrowBook(int bookID);


};