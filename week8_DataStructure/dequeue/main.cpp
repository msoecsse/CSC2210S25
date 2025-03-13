#include <iostream>

using namespace std;

// Node structure for the deque (doubly linked list)
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node
    Node* prev;   // Pointer to the previous node
};

// Deque class using a doubly linked list
class Deque {
private:
    Node* front; // Pointer to the front of the deque
    Node* rear;  // Pointer to the rear of the deque

public:
    // Constructor to initialize the deque
    Deque() {
        front = rear = nullptr;
    }

    // Push an element at the front
    void pushFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = front;
        newNode->prev = nullptr;

        if (isEmpty()) {
            rear = newNode; // If deque was empty, rear also points to newNode
        } else {
            front->prev = newNode;
        }

        front = newNode;
        cout << "added at Front: " << value << endl;
    }

    // Push an element at the back
    void pushBack(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (isEmpty()) {
            front = newNode; // If deque was empty, front also points to newNode
        } else {
            rear->next = newNode;
        }

        rear = newNode;
        cout << "added at Back: " << value << endl;
    }

    // Pop an element from the front
    int popFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot pop from an empty deque.\n";
            return -1;
        }

        Node* temp = front;
        int poppedValue = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // If deque becomes empty, rear should also be null
        } else {
            front->prev = nullptr;
        }

        delete temp;
        cout << "removed from Front: " << poppedValue << endl;
        return poppedValue;
    }

    // Pop an element from the back
    int popBack() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot pop from an empty deque.\n";
            return -1;
        }

        Node* temp = rear;
        int poppedValue = temp->data;
        rear = rear->prev;

        if (rear == nullptr) {
            front = nullptr; // If deque becomes empty, front should also be null
        } else {
            rear->next = nullptr;
        }

        delete temp;
        cout << "removed from Back: " << poppedValue << endl;
        return poppedValue;
    }

    // Get the front element
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty! No front element.\n";
            return -1;
        }
        return front->data;
    }

    // Get the back element
    int peekBack() {
        if (isEmpty()) {
            cout << "Deque is empty! No rear element.\n";
            return -1;
        }
        return rear->data;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to clean up memory
    ~Deque() {
        while (!isEmpty()) {
            popFront(); // Remove all elements to free memory
        }
        cout << "Deque memory cleaned up.\n";
    }
};

// Main function to test deque operations
int main() {
    Deque dq;

    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(30);

    cout << "Front element: " << dq.peekFront() << endl;
    cout << "Back element: " << dq.peekBack() << endl;

    dq.popFront();
    dq.popBack();
    dq.popFront();
    dq.popBack();

    dq.popFront(); // Attempting to pop from an empty deque

    return 0;
}
