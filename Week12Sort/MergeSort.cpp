//
// Created by bhattacharya on 4/15/2025.
//
#include <iostream>
#include <vector>
using namespace std;
// Function to perform merging of two sorted subarrays
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid; // Size of the right subarray

    vector<T> L(n1); // Left subarray
    vector<T> R(n2); // Right subarray

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    // Merge the two subarrays
    while (i < n1 && j < n2) { // While there are elements in both subarrays
        if (L[i] <= R[j]) { // If the current element of L[] is less than or equal to the current element of R[]
            arr[k] = L[i]; // Copy the smaller element to arr[]
            i++;
        } else { // If the current element of R[] is less than the current element of L[]
            arr[k] = R[j]; // Copy the smaller element to arr[]
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i]; // Copy the remaining elements of L[] to arr[]
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j]; // Copy the remaining elements of R[] to arr[]
        j++;
        k++;
    }

    // No need to copy the remaining elements of L[] and R[] because they are already in arr[]
    // The remaining elements are already in their correct position
    // in the original array
}
// Function to perform merge sort
template <typename T>
void mergeSort(vector<T>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    mergeSort(vec, 0, vec.size() - 1);
    cout << "Sorted: ";
    printContainer(vec);

    return 0;
}
