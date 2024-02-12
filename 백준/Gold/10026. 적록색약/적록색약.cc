#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
char arr[100][100];
bool visited[100][100];
int T1[4] = { -1, 0, 0, 1 };
int T2[4] = { 0, -1, 1, 0 };
// (T1[i], T2[i]) : 위, 왼, 오른, 아래

bool validPos(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

bool check(char c1, char c2) {
    return (c1 == c2) || (c1 != 'B' && c2 != 'B');
}

void dfs(int i, int j, bool same) {
    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int ni = i + T1[k];
        int nj = j + T2[k];
        if ( (!same && validPos(ni, nj) && !visited[ni][nj] && arr[i][j] == arr[ni][nj])
           || (same && validPos(ni, nj) && !visited[ni][nj] && check(arr[i][j], arr[ni][nj])) )
            dfs(ni, nj, same);
    }
}

void f(bool same) {
    memset(visited, 0, 10000);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!visited[i][j]) {
                dfs(i, j, same);
                ++cnt;
            }
    cout << cnt << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    
    f(false);
    f(true);
}