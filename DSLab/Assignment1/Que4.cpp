#include <iostream>
using namespace std;
void reverseArray() {
    int n;
    cout << "\nEnter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void matrixMultiplication() {
    int m, n, p;
    cout << "\nEnter rows and columns of Matrix A: ";
    cin >> m >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;
    int A[m][n], B[n][p], C[m][p];
    cout << "Enter Matrix A elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "Enter Matrix B elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Resultant Matrix C:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}
void transposeMatrix() {
    int r, c;
    cout << "\nEnter rows and columns of matrix: ";
    cin >> r >> c;
    int A[r][c], T[c][r];
    cout << "Enter Matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }
    cout << "Transpose Matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: reverseArray(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: return 0;
            default: cout << "Invalid Choice!\n";
        }
    }
}
