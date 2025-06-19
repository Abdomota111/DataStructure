#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

   
void add(Node*& head, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    
    if (head == NULL) {
        head = temp;  
        return;
    }

    Node* p = head->prev;  
    p->next =temp;
    temp->prev = p;
    temp->next = head;
    head->prev = temp;  // Pointing the head's prev to the new node
    head = temp;  // Update the head to the new node
}
    

// Function to traverse CDLL
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* p = head;
    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != head);

    cout << "(head)\n"; // Indicating circular nature
}


int main() {
    
    
    
     // Predefined nodes
    Node* head = new Node{10, NULL, NULL};
    Node* second = new Node{20, NULL, NULL};
    Node* third = new Node{30, NULL, NULL};
    Node* tail = new Node{40, NULL, NULL};

    // Connecting nodes to form a CDLL
    head->next = second;
    head->prev = tail;

    second->next = third;
    second->prev = head;

    third->next = tail;
    third->prev = second;

    tail->next = head;
    tail->prev = third;

    
    
    add(head,90);
    
    traverse(head);
    
    return 0;
}