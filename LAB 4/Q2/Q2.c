#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Binary search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return 1;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

// Check if pair exists
int existsPair(int S1[], int S2[], int n, int x) {
    qsort(S2, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        int target = x - S1[i];
        if (binarySearch(S2, n, target))
            return 1;
    }
    return 0;
}

int main() {
    int S1[] = {1, 4, 5, 7};
    int S2[] = {2, 3, 6, 8};
    int n = 4;
    int x = 10;

    if (existsPair(S1, S2, n, x))
        printf("Pair exists\n");
    else
        printf("No such pair\n");

    return 0;
}
