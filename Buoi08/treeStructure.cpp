#include <iostream>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *fChild = NULL;
    TreeNode *nSib = NULL;
};

TreeNode *newNode(char x);
TreeNode *addChild(TreeNode *p, char x);
TreeNode *addSib(TreeNode *p, char x);
void preOrder(TreeNode *p);
void inOrder(TreeNode *p);
void postOrder(TreeNode *p);
TreeNode *find(TreeNode *T, char x);

TreeNode *newNode(char x) {
    TreeNode *q = new TreeNode();
    q->data = x;
    q->fChild = q->nSib = NULL;
    return q;
}

TreeNode *addChild(TreeNode *p, char x) {
    TreeNode *q = newNode(x);
    if (p == NULL)
        p = q;
    else if (p->fChild != NULL) {
        q->nSib = p->fChild;
        p->fChild = q;
    } else {
        p->fChild = q;
    }
    return q;
}

TreeNode *addSib(TreeNode *p, char x) {
    TreeNode *q = newNode(x);
    if (p == NULL)
        p = q;
    else {
        q->nSib = p->nSib;
        p->nSib = q;
    }
    return q;
}

void preOrder(TreeNode *p) {
    if (p != NULL) {
        TreeNode *q = p->fChild;
        cout << p->data << "-";
        preOrder(q);
        if (q != NULL) {
            q = q->nSib;
            while (q != NULL) {
                preOrder(q);
                q = q->nSib;
            }
        }
    }
}

void inOrder(TreeNode *p) {
    if (p != NULL) {
        TreeNode *q = p->fChild;
        inOrder(q);
        cout << p->data << "-";
        if (q != NULL) {
            q = q->nSib;
            while (q != NULL) {
                inOrder(q);
                q = q->nSib;
            }
        }
    }
}

void postOrder(TreeNode *p) {
    if (p != NULL) {
        TreeNode *q = p->fChild;
        postOrder(q);
        if (q != NULL) {
            q = q->nSib;
            while (q != NULL) {
                postOrder(q);
                q = q->nSib;
            }
        }
        cout << p->data << "-";
    }
}

TreeNode *find(TreeNode *T, char x) {
    if (T == NULL) return NULL;
    TreeNode *p;
    if (T->data == x) return T;
    TreeNode *q = T->fChild;
    p = NULL;
    while (p == NULL && q != NULL) {
        p = find(q, x);
        q = q->nSib;
    }
    return p;
}

int main() {
    // Tạo nút gốc A
    TreeNode *T = newNode('A');
    TreeNode *A = T, *B, *D, *E, *G, *H, *I, *K, *M, *N, *P, *Q;

    // Các con của A gồm B và D
    B = addChild(A, 'B');
    D = addSib(B, 'D');

    // Các con của B gồm E và G
    E = addChild(B, 'E');
    G = addSib(E, 'G');

    // Con của E là K
    K = addChild(E, 'K');

    // Con của G là M
    M = addChild(G, 'M');

    // Các con của D gồm H và I
    H = addChild(D, 'H');
    I = addSib(H, 'I');

    // Con của H là N
    N = addChild(H, 'N');

    // Các con của I gồm P và Q
    P = addChild(I, 'P');
    Q = addSib(P, 'Q');

    // Chạy các phép duyệt cây
    cout << "\n---PREORDER:";
    preOrder(T);
    cout << "\n---INORDER:";
    inOrder(T);
    cout << "\n---POSTORDER:";
    postOrder(T);

    cout << endl;
    return 0;
}
