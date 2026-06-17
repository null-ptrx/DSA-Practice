#include <bits/stdc++.h>
using namespace std;
//Brute Force
// void rotateByKPlaces(vector<int>& arr, int n) {
//     int k = 3;
//     vector<int> temp(k);
//     for (int i = 0; i < k; i++) {
//         temp[i] = arr[i];
//     }
//     int i = 0;
//     for (int j = k; j < n; j++) {
//         arr[i] = arr[j];
//         i++;
//     }
//     for (int i = 0; i < k; i++) {
//         arr[n-k+i] = temp[i];
//     }

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

// }
void rotateByKPlaces(vector<int>& arr, int n) {
    int k = 3;
    k %= n;
    
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.begin()+n);
    reverse(arr.begin(), arr.begin()+n);
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
        rotateByKPlaces(arr, n);
        cout << endl;
    }
    return 0;
}