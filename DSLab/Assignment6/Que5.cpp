#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    SinglyLinkedList sll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        sll.insertEnd(val);
    }

    cout << "Do you want to make it circular? (1-Yes, 0-No): ";
    int choice;
    cin >> choice;
    if (choice == 1) sll.makeCircular();

    if (sll.isCircular())
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}