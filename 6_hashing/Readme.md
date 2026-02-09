# 📚 Complete Hashing Notes - DSA

**Source:** [Striver's Hashing Video](https://youtu.be/KEs5UyBJ39g)  
**Topic:** Hashing - Pre-storing and Fetching  
**Date:** Study Notes for Future Revision

---

## 🎯 Table of Contents
1. [Core Problem & Brute Force](#1-core-problem--brute-force)
2. [Hashing Concept](#2-hashing-concept)
3. [Number Hashing (Array-based)](#3-number-hashing-array-based)
4. [Array Size Limits & Memory Constraints](#4-array-size-limits--memory-constraints)
5. [Character Hashing](#5-character-hashing)
6. [Maps & Unordered Maps](#6-maps--unordered-maps)
7. [Internal Implementation & Collisions](#7-internal-implementation--collisions)
8. [Key Types & Constraints](#8-key-types--constraints)
9. [Time & Space Complexity Summary](#9-time--space-complexity-summary)
10. [Important Tips & Best Practices](#10-important-tips--best-practices)
11. [Practice Problems](#11-practice-problems)

---

---

## 1. Core Problem & Brute Force

### 📌 Problem Statement
Given an array and **Q queries**, find how many times a specific number appears in the array.

**Example:**
```
Array: [1, 2, 1, 3, 2]
Queries: [1, 5, 2]

Output:
1 appears 2 times
5 appears 0 times
2 appears 2 times
```

---

### ❌ Brute Force Approach

**Method:** For each query, iterate through the entire array and count.

```cpp
for (int i = 0; i < Q; i++) {
    int x = queries[i];
    int count = 0;
    
    for (int j = 0; j < N; j++) {
        if (arr[j] == x) count++;
    }
    
    cout << x << " appears " << count << " times\n";
}
```

**Time Complexity:** `O(Q × N)`

**Problem:**
- If Q = 10⁵ and N = 10⁵
- Total operations = 10¹⁰
- Time = 10¹⁰ / 10⁸ = **100 seconds** ⚠️
- Most platforms have **1-2 second** time limit
- Result: **TLE (Time Limit Exceeded)** ❌

> **⏰ Time Limit Rule:** Most competitive programming platforms allow ~10⁸ operations per second.

---

---

## 2. Hashing Concept

### 🔑 Definition
**Hashing = Pre-storing + Fetching**

Instead of counting every time, we:
1. **Pre-store** all frequencies once → O(N)
2. **Fetch** instantly when queried → O(1)

---

### ✅ Hashing Approach

**Step 1:** Create a hash array where:
- **Index** = the number
- **Value at index** = frequency of that number

**Step 2:** Pre-compute frequencies

**Step 3:** Answer queries in O(1)

```cpp
// Step 1: Create hash array
int hash[13] = {0};

// Step 2: Pre-store
for (int i = 0; i < N; i++) {
    hash[arr[i]]++;
}

// Step 3: Fetch
for (int i = 0; i < Q; i++) {
    int x = queries[i];
    cout << x << " appears " << hash[x] << " times\n";
}
```

**Time Complexity:** `O(N + Q)` ✅

**Example:**
- N = 10⁵, Q = 10⁵
- Operations = 2 × 10⁵
- Time = **0.002 seconds** 🚀

---

---

## 3. Number Hashing (Array-based)

### 📊 Complete Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Pre-computation
    int hash[13] = {0}; // Assuming max element is 12
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    
    // Queries
    int q;
    cin >> q;
    
    while (q--) {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
    
    return 0;
}
```

---

### 🔍 Dry Run Example

**Input:**
```
Array: [1, 2, 1, 3, 2]
```

**Pre-storing Process:**

| Step | arr[i] | Operation | Hash Array State |
|------|--------|-----------|------------------|
| Initial | - | - | [0,0,0,0,0,...] |
| i=0 | 1 | hash[1]++ | [0,1,0,0,0,...] |
| i=1 | 2 | hash[2]++ | [0,1,1,0,0,...] |
| i=2 | 1 | hash[1]++ | [0,2,1,0,0,...] |
| i=3 | 3 | hash[3]++ | [0,2,1,1,0,...] |
| i=4 | 2 | hash[2]++ | [0,2,2,1,0,...] |

**Final Hash Array:**
```
Index: [0][1][2][3][4][5]...
Value: [0][2][2][1][0][0]...
       ↑  ↑  ↑  ↑
       0  1  2  3
```

**Queries:**
- `hash[1]` → 2 (instant!)
- `hash[5]` → 0 (instant!)
- `hash[2]` → 2 (instant!)

---

---

## 4. Array Size Limits & Memory Constraints

### 🚨 CRITICAL MEMORY RULES

#### **Inside `main()` (Local/Stack Memory)**

| Data Type | Maximum Size | Memory |
|-----------|--------------|--------|
| `int` | ~10⁶ (1 million) | 4 MB |
| `bool` | ~10⁷ (10 million) | 1.25 MB |

```cpp
int main() {
    int hash[1000000]; // ✅ OK
    int hash[10000000]; // ❌ Segmentation Fault
    
    bool hash[10000000]; // ✅ OK (bool uses less space)
}
```

---

#### **Global Declaration (Heap Memory)**

| Data Type | Maximum Size | Memory |
|-----------|--------------|--------|
| `int` | ~10⁷ (10 million) | 40 MB |
| `bool` | ~10⁸ (100 million) | 12.5 MB |

```cpp
int hash[10000000]; // ✅ OK (global)

int main() {
    // Use hash array here
}
```

---

### ⚠️ When Array Hashing Fails

**Problem:** If numbers are too large (e.g., 10⁹ or 10¹⁸)

```cpp
Array: [1000000000, 999999999, 1000000001]

// Need: hash[1000000000]
// Size: 10^9 integers = 4 GB ❌ NOT POSSIBLE
```

**Solution:** Use **Maps** instead! 🗺️

---

### 📝 Memory Limit Summary Table

| Scenario | Max Array Size | Where to Declare |
|----------|----------------|------------------|
| Numbers ≤ 10⁶ | 10⁶ | Inside `main()` |
| Numbers ≤ 10⁷ | 10⁷ | Global |
| Numbers > 10⁷ | - | Use Map/Unordered Map |

---

---

## 5. Character Hashing

### 🔤 Method 1: Lowercase Letters Only (26 slots)

**Concept:** Map 'a'-'z' to indices 0-25

**Formula:** `index = char - 'a'`

**Example:**
```
'a' - 'a' = 97 - 97 = 0
'b' - 'a' = 98 - 97 = 1
'c' - 'a' = 99 - 97 = 2
...
'z' - 'a' = 122 - 97 = 25
```

---

#### **Implementation:**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    // Pre-compute
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        hash[s[i] - 'a']++;
    }
    
    // Query
    int q;
    cin >> q;
    
    while (q--) {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
    
    return 0;
}
```

---

#### **Dry Run:**

**String:** `"abcdabefc"`

| i | s[i] | s[i] - 'a' | Operation | Hash State |
|---|------|------------|-----------|------------|
| 0 | 'a' | 0 | hash[0]++ | [1,0,0,...] |
| 1 | 'b' | 1 | hash[1]++ | [1,1,0,...] |
| 2 | 'c' | 2 | hash[2]++ | [1,1,1,...] |
| 3 | 'd' | 3 | hash[3]++ | [1,1,1,1,...] |
| 4 | 'a' | 0 | hash[0]++ | [2,1,1,1,...] |
| 5 | 'b' | 1 | hash[1]++ | [2,2,1,1,...] |
| 6 | 'e' | 4 | hash[4]++ | [2,2,1,1,1,...] |
| 7 | 'f' | 5 | hash[5]++ | [2,2,1,1,1,1,...] |
| 8 | 'c' | 2 | hash[2]++ | [2,2,2,1,1,1,...] |

**Final:**
```
Index: [a][b][c][d][e][f][g]...
Value: [2][2][2][1][1][1][0]...
```

---

### 🔤 Method 2: All Characters (256 ASCII)

**Concept:** Use the character's ASCII value directly as index

**No subtraction needed!**

```cpp
int hash[256] = {0};

for (int i = 0; i < s.length(); i++) {
    hash[s[i]]++; // C++ automatically converts char to ASCII
}

// Query
char c;
cin >> c;
cout << hash[c] << endl; // Direct access
```

---

#### **ASCII Values Reference:**

| Character | ASCII Value |
|-----------|-------------|
| 'A' - 'Z' | 65 - 90 |
| 'a' - 'z' | 97 - 122 |
| '0' - '9' | 48 - 57 |
| Space ' ' | 32 |
| '!' | 33 |

---

#### **Example:**

**String:** `"Hello World!"`

```
'H' = 72 → hash[72]++
'e' = 101 → hash[101]++
'l' = 108 → hash[108]++ (appears 3 times)
'o' = 111 → hash[111]++ (appears 2 times)
' ' = 32 → hash[32]++
'W' = 87 → hash[87]++
'r' = 114 → hash[114]++
'd' = 100 → hash[100]++
'!' = 33 → hash[33]++
```

**Query:**
```cpp
cout << hash['l']; // Output: 3
cout << hash['o']; // Output: 2
```

---

### ⚠️ Important: Uppercase vs Lowercase

**Problem with Method 1:**

```cpp
int hash[26] = {0};
char c = 'C'; // Uppercase

int index = c - 'a';
// 'C' = 67, 'a' = 97
// index = 67 - 97 = -30 ❌ NEGATIVE INDEX!
```

**This causes:**
- **Undefined Behavior** (accessing memory before array)
- **Segmentation Fault** (possible crash)
- **Random values** (if memory contains garbage)

---

**Solution:**

**Option 1:** Use 256-size array
```cpp
int hash[256] = {0};
hash['C']++; // Safe! Index = 67
hash['c']++; // Safe! Index = 99
```

**Option 2:** Use Map
```cpp
unordered_map<char, int> mpp;
mpp['C']++; // Safe!
mpp['c']++; // Safe!
```

---

### 📊 Character Hashing Decision Tree

```
What type of characters?
│
├─ Only lowercase (a-z)
│  └─> Use hash[26] with (char - 'a')
│
├─ Only uppercase (A-Z)
│  └─> Use hash[26] with (char - 'A')
│
├─ Mixed case or special characters
│  └─> Use hash[256] with direct ASCII
│
└─ Very large character set (Unicode, etc.)
   └─> Use unordered_map<char, int>
```

---

---

## 6. Maps & Unordered Maps

### 🗺️ When to Use Maps?

**Problem:** Numbers are too large for arrays

**Example:**
```cpp
Array: [1000000000, 2, 1000000000, 3, 2]
// Need hash[1000000000] = impossible!
```

**Solution:** Maps store only elements that exist!

---

---

### 📘 Type 1: `std::map` (Ordered Map)

#### **Features:**
✅ Stores keys in **sorted order**  
✅ Implemented using **Red-Black Tree** (self-balancing BST)  
✅ Time Complexity: **O(log N)** for insert/search/delete  

---

#### **Syntax:**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> mpp; // <key_type, value_type>
    
    // Insert/Update
    mpp[1] = 5;
    mpp[2] = 3;
    mpp[3]++; // Increment
    
    // Access
    cout << mpp[1]; // 5
    cout << mpp[100]; // 0 (returns 0 if key doesn't exist)
    
    // Check existence
    if (mpp.find(2) != mpp.end()) {
        cout << "Found!";
    }
    
    // Iterate (sorted order!)
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }
    
    return 0;
}
```

---

#### **Complete Example:**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Pre-compute
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    
    // Queries
    int q;
    cin >> q;
    
    while (q--) {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
    
    return 0;
}
```

---

#### **Dry Run:**

**Array:** `[1000000000, 2, 1000000000, 3, 2]`

**Pre-storing:**

| Step | Element | Operation | Map State |
|------|---------|-----------|-----------|
| 1 | 1000000000 | mpp[1000000000]++ | {1000000000→1} |
| 2 | 2 | mpp[2]++ | {2→1, 1000000000→1} (sorted!) |
| 3 | 1000000000 | mpp[1000000000]++ | {2→1, 1000000000→2} |
| 4 | 3 | mpp[3]++ | {2→1, 3→1, 1000000000→2} |
| 5 | 2 | mpp[2]++ | {2→2, 3→1, 1000000000→2} |

**Final Map (sorted by key):**
```
{
    2 → 2,
    3 → 1,
    1000000000 → 2
}
```

**Key Advantage:** Only 3 entries instead of 1 billion! 🎉

---

#### **Iterating Through Map:**

```cpp
// Method 1: Range-based for loop
for (auto it : mpp) {
    cout << it.first << " -> " << it.second << endl;
}

// Method 2: Iterator
for (auto it = mpp.begin(); it != mpp.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
}

// Output (always sorted):
// 2 -> 2
// 3 -> 1
// 1000000000 -> 2
```

---

---

### 📗 Type 2: `std::unordered_map` (Hash Map)

#### **Features:**
✅ **No specific order** (faster than map)  
✅ Implemented using **Hash Table with Chaining**  
✅ Time Complexity:  
   - **Average/Best Case:** O(1)  
   - **Worst Case:** O(N) (rare, due to collisions)

---

#### **Syntax:**

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> mpp;
    
    mpp[1] = 5;
    mpp[2] = 3;
    mpp[5]++;
    
    cout << mpp[1]; // 5
    
    // Iterate (random order!)
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }
    
    return 0;
}
```

---

#### **Same Example with Unordered Map:**

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1000000000, 2, 1000000000, 3, 2};
    int n = 5;
    
    unordered_map<int, int> mpp;
    
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    
    // Query
    cout << mpp[1000000000]; // 2
    cout << mpp[2]; // 2
    
    return 0;
}
```

**Final Map (random order):**
```
Possible output:
{
    1000000000 → 2,
    3 → 1,
    2 → 2
}

OR

{
    2 → 2,
    1000000000 → 2,
    3 → 1
}
```

**Order is unpredictable!** But **O(1) access** 🚀

---

---

### ⚖️ Map vs Unordered Map Comparison

| Feature | `map` | `unordered_map` |
|---------|-------|-----------------|
| **Ordering** | Sorted (ascending by key) | No order |
| **Implementation** | Red-Black Tree (BST) | Hash Table |
| **Insert** | O(log N) | O(1) average, O(N) worst |
| **Search** | O(log N) | O(1) average, O(N) worst |
| **Delete** | O(log N) | O(1) average, O(N) worst |
| **Space** | O(N) | O(N) |
| **When to Use** | Need sorted order | Need speed |
| **Cache Performance** | Better (tree traversal) | Can be worse |

---

### 🎯 Which One to Choose?

#### **Strategy:**

```
1. Start with unordered_map (faster on average)
   ↓
2. If you get TLE (Time Limit Exceeded)
   ↓
3. Switch to map
   ↓
4. If you need sorted output
   ↓
   Use map from the beginning
```

---

#### **Example Scenarios:**

| Requirement | Use |
|-------------|-----|
| Just need frequency | `unordered_map` |
| Need sorted output | `map` |
| Getting TLE with unordered_map | `map` |
| Numbers > 10⁷ | Either map |
| Need fastest average time | `unordered_map` |

---

### 📌 Important Map Operations

```cpp
unordered_map<int, int> mpp;

// Insert/Update
mpp[key] = value;
mpp[key]++; // Increment

// Access
int val = mpp[key]; // Returns 0 if key doesn't exist

// Check if key exists
if (mpp.find(key) != mpp.end()) {
    // Key exists
}

// Or use count
if (mpp.count(key)) {
    // Key exists
}

// Erase
mpp.erase(key);

// Size
int size = mpp.size();

// Clear all
mpp.clear();
```

---

---

## 7. Internal Implementation & Collisions

### 🔧 How Does Hashing Work Internally?

When you use `unordered_map`, it uses a **hash function** to convert keys into array indices.

---

### 🎲 The Division Method

**Most common internal hashing technique**

**Formula:**
```
hash_index = key % table_size
```

**Example:**
```
Table size = 10

Number 18 → 18 % 10 = 8 (store at index 8)
Number 25 → 25 % 10 = 5 (store at index 5)
Number 8  → 8 % 10 = 8  (store at index 8) ⚠️
Number 28 → 28 % 10 = 8 (store at index 8) ⚠️
```

---

### 💥 What is a Collision?

**Collision:** When two different keys hash to the **same index**

**Example:**
```
8 % 10 = 8
18 % 10 = 8
28 % 10 = 8
38 % 10 = 8

All map to index 8 → COLLISION!
```

---

### 🔗 Handling Collisions: Linear Chaining

**Technique:** Store multiple elements at the same index using a **linked list**

---

#### **Visual Representation:**

```
Hash Table (size 10):

Index 0: []
Index 1: []
Index 2: [42]
Index 3: [33] → [73]
Index 4: []
Index 5: [25]
Index 6: []
Index 7: []
Index 8: [8] → [18] → [28] → [38]  (chained!)
Index 9: []
```

---

#### **How Search Works:**

**Searching for 28:**

1. Calculate hash: `28 % 10 = 8`
2. Go to index 8
3. Traverse linked list: `8 → 18 → 28` ✅ Found!

**Time:** Depends on chain length

---

### ⏱️ Time Complexity Analysis

#### **Best Case (No Collisions):**
- Each index has exactly 1 element
- Direct access: **O(1)**

```
Index 0: [10]
Index 1: [21]
Index 2: [32]
Index 3: [43]
...
```

---

#### **Average Case (Few Collisions):**
- Good hash function distributes elements evenly
- Each index has ~2-3 elements
- Still **O(1)** on average

```
Index 0: [10]
Index 1: [21] → [31]
Index 2: [32]
Index 3: [43] → [53] → [63]
...
```

---

#### **Worst Case (All Collisions):**
- All elements hash to the **same index**
- Forms a linear linked list
- Search/Insert/Delete: **O(N)** ❌

```
Index 0: []
Index 1: []
...
Index 8: [8] → [18] → [28] → [38] → [48] → [58] → ...
...
```

**Example:**
```
Numbers: [10, 20, 30, 40, 50, 60, 70]
Table size: 10
All hash to: 10 % 10 = 0

Index 0: [10] → [20] → [30] → [40] → [50] → [60] → [70]
```

Searching for 70 requires checking all 7 elements → O(N)

---

### 🎯 Why Unordered Map is O(1) Average

**Good hash functions:**
- Distribute keys **uniformly** across table
- Minimize collisions
- Keep chains short

**Example of Good Distribution:**
```
Keys: [18, 25, 8, 33, 42, 17, 51, 64, 73, 99]
Table size: 10

18 % 10 = 8
25 % 10 = 5
8 % 10 = 8
33 % 10 = 3
42 % 10 = 2
17 % 10 = 7
51 % 10 = 1
64 % 10 = 4
73 % 10 = 3
99 % 10 = 9

Distribution:
Index 1: [51]
Index 2: [42]
Index 3: [33] → [73]  (small chain)
Index 4: [64]
Index 5: [25]
Index 7: [17]
Index 8: [18] → [8]   (small chain)
Index 9: [99]

Most indices: 1-2 elements → O(1) ✅
```

---

### 🔍 Internal Hash Table Structure

```cpp
// Simplified internal structure
class UnorderedMap {
    struct Node {
        int key;
        int value;
        Node* next;
    };
    
    vector<Node*> table; // Array of linked lists
    int table_size;
    
    int hash(int key) {
        return key % table_size;
    }
    
    void insert(int key, int value) {
        int index = hash(key);
        // Insert at table[index] (chaining)
    }
};
```

---

---

## 8. Key Types & Constraints

### 🗝️ What Can Be Used as Keys?

#### **`map` (More Flexible)**

✅ Can use almost any data type:
- Primitive types: `int`, `long`, `double`, `string`
- **Pairs:** `pair<int, int>`
- **Vectors:** Not recommended but possible

```cpp
map<int, int> m1; // ✅
map<string, int> m2; // ✅
map<pair<int, int>, int> m3; // ✅
map<char, int> m4; // ✅
```

**Example with Pair:**
```cpp
map<pair<int, int>, string> mpp;

mpp[{1, 2}] = "Point A";
mpp[{3, 4}] = "Point B";

cout << mpp[{1, 2}]; // "Point A"
```

---

#### **`unordered_map` (Restricted)**

⚠️ Can only use types with predefined hash functions:
- Primitive types: `int`, `long`, `double`, `string`
- **Cannot use:** `pair`, `vector` (without custom hash)

```cpp
unordered_map<int, int> m1; // ✅
unordered_map<string, int> m2; // ✅
unordered_map<pair<int, int>, int> m3; // ❌ ERROR!
```

**Why?**
- Unordered map needs a hash function
- Pairs don't have a default hash function

---

#### **Using Pair in Unordered Map (Advanced)**

You need to provide a **custom hash function**:

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

unordered_map<pair<int, int>, int, PairHash> mpp;
mpp[{1, 2}] = 5; // ✅ Now it works
```

**Recommendation:** Just use `map` if you need pair keys!

---

### 📊 Key Type Summary

| Key Type | `map` | `unordered_map` |
|----------|-------|-----------------|
| `int` | ✅ | ✅ |
| `long` | ✅ | ✅ |
| `double` | ✅ | ✅ |
| `string` | ✅ | ✅ |
| `char` | ✅ | ✅ |
| `pair<int, int>` | ✅ | ❌ (need custom hash) |
| `vector<int>` | ❌ (not recommended) | ❌ |

---

---

## 9. Time & Space Complexity Summary

### ⏱️ Complete Complexity Table

| Technique | Pre-store | Query | Space | Range Limit |
|-----------|-----------|-------|-------|-------------|
| **Array (local)** | O(N) | O(1) | O(max_value) | ≤ 10⁶ |
| **Array (global)** | O(N) | O(1) | O(max_value) | ≤ 10⁷ |
| **Map** | O(N log N) | O(log N) | O(unique) | Any |
| **Unordered Map** | O(N) avg | O(1) avg | O(unique) | Any |

---

### 🔍 Detailed Analysis

#### **1. Array Hashing**
```
Pre-store: for (int i = 0; i < N; i++) hash[arr[i]]++;
→ O(N)

Query: cout << hash[x];
→ O(1)

Space: hash[MAX_VALUE]
→ O(MAX_VALUE)
```

**When MAX_VALUE is small:** Very efficient!  
**When MAX_VALUE is large:** Wastes memory!

---

#### **2. Map (Ordered)**
```
Pre-store: for (int i = 0; i < N; i++) mpp[arr[i]]++;
→ O(N log N) (each insertion is O(log N))

Query: cout << mpp[x];
→ O(log N) (tree search)

Space: Only stores unique elements
→ O(number of unique elements)
```

---

#### **3. Unordered Map**
```
Pre-store: for (int i = 0; i < N; i++) mpp[arr[i]]++;
→ O(N) average (each insertion is O(1) average)

Query: cout << mpp[x];
→ O(1) average, O(N) worst

Space: Only stores unique elements
→ O(number of unique elements)
```

---

### 📈 Real-World Performance

**Test Case:** N = 10⁵, Q = 10⁵, Numbers range up to 10⁹

| Method | Pre-store Time | Query Time | Total Time |
|--------|----------------|------------|------------|
| Brute Force | - | O(Q × N) | 10¹⁰ ops (~100s) ❌ |
| Array | - | - | Can't use (too large) |
| Map | O(N log N) | O(Q log N) | ~10⁶ ops (~0.01s) ✅ |
| Unordered Map | O(N) | O(Q) | ~2×10⁵ ops (~0.002s) 🚀 |

---

---

## 10. Important Tips & Best Practices

### 💡 Tip 1: Array Size Limits (CRITICAL)

```cpp
// Inside main()
int hash[1000000]; // ✅ OK (~10^6)
int hash[10000000]; // ❌ Segmentation Fault

// Global
int hash[10000000]; // ✅ OK (~10^7)

// Boolean arrays use less memory
bool hash[10000000]; // ✅ OK inside main() (~10^7)
```

**Rule:** Always check if your numbers fit within array limits!

---

### 💡 Tip 2: Character Hashing Warning

```cpp
// WRONG for uppercase
int hash[26] = {0};
char c = 'C';
hash[c - 'a']++; // ❌ Negative index! Undefined behavior

// CORRECT
int hash[256] = {0};
hash[c]++; // ✅ Works for any character
```

**Lesson:** Use 256-size array for mixed-case strings!

---

### 💡 Tip 3: Map Performance Strategy

```
Always start with: unordered_map
↓
If TLE occurs
↓
Switch to: map
```

**Why?**
- `unordered_map` is O(1) average (faster)
- Worst case O(N) is **rare** in practice
- `map` is reliable O(log N) always

---

### 💡 Tip 4: Pre-computation Optimization

You can combine input and pre-computation:

```cpp
// Method 1: Separate loops
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
}

// Method 2: Combined (saves one loop)
for (int i = 0; i < n; i++) {
    cin >> arr[i];
    hash[arr[i]]++; // Pre-compute while taking input
}
```

**Note:** Both are still O(N), but Method 2 is slightly faster in practice!

---

### 💡 Tip 5: When Maps Return 0

```cpp
map<int, int> mpp;
cout << mpp[100]; // Prints 0 (key doesn't exist)

// This CREATES the key with value 0!
mpp[100]; // Now mpp = {100 → 0}
```

**Safe way to check:**
```cpp
if (mpp.find(100) != mpp.end()) {
    cout << mpp[100];
} else {
    cout << "Not found";
}
```

---

### 💡 Tip 6: Avoid Accessing Non-existent Keys

```cpp
unordered_map<int, int> mpp;

// BAD: Creates key with value 0
int val = mpp[999]; // mpp now has {999 → 0}

// GOOD: Check first
if (mpp.count(999)) {
    int val = mpp[999];
}
```

---

### 💡 Tip 7: Time Limit Expectations

**Competitive Programming Standards:**
- **10⁸ operations** ≈ 1 second
- **10⁶ operations** ≈ 0.01 second
- **10¹⁰ operations** ≈ 100 seconds (TLE!)

**Target complexity:**
- N ≤ 10⁵ → O(N log N) or better
- N ≤ 10⁶ → O(N) or better
- N ≤ 10⁸ → O(N) with tight constant

---

### 💡 Tip 8: Space vs Time Tradeoff

Hashing **trades space for time**:

```
Without Hashing:
- Time: O(Q × N)
- Space: O(1)

With Hashing:
- Time: O(N + Q)
- Space: O(N) or O(unique elements)
```

**Worth it?** Almost always YES in competitive programming!

---

### 💡 Tip 9: Character Auto-conversion

```cpp
int hash[256] = {0};
char c = 'A';

// These are equivalent:
hash[c]++;
hash['A']++;
hash[65]++; // ASCII value of 'A'
```

C++ automatically converts `char` to `int` (ASCII value)!

---

### 💡 Tip 10: Global vs Local Declaration

```cpp
// Global (outside main)
int hashGlobal[10000000]; // ✅ Works

int main() {
    // Local (inside main)
    int hashLocal[10000000]; // ❌ Segmentation Fault
    
    // Solution: Use global or reduce size
}
```

**When in doubt:** Declare globally!

---

---

## 11. Practice Problems

### 🎯 Beginner Level

#### **Problem 1: Frequency Count**
Count frequency of each element in array

**Input:**
```
[1, 2, 1, 3, 2, 2]
```

**Output:**
```
1 → 2
2 → 3
3 → 1
```

**Solution:**
```cpp
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

---

#### **Problem 2: First Non-Repeating Character**
Find first character that appears only once

**Input:**
```
"aabbcde"
```

**Output:**
```
c
```

**Solution:**
```cpp
int hash[26] = {0};
for (char c : s) hash[c - 'a']++;

for (char c : s) {
    if (hash[c - 'a'] == 1) {
        cout << c;
        break;
    }
}
```

---

#### **Problem 3: Check if Two Strings are Anagrams**
Two strings are anagrams if they have same character frequencies

**Input:**
```
s1 = "listen"
s2 = "silent"
```

**Output:**
```
Yes
```

**Solution:**
```cpp
int hash1[26] = {0}, hash2[26] = {0};

for (char c : s1) hash1[c - 'a']++;
for (char c : s2) hash2[c - 'a']++;

bool isAnagram = true;
for (int i = 0; i < 26; i++) {
    if (hash1[i] != hash2[i]) {
        isAnagram = false;
        break;
    }
}
```

---

### 🎯 Intermediate Level

#### **Problem 4: Two Sum**
Find two numbers that add up to target

**Input:**
```
arr = [2, 7, 11, 15]
target = 9
```

**Output:**
```
Indices: 0, 1 (values: 2, 7)
```

**Solution:**
```cpp
unordered_map<int, int> mpp;

for (int i = 0; i < n; i++) {
    int complement = target - arr[i];
    
    if (mpp.find(complement) != mpp.end()) {
        cout << mpp[complement] << " " << i;
        return;
    }
    
    mpp[arr[i]] = i;
}
```

**Time:** O(N), **Space:** O(N)

---

#### **Problem 5: Longest Substring Without Repeating**
Find length of longest substring with unique characters

**Input:**
```
"abcabcbb"
```

**Output:**
```
3 ("abc")
```

**Solution:**
```cpp
unordered_map<char, int> lastSeen;
int maxLen = 0, start = 0;

for (int end = 0; end < s.length(); end++) {
    if (lastSeen.find(s[end]) != lastSeen.end()) {
        start = max(start, lastSeen[s[end]] + 1);
    }
    
    lastSeen[s[end]] = end;
    maxLen = max(maxLen, end - start + 1);
}
```

---

#### **Problem 6: Highest and Lowest Frequency Element**
Find elements with max and min frequency

**Input:**
```
[1, 2, 2, 3, 3, 3]
```

**Output:**
```
Highest frequency: 3 (appears 3 times)
Lowest frequency: 1 (appears 1 time)
```

**Solution:**
```cpp
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;

int maxFreq = 0, minFreq = INT_MAX;
int maxElem, minElem;

for (auto it : freq) {
    if (it.second > maxFreq) {
        maxFreq = it.second;
        maxElem = it.first;
    }
    if (it.second < minFreq) {
        minFreq = it.second;
        minElem = it.first;
    }
}
```

---

### 🎯 Advanced Level

#### **Problem 7: Subarray Sum Equals K**
Count subarrays with sum equal to K

**Input:**
```
arr = [1, 2, 3]
K = 3
```

**Output:**
```
2 (subarrays: [3], [1, 2])
```

**Solution:**
```cpp
unordered_map<int, int> prefixSum;
prefixSum[0] = 1; // Empty subarray

int sum = 0, count = 0;

for (int i = 0; i < n; i++) {
    sum += arr[i];
    
    if (prefixSum.find(sum - K) != prefixSum.end()) {
        count += prefixSum[sum - K];
    }
    
    prefixSum[sum]++;
}
```

---

#### **Problem 8: Longest Consecutive Sequence**
Find length of longest consecutive elements

**Input:**
```
[100, 4, 200, 1, 3, 2]
```

**Output:**
```
4 (sequence: 1, 2, 3, 4)
```

**Solution:**
```cpp
unordered_set<int> s(arr.begin(), arr.end());
int maxLen = 0;

for (int num : s) {
    if (s.find(num - 1) == s.end()) { // Start of sequence
        int currNum = num;
        int currLen = 1;
        
        while (s.find(currNum + 1) != s.end()) {
            currNum++;
            currLen++;
        }
        
        maxLen = max(maxLen, currLen);
    }
}
```

---

---

## 📝 Quick Reference Cheat Sheet

### Array Hashing
```cpp
int hash[SIZE] = {0};
for (int x : arr) hash[x]++;
cout << hash[query];
```

### Character Hashing (Lowercase)
```cpp
int hash[26] = {0};
for (char c : s) hash[c - 'a']++;
cout << hash[query - 'a'];
```

### Character Hashing (All)
```cpp
int hash[256] = {0};
for (char c : s) hash[c]++;
cout << hash[query];
```

### Map
```cpp
map<int, int> mpp;
for (int x : arr) mpp[x]++;
cout << mpp[query];
```

### Unordered Map
```cpp
unordered_map<int, int> mpp;
for (int x : arr) mpp[x]++;
cout << mpp[query];
```

---

## 🎓 Key Formulas

### Character Mapping
```
Lowercase: index = char - 'a'  (a=0, b=1, ..., z=25)
Uppercase: index = char - 'A'  (A=0, B=1, ..., Z=25)
ASCII: index = char            (any character)
```

### Hash Function (Division Method)
```
index = key % table_size
```

### Time Complexity Rules
```
Brute Force: O(Q × N)
Array Hash: O(N + Q)
Map: O(N log N + Q log N)
Unordered Map: O(N + Q) average
```

---

## 🏆 Decision Making Flowchart

```
START
  ↓
Numbers ≤ 10⁶?
  ├─ YES → Use local array hash
  └─ NO → Numbers ≤ 10⁷?
      ├─ YES → Use global array hash
      └─ NO → Need sorted output?
          ├─ YES → Use map
          └─ NO → Use unordered_map
                  ↓
            Getting TLE?
                  ├─ YES → Switch to map
                  └─ NO → Continue
```

---

## 📚 Important Concepts Summary

### ✅ What is Hashing?
Pre-storing frequencies to enable O(1) queries

### ✅ Why Use Hashing?
Convert O(Q × N) brute force to O(N + Q)

### ✅ Array Hashing Limits
- Local: 10⁶ (int), 10⁷ (bool)
- Global: 10⁷ (int), 10⁸ (bool)

### ✅ Character Hashing
- Lowercase only: `char - 'a'` → 26 slots
- All characters: ASCII value → 256 slots

### ✅ Maps
- `map`: Sorted, O(log N)
- `unordered_map`: Unsorted, O(1) average

### ✅ Collisions
- Handled by chaining (linked lists)
- Worst case: O(N) when all keys collide

### ✅ Strategy
1. Try array if range allows
2. Use unordered_map for speed
3. Switch to map if TLE

---

## 🎬 Final Notes

### Remember:
- **Hashing = Pre-store + Fetch**
- **Array for small ranges** (≤ 10⁷)
- **Maps for large ranges** (> 10⁷)
- **Unordered map first**, map if TLE
- **Watch memory limits** (local vs global)
- **Character hashing needs care** (lowercase vs all)

### Common Mistakes to Avoid:
❌ Using array for numbers > 10⁷  
❌ Using `char - 'a'` for uppercase  
❌ Forgetting to initialize arrays to 0  
❌ Using map when unordered_map suffices  
❌ Declaring huge arrays inside main()  

### Homework (from Video):
1. Find element with **highest frequency**
2. Find element with **lowest frequency**
3. Practice character hashing problems
4. Implement custom hash functions

---

## 📖 Additional Resources

- **Video:** [Striver's Hashing](https://youtu.be/KEs5UyBJ39g)
- **Practice:** LeetCode, CodeForces, GeeksforGeeks
- **Topics to Learn Next:**
  - Sets and Multisets
  - Hash Functions (custom)
  - Perfect Hashing
  - Bloom Filters

---

## ✨ Last Words

> "Hashing is not just a technique, it's a mindset.  
> Think: Can I pre-compute this?  
> If yes, use hashing!" - Striver

**Good luck with your DSA journey! 🚀**

---

**Created on:** February 9, 2026  
**Last Updated:** February 9, 2026  
**Status:** Complete ✅

---
