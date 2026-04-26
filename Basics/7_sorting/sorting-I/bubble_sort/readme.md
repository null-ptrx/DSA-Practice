# Bubble Sort

In Bubble Sort, we **push the maximum element to the end** in each pass — it's the opposite of Selection Sort (which pulls the minimum to the front).

---

## How It Works

### Outer Loop — `i` from `0` to `< n-1`
We run `n-1` passes total. Each pass guarantees that the largest unsorted element "bubbles up" to its correct position at the end.

### Inner Loop — `j` from `0` to `< n-1-i`
We compare adjacent elements: `arr[j]` and `arr[j+1]`.  
After every pass, the last `i` elements are already sorted — so we shrink the inner loop by `i` each time, skipping unnecessary comparisons.

### Swap Condition
```
if arr[j] > arr[j+1] → swap
```
This keeps pushing the current maximum toward the end.

---

## Optimization — Early Exit

If the array is **already sorted**, we don't need to continue.

- Set `swapped = false` before each inner loop
- If a swap happens, set `swapped = true`
- After the inner loop: if `!swapped` → array is sorted → `return` early

This brings best-case time complexity down to **O(n)**.

---

## Complexity

| Case | Time | Space |
|------|------|-------|
| Best (already sorted) | O(n) | O(1) |
| Average | O(n²) | O(1) |
| Worst (reverse sorted) | O(n²) | O(1) |