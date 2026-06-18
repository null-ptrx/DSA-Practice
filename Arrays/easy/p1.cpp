//Brute Force
int largestElementBf(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[n-1];
}
//Optimal Approach
int largestElementOp(vector<int>& nums) {
    int largest = INT_MIN;
    for(int i = 0; i < 0; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest;
}

