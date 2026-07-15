#include <bits/stdc++.h>
using namespace std;
//bruteforce
int test(vector<int>& nums, int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n / 2) return nums[i];
    }
    return -1;
}
//better
int majorityElement(vector<int>& nums, int n) {
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    for (auto it : mp) {
        if (it.second > n / 2) {
            return it.first;
        }
    }
    return -1; 
}
//optimal
int majorityElement(vector<int>& nums, int n) {
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            count++;
            ele = nums[i];
        } else if (nums[i] == ele) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ele) count++;
    }
    if (count > n/2) return ele;

    return -1;
}
int main() {
    
    return 0;
}
