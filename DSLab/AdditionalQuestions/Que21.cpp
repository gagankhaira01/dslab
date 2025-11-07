#include <iostream>
using namespace std;

// ------------------- CIRCULAR SINGLY LINKED LIST -------------------
class NodeCLL {
public:
    int data;
    NodeCLL* next;
    NodeCLL(int x) {
        data = x;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    NodeCLL* head;
public:
    CircularLinkedList() { head = nullptr; }

    void append(int x) {
        NodeCLL* newNode = new NodeCLL(x);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        NodeCLL* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int countOnes(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    void removeEvenParityNodes() {
        if (!head) return;

        NodeCLL* curr = head;
        NodeCLL* prev = nullptr;

        // Handle head nodes with even parity
        while (countOnes(head->data) % 2 == 0) {
            if (head->next == head) { // only one node
                delete head;
                head = nullptr;
                return;
            }
            NodeCLL* last = head;
            while (last->next != head)
                last = last->next;
            NodeCLL* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }

        prev = head;
        curr = head->next;

        while (curr != head) {
            if (countOnes(curr->data) % 2 == 0) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void display() {
        if (!head) return;
        NodeCLL* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// ------------------- DOUBLY LINKED LIST -------------------
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

    int countOnes(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    void removeEvenParityNodes() {
        NodeDLL* curr = head;

        while (curr) {
            NodeDLL* nextNode = curr->next;
            if (countOnes(curr->data) % 2 == 0) {
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next; // head node
                if (curr->next) curr->next->prev = curr->prev;
                delete curr;
            }
            curr = nextNode;
        }
    }

    void display() {
        NodeDLL* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    // Circular Linked List Example: 9 -> 11 -> 34 -> 6 -> 13 -> 21
    CircularLinkedList cll;
    cll.append(9);
    cll.append(11);
    cll.append(34);
    cll.append(6);
    cll.append(13);
    cll.append(21);

    cout << "Original Circular Linked List: ";
    cll.display();

    cll.removeEvenParityNodes();

    cout << "CLL after removing even parity nodes: ";
    cll.display();

    // Doubly Linked List Example: 18 <=> 15 <=> 8 <=> 9 <=> 14
    DoublyLinkedList dll;
    dll.append(18);
    dll.append(15);
    dll.append(8);
    dll.append(9);
    dll.append(14);

    cout << "Original Doubly Linked List: ";
    dll.display();

    dll.removeEvenParityNodes();

    cout << "DLL after removing even parity nodes: ";
    dll.display();

    return 0;
}
