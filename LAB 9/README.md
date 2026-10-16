# DAA Lab 09 — Greedy Algorithms (C)

This repository contains C source files and notes for the questions in the supplied Lab-09 PDF.

## Contents

| Question | File | Method / status |
|---|---|---|
| 1. Fractional Knapsack with Deterioration Rate | `01_fractional_knapsack_deterioration.c` | Time-dependent greedy heuristic; modeling ambiguity is documented |
| 2. Huffman Coding | `02_huffman_canonical.c` | Huffman tree + canonical codes |
| 3. Minimum Initial Fuel | `03_minimum_initial_fuel.c` | Max-heap reverse greedy |
| 4. Minimum Cost to Connect Sticks | `04_minimum_cost_connect_sticks.c` | Min-heap |
| 5. Candy Distribution | `05_candy_distribution.c` | Two directional passes |
| 6. Reorganize String with K-Distance Apart | `06_reorganize_string_k_distance.c` | Greedy frequency selection with cooldown |
| 7. Minimize Deviation in Array | `07_minimize_array_deviation.c` | Repeatedly halve current maximum |
| 8. Minimum Meeting Rooms | `08_minimum_meeting_rooms.c` | Sort start/end times |
| 9. Hu-Tucker Greedy Simulation | `09_hu_tucker_notes.c` | Candidate cost validator, **not** the full Hu-Tucker optimizer |
| 10. Greedy Superstring Conjecture | `10_greedy_superstring_notes.md` | Research notes; handout labels this an open problem |

## Compile

Compile each C file independently with GCC, for example:

```bash
gcc -std=c11 -Wall -Wextra -O2 04_minimum_cost_connect_sticks.c -o sticks
./sticks
```

Windows / MinGW uses the same compile command; run the generated `.exe` file.

## Input formats and examples

### Q1 — Deteriorating fractional knapsack
Input:
```text
3 50
60 10 0.01
100 20 0.02
120 30 0.005
```
Each item row is `value weight decay_rate`.

**Important:** the prompt does not specify exactly how time evolves during consumption. Q1 assumes time equals cumulative weight already consumed and evaluates density at the start of each selected item. This is a heuristic, not a proof of globally optimal scheduling under every possible interpretation.

### Q2 — Canonical Huffman coding
Input:
```text
4
a 5
b 9
c 12
d 13
```
Each row is a single-character symbol and its frequency. Symbols must be unique. Codes are output in canonical order (increasing length, then symbol).

### Q3 — Minimum fuel stops
Input:
```text
100 25 4
10 60
20 30
50 40
70 50
```
First line is `target_distance initial_fuel station_count`; each station is `distance fuel_added`. Output `-1` if unreachable.

### Q4 — Connect sticks
Input:
```text
4
1 2 3 4
```
Output is the minimum total joining cost.

### Q5 — Candy distribution
Input:
```text
3
1 2 2
```
Outputs total candies and a valid per-child allocation.

### Q6 — Reorganize string
Input:
```text
aabbcc 3
```
Prints a valid arrangement, or an empty line if the greedy construction cannot place a character. `K` is interpreted as a minimum positional distance.

### Q7 — Minimize array deviation
Input:
```text
4
1 2 3 4
```
Input values must be positive integers.

### Q8 — Meeting rooms
Input:
```text
3
0 30
5 10
15 20
```
A meeting ending exactly when another starts can reuse the room.

### Q9 — Hu-Tucker
Input:
```text
3
5 2
2 1
7 2
```
This validates the weighted path length of supplied `(weight, depth)` pairs. It does not construct an optimal alphabetic tree. Do not submit it as a full Hu-Tucker solution without completing that algorithm.

## Complexity summary

- Q1: `O(n^2)` time, `O(n)` space for the implemented greedy heuristic.
- Q2: `O(n log n)` time for Huffman construction plus canonical sorting; `O(n)` space, excluding fixed-size character alphabet.
- Q3: `O(n log n)` time, `O(n)` space.
- Q4: `O(n log n)` time, `O(n)` space.
- Q5: `O(n)` time, `O(n)` space.
- Q6: `O(L * 256)` time, `O(L + 256)` space, where `L` is string length.
- Q7: scan-based implementation; `O(nR)` time where `R` is the number of maximum-halving steps, `O(n)` space.
- Q8: `O(n log n)` time, `O(n)` space.
- Q9: `O(n)` time for evaluating supplied depths, `O(1)` auxiliary space.
