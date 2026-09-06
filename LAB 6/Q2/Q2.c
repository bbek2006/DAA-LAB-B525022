#include <stdio.h>
#include <math.h>

#define MAX 50

// Input matrix
void input(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
}

// Print matrix
void print(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

// (i) Addition
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// (ii) Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// (iii) Zero matrix check
int isZero(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                return 0;
    return 1;
}

// (iv) Symmetric check
int isSymmetric(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (A[i][j] != A[j][i])
                return 0;
    return 1;
}

// (v) Determinant using Gaussian elimination
double determinant(int A[MAX][MAX], int n) {
    double det = 1;
    int temp[MAX][MAX];

    // copy matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = A[i][j];

    for (int i = 0; i < n; i++) {
        if (temp[i][i] == 0) return 0;

        for (int j = i+1; j < n; j++) {
            double ratio = (double)temp[j][i] / temp[i][i];
            for (int k = 0; k < n; k++)
                temp[j][k] -= ratio * temp[i][k];
        }
        det *= temp[i][i];
    }
    return det;
}

// (vi) Transpose in-place
void transpose(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

// (vii) Eigenvalues (only 2x2 case for demo)
void eigen2x2(int A[MAX][MAX]) {
    int a = A[0][0], b = A[0][1];
    int c = A[1][0], d = A[1][1];

    double trace = a + d;
    double det = a*d - b*c;
    double disc = sqrt(trace*trace - 4*det);

    double lambda1 = (trace + disc)/2;
    double lambda2 = (trace - disc)/2;

    printf("Eigenvalues: %.2f, %.2f\n", lambda1, lambda2);
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter Matrix A:\n");
    input(A, n);

    printf("Enter Matrix B:\n");
    input(B, n);

    // Addition
    add(A, B, C, n);
    printf("\nAddition:\n");
    print(C, n);

    // Multiplication
    multiply(A, B, C, n);
    printf("\nMultiplication:\n");
    print(C, n);

    // Zero check
    printf("\nIs Zero Matrix: %s\n", isZero(A, n) ? "Yes" : "No");

    // Symmetric check
    printf("Is Symmetric: %s\n", isSymmetric(A, n) ? "Yes" : "No");

    // Determinant
    printf("Determinant: %.2f\n", determinant(A, n));

    // Transpose
    transpose(A, n);
    printf("\nTranspose of A:\n");
    print(A, n);

    // Eigen (only if 2x2)
    if (n == 2) {
        eigen2x2(A);
    } else {
        printf("Eigenvalues demo only for 2x2 matrix\n");
    }

    return 0;
}
