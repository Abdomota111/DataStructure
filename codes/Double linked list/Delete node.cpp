#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to remove a given node from DLL
void remove(Node*& head, Node* p) {
    if (p == nullptr) return; // If the node is null, do nothing

    Node* u = p->prev;
    Node* w = p->next;

    if (u != nullptr) 
        u->next = w; // Linking out p from the previous node
    else 
        head = w; // If p was the head, update head

    if (w != nullptr) 
        w->prev = u; // Linking out p from the next node

    delete p; // Free memory
}

// Function to traverse and print the DLL
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "Empty Linked List" << endl;
        return;
    }

    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " <-> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Function to find a node by value
Node* search(Node* head, int x) {
    Node* p = head;
    while (p != nullptr && p->data != x) {
        p = p->next;
    }
    return p; // Returns the node if found, else nullptr
}

int main() {
    // Creating a simple DLL: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node();
    head->data = 10;
    head->prev = nullptr;

    Node* second = new Node();
    second->data = 20;
    second->prev = head;
    head->next = second;

    Node* third = new Node();
    third->data = 30;
    third->prev = second;
    second->next = third;

    Node* fourth = new Node();
    fourth->data = 40;
    fourth->prev = third;
    third->next = fourth;
    fourth->next = nullptr;

    // Display the list
    cout << "Doubly Linked List before removal: ";
    traverse(head);

    // Remove node with value 30
    Node* nodeToRemove = search(head, 30);
    remove(head, nodeToRemove);

    // Display after deletion
    cout << "Doubly Linked List after removing 30: ";
    traverse(head);

    return 0;
}
