#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct STACK {
    int arr[MAX_SIZE];
    int size = 0;
    int max_size = MAX_SIZE;
};

bool isEmpty(const STACK &st) {
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

int pop(STACK &st) {
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int val = st.arr[st.size - 1];
    st.size--;
    return val;
}

// Hàm chuyển đổi Thập phân -> Thập lục phân (Hexadecimal)
void convertDec2Hex(int x, STACK &st) {
    if (x == 0) {
        cout << 0 << endl;
        return;
    }

    char hexChars[] = "0123456789ABCDEF";

    while (x > 0) {
        push(st, x % 16);
        x = x / 16;
    }

    while (!isEmpty(st)) {
        int val = pop(st);
        cout << hexChars[val];
    }
    cout << endl;
}

int main() {
    int x;
    cout << "Enter x: ";
    cin >> x;

    STACK st;
    cout << "Hexadecimal: ";
    convertDec2Hex(x, st);

    return 0;
}