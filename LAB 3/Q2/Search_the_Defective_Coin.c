#include <stdio.h>

// Function to simulate weighing two groups
int weigh(int arr[], int l1, int r1, int l2, int r2) {
    int sum1 = 0, sum2 = 0;

    for (int i = l1; i <= r1; i++)
        sum1 += arr[i];

    for (int i = l2; i <= r2; i++)
        sum2 += arr[i];

    if (sum1 == sum2) return 0;      // equal
    else if (sum1 < sum2) return -1; // left lighter
    else return 1;                   // right lighter
}

// Divide and conquer function
int findDefective(int arr[], int low, int high) {
    if (low == high)
        return low; // single coin

    int n = high - low + 1;
    int mid = low + n / 2 - 1;

    // If odd number of coins, keep one aside
    if (n % 2 != 0) {
        int result = weigh(arr, low, mid, mid + 1, high - 1);

        if (result == 0) {
            // leftover coin might be defective
            if (arr[high] < arr[low])
                return high;
            else
                return -1; // no defective coin
        } 
        else if (result == -1)
            return findDefective(arr, low, mid);
        else
            return findDefective(arr, mid + 1, high - 1);
    } 
    else {
        int result = weigh(arr, low, mid, mid + 1, high);

        if (result == 0)
            return -1; // no defective coin
        else if (result == -1)
            return findDefective(arr, low, mid);
        else
            return findDefective(arr, mid + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter weights of coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = findDefective(arr, 0, n - 1);

    if (result == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin found at index %d (0-based).\n", result);

    return 0;
}