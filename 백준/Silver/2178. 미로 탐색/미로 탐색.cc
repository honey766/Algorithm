#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
bool visited[100][100];
bool a[100][100]; //지도
int T1[4] = { -1, 0, 0, 1 };
int T2[4] = { 0, -1, 1, 0 };
//k가 0:위, 1:왼, 2:오른, 3:아래

//위를 확인하려면 i > 0
bool validPos(int i, int j, int k) {
    switch (k) {
    case 0: return i > 0;
    case 1: return j > 0;
    case 2: return j < m - 1;
    case 3: return i < n - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(visited, 0, 10000);
    int i, j, cnt = 0;
    string s;
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> s;
        for (j = 0; j < m; ++j)
            a[i][j] = s[j] - '0';
    }

    queue<pair<short, short>> que;
    que.push({ 0,0 });
    visited[0][0] = true;
    while (!que.empty()) {
        ++cnt;
        int sz = que.size();
        while (sz--) {
            i = que.front().first;
            j = que.front().second;
            if (i == n - 1 && j == m - 1) break;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + T1[k];
                int nj = j + T2[k];
                if (validPos(i, j, k) && a[ni][nj] && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    que.push({ ni, nj });
                }
            }
        }
        if (i == n - 1 && j == m - 1) break;
    }
    cout << cnt;
}