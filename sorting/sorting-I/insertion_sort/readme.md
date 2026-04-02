# Insertion Sort

In Insertion Sort, we **pick each element and place it at its correct position** among the already-sorted elements to its left.

---

## How It Works

### Outer Loop — `i` from `1` to `<= n-1`
We start from index `1` because a single element (index `0`) is already sorted by itself — nothing to compare on its left.

### Setting `j = i`
`j` tracks which element we're currently placing. We move it leftward, swapping with neighbors until it reaches its correct position.

### Inner While Loop — runs while `j > 0` and `arr[j] < arr[j-1]`
- `j > 0` ensures there are elements on the left to compare against
- `arr[j] < arr[j-1]` means the current element is out of place → swap and move left

### No Explicit Optimization Needed
If the array is already sorted, the while condition `arr[j] < arr[j-1]` is never true — so the inner loop never runs, giving us O(n) best case naturally.

---

## Complexity

| Case | Time | Space |
|------|------|-------|
| Best (already sorted) | O(n) | O(1) |
| Average | O(n²) | O(1) |
| Worst (reverse sorted) | O(n²) | O(1) |