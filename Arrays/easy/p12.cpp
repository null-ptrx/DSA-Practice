//bruteforce
int findMaxConsecutiveOnes(vector<int>& nums, int n) {
    vector<int> count(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count[j]++;
        } else {
            j++;
        }
    }
    sort(count.begin(), count.end());
    return count[n-1];

}
//optimal 
int findMaxConsecutiveOnes(vector<int>& nums, int n) {
    int count = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;
            maximum = max(maximum, count);
        } else {
            count = 0;
        }
    }
    return maximum;

}