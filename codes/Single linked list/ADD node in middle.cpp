#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert x before y
void insertBefore(Node*& head, int x, int y) {
    Node* P = new Node();
    P->data = x;
    P->next = nullptr;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr->next != nullptr) {
        if (curr->data != y) {
            prev = curr;
            curr = curr->next;
        } else {
            prev->next = P;
            P->next = curr;
            return;
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

    insertBefore(head, 25, 30);

    cout << "Updated List: ";
    Traverse(head);

    return 0;
}



=======================================================================================================================
=======================================================================================================================
#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;  // Initialize head as null
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void InsertAtPosition(int x, int position) {
        Node* p = new Node();
        p->data = x;
        
        if (position == 1) {  // Insert at the beginning
            p->next = head;
            head = p;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp != nullptr && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == nullptr) {  // Position is out of bounds
            cout << "Position is out of bounds!" << endl;
            delete p;
            return;
        }

        p->next = temp->next;  // Insert the new node after temp
        temp->next = p;  // Update the next pointer of the previous node
    }
};

int main() {
    LinkedList list;
    
    list.InsertAtPosition(10, 1);  // Insert 10 at position 1
    list.InsertAtPosition(20, 2);  // Insert 20 at position 2
    list.InsertAtPosition(30, 3);  // Insert 30 at position 3
    
    list.InsertAtPosition(15, 2);  // Insert 15 at position 2
    list.print();  // Output: 10 15 20 30

    list.InsertAtPosition(5, 1);   // Insert 5 at position 1
    list.print();  // Output: 5 10 15 20 30

    list.InsertAtPosition(25, 4);  // Try to insert at position 6 (out of bounds)
    list.print();  // Output: Position is out of bounds!

    return 0;
}
