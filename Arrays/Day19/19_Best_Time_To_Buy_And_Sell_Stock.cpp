// brute
int buySellStocks(vector<int> &nums, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int cost = nums[i] - nums[j];
            profit = max(profit, cost);
        }
    }
    return profit;
}
// optimal

int buySellStocks(vector<int> &nums, int n)
{
    int mini = nums[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int cost = nums[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, nums[i]);
    }
    return profit;
}