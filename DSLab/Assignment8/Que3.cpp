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

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        if (!node->left) return 1 + minDepth(node->right);
        if (!node->right) return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

public:
    BST() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }

    void deleteElement(int val) { root = deleteNode(root, val); }

    int getMaxDepth() { return maxDepth(root); }

    int getMinDepth() { return minDepth(root); }

    void displayInOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int choice, val;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display In-order\n4. Max Depth\n5. Min Depth\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insert(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                bst.deleteElement(val);
                break;
            case 3:
                cout << "In-order traversal: ";
                bst.displayInOrder();
                break;
            case 4:
                cout << "Maximum depth: " << bst.getMaxDepth() << endl;
                break;
            case 5:
                cout << "Minimum depth: " << bst.getMinDepth() << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}