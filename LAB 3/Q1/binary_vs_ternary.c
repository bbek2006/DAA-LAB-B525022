#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Ternary Search Function
int ternarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == x)
            return mid1;
        if (arr[mid2] == x)
            return mid2;

        if (x < arr[mid1])
            high = mid1 - 1;
        else if (x > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int res1 = binarySearch(arr, n, x);
    int res2 = ternarySearch(arr, n, x);

    // Output results
    if (res1 != -1)
        printf("Binary Search: Found at index %d\n", res1);
    else
        printf("Binary Search: Not Found\n");

    if (res2 != -1)
        printf("Ternary Search: Found at index %d\n", res2);
    else
        printf("Ternary Search: Not Found\n");

    return 0;
}