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

## Insertion Sort

**Core Idea:** Pick up each element and insert it into its correct position among the already-sorted elements to its left.

### How it works
- Outer loop runs from `i = 1` to `i < n` — starts at 1 because a single element is trivially sorted
- For each outer iteration, set `j = i` and decrease `j` by 1 each step
- Inner loop runs while `j > 0`
- If `arr[j - 1] > arr[j]`, swap the two elements; otherwise stop early
- **Already optimized by nature** — if the array is sorted, the inner loop condition `arr[j - 1] > arr[j]` is never true, so the inner loop exits immediately on every iteration; only the outer loop runs, giving O(n) time with O(1) space

### Complexity

| Case | Time | Space |
|------|------|-------|
| Best (sorted) | O(n) | O(1) |
| Average | O(n²) | O(1) |
| Worst (reverse sorted) | O(n²) | O(1) |

> ✅ **Inherently optimized** — no extra flag needed. On a sorted array, the inner loop never executes a swap and exits immediately, so only the outer loop's n iterations run → O(n) time, O(1) space.

---

## Comparison

| Property | Selection Sort | Bubble Sort | Insertion Sort |
|----------|---------------|-------------|----------------|
| Strategy | Pick minimum, place at front | Push maximum to end via swaps | Pick element, shift into sorted left portion |
| Time (all cases) | O(n²) | O(n²) avg/worst, O(n) best | O(n²) avg/worst, O(n) best |
| Space | O(1) | O(1) | O(1) |
| Optimizable | ❌ No | ✅ Yes (early exit) | ✅ Yes (early exit) |
| Swaps | At most O(n) | Up to O(n²) | Up to O(n²) |