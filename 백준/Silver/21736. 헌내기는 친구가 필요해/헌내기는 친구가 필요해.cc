#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
queue<pair<short, short>> que;
char arr[600][600];
bool visited[600][600];
int T1[4] = { -1, 1, 0, 0 };
int T2[4] = { 0, 0, -1, 1 }; //상하좌우

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void visit(int i, int j) {
    que.push({ i, j });
    visited[i][j] = true;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(visited, 0, 360000);
    int i, j, cnt = 0;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') visit(i, j);
        }

    while (!que.empty()) {
        i = que.front().first;
        j = que.front().second;
        que.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = i + T1[k];
            int nj = j + T2[k];
            if (validPos(ni, nj) && arr[ni][nj] != 'X' && !visited[ni][nj]) {
                if (arr[ni][nj] == 'P') ++cnt;
                visit(ni, nj);
            }
        }
    }
    if (cnt == 0) cout << "TT";
    else cout << cnt;
}