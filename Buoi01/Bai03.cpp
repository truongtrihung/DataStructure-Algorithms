#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 100

// a) Hàm nhập mảng
void nhapmang (int a[], int &n);

// b) Hàm in mảng
void inmang (int a[], int n);

// c) Hàm tìm số dương nhỏ nhất trong mảng
int min_pos (int a[], int n);

// d) Hàm tính tổng của các số dương trong mảng
int tong_pos (int a[], int n);

// e) Tìm số chẵn đầu tiên trong mảng
int first_even (int a[], int n);

int main() {
    int n, a[MAX];
    cout << "Nhap so phan tu n: ";
    cin >> n;

    nhapmang (a, n);

    cout << "Mang vua nhap: ";
    inmang (a, n);

    int min = min_pos (a, n);
    if (min == -1) cout << "Khong co so duong nho nhat trong mang";
    else cout << "So duong nho nhat trong mang la: " << min;

    cout << endl;

    cout << "Tong cac so duong co trong mang la: " << tong_pos (a, n);

    cout << endl;

    cout << "So chan dau tien trong mang la: " << first_even (a, n);

    cout << endl;

    return 0;
}

// a) Hàm nhập mảng
void nhapmang (int a[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

// b) Hàm in mảng
void inmang (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int timSoDuong (int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) return a[i];
    }
    return -1;
}

// c) Hàm tìm số dương nhỏ nhất trong mảng
int min_pos (int a[], int n) {
    int min = timSoDuong (a, n); // Tìm số dương đầu tiên có trong mảng
    if (min == -1) return -1;   // Không có số dương trong mảng
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] < min) {
            min = a[i];
        }
    }
    return min;
}



// d) Hàm tính tổng của các số dương trong mảng
int tong_pos (int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) tong += a[i];
    }
    return tong;
}

// e) Tìm số chẵn đầu tiên trong mảng
int first_even (int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) return a[i];
    }
    return 0;
}