# WEEK 1 – Question 1: Put Them in Order

## Objective

Determine the increasing order of growth of the given functions for sufficiently large values of \(n\) and verify the result graphically.

---

## Functions Considered

- \( \frac{1}{n} \)
- \( \log_2 n \)
- \( 12\sqrt{n} \)
- \( 50n^{0.5} \)
- \( n^{0.51} \)
- \( 2^{32}n \)
- \( n\log_2 n \)
- \( 100n^2 + 6n \)
- \( n^2 - 324 \)
- \( 2n^3 \)
- \( n^{\log_2 n} \)
- \( 3^n \)

---

## Implementation

The program `growth.c` evaluates the above functions for

```
n = 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
```

To make functions with vastly different growth rates comparable, the program computes

\[
\log_2(f(n))
\]

instead of the raw function values.

The computed values are stored in `growth.csv`.

---

## Graphs

The data in `growth.csv` was imported into Microsoft Excel to generate the graphs.

Since some functions (particularly \(3^n\) and \(n^{\log_2 n}\)) grow much faster than the others, displaying all functions on a single graph makes the remaining curves difficult to observe.

Therefore, the functions have been divided into **four graphs** for improved readability. All four graphs are generated from the same dataset and together represent all the given functions.

---

## Files

| File | Description |
|------|-------------|
| `growth.c` | C program used to generate the data |
| `growth.csv` | Generated data for plotting |
| `graphs.png` | Combined image containing the four graphs |
| `README.md` | Documentation for Question 1 |

---

## Final Order of Growth

\[
\frac1n
<
\log_2 n
<
12\sqrt n
=
50n^{0.5}
<
n^{0.51}
<
2^{32}n
<
n\log_2 n
<
100n^2+6n
=
n^2-324
<
2n^3
<
n^{\log_2 n}
<
3^n
\]

---

## Observations

- Constant multipliers do not affect asymptotic growth.
- Lower-order terms are ignored for sufficiently large values of \(n\).
- The generated graphs visually confirm the theoretical ordering of the functions.
