#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> que;
bool visited[100001];

void pushque(int n) {
    while (n <= 100000 && !visited[n]) {
        que.push(n);
        visited[n] = true;
        n <<= 1;
    }
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

    pushque(n);
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            a = que.front();
            if (a == k) break;
            que.pop();
            if (!visited[a + 1]) pushque(a + 1);
            if (a > 0 && !visited[a - 1]) pushque(a - 1);
        }
        if (a == k) break;
        cnt++;
    }
    cout << cnt;
}