#include <bits/stdc++.h>
using namespace std;

void bruteForce(int arr[], int n, int queries[], int q) {

    for (int i = 0; i < q; i++) {
        int x = queries[i];
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] == x) {
                count++;
            }
        }
        cout << "number " << x << " comes " << count << " times" << endl;
    }

}


void hashing(int arr[], int n, int queries[], int q) {
    int hashArr[13] = {0};
    for (int i = 0; i < n; i++) {
        hashArr[arr[i]]++;
    }

    for (int j = 0; j < q; j++) {
        int x = queries[j];
        cout << "number " << x << " comes " << hashArr[x] << " times" << endl;
    }
}

// void strHashing(string str, int n, char queries[], int q) {
//     int hashArr[26] = {0};
//     for (int i = 0; i < n; i++) {
//         hashArr[str[i]- 'a']++;
//     }

//     for (int j = 0; j< q; j++) {
//         char x = queries[j];
//         cout << "char " << x << " comes " << hashArr[x - 'a'] << " times" << endl;
//     }

// }

void strHashing(string str, int n, char queries[], int q) {
    int hashArr[256] = {0};
    for (int i = 0; i < n; i++) {
        hashArr[str[i]]++;
    }

    for (int j = 0; j< q; j++) {
        char x = queries[j];
        cout << "char " << x << " comes " << hashArr[x] << " times" << endl;
    }

}

// void mapHashing(int arr[], int n, int queries[], int q) {
//     map<int, int> mpp;

//     for (int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }

//     for (int j = 0; j < q; j++) {
//         int x = queries[j];
//         cout << "number " << x << " comes " << mpp[x] << " times" << endl;


//     }
// }

void mapHashing(int arr[], int n, int queries[], int q) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (int j = 0; j < q; j++) {
        int x = queries[j];
        cout << "number " << x << " comes " << mpp[x] << " times" << endl;


    }
}
int main() {
    int arr[] = {1, 3, 2, 1, 4, 3, 2, 5, 6};
    int n = 9;
    int queries[] = {1, 3, 6, 2};
    int q = 4;
    // string str ="abcdefgxdhhchCDWCJWC7664545&*^&%^";
    // char queries[] = {'a', 'b', 'c'};
    mapHashing(arr, n, queries, q);
    
    // strHashing(str, 7, queries, 3);

    return 0;
}