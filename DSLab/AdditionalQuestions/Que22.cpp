#include <iostream>
using namespace std;

class NodeDLL {
public:
    int data;
    NodeDLL* next;
    NodeDLL* prev;
    NodeDLL(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    NodeDLL* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void append(int x) {
        NodeDLL* newNode = new NodeDLL(x);
        if (!head) {
            head = newNode;
            return;
        }
        NodeDLL* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    NodeDLL* reverseInGroups(NodeDLL* node, int k) {
        NodeDLL* curr = node;
        NodeDLL* newHead = nullptr;
        NodeDLL* groupPrev = nullptr;

        while (curr) {
            NodeDLL* groupStart = curr;
            NodeDLL* prev = nullptr;
            int count = 0;

            // Reverse k nodes
            while (curr && count < k) {
                NodeDLL* nextNode = curr->next;
                curr->next = prev;
                curr->prev = nextNode; // swap prev and next
                prev = curr;
                curr = nextNode;
                count++;
            }

            if (!newHead) newHead = prev; // new head of entire list

            if (groupPrev) {
                groupPrev->next = prev;
                prev->prev = groupPrev;
            }

            groupPrev = groupStart;
        }

        return newHead;
    }

    void reverseInGroups(int k) {
        head = reverseInGroups(head, k);
    }

    void display() {
        NodeDLL* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

// ------------------- MAIN -------------------
int main() {
    DoublyLinkedList dll;

    // Example: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.append(6);

    int k;
    cout << "Enter group size k: ";
    cin >> k;

    cout << "Original DLL: ";
    dll.display();

    dll.reverseInGroups(k);

    cout << "DLL after reversing in groups of " << k << ": ";
    dll.display();

    return 0;
}