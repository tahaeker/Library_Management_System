#include "Book.h"  
#include <iostream>

void Book::setBookDetails(int i, string t, string a, bool s) {
	id = i;
	title = t;
	author = a;
	isBorrowed = s;
}

void Book::display() {
	cout << "Book ID: " << id << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
}

void Book::BorrowBookFromBook() {
	isBorrowed = true;
}

void Book::BookFromBorrowBook () {
	isBorrowed = false;
}

bool Book::isAvailable() {
	return !isBorrowed;
}

int Book::getId() {
	return id;
}	