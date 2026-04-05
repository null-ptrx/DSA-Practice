#include <bits/stdc++.h>
using namespace std;

int largest(vector<long long>& arr, int n) {
    int largest = arr[0];

    for (int i = 0; i < n; i++) {
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

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << largest(arr, n) << endl;
    }

    return 0;
}