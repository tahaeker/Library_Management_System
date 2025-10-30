
#include <iostream>
#include Book.h
using namespace std;

class Book {
	int id;
	string title;
	string author;
	bool isBorrowed;

public:
	void setBookDetails();
	void displayBookDetails();
	bool borrowBook();
	bool returnBook();
	bool isAvailable();
	int getId();
	string getSaveFormat();

};

class Library {



};

int main()
{



}

