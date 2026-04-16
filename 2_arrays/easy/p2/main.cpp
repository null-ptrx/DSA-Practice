#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
int brute(vector<long long>& arr, int n) {
    sort(arr.begin(), arr.end());
    int largest = arr[n -1];
    int second_largest;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) {
            second_largest = arr[i];
            break;
        }
    }
    return second_largest;
}

// 🟡 Better Approach
int better(vector<long long>& arr, int n) {
    //pass 1 find largest first
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    // pass 2 second largest 
    int second_largest = -1;

     for (int i = 0; i < n; i++) {
        if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

// 🟢 Optimal Approach
int optimal(vector<long long>& arr, int n) {
    int largest = arr[0];
    int second_largest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
    }
    return second_largest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // cout << brute(arr, n) << endl;
        // cout << better(arr, n) << endl;
        cout << optimal(arr, n) << endl;
    }

    return 0;
}