#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Data {
    char i;
    char j;
    char k;
    Data(int I, int J, int K) { i = I; j = J; k = K; }
};

int n, m, h;
queue<Data> que;
char arr[100][100][100];
bool visited[100][100][100];
int clear; //익은 토마토 개수
int T1[6] = { 0, 0, 0, 0, 1, -1 };
int T2[6] = { 0, 0, 1, -1, 0, 0 };
int T3[6] = { 1, -1, 0, 0, 0, 0 };
// (T1[i], T2[i]) : 위, 아래, 왼, 오른, 앞, 뒤

bool validPos(int i, int j, int k) {
    return 0 <= i && i < n && 0 <= j && j < m && 0 <= k && k < h;
}

void visit(int i, int j, int k) {
    que.push(Data(i, j, k));
    visited[i][j][k] = true;
    ++clear;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(visited, 0, 1'000'000);
    int i, j, k, a, cnt, tomatoCnt; //총 토마토 개수
    cnt = tomatoCnt = clear = 0;
    cin >> m >> n >> h;
    for (k = 0; k < h; ++k)
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j) {
                cin >> a;
                if (a != -1) ++tomatoCnt;
                if (a == 1) visit(i, j, k);
                arr[i][j][k] = a;
            }

    while (!que.empty() && tomatoCnt != clear) {
        int sz = que.size();
        while (sz--) {
            i = que.front().i;
            j = que.front().j;
            k = que.front().k;
            que.pop();
            for (int l = 0; l < 6; ++l) {
                int ni = i + T1[l];
                int nj = j + T2[l];
                int nk = k + T3[l];
                if (validPos(ni, nj, nk) && arr[ni][nj][nk] == 0 && !visited[ni][nj][nk])
                    visit(ni, nj, nk);
            }
        }
        ++cnt;
    }
    if (tomatoCnt == clear) cout << cnt;
    else cout << "-1";
}