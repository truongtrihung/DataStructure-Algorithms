#include <iostream>
#include <string>
#include <algorithm>

#define MAX 100

using namespace std;

struct employee {
    string id;
    string name;
    int age;
};

struct ArrList {
    employee data[MAX];
    int len = 0;
    int maxLen = MAX;
};
int inputList(ArrList &List, int n);
void printList(ArrList List, int f, int t);
void appendList(ArrList &DS1, ArrList DS2);
void sortByAge(ArrList &List);
void swap (int &xp, int &yp);

int main() {
    ArrList DS1, DS2;
    int n1, n2;

    // 1. Nhập và xuất danh sách DS1
    cout << "Nhap so luong nhan vien DS1: ";
    cin >> n1;
    inputList(DS1, n1);

    cout << endl;

    // 1. Nhập và xuất danh sách DS2
    cout << "Nhap so luong nhan vien DS2: ";
    cin >> n2;
    inputList(DS2, n2);

    cout << endl;

    cout << "======= Danh sach DS1  =======";
    printList(DS1, 1, DS1.len);

    cout << endl;

    cout << "======= Danh sach DS2  =======";
    printList(DS2, 1, DS2.len);

    cout << endl;

    // 2. Nối DS2 vào cuối DS1 và in ra DS1 sau khi nối
    appendList(DS1, DS2);
    cout << "======= DS1 sau khi noi DS2 vao cuoi =======";
    printList(DS1, 1, DS1.len);

    cout << endl;

    // 3. Sắp xếp DS1 tăng dần theo tuổi (Age)
    sortByAge(DS1);
    cout << "======= DS1 sau khi sap xep tang dan theo tuoi =======";
    printList(DS1, 1, DS1.len);

    return 0;
}

// Hàm nhập thông tin cho danh sách
int inputList(ArrList &List, int n) {
    if (List.len + n > List.maxLen) {
        cout << "Danh sach da day, khong the them!" << endl;
        return 0;
    } else {
        for (int i = List.len; i < n; i++) {
            cout << "\nNhan vien thu " << i + 1 << ":" << endl;
            cout << "Enter id: ";
            cin >> List.data[i].id;
            cout << "Enter name: ";
            cin >> List.data[i].name;
            cout << "Enter age: ";
            cin >> List.data[i].age;
        }
        List.len += n; // Cập nhật độ dài mới của danh sách
        return 1;
    }
}

// Hàm in các phần tử trong danh sách từ vị trí f đến t
void printList(ArrList List, int f, int t) {
    if (t < f || List.len == 0) {
        cout << "\nDanh sach rong!" << endl;
        return;
    }
    cout << "\n | STT | ID | Name | Age |\n";
    cout << "-----------------------------------" << endl;
    for (int i = f - 1; i < t; i++) {
        cout << "| " << i + 1 << " | " << List.data[i].id
             << " | " << List.data[i].name
             << " | " << List.data[i].age << " |" << endl;
    }
    cout << "-----------------------------------" << endl;
}

// Append DS2 to the end of DS1 and print DS1
void appendList(ArrList &DS1, ArrList DS2) {
    // Kiểm tra nếu tổng số phần tử vượt quá dung lượng tối đa
    if (DS1.len + DS2.len > DS1.maxLen) {
        cout << "\n[Loi] Khong the noi vi vuot qua dung luong MAX!" << endl;
        return;
    }

    // Bắt đầu chép từng phần tử của DS2 vào sau vị trí cuối cùng của DS1
    for (int i = 0; i < DS2.len; i++) {
        DS1.data[DS1.len + i] = DS2.data[i];
    }

    // Cập nhật lại tổng độ dài của DS1
    DS1.len += DS2.len;
}

// Sort the list in ascending order by age (Using Bubble Sort)
void sortByAge(ArrList &List) {
    for (int i = 0; i < List.len - 1; i++) {
        for (int j = 0; j < List.len - i - 1; j++) {
            if (List.data[j].age > List.data[j + 1].age) {
                swap(List.data[j], List.data[j + 1]);
            }
        }
    }
}

void swap (int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}