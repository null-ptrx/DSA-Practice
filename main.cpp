#include <bits/stdc++.h>
using namespace std;

//Brute Force
int largestElementBf(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    return arr[n-1];
}
//Optimal Approach
int largestElementOp(vector<int>& arr, int n) {
    int largest = INT_MIN;

    for(int i = 0; i < 0; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
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
        largestElementBf(arr, n);
    }

    return 0;
}