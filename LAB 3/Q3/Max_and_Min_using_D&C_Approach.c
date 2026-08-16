#include <stdio.h>

struct Pair {
    int min;
    int max;
};

// Divide and Conquer function
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // Base case: only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    mid = (low + high) / 2;

    // Conquer
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Pair ans = findMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", ans.min);
    printf("Maximum element: %d\n", ans.max);

    return 0;
}