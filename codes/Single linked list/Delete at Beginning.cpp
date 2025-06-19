#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete a node from the beginning
void deleteFromBeginning(Node*& head) {
    if (head != nullptr) {
        Node* P = head;    // Store the current head
        head = head->next; // Move head to the next node
        delete P;          // Free memory
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
    // Creating a sample linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node();
    head->data = 10;

    Node* second = new Node();
    second->data = 20;
    head->next = second;

    Node* third = new Node();
    third->data = 30;
    second->next = third;

    Node* fourth = new Node();
    fourth->data = 40;
    third->next = fourth;

    fourth->next = nullptr;

    cout << "Original List: ";
    Traverse(head);

    // Deleting node from the beginning
    deleteFromBeginning(head);

    cout << "Updated List after deleting head: ";
    Traverse(head);

    return 0;
}
