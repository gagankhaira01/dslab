#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = head;
        while (right->next) 
            right = right->next;

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string str;
    cout << "Enter string: ";
    cin >> str;

    for (char c : str)
        dll.insertEnd(c);

    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}