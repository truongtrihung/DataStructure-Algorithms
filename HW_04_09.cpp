#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 1000

void taoNgauNhien(int a[], int &n);
void saoChep(int goc[], int dich[], int n);
void ghifile(char filename[], int a[], int n, const char* tenthuattoan);
void swap(int &xp, int &yp);
int partition (int arr[], int low, int high);

// 5 Thuat toan sap xep
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void quickSort(int a[], int l, int r);
void mergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);


int main() {
    srand(time(0));
    int goc[MAX], temp[MAX];
    int n;

    // Sinh ngau nhien mang > 10 phan tu
    taoNgauNhien(goc, n);

    // Ghi mang ban dau vao file Output
    char path[] = "/home/hunghaohan/Documents/DataStructures&Algorithms/Output.txt";

    FILE *fp = fopen(path, "w");
    if (fp) {
        fprintf(fp, "--- MANG BAN DAU (%d phan tu) ---\n", n);
        for (int i = 0; i < n; i++) fprintf(fp, "%d ", goc[i]);
        fprintf(fp, "\n\n--- KET QUA SAP XEP ---\n");
        fclose(fp);
    }

    // 1. Selection Sort
    saoChep(goc, temp, n);
    selectionSort(temp, n);
    ghifile(path, temp, n, "1. Selection Sort");

    // 2. Insertion Sort
    saoChep(goc, temp, n);
    insertionSort(temp, n);
    ghifile(path, temp, n, "2. Insertion Sort");

    // 3. Bubble Sort
    saoChep(goc, temp, n);
    bubbleSort(temp, n);
    ghifile(path, temp, n, "3. Bubble Sort");

    // 4. Quick Sort
    saoChep(goc, temp, n);
    quickSort(temp, 0, n - 1);
    ghifile(path, temp, n, "4. Quick Sort");

    // 5. Merge Sort
    saoChep(goc, temp, n);
    mergeSort(temp, 0, n - 1);
    ghifile(path, temp, n, "5. Merge Sort");

    cout << "Da xu ly xong va ghi vao file Output.txt!" << endl;
    return 0;
}

void taoNgauNhien(int a[], int &n) {
    n = 15; // > 10 phan tu
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void saoChep(int goc[], int dich[], int n) {
    for (int i = 0; i < n; i++) {
        dich[i] = goc[i];
    }
}

void ghifile(char filename[], int a[], int n, const char* tenthuattoan) {
    FILE *fp = fopen(filename, "a"); // Ghi noi tiep (append)
    if (!fp) return;

    fprintf(fp, "%s: ", tenthuattoan);
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", a[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

void swap(int &xp, int &yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void selectionSort(int a[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return (i);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}