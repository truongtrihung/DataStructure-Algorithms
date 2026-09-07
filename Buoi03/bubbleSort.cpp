#include <iostream>
using namespace std;

#define MAX 100

void nhapmang (int arr[], int &n);

void xuatmang (int arr[], int n);

void bubbleSort(int arr[], int n);

void swap (int &xp, int &yp);

int main() {
    int n, arr[MAX];
    cout << "Nhap so luong phan tu trong mang: " ;
    cin >> n;

    cout << "Nhap mang: ";
    nhapmang(arr, n);

    cout << "Mang da nhap la: ";
    xuatmang(arr, n);

    bubbleSort(arr, n);
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

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // đổi thành arr[j] < arr[j+1] nếu descending
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void swap (int &xp, int &yp) {
    int temp;
    temp = xp;
    xp = yp;
    yp = temp;
}
