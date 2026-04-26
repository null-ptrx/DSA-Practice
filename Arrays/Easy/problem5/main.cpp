#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force
void brute(vector<int>& arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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

        brute(arr, n);
        for (int i = 0; i < n;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
      
    }

    return 0;
}