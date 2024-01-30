#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, a, cnt = 0;
    cin >> n >> k;
    if (k <= n) {
        cout << n - k;
        return 0;
    }
    bool visited[100001];
    memset(visited, 0, 100001);

    queue<int> que;
    que.push(n);
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            a = que.front();
            if (a == k) break;
            visited[a] = true;
            que.pop();
            if (a * 2 <= 100000 && !visited[a * 2]) que.push(a * 2);
            if (a < 100000 && !visited[a + 1]) que.push(a + 1);
            if (a > 0 && !visited[a - 1]) que.push(a - 1);
        }
        if (a == k) break;
        cnt++;
    }
    cout << cnt;
}