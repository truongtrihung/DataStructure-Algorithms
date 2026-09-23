#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct STACK {
    Node *pHead;
    Node *pTail;
};

Node *createNode(int x) {
    Node *p = new Node();

    if (p == nullptr) {
        cout << "Memory allocation failed." << endl;
        return nullptr;
    }

    p->data = x;
    p->pNext = nullptr;
}

STACK *initSTACK() {
    STACK s;

    s.pHead = nullptr;
    s.pTail = nullptr;

    return &s;
}

bool isEmpty(STACK s) {
    return s.pHead == nullptr and s.pTail == nullptr;
}

void insertFirst(STACK &s, Node *x) {
    if (isEmpty(s)) {
        s.pHead = x;
        s.pTail = x;
        return;
    }

    x->pNext = s.pHead;
    s.pHead = x;
}

int removeFirst(STACK &s) {
    if (isEmpty(s)) {
        return NULL;
    }
    Node *p = s.pHead;
    int x = p->data;

    s.pHead = p->pNext;

    delete p;

    // tương tác với pHead? chưa kiểm tra pTail
    // s chỉ có 1 phần tử -> xóa phần tử này
    // s.pHead = NULL / s.pTail = first

    if (s.pHead == nullptr) s.pTail = nullptr;

    return x;
}

void push(STACK &l, int x) {
    Node *p = createNode(x);
    insertFirst(s, p);
}

int pop(STACK &l) {
    removeFirst(s);
}

int top(STACK &s) {
    if (isEmpty(s)) return NULL;

    return s.pHead->data;
}
