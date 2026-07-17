#include <bits/stdc++.h>
using namespace std;
// Brute Force
// bool linearSearch(vector<int> &nums, int num)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == num)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int test(vector<int> &nums) {
//   int n = nums.size();
//   int maxCount = 0;
//   for (int i = 0; i < n; i++) {
//     int count = 1;
//     int x = nums[i];
//     while (linearSearch(nums, x + 1)) {
//       x++;
//       count++;
//       maxCount = max(maxCount, count);
//     }
//   }
//   return maxCount;
// }



// int test(vector<int> &nums)
// {
//         int n = nums.size();
//         int maxCount = 0;
//         int last = INT_MIN;
//         int count = 0;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == last + 1) {
//                 count++;
//                 last = nums[i];
                
//             } else if (last != nums[i]){
//                 last = nums[i];
//                 count = 1;
                
//             }
//             maxCount = max(maxCount, count);
//         }
//         return maxCount;
// }

int test(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0 ) return -1;
    int len = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    } 
    
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int count = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                count++;
                x++;
            }
            len = max(len, count);
        }
    }
    return len;
}
int main() {
    vector<int> nums = { 1, 2, 2, 3 };
    cout << test(nums);
    return 0;
}