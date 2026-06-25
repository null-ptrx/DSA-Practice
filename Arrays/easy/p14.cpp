// brute1
int test(vector<int> &nums, int n)
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
int test(vector<int> &nums, int n)
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
//better
int test(vector<int> &nums, int n)
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

// approch at first 
void test(vector<int> &nums, int n)
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

