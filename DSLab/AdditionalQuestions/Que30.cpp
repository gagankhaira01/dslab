#include <iostream>
using namespace std;

// -------------------- BST Node --------------------
class NodeBST {
public:
    int data;
    NodeBST* left;
    NodeBST* right;
    NodeBST(int val) {
        data = val;
        left = right = nullptr;
    }
};

// -------------------- Doubly Linked List Node --------------------
class NodeDLL {
public:
    int data;
    NodeDLL* prev;
    NodeDLL* next;
    NodeDLL(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// -------------------- BST Class --------------------
class BST {
public:
    NodeBST* root;
    BST() { root = nullptr; }

    void insert(int val) {
        NodeBST* newNode = new NodeBST(val);
        if (!root) {
            root = newNode;
            return;
        }
        NodeBST* curr = root;
        NodeBST* parent = nullptr;
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

    // Convert BST to DLL using in-order traversal
    void bstToDll(NodeBST* node, NodeDLL*& head, NodeDLL*& prev) {
        if (!node) return;

        bstToDll(node->left, head, prev);

        NodeDLL* curr = new NodeDLL(node->data);
        if (!head) head = curr;
        if (prev) {
            prev->next = curr;
            curr->prev = prev;
        }
        prev = curr;

        bstToDll(node->right, head, prev);
    }
};

// Merge two sorted DLLs
NodeDLL* mergeDLLs(NodeDLL* head1, NodeDLL* head2) {
    NodeDLL dummy(0);
    NodeDLL* tail = &dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    if (dummy.next) dummy.next->prev = nullptr;
    return dummy.next;
}

// Print DLL
void printDLL(NodeDLL* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <=> ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- MAIN --------------------
int main() {
    BST bst1, bst2;

    // BST 1: 10, 5, 15
    bst1.insert(10);
    bst1.insert(5);
    bst1.insert(15);

    // BST 2: 20, 3, 7
    bst2.insert(20);
    bst2.insert(3);
    bst2.insert(7);

    NodeDLL* head1 = nullptr;
    NodeDLL* prev1 = nullptr;
    bst1.bstToDll(bst1.root, head1, prev1);

    NodeDLL* head2 = nullptr;
    NodeDLL* prev2 = nullptr;
    bst2.bstToDll(bst2.root, head2, prev2);

    NodeDLL* mergedHead = mergeDLLs(head1, head2);

    cout << "Merged Doubly Linked List in sorted order: ";
    printDLL(mergedHead);

    return 0;
}