# C++ STL Stack

This README explains the basics of the **C++ STL `stack`** container and its commonly
used operations.

---

## Stack Declaration

```cpp
stack<int> st;
Creates an empty stack of integers.
```
# Push Operations
```
st.push(1);
st.push(2);
st.emplace(5);
push() inserts an element into the stack

emplace() constructs the element directly

Elements are added on top of the stack
```
# Accessing Top Element
```
st.top();
Returns the top element of the stack

Does not remove the element
```
# Pop Operation
```
st.pop();
Removes the top element from the stack

Does not return the removed value
```
# Utility Functions
```
st.size();   // returns number of elements
st.empty();  // checks if stack is empty
Swap Operation
stack<int> st1, st2;
st1.swap(st2);
Swaps the contents of two stacks.
```
# Key Characteristics
```
Stack follows LIFO (Last In First Out)

Only the top element is accessible

No iterators are available

Random access is not allowed

Time Complexity
All standard stack operations run in O(1) constant time:

push()

emplace()

pop()

top()

size()

empty()