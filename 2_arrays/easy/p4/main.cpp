#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
int brute(vector<long long>& arr, int n) {
    set <long long> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int index = 0;
    for (auto it : st) {
        arr[index] = it;
        index++;
    }
    return index;
}

// 🟢 Optimal Approach
int optimal(vector<long long>& arr, int n) {
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1; // size of array with no duplicates
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

        cout << brute(arr, n) << endl ;
        
        cout << optimal(arr, n) << endl;
    }

    return 0;
}