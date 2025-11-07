#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;

    // generate all possible pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            // If absolute difference = k, then increment
            // count by 1
            if (abs(arr[i] - arr[j]) == k) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 4, 1, 4, 5};
    int k = 3;

    cout << countPairs(arr, k);
    return 0;
}