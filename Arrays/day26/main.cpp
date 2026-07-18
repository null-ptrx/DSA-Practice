#include <bits/stdc++.h>
using namespace std;

//optimal
void printInSpiralManner(vector<vector<int>> & matrix) {
    int n = matrix.size(); 
    int m = matrix[0].size();

    int top = 0; 
    int left = 0; 
    int right = m-1;
    int bottom = n-1;
    while (left <= right && top <= bottom) {
    for(int i = left; i <= right; i++) {
        cout << matrix[top][i] << "  ";
    }
    top++;
    for (int i = top; i <= bottom; i++) {
        cout << matrix[i][right] << "  ";
    }
    right--;
    if (top <= bottom) {
        for (int i = right; i >= left; i--) {
            cout << matrix[bottom][i] << "  ";
        }
        bottom--; 
    }
    if (left <= right) {
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << "  ";
        }
        left++;
    }

}
}
int main() {
    vector<vector<int>> matrix = {
        {1,   2,  3,  4,  5,  6},
        {20, 21, 22, 23, 24,  7},
        {19, 32, 33, 34, 25,  8},
        {18, 31, 36, 35, 26,  9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}
    };
  printInSpiralManner(matrix);
  return 0;
}