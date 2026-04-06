#include <bits/stdc++.h>
using namespace std;

bool is_sorted (vector<int> arr, int n) {
    for (int i = 1; i <n; i++) {
        if (arr[i] >= arr[i - 1]);
        else return false;
    }
    return true;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << is_sorted(arr, n) << endl;
    }
    return 0;
}