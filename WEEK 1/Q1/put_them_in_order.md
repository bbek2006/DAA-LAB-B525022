# WEEK 1 – Question 1: Put Them in Order

## Objective

Determine the increasing order of growth of the given functions for sufficiently large values of **n** and verify the result graphically.

---

## Functions Considered

- 1/n
- log₂(n)
- 12√n
- 50√n
- n^0.51
- 2³² × n
- n log₂(n)
- 100n² + 6n
- n² − 324
- 2n³
- n^(log₂ n)
- 3ⁿ

---

## Implementation

The program `growth.c` evaluates the above functions for the following values of **n**:

```text
2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
```

Instead of plotting the raw function values, the program computes **log₂(f(n))** for every function. Using logarithmic values compresses the scale, making functions with vastly different growth rates easier to compare visually.

The computed values are written to `growth.csv`.

---

## Graphs

The generated `growth.csv` file was imported into Microsoft Excel to create the graphs.

Since some functions (especially **3ⁿ** and **n^(log₂ n)**) grow much faster than the others, plotting all functions on a single graph makes the smaller-growth functions difficult to distinguish.

To improve readability, the functions have been divided into **four separate graphs**. These graphs are then combined into a **single image** (`graphs.png`) so that all functions can be viewed together while remaining clearly visible.

---

## Files

| File | Description |
|------|-------------|
| `growth.c` | C program that generates the dataset |
| `growth.csv` | Generated data used for plotting |
| `graphs.png` | Combined image containing the four graphs |
| `README.md` | Documentation for Question 1 |

---

## Final Order of Growth

```text
1/n
<
log₂(n)
<
12√n = 50√n
<
n^0.51
<
2³² × n
<
n log₂(n)
<
100n² + 6n = n² − 324
<
2n³
<
n^(log₂ n)
<
3ⁿ
```

---

## Observations

- Constant multipliers do not affect asymptotic growth.
- Lower-order terms do not affect the asymptotic order for sufficiently large values of **n**.
- The generated graphs visually support the theoretical ordering of the functions.

---

## Repository Structure

```text
Q1/
├── Picture1.png
├── Picture2.png
├── Picture3.png
├── growth.csv
├── put_them_in_order.c
└── put_them_in_order.md
```
