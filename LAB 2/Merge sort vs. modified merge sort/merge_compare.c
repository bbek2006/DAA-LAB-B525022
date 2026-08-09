#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

long long comp_merge = 0;
long long comp_modified = 0;

/* ================= NORMAL MERGE SORT ================= */

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comp_merge++;  // comparison count

        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* ================= MODIFIED MERGE SORT (3-WAY) ================= */

void merge3(int arr[], int l, int m1, int m2, int r) {

    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;

    int A[n1], B[n2], C[n3];

    for (int i = 0; i < n1; i++) A[i] = arr[l + i];
    for (int i = 0; i < n2; i++) B[i] = arr[m1 + 1 + i];
    for (int i = 0; i < n3; i++) C[i] = arr[m2 + 1 + i];

    int i = 0, j = 0, k = 0, idx = l;

    while (i < n1 && j < n2 && k < n3) {
        comp_modified += 2;  // approx comparisons

        if (A[i] <= B[j] && A[i] <= C[k])
            arr[idx++] = A[i++];
        else if (B[j] <= A[i] && B[j] <= C[k])
            arr[idx++] = B[j++];
        else
            arr[idx++] = C[k++];
    }

    while (i < n1 && j < n2) {
        comp_modified++;
        if (A[i] <= B[j]) arr[idx++] = A[i++];
        else arr[idx++] = B[j++];
    }

    while (j < n2 && k < n3) {
        comp_modified++;
        if (B[j] <= C[k]) arr[idx++] = B[j++];
        else arr[idx++] = C[k++];
    }

    while (i < n1 && k < n3) {
        comp_modified++;
        if (A[i] <= C[k]) arr[idx++] = A[i++];
        else arr[idx++] = C[k++];
    }

    while (i < n1) arr[idx++] = A[i++];
    while (j < n2) arr[idx++] = B[j++];
    while (k < n3) arr[idx++] = C[k++];
}

void mergeSort3(int arr[], int l, int r) {
    if (l < r) {
        int size = r - l + 1;

        int m1 = l + size / 3 - 1;
        int m2 = l + 2 * size / 3 - 1;

        mergeSort3(arr, l, m1);
        mergeSort3(arr, m1 + 1, m2);
        mergeSort3(arr, m2 + 1, r);

        merge3(arr, l, m1, m2, r);
    }
}

/* ================= MAIN ================= */

int main() {

    FILE *fp = fopen("merge_compare.csv", "w");

    if (!fp) {
        printf("Error creating file\n");
        return 1;
    }

    fprintf(fp, "n,MergeSort,ModifiedMergeSort\n");

    srand(time(NULL));

    for (int n = 100; n <= 2000; n += 100) {

        int arr1[MAX], arr2[MAX];

        for (int i = 0; i < n; i++) {
            int val = rand() % 10000;
            arr1[i] = val;
            arr2[i] = val;
        }

        comp_merge = 0;
        comp_modified = 0;

        mergeSort(arr1, 0, n - 1);
        mergeSort3(arr2, 0, n - 1);

        fprintf(fp, "%d,%lld,%lld\n", n, comp_merge, comp_modified);

        printf("n=%d | Merge=%lld | Modified=%lld\n", n, comp_merge, comp_modified);
    }

    fclose(fp);

    printf("\nmerge_compare.csv generated successfully.\n");

    return 0;
}