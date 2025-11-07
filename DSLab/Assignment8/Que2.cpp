#include <iostream>
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

// Insert node in BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Recursive search
Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// Non-recursive search
Node* searchNonRecursive(Node* root, int key) {
    Node* curr = root;
    while (curr) {
        if (key == curr->data) return curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return nullptr;
}

// Maximum element in BST
Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

// Minimum element in BST
Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// In-order successor
Node* inOrderSuccessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->right) return findMin(node->right);
    Node* succ = nullptr;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

// In-order predecessor
Node* inOrderPredecessor(Node* root, Node* node) {
    if (!node) return nullptr;
    if (node->left) return findMax(node->left);
    Node* pred = nullptr;
    while (root) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}

// In-order traversal (for display)
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;
    cout << "Enter number of nodes in BST: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "In-order traversal of BST: ";
    inOrder(root);
    cout << endl;

    cout << "Enter key to search: ";
    cin >> val;
    Node* foundR = searchRecursive(root, val);
    Node* foundNR = searchNonRecursive(root, val);
    cout << "Recursive search: " << (foundR ? "Found" : "Not Found") << endl;
    cout << "Non-recursive search: " << (foundNR ? "Found" : "Not Found") << endl;

    Node* maxNode = findMax(root);
    Node* minNode = findMin(root);
    cout << "Maximum element: " << (maxNode ? maxNode->data : -1) << endl;
    cout << "Minimum element: " << (minNode ? minNode->data : -1) << endl;

    Node* succ = inOrderSuccessor(root, foundR);
    Node* pred = inOrderPredecessor(root, foundR);
    cout << "In-order successor of " << val << ": " << (succ ? succ->data : -1) << endl;
    cout << "In-order predecessor of " << val << ": " << (pred ? pred->data : -1) << endl;

    return 0;
}