#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1'000'000'000
#define pr pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int v, e, k, u, vv, w;
    cin >> v >> e >> k;
    vector<vector<pr>> graph(v, vector<pr>());
    int* dist = new int[v];
    while (e--) {
        cin >> u >> vv >> w;
        graph[u - 1].push_back({ vv - 1, w });
    }

    for (int i = 0; i < v; i++)
        dist[i] = INF;
    priority_queue<pr> pq;
    pq.push({ 0, k - 1 });
    dist[k - 1] = 0;
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] != cur_dist) continue;

        for (pr p : graph[cur_node]) {
            int nxt_dist = dist[cur_node] + p.second;
            if (nxt_dist < dist[p.first]) {
                dist[p.first] = nxt_dist;
                pq.push({ -nxt_dist, p.first });
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}