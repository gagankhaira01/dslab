#include <iostream>
using namespace std;

int main() {
    int n, type;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    cout << "Choose matrix type:\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cout << "Enter choice: ";
    cin >> type;

    int size = 0;

    // Determine required size
    if (type == 1) size = n;
    else if (type == 2) size = 3 * n - 2;
    else size = n * (n + 1) / 2;

    int *A = new int[size];
    for (int i = 0; i < size; i++) A[i] = 0;

    cout << "Enter elements of " << n << "x" << n << " matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            if (type == 1 && i == j)
                A[i - 1] = x;

            else if (type == 2 && (i == j || i == j + 1 || i == j - 1)) {
                int k;
                if (i == j) k = n + (i - 2);
                else if (i == j + 1) k = i - 2;
                else k = 2 * n - 1 + (i - 1);
                A[k] = x;
            }

            else if (type == 3 && i >= j)
                A[i * (i - 1) / 2 + (j - 1)] = x;

            else if (type == 4 && i <= j)
                A[j * (j - 1) / 2 + (i - 1)] = x;

            else if (type == 5 && i >= j)
                A[i * (i - 1) / 2 + (j - 1)] = x;

            else if (type == 5 && i < j)
                A[j * (j - 1) / 2 + (i - 1)] = x;
        }
    }

    cout << "\nOptimized Stored Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val = 0;

            if (type == 1 && i == j)
                val = A[i - 1];

            else if (type == 2) {
                if (i == j) val = A[n + (i - 2)];
                else if (i == j + 1) val = A[i - 2];
                else if (i == j - 1) val = A[2 * n - 1 + (i - 1)];
                else val = 0;
            }

            else if (type == 3)
                val = (i >= j) ? A[i * (i - 1) / 2 + (j - 1)] : 0;

            else if (type == 4)
                val = (i <= j) ? A[j * (j - 1) / 2 + (i - 1)] : 0;

            else if (type == 5)
                val = (i >= j) ? A[i * (i - 1) / 2 + (j - 1)] : A[j * (j - 1) / 2 + (i - 1)];

            cout << val << " ";
        }
        cout << endl;
    }

    delete[] A;
    return 0;
}
