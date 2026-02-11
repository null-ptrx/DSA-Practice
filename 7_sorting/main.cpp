#include <bits/stdc++.h>

using namespace std;

void selection(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertion(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}
int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    // cout << "this is unsorted array" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] <<" ";
    // }
    // cout << endl;
    selection(arr, n);
    cout << "this is a sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
