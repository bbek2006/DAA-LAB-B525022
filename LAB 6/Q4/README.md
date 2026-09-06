Title: Sorting using Reversal Operation

Problem:
Sort a permutation using only reverse(p, i, j)

Part 1:
- Place largest element at correct position
- Uses ≤ 2 reversals per element
- Total reversals: O(n)

Part 2 (Cost Model):
- Cost of reversal = length of segment
- Naive method → O(n^2)

Optimized Approach:
- Divide & Conquer (like merge sort)
- Merge using block reversals

Complexity:
- Time/Cost: O(n log^2 n)

Key Insight:
- Reversal is powerful enough to simulate sorting
- Cost depends on how large segments are reversed
