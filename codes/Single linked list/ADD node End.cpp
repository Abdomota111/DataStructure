#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Function to add a new node at the END
void Add(Node*& head, char x) {
    Node* P = new Node(); // Create new node
    P->data = x;          // Assign value to new node
    P->next = nullptr;    // New node will be the last node

    if (head == nullptr) { // If list is empty, new node becomes head
        head = P;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = P; // Link last node to new node
    }
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
    
    Add(head, 'X'); // List: A -> B -> C -> D -> X -> NULL

    // Print the list
    cout << "Linked List after inserting node at the end: ";
    Traverse(head);

    return 0;
}
