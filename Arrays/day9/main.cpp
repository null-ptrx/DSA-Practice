#include <bits/stdc++.h>
using namespace std;

//bruteforce
void unionSorted(vector<int>& nums1, vector<int>& nums2) {
    vector<int> unionArray;
    set<int> unionSt;
    for (int i = 0; i < n1; i++) {
        unionSt.insert(nums1[i]);
    }
    for (int i = 0; i < n2; i++) {
        unionSt.insert(nums2[i]);
    }
    int i = 0;
    for (auto it : unionSt) {
        unionArray.push_back(it);
    }

    for (auto it : unionArray) {
        cout << it << " ";
    }
    cout << endl;
}
//optimal
void unionSorted(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> unionArray;
    int i = 0;
    int j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();

    while (j < n2 && i < n1)
    {
        if (nums1[i] <= nums2[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != nums1[i])
            {
                unionArray.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != nums2[j])
            {
                unionArray.push_back(nums2[j]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (unionArray.size() == 0 || unionArray.back() != nums2[j])
        {
            unionArray.push_back(nums2[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (unionArray.size() == 0 || unionArray.back() != nums1[i])
        {
            unionArray.push_back(nums1[i]);
        }
        i++;
    }
}

int main() {
    
    return 0;
}
