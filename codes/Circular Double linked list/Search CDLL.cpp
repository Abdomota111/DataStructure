#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Search function to find a value in the circular doubly linked list
void search(Node *head, int x) {
    // If the list is empty
    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    Node *p = head;
    do {
        if (p->data == x) {
            cout << "Found" << endl;
            return;
        }
        p = p->next;  // Move to the next node
    } while (p != head);  // Stop when we return to the head

    // If the element is not found
    cout << "X is not found" << endl;
}

// Main function to test the search function
int main() {
    Node *head = nullptr;

    // Code to insert some nodes for testing purposes
    // You can use the insert function from the previous code to add nodes
    // Example: insert(head, 10); insert(head, 20);

    // Test searching in an empty list
    search(head, 10);

    return 0;
}
