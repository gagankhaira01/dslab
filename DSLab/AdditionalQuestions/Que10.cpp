#include <iostream>
#include <vector>
using namespace std;

bool canBeSortedUsingStack(vector<int> A) {
    vector<int> S; // stack
    int expected = 1; // assume array elements are 1..N
    int N = A.size();
    int i = 0;

    while (i < N || !S.empty()) {
        if (!S.empty() && S.back() == expected) {
            S.pop_back();
            expected++;
        } else if (i < N) {
            S.push_back(A[i]);
            i++;
        } else {
            // cannot pop expected from stack
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter elements of array A: ";
    for (int i = 0; i < N; i++)
        cin >> A[i];

    if (canBeSortedUsingStack(A))
        cout << "It is possible to sort array B in ascending order.\n";
    else
        cout << "It is NOT possible to sort array B in ascending order.\n";

    return 0;
}