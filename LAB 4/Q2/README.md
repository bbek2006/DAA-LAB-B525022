## Problem

Given two sets **S1** and **S2** (each of size *n*) and a number **x**, determine whether there exists a pair:

```
a ∈ S1, b ∈ S2 such that a + b = x
```

---

## Approach

A brute-force solution checks all pairs in **O(n²)** time.
This can be optimized using **sorting + binary search**.

### Steps

1. Sort one set (choose S2).
2. For each element `a` in S1:

   * Compute `target = x - a`
   * Search for `target` in S2 using binary search

---

## Algorithm

* Sort S2 → **O(n log n)**
* For each element in S1:

  * Binary search in S2 → **O(log n)**

Total:

```
O(n log n)
```

---

## Complexity

| Metric           | Value      |
| ---------------- | ---------- |
| Time Complexity  | O(n log n) |
| Space Complexity | O(1)       |

---

## Example

### Input

```
S1 = {1, 4, 5, 7}
S2 = {2, 3, 6, 8}
x = 10
```

### Output

```
Pair exists
```

### Explanation

```
4 (from S1) + 6 (from S2) = 10
```

---

## Alternative Method (Two-Pointer)

If both arrays are sorted:

1. Sort S1 and S2

2. Initialize:

   * i = 0 (start of S1)
   * j = n - 1 (end of S2)

3. While i < n and j >= 0:

   * If S1[i] + S2[j] == x → found
   * If sum < x → i++
   * If sum > x → j--

Time: **O(n log n)** (due to sorting)

---

## Conclusion

The problem is efficiently solved using:

* Sorting + Binary Search
* Avoiding quadratic comparisons

This approach ensures scalability for large inputs.
