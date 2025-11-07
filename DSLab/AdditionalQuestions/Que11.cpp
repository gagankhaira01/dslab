#include <iostream>
#include <cstring>
using namespace std;

void generateBinaryNumbers(int n) {
    int front = 0, rear = 0;
    char q[n * 32][32]; // 2D char array to store binary strings
    char temp[32];

    // Initialize queue with "1"
    strcpy(q[rear++], "1");

    for (int i = 1; i <= n; i++) {
        // Dequeue
        strcpy(temp, q[front++]);

        cout << temp << " ";

        // Enqueue temp + "0"
        strcpy(q[rear], temp);
        strcat(q[rear], "0");
        rear++;

        // Enqueue temp + "1"
        strcpy(q[rear], temp);
        strcat(q[rear], "1");
        rear++;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);

    return 0;
}