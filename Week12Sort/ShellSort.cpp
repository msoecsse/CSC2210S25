#include <iostream>
#include <vector>

// Shell Sort function
template <typename Container>
void shellSort(Container& arr) {
    auto n = arr.size(); // Get the size of the container

    // Start with a large gap, then reduce the gap
    // The gap is halved each time until it becomes 0
    for (auto gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        for (auto i = gap; i < n; ++i) {
            auto temp = arr[i]; // Store the current element
            auto j = i;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            // This is a gapped insertion sort
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; // Shift the element to the right
                j -= gap; // Move to the next element in the gap
            }

            arr[j] = temp;
        }
    }
}
int main() {
    std::vector<int> data = {45, 23, 76, 12, 8, 56, 90, 34, 19};

    std::cout << "Before Shell Sort:\n";
    for (auto num : data) std::cout << num << " ";
    std::cout << "\n";

    shellSort(data);

    std::cout << "After Shell Sort:\n";
    for (auto num : data) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
