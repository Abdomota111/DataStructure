#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

int main() {
    Node* head = nullptr; // Head pointer initialized to NULL

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

    // Printing the list using head pointer
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Checking and printing head
    if (head != nullptr) {
        cout << "Head of the list contains: " << head->data << endl;
    }

    // Free allocated memory
    delete A;
    delete B;
    delete C;
    delete D;

    return 0;
}
