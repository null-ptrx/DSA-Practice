#include <iostream>
using namespace std;



// 1. Solid Square
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// 2. Right-Angled Triangle
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// 3. Right-Angled Number Triangle
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

// 4. Right-Angled Number Triangle (Same digit per row)
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

// 5. Inverted Right-Angled Triangle
void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// 6. Inverted Number Triangle
void pattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

// 7. Star Pyramid
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Spaces
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        // Stars: (2*i + 1)
        for (int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }
}

// 8. Inverted Star Pyramid
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Spaces
        for (int j = 0; j < i; j++)
            cout << " ";
        // Stars
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            cout << "*";
        cout << endl;
    }
}

// 9. Diamond Star Pattern
void pattern9(int n)
{
    pattern7(n);
    pattern8(n);
}

// 10. Half Diamond Star Pattern
void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// 11. Binary Triangle (0s and 1s)
void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = (i % 2 == 0) ? 1 : 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

// 12. Number Bridge
void pattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        for (int j = 1; j <= space; j++)
            cout << " ";
        for (int j = i; j >= 1; j--)
            cout << j;
        cout << endl;
        space -= 2;
    }
}

// 13. Increasing Number Triangle (Floyd's Triangle)
void pattern13(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// 14. Increasing Letter Triangle
void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 15. Inverted Letter Triangle
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch < 'A' + (n - i); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 16. Alpha-Ramp
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 17. Alpha-Hill
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        cout << endl;
    }
}

// 18. Alpha-Triangle (Starting from nth character)
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// 19. Symmetric Void Pattern
void pattern19(int n)
{
    // Upper Half
    int space = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "*";
        for (int j = 0; j < space; j++)
            cout << " ";
        for (int j = 1; j <= n - i; j++)
            cout << "*";
        space += 2;
        cout << endl;
    }
    // Lower Half
    space = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        for (int j = 0; j < space; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        space -= 2;
        cout << endl;
    }
}

// 20. Symmetric Butterfly Pattern
void pattern20(int n)
{
    int space = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        // Left Stars
        for (int j = 1; j <= stars; j++)
            cout << "*";
        // Middle Spaces
        for (int j = 1; j <= space; j++)
            cout << " ";
        // Right Stars
        for (int j = 1; j <= stars; j++)
            cout << "*";

        cout << endl;
        if (i < n)
            space -= 2;
        else
            space += 2;
    }
}

// 21. Hollow Square
void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

// 22. Concentric Square Numbers
void pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            // The value is the distance from the nearest edge
            cout << (n - min(min(top, down), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    if (!(cin >> n))
        return 0;

    cout << "--- Pattern 22 ---" << endl;
    pattern1(n);  // Change pattern here
    pattern2(n);  // Change pattern here
    pattern3(n);  // Change pattern here
    pattern4(n);  // Change pattern here
    pattern5(n);  // Change pattern here
    pattern6(n);  // Change pattern here
    pattern7(n);  // Change pattern here
    pattern8(n);  // Change pattern here
    pattern9(n);  // Change pattern here
    pattern10(n); // Change pattern here
    pattern11(n); // Change pattern here
    pattern12(n); // Change pattern here
    pattern13(n); // Change pattern here
    pattern14(n); // Change pattern here
    pattern15(n); // Change pattern here
    pattern16(n); // Change pattern here
    pattern17(n); // Change pattern here
    pattern18(n); // Change pattern here
    pattern19(n); // Change pattern here
    pattern20(n); // Change pattern here
    pattern21(n); // Change pattern here
    pattern22(n); // Change pattern here

    return 0;
}

