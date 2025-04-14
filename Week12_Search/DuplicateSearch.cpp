#include <vector>
#include <iostream>

using namespace std;
template <typename Container, typename T>
vector<size_t> linearSearchWithDuplicates(const Container& container, const T& target) {
    vector<size_t> indices;
    size_t index = 0;
    for (const auto& element : container) {
        if (element == target) {
            indices.push_back(index);
        }
        ++index;
    }
    return indices;
}
// Binary search with duplicates
template <typename Container, typename T>
vector<size_t> binarySearchWithDuplicates(const Container& container, const T& target) {
    vector<size_t> indices;
    auto low = container.begin();
    auto high = container.end();

    while (low < high) {
        auto mid = low + (distance(low, high) / 2);
        if (*mid == target) {
            // Found the target, now find all duplicates
            auto left = mid;
            auto right = mid;

            // Move left
            while (left != container.begin() && *(--left) == target) {
                indices.push_back(distance(container.begin(), left));
            }
            // Move right
            while (++right != container.end() && *right == target) {
                indices.push_back(distance(container.begin(), right));
            }
            break; // Exit the loop after finding all duplicates
        } else if (*mid < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return indices;
}




int main() {
    vector<int> numbers = {3, 5, 7, 5, 9, 5, 2};
    int target = 5;

  vector<size_t> foundIndices = linearSearchWithDuplicates(numbers, target);

    if (!foundIndices.empty()) {
      cout << "Found " << target << " at indices: ";
        for (size_t index : foundIndices) {
            cout << index << " ";
        }
        cout << std::endl;
    } else {
        cout << target << " not found in the container." << std::endl;
    }
    // Test with binary search
    vector<int> sortedNumbers = {1, 2, 3, 4, 5, 5, 5, 6, 7};
    int targetBinary = 5;
    vector<size_t> foundIndicesBinary = binarySearchWithDuplicates(sortedNumbers, targetBinary);
    if (!foundIndicesBinary.empty()) {
        cout << "Found " << targetBinary << " at indices: ";
        for (size_t index : foundIndicesBinary) {
            cout << index << " ";
        }
        cout << std::endl;
    } else {
        cout << targetBinary << " not found in the container." << std::endl;
    }

    return 0;
}
