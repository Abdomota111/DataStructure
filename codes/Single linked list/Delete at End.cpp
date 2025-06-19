#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete a node from the end
void deleteFromEnd(Node*& head) {
    if (head != nullptr) {
        // If the list has only one node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* p = head;
            Node* q = nullptr;

            // Traverse to the last node
            while (p->next != nullptr) {
                q = p;
                p = p->next;
            }

            q->next = nullptr; // Remove last node reference
            delete p; // Free the last node
        }
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

    // Deleting node from the end
    deleteFromEnd(head);

    cout << "Updated List after deleting last node: ";
    Traverse(head);

    return 0;
}
