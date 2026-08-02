# WEEK 1 – Question 4: Towers of Hanoi (ToH)

## Objective

Simulate the solution to the **Tower of Hanoi (ToH)** problem using C and analyze how the total number of moves required changes with the number of disks.

---

## Method

A recursive solution to the Tower of Hanoi problem is implemented.

For each value of **n** (number of disks), the program recursively solves the problem and counts the total number of moves required.

The experiment is performed for:

```text
n = 1, 2, 3, ..., 20
```

The results are stored in `moves.csv`.

---

## Algorithm

The recursive algorithm follows these steps:

1. Move the top **n − 1** disks from the source rod to the auxiliary rod.
2. Move the largest disk from the source rod to the destination rod.
3. Move the **n − 1** disks from the auxiliary rod to the destination rod.

The recurrence relation is:

```text
T(n) = 2T(n − 1) + 1
```

with the base case:

```text
T(1) = 1
```

---

## Implementation

The program recursively counts the number of moves required to solve the Tower of Hanoi problem without printing every move.

For each value of **n**, the computed number of moves is written to `moves.csv`.

---

## Graph

The generated `moves.csv` file was imported into **Microsoft Excel** to create the graph.

### Number of Moves vs Number of Disks

![Tower of Hanoi Graph](graph%20of%20recurssive%20algorithm.png)

---

## Observations

- The number of moves increases very rapidly as the number of disks increases.
- Each additional disk nearly doubles the number of moves required.
- The plotted graph shows an exponential growth pattern rather than a linear or polynomial trend.
- Even a small increase in the number of disks results in a significant increase in the number of moves.

---

## Conclusion

From the graph, it can be concluded that the Tower of Hanoi algorithm has **exponential time complexity**.

The total number of moves required to solve the problem is:

```text
T(n) = 2ⁿ − 1
```

Therefore, the time complexity of the recursive algorithm is:

```text
O(2ⁿ)
```

This demonstrates that the algorithm becomes impractical for very large values of **n**, as the required number of moves grows exponentially.

---

## Files

| File | Description |
|------|-------------|
| `Towers_of_Hanoi(ToH).c` | C implementation of the recursive Tower of Hanoi algorithm |
| `moves.csv` | Number of moves generated for different values of **n** |
| `graph of recursive algorithm.png` | Graph generated from `moves.csv` using Microsoft Excel |
| `Towers_of_Hanoi(ToH).md` | Documentation for Question 4 |
