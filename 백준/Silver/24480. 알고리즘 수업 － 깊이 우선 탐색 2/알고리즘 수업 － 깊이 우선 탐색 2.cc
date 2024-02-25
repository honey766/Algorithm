#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
int* visited;
int cnt;
void dfs(int r) {
    visited[r] = ++cnt;
    for (int v : graph[r]) {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, r, u, v;
    cin >> n >> m >> r;
    graph.resize(n);
    visited = new int[n]();
    cnt = 0;
    while (m--) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    dfs(r - 1);
    for (int i = 0; i < n; i++)
        cout << visited[i] << '\n';
}