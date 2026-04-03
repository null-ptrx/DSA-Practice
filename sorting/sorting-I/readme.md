# Sorting Algorithms

Sorting is the process of arranging elements in a specific order (ascending or descending). It is one of the most fundamental problems in computer science and forms the base for many other algorithms.

---

## Algorithms Covered

| Algorithm | Approach | Folder |
|-----------|----------|--------|
| Selection Sort | Pick minimum, place at front | [selection-sort](./selection_sort/) |
| Bubble Sort | Push maximum to end via swaps | [bubble-sort](./bubble_sort/) |
| Insertion Sort | Pick element, shift into sorted left portion | [insertion-sort](./insertion_sort/) |

---

## Comparison

| Property | Selection Sort | Bubble Sort | Insertion Sort |
|----------|---------------|-------------|----------------|
| Strategy | Pick minimum, place at front | Push maximum to end via swaps | Pick element, shift into sorted left portion |
| Best Case | O(n²) | O(n) | O(n) |
| Avg / Worst Case | O(n²) | O(n²) | O(n²) |
| Space | O(1) | O(1) | O(1) |
| Stable | ❌ No | ✅ Yes | ✅ Yes |
| Adaptive | ❌ No | ✅ Yes | ✅ Yes |
| Optimizable | ❌ No | ✅ Yes (early exit) | ✅ Yes (naturally) |
| Swaps | At most O(n) | Up to O(n²) | Up to O(n²) |
| Best Use Case | When writes are costly | Almost sorted data | Nearly sorted / small arrays |

---

## Key Concepts

- **Stable Sort** — equal elements maintain their original relative order
- **Adaptive Sort** — performs better when input is partially sorted
- **In-place Sort** — requires no extra memory beyond the input array (all three above are in-place)