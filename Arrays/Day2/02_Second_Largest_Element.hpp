//brute force
int secondLargestBruteForce(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int largest = nums[n - 1];
    int secondLargest;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] != largest)
        {
            secondLargest = nums[i];
            break;
        }
    }
    return secondLargest;
}
//better
int secondLargest(vector<int>& nums) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] > largest ) {
            largest = nums[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] > secondLargest && nums[i] < largest) {
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}
//optimal
int secondLargest(vector<int>& nums) {
    int largest =nums[0];
        int secondLargest = INT_MIN;
        for (int i = 0; i <nums.size(); i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest =nums[i];
            } else if (nums[i] < largest &&nums[i] > secondLargest) {
                secondLargest =nums[i];
            }
        }
        if (secondLargest != INT_MIN && secondLargest < largest) {

        return secondLargest;
        }
        else return -1;
    
}

