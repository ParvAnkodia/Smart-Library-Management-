#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
    }

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
};

void addBook() {
    ofstream file("library.txt", ios::app);
    Book b;
    b.input();
    file.write((char*)&b, sizeof(b));
    file.close();
    cout << "Book Added Successfully!\n";
}

void displayBooks() {
    ifstream file("library.txt");
    Book b;
    while (file.read((char*)&b, sizeof(b))) {
        b.display();
    }
    file.close();
}

void searchBook(int bookID) {
    ifstream file("library.txt");
    Book b;
    bool found = false;
    while (file.read((char*)&b, sizeof(b))) {
        if (b.id == bookID) {
            cout << "Book Found!\n";
            b.display();
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Book Not Found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Smart Library Management System ---\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: {
                int bookID;
                cout << "Enter Book ID to Search: ";
                cin >> bookID;
                searchBook(bookID);
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
