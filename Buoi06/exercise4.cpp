#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct STACK {
    int arr[MAX_SIZE];
    int size = 0;
    int max_size = MAX_SIZE;
};

bool isEmpty(STACK &st){
    return st.size == 0;
}

bool isFull(const STACK &st) {
    return st.size == st.max_size;
}

void push(STACK &st, int x) {
    if (isFull(st)) {
        cout << "Stack is full" << endl;
        return;
    }
    st.arr[st.size] = x;
    st.size++;
}

int* pop(STACK &st) {
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return NULL;
    }

    int* x = &st.arr[st.size - 1];
    st.size--;
    return x;
}

int* top(STACK &st) {
    // Kiểm tra rỗng
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return NULL;
    }
    return &st.arr[st.size - 1];
}

void convertDec2Bin(int x, STACK &st) {
    while (x > 0) {
        push(st, x % 16);
        x = x / 16;
    }

    while (!isEmpty(st)) {
        int x = *pop(st);
        if (x >= 0 && x <= 9) {
            cout << x << " ";
        }
        else {
            if (x == 10) cout << "A";
            if (x == 11) cout << "B";
            if (x == 12) cout << "C";
            if (x == 13) cout << "D";
            if (x == 14) cout << "E";
            if (x == 15) cout << "F";
        }
    }
    cout << endl;
}

int main() {
    int x;
    // tính nhị phân
    cout << "Enter x: ";
    cin >> x;
    STACK st;
    convertDec2Bin(x, st);

    return 0;
}