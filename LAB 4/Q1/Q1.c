#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    char color; // 'R', 'B', 'Y'
} Item;

void sortByColor(Item A[], int n) {
    Item *R = (Item *)malloc(n * sizeof(Item));
    Item *B = (Item *)malloc(n * sizeof(Item));
    Item *Y = (Item *)malloc(n * sizeof(Item));

    int r = 0, b = 0, y = 0;

    // Step 1: Distribute
    for (int i = 0; i < n; i++) {
        if (A[i].color == 'R')
            R[r++] = A[i];
        else if (A[i].color == 'B')
            B[b++] = A[i];
        else
            Y[y++] = A[i];
    }

    // Step 2: Merge back
    int k = 0;
    for (int i = 0; i < r; i++)
        A[k++] = R[i];
    for (int i = 0; i < b; i++)
        A[k++] = B[i];
    for (int i = 0; i < y; i++)
        A[k++] = Y[i];

    free(R);
    free(B);
    free(Y);
}

void printArray(Item A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %c) ", A[i].number, A[i].color);
    }
    printf("\n");
}

int main() {
    Item A[] = {
        {1, 'B'}, {2, 'R'}, {3, 'Y'}, {4, 'R'},
        {5, 'B'}, {6, 'Y'}, {7, 'R'}
    };

    int n = sizeof(A) / sizeof(A[0]);

    printf("Before sorting:\n");
    printArray(A, n);

    sortByColor(A, n);

    printf("After sorting (R -> B -> Y):\n");
    printArray(A, n);

    return 0;
}
