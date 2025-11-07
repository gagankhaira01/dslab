#include <iostream>
using namespace std;

#define SIZE 256

class Queue {
private:
    char arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(char c) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = c;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    char getFront() {
        if (!isEmpty()) return arr[front];
        return '\0';
    }
};

void firstNonRepeating(string str) {
    int freq[SIZE] = {0};
    Queue q;

    for (char c : str) {
        if (c == ' ') continue;

        freq[(unsigned char)c]++;
        q.enqueue(c);

        while (!q.isEmpty() && freq[(unsigned char)q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);

    cout << "Output: ";
    firstNonRepeating(input);

    return 0;
}