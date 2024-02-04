#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    bool* visited;
    int v, e, start, a, b, f;
    cin >> v >> e >> start;
    --start;
    vector<int>* graph = new vector<int>[v];
    visited = new bool[v];
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < v; ++i)
        sort(graph[i].begin(), graph[i].begin() + graph[i].size());
    memset(visited, 0, v);
    stack<int> stk;
    stk.push(start);
    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        cout << cur + 1 << ' ';
        for (int i = graph[cur].size() - 1; i >= 0; --i) {
            f = graph[cur][i];
            if (visited[f]) continue;
            stk.push(f);
        }
    }
    cout << '\n';
    memset(visited, 0, v);
    queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        cout << cur + 1 << ' ';
        for (int i = 0; i < graph[cur].size(); ++i) {
            f = graph[cur][i];
            if (visited[f]) continue;
            que.push(f);
        }
    }
}