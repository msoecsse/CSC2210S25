#ifndef MUSICSTORE_H
#define MUSICSTORE_H

#include "BookStore.h"
#include "StoreUtilities.h"
#include <string>

// MusicStore class inherits from BookStore and StoreUtilities
class MusicStore : public BookStore, public StoreUtilities {
private:
    std::string artist;
    std::string format; // e.g., CD, Vinyl, Digital

public:
    // Default constructor
    MusicStore()
      : BookStore(), // initialize base class BookStore
        artist("Unknown"),
        format("Unknown")
    {}

    // Parameterized constructor
    MusicStore(const std::string &t, const std::string &a, double p,
               const std::string &art, const std::string &f)
      : BookStore(t, a, p), // call BookStore constructor
        artist(art),
        format(f)
    {}

    // Method to input music data
    void inputMusicData() {
        std::cout << "----- Enter Music Details -----\n";
        std::cout << "Enter Title (Album / Track name): ";
        std::getline(std::cin, title);   // 'title' is inherited from BookStore
        std::cout << "Enter Artist: ";
        std::getline(std::cin, artist);
        std::cout << "Enter Format (CD, Vinyl, Digital): ";
        std::getline(std::cin, format);
        std::cout << "Enter Price: ";
        std::cin >> price;               // 'price' is inherited from BookStore
        std::cin.ignore(); // clear newline
    }

    // Method to display music data
    void displayMusicData() const {
        std::cout << "----- Music Details -----\n";
        std::cout << "Title (Album / Track): " << title << "\n";   // from BookStore
        std::cout << "Artist:               " << artist << "\n";
        std::cout << "Format:               " << format << "\n";
        std::cout << "Price:                $" << price << "\n";
    }
};

#endif
