# 📊 DSA — Sorting Algorithms Revision Notes

> **Source:** Striver's A2Z DSA Course — [Watch Here](https://youtu.be/HGk_ypEuS24)
> **Algorithms Covered:** Selection Sort · Bubble Sort · Insertion Sort

---

## 📋 Table of Contents

1. [Summary Cheat Sheet](#-summary-cheat-sheet)
2. [Selection Sort](#1-selection-sort)
3. [Bubble Sort](#2-bubble-sort)
4. [Insertion Sort](#3-insertion-sort)
5. [Code (Your Implementation)](#-your-full-code)
6. [Bug Fixes in Your Code](#-bug-fixes-in-your-code)

---

## ⚡ Summary Cheat Sheet

| Algorithm | Strategy | Best Case | Average Case | Worst Case | Stable? |
|-----------|----------|-----------|--------------|------------|---------|
| **Selection Sort** | Select min → swap to front | O(n²) | O(n²) | O(n²) | ❌ No |
| **Bubble Sort** | Push max to end via adjacent swaps | O(n) | O(n²) | O(n²) | ✅ Yes |
| **Insertion Sort** | Place element in correct position on left | O(n) | O(n²) | O(n²) | ✅ Yes |

> 🔑 **Key Insight:** All three are O(n²) for average/worst, but Bubble and Insertion both achieve O(n) best case when the array is **already sorted**. Selection Sort can NEVER be O(n) — it always scans the full unsorted portion.

---

## 1. Selection Sort

### 💡 Core Idea
> Repeatedly **select the minimum** element from the unsorted part and **swap it** to the front.

Think of it like this: you have a row of numbers, you scan all of them, pick the smallest, bring it to position 0. Then scan the rest, pick the next smallest, bring it to position 1. Repeat.

### 📌 Key Points
- Always makes exactly **n-1 passes** regardless of input
- Number of **comparisons** = n(n-1)/2 — always the same
- Number of **swaps** = at most n-1 (very few swaps — good when writes are expensive)
- **NOT stable** — equal elements can change relative order
- Best = Average = Worst = **O(n²)** — no optimization possible

### 🔢 Algorithm Steps
```
for i = 0 to n-2:
    mini = i
    for j = i+1 to n-1:
        if arr[j] < arr[mini]:
            mini = j
    swap(arr[i], arr[mini])
```

### 🧪 Dry Run — `arr = {13, 46, 24, 52, 20, 9}`, n = 6

#### Pass 1 (i = 0) — Find min in entire array, swap with index 0
```
[13, 46, 24, 52, 20, 9]
 ↑                   ↑
 i=0              mini=5 (value 9 is smallest)

After swap → [9, 46, 24, 52, 20, 13]
✅ Index 0 is sorted
```

#### Pass 2 (i = 1) — Find min from index 1 onwards
```
[9 | 46, 24, 52, 20, 13]
     ↑            ↑
     i=1       mini=4 (value 13 is smallest in remaining)

Wait — scan: 46, 24, 52, 20, 13 → minimum is 13 at index 5
After swap → [9, 13, 24, 52, 20, 46]
✅ Index 1 is sorted
```

#### Pass 3 (i = 2) — Find min from index 2 onwards
```
[9, 13 | 24, 52, 20, 46]
         ↑   
         i=2
Scan: 24, 52, 20, 46 → minimum is 20 at index 4
After swap → [9, 13, 20, 52, 24, 46]
✅ Index 2 is sorted
```

#### Pass 4 (i = 3)
```
[9, 13, 20 | 52, 24, 46]
             ↑
             i=3
Scan: 52, 24, 46 → minimum is 24 at index 4
After swap → [9, 13, 20, 24, 52, 46]
✅ Index 3 is sorted
```

#### Pass 5 (i = 4)
```
[9, 13, 20, 24 | 52, 46]
                 ↑
                 i=4
Scan: 52, 46 → minimum is 46 at index 5
After swap → [9, 13, 20, 24, 46, 52]
✅ Index 4 is sorted
```

#### ✅ Final Sorted Array: `[9, 13, 20, 24, 46, 52]`

### 💻 Clean Code
```cpp
void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;                          // assume current index is minimum
        for (int j = i + 1; j < n; j++) {     // scan the rest
            if (arr[j] < arr[mini]) {
                mini = j;                      // update minimum index
            }
        }
        swap(arr[i], arr[mini]);               // place minimum at position i
    }
}
```

---

## 2. Bubble Sort

### 💡 Core Idea
> Compare **adjacent pairs** and swap if out of order. This "bubbles" the **largest element** to the end in each pass.

Like bubbles rising in water — the heaviest sinks... wait, actually the heaviest (largest) rises to the top (end) each round.

### 📌 Key Points
- After each pass, the largest unsorted element is at its **correct final position**
- After pass `i`, the last `i` elements are sorted
- Can be **optimized with a `didSwap` flag** — if no swap in a pass, array is already sorted → `O(n)` best case
- **Stable sort** — equal elements maintain their original order
- Without optimization: always O(n²)
- With optimization: O(n) best case (already sorted array)

### 🔢 Algorithm Steps (Optimized)
```
for i = n-1 down to 1:
    didSwap = 0
    for j = 0 to i-1:
        if arr[j] > arr[j+1]:
            swap(arr[j], arr[j+1])
            didSwap = 1
    if didSwap == 0: BREAK  ← early exit if already sorted
```

### 🧪 Dry Run — `arr = {13, 46, 24, 52, 20, 9}`, n = 6

#### Pass 1 (i = 5) — Bubble largest to end
```
Step 1: Compare arr[0]=13 and arr[1]=46 → 13 < 46, NO swap
        [13, 46, 24, 52, 20, 9]

Step 2: Compare arr[1]=46 and arr[2]=24 → 46 > 24, SWAP
        [13, 24, 46, 52, 20, 9]

Step 3: Compare arr[2]=46 and arr[3]=52 → 46 < 52, NO swap
        [13, 24, 46, 52, 20, 9]

Step 4: Compare arr[3]=52 and arr[4]=20 → 52 > 20, SWAP
        [13, 24, 46, 20, 52, 9]

Step 5: Compare arr[4]=52 and arr[5]=9  → 52 > 9,  SWAP
        [13, 24, 46, 20, 9, 52]
                              ✅ 52 is at correct position
didSwap = 1 → continue
```

#### Pass 2 (i = 4) — Bubble second-largest to position 4
```
[13, 24, 46, 20, 9 | 52]
Compare pairs up to index 3:
13↔24: no swap → [13, 24, 46, 20, 9]
24↔46: no swap → [13, 24, 46, 20, 9]
46↔20: SWAP    → [13, 24, 20, 46, 9]
46↔9 : SWAP    → [13, 24, 20, 9, 46]
                              ✅ 46 is at correct position
```

#### Pass 3 (i = 3)
```
[13, 24, 20, 9 | 46, 52]
13↔24: no swap → [13, 24, 20, 9]
24↔20: SWAP    → [13, 20, 24, 9]
24↔9 : SWAP    → [13, 20, 9, 24]
                         ✅ 24 is at correct position
```

#### Pass 4 (i = 2)
```
[13, 20, 9 | 24, 46, 52]
13↔20: no swap → [13, 20, 9]
20↔9 : SWAP    → [13, 9, 20]
                      ✅ 20 is at correct position
```

#### Pass 5 (i = 1)
```
[13, 9 | 20, 24, 46, 52]
13↔9: SWAP → [9, 13]
                 ✅ Done
```

#### ✅ Final Sorted Array: `[9, 13, 20, 24, 46, 52]`

#### 🎯 Optimization Demo — Already Sorted Input `[9, 13, 20, 24, 46, 52]`
```
Pass 1: Compare all pairs → NO swaps at all → didSwap = 0 → BREAK immediately
Result: Only 1 pass needed → O(n) ✅
```

### 💻 Clean Code (Optimized)
```cpp
void bubble(int arr[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) break;  // ← KEY optimization
    }
}
```

---

## 3. Insertion Sort

### 💡 Core Idea
> Take one element and **insert it into its correct position** among the already-sorted elements on its left.

Think of sorting playing cards in your hand — you pick up a new card and slide it left until it's in the right spot.

### 📌 Key Points
- Left side is always sorted; right side is unsorted
- Picks element at index `i`, then shifts it left until it's in the right place
- **Stable sort** — maintains relative order of equal elements
- Very efficient for **nearly sorted arrays**
- Best Case: `O(n)` — already sorted (inner while loop never runs)
- Worst Case: `O(n²)` — reverse sorted (element always shifts all the way left)
- Uses **swaps** (not shifts) in most implementations

### 🔢 Algorithm Steps
```
for i = 1 to n-1:
    j = i
    while j > 0 AND arr[j-1] > arr[j]:
        swap(arr[j-1], arr[j])
        j--
```

> ⚠️ **Bug in your code:** `while (j > 0 && arr[j-1])` — this checks if `arr[j-1]` is non-zero (truthy), NOT if `arr[j-1] > arr[j]`. See Bug Fixes section below.

### 🧪 Dry Run — `arr = {13, 46, 24, 52, 20, 9}`, n = 6

#### Pass 1 (i = 1) — Insert 46 into sorted portion [13]
```
Sorted: [13] | Unsorted: [46, 24, 52, 20, 9]
j=1: arr[0]=13 > arr[1]=46? → 13 > 46? NO → stop
Result: [13, 46, 24, 52, 20, 9]  (no change)
```

#### Pass 2 (i = 2) — Insert 24 into sorted portion [13, 46]
```
Sorted: [13, 46] | Unsorted: [24, 52, 20, 9]
j=2: arr[1]=46 > arr[2]=24? → YES → SWAP
     [13, 24, 46, 52, 20, 9]
j=1: arr[0]=13 > arr[1]=24? → NO  → stop
Result: [13, 24, 46, 52, 20, 9]
```

#### Pass 3 (i = 3) — Insert 52 into sorted portion [13, 24, 46]
```
Sorted: [13, 24, 46] | Unsorted: [52, 20, 9]
j=3: arr[2]=46 > arr[3]=52? → NO → stop
Result: [13, 24, 46, 52, 20, 9]  (no change)
```

#### Pass 4 (i = 4) — Insert 20 into sorted portion [13, 24, 46, 52]
```
Sorted: [13, 24, 46, 52] | Unsorted: [20, 9]
j=4: arr[3]=52 > arr[4]=20? → YES → SWAP
     [13, 24, 46, 20, 52, 9]
j=3: arr[2]=46 > arr[3]=20? → YES → SWAP
     [13, 24, 20, 46, 52, 9]
j=2: arr[1]=24 > arr[2]=20? → YES → SWAP
     [13, 20, 24, 46, 52, 9]
j=1: arr[0]=13 > arr[1]=20? → NO  → stop
Result: [13, 20, 24, 46, 52, 9]
```

#### Pass 5 (i = 5) — Insert 9 into sorted portion [13, 20, 24, 46, 52]
```
Sorted: [13, 20, 24, 46, 52] | Unsorted: [9]
j=5: arr[4]=52 > arr[5]=9?  → YES → SWAP → [13, 20, 24, 46, 9, 52]
j=4: arr[3]=46 > arr[4]=9?  → YES → SWAP → [13, 20, 24, 9, 46, 52]
j=3: arr[2]=24 > arr[3]=9?  → YES → SWAP → [13, 20, 9, 24, 46, 52]
j=2: arr[1]=20 > arr[2]=9?  → YES → SWAP → [13, 9, 20, 24, 46, 52]
j=1: arr[0]=13 > arr[1]=9?  → YES → SWAP → [9, 13, 20, 24, 46, 52]
j=0: j > 0? → NO → stop
Result: [9, 13, 20, 24, 46, 52]
```

#### ✅ Final Sorted Array: `[9, 13, 20, 24, 46, 52]`

### 💻 Clean Code (Fixed)
```cpp
void insertion(int arr[], int n) {
    for (int i = 1; i <= n - 1; i++) {    // start from index 1
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {  // ← MUST compare arr[j-1] > arr[j]
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}
```

---

## 🧾 Your Full Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

void bubble(int arr[], int n) {
    // Basic version
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Optimized version (with early exit)
    for (int i = n - 1; i >= 1; i--) {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        if (didswap == 0) break;
    }
}

void insertion(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1]) {       // ⚠️ BUG: missing > arr[j]
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    bubble(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
```

---

## 🐛 Bug Fixes in Your Code

### Bug 1 — Insertion Sort: Wrong `while` condition

```cpp
// ❌ YOUR CODE — checks if arr[j-1] is non-zero (truthy), not a comparison!
while (j > 0 && arr[j - 1]) {

// ✅ FIXED — correctly compares adjacent elements
while (j > 0 && arr[j - 1] > arr[j]) {
```

**Why it's a bug:** `arr[j-1]` by itself evaluates to `true` if the value is non-zero. So the while loop keeps swapping without the correct stopping condition, giving completely wrong output.

### Bug 2 — Bubble Sort: Two implementations running back to back

```cpp
// ⚠️ Your bubble() function runs BOTH the basic and optimized versions
// The array gets sorted by the first loop, then the second loop runs on
// an already-sorted array (which is harmless, but wasteful).
// Pick ONE — the optimized version is always better.
```

### Bug 3 — Insertion Sort: Loop starts at i = 0 instead of i = 1

```cpp
// ❌ Starts at 0 — comparing index 0 with index -1 (never executes inner loop anyway,
//    but semantically wrong and wastes one iteration)
for (int i = 0; i <= n - 1; i++) {

// ✅ Should start at 1 — first element is trivially "sorted"
for (int i = 1; i <= n - 1; i++) {
```

---

## 🔁 At-a-Glance Comparison

```
Array:  [13, 46, 24, 52, 20, 9]

Selection: finds MIN each pass, swaps to front
  Pass 1 → [9,  46, 24, 52, 20, 13]   (swapped 13 ↔ 9)
  Pass 2 → [9,  13, 24, 52, 20, 46]   (swapped 46 ↔ 13)
  Pass 3 → [9,  13, 20, 52, 24, 46]   (swapped 24 ↔ 20)
  Pass 4 → [9,  13, 20, 24, 52, 46]   (swapped 52 ↔ 24)
  Pass 5 → [9,  13, 20, 24, 46, 52]   (swapped 52 ↔ 46)

Bubble:    bubbles MAX to end each pass
  Pass 1 → [13, 24, 46, 20, 9,  52]   (52 in place)
  Pass 2 → [13, 24, 20, 9,  46, 52]   (46 in place)
  Pass 3 → [13, 20, 9,  24, 46, 52]   (24 in place)
  Pass 4 → [13, 9,  20, 24, 46, 52]   (20 in place)
  Pass 5 → [9,  13, 20, 24, 46, 52]   ✅

Insertion: inserts each element in its correct left-side position
  i=1  → [13, 46, 24, 52, 20, 9]    (46 already placed)
  i=2  → [13, 24, 46, 52, 20, 9]    (24 inserted)
  i=3  → [13, 24, 46, 52, 20, 9]    (52 already placed)
  i=4  → [13, 20, 24, 46, 52, 9]    (20 inserted)
  i=5  → [9,  13, 20, 24, 46, 52]   ✅
```

---

> 💡 **Revision Tip:** For interviews — remember Selection is the "dumb" one (always O(n²), no optimization). Bubble and Insertion are "smart" — they detect already-sorted input and finish in O(n). In practice, Insertion Sort is used inside hybrid algorithms like TimSort because it's very fast on small or nearly-sorted arrays.
