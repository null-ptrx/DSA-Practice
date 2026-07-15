#include <bits/stdc++.h>
using namespace std;
// void test(vector<int>& nums, int n) {
    //     vector<int> negative;
    //     vector<int> positive;
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] > 0) {
    //             positive.push_back(nums[i]);
    //         } else {
    //             negative.push_back(nums[i]);
    //         }
    //     }
    //     int posi = 0;
    //     int negi = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (i % 2 == 0) {
    //             nums[i] = positive[posi];
    //             posi++;
    //         } else {
    //             nums[i] = negative[negi];
    //             negi++;
    //         }
    //     }
    // for (int i = 0; i < n/2; i++) {
    //     nums[i * 2] = positive[i];
    //     nums[i * 2 + 1] = negative[i];
    // }
    
    //     for (auto it : nums) {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    // void test(vector<int>& nums, int n) {
    //     vector<int> ans(n);
    //     int posi = 0;
    //     int negi = 1;
    //     for (int i = 0; i < n; i++) {
    //          if (nums[i] > 0) {
    //             ans[posi] = nums[i];
    //             posi += 2;
    //         }
    //          else {
    //             ans[negi] = nums[i];
    //             negi += 2;
    //         }
    //     }
    //     for (auto it : ans) {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    
    void test(vector<int> &nums, int n)
    {
        vector<int> negative;
        vector<int> positive;
        for (auto it : nums)
        {
            if (it > 0)
            {
                positive.push_back(it);
            }
            else
            {
                negative.push_back(it);
            }
        }
        if (positive.size() > negative.size())
        {
            for (int i = 0; i < negative.size(); i++)
            {
                nums[i * 2] = positive[i];
                nums[i * 2 + 1] = negative[i];
            }
            int index = negative.size();
            for (int i = index * 2; i < n; i++)
            {
                nums[i] = positive[index];
                index++;
            }
        }
        else
        {
            for (int i = 0; i < positive.size(); i++)
            {
                nums[i * 2] = negative[i];
                nums[i * 2 + 1] = positive[i];
            }
            int index = positive.size();
            for (int i = index * 2; i < n; i++)
            {
                nums[i] = negative[index];
                index++;
            }
        }
        for (auto it : nums)
        {
            cout << it << " ";
        }
        cout << endl;
    }
int main() {
    
    return 0;
}
