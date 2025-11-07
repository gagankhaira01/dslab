#include <iostream>
using namespace std;

#define SIZE 100

// ================= Queue Class =================
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

    void enqueue(int x) {
        if (rear == SIZE - 1) {
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

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void clear() {
        front = rear = -1;
    }
};

// ================= Stack using Two Queues =================
class StackTwoQ {
private:
    Queue q1, q2;

public:
    void push(int x) {
        // Step 1: enqueue new element in q2
        q2.enqueue(x);

        // Step 2: move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Step 3: swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << q1.dequeue() << endl;
    }

    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top: " << q1.getFront() << endl;
        }
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

// ================= Stack using One Queue =================
class StackOneQ {
private:
    Queue q;

public:
    void push(int x) {
        int sz = q.size();
        q.enqueue(x);

        // Rotate previous elements
        for (int i = 0; i < sz; i++) {
            q.enqueue(q.dequeue());
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << q.dequeue() << endl;
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top: " << q.getFront() << endl;
        }
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

// ================= Main Function =================
int main() {
    cout << "--- Stack using Two Queues ---" << endl;
    StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();   // should be 30
    s1.pop();   // removes 30
    s1.top();   // should be 20

    cout << endl << "--- Stack using One Queue ---" << endl;
    StackOneQ s2;
    s2.push(5);
    s2.push(15);
    s2.push(25);
    s2.top();   // should be 25
    s2.pop();   // removes 25
    s2.top();   // should be 15

    return 0;
}