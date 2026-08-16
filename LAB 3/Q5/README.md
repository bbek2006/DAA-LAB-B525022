# DAA Lab – Week 3

## Question 5: Special Pattern Matrix Multiplication using Divide and Conquer

### Objective

To design and implement a divide-and-conquer algorithm to multiply two special structured matrices of size n x n efficiently in O(n²) time.

---

### Problem Description

You are given two square matrices of size n x n, where:

* n = 2^k (for some natural number k)
* Each matrix follows a **special recursive structure**:

When divided into four equal blocks:

```
M = | M1  M2 |
    | M2  M1 |
```

Where:

* Diagonal blocks are identical (M1)
* Off-diagonal blocks are identical (M2)

This pattern continues recursively until single elements.

---

### Key Insight

Instead of performing standard matrix multiplication (O(n³)), we exploit the structure:

Let:

```
A = | A1  A2 |
    | A2  A1 |

B = | B1  B2 |
    | B2  B1 |
```

Then:

```
C = A × B = | C1  C2 |
            | C2  C1 |
```

Where:

```
C1 = A1·B1 + A2·B2  
C2 = A1·B2 + A2·B1  
```

---

### Approach

1. Divide matrices into submatrices (A1, A2, B1, B2)
2. Recursively compute:

   * A1 × B1
   * A2 × B2
   * A1 × B2
   * A2 × B1
3. Combine results:

   * C1 = A1B1 + A2B2
   * C2 = A1B2 + A2B1
4. Construct final matrix using symmetry

---

### Time Complexity

Recurrence:

```
T(n) = 4T(n/2) + O(n²)
```

Solving:

```
T(n) = O(n²)
```

This is significantly better than naive O(n³).

---

### Implementation Details

* Language used: C
* Recursive divide-and-conquer approach
* Uses matrix addition and multiplication functions
* Exploits symmetry to reduce computation

---

### Sample Input

```text
2
1 2
2 1

3 4
4 3
```

### Sample Output

```text
11 10
10 11
```

---

### Advantages

* Reduces time complexity from O(n³) to O(n²)
* Efficient for structured matrices
* Demonstrates optimization using mathematical properties

---

### Limitations

* Works only for matrices with this specific recursive structure
* Requires n to be a power of 2

---

### Conclusion

By exploiting the recursive symmetry of the matrix structure, the multiplication can be performed in O(n²) time. This demonstrates how recognizing patterns in input data can significantly optimize algorithm performance.

---

### Learning Outcome

* Understanding structured matrix optimization
* Applying divide-and-conquer beyond standard problems
* Reducing time complexity using mathematical properties
* Designing efficient recursive algorithms

