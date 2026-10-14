#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = -1;
    int last = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target && first == -1) {
            first = i;
            last = i;
        } else if (nums[i] == target && first != -1) {
            last = i;
        }

    }
    return {first, last};
}

int main()
{
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    
    return 0;
}