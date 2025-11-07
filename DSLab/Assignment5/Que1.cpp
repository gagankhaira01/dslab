#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

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

void insertBeforeValue(int value, int before) {
    if (head == nullptr) return;
    if (head->data == before) {
        insertAtBeginning(value);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != before)
        temp = temp->next;
    if (temp->next == nullptr) return;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterValue(int value, int after) {
    Node* temp = head;
    while (temp != nullptr && temp->data != after)
        temp = temp->next;
    if (temp == nullptr) return;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecific(int value) {
    if (head == nullptr) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;
    if (temp->next == nullptr) return;
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found" << endl;
}

void display() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value, ref;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter new value and reference value: ";
                cin >> value >> ref;
                insertBeforeValue(value, ref);
                break;
            case 4:
                cout << "Enter new value and reference value: ";
                cin >> value >> ref;
                insertAfterValue(value, ref);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteSpecific(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
