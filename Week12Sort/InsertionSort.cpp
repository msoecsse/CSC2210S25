//
// Created by bhattacharya on 4/15/2025.
//

// Insertion Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template <typename Container>
void insertionSort(Container& container) {
    // Iterate through the container starting from the second element
    // because the first element is trivially sorted
    // The iterator 'it' points to the current element being inserted
    for (auto it = next(container.begin()); it != container.end(); ++it) {
        auto key = *it; // The element to be inserted
        auto jt = it; // The iterator to find the correct position for 'key'

        // Shift elements of the sorted part of the container
        // that are greater than 'key' to one position ahead
        while (jt != container.begin() && key < *std::prev(jt)) {
            *jt = *std::prev(jt);
            --jt;
        }
        *jt = key;
    }
}
// recursive function to perform insertion sort
 template <typename Container>
 void insertionSortRecursive(Container& container, typename Container::iterator it) {
    if (it == container.end()) return;  // Base case: if the iterator reaches the end, return
    auto key = *it; // The element to be inserted
    auto jt = it; // The iterator to find the correct position for 'key'
    // Shift elements of the sorted part of the container
    // that are greater than 'key' to one position ahead
    // As long as key is less than elements before it, shift them right.
    while (jt != container.begin() && key < *std::prev(jt)) {
        *jt = *std::prev(jt); // std::prev(jt) gives the previous element.
        --jt;
    }
    *jt = key; // Once the correct position is found, insert the key.
    insertionSortRecursive(container, ++it); // Move the iterator forward to the next element and recurse.
    //Recursive call for the next element
}



// Function to print the contents of a container
template <typename T>
void printContainer(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {64, 25, 12, 22, 11};

    cout << "Original : ";
    printContainer(vec);
    insertionSort(vec);
    cout << "Sorted: ";
    printContainer(vec);

    return 0;
}