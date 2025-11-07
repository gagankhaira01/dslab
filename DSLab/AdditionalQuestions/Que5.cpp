#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int count = 0;

    // Count how many 2's will be duplicated within array size
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) count++;
    }

    // Start from the end and move elements to their new positions
    for (int i = n - 1; i >= 0; i--) {
        int newPos = i + count;
        if (newPos < n) arr[newPos] = arr[i]; // Copy element to new position

        if (arr[i] == 2) {
            count--;
            newPos = i + count;
            if (newPos < n) arr[newPos] = 2; // Duplicate 2
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
