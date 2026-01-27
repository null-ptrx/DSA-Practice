# C++ STL Deque

This README explains the basics of the **C++ STL `deque` (Double Ended Queue)** container
and its commonly used operations.

---

## Deque Declaration

```cpp
deque<int> dq1;
Creates an empty deque of integers.
```
# Deque Initialization
```
deque<string> cars = {"Volvo", "BMW", "Ford"};
Creates a deque and initializes it with string values.

{"Volvo", "BMW", "Ford"}
Insertion Operations
dq1.push_back(10);
dq1.emplace_back(20);

dq1.push_front(5);
dq1.emplace_front(1);
push_back() / emplace_back() → insert at the end

push_front() / emplace_front() → insert at the front
```
# Key Feature of Deque

A deque allows fast insertion and deletion at both front and back.

This makes it different from vector, where front insertion is slow.

# Traversing a Deque
```
for(auto it = dq1.begin(); it != dq1.end(); it++) {
    cout << *it << " ";
}
Or using range-based loop:

for(auto x : dq1) {
    cout << x << " ";
}
```
# Common Functions (Same as Vector & List)
The following functions work the same way as in vector and list:

begin()

end()

rbegin()

rend()

insert()

erase()

clear()

size()

swap()

empty()

# Key Points
Deque supports random access like vector (dq[i])

Fast insertion/removal at both ends

Internally implemented as multiple blocks

Useful when operations are needed at both ends