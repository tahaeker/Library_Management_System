#pragma once

#include <string>
#include "Library.h"
#include "Book.h"

using namespace std;


Library::Library(string fileName) {
	bookFileName = fileName;
	bookCount = 0;
	loadBooksFromFile(bookFileName);

}
void Library::loadBooksFromFile(string title) {
	
}


void Library::saveBooksToFile() {
	
}

void Library::saveBooksToFile() {
	
}

void Library::borrowBookFromBook(int bookID) {

}

void Library::returnBookFromBorrowBook(int bookID) {


}


