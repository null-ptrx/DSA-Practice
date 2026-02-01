#include <bits/stdc++.h>
using namespace std;
//parameterized recursion 
//problem - sum of first n numbers 
// void f(int i, int sum) {
//     if (i < 1) {
//         cout << sum;
//         return;
//     }
//     f(i - 1, sum + i);

// }

//functional recursion
int f(int n) {
    if (n == 0) return 0;
    return n + f(n -1);

}

//problem - factorial of n numbers
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n -1);
}


int main()
{
    cout << fact(6);
    return 0;
}
