#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to interleave queue
void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements" << endl;
        return;
    }

    int half = n / 2;
    int firstHalf[SIZE], secondHalf[SIZE];

    // Store halves
    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }
    for (int i = 0; i < half; i++) {
        secondHalf[i] = q.dequeue();
    }

    // Interleave and enqueue back
    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);
        q.enqueue(secondHalf[i]);
    }
}

int main() {
    Queue q;
    int n, val;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}