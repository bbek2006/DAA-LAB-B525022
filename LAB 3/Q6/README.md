# DAA Lab – Week 3

## Question 6: Use of Loop Invariants in Sorting (Selection Sort)

### Objective

To understand and implement sorting using **loop invariants**, and to analyze its correctness and time complexity.

---

### Problem Description

Given an array A of n elements, sort the array by repeatedly:

* Finding the smallest element in the unsorted portion
* Swapping it with the first unsorted position

This process continues for the first (n − 1) elements.

---

### Algorithm (Selection Sort)

1. Start from the first element
2. Find the smallest element in the remaining array
3. Swap it with the current position
4. Repeat for the next position

---

### Loop Invariant

At the start of each iteration i:

A[0 ... i−1] contains the i smallest elements in **sorted order**.

---

### Proof of Correctness

**Initialization:**
Before the first iteration, the subarray is empty → trivially sorted

**Maintenance:**
Each iteration places the smallest remaining element at position i
→ Sorted portion grows correctly

**Termination:**
After (n − 1) iterations:

* First (n − 1) elements are sorted
* Last element is automatically in correct position

---

### Why Only (n − 1) Iterations?

After placing (n − 1) elements correctly:

* The last element must be the largest
* Hence already in correct position

---

### Time Complexity

* Worst Case: Θ(n²)
* Best Case: Θ(n²)

No improvement in best case since comparisons are always performed.

---

### Implementation Details

* Language used: C
* In-place sorting algorithm
* Minimum number of swaps: (n − 1)

---

### Sample Input

```text id="p3t7nm"
5
64 25 12 22 11
```

### Sample Output

```text id="d8k1qv"
Sorted array:
11 12 22 25 64
```

---

### Conclusion

Selection sort demonstrates the concept of loop invariants clearly. Although not efficient for large datasets, it is useful for understanding algorithm correctness and basic sorting techniques.

---

### Learning Outcome

* Understanding loop invariants (initialization, maintenance, termination)
* Applying selection sort algorithm
* Analyzing time complexity
* Proving correctness of algorithms

