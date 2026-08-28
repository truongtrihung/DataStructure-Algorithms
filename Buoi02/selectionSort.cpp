#include <iostream>
using namespace std;

void selectionSort(int arr[], int n);

void swap(int &xp, int &yp);

int main() {
    int arr[] = {9, 7, 8, 4, 5, 6, 3, 1, 2, 10};
    int n;
    
    cin >> n; 
    
    selectionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}
