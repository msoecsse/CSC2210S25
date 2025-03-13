// Single linked list

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * A template-based implementation of a singly linked list.
 * @tparam T The type of elements stored in the linked list.
 */
template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        // Constructor to initialize a node with given data
        Node(const T &d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    // Constructor initializes an empty linked list
    SingleLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Destructor to free all allocated memory
    ~SingleLinkedList() {
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
            Node* newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
            listSize++;
        }
    }

    // Remove the first element from the list
    void pop_front() {
        if (!head) throw underflow_error("List is empty");
        Node* toDelete = head;
        head = head->next;
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
            Node* current = head;
            while (current->next != tail) current = current->next;
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        listSize--;
    }

    // Remove an element at a given index
    void remove(int index) {
        if (index < 0 || index >= listSize) throw out_of_range("Index out of bounds");
        if (index == 0) pop_front();
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) current = current->next;
            Node* toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete == tail) tail = current;
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

    // Search for an element in the list
    int search(const T &data) {
        int index = 0;
        for (Node* current = head; current; current = current->next, index++)
            if (current->data == data) return index;
        return -1;
    }

    // Size of the list
    int size() const { return listSize; }

    // Print all elements of the list
    void print() const {
        for (Node* current = head; current; current = current->next)
            cout << current->data << (current->next ? " -> " : "\n");
    }
};

int main() {
    SingleLinkedList<int> list;

    list.push_back(10);
    list.push_front(5);
    list.insert(7, 1);
    cout << "List after insertion: "; list.print();

    list.pop_front();
    cout << "After pop_front: "; list.print();

    list.pop_back();
    cout << "After pop_back: "; list.print();

    list.push_back(20);
    list.push_back(30);
    cout << "After adding 20 and 30: "; list.print();

    list.remove(1);
    cout << "After removing index 1: "; list.print();

    return 0;
}
