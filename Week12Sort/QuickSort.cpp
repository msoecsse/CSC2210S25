//
// Created by bhattacharya on 4/15/2025.
//

// Quick Sort
// Time Complexity: O(n log n) on average, O(n^2) in the worst case
// Space Complexity: O(log n) for the recursive stack

#include <iostream>
#include <vector>
using namespace std;


// Function to perform swapping of two elements
template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
// Function to perform partitioning of the array
template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than or equal to pivot
            i++; // Increment index of smaller element
            Swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    Swap(arr[i + 1], arr[high]); // Swap arr[i + 1] and arr[high] (or pivot)
    return i + 1; // Return the partitioning index
}
// Function to perform Quick Sort
template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    quickSort(vec, 0, vec.size() - 1);
    cout << "Sorted: ";
    printContainer(vec);


    return 0;
}
