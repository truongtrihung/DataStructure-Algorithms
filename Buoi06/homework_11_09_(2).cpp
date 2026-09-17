#include <iostream>
using namespace std;

// Cấu trúc một nút (Node) trong Linked List
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    // Khởi tạo Stack (Init)
    void Init() {
        top = nullptr;
    }

    LinkedListStack() {
        Init();
    }

    // Kiểm tra Rỗng (IsEmpty)
    bool IsEmpty() {
        return (top == nullptr);
    }

    // Thêm phần tử vào đầu danh sách (Push)
    void Push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    // Lấy phần tử khỏi đầu danh sách (Pop)
    int Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Giải phóng bộ nhớ khi hủy đối tượng
    ~LinkedListStack() {
        while (!IsEmpty()) {
            Pop();
        }
    }
};

int main() {
    LinkedListStack s;
    s.Init();

    cout << "=== LINKED LIST-BASED STACK TEST ===\n";
    cout << "Is Empty: " << (s.IsEmpty() ? "Yes" : "No") << endl;

    s.Push(100);
    s.Push(200);
    s.Push(300);

    cout << "Is Empty: " << (s.IsEmpty() ? "Yes" : "No") << endl;

    cout << "Popped: " << s.Pop() << endl;
    cout << "Popped: " << s.Pop() << endl;

    return 0;
}