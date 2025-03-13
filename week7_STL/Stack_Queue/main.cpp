#include <iostream>
#include <stack>
#include <queue>
#include <vector>

int main() {
    // -------------------- Demonstrating std::stack --------------------
    std::stack<int> myStack;
    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element of myStack: " << myStack.top() << "\n"; // Expected 30

    // Pop an element
    myStack.pop();
    std::cout << "Top element of myStack after pop: " << myStack.top() << "\n"; // Expected 20

    // Size of the stack
    std::cout << "Size of myStack: " << myStack.size() << "\n";

    // Check if empty
    std::cout << "Is myStack empty? " << (myStack.empty() ? "Yes" : "No") << "\n\n";


    // -------------------- Demonstrating std::queue --------------------
    std::queue<std::string> myQueue;
    // Enqueue (push) elements
    myQueue.push("Alice");
    myQueue.push("Bob");
    myQueue.push("Charlie");

    std::cout << "Front element of myQueue: " << myQueue.front() << "\n"; // Expected "Alice"
    std::cout << "Back element of myQueue: " << myQueue.back() << "\n";   // Expected "Charlie"

    // Dequeue (pop) an element
    myQueue.pop();
    std::cout << "Front element after pop: " << myQueue.front() << "\n"; // Expected "Bob"

    // Size of the queue
    std::cout << "Size of myQueue: " << myQueue.size() << "\n";

    // Check if empty
    std::cout << "Is myQueue empty? " << (myQueue.empty() ? "Yes" : "No") << "\n\n";


    // -------------------- Demonstrating std::priority_queue --------------------
    // By default, std::priority_queue is a max-heap (largest element on top)
    std::priority_queue<int> myPriorityQueue;

    // Push elements
    myPriorityQueue.push(5);
    myPriorityQueue.push(10);
    myPriorityQueue.push(1);

    std::cout << "Top of myPriorityQueue: " << myPriorityQueue.top() << "\n"; // Expected 10

    // Pop an element
    myPriorityQueue.pop();
    std::cout << "Top of myPriorityQueue after pop: " << myPriorityQueue.top() << "\n"; // Expected 5

    // Size of the priority_queue
    std::cout << "Size of myPriorityQueue: " << myPriorityQueue.size() << "\n";

    // Check if empty
    std::cout << "Is myPriorityQueue empty? " << (myPriorityQueue.empty() ? "Yes" : "No") << "\n\n";

    // If you want a min-heap, you can define a custom comparator or use std::greater<int>
    std::priority_queue<int, std::vector<int>, std::greater<int>> myMinHeap;
    myMinHeap.push(5);
    myMinHeap.push(10);
    myMinHeap.push(1);

    std::cout << "Top of myMinHeap (smallest element): " << myMinHeap.top() << "\n"; // Expected 1
    myMinHeap.pop();
    std::cout << "Top of myMinHeap after pop (smallest element): " << myMinHeap.top() << "\n"; // Expected 5

    return 0;
}
