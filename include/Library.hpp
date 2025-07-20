#pragma once

#include <vector>
#include "Book.hpp"
#include<string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void displayAllBooks() const;
    void searchBookByTitle(const std::string& title) const;
    void borrowBook(const std::string& title);
    void returnBook(const std::string& title);
};

