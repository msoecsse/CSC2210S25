#include <iostream>
#include "BookStore.h"
#include "MusicStore.h"  // Now inherits from BookStore and StoreUtilities

int main() {
    // Create a BookStore object
    BookStore myBook;
    std::cout << "### BookStore Object ###" << std::endl;
    myBook.inputData();
    myBook.displayData();

    std::cout << std::endl;

    // Create a MusicStore object
    MusicStore myMusic;
    std::cout << "### MusicStore Object ###" << std::endl;
    myMusic.inputMusicData();
    myMusic.displayMusicData();

    // Now call the StoreUtilities method (printReceipt)
    std::cout << std::endl;
    myMusic.printReceipt(); // inherited from StoreUtilities

    return 0;
}
