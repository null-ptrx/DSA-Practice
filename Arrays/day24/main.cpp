#include <bits/stdc++.h>
using namespace std;
// Brute Force linear treversal 
// void markRow(int i, vector<vector<int>>& matrix) { // mark rows 
//   int m = matrix[0].size();
//   for (int j = 0; j < m; j++) {
//     if (matrix[i][j] != 0) {
//       matrix[i][j] = -1; 
//     }
//   }
// }

// void markCol(int j, vector<vector<int>>& matrix) { // mark cols
//   int n = matrix.size();
//   for (int i = 0; i < n; i++) {
//     if (matrix[i][j] != 0) {
//       matrix[i][j] = -1; 
//     }
//   }
// }

// vector<vector<int>> setMatrixZero(vector<vector<int>> &matrix) {
//   int n = matrix.size(); // no of rows
//   int m = matrix[0].size(); // no of cols

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (matrix[i][j] == 0) {
//         markRow(i, matrix);
//         markCol(j, matrix);
//       }
//     }
//   }
//   for (int i = 0; i < n; i++) {
//       for (int j = 0; j < m; j++) {
//             if(matrix[i][j] == -1) {
//               matrix[i][j] = 0;
//             }
//       }
//   }
//   return matrix;
// }


//better approch 
// void setMatrixZero(vector<vector<int>> &matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<int> rows(n);
//     vector<int> cols(m);

//     for (int i = 0; i < n; i++)  {
//         for (int j = 0; j < m; j++) {
//             if(matrix[i][j] == 0) {
//                 rows[i] = 1;
//                 cols[j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < m; j++) {
//         if (rows[i] || cols[j]) {
//          matrix[i][j] = 0;
//         }
//       }
//     }
// }

void setMatrixZero(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int col1 = 1;
  for (int i = 0; i < n; i++)  {
      for (int j = 0; j < m; j++) {
          if(matrix[i][j] == 0) {
            matrix[i][0] = 0;
            if (j == 0) {
              col1 = 0;
            } else {
              matrix[0][j] = 0;
            }
          }
      }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
       if (matrix[i][j] != 0) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
       }
    }

  }
  if (matrix[0][0] == 0) {
    for (int i = 0; i < m; i++) {
      matrix[0][i] = 0;
    }
  }
  if (col1 == 0) {
    for (int i = 0; i < n; i++) {
      matrix[i][0] = 0;
    }
  }
}
int main() {
  vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
  setMatrixZero(matrix);
  int n = matrix.size(); 
  int m = matrix[0].size();
  for (int i = 0; i < n; i++)  {
    for (int j = 0; j < m; j++) {
       cout << matrix[i][j] << "  ";
    }
    cout << endl;
}

  return 0;
}