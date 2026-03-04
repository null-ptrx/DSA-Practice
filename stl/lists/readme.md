# C++ STL List

This README explains the basics of the **C++ STL `list`** container and its commonly
used operations.

---

## List Declaration

```cpp
list<int> ls;
Creates an empty doubly linked list of integers.
```
# Insertion Operations
```ls.push_back(2);
ls.emplace_back(4);
Inserts elements at the end of the list

emplace_back() constructs the element directly (more efficient)

Front Insertion (Key Difference from Vector)
ls.push_front(5);
ls.emplace_front(1);
Inserts elements at the front of the list

❗ This operation is not available in vector

In vector, insertion at front requires insert()
```
# Important Note
In list, front insertion is fast (O(1)).
In vector, front insertion is slow (O(n))
This is because list is implemented as a doubly linked list.

# Common Functions (Same as Vector)
The following functions work the same way as in vector:

begin()

end()

rbegin()

rend()

insert()

erase()

clear()

size()

swap()

# Traversing a List
```
for(auto it = ls.begin(); it != ls.end(); it++) {
    cout << *it << " ";
}
Or using range-based loop:

for(auto x : ls) {
    cout << x << " ";
}

```
# key Points
list allows fast insertion and deletion at both ends

No random access (ls[0] ❌)

Iterators move one element at a time

Best used when frequent insertions/deletions are required