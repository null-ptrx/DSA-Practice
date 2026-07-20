#include <bits/stdc++.h>
using namespace std;
//type I - to print the specific element of given row
int ncr(int row, int col) {
    int res = 1;
    for (int i = 0 ; i < col; i++) {
        res = res * (row - i);
        res = res / (i + 1);
    }
    return res;
}


int main() {
    //type I
  int row = 10;
  int col = 3;
  cout << ncr(row-1, col-1) << endl;
}