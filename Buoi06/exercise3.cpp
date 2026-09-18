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

int pop(STACK &st) {
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    int x = st.arr[st.size - 1];
    st.size--;
    return x;
}

int top(STACK &st) {
    // Kiểm tra rỗng
    if (isEmpty(st)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return st.arr[st.size - 1];
}

void convertDec2Bin(int x, STACK &st) {
    while (x > 0) {
        push(st, x % 2);
        x = x / 2;
    }

    while (!isEmpty(st)) {
        cout << pop(st);
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