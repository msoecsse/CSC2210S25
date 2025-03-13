#include <iostream>
#include <set>
#include <map>
#include <string>

int main()
{
    // -------------------- Demonstrating std::set --------------------
    std::set<int> mySet;

    // Insert elements (duplicates are automatically ignored)
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(7);
    mySet.insert(1); // Duplicate, won't be inserted

    std::cout << "Contents of mySet: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n";  // Expected output: 1 3 7

    // Search for an element
    int searchValue = 3;
    auto it = mySet.find(searchValue);
    if (it != mySet.end()) {
        std::cout << "Element " << searchValue << " found in mySet.\n";
    } else {
        std::cout << "Element " << searchValue << " not found in mySet.\n";
    }

    // Erase an element
    mySet.erase(3);
    std::cout << "Contents of mySet after erasing 3: ";
    for (int val : mySet) {
        std::cout << val << " ";
    }
    std::cout << "\n\n"; // Expected output: 1 7


    // -------------------- Demonstrating std::map --------------------
    std::map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["Alice"] = 30;
    myMap["Bob"] = 25;
    myMap["Charlie"] = 35;

    // Another way to insert:
    myMap.insert(std::make_pair("Diana", 40));

    // Accessing elements:
    std::cout << "Bob's age is: " << myMap["Bob"] << "\n"; // Access by key

    // Iterating over a map
    std::cout << "\nContents of myMap:\n";
    for (const auto &pair : myMap) {
        std::cout << pair.first << " => " << pair.second << "\n";
    }

    // Search for an element
    std::string searchKey = "Charlie";
    auto itr = myMap.find(searchKey);
    if (itr != myMap.end()) {
        std::cout << "\nFound " << itr->first << " with value " << itr->second << "\n";
    } else {
        std::cout << "\nKey " << searchKey << " not found\n";
    }

    // Erase an element
    myMap.erase("Diana");

    std::cout << "\nContents of myMap after erasing 'Diana':\n";
    for (const auto &pair : myMap) {
        std::cout << pair.first << " => " << pair.second << "\n";
    }

    return 0;
}
