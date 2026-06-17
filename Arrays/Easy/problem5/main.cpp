#include <bits/stdc++.h>
using namespace std;
//Brute Force
void rotatedByone(vector<int>& nums, int n) {
    int temp;
    temp = nums[0];
    for (int i = 1; i < n; i++) {
        nums[i-1] = nums[i];
    }
    nums[n-1] = temp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        rotatedByone(nums, n);
    }
    return 0;
}