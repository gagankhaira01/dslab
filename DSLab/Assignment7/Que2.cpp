#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
            if (arr[i] > arr[maxIndex]) maxIndex = i;
        }

        // Swap minimum with start
        swap(arr[start], arr[minIndex]);

        // If max was at start, its index has changed after swap
        if (maxIndex == start) maxIndex = minIndex;

        // Swap maximum with end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
