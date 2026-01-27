# 📦 C++ STL Vector Basics

This repository contains my practice code for learning **C++ STL `vector`**.  
It covers vector initialization, iterators, insertion, deletion, and traversal methods.

---

## 🚀 Topics Covered

- Vector declaration and initialization
- `push_back()` vs `emplace_back()`
- Vector of pairs
- Iterators (`begin()`, `end()`)
- Accessing elements using iterators
- Looping through vectors
- `erase()` and `insert()` operations
- `pop_back()`, `clear()`, `empty()`
- `swap()` and `size()`

---

## 🧠 Example Code

```cpp
vector<int> v(5, 100);   // {100, 100, 100, 100, 100}

vector<int>::iterator it = v.begin();
it++;
cout << *it << " ";

🔍 Explanation
Creates a vector of size 5 with all values set to 100

Iterator starts at the first element

it++ moves iterator to the second element

*it accesses the value at that position

Output
100

🔁 Ways to Traverse a Vector
// Using iterator
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Range-based for loop
for(auto x : v) {
    cout << x << " ";
}

🧩 Key Notes
Iterators access one element at a time

erase() can remove single or multiple elements

insert() can add values or another vector

emplace_back() is faster than push_back()

empty() returns true (1) if vector is empty

