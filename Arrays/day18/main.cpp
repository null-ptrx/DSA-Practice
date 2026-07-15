#include <bits/stdc++.h>
using namespace std;
// bruteforce
int maxSubarraySum(vector<int> &nums, int n)
{
    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// optimal
int maxSubarraySum(vector<int> &nums, int n)
{
    int sum = 0;
    int maxSum = 0;
    int start;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += nums[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}
int main() {
    
    return 0;
}
