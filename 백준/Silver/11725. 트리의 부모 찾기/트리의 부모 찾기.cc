#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
int* parent;

void dfs(int i, int p) {
    parent[i] = p;
    for (int v : graph[i]) {
        if (v == p) continue;
        dfs(v, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    int a, b;
    parent = new int[n];
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 1; i < n; i++)
        cout << parent[i] + 1 << '\n';
}