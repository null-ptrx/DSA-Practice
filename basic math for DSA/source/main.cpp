#include <bits/stdc++.h>
using namespace std;

// Function to count the number of digits in a number (iterative method)
int digitCnt(int num)
{
    int count = 0;
    while (num > 0)
    {
        num % 10; // This line does nothing - should be removed
        num /= 10;
        count++;
    }
    return count;
}

// Function to count the number of digits using logarithm
int digitCnt2(int num)
{
    if (num == 0)
        return 1; // If num is zero, there is only one digit
    return (log10(num) + 1);
}

// Function to reverse the digits of a number
int reverse(int num)
{
    int reverse = 0;
    while (num > 0)
    {
        reverse = reverse * 10 + (num % 10); // Build reversed number
        num = num / 10;
    }
    return reverse;
}

// Function to check if a number is a palindrome
string palindrome(int num)
{
    int c = num;
    if (c == reverse(num))
        return "palindrome";
    else
        return "not palindrome";
}

// Function to check if a number is an Armstrong number (assumes 3-digit)
string armstrong(int num)
{
    int c = num;
    int sum = 0;
    while (num > 0)
    {
        int ld = num % 10;   // Extract last digit
        sum += ld * ld * ld; // Cube the digit and add to sum
        num /= 10;
    }
    if (sum == c)
        return "armstrong";
    else
        return "not armstrong";
}

// Function to check if a number is an Armstrong number (works for any digit count)
string armstrong2(int num)
{
    int c = num;
    int dcnt = (int)(log10(num) + 1); // Count total digits
    int sum = 0;
    while (num > 0)
    {
        int ld = num % 10;    // Extract last digit
        sum += pow(ld, dcnt); // Raise digit to power of digit count
        num /= 10;
    }
    if (sum == c)
        return "armstrong";
    else
        return "not armstrong";
}

// Function to print all divisors of a number (brute force method)
void printdivisors(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
}

// Function to print all divisors using square root optimization
void printdivisors2(int num)
{
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
            // Print the corresponding divisor if it's different
            if (i != num / i)
            {
                cout << num / i << " ";
            }
        }
    }
}

// Function to check if a number is prime
bool primeNum(int num)
{
    if (num <= 1)
        return false;

    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    return (count == 2); // Prime numbers have exactly 2 divisors
}

// Function to find GCD using brute force method (worst case)
int gcd(int num1, int num2)
{
    int gcd = 1;
    for (int i = 1; i <= min(num1, num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i; // Update GCD when common divisor found
        }
    }
    return gcd;
}

// Function to find GCD by iterating from max to min (better for some cases)
void gcd2(int num1, int num2)
{
    for (int i = min(num1, num2); i >= 1; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            cout << i;
            break; // Exit once first (largest) common divisor is found
        }
    }
}

// Function to find GCD using Euclidean algorithm (most efficient)
int gcd3(int num1, int num2)
{
    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
            num1 = num1 % num2; // Replace larger number with remainder
        else
            num2 = num2 % num1;
    }

    // Return the non-zero value
    if (num1 == 0)
        return num2;
    return num1;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Find and display GCD
    gcd2(num1, num2);

    return 0;
}