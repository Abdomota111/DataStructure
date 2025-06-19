#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNewNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void insert(Node*& root, int x) {
    if (root == nullptr) {
        root = CreateNewNode(x);
    }
    else if (x <= root->data) {
        insert(root->left, x);
    }
    else {
        insert(root->right, x);
    }
}

// Optional: Inorder traversal to test the tree
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 17);
    insert(root, 25);

    cout << "Inorder Traversal: ";
    inorder(root);  // Expected: 8 10 12 15 17 20 25

    return 0;
}
