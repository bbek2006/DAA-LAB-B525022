#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Add matrices
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Standard multiplication (base case small n)
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Divide & Conquer for special matrix
void specialMultiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {

    // Base case
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int C1[MAX][MAX], C2[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    // Extract blocks (only need A1, A2 and B1, B2 due to pattern)
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + mid];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + mid];
        }
    }

    int P1[MAX][MAX], P2[MAX][MAX], P3[MAX][MAX], P4[MAX][MAX];

    // Recursive multiplications
    specialMultiply(A1, B1, P1, mid);
    specialMultiply(A2, B2, P2, mid);
    specialMultiply(A1, B2, P3, mid);
    specialMultiply(A2, B1, P4, mid);

    // C1 = P1 + P2
    add(P1, P2, C1, mid);

    // C2 = P3 + P4
    add(P3, P4, C2, mid);

    // Construct final matrix using symmetry
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C1[i][j];
            C[i][j + mid] = C2[i][j];
            C[i + mid][j] = C2[i][j];
            C[i + mid][j + mid] = C1[i][j];
        }
    }
}

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter n (power of 2): ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    specialMultiply(A, B, C, n);

    printf("Result matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}