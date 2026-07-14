#include <bits/stdc++.h>
using namespace std;
// Brute Force
//  void markRow(int i, vector<vector<int>> & arr)
//  {
//      int m = arr[0].size();
//      for (int j = 0; j < m; j++)
//      {
//          if (arr[i][j] != 0)
//          {
//              arr[i][j] = -1;
//          }
//      }
//  }
//  void markCol(int j, vector<vector<int>> &arr)
//  {
//      int n = arr.size();
//      for (int i = 0; i < n; i++)
//      {
//         if (arr[i][j] != 0) {
//             arr[i][j] = -1;
//         }
//      }
//  }
//  void test(vector<vector<int>>& arr) {
//      int rows = arr.size();
//      int columns = arr[0].size();

//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             if (arr[i][j] == 0) {
//                 markRow(i, arr);
//                 markCol(j, arr);
//             }
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             if(arr[i][j] == -1){
//                 arr[i][j] = 0;
//             }
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//            cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
void test(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> rows(n);
    vector<int> cols(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (rows[i] || cols[j]) {
         arr[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        
          cout << arr[i][j] << " ";
      }
      cout << endl;
    }
}
int main() {
  vector<vector<int>> arr = {{1, 1, 0}, {1, 1, 1}, {1, 1, 0}};
  test(arr);
  return 0;
}