#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;
};

void addFirst(Node *&head, int x) {
    Node *p = new Node();
    p->data = x;
    p->prev = NULL;
    p->next = head;
    if (head != NULL) head->prev = p;
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = new Node();
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    if (head == NULL) {
        head = p;
    } else {
        Node *q = head;
        while (q->next != NULL) q = q->next;
        q->next = p;
        p->prev = q;
    }
}

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << "->";
        n = n->next;
    }
    cout << "NULL" << endl;
}

void printListLF(Node *n) {
    while (n->next != NULL) n = n->next;
    while (n != NULL) {
        cout << n->data << "<-";
        n = n->prev;
    }
}

int main() {
    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    for (int x = 1; x < 21; x = x + 2) {
        addLast(head1, x);
    }
    for (int x = 2; x < 21; x = x + 2) {
        addLast(head2, x);
    }
    cout << "\n\n====LIST 1: Start to Last====\n"; printList(head1);
    cout << "\n\n====LIST 1: Last to Start====\n"; printListLF(head1);
    cout << "\n\n====LIST 2: Start to Last====\n"; printList(head2);
    cout << "\n\n====LIST 2: Last to Start====\n"; printListLF(head2);
    return 0;
}
