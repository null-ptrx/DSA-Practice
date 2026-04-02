#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &arr, int n) {
    for (int i = 0; i < n-1 ; i++) {
        bool swapped = false;
        for (int j = 0; j < n -1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) return;
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
    bubble(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
    

    return 0;
}