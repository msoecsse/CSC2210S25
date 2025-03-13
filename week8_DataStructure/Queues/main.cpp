#include <iostream>

using namespace std;

// Node structure for the queue
struct Node {
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the queue
};

// Queue class using linked list implementation
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation: Insert an element at the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(); // Create a new node dynamically
        newNode->data = value;
        newNode->next = nullptr; // Since this will be the last node

        if (isEmpty()) {
            // If the queue is empty, front and rear both point to the new node
            front = rear = newNode;
        } else {
            // Otherwise, link the new node to the current rear and update rear
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation: Remove the front element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from an empty queue.\n";
            return -1; // Return an invalid value
        }

        Node* temp = front; // Store the current front node
        int dequeuedValue = temp->data;

        front = front->next; // Move front to the next node

        if (front == nullptr) {
            // If the queue becomes empty, reset rear to nullptr as well
            rear = nullptr;
        }

        delete temp; // Free memory
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    // Peek operation: View the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Dequeue all elements to free memory
        }
        cout << "Queue memory cleaned up.\n";
    }
    // Print all elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements are: ";
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test queue operations
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
