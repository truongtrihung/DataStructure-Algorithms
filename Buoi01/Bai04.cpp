#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 100

// Hàm nhập mảng
void nhapmang (int a[], int &n);

//Hàm in mảng
void inmang (int a[], int n);

// a) Tìm giá trị tuyệt đối lớn nhất có trong mảng
int max_abs (int a[], int n);

// b) Tính tổng các số nằm từ -10 đến 10
int sum (int a[], int n);

// c) Tìm số đầu tiên chia hết cho cả 2 và 3
int divisible (int a[], int n);

int main () {
    int n, a[MAX];
    cout << "Nhap so phan tu n: ";
    cin >> n;

    nhapmang(a, n);

    cout << endl;

    cout << "Mang vua nhap la: ";
    inmang (a, n);

    cout << endl;

    cout << "Gia tri tuyet doi lon nhat co trong mang la: " << max_abs (a, n);

    cout << endl;

    cout << "Tong cac so nam tu -10 den 10 la: " << sum (a, n);

    cout << endl;

    cout << "So chia het cho ca 2 va 3 la: " << divisible (a, n);

    cout << endl;

    return 0;
}


// Hàm nhập mảng
void nhapmang (int a[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

//Hàm in mảng
void inmang (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// a) Tìm giá trị tuyệt đối lớn nhất có trong mảng
int max_abs (int a[], int n) {
    int max = abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (max < abs(a[i])) max = abs(a[i]);
    }
    return max;
}

// b) Tính tổng các số nằm từ -10 đến 10
int sum (int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= -10 && a[i] <= 10) {
            sum += a[i];
        }
    }
    return sum;
}

// c) Tìm số đầu tiên chia hết cho cả 2 và 3
int divisible (int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] % 3 == 0) return a[i];
    }
    return -12;
}