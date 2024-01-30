#include <iostream>
#include <queue>
using namespace std;

pair<int, int> visit[100001]; //virit[n] == {i, j} : n을 최소 i번 횟수로 j가지 방법으로 도달 가능

void pushque(queue<int>& que, int n, int howmany, int cnt) {
    if (visit[n].first > cnt) {
        visit[n] = { cnt, howmany };
        que.push(n);
    }
    else if (visit[n].first == cnt)
        visit[n].second += howmany;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, a, cnt = 0;
    bool isEnd = false;
    cin >> n >> k;
    if (k <= n) {
        cout << n - k << '\n' << 1;
        return 0;
    }
    for (int i = 0; i <= 100000; i++)
        visit[i] = { 1000000, -1 };

    queue<int> que;
    que.push(n);
    visit[n] = { 0, 1 };
    while (!que.empty()) {
        int sz = que.size();
        while (sz--) {
            a = que.front(); que.pop();
            if (a == k) isEnd = true;
            if (a * 2 <= 100000) pushque(que, a * 2, visit[a].second, cnt + 1);
            if (a < 100000) pushque(que, a + 1, visit[a].second, cnt + 1);
            if (a > 0) pushque(que, a - 1, visit[a].second, cnt + 1);
        }
        if (isEnd) break;
        cnt++;
    }
    cout << cnt << '\n' << visit[k].second;
}