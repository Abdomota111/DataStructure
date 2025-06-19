#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Front and rear pointers
Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return -1; // Error value
    }
    int x = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) { // Queue is now empty
        rear = nullptr;
    }
    delete temp;
    return x;
}

int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->data;
}

int getRear() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return rear->data;
}

int size() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


// Print and restore function
void printAndRestoreQueue(Node*& front, Node*& rear) {
    Node* tempFront;
    Node* tempRear;
    Init(tempFront, tempRear); // Initialize temp queue

    while (front != nullptr) {
        int val = dequeue(front, rear);
        cout << val << " ";
        enqueue(tempFront, tempRear, val); // Put into temp queue
    }
    cout << endl;

    // Restore original queue
    while (tempFront != nullptr) {
        int val = dequeue(tempFront, tempRear);
        enqueue(front, rear, val);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Queue: "; printAndRestoreQueue();
    cout << "Front: " << getFront() << endl;
    cout << "Rear: " << getRear() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Queue after dequeue: "; printQueue();
    cout << "Front: " << getFront() << endl;
    enqueue(40);
    cout << "Rear: " << getRear() << endl;
    cout << "Size: " << size() << endl;
    return 0;
}
