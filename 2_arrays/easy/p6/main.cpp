#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
void brute(vector<int>& arr, int n) {
    int d = 3;
    d = d % n;

    vector<int> temp;
    for (int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }

    for (int i = d; i < n; i++) {
        arr[i-d] = arr[i];
    }
    // int j = 0;
    for (int i = n -d; i < n; i++) {
        // arr[i] = temp[j];
        // j++;
        //or this way

        arr[i] = temp[i - (n - d)];

    }
}

// 🟢 Optimal Approach
void optimal(vector<int>& arr, int n) {
    int d = 4;
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
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

        optimal(arr, n);
        // better(arr, n);
        // optimal(arr, n);
        for (int i = 0; i < n;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}