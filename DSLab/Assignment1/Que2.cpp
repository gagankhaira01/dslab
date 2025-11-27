#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100], uniqueArr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int uniqueSize = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueSize; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr[uniqueSize] = arr[i];
            uniqueSize++;
        }
    }
    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < uniqueSize; i++)
        cout << uniqueArr[i] << " ";
    return 0;
}
