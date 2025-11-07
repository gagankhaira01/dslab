#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    bool loopExists = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) return;

    // Find the start of loop
    slow = head;
    Node* prev = NULL; // To keep track of last node in loop
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove loop
    prev->next = NULL;
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
    // Example: Creating looped linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "Linked list after removing loop: ";
    printList(head);

    return 0;
}