//bruteforce
int missing(vector<int>& nums, int n) {
    for (int i = 0; i < n+1; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (i == nums[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;  
}
//better 
int missing(vector<int>& nums, int n) {
    vector<int> hashArr(n+1);
    for (int i = 0; i < n; i++) {
        hashArr[nums[i]] = 1;
    } 
    for (int i = 0; i < n+1; i++) {
        if (hashArr[i] == 0) return i;
    }
    return -1;
}

//optimal using sum
int missing(vector<int>& nums, int n) {
    int sum = n*(n+1)/2;
    int rSum = 0;
    for (int i = 0; i < n; i++) {
        rSum += nums[i];
    } 
    return sum - rSum;
}

//optimal using xor
int missing(vector<int>& nums, int n) {
    int xor1 = 0; 
    int xor2 = 0;
    for (int i = 0; i < n; i++) {
        xor2 ^= nums[i];
        xor1 ^= i; 
    }
    xor1 ^= n;
    return xor1 ^ xor2; 
}