# DAA Lab-07 — Algorithm Application Puzzles

**Course:** Design and Analysis of Algorithms (DAA)  
**Lab:** 07  
**Date:** September 8, 2026  
**Instructor:** Dr. Ajaya Kumar Dash

This repository contains C implementations for all seven questions in DAA Lab-07.

## Questions

| File | Problem | Main technique | Complexity |
|---|---|---|---|
| `Q1_coin_triangle.c` | Invert a coin triangle | Mathematical optimization / transform-and-conquer | O(1) |
| `Q2_super_egg_testing.c` | Super egg testing | Dynamic programming | O(E·F²) time, O(E·F) space |
| `Q3_reves_puzzle.c` | Reve's puzzle | Frame–Stewart DP + recursion | O(n³) DP, output-sensitive move generation |
| `Q4_security_switches.c` | Security switches | Recurrence / decrease-by-one | O(n) to compute count |
| `Q5_moving_target.c` | Hitting a moving target | Greedy / representation transformation | O(n) |
| `Q6_best_time_alive.c` | Best time to be alive | Event sorting / sweep line | O(n log n) |
| `Q7_matrix_chain.c` | Matrix Chain Multiplication | Dynamic programming | O(n³) time, O(n²) space |

> The lab sheet asks for programs in C and complexity analysis for each problem.

---

## Compilation

Using GCC:

```bash
gcc Q1_coin_triangle.c -o q1
gcc Q2_super_egg_testing.c -o q2
gcc Q3_reves_puzzle.c -o q3
gcc Q4_security_switches.c -o q4
gcc Q5_moving_target.c -o q5
gcc Q6_best_time_alive.c -o q6
gcc Q7_matrix_chain.c -o q7
```

Run, for example:

```bash
./q2
```

On Windows with MinGW:

```bash
gcc Q2_super_egg_testing.c -o q2.exe
q2.exe
```

---

# Q1 — Invert the Coin Triangle

If the triangle has `n` rows, it contains

`T(n) = n(n+1)/2`

coins.

The minimum number of coins that have to be moved is:

`floor(T(n)/3) = floor(n(n+1)/6)`

An optimal construction chooses the row

`k ≈ (n+2)/3`

as the base of the inverted triangle. The program reports the minimum number of moves and the best candidate base row.

### Input
```text
n
```

### Example
```text
Input:
4

Output:
Number of rows: 4
Total coins: 10
Optimal base row(s): 2, 3
Minimum number of coin moves: 3
```

For `n = 4`, this is the familiar 10-coin triangle that can be inverted by moving 3 coins.

**Complexity:** O(1) time and O(1) extra space.

---

# Q2 — Super Egg Testing Experiment

Let `dp[e][f]` be the minimum number of drops required with `e` eggs and `f` floors.

If we drop an egg from floor `x`:

- If it breaks, we solve `e-1` eggs and `x-1` floors.
- If it survives, we solve `e` eggs and `f-x` floors.

Therefore:

`dp[e][f] = 1 + min(max(dp[e-1][x-1], dp[e][f-x]))`

for `1 <= x <= f`.

Base cases:

- `dp[e][0] = 0`
- `dp[e][1] = 1`
- `dp[1][f] = f`

For 2 eggs and 100 floors, the answer is 14.

**Complexity:** O(E·F²) time and O(E·F) space.

---

# Q3 — Reve's Puzzle

Reve's puzzle has four pegs. The Frame–Stewart strategy divides the `n` disks into:

- `k` disks handled using four pegs,
- `n-k` disks handled using three pegs,
- then the `k` disks are moved again using four pegs.

The recurrence is:

`H4(n) = min [2H4(k) + H3(n-k)]`

where:

`H3(m) = 2^m - 1`

The program uses dynamic programming to find the best split and recursively prints the moves.

For 8 disks:

`H4(8) = 33`

The optimal split is `k = 4`.

**Complexity:** O(n³) for the simple DP implementation, plus O(M) to print the `M` moves.

---

# Q4 — Security Switches

The switches start as:

`111...111`

and the target is:

`000...000`

The legal-move restriction makes this a recursive state-transition puzzle.

The minimum number of toggles is:

`floor(2^(n+1) / 3)`

Examples:

| n | Minimum moves |
|---:|---:|
| 1 | 1 |
| 2 | 2 |
| 3 | 5 |
| 4 | 10 |
| 5 | 21 |
| 6 | 42 |

The program computes this count using integer arithmetic. For practical values of `n`, it also avoids pretending that the exponentially long move sequence can be printed cheaply.

**Complexity:** O(n) time for the count and O(1) auxiliary space.

---

# Q5 — Hitting a Moving Target

For `n > 2`, use the shot sequence:

`2, 3, 4, ..., n-1, n-1, n-2, ..., 2`

This uses:

`2(n-2)`

shots.

For `n = 2`, shoot at the same spot twice.

The strategy guarantees a hit because the set of positions in which the target can still be located shrinks after each shot.

**Complexity:** O(n) time and O(n) space for storing/printing the sequence.

---

# Q6 — The Best Time to Be Alive

Each scientist contributes two events:

- birth year: `+1`
- death year: `-1`

The problem specifies that if one scientist dies in the same year another is born, the death happens first. Therefore, for equal years, death events are processed before birth events.

After sorting all events by:

1. year ascending
2. death before birth for equal years

we sweep through the events and maintain the current number of living scientists.

The year at which this count is maximum is the answer.

**Complexity:** O(n log n) time for sorting and O(n) space.

### Input format

```text
N
Name1 BirthYear DeathYear
Name2 BirthYear DeathYear
...
```

Names are read as a single word so that the program remains simple.

---

# Q7 — Matrix Chain Multiplication

For matrices:

`A1 A2 ... An`

where matrix `Ai` has dimensions:

`p[i-1] × p[i]`

let:

`dp[i][j]`

be the minimum scalar multiplications needed to compute:

`Ai ... Aj`.

The recurrence is:

`dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]p[k]p[j])`

for:

`i <= k < j`.

The program also stores the best split in `split[i][j]` and recursively prints the optimal parenthesization.

**Complexity:** O(n³) time and O(n²) space.

---

## Notes

- The programs use standard C (`C99`-compatible style).
- Integer limits apply to exponential quantities such as the switch puzzle and number of Hanoi moves.
- Q3 uses the Frame–Stewart recurrence requested for the four-peg Reve's puzzle.
- Q1 reports the mathematical optimum and optimal base-row choice rather than attempting to draw the physical coins in a terminal.

## Source

The problem statements in this repository are based on the uploaded DAA Lab-07 sheet.
