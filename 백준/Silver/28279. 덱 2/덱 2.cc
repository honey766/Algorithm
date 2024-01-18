#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a;
    deque<int> deq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        switch (a) {
        case 1:
            cin >> a; deq.push_front(a);
            break;
        case 2:
            cin >> a; deq.push_back(a);
            break;
        case 3:
            if (deq.empty()) cout << "-1\n";
            else { cout << deq.front() << '\n'; deq.pop_front(); }
            break;
        case 4:
            if (deq.empty()) cout << "-1\n";
            else { cout << deq.back() << '\n'; deq.pop_back(); }
            break;
        case 5:
            cout << deq.size() << '\n';
            break;
        case 6:
            if (deq.empty()) cout << "1\n";
            else cout << "0\n";
            break;
        case 7:
            if (deq.empty()) cout << "-1\n";
            else cout << deq.front() << '\n';
            break;
        case 8:
            if (deq.empty()) cout << "-1\n";
            else cout << deq.back() << '\n';
            break;
        }
    }
}