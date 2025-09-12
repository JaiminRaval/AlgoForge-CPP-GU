#include <iostream>
using namespace std;

// Simple Stack class using array
class Stack {
private:
    int arr[100];  // Fixed size array to store stack elements
    int top;       // Index pointing to the top element (-1 means empty)

public:
    // Constructor - initializes an empty stack
    Stack() {
        top = -1;  // -1 means stack is empty
        cout << " New stack created (empty)\n";
    }

    // Push: Add element to top of stack
    void push(int value) {
        // Check if stack is full (overflow condition)
        if (top >= 99) {
            cout << "❌ Stack Overflow! Cannot push " << value << "\n";
            return;
        }

        top++;           // Move top pointer up
        arr[top] = value; // Store the value

        cout << " Pushed " << value << " | Stack size now: " << (top + 1) << "\n";
    }

    // Pop: Remove top element from stack
    void pop() {
        // Check if stack is empty (underflow condition)
        if (top < 0) {
            cout << "❌ Stack Underflow! Nothing to pop\n";
            return;
        }

        cout << " Popped " << arr[top] << " | Stack size now: " << top << "\n";
        top--;  // Move top pointer down
    }

    // Peek: Look at top element without removing it
    int peek() {
        if (top < 0) {
            cout << " Stack is empty - no top element\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Print all elements in the stack
    void display() {
        if (top < 0) {
            cout << " Stack is empty\n";
            return;
        }

        cout << " Stack contents (top → bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " → ";
        }
        cout << "\n";
    }

    // Get current stack size
    int size() {
        return top + 1;
    }
};

int main() {
    cout << "-/-/-/ Stack Implementation Demo -/-/-/\n\n";

    Stack myStack;  // Create a new stack

    cout << "\n Testing Push Operations:\n";
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();

    cout << "\n Testing Peek Operation:\n";
    cout << " Top element is: " << myStack.peek() << "\n";

    cout << "\n Testing Pop Operations:\n";
    myStack.pop();
    myStack.display();

    myStack.pop();
    myStack.display();

    cout << "\n Testing Empty Stack:\n";
    myStack.pop();  // Remove last element
    myStack.display();

    cout << "\n Testing Underflow:\n";
    myStack.pop();  // Try to pop from empty stack

    cout << "\n Final Status:\n";
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack size: " << myStack.size() << "\n";

    return 0;
}
