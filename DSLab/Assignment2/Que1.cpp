#include <iostream>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    int target;
    std::cout << "Enter element to search: ";
    std::cin >> target;
    int result = binarySearch(arr, n, target);
    if (result != -1)
        std::cout << "Element found at index " << result << std::endl;
    else
        std::cout << "Element not found" << std::endl;
    return 0;
}
