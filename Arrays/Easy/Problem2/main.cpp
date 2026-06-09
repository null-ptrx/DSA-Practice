#include <bits/stdc++.h>
using namespace std;

int secondLargestBruteForce(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    int largest = arr[n - 1];
    int secondLargest;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secondLargest = arr[i];
            break;
        }
    }
    return secondLargest;
}

int secondLargestBetter(vector<int> arr, int n) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest ) {
            largest = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int secondLargestOptimal(vector<int> arr, int n) {
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest ) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        } 
    }                                              
    return secondLargest;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "brute force approch";
        cout << "--Second largest element is " << secondLargestBruteForce(arr, n) << endl;
        cout << "Better approch";
        cout << "--Second largest element is " << secondLargestBetter(arr, n) << endl;
        cout << "Optimal approch";
        cout << "--Second largest element is " << secondLargestOptimal(arr, n) << endl;
    }

    return 0;
}