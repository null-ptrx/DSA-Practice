#include <bits/stdc++.h>
using namespace std;
// brute force - pick the element and compare with all
void majortityElement(vector<int> & nums)
{
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if (ans.size() == 0 || ans[0] != nums[i]){
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                    count++;
            }
            if (count > (n / 3))
                ans.push_back(nums[i]);
        }
        if (ans.size() == 2) break;

    }
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

// better - hashing

void majortityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
        if (mpp[nums[i]] == ((n/3) + 1)) {
            ans.push_back(nums[i]);
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

// optimal - mores voting algo

void majortityElement(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && nums[i] != ele2)
        {
            cnt1++;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != ele1)
        {
            cnt2++;
            ele2 = nums[i];
        }
        else if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int cntCheck1 = 0;
    int cntCheck2 = 0;
    for (auto it : nums)
    {
        if (it == ele1)
            cntCheck1++;
        else if (it == ele2)
            cntCheck2++;
    }
    if (cntCheck1 > (n / 3))
        ans.push_back(ele1);
    if (cntCheck2 > (n / 3))
        ans.push_back(ele2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 3, 2, 2};
    majortityElement(nums);
}