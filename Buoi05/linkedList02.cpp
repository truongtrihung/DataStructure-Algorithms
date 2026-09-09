#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void addFirst(Node *&head, int x);

void addLast(Node *&head, int x);

void printList(Node *n);

int main() {
    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    for (int x = 0; x < 10; x++) {
        addFirst(head1, x + 1);
        cout << x << " -> ";
        addLast(head2, x + 1);
        cout << x << " ; ";
    }
    cout << "\n=====LIST 1=====" << endl;
    printList(head1);
    cout << "\n=====LIST 2=====" << endl;
    printList(head2);
    return 0;
}

void addFirst(Node *&head, int x) {
    Node *p = new Node();
    p->data = x;
    p->next = head;
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = new Node();
    p->data = x;
    p->next = NULL;
    if (head == NULL) {
        head = p;
    } else {
        Node *q = head;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "NULL" << endl;
}
