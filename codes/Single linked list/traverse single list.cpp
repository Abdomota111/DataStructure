#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Function to traverse and print the linked list
void Traverse(Node* list) {
    Node* P = list;  // Start at the head

    while (P != nullptr) {  // Continue until the end of the list
        cout << P->data << " -> ";  // Display data
        P = P->next;  // Move to the next node
    }
    cout << "NULL" << endl;  // Indicate end of list
}

int main() {
    Node* head = nullptr; 

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

    // Call Traverse function
    cout << "Linked List: ";
    Traverse(head);

    return 0;
}
