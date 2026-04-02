## Comparison

| Property | Selection Sort | Bubble Sort | Insertion Sort |
|----------|---------------|-------------|----------------|
| Strategy | Pick minimum, place at front | Push maximum to end via swaps | Pick element, shift into sorted left portion |
| Time (all cases) | O(n²) | O(n²) avg/worst, O(n) best | O(n²) avg/worst, O(n) best |
| Space | O(1) | O(1) | O(1) |
| Optimizable | ❌ No | ✅ Yes (early exit) | ✅ Yes (early exit) |
| Swaps | At most O(n) | Up to O(n²) | Up to O(n²) |