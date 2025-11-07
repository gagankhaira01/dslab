#include <iostream>
#include <unordered_map>
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

class BinaryTree {
private:
    int preIndex = 0;

    Node* buildTreeUtil(int inorder[], int preorder[], int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        int inIndex = inMap[rootVal];

        root->left = buildTreeUtil(inorder, preorder, inStart, inIndex - 1, inMap);
        root->right = buildTreeUtil(inorder, preorder, inIndex + 1, inEnd, inMap);

        return root;
    }

public:
    Node* buildTree(int inorder[], int preorder[], int n) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;
        preIndex = 0;
        return buildTreeUtil(inorder, preorder, 0, n - 1, inMap);
    }

    void inorderTraversal(Node* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};

// ------------------- MAIN -------------------
int main() {
    int inorder[] = {20, 30, 40, 50, 60, 70, 80};
    int preorder[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    BinaryTree tree;
    Node* root = tree.buildTree(inorder, preorder, n);

    cout << "Inorder traversal of constructed tree: ";
    tree.inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal of constructed tree: ";
    tree.preorderTraversal(root);
    cout << endl;

    return 0;
}