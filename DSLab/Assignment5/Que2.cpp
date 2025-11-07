#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

int deleteKeyOccurrences(int key) {
    int count = 0;
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void display() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "List is empty";
        return;
    }
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    int count = deleteKeyOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display();

    return 0;
}