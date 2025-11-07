#include <iostream>
using namespace std;

long long mergeAndCount(double A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int j = 0; j < n2; j++) R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            inv_count += (n1 - i); // count inversions
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    return inv_count;
}

long long mergeSortAndCount(double A[], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        count += mergeSortAndCount(A, left, mid);
        count += mergeSortAndCount(A, mid + 1, right);

        count += mergeAndCount(A, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    double A[n];
    cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++) cin >> A[i];

    long long inversions = mergeSortAndCount(A, 0, n - 1);

    cout << "Number of inversions = " << inversions << endl;
    return 0;
}
