//
// Created by bhattacharya on 4/17/2025.
//

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
// Function to perform bubble sort
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
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
    bubbleSort(vec);
    cout << "Sorted: ";
    printContainer(vec);
    return 0;
}