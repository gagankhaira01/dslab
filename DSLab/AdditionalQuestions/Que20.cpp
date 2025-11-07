#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to split a circular linked list into two halves
void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (!head) {
        *head1 = *head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Using slow and fast pointers to find mid
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For even number of nodes, fast->next->next == head
    // For odd number of nodes, fast->next == head
    *head1 = head;
    *head2 = slow->next;

    // Make first half circular
    slow->next = *head1;

    // Make second half circular
    Node* temp = *head2;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = *head2;
}

// Function to print circular linked list
void printCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Creating circular linked list: 10->4->9
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head; // circular

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircularList(head, &head1, &head2);

    cout << "First half: ";
    printCircularList(head1);

    cout << "Second half: ";
    printCircularList(head2);

    return 0;
}