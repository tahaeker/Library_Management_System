#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "Library.h"
#include <windows.h>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initConsole() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void enableUTF8Console() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
void slowPrint(const string& text, int delay = 10) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}


void printBanner() {
    cout << "\033[1;36m";
    cout << "=============================================\n";
    cout << "        📚  LIBRARY MANAGEMENT         \n";
    cout << "=============================================\n";
    cout << "\033[0m";
}

// Bekleme animasyonu
void loading(const string& msg) {
    cout << msg;
    for (int i = 0; i < 3; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << endl;
}


int main() {

    initConsole();
    enableUTF8Console();

    Library myLibrary("books.txt");
    int choice;
    bool running = true;

    while (running) {
        clearScreen();
        printBanner();
        cout << "\033[1;33mWelcome to your personal book system.\033[0m\n\n";
        cout << "1️⃣  List All Books\n";
        cout << "2️⃣  Borrow a Book\n";
        cout << "3️⃣  Return a Book\n";
        cout << "4️⃣  Save & Exit\n";
        cout << "\nSelect an option: ";

        cin >> choice;
        clearScreen();

        switch (choice) {
        case 1: {
            printBanner();
            cout << "\033[1;32mList of Books:\033[0m\n\n";
            auto books = myLibrary.listAllBooks();
            for (auto& b : books)
                cout << " - " << b << endl;
            cout << "\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }

        case 2: {
            printBanner();
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            loading("Processing");
            cout << "\033[1;34m" << myLibrary.borrowBook(id) << "\033[0m\n";
            cout << "\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }

        case 3: {
            printBanner();
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            loading("Processing");
            cout << "\033[1;34m" << myLibrary.returnBook(id) << "\033[0m\n";
            cout << "\nPress ENTER to continue...";
            cin.ignore();
            cin.get();
            break;
        }

        case 4: {
            printBanner();
            loading("Saving changes");
            if (myLibrary.saveBooksToFile())
                cout << "\033[1;32mAll changes saved successfully. Goodbye!\033[0m\n";
            else
                cout << "\033[1;31mError: Could not save the file!\033[0m\n";
            running = false;
            break;
        }

        default:
            cout << "\033[1;31mInvalid choice! Try again.\033[0m\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
    return 0;
}
