/*
    Write a program to read and display an array of n laptops (laptop name, product ID, RAM, price).
    Write a function to do the following tasks:
    a) Find the laptop with the largest RAM capacity
    b) Sort the list in ascending order of price by selecion sort
*/
#include <iostream>
using namespace std;

#define MAX 10

struct laptops {
    string name;
    string id;
    int ram;
    double price;
};

//  Hàm nhập danh sách laptop
void nhapDSLap (laptops arr[], int &n);

//  Hàm xuất danh sách laptop
void xuatlaptop (laptops arr[], int n);

// a) Hàm tìm laptop có dung lượng ram lớn nhất 
laptops findHighest (laptops arr[], int n);


// b) Hàm sắp xết danh sách giá laptop tăng dần 
void sorting (laptops arr[], int n);

// Hàm hoán vị
void swap (laptops &xp, laptops &yp);

int main(){
    laptops arr[MAX];
    int n;
    
    nhapDSLap (arr, n);
    xuatlaptop (arr, n);

    laptops highest = findHighest (arr, n);
    cout << "===Laptop co gia cao nhat===" << endl;
    cout << "Ten laptop: " << highest.name << endl;
    cout << "ID laptop: " << highest.id << endl;
    cout << "RAM cua laptop: " << highest.ram << endl;
    cout << "Gia cua laptop: " << highest.price << endl;

    sorting (arr, n);
    cout << "Thu tu laptop duoc xep tang dan la: " << endl;
    xuatlaptop (arr, n);

    return 0;
}


//  Hàm nhập danh sách laptop
void nhapDSLap (laptops arr[], int &n){
    cout << "Nhap so luong laptop: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cin.ignore ();

        cout << "Nhap ten laptop: ";
        getline (cin, arr[i].name);

        cout << "Nhap id laptop: ";
        getline (cin, arr[i].id);

        cout << "Nhap dung luong RAM cua laptop: ";
        cin >> arr[i].ram;

        cout << "Nhap gia cua laptop: ";
        cin >> arr[i].price;
    }
}

//  Hàm xuất danh sách laptop
void xuatlaptop (laptops arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "Thong tin cua laptop thu: " << i + 1 << endl;
        cout << "Ten laptop: " << arr[i].name << endl;
        cout << "ID: " << arr[i].id << endl;
        cout << "Dung luong RAM: " << arr[i].ram << endl;
        cout << "Nhap gia cua laptop: " << arr[i].price << endl;
    }
}

// a) Hàm tìm laptop có dung lượng ram lớn nhất 
laptops findHighest (laptops arr[], int n){
    laptops highest = arr[0];
    for (int i = 1; i < n;i ++){
        if (arr[i].ram > highest.ram) highest = arr[i];
    }
    return highest;
}


// b) Hàm sắp xết danh sách giá laptop tăng dần 
void sorting (laptops arr[], int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++){
        min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j].price < arr[min_idx].price) 
                min_idx = j;
        }
        swap (arr[i], arr[min_idx]);
    }
}


// Hàm hoán vị
void swap (laptops &xp, laptops &yp){
    laptops temp = xp;
    xp = yp;
    yp = temp;
}