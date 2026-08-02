## Sample Test Cases

### Test Case 1

**Input**

```text
Number of elements: 10
Array:
10 25 30 15 8 25 40 18 12 5
```

**Output**

```text
Duplicate elements found.
```

---

### Test Case 2

**Input**

```text
Number of elements: 8
Array:
3 7 12 18 24 30 36 42
```

**Output**

```text
All elements are unique.
```

---

### Test Case 3

**Input**

```text
Number of elements: 6
Array:
5 5 5 5 5 5
```

**Output**

```text
Duplicate elements found.
```

---

## Observation

- Every element is compared with every other element.
- As the number of elements increases, the number of comparisons increases rapidly.
- The generated graph (from `comparisons.csv`) shows a quadratic growth in the number of comparisons.
- For small arrays, the algorithm performs adequately.
- For sufficiently large values of **n**, the execution time becomes noticeably higher.

---

## Conclusion

The implemented method uses a brute-force approach that compares every pair of elements.

Its time complexity is:

```text
O(n²)
```

Therefore, for sufficiently large values of **n**, this method becomes inefficient. More efficient techniques such as **sorting (O(n log n))** or **hashing (O(n))** can be used to detect duplicates in larger datasets.
