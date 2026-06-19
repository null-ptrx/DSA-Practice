// bruteforce
void moveZero(vector<int> &nums)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }
    int nonZero = temp.size();
    for (int i = nonZero; i < n; i++)
    {
        nums[i] = 0;
    }
}
// optimal
void moveZero(vector<int> &nums)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[j], nums[i]);
            j++;
        }
    }
}

// mine approch at first
void moveZero(vector<int> &nums)
{
    vector<int> temp;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == 0 && nums[i + 1] != 0)
        {
            swap(nums[i], nums[i + 1]);
        }
        else if (nums[i] == 0 && nums[i + 1] == 0)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (nums[j] != 0)
                {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
    }
}