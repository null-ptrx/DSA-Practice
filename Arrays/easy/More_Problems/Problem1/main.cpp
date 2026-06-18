#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
int brute(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int smallest = arr[0];
    int second_smallest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != smallest)
        {
            second_smallest = arr[i];
            break;
        }
    }
    return second_smallest;
}

// 🟡 Better Approach
int better(vector<int> &arr, int n)
{
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    int second_smallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < second_smallest && arr[i] > smallest)
        {
            second_smallest = arr[i];
        }
    }

    if (second_smallest == INT_MAX)
        return -1;
    return second_smallest;
}

// 🟢 Optimal Approach
int optimal(vector<int> &arr, int n)
{
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    if (second_smallest == INT_MAX)
        return -1;
    return second_smallest;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

        // brute(arr, n);
        // better(arr, n);
        cout << optimal(arr, n) << endl;
    }

    return 0;
}