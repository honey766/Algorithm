#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graph;
int* visited;
int cnt;

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
        sort(graph[i].begin(), graph[i].end());

    queue<int> que;
    que.push(r - 1);
    visited[r - 1] = ++cnt;
    while (!que.empty()) {
        int a = que.front();
        que.pop();
        for (int v : graph[a])
            if (!visited[v]) {
                que.push(v);
                visited[v] = ++cnt;
            }
    }

    for (int i = 0; i < n; i++)
        cout << visited[i] << '\n';
}