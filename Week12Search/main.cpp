#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
using namespace std;

template <typename Container, typename T>
// The Container type parameter allows the function to accept any iterable collection
// Using Container as a template parameter makes the function type-agnostic.

auto linearSearch(const Container& container, const T& target) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it == target) {
            return it;  // return iterator to found element
        }
    }
    return container.end();  // not found
}

int main() {
    // Test with vector of integers
    vector<int> numbers = {10, 20, 30, 40, 50};
    int target = 30;

    auto result = linearSearch(numbers, target);
    if (result != numbers.end()) {
        cout << "Found " << target << " at index " // distance is used to get the index
        // distance keyword is used to get the index of the found element
                  << distance(numbers.cbegin(), result) << std::endl;
    } else {
        cout << target << " not found in the container." << std::endl;
    }

    // Test with vector of doubles
    std::vector<double> doubles = {1.1, 2.2, 3.3, 4.4, 5.5};
    double targetDouble = 3.3;
    auto doubleResult = linearSearch(doubles, targetDouble);
    if (doubleResult != doubles.end()) {
        cout << "Found " << targetDouble << " at index "
                  << distance(doubles.cbegin(), doubleResult) << std::endl;
    } else {
        cout << targetDouble << " not found in the container." << std::endl;
    }
    // Test with a string (as a container of chars)
   string str = "Hello, World!";
    char targetChar = 'W';
    auto charResult = linearSearch(str, targetChar);
    if (charResult != str.end()) {
       cout << "Found '" << targetChar << "' at index "
                  << std::distance(str.cbegin(), charResult) << std::endl;
    } else {
       cout << "'" << targetChar << "' not found in the string." << std::endl;
    }

    // Test with a list of strings
   list<std::string> words = {"apple", "banana", "cherry", "date"};
   string targetWord = "cherry";
    auto listResult = linearSearch(words, targetWord);
    if (listResult != words.end()) {
        cout << "Found " << targetWord << " in the list at position "
                  << std::distance(words.cbegin(), listResult) << std::endl;
    } else {
        cout << targetWord << " not found in the list." << std::endl;
    }

    return 0;
}
