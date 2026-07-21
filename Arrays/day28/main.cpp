#include <bits/stdc++.h>
using namespace std;
// type I - to print the specific element of given row
int ncr(int row, int col)
{
    int res = 1;
    for (int i = 0; i < col; i++)
    {
        res = res * (row - i);
        res = res / (i + 1);
    }
    return res;
}

// type II - to print the nth row
void nthRow(int n)
{
    for (int col = 1; col <= n; col++)
    {
        cout << ncr(n - 1, col - 1) << " ";
    }
}

// optimal version
void nthRow(int n)
{
    int ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans *= n - i;
        ans /= i;
        cout << ans << " ";
    }
}

// type III - to print the full pascal's triangle
void pascalTriangle(int n)
{
    for (int row = 1; row < n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << (ncr(row - 1, col - 1)) << " ";
        }
        cout << endl;
    }
}

// opyimal version
void pascalTriangle(int n)
{
    for (int row = 1; row < n; row++)
    {
        nthRow(row);
        cout << endl;
    }
}

int main()
{
    // type I - to print a specific element
    int row = 10;
    int col = 3;
    cout << ncr(row - 1, col - 1) << endl;

    // type II
    int n = 5;
    nthRow(n);

    // type III
    int n = 5;
    pascalTriangle(n);
}