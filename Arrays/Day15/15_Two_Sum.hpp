//bruteforce
vector<int> twoSum(vector<int>& nums, int n) {
    int target = 14;
    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i , j};
            }

        }
    }
    return {};
}
//better
vector<int> twoSum(vector<int>& nums, int n) {
    int target = 14;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
       int rem = target - nums[i];
       if (mp.find(rem) != mp.end()) {
        return {mp[rem],i};
       }
       if (mp.find(rem) == mp.end()) {
        mp[nums[i]] = i;
       }
    }
    return {};
}