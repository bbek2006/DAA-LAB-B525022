## Overview

This project demonstrates an **O(n) algorithm** to sort a list of items based on color while preserving the original order of numbers within each color group.

Each item consists of:

* A **number** (already sorted in ascending order)
* A **color**: Red (R), Blue (B), or Yellow (Y)

### Goal

Reorder items such that:

```
All Reds → All Blues → All Yellows
```

while maintaining the **relative order of numbers within each color** (stable sorting).

---

## Key Idea

Since the input is already sorted by number, we avoid re-sorting. Instead:

1. Traverse the array once.
2. Group items into three separate arrays (R, B, Y).
3. Merge them back in order: **R → B → Y**

This ensures:

* **Linear time complexity: O(n)**
* **Stability preserved**

---

## Algorithm

1. Initialize three arrays:

   * `R[]` for Red
   * `B[]` for Blue
   * `Y[]` for Yellow

2. Traverse the input:

   * If color = 'R' → add to `R`
   * If color = 'B' → add to `B`
   * Else → add to `Y`

3. Concatenate:

   * Copy `R`, then `B`, then `Y` back into original array

---

## Time & Space Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(n)  |

---

## C Implementation

```c
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

    for (int i = 0; i < n; i++) {
        if (A[i].color == 'R')
            R[r++] = A[i];
        else if (A[i].color == 'B')
            B[b++] = A[i];
        else
            Y[y++] = A[i];
    }

    int k = 0;
    for (int i = 0; i < r; i++) A[k++] = R[i];
    for (int i = 0; i < b; i++) A[k++] = B[i];
    for (int i = 0; i < y; i++) A[k++] = Y[i];

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
```

---

## Example

### Input

```
(1,B) (2,R) (3,Y) (4,R) (5,B) (6,Y) (7,R)
```

### Output

```
(2,R) (4,R) (7,R) (1,B) (5,B) (3,Y) (6,Y)
```

---

## Why This Works

* The input is already sorted by number.
* We **do not change order within groups**, only regroup them.
* Appending in traversal order guarantees **stability**.

---

## Possible Improvements

* Reduce space usage using **in-place partitioning** (more complex).
* Generalize to **k colors using counting-sort style indexing**.

---

## Conclusion

This approach efficiently solves the problem using:

* One pass
* No comparisons
* Guaranteed stability

It is optimal for this constraint set.

