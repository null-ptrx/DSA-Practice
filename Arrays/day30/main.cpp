#include <bits/stdc++.h>
using namespace std;
//bruteforce
// vector<vector<int>> threeSum(vector<int>& nums) {
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             for (int k = j+1; k < n; k++) {
//                 if (nums[i] + nums[j] + nums[k] == 0) {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }
//better

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     int n = nums.size();
    
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashMap;
//         for (int j = i + 1; j < n; j++)
//         {
//             int third = -nums[i] - nums[j];
//             if (hashMap.find(third) != hashMap.end()) {
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashMap.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }
//optimal
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i =0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
             if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    
    return ans;
}
//optimal - two pointer my version
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = i + 1;
    int k = n - 1;
    vector<vector<int>> ans;
    while (i < n)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            i++;
            j = i + 1;
            k = n - 1;
        }

        else if (j >= k)
        {
            i++;
            j = i + 1;
            k = n - 1;
        }
        else if (nums[i] + nums[j] + nums[k] == 0)
        {
            vector<int> temp = {nums[i], nums[j], nums[k]};
            ans.push_back(temp);
            j++;
            k--;
            while (j < k && nums[j] == nums[j - 1])
                j++;
            while (j < k && nums[k] == nums[k + 1])
                k--;
        }
        else if (nums[i] + nums[j] + nums[k] < 0)
        {
            j++;
        }
        else if (nums[i] + nums[j] + nums[k] > 0)
        {
            k--;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = { 2, -2, 0, 3, -3, 5 };
    vector<vector<int>> ans = threeSum(nums);
    cout << "{ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ",";
        }
        cout << " }";  
    }
    cout << " }";
    cout << endl;
    return 0;
}