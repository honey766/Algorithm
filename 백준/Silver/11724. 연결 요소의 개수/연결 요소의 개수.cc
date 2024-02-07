#include <iostream>
#include <vector>
using namespace std;

bool visited[1000];
vector<int> graph[1000];

void dfs(int i) {
    visited[i] = true;
    for (int idx : graph[i]) {
        if (visited[idx]) continue;
        dfs(idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int v, e, a, b, cnt = 0;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < v; ++i) {
        if (visited[i]) continue;
        ++cnt;
        dfs(i);
    }
    cout << cnt;
}