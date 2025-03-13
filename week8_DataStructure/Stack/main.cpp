#include <iostream>

using namespace std;

// Node structure to hold stack elements
struct Node {
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the stack
};

// Stack class using linked list implementation
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize stack
    Stack() {
        top = nullptr;
    }
    // destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack memory cleaned up.\n";
    }

    // Push operation: Insert an element into the stack
    void push(int value) {
        Node* newNode = new Node(); // Create a new node dynamically
        newNode->data = value;
        newNode->next = top; // Link the new node to the current top
        top = newNode;       // Update top to the new node
        cout << "added: " << value << endl;
    }

    // Pop operation: Remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return -1; // Return an invalid value
        }
        Node* temp = top; // Store the current top node
        int poppedValue = temp->data;
        top = top->next;  // Move top to the next node
        delete temp;      // Free memory
        cout << "removed: " << poppedValue << endl;
        return poppedValue;
    }

    // Peek operation: View the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
    // print all elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements are: ";
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    };

// Main function to test stack operations
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();
    s.pop();

    s.pop(); // Attempting to pop from an empty stack

    return 0;
}
