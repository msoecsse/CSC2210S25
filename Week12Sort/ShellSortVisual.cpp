#include <iostream>
#include <vector>

// Function to print the array with the current gap
void printArrayWithGap(const std::vector<int>& arr, int gap) {
    std::cout << "Gap = " << gap << ": ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Shell Sort using Insertion Sort logic within subarrays of the given gap
void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }

        // Visualize the current state of the array after this gap
        printArrayWithGap(arr, gap);
    }
}

int main() {
    std::vector<int> data = {23, 12, 1, 8, 34, 54, 2, 3};
    std::vector<int> arr = {10, 20, 15, 45, 36, 48, 7, 60, 18, 50, 2, 19, 43, 30, 55};


    std::cout << "Original array:\n";
    printArrayWithGap(arr, -1);  // -1 to indicate initial array

    std::cout << "\nShell Sort Progress:\n";
    shellSort(arr);

    std::cout << "\nSorted array:\n";
    printArrayWithGap(arr, 0);  // 0 to indicate final sorted array

    return 0;
}
