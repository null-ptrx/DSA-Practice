#include <bits/stdc++.h>
using namespace std;

bool sortedOrNot(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        };
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
        cout << "simple only one approch exist";
        cout << "--array is sorted or not" << sortedOrNot(arr, n) << endl;
    }
}