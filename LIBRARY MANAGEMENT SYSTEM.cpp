#include<bits/stdc++.h>
using namespace std;

// ----------------------
// Class Definition
// ----------------------
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    // Constructor
    Book(int _id = 0, string _title = "", string _author = "", bool _isIssued = false)
        : id(_id), title(_title), author(_author), isIssued(_isIssued) {}

    // Display Book Details
    void display() const {
        cout << "ID: " << id
            << " | Title: " << title
            << " | Author: " << author
            << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

// ----------------------
// Global Variables
// ----------------------
vector<Book> library;

// ----------------------
// Function Prototypes
// ----------------------
void loadFromFile();
void saveToFile();
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void removeBook();

// ----------------------
// Main Function
// ----------------------
int main() {
    int choice;
    loadFromFile();

    cout << "=====================================\n";
    cout << "      LIBRARY MANAGEMENT SYSTEM      \n";
    cout << "=====================================\n";

    do {
        cout << "\n1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Remove Book\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: removeBook(); break;
            case 0: saveToFile(); cout << "Exiting... Data saved!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// ----------------------
// Function Definitions
// ----------------------

// Load books from file
void loadFromFile() {
    ifstream file("library.txt");
    if (!file) return;

    library.clear();
    int id;
    string title, author;
    bool issued;

    while (file >> id) {
        file.ignore();
        getline(file, title);
        getline(file, author);
        file >> issued;
        file.ignore();
        library.push_back(Book(id, title, author, issued));
    }
    file.close();
}

// Save books to file
void saveToFile() {
    ofstream file("library.txt");
    for (auto &b : library) {
        file << b.id << "\n" << b.title << "\n" << b.author << "\n" << b.isIssued << "\n";
    }
    file.close();
}

// Add a new book
void addBook() {
    int id;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);

    // Check if ID already exists
    for (auto &b : library) {
        if (b.id == id) {
            cout << "A book with this ID already exists!\n";
            return;
        }
    }

    library.push_back(Book(id, title, author, false));
    saveToFile();
    cout << " Book added successfully!\n";
}

// Display all books
void displayBooks() {
    if (library.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    cout << "\n----- Library Books -----\n";
    for (auto &b : library)
        b.display();
}

// Search for a book by ID or Title
void searchBook() {
    int choice;
    cout << "Search by: 1. ID  2. Title\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    bool found = false;

    if (choice == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
        for (auto &b : library) {
            if (b.id == id) {
                b.display();
                found = true;
                break;
            }
        }
    } else if (choice == 2) {
        string title;
        cout << "Enter Book Title: ";
        getline(cin, title);
        for (auto &b : library) {
            if (b.title == title) {
                b.display();
                found = true;
            }
        }
    }

    if (!found) cout << "Book not found!\n";
}

// Issue a book
void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (auto &b : library) {
        if (b.id == id) {
            if (b.isIssued) {
                cout << " Book already issued!\n";
            } else {
                b.isIssued = true;
                saveToFile();
                cout << " Book issued successfully!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

// Return a book
void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (auto &b : library) {
        if (b.id == id) {
            if (!b.isIssued) {
                cout << " This book was not issued!\n";
            } else {
                b.isIssued = false;
                saveToFile();
                cout << " Book returned successfully!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

// Remove a book
void removeBook() {
    int id;
    cout << "Enter Book ID to remove: ";
    cin >> id;

    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == id) {
            library.erase(it);
            saveToFile();
            cout << " Book removed successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}
