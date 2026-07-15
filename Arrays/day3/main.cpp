#include <bits/stdc++.h>
using namespace std;

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

int main() {
    
    return 0;
}
