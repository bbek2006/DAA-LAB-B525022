Title: Median without Sorting

Algorithm:
- Uses Quickselect (based on partition of Quicksort)
- Finds median without fully sorting the array

Steps:
1. Choose pivot
2. Partition array
3. Recur only on required side

Complexity:
- Average: O(n)
- Worst: O(n^2)

Advantage:
- Faster than sorting (O(n log n))
