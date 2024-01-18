#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a;
    deque<pair<int, int>> deq;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a; deq.push_back({a, i});
    }
    a = deq.front().first; deq.pop_front();
    cout << "1 ";
    while (deq.size() > 1) {
        if (a > 0) {
            for (int i = 0; i < a - 1; i++) {
                deq.push_back(deq.front()); deq.pop_front();
            }
            a = deq.front().first;
            cout << deq.front().second << ' '; deq.pop_front();
        }
        else {
            for (int i = 0; i < -a - 1; i++) {
                deq.push_front(deq.back()); deq.pop_back();
            }
            a = deq.back().first;
            cout << deq.back().second << ' '; deq.pop_back();
        }
    }
    if(n > 1) cout << deq.front().second;
}