#include <iostream>
using namespace std;

// Queue class using array
class Queue {
    int front, rear, size;  // Track positions and current size
    int capacity;
    int* arr;

public:
    Queue(int c) {  // Constructor: set capacity and initialize
        capacity = c;
        front = 0;
        size = 0;
        rear = capacity - 1;
        arr = new int[capacity];
    }

    ~Queue() {  // Destructor: free memory
        delete[] arr;
    }

    bool isFull() {  // Check if queue is full
        return (size == capacity);
    }

    bool isEmpty() {  // Check if queue is empty
        return (size == 0);
    }

    void enqueue(int item) {  // Add item to rear
        if (isFull()) {
            cout << "Queue full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {  // Remove item from front
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return -1;  // Error value
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() {  // Peek front item
        if (isEmpty()) return -1;
        return arr[front];
    }
};

// Demo in main
int main() {
    Queue q(3);  // Capacity 3

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);  // This will show full

    cout << "dequeued: "<< q.dequeue() << endl;
    cout << "front now: "<< q.getFront() << endl;

    return 0;
}