#include <bits/stdc++.h>
using namespace std;

int main()
{

    // ----------- BASIC VECTOR INSERTION -----------
    vector<int> myVector;

    myVector.push_back(1);    // inserts 1
    myVector.emplace_back(2); // inserts 2

    // myVector = {1, 2}

    // ----------- VECTOR OF PAIRS -----------
    vector<pair<int, int>> vector2;

    vector2.push_back({1, 2});  // inserts pair (1,2)
    vector2.emplace_back(3, 4); // inserts pair (3,4)

    // ----------- VECTOR INITIALIZATION -----------
    vector<int> v(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v0(5);     // {0, 0, 0, 0, 0}

    vector<int> v1(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v2(v1);    // copy of v1

    // ----------- ITERATORS -----------
    vector<int>::iterator it = v.begin();
    it++;
    cout << *it << " "; // Output: 100

    it = v.begin() + 2;
    cout << *it << " "; // Output: 100

    // ----------- SPECIAL ITERATORS -----------
    cout << v.front() << " "; // First element -> 100
    cout << v.back() << " ";  // Last element -> 100

    // ----------- LOOPING THROUGH VECTOR -----------

    // Method 1: Iterator
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }

    // Method 2: Auto keyword
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }

    // Method 3: Range-based for loop
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    // ----------- ERASE OPERATIONS -----------
    v.erase(v.begin() + 1);                // removes 2nd element
    v.erase(v.begin() + 1, v.begin() + 3); // removes a range

    // ----------- INSERT OPERATIONS -----------
    vector<int> v3(2, 100); // {100, 100}

    v3.insert(v3.begin(), 300);       // {300, 100, 100}
    v3.insert(v3.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copyVec(2, 50); // {50, 50}
    v3.insert(v3.begin(), copyVec.begin(), copyVec.end());

    // ----------- SIZE -----------
    cout << v3.size() << endl; // Output: size of vector

    // ----------- POP BACK -----------
    v3.pop_back(); // removes last element

    // ----------- SWAP -----------
    vector<int> a = {10, 20};
    vector<int> b = {30, 40};

    a.swap(b);
    // a = {30, 40}, b = {10, 20}

    // ----------- CLEAR & EMPTY -----------
    a.clear();         // removes all elements
    cout << a.empty(); // Output: 1 (true)

    return 0;
}
