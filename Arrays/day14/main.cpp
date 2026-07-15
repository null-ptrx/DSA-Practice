#include <bits/stdc++.h>
using namespace std;

// brute1
int longestSubarray(vector<int> &nums, int n)
{
    int target = 15;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum == target)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
// brute 2
int longestSubarray(vector<int> &nums, int n)
{
    int target = 15;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == target)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
//better1
int longestSubarray(vector<int> &nums, int n)
{
    int k = 15;
    map<int , int> mp;
    int maxLen = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (mp.find(rem) != mp.end()) {
            int len = i- mp[rem];
            maxLen = max(maxLen ,len);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return maxLen;
}
//better 2
int longestSubarray(vector<int> &nums, int n)
{
    int k = 15;
    int maxLen = 0;
    int sum = 0;
    map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = sum - k;
        if (mp.find(rem) != mp.end()) {
            int len = i - mp[rem];
            maxLen = max(maxLen , len);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return maxLen;
}
// opyimal only if array has positive only 
int longestSubarray(vector<int> &nums, int n) {
    int k = 6;
    int maxLen = 0;
    int sum = nums[0];
    int right = 0;
    int left = 0;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen , right - left + 1);
        }
        right++;
        if (right < n) {
            sum += nums[right];
        }
    }
    return maxLen;
}


// approch at first 
void longestSubarray(vector<int> &nums, int n)
{
    int k = 15;
    vector<int> subArray;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int end = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                end = j;
                break;
            }
        }
        if (end != 0 && end-i+1 > maxLen) {
            maxLen = end-i+1;
            subArray.clear(); 
            for (int k = i; k <= end; k++) {
                subArray.push_back(nums[k]);
            }
        }
    }
    for (auto it : subArray) {
        cout << it << " ";
    }
    cout << endl;

}
int main() {
    
    return 0;
}
