# WEEK 1 – Question 5: Find the Partition Point

## Objective

Given an array consisting of a sequence of 0's followed by a sequence of 1's, determine the exact transition point between them.

---

## Method

Since all 0's appear before all 1's, the array is sorted with respect to the transition.

A **Binary Search** algorithm is used to efficiently locate the first occurrence of `1`, which represents the partition point.

---

## Algorithm

1. Initialize two pointers:
   - `low = 0`
   - `high = n - 1`
2. Find the middle element.
3. If the middle element is `1`, store its index and continue searching in the left half.
4. Otherwise, search the right half.
5. Repeat until the search space becomes empty.
6. The stored index is the partition point.

---

## Complexity Analysis

| Operation | Complexity |
|-----------|-----------:|
| Time Complexity | **O(log n)** |
| Space Complexity | **O(1)** |

---

## Observation

- Binary Search efficiently locates the first occurrence of `1`.
- The algorithm avoids scanning the entire array.
- It is significantly faster than a linear search for large arrays.

---

## Conclusion

Since the array is sorted into two contiguous regions (0's followed by 1's), Binary Search can determine the transition point in **O(log n)** time while using constant extra space.

---

## Files

| File | Description |
|------|-------------|
| `find_partition_point.c` | Binary Search implementation to locate the transition point |
| `find_partition_point.md` | Documentation for Question 5 |
## Sample Test Cases

### Test Case 1

**Input**

```text
11
0 0 0 0 0 0 1 1 1 1 1
```

**Output**

```text
Partition Point = 6
Transition: arr[6] = 1
```

---

### Test Case 2

**Input**

```text
10
0 0 0 0 1 1 1 1 1 1
```

**Output**

```text
Partition Point = 4
Transition: arr[4] = 1
```

---

### Test Case 3

**Input**

```text
6
1 1 1 1 1 1
```

**Output**

```text
Partition Point = 0
Transition: arr[0] = 1
```

---

### Test Case 4

**Input**

```text
6
0 0 0 0 0 0
```

**Output**

```text
The array contains no 1's.
```
