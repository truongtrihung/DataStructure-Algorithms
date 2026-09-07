#include <iostream>
using namespace std;

#define MAX 100

void nhapmang (int arr[], int &n);

void xuatmang (int arr[], int n);

void insertionSort(int arr[], int n);

int main() {
    int n, arr[MAX];
    cout << "Nhap so luong phan tu trong mang: " ;
    cin >> n;

    cout << "Nhap mang: ";
    nhapmang(arr, n);

    cout << "Mang sau khi nhap la: ";
    xuatmang(arr, n);

    insertionSort(arr, n);
    cout << "Mang sau khi sap xep la: ";
    xuatmang(arr, n);
}

void nhapmang (int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void xuatmang (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {    // giảm dần thì đổi arr[j] < key
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}