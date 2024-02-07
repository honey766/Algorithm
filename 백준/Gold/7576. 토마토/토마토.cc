#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
queue<pair<short, short>> que;
char arr[1000][1000];
bool visited[1000][1000];
int clear; //익은 토마토 개수
int T1[4] = { -1, 0, 0, 1 };
int T2[4] = { 0, -1, 1, 0 };
// (T1[i], T2[j]) : 위, 왼, 오른, 아래

bool validPos(int i, int j, int k) {
    switch (k) {
    case 0: return i > 0;
    case 1: return j > 0;
    case 2: return j < m - 1;
    case 3: return i < n - 1;
    }
}

void visit(int i, int j) {
    que.push({ i, j });
    visited[i][j] = true;
    ++clear;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(visited, 0, 1000000);
    int i, j, a, cnt, tomatoCnt; //총 토마토 개수
    cnt = tomatoCnt = clear = 0;
    cin >> m >> n;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            cin >> a;
            if (a != -1) ++tomatoCnt;
            if (a == 1) visit(i, j);
            arr[i][j] = a;
        }

    while (!que.empty() && tomatoCnt != clear) {
        int sz = que.size();
        while (sz--) {
            i = que.front().first;
            j = que.front().second;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + T1[k];
                int nj = j + T2[k];
                if (validPos(i, j, k) && arr[ni][nj] == 0 && !visited[ni][nj])
                    visit(ni, nj);
            }
        }
        ++cnt;
    }
    if (tomatoCnt == clear) cout << cnt;
    else cout << "-1";
}