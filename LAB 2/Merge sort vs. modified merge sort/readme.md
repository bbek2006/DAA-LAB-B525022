# WEEK 2 – Question 2  
## Merge Sort vs Modified Merge Sort

---

## Objective

To compare the performance of standard merge sort and a modified merge sort that divides the array into three parts, and to analyze their time complexity using graphs.

---

## Theory

### Standard Merge Sort

Recurrence:
\[
T(n) = 2T(n/2) + O(n)
\]

\[
T(n) = O(n \log n)
\]

---

### Modified Merge Sort (3-way split)

Recurrence:
\[
T(n) = 3T(n/3) + O(n)
\]

Using Master Theorem:
\[
T(n) = O(n \log n)
\]

---

## Implementation

The program `merge_compare.c`:

- Generates random arrays
- Runs:
  - Standard merge sort
  - Modified 3-way merge sort
- Counts number of comparisons
- Writes results to:

```
merge_compare.csv
```

---

## Graph

The CSV file was imported into **Microsoft Excel** to generate the graph.

![Merge Sort Comparison](merge_compare.png)

---

## Observation

- Both algorithms grow at similar rates.
- Modified merge sort performs **more comparisons** than standard merge sort.
- The difference is due to:
  - More complex merging in 3-way merge.

---

## Conclusion

- Both algorithms have the same asymptotic complexity:

\[
O(n \log n)
\]

- However, the modified merge sort has higher constant factors and is less efficient in practice.

---

## Files

| File | Description |
|------|-------------|
| `merge_compare.c` | Implementation |
| `merge_compare.csv` | Data for graph |
| `merge_compare.png` | Graph plotted using Excel |
| `Merge_Sort_Analysis.md` | Documentation |

---

## Note

The comparison is based on **number of comparisons**, not execution time, to accurately reflect asymptotic behavior.
