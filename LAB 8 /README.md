# DAA Lab-08 — Dynamic Programming

**Course:** Design and Analysis of Algorithms (DAA)  
**Lab:** 08  
**Semester:** 3rd  
**Instructor:** Dr. Ajaya Kumar Dash  
**Date:** September 29, 2026

This repository contains C implementations of all 9 questions from DAA Lab-08.

## Problems

| File | Problem | Technique | Time Complexity | Space Complexity |
|---|---|---|---|---|
| `Q1_minimum_coin_change.c` | Minimum Coin Change | Dynamic Programming | O(nV) | O(V) |
| `Q2_coin_change_ways.c` | Coin Change — Total Ways | Dynamic Programming | O(nV) | O(V) |
| `Q3_lcs.c` | Longest Common Subsequence | Dynamic Programming | O(mn) | O(mn) |
| `Q4_lis.c` | Longest Increasing Subsequence | Dynamic Programming | O(n²) | O(n) |
| `Q5_msis.c` | Maximum Sum Increasing Subsequence | Dynamic Programming | O(n²) | O(n) |
| `Q6_edit_distance.c` | Edit Distance with Traceback | Dynamic Programming | O(mn) | O(mn) |
| `Q7_rod_cutting.c` | Rod Cutting with Reconstruction | Dynamic Programming | O(n²) | O(n) |
| `Q8_obst.c` | Optimal Binary Search Tree | Dynamic Programming | O(n³) | O(n²) |
| `Q9_collatz.c` | Collatz Conjecture | Iterative Simulation | Depends on trajectory | O(trajectory length) |

## Compilation

```bash
gcc Q1_minimum_coin_change.c -o q1
gcc Q2_coin_change_ways.c -o q2
gcc Q3_lcs.c -o q3
gcc Q4_lis.c -o q4
gcc Q5_msis.c -o q5
gcc Q6_edit_distance.c -o q6
gcc Q7_rod_cutting.c -o q7
gcc Q8_obst.c -o q8
gcc Q9_collatz.c -o q9
```

On Windows:

```bash
gcc Q1_minimum_coin_change.c -o q1.exe
q1.exe
```

## Q1 — Minimum Coin Change

`dp[x]` stores the minimum number of coins required to make amount `x`.

Recurrence:

`dp[x] = min(dp[x], dp[x-coin] + 1)`

If the target cannot be formed, the program prints `-1`.

**Complexity:** O(nV) time, O(V) space.

## Q2 — Coin Change: Total Number of Ways

`dp[x]` stores the number of combinations that form amount `x`.

Coins are processed one at a time so that different orders of the same coins are not counted separately.

**Complexity:** O(nV) time, O(V) space.

## Q3 — Longest Common Subsequence

`dp[i][j]` stores the LCS length of the first `i` characters of X and first `j` characters of Y.

The table is traversed backwards to reconstruct the actual LCS.

**Complexity:** O(mn) time, O(mn) space.

## Q4 — Longest Increasing Subsequence

`dp[i]` stores the length of the longest strictly increasing subsequence ending at index `i`.

**Complexity:** O(n²) time, O(n) space.

## Q5 — Maximum Sum Increasing Subsequence

`dp[i]` stores the maximum sum of a strictly increasing subsequence ending at index `i`.

**Complexity:** O(n²) time, O(n) space.

## Q6 — Edit Distance with Traceback

The allowed operations are insertion, deletion and substitution.

`dp[i][j]` stores the minimum operations required to transform the first `i` characters of A into the first `j` characters of B.

The program also prints the traceback operations.

**Complexity:** O(mn) time, O(mn) space.

## Q7 — Rod Cutting with Reconstruction

`dp[i]` stores the maximum revenue obtainable from a rod of length `i`.

A `choice[]` array records the first piece selected, allowing the optimal decomposition to be reconstructed.

**Complexity:** O(n²) time, O(n) space.

## Q8 — Optimal Binary Search Tree

Dynamic programming is used to find the minimum expected search cost using successful probabilities `p` and dummy-key probabilities `q`.

For every interval, every possible key is considered as the root.

**Complexity:** O(n³) time, O(n²) space.

## Q9 — Collatz Conjecture

For a positive integer n:

```text
if n is even:
    n = n / 2
else:
    n = 3*n + 1
```

The trajectory is generated iteratively until 1 is reached.

The program analyzes every starting value in an interval `[a,b]`, records the number of steps and maximum value reached, and checks for unsigned-integer overflow.

The conjecture itself remains unproven.

**Complexity:** For a trajectory of T steps, O(T) time and O(T) space when the trajectory is stored.
