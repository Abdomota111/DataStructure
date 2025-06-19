#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the beginning of a doubly linked list
void insert(Node*& head, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    temp->prev = nullptr;

    if (head != nullptr) {
        head->prev = temp;
    }

    head = temp; // Update head to the new node
}

// Function to traverse and print the list
void Traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr; // Initially, the list is empty

    // Insert elements into the doubly linked list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    // Print the updated list
    cout << "Doubly Linked List after insertions: ";
    Traverse(head);

    return 0;
}