#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Declare a stack of integers
    stack<int> st;

    // Push elements into the stack
    st.push(1);    // Stack: {1}
    st.push(2);    // Stack: {1, 2}
    st.emplace(5); // Stack: {1, 2, 5}

    // Access the top element
    cout << st.top() << endl; // Output: 5

    // Remove the top element
    st.pop(); // Stack becomes {1, 2}

    // Access top element again
    cout << st.top() << endl; // Output: 2

    // Get size of the stack
    cout << st.size() << endl; // Output: 2

    // Check if stack is empty
    cout << st.empty() << endl; // Output: 0 (false)

    // Swap two stacks
    stack<int> st1, st2;
    st1.push(10);
    st2.push(20);

    st1.swap(st2);
    // st1 now has 20, st2 now has 10

    /*
        IMPORTANT NOTES:
        - Stack follows LIFO (Last In First Out)
        - Only top element is accessible
        - No iterators available
        - All operations run in O(1) constant time
    */

    return 0;
}
