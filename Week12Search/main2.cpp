#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>  // for sort
using namespace std;

template <typename Container, typename T>
int binarySearchIndex(const Container& container, const T& target) {
    auto low = container.begin();
    auto high = container.end();

    while (low < high) {
        auto mid = low + (distance(low, high) / 2);
        if (*mid == target) {
            return static_cast<int>(distance(container.begin(), mid));
        } else if (*mid < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return -1;  // not found
}
// recursive version
// in this version we are using the same function name
// but with different parameters
//
template <typename Container, typename T>
int binarySearchIndexRecursive(const Container& container, const T& target, int low, int high) {
    if (low >= high) {
        return -1;  // not found
    }
    auto mid = low + (high - low) / 2;
    if (container[mid] == target) {
        return mid;
    } else if (container[mid] < target) {
        return binarySearchIndexRecursive(container, target, mid + 1, high);
    } else {
        return binarySearchIndexRecursive(container, target, low, mid);
    }
}


int main() {
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70};
  sort(nums.begin(), nums.end());  // ensure sorted

    int index = binarySearchIndex(nums, 40);
    if (index != -1) {
        cout << "Found 40 at index " << index << std::endl;
    } else {
        std::cout << "40 not found." << std::endl;
    }

    std::string letters = "abcdefg";
    int charIndex = binarySearchIndex(letters, 'e');
    if (charIndex != -1) {
        cout << "Found 'e' at index " << charIndex << std::endl;
    } else {
      cout << "'e' not found." << std::endl;
    }
    // Test with a vector of doubles
    vector<double> doubles = {1.1, 2.2, 3.3, 4.4, 5.5};
    sort(doubles.begin(), doubles.end());  // ensure sorted
    double targetDouble = 3.3;
    int doubleIndex = binarySearchIndexRecursive(doubles, targetDouble, 0, doubles.size());
    if (doubleIndex != -1) {
        cout << "Found " << targetDouble << " at index " << doubleIndex << std::endl;
    } else {
        cout << targetDouble << " not found." << std::endl;
    }

    return 0;
}
