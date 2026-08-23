#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval*)a;
    Interval *i2 = (Interval*)b;
    return i1->start - i2->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    // Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    result[index] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping
        if (arr[i].start <= result[index].end) {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap
            index++;
            result[index] = arr[i];
        }
    }

    // Print result
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("(%d, %d) ", result[i].start, result[i].end);
    }
    printf("\n");
}

int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {7,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
