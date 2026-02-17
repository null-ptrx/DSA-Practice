#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }

        swap(arr[i], arr[mini]);
    }
}
void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            } 
        }
        if (didswap == 0) break;
    }


}
void insertion(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

}
int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    bubble(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
