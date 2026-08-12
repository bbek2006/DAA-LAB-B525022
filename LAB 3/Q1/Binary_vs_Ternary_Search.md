# Binary vs Ternary Search

## Problem Statement

Given a **sorted array of size ( n )**, implement and compare:

* **Binary Search**
* **Ternary Search**

The objective is to:

1. Search for an element ( x ) in the array.
2. Compare their **time complexities mathematically**.
3. Justify which approach is more efficient.

---

## Algorithms Overview

### 1. Binary Search

Binary search divides the search space into **two equal halves** at each step.

* Choose middle index:
  [
  mid = \frac{low + high}{2}
  ]
* Compare ( x ) with ( A[mid] )
* Eliminate half of the search space

---

### 2. Ternary Search

Ternary search divides the search space into **three parts**.

* Choose two midpoints:
  [
  mid_1 = low + \frac{high - low}{3}, \quad
  mid_2 = high - \frac{high - low}{3}
  ]
* Compare ( x ) with both ( A[mid_1] ) and ( A[mid_2] )
* Reduce search space to one-third

---

## Time Complexity Analysis

### Binary Search

At each step:

* Problem size reduces:
  [
  n \rightarrow \frac{n}{2} \rightarrow \frac{n}{4} \rightarrow \cdots
  ]

After ( k ) steps:
[
\frac{n}{2^k} = 1
]

Solving:
[
2^k = n \Rightarrow k = \log_2 n
]

### Final Complexity:

[
\boxed{T(n) = O(\log_2 n)}
]

---

### Ternary Search

At each step:

* Problem size reduces:
  [
  n \rightarrow \frac{n}{3} \rightarrow \frac{n}{9} \rightarrow \cdots
  ]

After ( k ) steps:
[
\frac{n}{3^k} = 1
]

Solving:
[
3^k = n \Rightarrow k = \log_3 n
]

However, each step involves **2 comparisons**, so:

[
T(n) = 2 \cdot \log_3 n
]

Convert to base 2:

[
\log_3 n = \frac{\log_2 n}{\log_2 3}
]

Thus:
[
T(n) = 2 \cdot \frac{\log_2 n}{\log_2 3}
]

Since:
[
\log_2 3 \approx 1.585
]

[
T(n) \approx \frac{2}{1.585} \log_2 n \approx 1.26 \log_2 n
]

### Final Complexity:

[
\boxed{T(n) \approx 1.26 \log_2 n}
]

---

## Comparison Summary

| Algorithm      | Steps per Iteration | Comparisons per Step | Total Complexity          |
| -------------- | ------------------- | -------------------- | ------------------------- |
| Binary Search  | Divide by 2         | 1                    | ( O(\log_2 n) )           |
| Ternary Search | Divide by 3         | 2                    | ( \approx 1.26 \log_2 n ) |

---

## Key Insight

Even though ternary search reduces the search space faster:

* It performs **more comparisons per iteration**
* This increases the constant factor

[
\text{Binary Search} < \text{Ternary Search in practice}
]

---

## Conclusion

Binary search is more efficient because:

* Fewer comparisons per iteration
* Lower constant factor
* Same asymptotic class but better practical performance

[
\boxed{\text{Binary Search is preferred over Ternary Search for sorted arrays}}
]

---

## How to Run

1. Compile:

   ```bash
   gcc search.c -o search
   ```
2. Run:

   ```bash
   ./search
   ```
3. Input:

   * Size of array
   * Sorted elements
   * Element to search

---

## Notes

* Both algorithms require the array to be **sorted**
* Binary search is the standard approach used in libraries and systems

