//bruteforce
int singleNumber(vector<int>& nums, int n){
    int count = 0;
    for ( int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count == 1) return nums[i]; 
        count = 0;
    }
    return -1;
}
//better
int singleNumber(vector<int>& nums, int n){
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++; 
    }
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return -1;
}
//optimal
int singleNumber(vector<int>& nums, int n){
    int number = 0;
    for ( int i = 0; i < n; i++) {
        number ^= nums[i];
    }
    return number;
}