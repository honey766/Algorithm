#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
queue<pair<short, short>> que;
int visited[1000][1000];
int T1[4] = { -1, 0, 0, 1 };
int T2[4] = { 0, -1, 1, 0 };
// (T1[i], T2[i]) : 위, 왼, 오른, 아래

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void visit(int i, int j, int cnt) {
    que.push({ i, j });
    visited[i][j] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, j, a, cnt = 0;
    memset(visited, -1, 4000000);
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            cin >> a;
            if (a == 2) que.push({ i, j });
            if (a != 1) visited[i][j] = 0;
        }

    while (!que.empty()) {
        ++cnt;
        int sz = que.size();
        while (sz--) {
            i = que.front().first;
            j = que.front().second;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + T1[k];
                int nj = j + T2[k];
                if (validPos(ni, nj) && visited[ni][nj] == -1)
                    visit(ni, nj, cnt);
            }
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
            cout << visited[i][j] << ' ';
        cout << '\n';
    }
}