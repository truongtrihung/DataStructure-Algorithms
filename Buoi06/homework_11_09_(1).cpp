#include <iostream>
using namespace std;

#define MAX 100

class ArrayStack {
private:
    int top;
    int data[MAX];

public:
    // Khởi tạo Stack (Init)
    void Init() {
        top = -1;
    }

    ArrayStack() {
        Init();
    }

    // Kiểm tra Rỗng (IsEmpty)
    bool IsEmpty() {
        return (top < 0);
    }

    // Kiểm tra Đầy (IsFull)
    bool IsFull() {
        return (top >= MAX - 1);
    }

    // Thêm phần tử (Push)
    bool Push(int x) {
        if (IsFull()) {
            cout << "Stack Overflow!\n";
            return false;
        }
        data[++top] = x;
        return true;
    }

    // Xóa/Lấy phần tử (Pop)
    int Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return data[top--];
    }
};

int main() {
    ArrayStack s;
    s.Init();

    cout << "=== ARRAY-BASED STACK TEST ===\n";
    cout << "Is Empty: " << (s.IsEmpty() ? "Yes" : "No") << endl;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Is Empty: " << (s.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (s.IsFull() ? "Yes" : "No") << endl;

    cout << "Popped: " << s.Pop() << endl;
    cout << "Popped: " << s.Pop() << endl;

    return 0;
}