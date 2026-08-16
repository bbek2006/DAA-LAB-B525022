# DAA Lab – Week 3

## Question 3: Finding Maximum and Minimum using Divide and Conquer

### Objective

To design and implement a divide-and-conquer algorithm to find the maximum and minimum elements in an array such that the number of comparisons is minimized and bounded by:

(3n/2) - 2

---

### Problem Description

Given an array of size n, determine:

* The minimum element
* The maximum element

The goal is to achieve this using fewer comparisons than the naive approach.

---

### Approach

The algorithm uses the divide-and-conquer paradigm:

1. Divide the array into two halves
2. Conquer each half recursively to find their min and max
3. Combine the results:

   * Compare the two minimums → overall minimum
   * Compare the two maximums → overall maximum

---

### Base Cases

* If the array has one element:
  That element is both min and max

* If the array has two elements:
  Compare once and assign min and max

---

### Algorithm Steps

1. If low == high → return that element as both min and max
2. If only two elements:

   * Compare once and assign min and max
3. Otherwise:

   * Divide array into two halves
   * Recursively find min and max in each half
   * Combine results using 2 comparisons

---

### Time Complexity

Recurrence:
T(n) = 2T(n/2) + 2

Final:
T(n) ≤ (3n/2) - 2

---

### Implementation Details

* Language used: C
* Uses a structure to return both min and max
* Recursive divide-and-conquer approach

---

### Sample Input

```
6
3 5 1 8 2 9
```

### Sample Output

```
Minimum element: 1  
Maximum element: 9
```

---

### Comparison with Naive Approach

| Method                 | Number of Comparisons |
| ---------------------- | --------------------- |
| Naive (separate scans) | 2n - 2                |
| Divide & Conquer       | (3n/2) - 2            |

---

### Conclusion

The divide-and-conquer approach reduces the number of comparisons compared to the naive method. By solving smaller subproblems and combining results efficiently, it achieves near-optimal performance.

---

### Learning Outcome

* Understanding divide-and-conquer strategy
* Reducing comparisons in algorithm design
* Applying recursion effectively
* Analyzing time complexity using recurrence relations

