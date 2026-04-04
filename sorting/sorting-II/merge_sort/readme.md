# Merge Sort

Merge Sort is a **divide and conquer** algorithm — it recursively splits the array into halves, sorts each half, then merges them back together in order.

---

## How It Works

### Divide
Recursively split the array from the middle until each sub-array has only one element. A single element is already sorted by itself.

### Merge
Once we hit the base case, we start merging back. Two pointers — one for the left half, one for the right — compare elements and build a sorted `temp` array, which is copied back into the original.

### Recursion Flow
```
merge_sort(arr, low, high)
├── merge_sort(arr, low, mid)       ← sort left half
├── merge_sort(arr, mid+1, high)    ← sort right half
└── mergeArray(arr, low, mid, high) ← merge both halves
```

Base case: `if (low >= high) return` — single element, nothing to sort.

---

## Why O(n log n)

- **log n** — number of times we can divide the array in half
- **n** — work done at each level to merge all elements

Total: **O(n log n)** at all cases — best, average, and worst.

---

## Complexity

| Case | Time | Space |
|------|------|-------|
| Best | O(n log n) | O(n) |
| Average | O(n log n) | O(n) |
| Worst | O(n log n) | O(n) |

> Space is O(n) because of the `temp` array used during merging.

---

## Properties

| Property | Value |
|----------|-------|
| Stable | ✅ Yes |
| Adaptive | ❌ No |
| In-place | ❌ No |
| Recursive | ✅ Yes |