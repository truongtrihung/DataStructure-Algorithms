#include <iostream>
using namespace std;

// Sửa Object/int thành char để lưu các ký tự A, B, C... của cây trong hình
struct BinaryNode {
    char data;
    struct BinaryNode *left;
    struct BinaryNode *right;
};

// Hàm bổ trợ để tạo một node mới nhanh hơn
BinaryNode* newNode(char x) {
    BinaryNode *q = new BinaryNode();
    q->data = x;
    q->left = NULL;
    q->right = NULL;
    return q;
}

// Đã sửa lỗi: Thay đổi struct tree_node -> BinaryNode, left_child -> left, right_child -> right
void preorder(struct BinaryNode *p) {
    if (p != NULL) {
        cout << p->data << "-";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct BinaryNode *p) {
    if (p != NULL) {
        inorder(p->left);
        cout << p->data << "-";
        inorder(p->right);
    }
}

void postorder(struct BinaryNode *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "-";
    }
}

int FindMax(struct BinaryNode *p) {
    int root_val, left_val, right_val, max_val;
    max_val = -1; // Assuming all values are positive integers
    if (p != NULL) {
        root_val = p->data;
        left_val = FindMax(p->left);
        right_val = FindMax(p->right);

        if (left_val > right_val)
            max_val = left_val;
        else
            max_val = right_val;
        if (root_val > max_val)
            max_val = root_val;
    }
    return max_val;
}

int add(struct BinaryNode *p) {
    if (p == NULL)
        return 0;
    else
        return (p->data + add(p->left) + add(p->right));
}

int main() {

    BinaryNode *A = newNode('A');
    BinaryNode *B = newNode('B');
    BinaryNode *D = newNode('D');
    BinaryNode *E = newNode('E');
    BinaryNode *G = newNode('G');
    BinaryNode *H = newNode('H');
    BinaryNode *I = newNode('I');
    BinaryNode *K = newNode('K');
    BinaryNode *M = newNode('M');
    BinaryNode *N = newNode('N');
    BinaryNode *P = newNode('P');
    BinaryNode *Q = newNode('Q');

    // 2. Thiết lập mối quan hệ Trái (left) - Phải (right) chuẩn theo sơ đồ
    A->left = B;    A->right = D;

    B->left = E;    B->right = G;
    E->left = K;    E->right = NULL; // K nằm bên trái của E
    G->left = NULL; G->right = M;    // M nằm bên phải của G

    D->left = H;    D->right = I;
    H->left = N;    H->right = NULL; // N nằm bên trái của H
    I->left = P;    I->right = Q;    // P nằm trái, Q nằm phải của I

    // 3. Thực thi các phép toán và in kết quả ra màn hình
    cout << "\n---PREORDER: ";
    preorder(A);

    cout << "\n---INORDER: ";
    inorder(A);

    cout << "\n---POSTORDER: ";
    postorder(A);

    cout << "\n\n---Ky tu lon nhat (theo ma ASCII): " << (char)FindMax(A);
    cout << "\n---Tong gia tri ma ASCII cua ca cay: " << add(A);

    cout << endl;
    return 0;
}
