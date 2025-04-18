#include <iostream>
#include <vector>
#include <algorithm>  // for sort
#include <iomanip>    // for setw
#include <string>

// Function to display the array and highlight the current index
void displayArray(const std::vector<int>& arr, int currentIndex = -1, int low = -1, int mid = -1, int high = -1, std::string label = "") {
    std::cout << label << " Array: [ ";
    for (size_t i = 0; i < arr.size(); ++i) {
        if ((int)i == currentIndex || (int)i == mid) {
            std::cout << "(" << arr[i] << ") ";
        } else {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "]" << std::endl;

    // Visual indicator of positions
    if (low != -1 || mid != -1 || high != -1) {
        std::cout << "           ";
        for (size_t i = 0; i < arr.size(); ++i) {
            if ((int)i == low) std::cout << " L ";
            else if ((int)i == mid) std::cout << " M ";
            else if ((int)i == high) std::cout << " H ";
            else std::cout << "   ";
        }
        std::cout << std::endl;
    }
}

// Linear search with step-by-step visualization
int linearSearch(const std::vector<int>& arr, int target) {
    std::cout << "\n Starting Linear Search...\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        displayArray(arr, i, -1, -1, -1, "Step " + std::to_string(i + 1));
        if (arr[i] == target) {
            std::cout << " Found " << target << " at index " << i << "!\n";
            return i;
        }
    }
    std::cout << " " << target << " not found in the array.\n";
    return -1;
}

// Binary search with step-by-step visualization
int binarySearch(const std::vector<int>& arr, int target) {
    std::cout << "\n Starting Binary Search...\n";
    int low = 0, high = arr.size();

    int step = 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        displayArray(arr, -1, low, mid, high - 1, "Step " + std::to_string(step));
        ++step;

        if (arr[mid] == target) {
            std::cout << " Found " << target << " at index " << mid << "!\n";
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    std::cout << " " << target << " not found in the array.\n";
    return -1;
}

int main() {
    std::vector<int> arr = {50, 10, 20, 30, 70, 40, 60};

    std::cout << "Initial array (unsorted for linear search):\n";
    displayArray(arr);

    int target;
    std::cout << "\nEnter the number to search for: ";
    std::cin >> target;

    // Linear Search
    linearSearch(arr, target);

    // Binary Search (requires sorted array)
    std::sort(arr.begin(), arr.end());
    std::cout << "\nArray sorted for binary search:\n";
    displayArray(arr);
    binarySearch(arr, target);

    return 0;
}
