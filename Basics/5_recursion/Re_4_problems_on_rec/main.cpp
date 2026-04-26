#include <bits/stdc++.h>

using namespace std;

void f(int l, int r, int arr[],int n) {
    if (l >= r) {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return;
    }
    swap(arr[l], arr[r]);
    f(l + 1, r - 1, arr, n);
}
void f(int i, int arr[], int n)
{
    if (i > n / 2) {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}

bool palindrome(int i, string str, int n) {
    if (i >= n / 2) return true;
    if (str[i] != str[n - i - 1]) return false;
    return palindrome(i + 1, str, n);
}

int main()
{   
    palindrome(0, "dhami", 5);
    return 0;
}
