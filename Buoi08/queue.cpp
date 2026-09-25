#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct QUEUE {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Khởi tạo hàng đợi rỗng
QUEUE initQueue() {
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    return q;
}

// Kiểm tra hàng đợi rỗng
bool isEmpty(QUEUE q) {
    return (q.front == -1 || q.front > q.rear);
}

// Kiểm tra hàng đợi đầy
bool isFull(QUEUE q) {
    return (q.rear == MAX_SIZE - 1);
}

// Thêm phần tử x vào cuối hàng đợi
void enqueue(QUEUE &q, int x) {
    if (isFull(q)) {
        cout << "Hang doi da day!" << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
    }
    q.rear++;
    q.arr[q.rear] = x;
}

// Trích, hủy phần tử đầu hàng đợi
int dequeue(QUEUE &q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!" << endl;
        return -1;
    }
    int val = q.arr[q.front];
    q.front++;
    return val;
}

// Xem thông tin ở phần tử đầu hàng đợi
int front(QUEUE &q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!" << endl;
        return -1;
    }
    return q.arr[q.front];
}

int main() {
    QUEUE q = initQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Phan tu dau: " << front(q) << endl;

    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Phan tu dau moi: " << front(q) << endl;

    return 0;
}