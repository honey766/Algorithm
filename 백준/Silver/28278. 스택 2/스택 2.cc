#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;
    int length;

public:
    Stack() {
        this->stack = new int[1000000];
        this->length = 0;
    }
    void Push(int x) {
        if (length == 1000000) return;
        stack[length++] = x;
    }
    int Pop() {
        if (length == 0) return -1;
        return stack[--length];
    }
    int Size() {
        return length;
    }
    int Empty() {
        return (length == 0);
    }
    int Peek() {
        if (length == 0) return -1;
        return stack[length - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    Stack st = Stack();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        switch(m) {
        case 1:
            cin >> m;
            st.Push(m);
            break;
        case 2:
            cout << st.Pop() << '\n';
            break;
        case 3:
            cout << st.Size() << '\n';
            break;
        case 4:
            cout << st.Empty() << '\n';
            break;
        case 5:
            cout << st.Peek() << '\n';
            break;
        }
    }
}