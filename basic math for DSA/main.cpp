#include <bits/stdC++.h>
using namespace std;

int digitCnt (int num) {
    int count = 0;
    while (num > 0)
    {
        num % 10;
        num /= 10;
        count++;
    }
    return count;
}

int reverse(int num) {
    int reverse = 0;
    while (num > 0)
    {
        reverse = reverse * 10 + (num % 10);
        num = num / 10;
    }
    return reverse;
}

string palindrome(int num) {
    int c = num;
    if (c == reverse(num))
        return "palindrome";
    else
        return "not palindrome";

}

string armstrong(int num) {
    int c = num;
    int sum = 0;
    while (num > 0)
    {   
        int ld = num % 10;
        sum += ld * ld * ld;
        num /= 10;
    }
    if (sum == c)
        return "armstrong";
    else
        return "not armstrong";
}
int main () {
    int num;
    cout <<"enter a number";
    cin >> num;

    cout << armstrong(num);

    return 0;
} 