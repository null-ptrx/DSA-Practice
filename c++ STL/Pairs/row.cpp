#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p = {1, 3};
    cout  << p.first << p.second; //print 1 and 3

    pair<int, pair<int, int>> q = {1, {3, 4}};
    cout << q.first <<" " << q.second.second << " " << q.second.first; // prints 1 4 3

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second; 

    return 0;
}