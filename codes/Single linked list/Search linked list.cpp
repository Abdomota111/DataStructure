#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Function to create a new node
Node* CreateNode(char x) {
    Node* newNode = new Node(); // Create new node
    newNode->data = x;          // Set the node's data
    newNode->next = nullptr;    // Initially, the node points to nullptr
    return newNode;             // Return the new node
}

// Function to add a new node at the beginning
void Add(Node*& head, char x) {
    Node* P = CreateNode(x);    // Create new node with data 'x'
    P->next = head;             // Point new node to current head
    head = P;                   // Update head to point to new node
}

// Function to add a node at the end
void AddAtEnd(Node*& head, char x) {
    Node* P = CreateNode(x);    // Create a new node with data 'x'
    if (head == nullptr) {      // If the list is empty
        head = P;               // The new node becomes the head
    } else {
        Node* q = head;         // Start at the head of the list
        while (q->next != nullptr) { // Traverse until the last node
            q = q->next;        // Move to the next node
        }
        q->next = P;            // Add the new node at the end
    }
}

// Function to search for a node with a specific value
void Search(Node* head, char x, bool& found) {
    Node* P = head;  // Start from the head of the list
    while (P != nullptr && P->data != x) {  // Traverse the list
        P = P->next;  // Move to the next node
    }

    if (P == nullptr) {  // If the end of the list is reached
        found = false;    // Value was not found
    } else {
        found = true;     // Value was found
    }
}

// Function to traverse and print the linked list
void Traverse(Node* head) {
    Node* P = head;  // Set P to the head of the list
    while (P != nullptr) {  // Traverse until the end of the list
        cout << P->data << " -> ";  // Display the data of the current node
        P = P->next;  // Move P to the next node
    }
    cout << "NULL" << endl;  // Indicate the end of the list
}

int main() {
    Node* head = nullptr; // Initially, the list is empty

    // Add nodes to the list
    Add(head, 'A');
    Add(head, 'B');
    Add(head, 'C');
    Add(head, 'D');

    // Print the updated list
    cout << "Linked List after adding nodes at the head: ";
    Traverse(head);

    // Search for a node with a specific value
    bool found;
    char searchValue = 'C';
    Search(head, searchValue, found); // Search for the value 'C'
    if (found) {
        cout << "Node with value " << searchValue << " found in the list." << endl;
    } else {
        cout << "Node with value " << searchValue << " not found in the list." << endl;
    }

    searchValue = 'X';  // Searching for a value that doesn't exist in the list
    Search(head, searchValue, found); // Search for the value 'X'
    if (found) {
        cout << "Node with value " << searchValue << " found in the list." << endl;
    } else {
        cout << "Node with value " << searchValue << " not found in the list." << endl;
    }

    return 0;
}
