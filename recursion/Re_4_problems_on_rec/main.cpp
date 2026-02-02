#include <bits/stdc++.h>

using namespace std;

/**
 * Reverses an array using two pointers (left and right).
 * l: starting index, r: ending index, n: total size for printing
 */
void f(int l, int r, int arr[], int n)
{
    // Base Case: If pointers meet or cross, the array is reversed
    if (l >= r)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return;
    }
    // Swap elements at the current boundaries
    swap(arr[l], arr[r]);
    // Move boundaries inward
    f(l + 1, r - 1, arr, n);
}

/**
 * Reverses an array using a single index (i).
 * i: current index, n: total size
 */
void f(int i, int arr[], int n)
{
    // Base Case: If we've reached the middle, stop
    // Using n/2 ensures we don't re-swap elements back to original
    if (i >= n / 2)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        return;
    }
    // Swap current element with its mirror counterpart at the end
    swap(arr[i], arr[n - i - 1]);
    // Move to the next index
    f(i + 1, arr, n);
}

/**
 * Checks if a string is a palindrome recursively.
 * i: current index, str: the string, n: string length
 */
bool palindrome(int i, string str, int n)
{
    // Base Case: If we reached the middle without returning false, it's a palindrome
    if (i >= n / 2)
        return true;

    // If characters at mirror positions don't match, it's not a palindrome
    if (str[i] != str[n - i - 1])
        return false;

    // Recurse to the next character pair
    return palindrome(i + 1, str, n);
}

int main()
{
    // Example: Palindrome Check
    string s = "dhami";
    if (palindrome(0, s, s.length()))
    {
        cout << s << " is a palindrome" << endl;
    }
    else
    {
        cout << s << " is not a palindrome" << endl;
    }

    // Example: Array Reversal
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Reversed Array: ";
    f(0, arr, n); // Calling the single-index version

    return 0;
}