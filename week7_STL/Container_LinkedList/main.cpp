#include <iostream>
#include <list>

int main() {
    std::list<int> lst;

// Adding elements
    //push_front() function
    // The push_front() function adds an element to the front of the list.


    // Insert elements at the beginning
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);



    // Insert elements at the end
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);


    // Insert at specific position
    auto it = lst.begin();
    // The begin() function returns an iterator pointing to the first element in the list.
    // The end() function returns an iterator pointing to the past-the-end element in the list.
    // The iterator is a pointer-like object that can be used to access elements in the list.
    ++it;  // move iterator to point to "20"
    // insert() function
    lst.insert(it, 15);  // insert 15 before 20

    // Remove an element by value
    lst.remove(10);

    // Iterate
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << "\n";

///
    std::list<int> l = {1, 3, 4, 2, 5};


    // Move iterator to the second element
    auto itr = l.begin();
    // advance() function
    // The advance() function moves the iterator by a
    // specified number of positions.
    std::advance(itr, 2); // &[itr] will give the memory location
    // jump 2 steps

    // Update the value using iterator
    *itr = 10; // dereference the itr and store the value 10

    for (auto i: l) {
        // for each loop
        std::cout << i << " ";
    }

    return 0;
}
