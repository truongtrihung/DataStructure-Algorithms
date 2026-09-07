#include <iostream>
using namespace std;

#define MAX 100

void nhapMang(int arr[], int &n);

void inMang(int arr[], int n);

void selectionSort(int arr[], int n);

void swap(int &xp, int &yp);

int main() {
    int arr[MAX];
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    cout << "Nhap mang: ";
    nhapMang(arr, n);

    cout << "Mang da nhap la: ";
    inMang(arr, n);

    selectionSort(arr, n);
    cout << "Mang sau khi sap xep la: ";
    inMang(arr, n);

    return 0;
}

void nhapMang(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
