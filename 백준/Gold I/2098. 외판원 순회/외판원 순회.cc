#include <iostream>
using namespace std;
#define INF 17000000

int n;
int graph[16][16];
int dp[16][1 << 16] = { 0, };

int dfs(int cur, int status) {
    if (status == (1 << n) - 1) {
        if (!graph[cur][0]) return INF;
        return graph[cur][0];
    }

    if (dp[cur][status]) return dp[cur][status];
    
    int ret = INF;
    for (int i = 0; i < n; ++i) {
        if (!graph[cur][i] || status & (1 << i)) continue;
        
        ret = min(ret, graph[cur][i] + dfs(i, status | (1 << i)));
    }
    
    return dp[cur][status] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    cout << dfs(0, 1);
}