#include <iostream>
using namespace std;

struct student {
    string name;
    string id;
    float gpa;
};

void NhapDSSV(student arr[], int &n);

void XuatDSSV(student arr[], int n);

student FindHighest(student arr[], int n);

void Sapxep(student arr[], int n);

int main() {
    student arr[10];
    int n;
    NhapDSSV(arr, n);
    XuatDSSV(arr, n);

    student highest = FindHighest(arr, n);
    cout << "===Sinh vien co GPA cao nhat===" << endl;
    cout << "Ho va ten: " << highest.name << endl;
    cout << "ID: " << highest.id << endl;
    cout << "GPA: " << highest.gpa << endl;

    Sapxep(arr, n);
    cout << "Thu tu sinh vien (giam dan) la: " << endl;
    XuatDSSV(arr, n);

    return 0;
}

void NhapDSSV(student arr[], int &n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();

        cout << "Nhap ten: ";
        getline(cin, arr[i].name);

        cout << "Nhap id: ";
        getline(cin, arr[i].id);

        cout << "Nhap gpa: ";
        cin >> arr[i].gpa;
    }
}

void XuatDSSV(student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin cua sinh vien thu: " << i + 1 << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Ho va ten: " << arr[i].name << endl;
        cout << "GPA: " << arr[i].gpa << endl;
    }
}

student FindHighest(student arr[], int n) {
    student highest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].gpa > highest.gpa) {
            highest = arr[i];
        }
    }
    return highest;
}

void Sapxep(student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].gpa > arr[i].gpa) {
                student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
