//Brute Force
void rotatedByone(vector<int>& nums) {
    int temp;
    temp = nums[0];
    for (int i = 1; i < n; i++) {
        nums[i-1] = nums[i];
    }
    nums[n-1] = temp;
}
