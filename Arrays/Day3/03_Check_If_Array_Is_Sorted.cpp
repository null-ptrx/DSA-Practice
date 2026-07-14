//optimal
bool sortedOrNot(vector<int>& nums)
{
    for (int i = 1; i < n; i++)
    {
        if (nums[i] >= nums[i - 1])
        {
        }
        else
        {
            return false;
        };
    }
    return true;
}
