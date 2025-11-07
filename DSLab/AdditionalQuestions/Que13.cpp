#include <iostream>
#include <stack>
using namespace std;

bool canSortQueueUsingStack(int arr[], int n) {
    stack<int> S;
    int expected = 1;
    int i = 0;

    while (i < n || !S.empty()) {
        if (i < n && arr[i] == expected) {
            // Move directly from queue to output
            i++;
            expected++;
        } else if (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        } else if (i < n) {
            S.push(arr[i]);
            i++;
        } else {
            return false; // Cannot place expected element
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements of queue: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (canSortQueueUsingStack(arr, n))
        cout << "Yes, it can be arranged in increasing order.\n";
    else
        cout << "No, it cannot be arranged in increasing order.\n";

    delete[] arr;
    return 0;
}