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
	void loadBooksFromFile(string title);
	void saveBooksToFile();
	void listAllBooks();
	void borrowBookFromBook(int bookID);
	void returnBookFromBorrowBook(int bookID);


};