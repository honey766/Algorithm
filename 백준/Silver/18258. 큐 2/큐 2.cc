#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a;
    string s;
    queue<int> q;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> s;
        if (s == "push") {
            cin >> a; q.push(a);
        }
        else {
            if (s == "pop") {
                if (q.empty()) cout << "-1";
                else {
                    cout << q.front(); q.pop();
                }
            }
            else if (s == "size") {
                cout << q.size();
            }
            else if (s == "empty") {
                if (q.empty()) cout << '1';
                else cout << '0';
            }
            else if (s == "front") {
                if (q.empty()) cout << "-1";
                else cout << q.front();
            }
            else if (s == "back") {
                if (q.empty()) cout << "-1";
                else cout << q.back();
            }
            cout << '\n';
        }
    }
}