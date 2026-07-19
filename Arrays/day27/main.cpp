#include <bits/stdc++.h>
using namespace std;

//bruteforcee
int printInSpiralManner(vector<int> & nums, int k) {
    int subarray = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j]; 
            if (sum == k) {
                subarray += 1;
            }
        }

    }

    return subarray;
}
//optimal my version
int printInSpiralManner(vector<int> & nums, int k) {
    int count = 0;
    int n = nums.size();
    int sum = 0;
    map<int, int> mp = {{0, 1}};
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = sum - k;
        if (mp.find(rem) != mp.end()) {
            count++;
            mp[nums[i]]++;
            
        }
        if (mp.find(rem) == mp.end()) {
            mp[sum]++;
        }
    }
    return count;
}
// strivers 
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();
    int preSum = 0;
    map<int, int> mp = {{0, 1}};
    for (int i = 0; i < n; i++) {
        preSum += nums[i];
        int remove = preSum - k;
        count += mp[remove];
        mp[preSum] += 1;
    
    }
    return count;
}
int main() {
  vector<int> nums = {3, 1, 2, 4};
  int k = 6;
  cout <<printInSpiralManner(nums, k);
  return 0;
}