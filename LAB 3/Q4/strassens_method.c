#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to add two matrices
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void sub(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen multiplication
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    // تقسيم matrices
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, T1, mid);
    add(B11, B22, T2, mid);
    strassen(T1, T2, M1, mid);

    // M2 = (A21 + A22)B11
    add(A21, A22, T1, mid);
    strassen(T1, B11, M2, mid);

    // M3 = A11(B12 - B22)
    sub(B12, B22, T2, mid);
    strassen(A11, T2, M3, mid);

    // M4 = A22(B21 - B11)
    sub(B21, B11, T2, mid);
    strassen(A22, T2, M4, mid);

    // M5 = (A11 + A12)B22
    add(A11, A12, T1, mid);
    strassen(T1, B22, M5, mid);

    // M6 = (A21 - A11)(B11 + B12)
    sub(A21, A11, T1, mid);
    add(B11, B12, T2, mid);
    strassen(T1, T2, M6, mid);

    // M7 = (A12 - A22)(B21 + B22)
    sub(A12, A22, T1, mid);
    add(B21, B22, T2, mid);
    strassen(T1, T2, M7, mid);

    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, T1, mid);
    sub(T1, M5, T2, mid);
    add(T2, M7, C11, mid);

    // C12 = M3 + M5
    add(M3, M5, C12, mid);

    // C21 = M2 + M4
    add(M2, M4, C21, mid);

    // C22 = M1 - M2 + M3 + M6
    sub(M1, M2, T1, mid);
    add(T1, M3, T2, mid);
    add(T2, M6, C22, mid);

    // Combine result
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter size of matrix (n x n, power of 2): ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Result Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}