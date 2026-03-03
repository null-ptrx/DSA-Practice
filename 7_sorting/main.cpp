#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // swap the elements
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {   
        int count = 0;
        for (int j = 0; j < n - i - 1; j++)
        {   
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0) return;
    }
}
void insertion(int arr[], int n)
{
    
}
int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    bubble(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
