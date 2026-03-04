# Part 2 — Sorting Algorithms 


## Merge Sort

---

## Overview

Merge Sort is a **divide-and-conquer** sorting algorithm that recursively splits an array into halves, sorts each half, and merges them back together in sorted order.

---

## How It Works

### Step 1 — Divide

- Recursively split the array using indices `low` and `high`
- Calculate `mid = low + (high - low) / 2`
- **Base case:** if `low >= high`, the subarray has one element — already sorted, return
- Recurse on the left half `[low, mid]`, then the right half `[mid+1, high]`

### Step 2 — Merge

- Create a temporary array `temp` to hold the sorted result
- Use two pointers:
  - `left` → starts at `low` (beginning of left subarray)
  - `right` → starts at `mid + 1` (beginning of right subarray)
- Compare `arr[left]` and `arr[right]` — push the smaller value into `temp` and advance that pointer
- Once one subarray is exhausted, append all remaining elements from the other (already sorted)
- Copy `temp` back into `arr[low..high]`

---

## Complexity Analysis

| Type             | Complexity   | Reason                                          |
|------------------|--------------|-------------------------------------------------|
| Time Complexity  | `O(n log n)` | `O(log n)` recursive depth × `O(n)` merge step |
| Space Complexity | `O(n)`       | Temporary array used during merge               |

---

## Key Points

- **Recursive & backtracking-based** — solves subproblems before combining
- **Stable sort** — equal elements maintain their original relative order
- **Not in-place** — requires `O(n)` extra space for the temp array
- **Guaranteed `O(n log n)`** — unlike Quick Sort, performance does not degrade on sorted input