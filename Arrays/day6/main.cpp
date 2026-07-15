#include <bits/stdc++.h>
using namespace std;

//Brute Force
void rotateByKPlaces(vector<int>& nums) {
    int k = 3;
    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[i];
    }
    int i = 0;
    for (int j = k; j < n; j++) {
        nums[i] = nums[j];
        i++;
    }
    for (int i = 0; i < k; i++) {
        nums[n-k+i] = temp[i];
    }

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

}
//optimal
void rotateByKPlaces(vector<int>& nums, int n) {
    int k = 3;
    k %= n;
    
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.begin()+n);
    reverse(nums.begin(), nums.begin()+n);
}

int main() {
    
    return 0;
}
