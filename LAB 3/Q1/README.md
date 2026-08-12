# Binary vs Ternary Search (C)

## Problem Statement

Binary vs Ternary Search: In binary search, an ( n )-element list is divided into nearly two equal halves, while in ternary search, it is divided into nearly three equal intervals. The search is then performed in one of these intervals.

Design and implement a C program to search for an element ( x ) in a sorted list of size ( n ) using both binary and ternary search. Justify and validate that binary search is better than ternary search via your implementation.

---

## Time Complexity Derivation

### Binary Search

Recurrence:

```
T(n) = T(n/2) + 1
```

Expand:

```
T(n) = T(n/2^k) + k
```

Base case:

```
n / 2^k = 1
=> 2^k = n
=> k = log2(n)
```

Final:

```
T(n) = Θ(log2 n)
```

---

### Ternary Search

Recurrence:

```
T(n) = T(n/3) + 2
```

Expand:

```
T(n) = T(n/3^k) + 2k
```

Base case:

```
n / 3^k = 1
=> 3^k = n
=> k = log3(n)
```

Final:

```
T(n) = Θ(2 log3 n)
```

---

### Comparison

Convert to same base:

```
log3(n) = log2(n) / log2(3)
```

So:

```
T(n) ≈ 2 * (log2(n) / 1.585)
     ≈ 1.26 log2(n)
```

---

### Conclusion

```
Binary Search:   Θ(log2 n)
Ternary Search:  ≈ 1.26 log2 n
```

Binary search is faster due to fewer comparisons.

---

## Key Note

* Both algorithms have logarithmic complexity
* Binary search is asymptotically similar but practically faster due to a smaller constant factor
* Binary search is preferred in real-world implementations


