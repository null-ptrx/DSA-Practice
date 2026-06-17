#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums, int n) {
    int i = 0;
    for (int j = 1; j<n; j++) {
        if (nums[j] != nums[i]) {
            nums[i+1] = nums[j];
            i++;
        }
    } 
     return i+1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        removeDuplicates(nums, n);
    }
}