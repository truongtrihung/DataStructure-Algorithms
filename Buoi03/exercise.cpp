#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1000

void docfile (char filename[],int a[], int &n);

void ghifile (char filename[], int a[], int n, char tenbien);

void insertionSort (char filename[], int a[], int n);

void bubbleSort (char filename[], int a[], int n);

void swap (int &xp, int &yp);


int main () {
    int input[MAX];
    int A[MAX], B[MAX];
    int n;

    // Doc file
    docfile("/home/hunghaohan/Documents/DataStructures&Algorithms/Buoi03/Input.DAT", input, n);

    if (n == 0) {
        cout << "Khong co du lieu de xu ly" << endl;
        return 0;
    }

    // Sao chep input sang A va B ngay trong main
    for (int i = 0; i < n; i++) {
        A[i] = input[i];
        B[i] = input[i];
    }

    // Ascening of Insertion Sort
    insertionSort ("Insert.DAT", A, n);
    ghifile ("/home/hunghaohan/Documents/DataStructures&Algorithms/Buoi03/Insert.DAT", A, n, 'A');

    // Descending of Bubble Sort
    bubbleSort ("Bubble.DAT", B, n);
    ghifile("/home/hunghaohan/Documents/DataStructures&Algorithms/Buoi03/Bubble.DAT", B, n, 'B');

    cout << "Da xu ly ok" << endl;
    return 0;
}

void docfile (char filename[], int a[], int &n) {
    FILE *fp;
    fp = fopen (filename, "r");
    if (!fp) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    n = 0;
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        a[n++] = num;
        fgetc(fp);
    }
    fclose (fp);
}

void ghifile (char filename[], int a[], int n, char tenbien) {
    FILE *fp;
    fp = fopen (filename, "w");
    if (!fp) {
        cout << "Khong mo duoc file" << endl;
        return;
    }

    // In tên biến trước dãy số
    fprintf (fp, "%c = ", tenbien);

    for (int i = 0; i < n; i++) {
        fprintf (fp, "%d", a[i]);
        if (i < n - 1) {
            fprintf (fp, ";");
        }
    }
    fclose (fp);
}

void insertionSort (char filename[], int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {    // giảm dần thì đổi arr[j] < key
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void bubbleSort (char filename[], int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {  // đổi thành arr[j] < arr[j+1] nếu descending
                swap(a[j], a[j + 1]);
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

