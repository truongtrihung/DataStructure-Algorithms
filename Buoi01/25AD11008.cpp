#include <iostream>
using namespace std;

#define MAX 10

struct employees {
    string name;
    string id;
    double salary;
};

// a) Hàm nhập danh sách nhân viên
void nhapDSNV (employees arr[], int &n);

// b) Hàm xuất danh sách nhân viên
void xuatDSNV (employees arr[], int n);

// c) Hàm tìm nhân viên có lương cao nhất
employees findHighest (employees arr[], int n);

// d) Hàm sắp xếp lương nhân viên từ thấp lên cao
void sapxep (employees arr[], int n);

int main () {
    employees arr[MAX];
    int n;
    nhapDSNV (arr, n);
    xuatDSNV (arr, n);

    employees highest = findHighest (arr, n);
    cout << "===Nhan vien co luong cao nhat===" << endl;
    cout << "Ho va ten: " << highest.name << endl;
    cout << "ID: " << highest.id << endl;
    cout << "Salary: " << highest.salary << endl;

    sapxep(arr, n);
    cout << "Thu tu nhan vien tang dan la: " << endl;
    xuatDSNV (arr, n);

    return 0;
}

// a) Hàm nhập danh sách nhân viên
void nhapDSNV (employees arr[], int &n) {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();

        cout << "Nhap ten: ";
        getline (cin, arr[i].name);

        cout << "Nhap id: ";
        getline (cin, arr[i].id);

        cout << "Nhap salary: ";
        cin >> arr[i].salary;
    }
}

// b) Hàm xuất danh sách nhân viên
void xuatDSNV (employees arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin cua nhan vien thu: " << i + 1 << endl;
        cout << "Ho va ten: " << arr[i].name << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Salary: " << arr[i].salary << endl;
    }
}

// c) Hàm tìm nhân viên có lương cao nhất
employees findHighest (employees arr[], int n) {
    employees highest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].salary > highest.salary) highest = arr[i];
    }
    return highest;
}

// d) Hàm sắp xếp lương nhân viên từ thấp lên cao
void sapxep (employees arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].salary > arr[j].salary) {
                employees temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
