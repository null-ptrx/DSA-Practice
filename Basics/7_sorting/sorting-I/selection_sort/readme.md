## Selection Sort

In Selection Sort, we find the **minimum element** from the unsorted part and **swap it with the first element** of that part.

---

### Working

1. The outer loop runs from `0` to `n - 2` — because `n - 1` is the last index of the array, and a single remaining element is already sorted by default, so there is no need to process it.

2. At the start of each outer loop iteration, we set `minIndex = i`, assuming the current position holds the minimum element.

3. The inner loop then compares this assumed minimum with all remaining elements in the unsorted part. If any element is smaller, we update `minIndex` to that element's index. By the end of the inner loop, `minIndex` holds the index of the actual minimum element.

4. After the inner loop ends, we swap the element at index `i` with the element at `minIndex`.

5. This process repeats for the next iteration of `i`, but now the unsorted part is smaller by one — because the first element is already placed in its correct sorted position.

---

### Complexity

| Type | Complexity |
|------|------------|
| Best Case | O(n²) |
| Average Case | O(n²) |
| Worst Case | O(n²) |
| Space | O(1) |