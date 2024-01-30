#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[100001];

void pushque(queue<int>& que, int n) {
    que.push(n);
    visited[n] = true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, a, cnt = 0;
    cin >> n >> k;
    if (k <= n) {
        cout << n - k;
        return 0;
    }
    memset(visited, 0, 100001);

    queue<int> que;
    pushque(que, n);
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            a = que.front();
            if (a == k) break;  
            que.pop();
            if (a * 2 <= 100000 && !visited[a * 2]) pushque(que, a * 2);
            if (a < 100000 && !visited[a + 1]) pushque(que, a + 1);
            if (a > 0 && !visited[a - 1]) pushque(que, a - 1);
        }
        if (a == k) break;
        cnt++;
    }
    cout << cnt;
}