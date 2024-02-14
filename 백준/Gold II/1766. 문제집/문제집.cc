#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<short>> graph(n, vector<short>());
    priority_queue<int, vector<int>, greater<int>> pq;
    short* indegree = new short[n]();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        ++indegree[b - 1];
    }
    for (int i = 0; i < n; ++i)
        if (!indegree[i])
            pq.push(i);
    while (!pq.empty()) {
        int idx = pq.top();
        cout << idx + 1 << ' ';
        pq.pop();
        for (int c : graph[idx])
            if (--indegree[c] == 0)
                pq.push(c);
    }
}