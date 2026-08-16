# DAA Lab – Week 3

## Question 4: Matrix Multiplication using Strassen’s Method

### Objective

To implement matrix multiplication using Strassen’s Divide and Conquer algorithm for two square matrices of size n x n.

---

### Problem Description

Given two square matrices A and B of size n x n, compute their product matrix C using an efficient divide-and-conquer approach instead of the conventional method.

---

### Approach

Strassen’s algorithm improves matrix multiplication by reducing the number of multiplications.

Instead of the standard 8 multiplications, it performs only 7 multiplications using optimized matrix combinations.

---

### Method

1. Divide each matrix into 4 submatrices:

   * A11, A12, A21, A22
   * B11, B12, B21, B22

2. Compute the following 7 products:

   * M1 = (A11 + A22)(B11 + B22)
   * M2 = (A21 + A22)(B11)
   * M3 = (A11)(B12 − B22)
   * M4 = (A22)(B21 − B11)
   * M5 = (A11 + A12)(B22)
   * M6 = (A21 − A11)(B11 + B12)
   * M7 = (A12 − A22)(B21 + B22)

3. Compute result submatrices:

   * C11 = M1 + M4 − M5 + M7
   * C12 = M3 + M5
   * C21 = M2 + M4
   * C22 = M1 − M2 + M3 + M6

4. Combine submatrices to form final matrix C

---

### Time Complexity

Recurrence:
T(n) = 7T(n/2) + O(n^2)

Final:
T(n) = O(n^2.81)

This is faster than the conventional method:
O(n^3)

---

### Implementation Details

* Language used: C
* Recursive divide-and-conquer implementation
* Uses helper functions for matrix addition and subtraction
* Works efficiently when n is a power of 2

---

### Sample Input

```text
2
1 2
3 4

5 6
7 8
```

### Sample Output

```text
19 22
43 50
```

---

### Limitations

* Works best when matrix size is a power of 2
* Requires extra memory for submatrices
* Overhead may reduce performance for small matrices

---

### Conclusion

Strassen’s algorithm reduces the number of multiplications required in matrix multiplication, improving asymptotic performance. It is an important application of divide-and-conquer techniques in algorithm design.

---

### Learning Outcome

* Understanding advanced divide-and-conquer algorithms
* Optimizing matrix multiplication
* Analyzing time complexity improvements
* Understanding practical limitations of theoretical algorithms

