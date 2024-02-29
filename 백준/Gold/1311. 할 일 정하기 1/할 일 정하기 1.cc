#include <iostream>
#include <cstring>
using namespace std;
#define INF 2'000'000'000

int n;
short d[20][20];
int dp[20][1 << 20];

int dfs(int cur, int status) {
    if (cur == n) return 0;

    if (dp[cur][status]) return dp[cur][status];

    int ret = INF;
    for (int i = 0; i < n; ++i) {
        if (status & (1 << i)) continue;
        ret = min(ret, d[cur][i] + dfs(cur + 1, status | (1 << i)));
    }
    return dp[cur][status] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> d[i][j];
    cout << dfs(0, 0);
}