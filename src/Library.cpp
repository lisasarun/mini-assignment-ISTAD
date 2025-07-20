#include <iostream>
#include "Library.hpp"

void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book added successfully."<<endl;
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library"<<endl;
        return;
    }
    for (const auto& book : books) {
        book.displayInfo();
        std::cout << "---------------------"<<endl;
    }
}

void Library::searchBookByTitle(const std::string& title) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            book.displayInfo();
            found = true;
            break;
        }
    }
    if (!found) std::cout << "Book not found.\n";
}

void Library::borrowBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            if (book.getAvailability()) {
                book.borrowBook();
                std::cout << "Book borrowed successfully.\n";
            } else {
                std::cout << "Book is currently unavailable.\n";
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::returnBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            book.returnBook();
            std::cout << "Book returned successfully"<<endl;
            return;
        }
    }
    std::cout << "Book not found!"<<endl;
}
