#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = 0; }

    void enqueue(int x) {
        if (rear < MAX) arr[rear++] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }

    bool isEmpty() { return front == rear; }

    int size() { return rear - front; }

    void display() {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void sortQueue(int n) {
        if (n <= 1) return;

        // Find the minimum element in first n elements
        int minVal = arr[front];
        for (int i = 0; i < n; i++) {
            int val = dequeue();
            if (val < minVal) minVal = val;
            enqueue(val);
        }

        // Move all elements except min to rear
        bool minPlaced = false;
        for (int i = 0; i < n; i++) {
            int val = dequeue();
            if (val == minVal && !minPlaced) {
                enqueue(val); // place min at rear
                minPlaced = true;
            } else {
                enqueue(val); // move others to rear
            }
        }

        // Recursively sort first n-1 elements
        sortQueue(n - 1);
    }
};

int main() {
    Queue q;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    q.sortQueue(n);

    cout << "Sorted queue: ";
    q.display();

    return 0;
}