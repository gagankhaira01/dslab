#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to rotate linked list left by k positions
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Compute length
    Node* temp = head;
    int n = 1;
    while (temp->next) {
        temp = temp->next;
        n++;
    }

    k = k % n; // if k >= n
    if (k == 0) return head;

    // temp is now at last node
    temp->next = head; // make it circular

    // Move to the new tail: k nodes from head
    Node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL; // break the circle

    return newHead;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Original list: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions: ";
    printList(head);

    return 0;
}