#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;

public:
    // Constructor
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
    }

    // Display book
    void display() {
        cout << "ID: " << id 
             << "  | Title: " << title 
             << "  | Author: " << author << endl;
    }

    int getId() { return id; }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> ws;
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << "\n--- Book List ---\n";
        for (auto &b : books)
            b.display();
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        for (auto &b : books) {
            if (b.getId() == id) {
                cout << "Book Found:\n";
                b.display();
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                cout << "Book Deleted Successfully!\n";
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void countBooks() {
        cout << "Total Books: " << books.size() << endl;
    }
};

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Count Books\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.deleteBook(); break;
            case 5: lib.countBooks(); break;
            case 6: return 0;
            default: cout << "Invalid Choice\n";
        }
    }
}