#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
void brute(vector<int>& arr, int n) {
}

// 🟡 Better Approach
void better(vector<int>& arr, int n) {
}

// 🟢 Optimal Approach
void otimal(vector<int>& arr, int n) {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // brute(arr, n);
        // better(arr, n);
        otimal(arr, n);
    }

    return 0;
}