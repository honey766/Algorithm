#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool* visited;
void dfs(int n) {
    for (int a : graph[n])
        if (!visited[a]) {
            visited[a] = true;
            dfs(a);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a;
    cin >> n;
    graph.resize(n);
    visited = new bool[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (a) graph[i].push_back(j);
        }
    for (int i = 0; i < n; ++i) {
        memset(visited, 0, n);
        dfs(i);
        for (int j = 0; j < n; ++j)
            cout << (int)visited[j] << ' ';
        cout << '\n';
    }
}