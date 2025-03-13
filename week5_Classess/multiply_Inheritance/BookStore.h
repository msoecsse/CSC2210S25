#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <string>

class BookStore {
protected:
    std::string title;
    std::string author;
    double price;

public:
    // Constructors
    BookStore() : title("Unknown"), author("Unknown"), price(0.0) {}
    BookStore(const std::string &t, const std::string &a, double p)
        : title(t), author(a), price(p) {}

    // Method to input bookstore data
    void inputData() {
        std::cout << "----- Enter Book Details -----\n";
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter Price: ";
        std::cin >> price;
        std::cin.ignore(); // clear the newline left by std::cin
    }

    // Method to display bookstore data
    void displayData() const {
        std::cout << "----- Book Details -----\n";
        std::cout << "Title:  " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Price:  $" << price << "\n";
    }
};

#endif
