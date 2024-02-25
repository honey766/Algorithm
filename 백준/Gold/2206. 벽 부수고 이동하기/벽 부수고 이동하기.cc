#include <iostream>
#include <queue>
using namespace std;

struct pr {
    int i;
    int j;
    bool breaked;
};
bool visited[1000][1000][2]; //visited[i][j][0] : 안 부숴봤을 때 진입, [1] : 부숴보고 진입
char arr[1000][1000];
int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 }; //상하좌우

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    int ni, nj, cnt = 0;
    bool end = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j] = s[j] - '0';
    }

    queue<pr> que;
    que.push({ 0, 0, false });
    visited[0][0][0] = true;
    while (!que.empty() && !end) {
        int sz = que.size();
        while (sz--) {
            pr p = que.front();
            if (p.i == n - 1 && p.j == m - 1) {
                end = true;
                break;
            }
            que.pop();
            for (int k = 0; k < 4; k++) {
                ni = p.i + dy[k];
                nj = p.j + dx[k];
                if (!validPos(ni, nj)) continue;
                if (p.breaked) { //이미 부숴본 경험이 있음
                    if (!arr[ni][nj] && !visited[ni][nj][1]) {
                        visited[ni][nj][1] = true;
                        que.push({ ni, nj, true });
                    }
                }
                else {
                    if (arr[ni][nj] && !visited[ni][nj][1]) {//부수기
                        visited[ni][nj][1] = true;
                        que.push({ ni, nj, true });
                    }
                    else if (!arr[ni][nj] && !visited[ni][nj][0]) {
                        visited[ni][nj][0] = true;
                        que.push({ ni, nj, false });
                    }
                }
            }
        }
        cnt++;
    }
    if (end) cout << cnt;
    else cout << "-1";
}