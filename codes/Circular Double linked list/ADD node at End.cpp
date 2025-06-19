#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Insert function, to insert a node at the end
void insert(Node *&head, int x) {
    Node *temp = new Node();  
    Node *p = head ? head->prev : nullptr;  // If head is not NULL, get the previous node

    temp->data = x;
    temp->next = temp;
    temp->prev = temp;

    // If the list is empty
    if (head == nullptr) {
        head = temp;
        return;
    }

    // If the list is not empty, insert at the end
    p->next = temp;        // The last node's next points to the new node
    temp->prev = p;        // The new node's prev points to the last node
    temp->next = head;     // The new node's next points to the head
    head->prev = temp;     // The head's prev points to the new node
}

// Function to display the list (with a circular visualization)
void display(Node *head) {
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return;
    }

    Node *temp = head;
    cout << "Circular Doubly Linked List: ";
    do {
        cout << "[ " << temp->data << " ]";
        if (temp->next != head) {
            cout << " <-> ";
        }
        temp = temp->next;
    } while (temp != head);  // Stop when we return to the head
    cout << " (head)\n";  // Indicate where the head is in the circular structure
}

// Main function to test the insert function
int main() {
    Node *head = nullptr;  // Initialize the head of the list as null

    // Insert some nodes at the end into the list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    // Display the list with circular doubly linked list visualization
    display(head);  // Expected output: [10] <-> [20] <-> [30] <-> (head)

    return 0;
}
