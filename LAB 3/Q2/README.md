# DAA Lab – Week 3

## Question 2: Defective Coin Problem (Divide and Conquer)

### Objective

To design and implement a divide-and-conquer algorithm to identify a defective coin (lighter coin) from a set of coins using a balance weighing technique. The algorithm should also correctly report if no defective coin exists.

---

### Problem Description

You are given **n coins**, where:

* All coins have identical weight except possibly one.
* The defective coin (if present) is **lighter** than the others.
* It is also possible that **no defective coin exists**.

Using a balance scale, determine:

* The index of the defective coin, or
* Report that all coins are equal.

---

### Approach

The solution uses a **divide-and-conquer strategy**:

1. Divide the coins into two equal halves.
2. Compare the two halves using a simulated weighing function.
3. Based on comparison:

   * If both halves are equal → no defective coin.
   * If one side is lighter → recurse into that half.
4. Continue until only one coin remains.

For odd number of coins:

* Leave one coin aside.
* Compare remaining coins.
* If equal → check leftover coin.

---

### Algorithm

* Recursively divide the problem into halves.
* Use a weighing function to compare subarrays.
* Reduce problem size by half in each step.

---

### Time Complexity

[
T(n) = T(n/2) + O(1)
]

[
T(n) = O(\log_2 n)
]

Thus, the algorithm satisfies the required complexity:
[
\log_2 n + c
]

---

### Implementation Details

* Language used: **C**
* Weighing is simulated by summing weights of groups.
* Input: Number of coins and their weights.
* Output: Index of defective coin or message if none exists.

---

### Sample Input

```
5
10 10 9 10 10
```

### Sample Output

```
Defective coin found at index 2
```

---

### Conclusion

This experiment demonstrates how divide-and-conquer reduces the problem size efficiently. By eliminating half of the coins in each step, the defective coin can be found in logarithmic time, making the algorithm highly efficient compared to linear search.

---

### Learning Outcome

* Understanding of divide-and-conquer paradigm
* Application of binary search–like strategy in real problems
* Optimization using logarithmic time complexity

