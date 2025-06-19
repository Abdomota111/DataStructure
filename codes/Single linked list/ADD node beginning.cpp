#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Function to add a new node at the beginning
void Add(Node*& head, char x) {
    Node* P = new Node(); // Create new node
    P->data = x;          // Assign value to new node
    P->next = head;       // Point new node to old head
    head = P;             // Update head to new node
}

// Function to traverse and print the linked list
void Traverse(Node* list) {
    Node* P = list; 
    while (P != nullptr) {
        cout << P->data << " -> ";
        P = P->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr; // Head pointer declared here

    // Creating nodes dynamically
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* D = new Node();

    // Assigning values
    A->data = 'A';
    B->data = 'B';
    C->data = 'C';
    D->data = 'D';

    // Linking nodes
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = nullptr;

    // Assigning head to the first node
    head = A;
    
    Add(head, 'X'); // List: X -> A -> B -> C -> D -> NULL

    // Print the list
    cout << "Linked List after inserting node at the head: ";
    Traverse(head);

    return 0;
}
===============================================================================================================
===============================================================================================================

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

// Function to traverse and print the linked list
void Traverse(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
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

    return 0;
}