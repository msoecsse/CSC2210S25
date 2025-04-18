#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename Container>
void selectionSort(Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        auto minIt = it;
        // compare the current element with the rest of the elements
        // to find the minimum element
        // next(it) is used to avoid comparing the current element with itself
        // and to start the search from the next element
        // this is a linear search
        for (auto jt = next(it); jt != container.end(); ++jt) {
            if (*jt < *minIt) {
                minIt = jt;
            }
        }
        if (minIt != it) {
            Swap(*it, *minIt);
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
    selectionSort(vec);
    cout << "Sorted: ";
    printContainer(vec);


    return 0;
}