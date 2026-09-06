Title: 2D Matrix Operations and Complexities

Operations Covered:
- Matrix Addition
- Matrix Multiplication
- Zero Matrix Check
- Symmetric Matrix Check
- Determinant (Gaussian elimination)
- Transpose (in-place)
- Eigenvalues (2x2 case)

Complexity Summary:
- Addition: O(n^2)
- Multiplication: O(n^3)
- Zero check: O(n^2)
- Symmetry check: O(n^2)
- Determinant: O(n^3) (optimized)
- Transpose: O(n^2)
- Eigenvalues: O(n^3)

Key Insights:
- Most matrix operations are quadratic
- Multiplication and determinant dominate with cubic cost
- Naive determinant (cofactor expansion) is inefficient: O(n!)
