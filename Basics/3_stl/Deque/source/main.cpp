#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Declare an empty deque of integers
    deque<int> dq1;

    // Insert elements at the back
    dq1.push_back(10);    // dq1 = {10}
    dq1.emplace_back(20); // dq1 = {10, 20}

    // Insert elements at the front
    dq1.push_front(5);    // dq1 = {5, 10, 20}
    dq1.emplace_front(1); // dq1 = {1, 5, 10, 20}

    // Traverse and print deque
    for (auto x : dq1)
    {
        cout << x << " ";
    }
    cout << endl;

    // Declare and initialize a deque with values
    deque<string> cars = {"Volvo", "BMW", "Ford"};

    // Print string deque
    for (auto it = cars.begin(); it != cars.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
        NOTE:
        - deque supports insertion and deletion at BOTH front and back
        - Most functions are same as vector and list:
          begin(), end(), rbegin(), rend(), insert(), erase(),
          clear(), size(), swap(), empty()
    */

    return 0;
}
