#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Adding elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Accessing by index
    std::cout << "First element: " << numbers[0] << "\n";

    // Iterate with range-based for
// Range-based for loop
// The range-based for loop is a for loop that iterates through each element in a vector
// or container.
// A range-based for loop is also known as a for each loop.
// The range-based loop declares a new variable that will be assigned
// with each successive element of a container,
//
    for (int num : numbers) { // new int variable num
        std::cout << num << " "; // for each num in numbers
    }
    std::cout << "\n";

    // Removing the last element
    numbers.pop_back();

    // Size and capacity
    std::cout << "Size: " << numbers.size()
              << ", Capacity: " << numbers.capacity() << "\n";
// empty() function
    std::cout << "Is empty: " << numbers.empty() << "\n";

    // Clearing the vector
    numbers.clear();
    std::cout << "Size after clear: " << numbers.size() << "\n";

    return 0;
}
