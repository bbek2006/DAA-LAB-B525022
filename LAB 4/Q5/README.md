## Problem

Given a list **I** of *n* intervals:

```
(x₁, y₁), (x₂, y₂), ..., (xₙ, yₙ)
```

merge all **overlapping intervals** and return a simplified list.

### Example

Input:

```
{(1,3), (2,6), (8,10), (7,18)}
```

Output:

```
{(1,6), (7,18)}
```

---

## Key Idea

To efficiently merge intervals:

1. **Sort intervals by starting time**
2. Traverse and merge overlapping intervals

---

## Approach

### Step 1: Sort

Sort intervals based on `start (xᵢ)` → **O(n log n)**

### Step 2: Merge

* Initialize result with first interval
* For each next interval:

  * If overlapping:

    ```
    current.start ≤ last.end
    ```

    → Merge by updating:

    ```
    last.end = max(last.end, current.end)
    ```
  * Else:
    → Add new interval

---

## Algorithm

```
Sort intervals by start

Initialize result list

For each interval:
  If result empty OR no overlap:
      Add interval to result
  Else:
      Merge with last interval
```

---

## Complexity

| Metric           | Value      |
| ---------------- | ---------- |
| Time Complexity  | O(n log n) |
| Space Complexity | O(n)       |

---

## Why This Works

* Sorting ensures intervals are processed in order
* Overlapping intervals become adjacent
* Single pass merging guarantees efficiency

---

## Edge Cases

* No intervals → empty output
* Fully overlapping → one interval
* Non-overlapping → same list
* Nested intervals → merged correctly

---

## Conclusion

Efficient merging using:

* Sorting
* Greedy traversal

Avoids brute-force comparisons and ensures optimal performance.
