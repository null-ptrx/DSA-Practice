#include <bits/stdc++.h>
using namespace std;

void selection(vector<int> &arr, int n) {
    for (int i = 0; i <= n-2; i ++) {
        int minIndex = i;
        for (int j = i; j <= n-1; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap the min with fornt 
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


int main() {
    int t;
cin >> t;

while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selection(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
    

    return 0;
}