#include <iostream>

#define MAX_SIZE 50

using namespace std;

int queue[MAX_SIZE];
int front = 0;
int rear = 0;
int count = 0;

bool isEmpty() {
    return count == 0;
}

bool isFull() {
    return count == MAX_SIZE;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    queue[rear] = x;
    rear = (rear + 1) % MAX_SIZE;
    count++;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return -1; // Error value
    }
    int x = queue[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return x;
}

int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue[front];
}

int getRear() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue[(rear - 1 + MAX_SIZE) % MAX_SIZE];
}

int size() {
    return count;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << "Front: " << getFront() << endl;
    cout << "Rear: " << getRear() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Front: " << getFront() << endl;
    cout << "Size: " << size() << endl;
    return 0;
}
