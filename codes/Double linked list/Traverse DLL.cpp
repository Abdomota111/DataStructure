#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

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
    cout << "NULL" << endl;  // Indicating the end of the list
}

// Main function to test traverse
int main() {
    // Creating a simple DLL: 10 <-> 20 <-> 30
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
    third->next = nullptr;

    // Traverse the linked list
    cout << "Doubly Linked List: ";
    traverse(head);

    return 0;
}
