#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to find intersection
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return NULL;

    Node* p1 = headA;
    Node* p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1; // either intersection node or NULL
}

int main() {
    Node* newNode;

    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);

    Node* head2 = new Node(10);

    // Common part
    newNode = new Node(15);
    head1->next->next->next = newNode;
    head2->next = newNode;

    newNode->next = new Node(30);

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        cout << "Intersection at node with data = " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
