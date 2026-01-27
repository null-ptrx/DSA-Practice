#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Declare a queue of integers
    queue<int> q;

    // Insert elements into the queue
    q.push(1);    // Queue: {1}
    q.push(2);    // Queue: {1, 2}
    q.emplace(3); // Queue: {1, 2, 3}

    // Modify the last element
    q.back() += 5; // Last element becomes 8

    // Access elements
    cout << q.back() << endl;  // Output: 8
    cout << q.front() << endl; // Output: 1

    // Remove the front element
    q.pop(); // Queue becomes {2, 8}

    // Access front after pop
    cout << q.front() << endl; // Output: 2

    /*
        NOTES:
        - Queue follows FIFO (First In First Out)
        - Insertion happens at the back
        - Deletion happens from the front
        - size(), swap(), empty() work same as stack
        - All operations are O(1) constant time
    */

    return 0;
}
