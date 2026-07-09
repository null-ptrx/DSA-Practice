#include <bits/stdc++.h>
using namespace std;
//Brute Force
int test(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 1;
        int x = nums[i];
        int j = 0;
        while (true) {
            if (nums[j] == x + 1) {
                x++;
                j++;
                count++;
            } else break;
        }
    } 
    return longest;
}

int main() {
    vector<int> nums  {100, 4, 200, 1, 3, 2};
    cout << test(nums);
    return 0;
}