#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse K nodes
Node* reverseKGroup(Node* head, int K) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Count the nodes to check if at least K nodes are present
    Node* temp = head;
    int nodeCount = 0;
    while (temp) {
        nodeCount++;
        temp = temp->next;
    }
    if (nodeCount < K) return head; // less than K nodes, leave as-is

    // Reverse first K nodes
    while (current && count < K) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse remaining nodes
    if (next) {
        head->next = reverseKGroup(next, K);
    }

    return prev; // new head after reversal
}

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int K;
    cout << "Enter value of K: ";
    cin >> K;

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, K);

    cout << "Reversed in groups of " << K << ": ";
    printList(head);

    return 0;
}