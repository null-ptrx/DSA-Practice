#include <bits/stdc++.h>
using namespace std;

void printLeader(vector<int> &nums) {
  vector<int> leaders;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    bool leader = true;
    for (int j = i + 1; j < n; j++) {
      if (nums[i] < nums[j]) {
        leader = false;
        break;
      } 
    }
    if (leader == true) {
      leaders.push_back(nums[i]);
    }
  }
  for (auto x : leaders) {
    cout << x << " ";
  }
}

void printLeader(vector<int> &nums)
{
  vector<int> leaders;
  int n = nums.size();
  int maxi = 0; 
  for (int i = n -1 ; i >= 0; i--) {
    if (nums[i] > maxi) {
      leaders.push_back(nums[i]);
    }
    maxi = max(maxi, nums[i]);
  }
 
}
int main() {
  vector<int> nums = {1, 2, 5, 3, 1, 2};
  printLeader(nums);
  return 0;
}
