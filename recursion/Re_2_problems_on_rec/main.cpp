#include <bits/stdc++.h>
using namespace std;

//print the name n times
void printName(int i,string name, int n) {
    if (i > n) return;
    cout << name << endl;
    printName(i + 1,name, n);
}
// print a number 1 to n times
void printNum(int i,int n) {
    if (i > n) return;
    cout << i << endl;
    printNum(i+1,n);

}
//print a number n to 1 times
void printNumOp(int i,int n) {
    if (i < 1 ) return;
    cout << i << endl;
    printNumOp(i-1, n);
}

//print a number 1 to n time using backtracking

void numback(int i, int n) {
    if (i < 1) return;
    numback(i-1, n);
    cout << i;
}

//print a number n to 1 using backtracking

void numback2(int i, int n) {
    if (i > n) return;
    numback2(i+1, n);
    cout << i;
}

int main() {
    int n = 5;
    numback2(1, n);

    return 0;
}
