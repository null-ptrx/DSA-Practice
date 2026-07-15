#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int n) {
    int target = 5;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) return i;
    }
    return -1; 
}

int main() {
    
    return 0;
}
