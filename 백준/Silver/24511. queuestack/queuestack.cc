#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a, m, temp;
    cin >> n;
    bool* isQueue = new bool[n];
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        cin >> a; isQueue[i] = (a == 0);
    }
    for (int i = 0; i < n; i++) {
        cin >> a; if (isQueue[i]) deq.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (!deq.empty()) {
            deq.push_front(a);
            a = deq.back();
            deq.pop_back();
        }
        cout << a << ' ';
    }
}