# C++ STL (Standard Template Library) - Complete Notes

## Table of Contents
1. [Introduction & Setup](#introduction--setup)
2. [Pairs](#pairs)
3. [Containers](#containers)
4. [Algorithms](#algorithms)
5. [Quick Reference](#quick-reference)

---

## Introduction & Setup

**STL** is a compilation of algorithms, containers, iterators, and functions designed to minimize code length and maximize efficiency.

### Standard Code Skeleton
```cpp
#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;      // Avoids writing std:: before commands

int main() {
    // Your code here
    return 0;
}
```

**Note:** While `#include <bits/stdc++.h>` is convenient for competitive programming, it's not standard and should be avoided in production code. Use specific headers instead.

---

## Pairs

Pairs store two elements together, even of different data types.

### Basic Declaration & Access
```cpp
pair<int, int> p = {1, 3};
cout << p.first;   // Output: 1
cout << p.second;  // Output: 3
```

### Nested Pairs (For 3+ values)
```cpp
pair<int, pair<int, int>> p = {1, {3, 4}};
cout << p.first;          // Output: 1
cout << p.second.first;   // Output: 3
cout << p.second.second;  // Output: 4
```

### Array of Pairs
```cpp
pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
cout << arr[1].second;  // Output: 4
```

---

## Containers

### 1. Vector (Dynamic Array)

Dynamically resizable array that can grow as needed.

#### Declaration
```cpp
vector<int> v;                    // Empty vector
vector<int> v(5, 100);           // {100, 100, 100, 100, 100}
vector<int> v = {1, 2, 3, 4};    // Initialize with values
vector<int> v2(v);               // Copy vector v to v2
```

#### Adding Elements
```cpp
v.push_back(5);      // Adds 5 at the end
v.emplace_back(6);   // Faster than push_back (constructs in-place)
```

#### Accessing Elements
```cpp
v[0];           // First element
v.at(0);        // First element (with bounds checking)
v.front();      // First element
v.back();       // Last element
```

#### Iterators
```cpp
vector<int>::iterator it = v.begin();  // Points to first element
v.end();        // Points to memory location AFTER last element
v.rbegin();     // Reverse begin (last element)
v.rend();       // Reverse end (before first element)
```

#### Iteration Methods
```cpp
// Method 1: Using index
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// Method 2: Using iterators
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Method 3: Range-based for loop (Recommended)
for (auto it : v) {
    cout << it << " ";
}
```

#### Deletion
```cpp
v.erase(v.begin() + 1);           // Deletes element at index 1
v.erase(v.begin() + 1, v.begin() + 4);  // Deletes range [1, 4)
v.pop_back();                      // Removes last element
v.clear();                         // Removes all elements
```

#### Insertion
```cpp
v.insert(v.begin(), 100);              // Insert 100 at beginning
v.insert(v.begin() + 2, 50);          // Insert 50 at index 2
v.insert(v.begin(), 2, 10);           // Insert 10 twice at beginning
```

#### Other Functions
```cpp
v.size();       // Returns number of elements
v.empty();      // Returns true if vector is empty
v.swap(v2);     // Swaps contents with another vector
```

**Time Complexity:**
- Access: O(1)
- Insert/Delete at end: O(1) amortized
- Insert/Delete at beginning/middle: O(N)

---

### 2. List (Doubly Linked List)

Similar to vector but allows efficient operations at both front and back.

```cpp
list<int> ls;
ls.push_back(2);      // {2}
ls.emplace_back(4);   // {2, 4}
ls.push_front(5);     // {5, 2, 4}
ls.emplace_front(1);  // {1, 5, 2, 4}
ls.pop_front();       // {5, 2, 4}
ls.pop_back();        // {5, 2}
```

**Time Complexity:** O(1) for front/back operations

---

### 3. Deque (Double-Ended Queue)

Combines features of vector and list with efficient operations at both ends.

```cpp
deque<int> dq;
dq.push_back(1);      // {1}
dq.push_front(2);     // {2, 1}
dq.pop_back();        // {2}
dq.pop_front();       // {}
dq.back();
dq.front();
```

**Time Complexity:** O(1) for front/back operations

---

### 4. Stack (LIFO - Last In First Out)

```cpp
stack<int> st;
st.push(1);         // {1}
st.push(2);         // {2, 1}
st.push(3);         // {3, 2, 1}
st.top();           // Returns 3
st.pop();           // Removes 3, stack: {2, 1}
st.size();          // Returns 2
st.empty();         // Returns false
```

**Time Complexity:** All operations are O(1)

**Note:** Stack has no iterators

---

### 5. Queue (FIFO - First In First Out)

```cpp
queue<int> q;
q.push(1);          // {1}
q.push(2);          // {1, 2}
q.push(3);          // {1, 2, 3}
q.front();          // Returns 1
q.back();           // Returns 3
q.pop();            // Removes 1, queue: {2, 3}
q.size();
q.empty();
```

**Time Complexity:** All operations are O(1)

---

### 6. Priority Queue (Heap)

#### Max Heap (Default)
```cpp
priority_queue<int> pq;
pq.push(5);         // {5}
pq.push(2);         // {5, 2}
pq.push(8);         // {8, 5, 2}
pq.top();           // Returns 8 (largest element)
pq.pop();           // Removes 8
```

#### Min Heap
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(5);         // {5}
pq.push(2);         // {2, 5}
pq.push(8);         // {2, 5, 8}
pq.top();           // Returns 2 (smallest element)
```

**Time Complexity:**
- push(): O(log N)
- pop(): O(log N)
- top(): O(1)

---

### 7. Set (Unique & Sorted)

Stores **unique** elements in **sorted** order.

```cpp
set<int> s;
s.insert(1);        // {1}
s.insert(2);        // {1, 2}
s.insert(2);        // {1, 2} (duplicate ignored)
s.insert(4);        // {1, 2, 4}

auto it = s.find(2);    // Returns iterator to 2
s.count(3);             // Returns 0 (not present)
s.count(2);             // Returns 1 (present)

s.erase(2);             // {1, 4}
s.erase(it);            // Erase using iterator
s.erase(s.begin(), s.find(4));  // Erase range
```

#### Iteration
```cpp
for (auto it : s) {
    cout << it << " ";
}
```

**Time Complexity:** All operations are O(log N)

#### Lower Bound & Upper Bound
```cpp
set<int> s = {1, 2, 4, 5, 6};
auto it = s.lower_bound(2);  // Returns iterator to 2
auto it = s.lower_bound(3);  // Returns iterator to 4 (next greater element)
auto it = s.upper_bound(2);  // Returns iterator to 4 (element after 2)
```

---

### 8. Multiset

Similar to set but **allows duplicates**, maintains sorted order.

```cpp
multiset<int> ms;
ms.insert(1);       // {1}
ms.insert(1);       // {1, 1}
ms.insert(1);       // {1, 1, 1}

ms.erase(1);        // Erases all occurrences of 1: {}

// To erase only one occurrence:
ms.erase(ms.find(1));  // Erases only one 1
```

**Time Complexity:** O(log N)

---

### 9. Unordered Set

Stores **unique** elements in **random order** (not sorted).

```cpp
unordered_set<int> us;
us.insert(1);
us.insert(2);
us.insert(3);
```

**Time Complexity:**
- Average: O(1)
- Worst case: O(N)

**Use when:** You need uniqueness but don't care about order.

---

### 10. Map (Key-Value Pairs)

Stores **unique keys** in **sorted** order with associated values.

```cpp
map<int, int> mpp;              // key -> value
map<int, string> mpp;           // Roll number -> Name
map<string, int> mpp;           // Name -> Roll number
map<int, pair<int, int>> mpp;   // Complex mappings

// Insertion
mpp[1] = 2;                     // {1 -> 2}
mpp.insert({3, 1});             // {1 -> 2, 3 -> 1}
mpp.emplace(2, 4);              // {1 -> 2, 2 -> 4, 3 -> 1}

// Access
cout << mpp[1];                 // Output: 2
cout << mpp[5];                 // Output: 0 (default value if key doesn't exist)

// Find
auto it = mpp.find(3);          // Returns iterator to key 3
if (it != mpp.end()) {
    cout << it->second;         // Access value
}
```

#### Iteration
```cpp
for (auto it : mpp) {
    cout << it.first << " " << it.second << endl;
}
```

**Time Complexity:** All operations are O(log N)

---

### 11. Multimap

Allows **duplicate keys** in sorted order.

```cpp
multimap<int, int> mmp;
mmp.insert({1, 2});
mmp.insert({1, 3});     // Same key allowed
```

**Time Complexity:** O(log N)

---

### 12. Unordered Map

Stores **unique keys** in **random order**.

```cpp
unordered_map<int, int> ump;
ump[1] = 2;
ump[3] = 4;
```

**Time Complexity:**
- Average: O(1)
- Worst case: O(N)

**Use when:** You need key-value pairs but don't care about order.

---

## Algorithms

### 1. Sorting

#### Basic Sorting (Ascending)
```cpp
int a[] = {5, 2, 8, 1, 9};
int n = 5;

// Array
sort(a, a + n);                         // {1, 2, 5, 8, 9}

// Vector
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end());               // {1, 2, 5, 8, 9}

// Partial sort (first 3 elements)
sort(a, a + 3);                         // {2, 5, 8, 1, 9}
```

#### Descending Order
```cpp
sort(a, a + n, greater<int>());         // {9, 8, 5, 2, 1}
```

#### Custom Sorting (Comparator)
```cpp
// Sort pairs by second element
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // If second elements are equal, sort by first
    return p1.first > p2.first;
}

pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
sort(a, a + n, comp);
// Result: {{2, 1}, {4, 1}, {1, 2}}
```

**Time Complexity:** O(N log N) - Uses Intro Sort (hybrid of Quick Sort, Heap Sort, Insertion Sort)

---

### 2. Built-in Functions

#### Count Set Bits
```cpp
int num = 7;  // Binary: 111
int count = __builtin_popcount(num);    // Returns 3

long long num = 165786578687;
int count = __builtin_popcountll(num);  // For long long
```

#### Permutations
```cpp
string s = "123";
sort(s.begin(), s.end());  // Must be sorted first!

do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));

// Output: 123, 132, 213, 231, 312, 321
```

**Note:** `next_permutation` returns `false` when it reaches the last permutation.

#### Max/Min Element
```cpp
int a[] = {5, 2, 8, 1, 9};
int n = 5;

int maxElement = *max_element(a, a + n);     // Returns 9
int minElement = *min_element(a, a + n);     // Returns 1

// For vectors
vector<int> v = {5, 2, 8, 1, 9};
int maxElement = *max_element(v.begin(), v.end());
```

#### Reverse
```cpp
int a[] = {1, 2, 3, 4, 5};
reverse(a, a + 5);  // {5, 4, 3, 2, 1}

string s = "hello";
reverse(s.begin(), s.end());  // "olleh"
```

#### Accumulate (Sum)
```cpp
vector<int> v = {1, 2, 3, 4, 5};
int sum = accumulate(v.begin(), v.end(), 0);  // Returns 15
// Third parameter is initial value
```

#### Count
```cpp
vector<int> v = {1, 2, 2, 3, 2, 4};
int cnt = count(v.begin(), v.end(), 2);  // Returns 3
```

#### Find
```cpp
vector<int> v = {1, 2, 3, 4, 5};
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) {
    cout << "Found at index: " << it - v.begin();
}
```

#### Binary Search (requires sorted array)
```cpp
int a[] = {1, 2, 3, 4, 5};
bool found = binary_search(a, a + 5, 3);  // Returns true

// Lower bound: first element >= x
auto it = lower_bound(a, a + 5, 3);  // Points to 3

// Upper bound: first element > x
auto it = upper_bound(a, a + 5, 3);  // Points to 4
```

---

## Quick Reference

### When to Use Which Container?

| Need | Container | Time Complexity |
|------|-----------|----------------|
| Dynamic array | `vector` | Access: O(1), Insert/Delete end: O(1) |
| Front & back operations | `deque` or `list` | O(1) |
| LIFO operations | `stack` | O(1) |
| FIFO operations | `queue` | O(1) |
| Always get max/min | `priority_queue` | Push/Pop: O(log N), Top: O(1) |
| Unique + Sorted | `set` | O(log N) |
| Unique + Fast lookup | `unordered_set` | O(1) average |
| Duplicates + Sorted | `multiset` | O(log N) |
| Key-Value + Sorted | `map` | O(log N) |
| Key-Value + Fast lookup | `unordered_map` | O(1) average |

### Common Patterns

#### Finding duplicates
```cpp
unordered_set<int> s;
for (int x : arr) {
    if (s.count(x)) {
        cout << "Duplicate: " << x;
    }
    s.insert(x);
}
```

#### Frequency count
```cpp
unordered_map<int, int> freq;
for (int x : arr) {
    freq[x]++;
}
```

#### K most frequent elements
```cpp
priority_queue<pair<int, int>> pq;  // Max heap by frequency
for (auto it : freq) {
    pq.push({it.second, it.first});
}
```

---

## Important Notes

1. **Iterators:** Use `auto` to avoid long iterator declarations
2. **Emplace vs Insert/Push:** `emplace` is generally faster as it constructs in-place
3. **Unordered containers:** Faster on average but worst case is O(N)
4. **Map access:** Using `map[key]` creates the key if it doesn't exist
5. **Set/Map:** Use when you need sorted order, otherwise use unordered versions
6. **Vector vs List:** Vector is better for random access, List is better for frequent insertions/deletions
7. **Always initialize:** Uninitialized containers can cause undefined behavior

---

## Practice Tips

✅ Always think about time complexity before choosing a container  
✅ Use `unordered_map/set` for O(1) lookups when order doesn't matter  
✅ Remember that `set` and `map` are sorted automatically  
✅ Use `lower_bound` and `upper_bound` for binary search in sorted containers  
✅ Know when to use `emplace` over `push/insert`  
✅ Practice custom comparators for sorting

---

**Video Reference:** [C++ STL Tutorial](https://youtu.be/RRVYpIET_RU?si=-Q4WleuzRlCi1hc3)

**Created for DSA Revision** 📚

---

## Additional Resources

- Practice problems on platforms like LeetCode, Codeforces, CodeChef
- Read official C++ documentation for deeper understanding
- Understand the underlying data structures (linked lists, heaps, hash tables, red-black trees)

Happy Coding! 🚀
