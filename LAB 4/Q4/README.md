## Problem

Given **n people** attending a party, each with:

* Entry time `aᵢ`
* Exit time `bᵢ` (where `bᵢ > aᵢ`)

Determine the **time at which the maximum number of people were present simultaneously**.

Assumptions:

* All entry and exit times are **distinct**
* Each person is present in interval:

```id="l4l9q8"
[aᵢ, bᵢ)
```

---

## Key Idea

Convert the problem into **event sorting**:

* Treat each entry as `+1`
* Treat each exit as `-1`

Then:

1. Sort all events by time
2. Traverse in order and maintain a running count
3. Track the maximum count and corresponding time

---

## Approach

1. Create an array of events:

   * `(time, +1)` → entry
   * `(time, -1)` → exit

2. Sort events by time → **O(n log n)**

3. Traverse:

   * Maintain `current_count`
   * Update `max_count` and `time`

---

## Algorithm

```id="r5nm9t"
Create array E of size 2n

For each person:
  Add (aᵢ, +1)
  Add (bᵢ, -1)

Sort E by time

current = 0
max = 0
time_of_max = -1

For each event in E:
  current += event.type
  If current > max:
    max = current
    time_of_max = event.time
```

---

## Complexity

| Metric           | Value      |
| ---------------- | ---------- |
| Time Complexity  | O(n log n) |
| Space Complexity | O(n)       |

---

## Example

### Input

```id="q9f82i"
Entries:  1  2  10  5  5
Exits:    4  5  12  9  12
```

### Output

```id="9u4n7k"
Maximum people = 3 at time = 5
```

---

## Why This Works

* Sorting ensures chronological processing
* Increment/decrement simulates people entering/leaving
* Maximum overlap corresponds to peak attendance

---

## Conclusion

Efficient solution using:

* Event transformation
* Sorting
* Prefix sum concept

Avoids brute-force O(n²) comparisons.
