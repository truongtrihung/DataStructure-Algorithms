#include <iostream>
using namespace std;

#define MAX 100

void nhapMang (int arr[], int &l, int &h);

void inMang (int arr[], int l, int h);

void quickSort(int arr[], int l, int h);

int partition(int arr[], int low, int high);

void myswap(int &a, int &b);

int main() {
    int arr[MAX];
    int l, h;
    cout << "Nhap l: ";
    cin >> l;
    cout << "Nhap h: ";
    cin >> h;

    cout << "Nhap mang: ";
    nhapMang(arr, l, h);

    cout << "Mang vua nhap la: ";
    inMang(arr, l, h);

    quickSort(arr, l, h);
    cout << "Mang sau khi sap xep la: ";
    inMang(arr, l, h);

    cout << endl;
    return 0;
}

void nhapMang (int arr[], int &l, int &h) {
    for (int i = l; i <= h; i++) {
        cin >> arr[i];
    }
}

void inMang (int arr[], int l, int h) {
    for (int i = l; i <= h; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            myswap(arr[i], arr[j]);
            i++;
        }
    }
    myswap(arr[i], arr[high]);
    return (i);
}

void myswap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
