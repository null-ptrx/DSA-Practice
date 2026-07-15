#include <bits/stdc++.h>
using namespace std;
//bruteforce
void intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> intersectionArray;
    vector<int> visited(n2);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                if (visited[j] == 0)
                {
                    intersectionArray.push_back(nums1[i]);
                    visited[j] = 1;
                    break;
                }
            }
            if (nums2[j] > nums1[i] ) break;
        }
    }
}
//optimal
void intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> intersectionArray;
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2) {
        if (nums2[j] > nums1[i]) {
            i++;
        } else if (nums2[j] < nums1[i]) {
            j++;
        } else {
            intersectionArray.push_back(nums1[i]);
            i++;
            j++;
        }
    }
}

int main() {
    
    return 0;
}
