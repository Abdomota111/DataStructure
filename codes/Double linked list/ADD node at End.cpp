#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of DLL
void insert(Node*& head, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    temp->prev = nullptr;

    // If the list is empty, make temp the head
    if (head == nullptr) {
        head = temp;
        return;
    }

    // Traverse to the last node
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Insert the new node at the end
    last->next = temp;
    temp->prev = last;
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
    // Creating a predefined Doubly Linked List: 10 <-> 20 <-> 30
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

    // Print the original list
    cout << "Original Doubly Linked List: ";
    Traverse(head);

    // Insert new node at the end
    insert(head, 40);

    // Print the updated list
    cout << "Updated Doubly Linked List after insertion: ";
    Traverse(head);

    return 0;
}
