// double linked list

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * A template-based implementation of a doubly linked list.
 * @tparam T The type of elements stored in the linked list.
 */
template <typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* prev; // Pointer to the previous node
        Node* next; // Pointer to the next node

        // Constructor to initialize a node with given data
        Node(const T &d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    // Constructor initializes an empty linked list
    DoubleLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // destructor to free all allocated memory
    ~DoubleLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        listSize = 0;
    }

    // Insert an element at the front of the list
    void push_front(const T &data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        // If the list is empty, the new node is also the tail
        if (!tail) tail = head;
        listSize++;
    }

    // Insert an element at the back of the list
    void push_back(const T &data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    // Insert an element at a given index (0-based)
    void insert(const T &data, int index) {
        if (index < 0 || index > listSize) throw out_of_range("Index out of bounds");
        if (index == 0) push_front(data);
        else if (index == listSize) push_back(data);
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) current = current->next;
            // Create a new node with the given data
            Node* newNode = new Node(data);
            // Connect the new node to the next node
            newNode->next = current->next; // Connect the new node to the next node
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            listSize++;
        }
    }

    // Remove the first element from the list
    void pop_front() {
        if (!head) throw underflow_error("List is empty");
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete toDelete;
        listSize--;
        if (!head) tail = nullptr;
    }

    // Remove the last element from the list
    void pop_back() {
        if (!head) throw underflow_error("List is empty");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete toDelete;
        }
        listSize--;
    }

    // Remove an element at a given index
    void remove(int index) {
        if (index < 0 || index >= listSize) throw out_of_range("Index out of bounds");
        if (index == 0) pop_front();
        else if (index == listSize - 1) pop_back();
        else {
            Node* current = head;
            for (int i = 0; i < index; i++) current = current->next;
            Node* toDelete = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete toDelete;
            listSize--;
        }
    }

    // Retrieve the element at a given index
    T& at(int index) {
        if (index < 0 || index >= listSize) throw out_of_range("Index out of bounds");
        Node* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        return current->data;
    }

    // Return the number of elements in the list
    int size() const {
        return listSize;
    }

    // Search for an element in the list
    int search(const T &data) {
        int index = 0;
        for (Node* current = head; current; current = current->next, index++)
            if (current->data == data) return index;
        return -1;
    }

    // Print all elements of the list
    void print() {
        for (Node* current = head; current; current = current->next)
            cout << current->data << " ";
        cout << endl;
    }
};

int main() {
 DoubleLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    list.print(); // 10 20 30 40 50

    list.pop_front();
    list.pop_back();
    list.print(); // 20 30 40

    list.insert(15, 1);
    list.insert(35, 3);
    list.print(); // 20 15 30 35 40

    list.remove(1);
    list.remove(3);
    list.print(); // 20 30 40

    cout << "Element at index 1: " << list.at(1) << endl; // 30

    cout << "Index of 30: " << list.search(30) << endl; // 1
    cout << "Index of 50: " << list.search(50) << endl; // -1

    cout << "Size of the list: " << list.size() << endl; // 3

    return 0;



}




