Title: Convolution using FFT (O(n log n))

Problem:
Compute convolution of two vectors A and B efficiently.

Naive Approach:
- Double loop → O(n^2)

Optimized Approach:
- Use Fast Fourier Transform (FFT)
- Convert convolution into pointwise multiplication

Steps:
1. Pad arrays to power of 2
2. Compute FFT of both arrays
3. Multiply element-wise
4. Apply inverse FFT

Complexity:
- FFT: O(n log n)
- Total: O(n log n)

Key Insight:
Convolution in time domain = Multiplication in frequency domain
