#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
public:
    int bookID;
    string title;
    string author;
    string status;

    Book(int id, string t, string a) : bookID(id), title(t), author(a), status("Available") {}

    void display() const {
        cout << "BookID: " << bookID
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: " << status << endl;
    }
};

// Member Class
class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) : memberID(id), name(n) {}

    void display() const {
        cout << "MemberID: " << memberID
             << ", Name: " << name << endl;
    }
};

// Library Management System Class
class LibraryManagementSystem {
    vector<Book> books;
    vector<Member> members;

public:
    // Add a new book
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // View all books
    void viewBooks() const {
        if (books.empty()) {
            cout << "No books available.\n";
        } else {
            for (const auto &book : books) {
                book.display();
            }
        }
    }

    // Add a new member
    void addMember() {
        int id;
        string name;
        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    // View all members
    void viewMembers() const {
        if (members.empty()) {
            cout << "No members registered.\n";
        } else {
            for (const auto &member : members) {
                member.display();
            }
        }
    }

    // Borrow a book
    void borrowBook() {
        int bookID;
        cout << "Enter Book ID to borrow: ";
        cin >> bookID;

        for (auto &book : books) {
            if (book.bookID == bookID) {
                if (book.status == "Available") {
                    book.status = "Borrowed";
                    cout << "Book borrowed successfully!\n";
                    return;
                } else {
                    cout << "Book is already borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    // Return a book
    void returnBook() {
        int bookID;
        cout << "Enter Book ID to return: ";
        cin >> bookID;

        for (auto &book : books) {
            if (book.bookID == bookID) {
                if (book.status == "Borrowed") {
                    book.status = "Available";
                    cout << "Book returned successfully!\n";
                    return;
                } else {
                    cout << "Book is not currently borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    // Main menu
    void menu() {
        int choice;
        do {
            cout << "\nLibrary Management System:\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Add Member\n";
            cout << "4. View Members\n";
            cout << "5. Borrow Book\n";
            cout << "6. Return Book\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    viewBooks();
                    break;
                case 3:
                    addMember();
                    break;
                case 4:
                    viewMembers();
                    break;
                case 5:
                    borrowBook();
                    break;
                case 6:
                    returnBook();
                    break;
                case 7:
                    cout << "Exiting system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 7);
    }
};

// Main Function
int main() {
    LibraryManagementSystem lms;
    lms.menu();
    return 0;
}
