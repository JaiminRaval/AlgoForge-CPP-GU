#include <iostream>  // For input/output
using namespace std;  // To avoid writing std:: everywhere



// Define a simple Node structure
struct Node {
    int data;      // Holds the data (we're using integers here)
    Node* next;    // Pointer to the next node in the list
};




// Function to print the entire linked list
void printList(Node* head) {
    Node* current = head;  // Start from the head of the list
    while (current  nullptr) {  // Loop until we reach the end
        cout << current->data << " -> ";  // Print the data
        current = current->next;  // Move to the next node
    }
    cout << "nullptr" << endl;  // Indicate the end of the list
}

// Function to insert a new node at the end of the list
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;  // Create a new node
    newNode->data = value;     // Set the data
    newNode->next = nullptr;   // New node points to nothing (end of list)

    if (head == nullptr) {     // If the list is empty
        head = newNode;        // The new node becomes the head
    } else {
        Node* current = head;  // Start from the head
        while (current->next != nullptr) {  // Find the last node
            current = current->next;
        }
        current->next = newNode;  // Link the last node to the new one
    }
}

// Main function to demonstrate the linked list
int main() {
    Node* head = nullptr;  // Start with an empty list (head points to nothing)

    // Insert some nodes
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    // Print the list
    cout << "Linked List: ";
    printList(head);

    // Note: In a real program, you should free the memory with delete to avoid leaks
    return 0;
}
