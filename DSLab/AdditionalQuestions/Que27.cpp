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

public:
    BST() { root = nullptr; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        Node* curr = root;
        Node* parent = nullptr;
        while (curr) {
            parent = curr;
            if (val < curr->data)
                curr = curr->left;
            else if (val > curr->data)
                curr = curr->right;
            else
                return; // no duplicates
        }
        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void inorderNonRecursive() {
        if (!root) return;

        Node* curr = root;
        Node* stack[100]; // simple array stack
        int top = -1;

        while (curr != nullptr || top != -1) {
            // Reach the leftmost node
            while (curr != nullptr) {
                stack[++top] = curr;
                curr = curr->left;
            }

            // curr is nullptr at this point
            curr = stack[top--]; // pop
            cout << curr->data << " ";

            // Visit right subtree
            curr = curr->right;
        }
        cout << endl;
    }
};

// ------------------- MAIN -------------------
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal (non-recursive): ";
    tree.inorderNonRecursive();

    return 0;
}
