#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* headC = nullptr;
Node* headD = nullptr;

void insertCircular(int val, int pos, int key = 0) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (!headC) {
        headC = newNode;
        newNode->next = headC;
        return;
    }
    Node* temp = headC;
    if (pos == 1) {
        while (temp->next != headC) temp = temp->next;
        newNode->next = headC;
        temp->next = newNode;
        headC = newNode;
    } else if (pos == 2) {
        while (temp->next != headC) temp = temp->next;
        temp->next = newNode;
        newNode->next = headC;
    } else if (pos == 3) {
        do {
            if (temp->data == key) break;
            temp = temp->next;
        } while (temp != headC);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteCircular(int key) {
    if (!headC) return;
    Node *curr = headC, *prev = nullptr;
    do {
        if (curr->data == key) {
            if (curr == headC && curr->next == headC) {
                delete curr;
                headC = nullptr;
                return;
            }
            if (curr == headC) {
                Node* temp = headC;
                while (temp->next != headC) temp = temp->next;
                temp->next = headC->next;
                headC = headC->next;
                delete curr;
                return;
            } else {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != headC);
}

void searchCircular(int key) {
    if (!headC) {
        cout << "List empty\n";
        return;
    }
    Node* temp = headC;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != headC);
    cout << "Not found\n";
}

void displayCircular() {
    if (!headC) {
        cout << "List empty\n";
        return;
    }
    Node* temp = headC;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != headC);
    cout << endl;
}

void insertDoubly(int val, int pos, int key = 0) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (!headD) {
        headD = newNode;
        return;
    }
    if (pos == 1) {
        newNode->next = headD;
        headD->prev = newNode;
        headD = newNode;
    } else if (pos == 2) {
        Node* temp = headD;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    } else if (pos == 3) {
        Node* temp = headD;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteDoubly(int key) {
    if (!headD) return;
    Node* temp = headD;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    else headD = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void searchDoubly(int key) {
    Node* temp = headD;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

void displayDoubly() {
    Node* temp = headD;
    if (!temp) {
        cout << "List empty\n";
        return;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, listType, val, key;
    while (true) {
        cout << "\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Back\n";
        cin >> choice;
        if (choice == 5) continue;

        if (listType == 1) {
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> val;
                cout << "1.First 2.Last 3.After specific node: ";
                int pos; cin >> pos;
                if (pos == 3) {
                    cout << "Enter key: ";
                    cin >> key;
                }
                insertCircular(val, pos, key);
            } else if (choice == 2) {
                cout << "Enter value to delete: ";
                cin >> key;
                deleteCircular(key);
            } else if (choice == 3) {
                cout << "Enter value to search: ";
                cin >> key;
                searchCircular(key);
            } else if (choice == 4) {
                displayCircular();
            }
        }

        else if (listType == 2) {
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> val;
                cout << "1.First 2.Last 3.After specific node: ";
                int pos; cin >> pos;
                if (pos == 3) {
                    cout << "Enter key: ";
                    cin >> key;
                }
                insertDoubly(val, pos, key);
            } else if (choice == 2) {
                cout << "Enter value to delete: ";
                cin >> key;
                deleteDoubly(key);
            } else if (choice == 3) {
                cout << "Enter value to search: ";
                cin >> key;
                searchDoubly(key);
            } else if (choice == 4) {
                displayDoubly();
            }
        }
    }
    return 0;
}