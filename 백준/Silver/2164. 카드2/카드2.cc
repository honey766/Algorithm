#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    bool youAreTrash = true;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() > 1) {
        if(!youAreTrash) q.push(q.front());
        q.pop();
        youAreTrash = !youAreTrash;
    }
    cout << q.front();
}