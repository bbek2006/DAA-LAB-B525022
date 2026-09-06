#include <stdio.h>
#include <math.h>

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// (i) Max
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// (ii) First & Second max
void firstSecondMax(int arr[], int n) {
    int first = -1e9, second = -1e9;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    printf("First max: %d, Second max: %d\n", first, second);
}

// (iii) Mean
double mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// (v) Standard deviation
double stdDev(int arr[], int n) {
    double m = mean(arr, n), sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] - m) * (arr[i] - m);
    return sqrt(sum / n);
}

// (viii) Reverse
void reverse(int arr[], int n) {
    for (int i = 0; i < n / 2; i++)
        swap(&arr[i], &arr[n - i - 1]);
}

// (ix) Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {  // as per question condition
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// (iv) Median via simple sort (for demo)
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// (vi) Mode (naive)
int mode(int arr[], int n) {
    int maxCount = 0, mode = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i+1; j < n; j++)
            if (arr[j] == arr[i])
                count++;
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

// (vii) Remove duplicates (naive)
int removeDuplicates(int arr[], int n) {
    int temp[n], k = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < k; j++)
            if (arr[i] == temp[j])
                found = 1;
        if (!found)
            temp[k++] = arr[i];
    }
    for (int i = 0; i < k; i++)
        arr[i] = temp[i];
    return k;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Max: %d\n", findMax(arr, n));
    firstSecondMax(arr, n);
    printf("Mean: %.2f\n", mean(arr, n));
    printf("Std Dev: %.2f\n", stdDev(arr, n));

    printf("Mode: %d\n", mode(arr, n));

    int newSize = removeDuplicates(arr, n);
    printf("After removing duplicates:\n");
    for (int i = 0; i < newSize; i++)
        printf("%d ", arr[i]);

    printf("\nReversed array:\n");
    reverse(arr, newSize);
    for (int i = 0; i < newSize; i++)
        printf("%d ", arr[i]);

    printf("\n");

    // Median
    sort(arr, newSize);
    printf("Median: %d\n", arr[newSize / 2]);

    // Partition
    partition(arr, 0, newSize - 1);
    printf("After partition:\n");
    for (int i = 0; i < newSize; i++)
        printf("%d ", arr[i]);

    return 0;
}
