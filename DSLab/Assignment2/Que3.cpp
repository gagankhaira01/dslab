#include <iostream>

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n;
}

int findMissingBinary(int arr[], int n) {
    int left = 0;
    int right = n - 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8;
    std::cout << "Missing number (Linear): " << findMissingLinear(arr, n) << std::endl;
    std::cout << "Missing number (Binary): " << findMissingBinary(arr, n) << std::endl;
    return 0;
}
