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
    int postIndex;

    Node* buildTreeUtil(int inorder[], int postorder[], int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if (inStart > inEnd)
            return nullptr;

        int rootVal = postorder[postIndex--];
        Node* root = new Node(rootVal);

        int inIndex = inMap[rootVal];

        // Important: build right subtree first
        root->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, inMap);
        root->left = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, inMap);

        return root;
    }

public:
    Node* buildTree(int inorder[], int postorder[], int n) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;

        postIndex = n - 1;
        return buildTreeUtil(inorder, postorder, 0, n - 1, inMap);
    }

    void inorderTraversal(Node* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void postorderTraversal(Node* root) {
        if (!root) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
};

// ------------------- MAIN -------------------
int main() {
    int inorder[] = {20, 30, 40, 50, 60, 70, 80};
    int postorder[] = {20, 40, 30, 60, 80, 70, 50};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    BinaryTree tree;
    Node* root = tree.buildTree(inorder, postorder, n);

    cout << "Inorder traversal of constructed tree: ";
    tree.inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal of constructed tree: ";
    tree.postorderTraversal(root);
    cout << endl;

    return 0;
}