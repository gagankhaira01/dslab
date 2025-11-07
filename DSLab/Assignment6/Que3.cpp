#include <iostream>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int size() {
        int count = 0;
        DoublyNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularNode {
public:
    int data;
    CircularNode* next;
    CircularNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    CircularNode* head;
public:
    CircularLinkedList() { head = nullptr; }

    void insertEnd(int val) {
        CircularNode* newNode = new CircularNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CircularNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        CircularNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    int n, val;

    DoublyLinkedList dll;
    cout << "Doubly Linked List - Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insertEnd(val);
    }

    CircularLinkedList cll;
    cout << "Circular Linked List - Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insertEnd(val);
    }

    cout << "Size of Doubly Linked List: " << dll.size() << endl;
    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}