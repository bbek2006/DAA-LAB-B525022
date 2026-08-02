#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Optimized Bubble Sort
int bubbleSortOptimized(int arr[], int n) {
    int comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }

    return comparisons;
}

// Standard Bubble Sort
int bubbleSortStandard(int arr[], int n) {
    int comparisons = 0;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return comparisons;
}

int main() {

    srand(time(NULL));

    FILE *fp = fopen("comparisons.csv", "w");

    fprintf(fp, "Size,Optimized,Standard\n");

    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];

    for (int n = 100; n <= 1000; n += 100) {

        // Generate random array
        for (int i = 0; i < n; i++) {
            arr1[i] = rand() % 10000;
            arr2[i] = arr1[i];
        }

        int opt = bubbleSortOptimized(arr1, n);
        int std = bubbleSortStandard(arr2, n);

        fprintf(fp, "%d,%d,%d\n", n, opt, std);

        printf("Size = %4d  Optimized = %6d  Standard = %6d\n",
               n, opt, std);
    }

    fclose(fp);

    printf("\ncomparisons.csv generated successfully.\n");

    return 0;
}