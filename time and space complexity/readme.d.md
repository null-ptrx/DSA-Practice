# Time and Space Complexity - Complete Notes

## Table of Contents
1. [What is Time Complexity?](#what-is-time-complexity)
2. [Big O Notation](#big-o-notation)
3. [Three Golden Rules](#three-golden-rules)
4. [Types of Analysis](#types-of-analysis)
5. [Common Time Complexities](#common-time-complexities)
6. [Example Problems](#example-problems)
7. [Space Complexity](#space-complexity)
8. [Competitive Programming Guidelines](#competitive-programming-guidelines)
9. [Quick Reference](#quick-reference)

---

## What is Time Complexity?

**NOT** the actual time taken to run code (varies by machine: old Windows PC vs MacBook)

**Definition:** The rate at which time taken increases with respect to input size ($n$)

### Key Points
- Time complexity measures **number of operations/steps**, not actual seconds
- Expressed using **Big O Notation** (e.g., $O(n)$, $O(n^2)$)
- Helps predict algorithm performance as input grows
- Machine-independent metric

### Example
```cpp
// Both loops do the same logical work
for (int i = 0; i < n; i++) {  // Fast machine: 0.5 sec
    // some operation
}

for (int i = 0; i < n; i++) {  // Slow machine: 2 sec
    // same operation
}
```
**Both have $O(n)$ complexity despite different execution times**

---

## Big O Notation

Big O notation describes the **upper bound** of time/space complexity.

### Notation
- $O(1)$ - Constant time
- $O(\log n)$ - Logarithmic time
- $O(n)$ - Linear time
- $O(n \log n)$ - Linearithmic time
- $O(n^2)$ - Quadratic time
- $O(n^3)$ - Cubic time
- $O(2^n)$ - Exponential time
- $O(n!)$ - Factorial time

---

## Three Golden Rules

### Rule 1: Always Consider Worst Case Scenario

**Focus on the extreme scenario where code takes maximum time**

```cpp
// Example: Linear Search
int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Found!
        }
    }
    return -1;  // Not found
}
```

**Analysis:**
- Best case: Element at index 0 → $O(1)$
- Average case: Element in middle → $O(n/2)$ → $O(n)$
- **Worst case: Element at end or not present → $O(n)$ ← We use this!**

**Why worst case?** Interviewers want to know the maximum time your code might take in production.

---

### Rule 2: Avoid/Ignore Constants

**Constants become insignificant as $n$ grows very large**

```cpp
// Example 1
for (int i = 0; i < n; i++) {      // n operations
    cout << arr[i];
}
for (int i = 0; i < n; i++) {      // n operations
    cout << arr[i] * 2;
}
for (int i = 0; i < n; i++) {      // n operations
    cout << arr[i] + 5;
}
```

**Analysis:** Total operations = $3n$  
**Simplified:** $O(3n)$ → **$O(n)$** (drop constant 3)

```cpp
// Example 2
for (int i = 0; i < n; i++) {      // n operations
    // some work
}
int x = 10;                         // 1 operation
int y = 20;                         // 1 operation
```

**Analysis:** Total = $n + 2$  
**Simplified:** $O(n + 2)$ → **$O(n)$** (drop constant +2)

**Why?** When $n = 1,000,000$, the difference between $3n$ and $n$ is negligible compared to the overall magnitude.

---

### Rule 3: Avoid/Ignore Lower Values

**Keep only the dominant (highest degree) term**

```cpp
// Example: Nested loops with extra operations
for (int i = 0; i < n; i++) {           // n times
    for (int j = 0; j < n; j++) {       // n times
        cout << i * j;                   // Total: n²
    }
}
for (int i = 0; i < n; i++) {           // n times
    cout << i;
}
int result = arr[0] + arr[1];           // Constant
```

**Analysis:** Total = $n^2 + n + 1$  
**Simplified:** $O(n^2 + n + 1)$ → **$O(n^2)$**

**Why?** As $n$ grows:
- When $n = 1000$: $n^2 = 1,000,000$ vs $n = 1,000$ (insignificant)
- $n^2$ dominates, so we ignore $n$ and constants

**General Rule:** $O(n^3 + n^2 + n + \log n + 5)$ → **$O(n^3)$**

---

## Types of Analysis

### 1. Best Case (Omega - $\Omega$)
**Minimum time required** - When everything goes perfectly

```cpp
int search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
// Best case: Element at index 0 → Ω(1)
```

---

### 2. Average Case (Theta - $\Theta$)
**Expected/median time complexity** - Realistic scenario

```cpp
// Average case: Element somewhere in middle → Θ(n)
```

---

### 3. Worst Case (Big O - $O$) ⭐ **Most Important**
**Maximum time required (Upper Bound)** - What interviewers care about

```cpp
// Worst case: Element at end or not found → O(n)
```

### Visual Representation
```
Time
  ↑
  |     Worst Case O(n)
  |    /
  |   /
  |  /  Average Case Θ(n/2) ≈ Θ(n)
  | /
  |/___Best Case Ω(1)
  |________________→ Input Size (n)
```

**Interview Focus:** Always discuss **worst case** unless specifically asked otherwise.

---

## Common Time Complexities

### Complexity Hierarchy (Fastest to Slowest)
```
O(1) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

### Visual Growth Chart
```
Operations
    ↑
10⁶ |                                              * O(2ⁿ) - Exponential
    |                                         *
10⁵ |                                    * O(n³) - Cubic
    |                               *
10⁴ |                          * O(n²) - Quadratic
    |                     *
10³ |                * O(n log n) - Linearithmic
    |           * O(n) - Linear
10² |      * O(log n) - Logarithmic
    | * O(1) - Constant
    |_____________________________________________→ Input Size (n)
      10   100   1K   10K  100K  1M
```

### Examples by Complexity

#### $O(1)$ - Constant
```cpp
int getFirst(int arr[]) {
    return arr[0];  // Always 1 operation
}
```

#### $O(\log n)$ - Logarithmic
```cpp
// Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
// Halves search space each iteration
```

#### $O(n)$ - Linear
```cpp
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}
```

#### $O(n \log n)$ - Linearithmic
```cpp
// Merge Sort, Quick Sort (average case)
void mergeSort(int arr[], int n) {
    // Divides array log n times
    // Each level does n work
}
```

#### $O(n^2)$ - Quadratic
```cpp
// Bubble Sort, Selection Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

#### $O(2^n)$ - Exponential
```cpp
// Fibonacci (naive recursive)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

#### $O(n!)$ - Factorial
```cpp
// Generate all permutations
void permute(string s, int l, int r) {
    if (l == r) cout << s << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
```

---

## Example Problems

### Example 1: Fixed Nested Loops

```cpp
void printPairs(int n) {
    for (int i = 0; i < n; i++) {          // Runs n times
        for (int j = 0; j < n; j++) {      // Runs n times for each i
            cout << i << " " << j << endl;
        }
    }
}
```

**Analysis:**
- Outer loop: $n$ iterations
- Inner loop: $n$ iterations for each outer iteration
- Total operations: $n \times n = n^2$

**Time Complexity:** $O(n^2)$

---

### Example 2: Dependent Nested Loops

```cpp
void printTriangle(int n) {
    for (int i = 0; i < n; i++) {          // Runs n times
        for (int j = 0; j <= i; j++) {     // Runs (i+1) times
            cout << "*";
        }
        cout << endl;
    }
}
```

**Analysis:**
```
When i = 0: inner loop runs 1 time
When i = 1: inner loop runs 2 times
When i = 2: inner loop runs 3 times
...
When i = n-1: inner loop runs n times

Total = 1 + 2 + 3 + ... + n = n(n+1)/2 = (n² + n)/2
```

**Applying the three rules:**
1. Worst case: All iterations complete
2. Remove constants: $(n^2 + n)/2$ → $n^2 + n$
3. Remove lower values: $n^2 + n$ → $n^2$

**Time Complexity:** $O(n^2)$

---

### Example 3: Sequential Loops

```cpp
void process(int n) {
    for (int i = 0; i < n; i++) {      // n operations
        cout << i;
    }
    
    for (int i = 0; i < n; i++) {      // n operations
        for (int j = 0; j < n; j++) {  // n² operations
            cout << i * j;
        }
    }
}
```

**Analysis:** $n + n^2$  
**Time Complexity:** $O(n^2)$ (ignoring lower term $n$)

---

### Example 4: Logarithmic Loop

```cpp
void halvingLoop(int n) {
    for (int i = 1; i < n; i = i * 2) {  // Doubles each time
        cout << i << " ";
    }
}
// Output for n=16: 1 2 4 8
```

**Analysis:**
```
Iteration 1: i = 1
Iteration 2: i = 2
Iteration 3: i = 4
Iteration 4: i = 8
...
Iteration k: i = 2^k where 2^k < n

Solving: 2^k = n → k = log₂(n)
```

**Time Complexity:** $O(\log n)$

---

### Example 5: Triple Nested Loop

```cpp
void threeLevels(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << i + j + k;
            }
        }
    }
}
```

**Analysis:** $n \times n \times n = n^3$  
**Time Complexity:** $O(n^3)$

---

### Example 6: Square Root Loop

```cpp
void sqrtLoop(int n) {
    for (int i = 1; i * i < n; i++) {
        cout << i << " ";
    }
}
```

**Analysis:**
```
Loop continues while i² < n
Maximum value: i = √n
```

**Time Complexity:** $O(\sqrt{n})$

---

## Space Complexity

**Definition:** Total memory space a program uses relative to input size

### Formula
```
Space Complexity = Input Space + Auxiliary Space
```

- **Input Space:** Memory to store input data (usually given, can't optimize)
- **Auxiliary Space:** Extra memory used to solve the problem (what we optimize)

---

### Example 1: No Extra Space

```cpp
int sum(int arr[], int n) {
    int total = 0;           // O(1) space
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}
```

**Space Complexity:**
- Input space: $O(n)$ for array
- Auxiliary space: $O(1)$ for `total` and `i`
- **Total:** $O(n)$, but we say **auxiliary space is $O(1)$**

---

### Example 2: Creating New Array

```cpp
int* doubleArray(int arr[], int n) {
    int* result = new int[n];    // O(n) auxiliary space
    for (int i = 0; i < n; i++) {
        result[i] = arr[i] * 2;
    }
    return result;
}
```

**Space Complexity:**
- Input: $O(n)$
- Auxiliary: $O(n)$ for `result` array
- **Total: $O(n) + O(n) = O(n)$**

---

### Example 3: Recursive Space (Call Stack)

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

**Space Complexity:** $O(n)$
- Each recursive call adds a frame to call stack
- Maximum depth: $n$ frames

**Call Stack Visualization:**
```
factorial(5)
    → factorial(4)
        → factorial(3)
            → factorial(2)
                → factorial(1) [returns]
```
Maximum $n$ frames in memory at once.

---

### Example 4: Matrix Space

```cpp
void createMatrix(int n) {
    int matrix[n][n];  // n × n = n² space
    // ... operations
}
```

**Space Complexity:** $O(n^2)$

---

### Critical Interview Tip ⚠️

**NEVER modify input data unless explicitly told to do so!**

```cpp
// ❌ BAD - Modifies input
void process(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * 2;  // Changing original data!
    }
}

// ✅ GOOD - Preserves input
vector<int> process(int arr[], int n) {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = arr[i] * 2;  // Original unchanged
    }
    return result;
}
```

**Why?**
- **Software Engineering Best Practice:** Input data might be needed elsewhere
- **Debugging:** Original data helps trace bugs
- **Testing:** Need original values for verification
- **Production:** Other parts of system may depend on unchanged data

**Exception:** Interviewer explicitly says "you can modify the input array" or "do it in-place"

---

## Competitive Programming Guidelines

### Server Capacity
Most online judges (LeetCode, Codeforces, CodeChef) can execute approximately:

**$10^8$ operations per second**

### Time Limit Strategy

For a **1-second time limit**, your algorithm should perform **≤ $10^8$ operations**

#### Quick Reference Table

| Input Size ($n$) | Max Acceptable Complexity | Algorithm Examples |
|------------------|---------------------------|-------------------|
| $n \leq 10$ | $O(n!)$, $O(n^6)$ | Permutations, brute force |
| $n \leq 20$ | $O(2^n)$ | Subset generation, bitmask DP |
| $n \leq 500$ | $O(n^3)$ | Floyd-Warshall, DP with 3 states |
| $n \leq 5,000$ | $O(n^2)$ | Nested loops, simple DP |
| $n \leq 10^6$ | $O(n \log n)$ | Sorting, binary search, heap |
| $n \leq 10^8$ | $O(n)$ | Single pass, linear DP |
| $n > 10^8$ | $O(\log n)$ or $O(1)$ | Binary search, math formula |

### Example Decision Making

**Problem:** Array of size $n = 10^5$, time limit = 1 second

**Should I use $O(n^2)$ bubble sort?**
- Operations: $(10^5)^2 = 10^{10}$
- Limit: $10^8$
- Decision: ❌ **NO** - Will get Time Limit Exceeded (TLE)

**Should I use $O(n \log n)$ merge sort?**
- Operations: $10^5 \times \log_2(10^5) \approx 10^5 \times 17 = 1.7 \times 10^6$
- Limit: $10^8$
- Decision: ✅ **YES** - Will pass comfortably

---

### Practical Tips

1. **Quick estimation:** If $n \times$ (complexity factor) $> 10^8$, likely TLE
2. **Constants matter in practice:** $O(n)$ with large constants might be slower than efficient $O(n \log n)$
3. **Worst case input:** Judges use worst-case inputs, so your worst-case analysis must be solid
4. **Memory limit:** Usually 256 MB, roughly $\approx 6.4 \times 10^7$ integers

---

## Quick Reference

### Time Complexity Cheat Sheet

| Code Pattern | Complexity | Example |
|--------------|-----------|---------|
| Single loop `for(i=0; i<n; i++)` | $O(n)$ | Linear search |
| Nested loops (fixed) | $O(n^2)$ | Bubble sort |
| Nested loops (dependent) | $O(n^2)$ | Triangle pattern |
| Binary search | $O(\log n)$ | Search in sorted array |
| Merge/Quick sort | $O(n \log n)$ | Efficient sorting |
| Recursive (divide by 2) | $O(\log n)$ | Binary search tree |
| Recursive (2 calls) | $O(2^n)$ | Fibonacci (naive) |
| Triple nested loops | $O(n^3)$ | Matrix multiplication |
| `while(i*=2)` or `while(i/=2)` | $O(\log n)$ | Halving/doubling |
| `while(i*=k)` | $O(\log_k n)$ | K-ary search |
| `while(i*i < n)` | $O(\sqrt{n})$ | Prime factorization |

### Space Complexity Patterns

| Scenario | Space | Example |
|----------|-------|---------|
| Few variables | $O(1)$ | Swap two numbers |
| Single array/list | $O(n)$ | Linear search result |
| 2D array | $O(n^2)$ | Matrix |
| Recursive depth $d$ | $O(d)$ | Factorial recursion |
| Hash map/set | $O(n)$ | Frequency counter |

### The Three Rules Checklist

✅ **Rule 1:** Always analyze **worst case**  
✅ **Rule 2:** Drop all **constants** ($5n$ → $n$)  
✅ **Rule 3:** Keep only **dominant term** ($n^2 + n$ → $n^2$)

---

## Practice Problems

### Beginner
1. Find time complexity of a single loop
2. Analyze nested loops
3. Calculate space for recursive functions

### Intermediate
4. Analyze dependent nested loops
5. Combine time complexity of sequential code blocks
6. Optimize $O(n^2)$ to $O(n \log n)$

### Advanced
7. Analyze recursive algorithms with multiple branches
8. Master Theorem for recurrence relations
9. Amortized analysis (dynamic array resizing)

---

## Common Mistakes to Avoid

❌ Confusing time complexity with actual runtime  
❌ Forgetting to consider worst case  
❌ Not simplifying using the three rules  
❌ Modifying input data without permission  
❌ Ignoring recursion call stack space  
❌ Choosing algorithm based only on best case  
❌ Not considering competitive programming constraints

---

## Pro Tips for Interviews

💡 **Communicate:** Always explain your thought process  
💡 **Start with brute force:** Then optimize if needed  
💡 **State complexity:** Clearly mention both time and space  
💡 **Trade-offs:** Sometimes $O(n)$ time vs $O(1)$ space is acceptable  
💡 **Know sorting:** $O(n \log n)$ is often the goal for optimization  
💡 **Hash maps are gold:** Often reduce $O(n^2)$ to $O(n)$

---

**Video Reference:** [Time and Space Complexity Tutorial](https://youtu.be/FPu9Uld7W-E?si=0pdwIMqskaYP52hq)

**Created for DSA Revision** 📚

---

Happy Learning! 🚀
