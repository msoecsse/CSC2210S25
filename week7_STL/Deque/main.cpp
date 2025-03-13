#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // 1) Push elements at front and back
    dq.push_back(20);    // dq = [20] // middle element
    dq.push_front(10);   // dq = [10, 20]
    dq.push_back(30);    // dq = [10, 20, 30]
    dq.push_front(5);    // dq = [5, 10, 20, 30]

    // 2) Emplace (construct in place) at front and back
    //    (For int it's the same effect as push, but for complex types,
    //    emplace avoids creating a temporary object.)
    dq.emplace_back(40);  // dq = [5, 10, 20, 30, 40]
    dq.emplace_front(1);  // dq = [1, 5, 10, 20, 30, 40]

    // 3) Index-based access
    std::cout << "dq[0] = " << dq[0] << "\n";
    std::cout << "dq.at(1) = " << dq.at(1) << "\n"; // at() performs bounds-checking

    // 4) Insert at arbitrary position
    auto it = dq.begin();
    ++it; // move iterator from dq.begin() (which is 1) to the second element (which is 5)
    dq.insert(it, 2); // inserts 2 before 5
    // Now dq = [1, 2, 5, 10, 20, 30, 40]

    // 5) Erase at arbitrary position
    it = dq.begin() + 3; // points to the element '10'
    dq.erase(it);
    // Now dq = [1, 2, 5, 20, 30, 40]

    // 6) Pop from front and back
    dq.pop_front(); // removes 1
    dq.pop_back();  // removes 40
    // Now dq = [2, 5, 20, 30]

    // 7) Check size and capacity-like behavior
    std::cout << "Size of dq: " << dq.size() << "\n";
    std::cout << "Is dq empty? " << std::boolalpha << dq.empty() << "\n";

    // 8) Emplace at arbitrary position
    it = dq.begin() + 1; // points to '5'
    dq.emplace(it, 99);  // inserts '99' before '5'
    // Now dq = [2, 99, 5, 20, 30]

    // 9) Resize the deque
    // If the new size is bigger, default-inserted elements are added (zeros for int).
    dq.resize(7);
    // Now dq = [2, 99, 5, 20, 30, 0, 0]

    // 10) Iterate using range-based for
    std::cout << "Elements in dq: ";
    for (int elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 11) Reverse iteration with rbegin() and rend()
    std::cout << "Elements in dq (reverse): ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    // 12) Clear all elements
    dq.clear();
    std::cout << "After clear(), size of dq: " << dq.size() << "\n";

    // 13) Swap two deques
    std::deque<int> dq1 = {1, 2, 3};
    std::deque<int> dq2 = {10, 20};
    dq1.swap(dq2);
    // Now dq1 = [10, 20], dq2 = [1, 2, 3]

    std::cout << "After swap:\n";
    std::cout << "dq1: ";
    for (int elem : dq1) std::cout << elem << " ";
    std::cout << "\n";
    std::cout << "dq2: ";
    for (int elem : dq2) std::cout << elem << " ";
    std::cout << "\n";

    return 0;
}
