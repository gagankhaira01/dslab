#include <iostream>
using namespace std;

class MinStack {
    long long* arr;
    int topIndex;
    int capacity;
    long long minEle;

public:
    MinStack(int size) {
        capacity = size;
        arr = new long long[capacity];
        topIndex = -1;
    }

    ~MinStack() {
        delete[] arr;
    }

    void push(long long x) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        if (topIndex == -1) { // empty stack
            topIndex++;
            arr[topIndex] = x;
            minEle = x;
        } else if (x >= minEle) {
            arr[++topIndex] = x;
        } else {
            arr[++topIndex] = 2 * x - minEle; // store modified value
            minEle = x;
        }
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack underflow\n";
            return;
        }
        long long topVal = arr[topIndex--];
        if (topVal < minEle) {
            minEle = 2 * minEle - topVal; // restore previous minimum
        }
    }

    long long top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        long long topVal = arr[topIndex];
        return (topVal >= minEle) ? topVal : minEle;
    }

    long long getMin() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }

    bool empty() {
        return topIndex == -1;
    }
};

int main() {
    MinStack s(100); // stack of size 100

    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << endl; // 3
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << endl; // 1
    s.pop();
    cout << "Min: " << s.getMin() << endl; // 2
    s.pop();
    cout << "Top: " << s.top() << endl;    // 5
    cout << "Min: " << s.getMin() << endl; // 3

    return 0;
}
