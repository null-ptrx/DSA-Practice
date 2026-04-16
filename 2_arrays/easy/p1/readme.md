# Largest Number in an Array

## Problem Statement
Find the largest element in a given array.

---

## Approach 1: Brute Force

**Steps:**
1. Sort the array using any sorting algorithm.
2. After sorting, the element at index `n - 1` (last index) is the largest.

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(1)` *(in-place sort)*

---

## Approach 2: Optimal (Linear Traversal)

**Steps:**
1. Initialize a variable `largest` with `a[0]` (first element).
2. Traverse the full array from index `1` to `n - 1`.
3. If any element is greater than `largest`, update `largest` with that element.
4. After traversal, `largest` holds the answer.

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## Code

Refer to the `.cpp` file for the optimal implementation.