#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void delet(Node* &head,int x,bool& Done){
    Node* p = head;
    Node* q = head;
    
    while((p!=NULL) && (p->data !=x)) {
        q=p;
        p = head->next;
    }
    if(p==NULL){
        Done = false;
    }
    else{
        Done = true;
        q->next = p->next;
        if(head==p){
            head = head->next;
        }
        delete p;
    }
}


void Traverse(Node* &head) {
    Node* P =head;
    while(P!=NULL) {
        cout <<P->data <<" -> ";
        P = P->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = nullptr; // Head pointer declared here

    // Creating nodes dynamically
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* D = new Node();

    // Assigning values
    A->data = 1;
    B->data = 22;
    C->data = 3;
    D->data = 4;

    // Linking nodes
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = nullptr;

    // Assigning head to the first node
    head = A;
    
    bool Done;
    Delete(head,22,Done);
    
    Traverse(head);
  
    return 0;
}