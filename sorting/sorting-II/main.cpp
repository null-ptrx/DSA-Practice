#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp = {};
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + (high - low)) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// void bubbleSort (int arr[], int n) {
//     if (n <= 0) return;
//     bubbleSort(arr, n-1);
//     if (arr[n -1] > arr[n]) {
//         swap(arr[n-1], arr[n]);
//     }
// }
// void bubbleSort (int arr[], int s, int end) {
//     if (end <= s) return;
//     bubbleSort(arr, s, end-1);
//     if (arr[s] > arr[end]) {
//         swap(arr[s], arr[end]);
//     }
// }
void bubbleSort (int arr[],int pass, int n, int s, int e) {
    if (s == e) return;
    bubbleSort(arr,pass, n, s, e -1);
    if (arr[e-1] > arr[e]) {
        swap(arr[e-1], arr[e]);
    }
}
int main()
{
    int arr[4] = {5, 4, 3, 2};
    bubbleSort(arr,1, 3, 0, 3);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}