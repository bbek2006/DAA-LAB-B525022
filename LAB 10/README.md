# DAA Lab 10 — Graphs and Disjoint Set Union (DSU)

This repository follows the five questions in the supplied Lab-10 PDF: online bipartiteness, dynamic grid islands, maximum-weight components with a size limit, reverse-time vertex deletion, and lexicographically smallest permutation by component swaps.

## Files

1. `01_online_graph_bipartiteness.c`
2. `02_dynamic_islands_grid.c`
3. `03_max_weight_component_size_limit.c`
4. `04_reverse_deletion_dsu.c`
5. `05_lexicographically_smallest_component_permutation.c`

## Compile

Compile each file independently:

```bash
gcc -std=c11 -Wall -Wextra -O2 02_dynamic_islands_grid.c -o islands
./islands
```

## Input formats and sample inputs

### Q1 — Online graph bipartiteness
Input: `V E`, followed by E edges `u v` (vertices are 1-based).
```text
3 3
1 2
2 3
3 1
```
The third edge should be rejected because it creates an odd cycle. This implementation re-checks the entire accepted graph after each candidate edge: O(E(V+E)) worst-case time, O(V+E) space.

### Q2 — Dynamic islands in a grid
Input: `R C K`, followed by K pairs `row column` (1-based).
```text
3 3 4
1 1
1 2
3 3
2 2
```
Outputs the island count after each land addition. Duplicate positions do not increase the count. Time O(K α(RC)), space O(RC).

### Q3 — Maximum weight component with size constraint
Input: `n m K`, then n vertex weights, then m edges.
```text
4 3 2
5 2 8 3
1 2
2 3
3 4
```
After each edge, output the maximum component weight among components of size at most K. This implementation scans DSU roots after every edge: O(m n α(n)) time, O(n) space.

### Q4 — Reverse-time vertex deletion
Input: `n m`, n vertex weights, m edges, then n vertices in deletion order.
```text
4 3
5 2 8 3
1 2
2 3
3 4
2 1 3 4
```
Uses reverse additions and DSU. The code outputs maximum component weight after each forward deletion; after the last deletion, the result is 0. Time O((n+m) α(n)) for the standard reverse-DSU approach, but this implementation scans all edges when adding each vertex, so its actual worst-case time is O(nm + (n+m) α(n)). Space O(n+m).

### Q5 — Lexicographically smallest component permutation
Input: `n m`, permutation A, then m allowed-swap edges.
```text
5 2
5 4 3 2 1
1 3
2 4
```
Values can be permuted freely within each connected component; each component's values are sorted and assigned to its sorted positions. Time O(n² + n log n + m α(n)) in this straightforward implementation, space O(n).

## Complexity summary

| Question | Time complexity | Space |
|---|---:|---:|
| Q1 | O(E(V+E)) | O(V+E) |
| Q2 | O(K α(RC)) | O(RC) |
| Q3 | O(m n α(n)) | O(n) |
| Q4 | O(nm + (n+m) α(n)) | O(n+m) |
| Q5 | O(n² + n log n + m α(n)) | O(n) |

`α(n)` is the inverse Ackermann function, effectively constant for practical input sizes.
