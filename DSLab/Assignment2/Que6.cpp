#include<iostream>

using namespace std;

// 6) Write a program to implement the following operations on a Sparse Matrix,
// assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices

int main()
{
    
    int sp_mat[7][3] = 
    {
        {6, 3, 6},
        {0, 2, 3},  
        {0, 4, 4},
        {1, 2, 5},
        {1, 3, 7},
        {3, 1, 2},
        {3, 2, 6}
    };

    int non_zero_elem = sp_mat[0][2];

    const int row_count = sp_mat[0][0] ;
    const int column_count = sp_mat[0][1];


    // (a) Transpose of the sparse matrix //


    for(int i = 1; i <= row_count; i++)
    {

        int temp = sp_mat[i][0];
        sp_mat[i][0] = sp_mat[i][1];
        sp_mat[i][1] = temp;
        
    }


    for (int i =0; i < row_count + 1; i++)
    {
        for (int j=0; j<column_count; j++)
        {
            cout << " " << sp_mat[i][j];
        }

        cout << endl;
    }

    // (b) Addition of two matrices //


    int sp1[10][3] = {
        {3, 3, 3},   
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 3}
    };

    int sp2[10][3] = {
        {3, 3, 3},
        {0, 0, 2},
        {1, 0, 7},
        {2, 2, 6}
    };

    int row_count1 = sp1[0][2] + 1; 
    int row_count2 = sp2[0][2] + 1;

    int add_sp[20][3];
    add_sp[0][0] = sp1[0][0]; 
    add_sp[0][1] = sp1[0][1]; 
    int k = 1;

    int i = 1, j = 1;
    while (i < row_count1 && j < row_count2) {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1]) {
            add_sp[k][0] = sp1[i][0];
            add_sp[k][1] = sp1[i][1];
            add_sp[k][2] = sp1[i][2] + sp2[j][2];
            i++;
            j++;
        }
        else if (sp1[i][0] < sp2[j][0] || 
                 (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
            add_sp[k][0] = sp1[i][0];
            add_sp[k][1] = sp1[i][1];
            add_sp[k][2] = sp1[i][2];
            i++;
        } 
        else {
           
            add_sp[k][0] = sp2[j][0];
            add_sp[k][1] = sp2[j][1];
            add_sp[k][2] = sp2[j][2];
            j++;
        }
        k++;
    }

    
    while (i < row_count1) {
        add_sp[k][0] = sp1[i][0];
        add_sp[k][1] = sp1[i][1];
        add_sp[k][2] = sp1[i][2];
        i++;
        k++;
    }
    while (j < row_count2) {
        add_sp[k][0] = sp2[j][0];
        add_sp[k][1] = sp2[j][1];
        add_sp[k][2] = sp2[j][2];
        j++;
        k++;
    }

    
    add_sp[0][2] = k - 1;

    
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < 3; y++) {
            cout << add_sp[x][y] << " ";
        }
        cout << endl;
    }
    
    // (c) Multiplication of two sparse matrix

    int A[10][3] = {
        {3, 3, 3}, 
        {0, 0, 2},
        {1, 1, 3},
        {2, 2, 4}
    };

    
    int B[10][3] = {
        {3, 3, 3},
        {0, 1, 5},
        {1, 2, 6},
        {2, 0, 7}
    };

    
    int m = A[0][0], n = A[0][1], nnzA = A[0][2];
    int n2 = B[0][0], p = B[0][1], nnzB = B[0][2];

    if (n != n2) {
        cout << "Matrix multiplication not possible (dimension mismatch)." << endl;
        return 0;
    }

    
    int temp[100][100] = {0};

    for (int i = 1; i <= nnzA; i++) {
        for (int j = 1; j <= nnzB; j++) {
            if (A[i][1] == B[j][0]) { 
                int row = A[i][0];
                int col = B[j][1];
                temp[row][col] += A[i][2] * B[j][2];
            }
        }
    }

    int result[20][3];
    int k = 1; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            if (temp[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = temp[i][j];
                k++;
            }
        }
    }

    result[0][0] = m;
    result[0][1] = p;
    result[0][2] = k - 1;

    for (int i = 0; i <= result[0][2]; i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}