#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if a binary tree is BST
bool isBST(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (!root) return true;
    if (root->data < minVal || root->data > maxVal)
        return false;
    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}

// Helper function to create a sample tree (for testing)
Node* createSampleTree() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);
    return root;
}

int main() {
    Node* root = createSampleTree();

    if (isBST(root))
        cout << "The binary tree is a BST." << endl;
    else
        cout << "The binary tree is NOT a BST." << endl;

    return 0;
}
