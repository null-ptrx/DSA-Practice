# 📚 Sorting Algorithms - Revision Notes

> **Source:** Striver's DSA Tutorial  
> **Video Link:** [https://youtu.be/HGk_ypEuS24](https://youtu.be/HGk_ypEuS24)  
> **Topics Covered:** Selection Sort, Bubble Sort, Insertion Sort

---

## 🎯 Quick Reference Table

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | In-Place |
|-----------|-----------|--------------|------------|-------|--------|----------|
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ No | ✅ Yes |
| **Bubble Sort** | O(n)* | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes |

*With optimization flag

---

## 1️⃣ Selection Sort

### 💡 Core Concept
**"Select minimums and swap to the front"**

### 🔄 How It Works
1. Find the minimum element in range `[0...n-1]` and swap with index `0`
2. Find the minimum in range `[1...n-1]` and swap with index `1`
3. Repeat until `n-2` (last element auto-sorted)

### 📝 Algorithm Steps
```
Array: [13, 46, 24, 52, 20, 9]

Pass 1 (i=0): Find min in [13, 46, 24, 52, 20, 9] → min = 9
              Swap arr[0] ↔ arr[5]
              Result: [9, 46, 24, 52, 20, 13]

Pass 2 (i=1): Find min in [46, 24, 52, 20, 13] → min = 13
              Swap arr[1] ↔ arr[5]
              Result: [9, 13, 24, 52, 20, 46]

Pass 3 (i=2): Find min in [24, 52, 20, 46] → min = 20
              Swap arr[2] ↔ arr[4]
              Result: [9, 13, 20, 52, 24, 46]

Pass 4 (i=3): Find min in [52, 24, 46] → min = 24
              Swap arr[3] ↔ arr[4]
              Result: [9, 13, 20, 24, 52, 46]

Pass 5 (i=4): Find min in [52, 46] → min = 46
              Swap arr[4] ↔ arr[5]
              Result: [9, 13, 20, 24, 46, 52] ✓
```

### 💻 Implementation
```cpp
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)  // Outer loop: 0 to n-2
    {
        int min = i;  // Assume current is minimum
        
        for (int j = i; j <= n - 1; j++)  // Find actual minimum
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        // Swap minimum with current position
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
```

### 📊 Complexity Analysis

**Time Complexity:**
- **Best Case:** O(n²) - No optimization possible
- **Average Case:** O(n²)
- **Worst Case:** O(n²)

**Why always O(n²)?**  
Even if the array is already sorted, the algorithm must scan the remaining unsorted portion to find the minimum.

**Calculation:**
```
Comparisons = (n-1) + (n-2) + (n-3) + ... + 2 + 1
            = n(n-1)/2
            = n²/2 - n/2
            = O(n²)
```

**Space Complexity:** O(1) - Only uses variables `i`, `j`, `min`, `temp`

### ⚠️ Key Points
- Outer loop: `i = 0` to `n-2` _(n-1 iterations)_
- Inner loop: `j = i` to `n-1` _(finds minimum)_
- **No optimization possible** - always scans entire unsorted portion
- **Not stable** - relative order of equal elements may change

---

## 2️⃣ Bubble Sort

### 💡 Core Concept
**"Push the maximum to the end through adjacent swapping"**

### 🔄 How It Works
1. Compare adjacent elements (`j` and `j+1`)
2. Swap if left > right
3. After each pass, largest element "bubbles up" to its correct position
4. Reduce range for next pass (already sorted at end)

### 📝 Algorithm Steps
```
Array: [13, 46, 24, 52, 20, 9]

Pass 1: Compare and swap adjacent elements
  [13, 46, 24, 52, 20, 9] → 13 < 46, no swap
  [13, 46, 24, 52, 20, 9] → 46 > 24, swap
  [13, 24, 46, 52, 20, 9] → 46 < 52, no swap
  [13, 24, 46, 52, 20, 9] → 52 > 20, swap
  [13, 24, 46, 20, 52, 9] → 52 > 9, swap
  [13, 24, 46, 20, 9, 52] → 52 is now in place ✓

Pass 2: Process up to n-2 (52 already sorted)
  → Result: [13, 24, 20, 9, 46, 52] → 46 in place ✓

Pass 3: Process up to n-3
  → Result: [13, 20, 9, 24, 46, 52] → 24 in place ✓

... continues until fully sorted
```

### 💻 Implementation (Optimized)
```cpp
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)  // Reduce range each pass
    {
        bool didSwap = false;  // Optimization flag
        
        for (int j = 0; j <= i - 1; j++)  // IMPORTANT: j <= i-1 to avoid out of bounds
        {
            if (arr[j] > arr[j + 1])  // Compare adjacent
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = true;
            }
        }
        
        if (!didSwap)  // Array is sorted, exit early
        {
            break;
        }
    }
}
```

### 📊 Complexity Analysis

**Time Complexity:**
- **Best Case:** O(n) - Array already sorted (with optimization)
- **Average Case:** O(n²)
- **Worst Case:** O(n²) - Reverse sorted array

**Without Optimization:**  
Always O(n²) regardless of input

**With Optimization (didSwap flag):**
- If no swaps occur in a pass → array is sorted → break early
- Best case: Only one pass needed → O(n)

**Space Complexity:** O(1) - Only uses `i`, `j`, `temp`, `didSwap`

### ⚠️ Key Points
- Inner loop: `j <= i - 1` to avoid accessing `arr[j+1]` out of bounds
- Largest elements bubble to the end first
- **Optimization:** Use `didSwap` flag for early exit
- **Stable sort** - maintains relative order of equal elements

### 🚨 Common Runtime Error
```cpp
// WRONG! Will cause out of bounds error
for (int j = 0; j <= i; j++)  // If j = i, then arr[j+1] = arr[i+1] is out of bounds!
```

**Correct:**
```cpp
for (int j = 0; j <= i - 1; j++)  // Ensures j+1 never exceeds i
```

---

## 3️⃣ Insertion Sort

### 💡 Core Concept
**"Take an element and insert it into its correct position in the sorted portion"**

### 🔄 How It Works
1. Start from index 1 (assume index 0 is sorted)
2. Pick current element
3. Compare with elements on the left
4. Shift larger elements to the right
5. Insert current element in correct position

### 📝 Algorithm Steps
```
Array: [13, 46, 24, 52, 20, 9]

i=0: [13] → Already sorted (base case)

i=1: Insert 46
     Compare 46 with 13 → 46 > 13, no shift
     Result: [13, 46, 24, 52, 20, 9]

i=2: Insert 24
     Compare 24 with 46 → 24 < 46, shift 46 right
     Compare 24 with 13 → 24 > 13, stop
     Result: [13, 24, 46, 52, 20, 9]

i=3: Insert 52
     Compare 52 with 46 → 52 > 46, no shift
     Result: [13, 24, 46, 52, 20, 9]

i=4: Insert 20
     Shift 52 → [13, 24, 46, _, 52, 9]
     Shift 46 → [13, 24, _, 46, 52, 9]
     Shift 24 → [13, _, 24, 46, 52, 9]
     Insert 20 → [13, 20, 24, 46, 52, 9]

i=5: Insert 9
     Shift all elements right
     Insert at beginning
     Result: [9, 13, 20, 24, 46, 52] ✓
```

### 💻 Implementation
```cpp
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)  // Process each element
    {
        int j = i;
        
        // Shift elements to right while current is smaller
        while (j > 0 && arr[j - 1] > arr[j])
        {
            // Swap
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            
            j--;  // Move left
        }
    }
}
```

### 📊 Complexity Analysis

**Time Complexity:**

**Best Case: O(n)** - Array already sorted
```
For sorted array [1, 2, 3, 4, 5]:
  i=0: while condition fails (j=0)
  i=1: arr[0]=1 < arr[1]=2, while doesn't run
  i=2: arr[1]=2 < arr[2]=3, while doesn't run
  ...
Only outer loop runs → O(n)
```

**Worst Case: O(n²)** - Reverse sorted array
```
For array [5, 4, 3, 2, 1]:
  i=0: 0 swaps
  i=1: 1 swap
  i=2: 2 swaps
  i=3: 3 swaps
  i=4: 4 swaps
  Total = 0+1+2+3+4 = 10 = n(n-1)/2 → O(n²)
```

**Average Case: O(n²)**

**Space Complexity:** O(1) - Only uses `i`, `j`, `temp`

### ⚠️ Key Points
- Outer loop: `i = 0` to `n-1`
- While condition: `j > 0 && arr[j-1] > arr[j]` _(crucial!)_
- **Adaptive algorithm** - performs better on nearly sorted data
- **Stable sort** - maintains relative order
- **Best for small arrays** or nearly sorted data

---

## 🎓 Interview Tips & Tricks

### 1. **When to Mention Optimization**
- **Always** mention the O(n) best case for Bubble and Insertion Sort
- Explain the `didSwap` flag optimization for Bubble Sort
- Shows deeper understanding of algorithms

### 2. **Stability Matters**
```
Stable: Bubble Sort, Insertion Sort
Unstable: Selection Sort (as implemented)
```

### 3. **Practical Usage**
- **Insertion Sort:** Best for nearly sorted data, small arrays
- **Selection Sort:** When memory writes are expensive (minimizes swaps)
- **Bubble Sort:** Rarely used in practice (teaching purposes)

### 4. **Common Interview Questions**
- ✅ "What's the difference between stable and unstable sorting?"
- ✅ "Why is Selection Sort always O(n²)?"
- ✅ "When would you use Insertion Sort over Quick Sort?"
- ✅ "How can you optimize Bubble Sort?"

### 5. **Space Complexity**
All three are **in-place** algorithms:
- ✅ O(1) auxiliary space
- ✅ Sort within the original array
- ✅ Memory efficient

---

## 🧮 Complexity Calculation Examples

### Selection Sort - Always O(n²)
```
For n = 6:
  i=0: 5 comparisons
  i=1: 4 comparisons
  i=2: 3 comparisons
  i=3: 2 comparisons
  i=4: 1 comparison
  
Total = 5+4+3+2+1 = 15 comparisons
Formula: n(n-1)/2 = 6(5)/2 = 15 ✓

Big-O: n²/2 - n/2 → O(n²)
```

### Bubble Sort - Best Case O(n)
```
Sorted array [1, 2, 3, 4, 5]:
  Pass 1: No swaps → didSwap = false → break
  Only 1 pass → n comparisons → O(n)
```

### Insertion Sort - Best vs Worst
```
Best (sorted): [1, 2, 3, 4, 5]
  While loop never executes → O(n)

Worst (reverse): [5, 4, 3, 2, 1]
  Each element shifts all previous → O(n²)
```

---

## 📌 Quick Comparison

| Feature | Selection | Bubble | Insertion |
|---------|-----------|--------|-----------|
| **Main Idea** | Select min | Bubble max up | Insert in place |
| **Swaps** | O(n) | O(n²) | O(n²) |
| **Comparisons** | O(n²) | O(n²) | O(n) to O(n²) |
| **Adaptive** | ❌ No | ✅ Yes | ✅ Yes |
| **Online** | ❌ No | ❌ No | ✅ Yes |
| **Use Case** | Min swaps needed | Teaching | Nearly sorted |

**Adaptive:** Performance improves with partially sorted input  
**Online:** Can sort data as it arrives

---

## 💡 Remember for Exams/Interviews

1. **Selection Sort:** "Always O(n²), no escape!"
2. **Bubble Sort:** "With flag, O(n) best case"
3. **Insertion Sort:** "O(n) for sorted, O(n²) for reverse"
4. **All three:** O(1) space, in-place sorting
5. **Stable:** Bubble & Insertion ✅ | Selection ❌

---

## 🔗 Additional Resources

- **Video Tutorial:** [Striver's Sorting Playlist](https://youtu.be/HGk_ypEuS24)
- **Practice:** Implement each algorithm with different test cases
- **Visualize:** Use [VisuAlgo](https://visualgo.net/en/sorting) to see animations

---

## ✅ Revision Checklist

- [ ] Can explain each algorithm's core concept
- [ ] Can write code from scratch without referring
- [ ] Can dry run on paper with example array
- [ ] Can calculate time complexity with proof
- [ ] Can explain when to use which algorithm
- [ ] Can identify stable vs unstable sorts
- [ ] Can explain optimization techniques

---

**Last Updated:** February 2026  
**Next Revision:** ___________

---

*Good luck with your revision! 🚀*
