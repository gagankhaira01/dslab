#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    {
        if (front == -1 || front > rear)
        {
            return 1;
        }
        else
        {
            return -1;
        }
        
    }

    bool isFull() 
    {
        if (rear == SIZE - 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    void enqueue(int x) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow Cannot insert " << x << endl;
            return;
        }

        if (front == -1) 
        {
            front = 0;
        } 

        arr[++rear] = x;
        cout << x << " enqueued into queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow Cannot dequeue." << endl;
            return;
        }

        cout << arr[front] << " dequeued from queue." << endl;
        front++;
    }

    void peek() 
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() 
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "--- Queue Menu ---";
        cout << "1. Enqueue " << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}