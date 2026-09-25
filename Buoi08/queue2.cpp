#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct NODE {
    int data;
    NODE *next;
};

// Tạo NODE (createNode)
NODE* createNode(int data) {
    NODE* newNode = new NODE();
    newNode -> data = data;
    newNode -> next = nullptr;
    return newNode;
}

// Khởi tạo queue rỗng
NODE* initQueue() {
    return nullptr;
}

// Kiểm tra queue rỗng
bool isEmpty(NODE* front) {
    return (front == nullptr);
}

// Thêm phần tử
void enQueue(NODE* &front, NODE* &rear, int x) {
    NODE* newNode = createNode(x);
    if (isEmpty(front)) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear -> next = newNode;
        rear = newNode;
    }
}

// Lấy và xóa phần tử
int deQueue(NODE* &front, NODE* &rear) {
    if (isEmpty(front)) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    NODE* temp = front;
    int val = temp -> data;
    front = front -> next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return val;
}

// Xem phần tử đầu
int getFront (NODE* front) {
    if (isEmpty(front)) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}

int main() {
    NODE* front = initQueue();
    NODE* rear = initQueue();

    enQueue(front, rear, 10);
    enQueue(front, rear, 20);
    enQueue(front, rear, 30);

    cout << "Phan tu dau: " << getFront(front) << endl;

    cout << "Lay ra: " << deQueue(front, rear) << endl;
    cout << "Phan tu dau moi: " << getFront(front) << endl;

    return 0;
}
