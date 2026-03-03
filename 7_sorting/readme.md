
# Sorting Algorithms

---

## Selection Sort

**Core Idea:** Find the minimum element and swap it to the front. Repeat for the rest of the array.

### How it works
- Outer loop runs from `i = 0` to `i <= n-1`
- Inner loop runs from `j = i` to `j < n`
- Track the index of the minimum element
- After the inner loop, swap the minimum to position `i`



### Complexity

| Case | Time | Space |
|------|------|-------|
| Best | O(n²) | O(1) |
| Average | O(n²) | O(1) |
| Worst | O(n²) | O(1) |

> ⚠️ **Cannot be optimized** — always compares every element regardless of input.

---

## Bubble Sort

**Core Idea:** Repeatedly push the largest unsorted element to the end via adjacent swaps.

### How it works
- Outer loop runs from `i = 0` to `i < n-1`
- Inner loop runs from `j = 0` to `j < n-i-1` (end shrinks each pass)
- Swap adjacent elements if left > right
- Uses a `count` flag — if no swaps happened, array is already sorted → exit early


### Complexity

| Case | Time | Space |
|------|------|-------|
| Best (sorted) | O(n) | O(1) |
| Average | O(n²) | O(1) |
| Worst | O(n²) | O(1) |

> ✅ **Can be optimized** — the `count` flag allows early exit if the array is already sorted, giving O(n) best case.

---

## Comparison

| Property | Selection Sort | Bubble Sort |
|----------|---------------|-------------|
| Strategy | Pick minimum, place at front | Push maximum to end via swaps |
| Time (all cases) | O(n²) | O(n²) avg/worst, O(n) best |
| Space | O(1) | O(1) |
| Optimizable | ❌ No | ✅ Yes (early exit) |
| Swaps | At most O(n) | Up to O(n²) |