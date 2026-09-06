#include <stdio.h>

#define MAX 100

int cost = 0;

// Reverse subarray [i, j]
void reverse(int arr[], int i, int j) {
    int len = j - i + 1;
    cost += len;

    while (i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++; j--;
    }
}

// Find index of value x
int find(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Greedy reversal sort
void reversalSort(int arr[], int n) {
    for (int curr = n; curr >= 1; curr--) {
        int idx = find(arr, n, curr);

        if (idx == curr - 1)
            continue;

        // Bring to front
        if (idx != 0)
            reverse(arr, 0, idx);

        // Move to correct position
        reverse(arr, 0, curr - 1);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter permutation:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    reversalSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal cost: %d\n", cost);

    return 0;
}
